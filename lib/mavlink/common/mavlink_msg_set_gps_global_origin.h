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
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_set_gps_global_origin_t, altitude) }, \
         { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 13, offsetof(mavlink_set_gps_global_origin_t, time_usec) }, \
         } \
}
#endif

/**
 * @brief Pack a set_gps_global_origin message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param latitude Latitude (WGS84), in degrees * 1E7
 * @param longitude Longitude (WGS84), in degrees * 1E7
 * @param altitude Altitude (AMSL), in meters * 1000 (positive for up)
 * @param time_usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_gps_global_origin_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, int32_t latitude, int32_t longitude, int32_t altitude, uint64_t time_usec)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN_LEN];
    _mav_put_int32_t(buf, 0, latitude);
    _mav_put_int32_t(buf, 4, longitude);
    _mav_put_int32_t(buf, 8, altitude);
    _mav_put_uint8_t(buf, 12, target_system);
    _mav_put_uint64_t(buf, 13, time_usec);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN_LEN);
#else
    mavlink_set_gps_global_origin_t packet;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;
    packet.target_system = target_system;
    packet.time_usec = time_usec;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN_MIN_LEN, MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN_LEN, MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN_CRC);
}

/**
 * @brief Pack a set_gps_global_origin message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param latitude Latitude (WGS84), in degrees * 1E7
 * @param longitude Longitude (WGS84), in degrees * 1E7
 * @param altitude Altitude (AMSL), in meters * 1000 (positive for up)
 * @param time_usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_gps_global_origin_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,int32_t latitude,int32_t longitude,int32_t altitude,uint64_t time_usec)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN_LEN];
    _mav_put_int32_t(buf, 0, latitude);
    _mav_put_int32_t(buf, 4, longitude);
    _mav_put_int32_t(buf, 8, altitude);
    _mav_put_uint8_t(buf, 12, target_system);
    _mav_put_uint64_t(buf, 13, time_usec);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN_LEN);
#else
    mavlink_set_gps_global_origin_t packet;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;
    packet.target_system = target_system;
    packet.time_usec = time_usec;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN_MIN_LEN, MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN_LEN, MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN_CRC);
}

/**
 * @brief Encode a set_gps_global_origin struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param set_gps_global_origin C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_gps_global_origin_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_set_gps_global_origin_t* set_gps_global_origin)
{
    return mavlink_msg_set_gps_global_origin_pack(system_id, component_id, msg, set_gps_global_origin->target_system, set_gps_global_origin->latitude, set_gps_global_origin->longitude, set_gps_global_origin->altitude, set_gps_global_origin->time_usec);
}

/**
 * @brief Encode a set_gps_global_origin struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param set_gps_global_origin C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_gps_global_origin_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_set_gps_global_origin_t* set_gps_global_origin)
{
    return mavlink_msg_set_gps_global_origin_pack_chan(system_id, component_id, chan, msg, set_gps_global_origin->target_system, set_gps_global_origin->latitude, set_gps_global_origin->longitude, set_gps_global_origin->altitude, set_gps_global_origin->time_usec);
}

/**
 * @brief Send a set_gps_global_origin message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param latitude Latitude (WGS84), in degrees * 1E7
 * @param longitude Longitude (WGS84), in degrees * 1E7
 * @param altitude Altitude (AMSL), in meters * 1000 (positive for up)
 * @param time_usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 */
#ifdef MAV