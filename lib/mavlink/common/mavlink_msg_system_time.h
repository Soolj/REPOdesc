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
         { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_system_time_t, time_boot_ms) }, 