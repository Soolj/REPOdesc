#pragma once
// MESSAGE GPS_RAW_INT PACKING

#define MAVLINK_MSG_ID_GPS_RAW_INT 24

MAVPACKED(
typedef struct __mavlink_gps_raw_int_t {
 uint64_t time_usec; /*< Timestamp (microseconds since UNIX epoch or microseconds since system boot)*/
 int32_t lat; /*< Latitude (WGS84, EGM96 ellipsoid), in degrees * 1E7*/
 int32_t lon; /*< Longitude (WGS84, EGM96 ellipsoid), in degrees * 1E7*/
 int32_t alt; /*< Altitude (AMSL, NOT WGS84), in meters * 1000 (positive for up). Note that virtually all GPS modules provide the AMSL altitude in addition to the WGS84 altitude.*/
 uint16_t eph; /*< GPS HDOP horizontal dilution of position (unitless). If unknown, set to: UINT16_MAX*/
 uint16_t epv; /*< GPS VDOP vertical dilution of position (unitless). If unknown, set to: UINT16_MAX*/
 uint16_t vel; /*< GPS ground speed (m/s * 100). If unknown, set to: UINT16_MAX*/
 uint16_t cog; /*< Course over ground (NOT heading, but direction of movement) in degrees * 100, 0.0..359.99 degrees. If unknown, set to: UINT16_MAX*/
 uint8_t fix_type; /*< See the GPS_FIX_TYPE enum.*/
 uint8_t satellites_visible; /*< Number of satellites visible. If unknown, set to 255*/
 int32_t alt_ellipsoid; /*< Altitude (above WGS84, EGM96 ellipsoid), in meters * 1000 (positive for up).*/
 uint32_t h_acc; /*< Position uncertainty in meters * 1000 (positive for up).*/
 uint32_t v_acc; /*< Altitude uncertainty in meters * 1000 (positive for up).*/
 uint32_t vel_acc; /*< Speed uncertainty in meters * 1000 (positive for up).*/
 uint32_t hdg_acc; /*< Heading / track uncertainty in degrees * 1e5.*/
}) mavlink_gps_raw_int_t;

#define MAVLINK_MSG_ID_GPS_RAW_INT_LEN 50
#define MAVLINK_MSG_ID_GPS_RAW_INT_MIN_LEN 30
#define MAVLINK_MSG_ID_24_LEN 50
#define MAVLINK_MSG_ID_24_MIN_LEN 30

#define MAVLINK_MSG_ID_GPS_RAW_INT_CRC 24
#define MAVLINK_MSG_ID_24_CRC 24



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GPS_RAW_INT { \
    24, \
    "GPS_RAW_INT", \
    15, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_gps_raw_int_t, time_usec) }, \
         { "fix_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_gps_raw_int_t, fix_type) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_gps_raw_int_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_gps_raw_int_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_gps_raw_int_t, alt) }, \
         { "eph", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_gps_raw_int_t, eph) }, \
         { "epv", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_gps_raw_int_t, epv) }, \
         { "vel", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_gps_raw_int_t, vel) }, \
         { "cog", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_gps_raw_int_t, cog) }, \
         { "satellites_visible", NULL, MAVLINK_TYPE_UINT8_T, 0, 29, offsetof(mavlink_gps_raw_int_t, satellites_visible) }, \
         { "alt_ellipsoid", NULL, MAVLINK_TYPE_INT32_T, 0, 30, offsetof(mavlink_gps_raw_int_t, alt_ellipsoid) }, \
         { "h_acc", NULL, MAVLINK_TYPE_UINT32_T, 0, 34, offsetof(mavlink_gps_raw_int_t, h_acc) }, \
         { "v_acc", NULL, MAVLINK_TYPE_UINT32_T, 0, 38, offsetof(mavlink_gps_raw_int_t, v_acc) }, \
         { "vel_acc", NULL, MAVLINK_TYPE_UINT32_T, 0, 42, offsetof(mavlink_gps_raw_int_t, vel_acc) }, \
         { "hdg_acc", NULL, MAVLINK_TYPE_UINT32_T, 0, 46, offsetof(mavlink_gps_raw_int_t, hdg_acc) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GPS_RAW_INT { \
    "GPS_RAW_INT", \
    15, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_gps_raw_int_t, time_usec) }, \
         { "fix_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_gps_raw_int_t, fix_type) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_gps_raw_int_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_gps_raw_int_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_gps_raw_int_t, alt) }, \
         { "eph", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_gps_raw_int_t, eph) }, \
         { "epv", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_gps_raw_int_t, epv) }, \
         { "vel", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_gps_raw_int_t, vel) }, \
         { "cog", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_gps_raw_int_t, cog) }, \
         { "satellites_visible", NULL, MAVLINK_TYPE_UINT8_T, 0, 29, offsetof(mavlink_gps_raw_int_t, satellites_visible) }, \
         { "alt_ellipsoid", NULL, MAVLINK_TYPE_INT32_T, 0, 30, offsetof(mavlink_gps_raw_int_t, alt_ellipsoid) }, \
         { "h_acc", NULL, MAVLINK_TYPE_UINT32_T, 0, 34, offsetof(mavlink_gps_raw_int_t, h_acc) }, \
         { "v_acc", NULL, MAVLINK_TYPE_UINT32_T, 0, 38, offsetof(mavlink_gps_raw_int_t, v_acc) }, \
         { "vel_acc", NULL, MAVLINK_TYPE_UINT32_T, 0, 42, offsetof(mavlink_gps_raw_int_t, vel_acc) }, \
         { "hdg_acc", NULL, MAVLINK_TYPE_UINT32_T, 0, 46, offsetof(mavlink_gps_raw_int_t, hdg_acc) }, \
         } \
}
#endif

/**
 * @brief Pack a gps_raw_int message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param fix_type See the GPS_FIX_TYPE enum.
 * @param lat Latitude (WGS84, EGM96 ellipsoid), in degrees * 1E7
 * @param lon Longitude (WGS84, EGM96 ellipsoid), in degrees * 1E7
 * @param alt Altitude (AMSL, NOT WGS84), in meters * 1000 (positive for up). Note that virtually all GPS modules provide the AMSL altitude in addition to the WGS84 altitude.
 * @param eph GPS HDOP horizontal dilution of position (unitless). If unknown, set to: UINT16_MAX
 * @param epv GPS VDOP vertical dilution of position (unitless). If unknown, set to: UINT16_MAX
 * @param vel GPS ground speed (m/s * 100). If unknown, set to: UINT16_MAX
 * @param cog Course over ground (NOT heading, but direction of movement) in degrees * 100, 0.0..359.99 degrees. If unknown, set to: UINT16_MAX
 * @param satellites_visible Number of satellites visible. If unknown, set to 255
 * @param alt_ellipsoid Altitude (above WGS84, EGM96 ellipsoid), in meters * 1000 (positive for up).
 * @param h_acc Position uncertainty in meters * 1000 (positive for up).
 * @param v_acc Altitude uncertainty in meters * 1000 (positive for up).
 * @param vel_acc Speed uncertainty in met