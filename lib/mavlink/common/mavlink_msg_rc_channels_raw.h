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
 uint16_t chan6