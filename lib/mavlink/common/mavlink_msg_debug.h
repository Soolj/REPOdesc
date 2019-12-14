#pragma once
// MESSAGE DEBUG PACKING

#define MAVLINK_MSG_ID_DEBUG 254

MAVPACKED(
typedef struct __mavlink_debug_t {
 uint32_t time_boot_ms; /*< Timestamp (milliseconds since system boot)*/
 float value; /*< DEBUG value*/
 uint8_t ind; /*< index of debug variable*/
}) mavlink_debug_t;

#define MAVLINK_MSG_ID_DEBUG_LEN 9
#define MAVLINK_MSG_ID_DEBUG_MIN_LEN 9
#define MAVLINK_MSG_ID_254_LEN 9
#define MAVLINK_MSG_ID_254_MIN_LEN 9

#define MAVLINK_MSG_ID_DEBUG_CRC 46
#define MAVLINK_MSG_ID_254_CRC 46



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DEBUG { \
    254, \
    "DEBUG", \
    3, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_debug_t, time_boot_ms) }, \
         { "ind", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_debug_t, ind) }, \
         { "value", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_debug_t, value) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DEBUG { \
    "DEBUG", \
    3, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_debug_t, time_boot_ms) }, \
         { "ind", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_debug_t, ind) }, \
         { "value", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_debug_t, value) }, \
         } \
}
#endif

/**
 * @brief Pack a debug message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms Timestamp (milliseconds since system boot)
 * @param ind index of debug variable
 * @param value DEBUG value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_debug_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint8_t ind, float value)
{
#if MAVLINK_NEED_