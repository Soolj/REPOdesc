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
    _mav_put_uint16