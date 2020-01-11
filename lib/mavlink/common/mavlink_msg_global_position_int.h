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
         { "hdg", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_global_position_int_t, hdg) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GLOBAL_POSITION_INT { \
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
         { "hdg", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_global_position_int_t, hdg) }, \
         } \
}
#endif

/**
 * @brief Pack a global_position_int message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms Timestamp (milliseconds since system boot)
 * @param lat Latitude, expressed as degrees * 1E7
 * @param lon Longitude, expressed as degrees * 1E7
 * @param alt Altitude in meters, expressed as * 1000 (millimeters), AMSL (not WGS84 - note that virtually all GPS modules provide the AMSL as well)
 * @param relative_alt Altitude above ground in meters, expressed as * 1000 (millimeters)
 * @param vx Ground X Speed (Latitude, positive north), expressed as m/s * 100
 * @param vy Ground Y Speed (Longitude, positive east), expressed as m/s * 100
 * @param vz Ground Z Speed (Altitude, positive down), expressed as m/s * 100
 * @param hdg Vehicle heading (yaw angle) in degrees * 100, 0.0..359.99 degrees. If unknown, set to: UINT16_MAX
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_global_position_int_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, int32_t lat, int32_t lon, int32_t alt, int32_t relative_alt, int16_t vx, int16_t vy, int16_t vz, uint16_t hdg)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GLOBAL_POSITION_INT_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_int32_t(buf, 4, lat);
    _mav_put_int32_t(buf, 8, lon);
    _mav_put_int32_t(buf, 12, alt);
    _mav_put_int32_t(buf, 16, relative_alt);
    _mav_put_int16_t(buf, 20, vx);
    _mav_put_int16_t(buf, 22, vy);
    _mav_put_int16_t(buf, 24, vz);
    _mav_put_uint16_t(buf, 26, hdg);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GLOBAL_POSITION_INT_LEN);
#else
    mavlink_global_position_int_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.lat = lat;
    packet.lon = lon;
   