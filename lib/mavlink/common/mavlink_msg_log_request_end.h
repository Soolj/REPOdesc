#pragma once
// MESSAGE LOG_REQUEST_END PACKING

#define MAVLINK_MSG_ID_LOG_REQUEST_END 122

MAVPACKED(
typedef struct __mavlink_log_request_end_t {
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
}) mavlink_log_request_end_t;

#define MAVLINK_MSG_ID_LOG_REQUEST_END_LEN 2
#define MAVLINK_MSG_ID_LOG_REQUEST_END_MIN_LEN 2
#define MAVLINK_MSG_ID_122_LEN 2
#define MAVLINK_MSG_ID_122_MIN_LEN 2

#define MAVLINK_MSG_ID_LOG_REQUEST_END_CRC 203
#define MAVLINK_MSG_ID_122_CRC 203



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LOG_REQUEST_END { \
    122, \
    "LOG_REQUEST_END", \
    2, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_log_request_end_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_log_request_end_t, target_component) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INF