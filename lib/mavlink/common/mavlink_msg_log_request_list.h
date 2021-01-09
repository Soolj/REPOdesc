#pragma once
// MESSAGE LOG_REQUEST_LIST PACKING

#define MAVLINK_MSG_ID_LOG_REQUEST_LIST 117

MAVPACKED(
typedef struct __mavlink_log_request_list_t {
 uint16_t start; /*< First log id (0 for first available)*/
 uint16_t end; /*< Last log id (0xffff for last available)*/
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
}) mavlink_log_request_list_t;

#define MAVLINK_MSG_ID_LOG_REQUEST_LIST_LEN 6
#define MAVLINK_MSG_ID_LOG_REQUEST_LIST_MIN_LEN 6
#define MAVLINK_MSG_ID_117_LEN 6
#define MAVLINK_MSG_ID_117_MIN_LEN 6

#define MAVLINK_MSG_ID_LOG_REQUEST_LIST_CRC 128
#define MAVLINK_MSG_ID_117_CRC 128



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LOG_REQUEST_LIST { \
    117, \
    "LOG_REQUEST_LIST", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_log_request_list_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_log_request_list_t, target_component) }, \
         { "start", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_log_request_list_t, start) }, \
         { "end", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_log_request_list_t, end) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LOG_REQUEST_LIST { \
    "LOG_REQUEST_LIST", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_log_request_list_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_log_request_list_t, target_component) }, \
         { "start", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_log_request_list_t, start) }, \
         { "end", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_log_request_list_t, end) }, \
         } \
}
#endif

/**
 * @brief Pack a log_request_list message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param start First log id (0 for first available)
 * @param end Last log id (0xffff for last available)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_log_request_list_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint16_t start, uint16_t end)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LOG_REQUEST_LIST_LEN];
    _mav_put_uint16_t(buf, 0, start);
    _mav_put_uint16_t(buf, 2, end);
    _mav_put_uint8_t(buf, 4, target_system);
    _mav_put_uint8_t(buf, 5, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LOG_REQUEST_LIST_LEN);
#else
    mavlink_log_request_list_t packet;
    packet.start = start;
    packet.end = end;
    packet.target_system = target_system;
    packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LOG_REQUEST_LIST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LOG_REQUEST_LIST;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LOG_REQUEST_LIST_MIN_LEN, MAVLINK_MSG_ID_LOG_REQUEST_LIST_LEN, MAVLINK_MSG_ID_LOG_REQUEST_LIST_CRC);
}

/**
 * @brief Pack a log_request_list message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param start First log id (0 for first available)
 * @param end Last log id (0xffff for last available)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_log_request_list_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint16_t start,uint16_t end)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LOG_REQUEST_LIST_LEN];
    _mav_put_uint16_t(buf, 0, start);
    _mav_put_uint16_t(buf, 2, end);
    _mav_put_uint8_t(buf, 4, target_system);
    _mav_put_uint8_t(buf, 5, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LOG_REQUEST_LIST_LEN);
#else
    mavlink_log_request_list_t packet;
    packet.start = start;
    packet.end = end;
    packet.target_system = target_system;
    packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LOG_REQUEST_LIST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LOG_REQUEST_LIST;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LOG_REQUEST_LIST_MIN_LEN, MAVLINK_MSG_ID_LOG_REQUEST_LIST_LEN, MAVLINK_MSG_ID_LOG_REQUEST_LIST_CRC);
}

/**
 * @brief Encode a log_request_list struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 f