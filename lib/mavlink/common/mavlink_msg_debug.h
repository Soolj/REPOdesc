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
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DEBUG_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, value);
    _mav_put_uint8_t(buf, 8, ind);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DEBUG_LEN);
#else
    mavlink_debug_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.value = value;
    packet.ind = ind;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DEBUG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DEBUG;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DEBUG_MIN_LEN, MAVLINK_MSG_ID_DEBUG_LEN, MAVLINK_MSG_ID_DEBUG_CRC);
}

/**
 * @brief Pack a debug message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms Timestamp (milliseconds since system boot)
 * @param ind index of debug variable
 * @param value DEBUG value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_debug_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint8_t ind,float value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DEBUG_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, value);
    _mav_put_uint8_t(buf, 8, ind);

      