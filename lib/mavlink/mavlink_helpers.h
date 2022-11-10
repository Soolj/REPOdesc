#pragma once

#include "string.h"
#include "checksum.h"
#include "mavlink_types.h"
#include "mavlink_conversions.h"
#include <stdio.h>

#ifndef MAVLINK_HELPER
#define MAVLINK_HELPER
#endif

#include "mavlink_sha256.h"

#ifdef MAVLINK_USE_CXX_NAMESPACE
namespace mavlink {
#endif

/*
 * Internal function to give access to the channel status for each channel
 */
#ifndef MAVLINK_GET_CHANNEL_STATUS
MAVLINK_HELPER mavlink_status_t* mavlink_get_channel_status(uint8_t chan)
{
#ifdef MAVLINK_EXTERNAL_RX_STATUS
	// No m_mavlink_status array defined in function,
	// has to be defined externally
#else
	static mavlink_status_t m_mavlink_status[MAVLINK_COMM_NUM_BUFFERS];
#endif
	return &m_mavlink_status[chan];
}
#endif

/*
 * Internal function to give access to the channel buffer for each channel
 */
#ifndef MAVLINK_GET_CHANNEL_BUFFER
MAVLINK_HELPER mavlink_message_t* mavlink_get_channel_buffer(uint8_t chan)
{

#ifdef MAVLINK_EXTERNAL_RX_BUFFER
	// No m_mavlink_buffer array defined in function,
	// has to be defined externally
#else
	static mavlink_message_t m_mavlink_buffer[MAVLINK_COMM_NUM_BUFFERS];
#endif
	return &m_mavlink_buffer[chan];
}
#endif // MAVLINK_GET_CHANNEL_BUFFER

/**
 * @brief Reset the status of a channel.
 */
MAVLINK_HELPER void mavlink_reset_channel_status(uint8_t chan)
{
	mavlink_status_t *status = mavlink_get_channel_status(chan);
	status->parse_state = MAVLINK_PARSE_STATE_IDLE;
}

/**
 * @brief create a signature block for a packet
 */
MAVLINK_HELPER uint8_t mavlink_sign_packet(mavlink_signing_t *signing,
					   uint8_t signature[MAVLINK_SIGNATURE_BLOCK_LEN],
					   const uint8_t *header, uint8_t header_len,
					   const uint8_t *packet, uint8_t packet_len,
					   const uint8_t crc[2])
{
	mavlink_sha256_ctx ctx;
	union {
	    uint64_t t64;
	    uint8_t t8[8];
	} tstamp;
	if (signing == NULL || !(signing->flags & MAVLINK_SIGNING_FLAG_SIGN_OUTGOING)) {
	    return 0;
	}
	signature[0] = signing->link_id;
	tstamp.t64 = signing->timestamp;
	memcpy(&signature[1], tstamp.t8, 6);
	signing->timestamp++;

	mavlink_sha256_init(&ctx);
	mavlink_sha256_update(&ctx, signing->secret_key, sizeof(signing->secret_key));
	mavlink_sha256_update(&ctx, header, header_len);
	mavlink_sha256_update(&ctx, packet, packet_len);
	mavlink_sha256_update(&ctx, crc, 2);
	mavlink_sha256_update(&ctx, signature, 7);
	mavlink_sha256_final_48(&ctx, &signature[7]);

	return MAVLINK_SIGNATURE_BLOCK_LEN;
}

/**
 * return new packet length for trimming payload of any trailing zero
 * bytes. Used in MAVLink2 to give simple support for variable length
 * arrays.
 */
MAVLINK_HELPER uint8_t _mav_trim_payload(const char *payload, uint8_t length)
{
	while (length > 1 && payload[length-1] == 0) {
		length--;
	}
	return length;
}

/**
 * @brief check a signature block for a packet
 */
MAVLINK_HELPER bool mavlink_signature_check(mavlink_signing_t *signing,
					    mavlink_signing_streams_t *signing_streams,
					    const mavlink_message_t *msg)
{
	if (signing == NULL) {
		return true;
	}
        const uint8_t *p = (const uint8_t *)&msg->magic;
	const uint8_t *psig = msg->signature;
        const uint8_t *incoming_signature = psig+7;
	mavlink_sha256_ctx ctx;
	uint8_t signature[6];
	uint16_t i;

	mavlink_sha256_init(&ctx);
	mavlink_sha256_update(&ctx, signing->secret_key, sizeof(signing->secret_key));
	mavlink_sha256_update(&ctx, p, MAVLINK_CORE_HEADER_LEN+1+msg->len);
	mavlink_sha256_update(&ctx, msg->ck, 2);
	mavlink_sha256_update(&ctx, psig, 1+6);
	mavlink_sha256_final_48(&ctx, signature);
	if (memcmp(signature, incoming_signature, 6) != 0) {
		return false;
	}

	// now check timestamp
	bool timestamp_checks = !(signing->flags & MAVLINK_SIGNING_FLAG_NO_TIMESTAMPS);
	union tstamp {
	    uint64_t t64;
	    uint8_t t8[8];
	} tstamp;
	uint8_t link_id = psig[0];
	tstamp.t64 = 0;
	memcpy(tstamp.t8, psig+1, 6);

	if (signing_streams == NULL) {
		return false;
	}

	// find stream
	for (i=0; i<signing_streams->num_signing_streams; i++) {
		if (msg->sysid == signing_streams->stream[i].sysid &&
		    msg->compid == signing_streams->stream[i].compid &&
		    link_id == signing_streams->stream[i].link_id) {
			break;
		}
	}
	if (i == signing_streams->num_signing_streams) {
		if (signing_streams->num_signing_streams >= MAVLINK_MAX_SIGNING_STREAMS) {
			// over max number of streams
			return false;
		}
		// new stream. Only accept if timestamp is not more than 1 minute old
		if (timestamp_checks && (tstamp.t64 + 6000*1000UL < signing->timestamp)) {
			return false;
		}
		// add new stream
		signing_streams->stream[i].sysid = msg->sysid;
		signing_streams->stream[i].compid = msg->compid;
		signing_streams->stream[i].link_id = link_id;
		signing_streams->num_signing_streams++;
	} else {
		union tstamp last_tstamp;
		last_tstamp.t64 = 0;
		memcpy(last_tstamp.t8, signing_streams->stream[i].timestamp_bytes, 6);
		if (timestamp_checks && tstamp.t64 <= last_tstamp.t64) {
			// repeating old timestamp
			return false;
		}
	}

	// remember last timestamp
	memcpy(signing_streams->stream[i].timestamp_bytes, psig+1, 6);

	// our next timestamp must be at least this timestamp
	if (tstamp.t64 > signing->timestamp) {
		signing->timestamp = tstamp.t64;
	}
	return true;
}


/**
 * @brief Finalize a MAVLink message with channel assignment
 *
 * This function calculates the checksum and sets length and aircraft id correctly.
 * It assumes that the message id and the payload are already correctly set. This function
 * can also be used if the message header has already been written before (as in mavlink_msg_xxx_pack
 * instead of mavlink_msg_xxx_pack_headerless), it just introduces little extra overhead.
 *
 * @param msg Message to finalize
 * @param system_id Id of the sending (this) system, 1-127
 * @param length Message length
 */
MAVLINK_HELPER uint16_t mavlink_finalize_message_buffer(mavlink_message_t* msg, uint8_t system_id, uint8_t component_id,
						      mavlink_status_t* status, uint8_t min_length, uint8_t length, uint8_t crc_extra)
{
	bool mavlink1 = (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) != 0;
	bool signing = 	(!mavlink1) && status->signing && (status->signing->flags & MAVLINK_SIGNING_FLAG_SIGN_OUTGOING);
	uint8_t signature_len = signing? MAVLINK_SIGNATURE_BLOCK_LEN : 0;
        uint8_t header_len = MAVLINK_CORE_HEADER_LEN+1;
	uint8_t buf[MAVLINK_CORE_HEADER_LEN+1];
	if (mavlink1) {
		msg->magic = MAVLINK_STX_MAVLINK1;
		header_len = MAVLINK_CORE_HEADER_MAVLINK1_LEN+1;
	} else {
		msg->magic = MAVLINK_STX;
	}
	msg->len = mavlink1?min_length:_mav_trim_payload(_MAV_PAYLOAD(msg), length);
	msg->sysid = system_id;
	msg->compid = component_id;
	msg->incompat_flags = 0;
	if (signing) {
		msg->incompat_flags |= MAVLINK_IFLAG_SIGNED;
	}
	msg->compat_flags = 0;
	msg->seq = status->current_tx_seq;
	status->current_tx_seq = status->current_tx_seq + 1;

	// form the header as a byte array for the crc
	buf[0] = msg->magic;
	buf[1] = msg->len;
	if (mavlink1) {
		buf[2] = msg->seq;
		buf[3] = msg->sysid;
		buf[4] = msg->compid;
		buf[5] = msg->msgid & 0xFF;
	} else {
		buf[2] = msg->incompat_flags;
		buf[3] = msg->compat_flags;
		buf[4] = msg->seq;
		buf[5] = msg->sysid;
		buf[6] = msg->compid;
		buf[7] = msg->msgid & 0xFF;
		buf[8] = (msg->msgid >> 8) & 0xFF;
		buf[9] = (msg->msgid >> 16) & 0xFF;
	}

	msg->checksum = crc_calculate(&buf[1], header_len-1);
	crc_accumulate_buffer(&msg->checksum, _MAV_PAYLOAD(msg), msg->len);
	crc_accumulate(crc_extra, &msg->checksum);
	mavlink_ck_a(msg) = (uint8_t)(msg->checksum & 0xFF);
	mavlink_ck_b(msg) = (uint8_t)(msg->checksum >> 8);

	if (signing) {
		mavlink_sign_packet(status->signing,
				    msg->signature,
				    (const uint8_t *)buf, header_len,
				    (const uint8_t *)_MAV_PAYLOAD(msg), msg->len,
				    (const uint8_t *)_MAV_PAYLOAD(msg)+(uint16_t)msg->len);
	}

	return msg->len + header_len + 2 + signature_len;
}

MAVLINK_HELPER uint16_t mavlink_finalize_message_chan(mavlink_message_t* msg, uint8_t system_id, uint8_t component_id,
						      uint8_t chan, uint8_t min_length, uint8_t length, uint8_t crc_extra)
{
	mavlink_status_t *status = mavlink_get_channel_status(chan);
	return mavlink_finalize_message_buffer(msg, system_id, component_id, status, min_length, length, crc_extra);
}

/**
 * @brief Finalize a MAVLink message with MAVLINK_COMM_0 as default channel
 */
MAVLINK_HELPER uint16_t mavlink_finalize_message(mavlink_message_t* msg, uint8_t system_id, uint8_t component_id,
						 uint8_t min_length, uint8_t length, uint8_t crc_extra)
{
    return mavlink_finalize_message_chan(msg, system_id, component_id, MAVLINK_COMM_0, min_length, length, crc_extra);
}

static inline void _mav_parse_error(mavlink_status_t *status)
{
    status->parse_error++;
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS
MAVLINK_HELPER void _mavlink_send_uart(mavlink_channel_t chan, const char *buf, uint16_t len);

/**
 * @brief Finalize a MAVLink message with channel assignment and send
 */
MAVLINK_HELPER void _mav_finalize_message_chan_send(mavlink_channel_t chan, uint32_t msgid,
                                                    const char *packet,
						    uint8_t min_length, uint8_t length, uint8_t crc_extra)
{
	uint16_t checksum;
	uint8_t buf[MAVLINK_NUM_HEADER_BYTES];
	uint8_t ck[2];
	mavlink_status_t *status = mavlink_get_channel_status(chan);
        uint8_t header_len = MAVLINK_CORE_HEADER_LEN;
	uint8_t signature_len = 0;
	uint8_t signature[MAVLINK_SIGNATURE_BLOCK_LEN];
	bool mavlink1 = (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) != 0;
	bool signing = 	(!mavlink1) && status->signing && (status->signing->flags & MAVLINK_SIGNING_FLAG_SIGN_OUTGOING);

        if (mavlink1) {
            length = min_length;
            if (msgid > 255) {
                // can't send 16 bit messages
                _mav_parse_error(status);
                return;
            }
            header_len = MAVLINK_CORE_HEADER_MAVLINK1_LEN;
            buf[0] = MAVLINK_STX_MAVLINK1;
            buf[1] = length;
            buf[2] = status->current_tx_seq;
            buf[3] = mavlink_system.sysid;
            buf[4] = mavlink_system.compid;
            buf[5] = msgid & 0xFF;
        } else {
	    uint8_t incompat_flags = 0;
	    if (signing) {
		incompat_flags |= MAVLINK_IFLAG_SIGNED;
	    }
            length = _mav_trim_payload(packet, length);
            buf[0] = MAVLINK_STX;
            buf[1] = length;
            buf[2] = incompat_flags;
            buf[3] = 0; // compat_flags
            buf[4] = status->current_tx_seq;
            buf[5] = mavlink_system.sysid;
            buf[6] = mavlink_system.compid;
            buf[7] = msgid & 0xFF;
            buf[8] = (msgid >> 8) & 0xFF;
            buf[9] = (msgid >> 16) & 0xFF;
        }
	status->current_tx_seq++;
	checksum = crc_calculate((const uint8_t*)&buf[1], header_len);
	crc_accumulate_buffer(&checksum, packet, length);
	crc_accumulate(crc_extra, &checksum);
	ck[0] = (uint8_t)(checksum & 0xFF);
	ck[1] = (uint8_t)(checksum >> 8);

	if (signing) {
		// possibly add a signature
		signature_len = mavlink_sign_packet(status->signing, signature, buf, header_len+1,
						    (const uint8_t *)packet, length, ck);
	}

	MAVLINK_START_UART_SEND(chan, header_len + 3 + (uint16_t)length + (uint16_t)signature_len);
	_mavlink_send_uart(chan, (const char *)buf, header_len+1);
	_mavlink_send_uart(chan, packet, length);
	_mavlink_send_uart(chan, (const char *)ck, 2);
	if (signature_len != 0) {
		_mavlink_send_uart(chan, (const char *)signature, signature_len);
	}
	MAVLINK_END_UART_SEND(chan, header_len + 3 + (uint16_t)length + (uint16_t)signature_len);
}

/**
 * @brief re-send a message over a uart channel
 * this is more stack efficient than re-marshalling the message
 * If the message is signed then the original signature is also sent
 */
MAVLINK_HELPER void _mavlink_resend_uart(mavlink_channel_t chan, const mavlink_message_t *msg)
{
	uint8_t ck[2];

	ck[0] = (uint8_t)(msg->checksum & 0xFF);
	ck[1] = (uint8_t)(msg->checksum >> 8);
	// XXX use the right sequence here

        uint8_t header_len;
        uint8_t signature_len;

        if (msg->magic == MAVLINK_STX_MAVLINK1) {
            header_len = MAVLINK_CORE_HEADER_MAVLINK1_LEN + 1;
            signature_len = 0;
            MAVLINK_START_UART_SEND(chan, header_len + msg->len + 2 + signature_len);
            // we can't send the structure directly as it has extra mavlink2 elements in it
            uint8_t buf[MAVLINK_CORE_HEADER_MAVLINK1_LEN + 1];
            buf[0] = msg->magic;
            buf[1] = msg->len;
            buf[2] = msg->seq;
            buf[3] = msg->sysid;
            buf[4] = msg->compid;
            buf[5] = msg->msgid & 0xFF;
            _mavlink_send_uart(chan, (const char*)buf, header_len);
        } else {
            header_len = MAVLINK_CORE_HEADER_LEN + 1;
            signature_len = (msg->incompat_flags & MAVLINK_IFLAG_SIGNED)?MAVLINK_SIGNATURE_BLOCK_LEN:0;
            MAVL