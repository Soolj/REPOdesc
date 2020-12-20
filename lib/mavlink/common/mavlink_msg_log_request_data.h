#pragma once
// MESSAGE LOG_REQUEST_DATA PACKING

#define MAVLINK_MSG_ID_LOG_REQUEST_DATA 119

MAVPACKED(
typedef struct __mavlink_log_request_data_t {
 uint32_t ofs; /*< Offset into the log*/
 uint32_t count; /*< Number of bytes*/
 uint16_t id; /*< Log id (from LOG_ENTRY reply)*/
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
}) mavlink_log_request_data_t;

#define MAVLINK_MSG_ID_LOG_REQUEST_DATA_LEN 12
#define MAVLINK_MSG_ID_LOG_REQUEST_DATA_MIN_LEN 12
#define MAVLINK_MSG_ID_119_LEN 12
#define MAVLINK_MSG_ID_119_MIN_LEN 12

#define MAVLINK_MSG_ID_LOG_REQUEST_DATA_CRC 116
#define MAVLINK_MSG_ID_119_CRC 116



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LOG_REQUEST_DATA { \
    119, \
    "LOG_REQUEST_DATA", \
    5, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_log_request_data_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_log_request_data_t, target_component) }, \
         { "id", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_log_request_data_t, id) }, \
         { "ofs", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_log_request_data_t, ofs) }, \
         { "count", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_log_request_data_t, count) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LOG_REQUEST_DATA { \
    "LOG_REQUEST_DATA", \
    5, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_log_request_data_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_log_request_data_t, target_component) }, \
         { "id", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_log_request_data_t, id) }, \
         { "ofs", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_log_request_data_t, ofs) }, \
         { "count", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_log_request_data_t, count) }, \
         } \
}
#endif

/**
 * @brief Pack a log_request_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param id Log id (from LOG_ENTRY reply)
 * @param ofs Offset into the log
 * @param count Number of bytes
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_log_request_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint16_t id, uint32_t ofs, uint32_t count)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LOG_REQUEST_DATA_LEN];
    _mav_put_uint32_t(buf, 0, ofs);
    _mav_put_uint32_t(buf, 4, count);
    _mav_put_uint16_t(buf, 8, id);
    _mav_put_uint8_t(buf, 10, target_system);
    _mav_put_uint8_t(buf, 11, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LOG_REQUEST_DATA_LEN);
#else
    mavlink_log_request_data_t packet;
    packet.ofs = ofs;
    packet.count = count;
    packet.id = id;
    packet.target_system = target_system;
    packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LOG_REQUEST_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LOG_REQUEST_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LOG_REQUEST_DATA_MIN_LEN, MAVLINK_MSG_ID_LOG_REQUEST_DATA_LEN, MAVLINK_MSG_ID_LOG_REQUEST_DATA_CRC);
}

/**
 * @brief Pack a log_request_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param id Log id (from LOG_ENTRY reply)
 * @param ofs Offset into the log
 * @param count Number of bytes
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_log_request_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint16_t id,uint32_t ofs,uint32_t count)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LOG_REQUEST_DATA_LEN];
    _mav_put_uint32_t(buf, 0, ofs);
    _mav_put_uint32_t(buf, 4, count);
    _mav_put_uint16_t(buf, 8, id);
    _mav_put_uint8_t(buf, 10, target_system);
    _mav_put_uint8_t(buf, 11, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LOG_REQUEST_DATA_LEN);
#else
    mavlink_log_request_data_t packet;
    packet.ofs = ofs;
    packet.count = count;
    packet.id = id;
    packet.target_system = target_system;
    packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LOG_REQUEST_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LOG_REQUEST_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LOG_REQUEST_DATA_MIN_LEN, MAVLINK_MSG_ID_LOG_REQUEST_DATA_LEN, MAVLINK_MSG_ID_LOG_REQUEST_DATA_CRC);
}

/**
 * @brief Encode a log_request_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param log_request_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_log_request_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_log_request_data_t* log_request_data)
{
    return mavlink_msg_log_request_data_pack(system_id, component_id, msg, log_request_data->target_system, log_request_data->target_component