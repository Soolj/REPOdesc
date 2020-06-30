#pragma once
// MESSAGE GPS_GLOBAL_ORIGIN PACKING

#define MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN 49

MAVPACKED(
typedef struct __mavlink_gps_global_origin_t {
 int32_t latitude; /*< Latitude (WGS84), in degrees * 1E7*/
 int32_t longitude; /*< Longitude (WGS84), in degrees * 1E7*/
 int32_t altitude; /*< Altitude (AMSL), in meters * 1000 (positive for up)*/
 uint64_t time_usec; /*< Timestamp (microseconds since UNIX epoch or microseconds since system boot)*/
}) mavli