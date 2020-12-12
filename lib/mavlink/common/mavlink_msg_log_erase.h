#pragma once
// MESSAGE LOG_ERASE PACKING

#define MAVLINK_MSG_ID_LOG_ERASE 121

MAVPACKED(
typedef struct __mavlink_log_erase_t {
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
}) mavlink_log_erase_t;

#define MAVLINK_MSG_ID_LOG_ERASE_LEN 2
#define MAVLINK_MSG_ID_LOG_ERASE_MIN_LEN 2
#define MAVLINK_MSG_ID_121_LEN 2
#define MAVLINK_MSG_ID_121_MIN_LEN 2

#define MAVLINK_MSG_ID_LOG_ERASE_CRC 237
#define MAVLINK_MSG_ID_121_CRC 237



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LOG_ERASE { \
    121, \
    "LOG_ERASE", \
    2, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_log_erase_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_log_erase_t, target_component) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LOG_ERASE { \
    "LOG_ERASE", \
    2, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_log_erase_