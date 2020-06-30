#pragma once
// MESSAGE GPS_GLOBAL_ORIGIN PACKING

#define MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN 49

MAVPACKED(
typedef struct __mavlink_gps_global_origin_t {
 int32_t latitude; /*< Latitude (WGS84), in degrees * 1E7*/
 int32_t longitude; /*< Longitude (WGS84), in degrees * 1E7*/
 int32_t altitude; /*< Altitude (AMSL), in meters * 1000 (positive for up)*/
 uint64_t time_usec; /*< Timestamp (microseconds since UNIX epoch or microseconds since system boot)*/
}) mavlink_gps_global_origin_t;

#define MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN_LEN 20
#define MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN_MIN_LEN 12
#define MAVLINK_MSG_ID_49_LEN 20
#define MAVLINK_MSG_ID_49_MIN_LEN 12

#define MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN_CRC 39
#define MAVLINK_MSG_ID_49_CRC 39



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GPS_GLOBAL_ORIGIN { \
    49, \
    "GPS_GLOBAL_ORIGIN", \
    4, \
    {  { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_gps_global_origin_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_gps_global_origin_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_gps_global_origin_t, altitude) }, \
         { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 12, offsetof(mavlink_gps_global_origin_t, time_usec) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GPS_GLOBAL_ORIGIN { \
    "GPS_GLOBAL_ORIGIN", \
    4, \
    {  { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_gps_global_origin_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_gps_global_origin_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_gps_global_origin_t, altitude) }, \
         { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 12, offsetof(mavlink_gps_global_origin_t, time_usec) }, \
         } \
}
#endif

/**
 * @brief Pack a gps_global_origin message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 