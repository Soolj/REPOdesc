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
         { "count", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, 