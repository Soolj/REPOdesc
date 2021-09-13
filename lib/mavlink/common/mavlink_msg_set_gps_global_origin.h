#pragma once
// MESSAGE SET_GPS_GLOBAL_ORIGIN PACKING

#define MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN 48

MAVPACKED(
typedef struct __mavlink_set_gps_global_origin_t {
 int32_t latitude; /*< Latitude (WGS84), in degrees * 1E7*/
 int32_t longitude; /*< Longitude (WGS84), in degrees * 1E7*/
 int32_t altitude; /*< Altitude (AMSL), in meters * 1000 (positive for up)*/
 uint8_t target_system; /*< System ID*/
 uint64_t time_usec; /*< Timestamp (microseconds since UNIX epoch or microseconds since system boot)*/
}) mavlink_set_gps_global_origin_t;

#define MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN_LEN 21
#define MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN_MIN_LEN 13
#define MAVLINK_MSG_ID_48_LEN 21
#define MAVLINK_MSG_ID_48_MIN_LEN 13

#define MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN_CRC 41
#define MAVLINK_MSG_ID_48_CRC 41



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SET_GPS_GLOBAL_ORIGIN { \
    48, \
    "SET_GPS_GLOBAL_ORIGIN", \
    5, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_set_gps_global_origin_t, target_system) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_set_gps_global_origin_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_set_gps_global_origin_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_set_gps_global_origin_t, altitude) }, \
         { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 13, offsetof(mavlink_set_gps_global_origin_t, time_usec) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SET_GPS_GLOBAL_ORIGIN { \
    "SET_GPS_GLOBAL_ORIGIN", \
    5, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_set_gps_global_origin_t, target_system) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_set_gps_global_origin_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_set_gps_global_origin_t, longitude) }, \
         