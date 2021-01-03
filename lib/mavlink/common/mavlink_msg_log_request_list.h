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
 * @param end Last l