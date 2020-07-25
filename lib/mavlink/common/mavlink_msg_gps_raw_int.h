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



