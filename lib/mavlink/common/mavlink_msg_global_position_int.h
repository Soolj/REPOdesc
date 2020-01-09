#pragma once
// MESSAGE GLOBAL_POSITION_INT PACKING

#define MAVLINK_MSG_ID_GLOBAL_POSITION_INT 33

MAVPACKED(
typedef struct __mavlink_global_position_int_t {
 uint32_t time_boot_ms; /*< Timestamp (milliseconds since system boot)*/
 int32_t lat; /*< Latitude, expressed as degrees * 1E7*/
 int32_t lon; /*< Longitude, expressed as degrees * 1E7*/
 int32_t alt; /*< Altitude in meters, expressed as * 1000 (millimeters), AMSL (not WGS84 - note that virtually all GPS modules provide the AMSL as well)*/
 int32_t relative_alt; /*< Altitude above ground in meters, expressed as * 1000 (millimeters)*/
 int16_t vx; /*< Ground X Speed (Latitude, positive north), expressed as m/s * 100*/
 int16_t vy; /*< Ground Y Speed (Longitude, positive east), expressed as m/s * 100*/
 int16_t vz; /*< Ground Z Speed (Altitude, positive down), expressed as m/s * 100*/
 uint16_t hdg; /*< Vehicle heading (yaw angle) in degrees * 100, 0.0..359.99 degrees. If unknown, set to: UINT16_MAX*/
}) mavlink_global_position_int_t;

#define MAVLINK_MSG_ID_GLOBAL_POSITION_INT_LEN 28
#define MAVLINK_MSG_ID_GLOBAL_POSITION_INT_MIN_LEN 28
#define MAVLINK_MSG_ID_33_LEN 28
#define MAVLINK_MSG_ID_33_MIN_LEN 28

#define MAVLINK_MSG_ID_GLOBAL_POSITION_INT_CRC 104
#define MAVLINK_MSG_ID_33_CRC 104



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GLOBAL_POSITION_INT { \
    33, \
    "GLOBAL_POSITION_INT", \
    9, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_global_position_int_t, time_boot_ms) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_global_position_int_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_global_position_int_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_global_position_int_t, alt) }, \
         { "relative_alt", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_global_position_int_t, relative_alt) }, \
         { "vx", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_global_position_int_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_global_position_int_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_global_position_int_t, vz) }, \
         { "hdg", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(m