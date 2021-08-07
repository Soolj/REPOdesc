#pragma once
// MESSAGE RC_CHANNELS_RAW PACKING

#define MAVLINK_MSG_ID_RC_CHANNELS_RAW 35

MAVPACKED(
typedef struct __mavlink_rc_channels_raw_t {
 uint32_t time_boot_ms; /*< Timestamp (milliseconds since system boot)*/
 uint16_t chan1_raw; /*< RC channel 1 value, in microseconds. A value of UINT16_MAX implies the channel is unused.*/
 uint16_t chan2_raw; /*< RC channel 2 value, in microseconds. A value of UINT16_MAX implies the channel is unused.*/
 uint16_t chan3_raw; /*< RC channel 3 value, in microseconds. A value of UINT16_MAX implies the channel is unused.*/
 uint16_t chan4_raw; /*< RC channel 4 value, in microseconds. A value of UINT16_MAX implies the channel is unused.*/
 uint16_t chan5_raw; /*< RC channel 5 value, in microseconds. A value of UINT16_MAX implies the channel is unused.*/
 uint16_t chan6_raw; /*< RC channel 6 value, in microseconds. A value of UINT16_MAX implies the channel is unused.*/
 uint16_t chan7_raw; /*< RC channel 7 value, in microseconds. A value of UINT16_MAX implies the channel is unused.*/
 uint16_t chan8_raw; /*< RC channel 8 value, in microseconds. A value of UINT16_MAX implies the channel is unused.*/
 uint8_t port; /*< Servo output port (set of 8 outputs = 1 port). Most MAVs will just use one, but this allows for more than 8 servos.*/
 uint8_t rssi; /*< Receive signal strength indicator, 0: 0%, 100: 100%, 255: invalid/unknown.*/
}) mavlink_rc_channels_raw_t;

#define MAVLINK_MSG_ID_RC_CHANNELS_RAW_LEN 22
#define MAVLINK_MSG_ID_RC_CHANNELS_RAW_MIN_LEN 22
#define MAVLINK_MSG_ID_35_LEN 22
#define MAVLINK_MSG_ID_35_MIN_LEN 22

#define MAVLINK_MSG_ID_RC_CHANNELS_RAW_CRC 244
#define MAVLINK_MSG_ID_35_CRC 244



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RC_CHANNELS_RAW { \
    35, \
    "RC_CHANNELS_RAW", \
    11, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_rc_channels_raw_t, time_boot_ms) }, \
         { "port", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_rc_channels_raw_t, port) }, \
         { "chan1_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_rc_channels_raw_t, chan1_raw) }, \
         { "chan2_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_rc_channels_raw_t, chan2_raw) }, \
         { "chan3_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_rc_channels_raw_t, chan3_raw) }, \
         { "chan4_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavli