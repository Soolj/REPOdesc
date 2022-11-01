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
	mavlink_sha256_update(&ctx, p, MAVLINK_CORE_HEADER_