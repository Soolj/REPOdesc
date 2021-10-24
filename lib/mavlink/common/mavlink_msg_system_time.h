#pragma once
// MESSAGE SYSTEM_TIME PACKING

#define MAVLINK_MSG_ID_SYSTEM_TIME 2

MAVPACKED(
typedef struct __mavlink_system_time_t {
 uint64_t time_unix_usec; /*< Timestamp of the master clock in microseconds since UNIX epoch.*/
 uint32_t time_boot_ms; /*< Timestamp of the component clock since boot time in milliseconds.*/
}) mavlink_system_time_t;

#define MAVLINK_MSG_ID_SYSTEM_TIME_LEN 12
#define MAVLINK_MSG_ID_SYSTEM_TIME_MIN_LEN 12
#define MAVLINK_MSG_ID_2_LEN 12
#define MAVLINK_MSG_ID_2_MIN_LEN 12

#define MAVLINK_MSG_ID_SYSTEM_TIME_CRC 137
#define MAVLINK_MSG_ID_2_CRC 137



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SYSTEM_TIME { \
    2, \
    "SYSTEM_TIME", \
    2, \
    {  { "time_unix_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_system_time_t, time_unix_usec) }, \
         { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_system_time_t, time_boot_ms) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SYSTEM_TIME { \
    "SYSTEM_TIME", \
    2, \
    {  { "time_unix_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_system_time_t, time_unix_usec) }, \
         { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_system_time_t, time_boot_ms) }, \
         } \
}
#endif

/**
 * @brief Pack a system_time message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_unix_usec Timestamp of the master clock in microseconds since UNIX epoch.
 * @param time_boot_ms Timestamp of the component clock since boot time in milliseconds.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_system_time_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_unix_usec, uint32_t time_boot_ms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYSTEM_TIME_LEN];
    _mav_put_uint64_t(buf, 0, time_unix_usec);
    _mav_put_uint32_t(buf, 8, time_boot_ms);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SYSTEM_TIME_LEN);
#else
    mavlink_system_time_t packet;
    packet.time_unix_usec = time_unix_usec;
    packet.time_boot_ms = time_boot_ms;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SYSTEM_TIME_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SYSTEM_TIME;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SYSTEM_TIME_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_CRC);
}

/**
 * @brief Pack a system_time message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for I