#pragma once
// MESSAGE GPS2_RAW PACKING

#define MAVLINK_MSG_ID_GPS2_RAW 124

MAVPACKED(
typedef struct __mavlink_gps2_raw_t {
 uint64_t time_usec; /*< Timestamp (microseconds since UNIX epoch or microseconds since system boot)*/
 int32_t lat; /*< Latitude (WGS84), in degrees * 1E7*/
 int32_t lon; /*< Longitude (WGS84), in degrees * 1E7*/
 int32_t alt; /*< Altitude (AMSL, not WGS84), in meters * 1000 (positive for up)*/
 uint32_t dgps_age; /*< Age of DGPS info*/
 uint16_t eph; /*< GPS HDOP horizontal dilution of position in cm (m*100). If unknown, set to: UINT16_MAX*/
 uint16_t epv; /*< GPS VDOP vertical dilution of position in cm (m*100). If unknown, set to: UINT16_MAX*/
 uint16_t vel; /*< GPS ground speed (m/s * 100). If unknown, set to: UINT16_MAX*/
 uint16_t cog; /*< Course over ground (NOT heading, but direction of movement) in degrees * 100, 0.0..359.99 degrees. If unknown, set to: UINT16_MAX*/
 uint8_t fix_type; /*< See the GPS_FIX_TYPE enum.*/
 uint8_t satellites_visible; /*< Number of satellite