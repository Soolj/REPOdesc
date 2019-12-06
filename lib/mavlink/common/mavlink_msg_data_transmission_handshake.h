#pragma once
// MESSAGE DATA_TRANSMISSION_HANDSHAKE PACKING

#define MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE 130

MAVPACKED(
typedef struct __mavlink_data_transmission_handshake_t {
 uint32_t size; /*< total data size in bytes (set on ACK only)*/
 uint16_t width; /*< Width of a matrix or image*/
 uint16_t height; /*< Height of a matrix or image*/
 uint16_t packets; /*< number of packets beeing sent (set on ACK only)*/
 uint8_t type; /*< type of requested/acknowledged data (as defined in ENUM DATA_TYPES in mavlink/include/mavlink_types.h)*/
 uint8_t payload; /*< payload size per packet (normally 253 byte, see DATA field size in message ENCAPSULATED_DATA) (set on ACK only)*/
 uint8_t jpg_quality; /*< JPEG quality out of [1,100]*/
}) mavlink_data_transmission_handshake_t;

#define MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE_LEN 13
#define MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE_MIN_LEN 13
#define MAVLINK_MSG_ID_130_LEN 13
#define MAVLINK_MSG_ID_130_MIN_LEN 13

#define MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE_CRC 29
#define MAVLINK_MSG_ID_130_CRC 29



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DATA_TRANSMISSION_HANDSHAKE { \
    130, \
    "DATA_TRANSMISSION_HANDSHAKE", \
    7, \
    {  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_data_transmission_handshake_t, type) }, \
         { "size", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_data_transmission_handshake_t, size) }, \
         { "width", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_data_transmission_handshake_t, width) }, \
         { "height", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_data_transmission_handshake_t, height) }, \
         { "packets", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_data_transmission_handshake_t, packets) }, \
         { "payload", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_data_transmission_handshake_t, payload) }, \
         { "jpg_quality", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_data_transmission_handshake_t, jpg_quality) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DATA_TRANSMISSION_HANDSHAKE { \
    "DATA_TRANSMISSION_HANDSHAKE", \
    7, \
    {  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_data_transmission_handshake_t, type) }, \
         { "size", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_data_transmission_handshake_t, size) }, \
         { "width", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_data_transmission_handshake_t, width) }, \
         { "height", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_data_transmission_handshake_t, height) }, \
         { "packets", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_data_transmission_handshake_t, packets) }, \
         { "payload", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_data_transmission_handshake_t, payload) }, \
         { "jpg_quality", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_data_transmission_handshake_t, jpg_quality) }, \
         } \
}
#endif

/**
 * @brief Pack a data_transmission_handshake message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param type type of requested/acknowledged data (as defined in ENUM DATA_TYPES in mavlink/include/mavlink_types.h)
 * @param size total data size in bytes (set on ACK only)
 * @param width Width of a matrix or image
 * @param height Height of a matrix or image
 * @param packets number of packets beeing sent (set on ACK only)
 * @param payload payload size per packet (normally 253 byte, see DATA field size in message ENCAPSULATED_DATA) (set on ACK only)
 * @param jpg_quality JPEG quality out of [1,100]
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_data_transmission_handshake_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t type, uint32_t size, uint16_t width, uint16_t height, uint16_t packets, uint8_t payload, uint8_t jpg_quality)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE_LEN];
    _mav_put_uint32_t(buf, 0, size);
    _mav_put_uint16_t(buf, 4, width);
    _mav_put_uint16_t(buf, 6, height);
    _mav_put_uint16_t(buf, 8, packets);
    _mav_put_uint8_t(buf, 10, type);
    _mav_put_uint8_t(buf, 11, payload);
    _mav_put_uint8_t(buf, 12, jpg_quality);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE_LEN);
#else
    mavlink_data_transmission_handshake_t packet;
    packet.size = size;
    packet.width = width;
    packet.height = height;
    packet.packets = packets;
    packet.type = type;
    packet.payload = payload;
    packet.jpg_quality = jpg_quality;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE_MIN_LEN, MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE_LEN, MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE_CRC);
}

/**
 * @brief Pack a data_transmission_handshake message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param type type of requested/acknowledged data (as defined in ENUM DATA_TYPES in mavlink/include/mavlink_types.h)
 * @param size total data size in bytes (set on ACK onl