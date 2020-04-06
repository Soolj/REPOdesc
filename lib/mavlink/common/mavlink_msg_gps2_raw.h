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
 uint8_t satellites_visible; /*< Number of satellites visible. If unknown, set to 255*/
 uint8_t dgps_numch; /*< Number of DGPS satellites*/
}) mavlink_gps2_raw_t;

#define MAVLINK_MSG_ID_GPS2_RAW_LEN 35
#define MAVLINK_MSG_ID_GPS2_RAW_MIN_LEN 35
#define MAVLINK_MSG_ID_124_LEN 35
#define MAVLINK_MSG_ID_124_MIN_LEN 35

#define MAVLINK_MSG_ID_GPS2_RAW_CRC 87
#define MAVLINK_MSG_ID_124_CRC 87



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GPS2_RAW { \
    124, \
    "GPS2_RAW", \
    12, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_gps2_raw_t, time_usec) }, \
         { "fix_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_gps2_raw_t, fix_type) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_gps2_raw_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_gps2_raw_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_gps2_raw_t, alt) }, \
         { "eph", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_gps2_raw_t, eph) }, \
         { "epv", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_gps2_raw_t, epv) }, \
         { "vel", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_gps2_raw_t, vel) }, \
         { "cog", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_gps2_raw_t, cog) }, \
         { "satellites_visible", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_gps2_raw_t, satellites_visible) }, \
         { "dgps_numch", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_gps2_raw_t, dgps_numch) }, \
         { "dgps_age", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_gps2_raw_t, dgps_age) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GPS2_RAW { \
    "GPS2_RAW", \
    12, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_gps2_raw_t, time_usec) }, \
         { "fix_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_gps2_raw_t, fix_type) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_gps2_raw_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_gps2_raw_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_gps2_raw_t, alt) }, \
         { "eph", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_gps2_raw_t, eph) }, \
         { "epv", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_gps2_raw_t, epv) }, \
         { "vel", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_gps2_raw_t, vel) }, \
         { "cog", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_gps2_raw_t, cog) }, \
         { "satellites_visible", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_gps2_raw_t, satellites_visible) }, \
         { "dgps_numch", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_gps2_raw_t, dgps_numch) }, \
         { "dgps_age", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_gps2_raw_t, dgps_age) }, \
         } \
}
#endif

/**
 * @brief Pack a gps2_raw message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param fix_type See the GPS_FIX_TYPE enum.
 * @param lat Latitude (WGS84), in degrees * 1E7
 * @param lon Longitude (WGS84), in degrees * 1E7
 * @param alt Altitude (AMSL, not WGS84), in meters * 1000 (positive for up)
 * @param eph GPS HDOP horizontal dilution of position in cm (m*100). If unknown, set to: UINT16_MAX
 * @param epv GPS VDOP vertical dilution of position in cm (m*100). If unknown, set to: UINT16_MAX
 * @param vel GPS ground speed (m/s * 100). If unknown, set to: UINT16_MAX
 * @param cog Course over ground (NOT heading, but direction of movement) in degrees * 100, 0.0..359.99 degrees. If unknown, set to: UINT16_MAX
 * @param satellites_visible Number of satellites visible. If unknown, set to 255
 * @param dgps_numch Number of DGPS satellites
 * @param dgps_age Age of DGPS info
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps2_raw_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint8_t fix_type, int32_t lat, int32_t lon, int32_t alt, uint16_t eph, uint16_t epv, uint16_t vel, uint16_t cog, uint8_t satellites_visible, uint8_t dgps_numch, uint32_t dgps_age)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GPS2_RAW_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, lat);
    _mav_put_int32_t(buf, 12, lon);
    _mav_put_int32_t(buf, 16, alt);
    _mav_put_uint32_t(buf, 20, dgps_age);
    _mav_put_uint16_t(buf, 24, eph);
    _mav_put_uint16_t(buf, 26, epv);
    _mav_put_uint16_t(buf, 28, vel);
    _mav_put_uint16_t(buf, 30, cog);
    _mav_put_uint8_t(buf, 32, fix_type);
    _mav_put_uint8_t(buf, 33, satellites_visible);
    _mav_put_uint8_t(buf, 34, dgps_numch);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPS2_RAW_LEN);
#else
    mavlink_gps2_raw_t packet;
    packet.time_usec = time_usec;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.dgps_age = dgps_age;
    packet.eph = eph;
    packet.epv = epv;
    packet.vel = vel;
    packet.cog = cog;
    packet.fix_type = fix_type;
    packet.satellites_visible = satellites_visible;
    packet.dgps_numch = dgps_numch;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPS2_RAW_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GPS2_RAW;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GPS2_RAW_MIN_LEN, MAVLINK_MSG_ID_GPS2_RAW_LEN, MAVLINK_MSG_ID_GPS2_RAW_CRC);
}

/**
 * @brief Pack a gps2_raw message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param fix_type See the GPS_FIX_TYPE enum.
 * @param lat Latitude (WGS84), in degrees * 1E7
 * @param lon Longitude (WGS84), in degrees * 1E7
 * @param alt Altitude (AMSL, not WGS84), in meter