#pragma once
// MESSAGE GPS_INJECT_DATA PACKING

#define MAVLINK_MSG_ID_GPS_INJECT_DATA 123

MAVPACKED(
typedef struct __mavlink_gps_inject_data_t {
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 uint8_t len; /*< data length*/
 uint8_t data[110]; /*< raw data (110 is enough for 12 satellites of RTCMv2)*/
}) mavlink_gps_inject_data_t;

#define MAVLINK_