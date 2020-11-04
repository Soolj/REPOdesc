#pragma once
// MESSAGE HIL_STATE PACKING

#define MAVLINK_MSG_ID_HIL_STATE 90

MAVPACKED(
typedef struct __mavlink_hil_state_t {
 uint64_t time_usec; /*< Timestamp (microseconds since UNIX epoch or microseconds since system boot)*/
 float roll; /*< Roll angle (rad)*/
 float pitch; /*< Pitch angle (rad)*/
 float yaw; /*< Yaw angle (rad)*/
 float rollspeed; /*< Body frame roll / phi angular speed (rad/s)*/
 float pitchspeed; /*< Body frame pitch / theta angular speed (rad/s)*/
 float yawspeed; /*< Body frame yaw / psi angular speed (rad/s)*/
 int32_t lat; /*< Latitude, expressed as degrees * 1E7*/
 int32_t lon; /*< Longitude, expressed as degrees * 1E7*/
 int32_t alt; /*< Altitude in meters, expressed as * 1000 (millimeters)*/
 int16_t vx; /*< Ground X Speed (Latitude), expressed as m/s * 100*/
 int16_t vy; /*< Ground Y Speed (Longitude), expressed as m/s * 100*/
 int16_t vz; /*< Ground Z Speed (Altitude), expressed as m/s * 100*/
 int16_t xacc; /*< X acceleration (mg)*/
 int16_t yacc; /*< Y acceleration (mg)*/
 int16_t zacc; /*< Z acceleration (mg)*/
}) mavlink_hil_state_t;

#define MAVLINK_MSG_ID_HIL_STATE_LEN 56
#define MAVLINK_MSG_ID_HIL_STATE_MIN_LEN 56
#define MAVLINK_MSG_ID_90_LEN 56
#define MAVLINK_MSG_ID_90_MIN_LEN 56

#define MAVLINK_MSG_ID_HIL_STATE_CRC 183
#define MAVLINK_MSG_ID_90_CRC 183



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_HIL_STATE { \
    90, \
    "HIL_STATE", \
    16, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_hil_state_t, time_usec) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_hil_state_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_hil_state_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_hil_state_t, yaw) }, \
         { "rollspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_hil_state_t, rollspeed) }, \
         { "pitchspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_hil_state_t, pitchspeed) }, \
         { "yawspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_hil_state_t, yawspeed) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 32, offsetof(mavlink_hil_state_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 36, offsetof(mavlink_hil_state_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 40, offsetof(mavlink_hil_state_t, alt) }, \
         { "vx", NULL, MAVLINK_TYPE_INT16_T, 0, 44, offsetof(mavlink_hil_state_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_INT16_T, 0, 46, offsetof(mavlink_hil_state_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_INT16_T, 0, 48, offsetof(mavlink_hil_state_t, vz) }, \
         { "xacc", NULL, MAVLINK_TYPE_INT16_T, 0, 50, offsetof(mavlink_hil_state_t, xacc) }, \
         { "yacc", NULL, MAVLINK_TYPE_INT16_T, 0, 52, offsetof(mavlink_hil_state_t, yacc) }, \
         { "zacc", NULL, MAVLINK_TYPE_INT16_T, 0, 54, offsetof(mavlink_hil_state_t, zacc) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_HIL_STATE { \
    "HIL_STATE", \
    16, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_hil_state_t, time_usec) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_hil_state_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_hil_state_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_hil_state_t, yaw) }, \
         { "rollspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_hil_state_t, rollspeed) }, \
         { "pitchspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_hil_state_t, pitchspeed) }, \
         { "yawspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_hil_state_t, yawspeed) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 32, offsetof(mavlink_hil_state_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 36, offsetof(mavlink_hil_state_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 40, offsetof(mavlink_hil_state_t, alt) }, \
         { "vx", NULL, MAVLINK_TYPE_INT16_T, 0, 44, offsetof(mavlink_hil_state_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_INT16_T, 0, 46, offsetof(mavlink_hil_state_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_INT16_T, 0, 48, offsetof(mavlink_hil_state_t, vz) }, \
         { "xacc", NULL, MAVLINK_TYPE_INT16_T, 0, 50, offsetof(mavlink_hil_state_t, xacc) }, \
         { "yacc", NULL, MAVLINK_TYPE_INT16_T, 0, 52, offsetof(mavlink_hil_state_t, yacc) }, \
         { "zacc", NULL, MAVLINK_TYPE_INT16_T, 0, 54, offsetof(mavlink_hil_state_t, zacc) }, \
         } \
}
#endif

/**
 * @brief Pack a hil_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param roll Roll angle (rad)
 * @param pitch Pitch angle (rad)
 * @param yaw Yaw angle (rad)
 * @param rollspeed Body frame roll / phi angular speed (rad/s)
 * @param pitchspeed Body frame pitch / theta angular speed (rad/s)
 * @param yawspeed Body frame yaw / psi angular speed (rad/s)
 * @param lat Latitude, expressed as degrees * 1E7
 * @param lon Longitude, expressed as degrees * 1E7
 * @param alt Altitude in meters, expressed as * 1000 (millimeters)
 * @param vx Ground X Speed (Latitude), expressed as m/s * 100
 * @param vy Ground Y Speed (Longitude), expressed as m/s * 100
 * @param vz Ground Z Speed (Altitude), expressed as m/s * 100
 * @param xacc X acceleration (mg)
 * @param yacc Y acceleration (mg)
 * @param zacc Z acceleration (mg)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_hil_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, float roll, float pitch, float yaw, float rollspeed, float pitchspeed, float yawspeed, int32_t lat, int32_t lon, int32_t alt, int16_t vx, int16_t vy, int16_t vz, int16_t xacc, int16_t yacc, int16_t zacc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HIL_STATE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, roll);
    _mav_put_float(buf, 12, pitch);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, rollspeed);
    _mav_put_float(buf, 24, pitchspeed);
    _mav_put_float(buf, 28, yawspeed);
    _mav_put_int32_t(buf, 32, lat);
    _mav_put_int32_t(buf, 36, lon);
    _mav_put_int32_t(buf, 40, alt);
    _mav_put_int16_t(buf, 44, vx);
    _mav_put_int16_t(buf, 46, vy);
    _mav_put_int16_t(buf, 48, vz);
    _mav_put_int16_t(buf, 50, xacc);
    _mav_put_int16_t(buf, 52, yacc);
    _mav_put_int16_t(buf, 54, zacc);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HIL_STATE_LEN);
#else
    mavlink_hil_state_t packet;
    packet.time_usec = time_usec;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.rollspeed = rollspeed;
    packet.pitchspeed = pitchspeed;
    packet.yawspeed = yawspeed;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.vx = vx;
    packet.vy = vy;
    packet.vz = vz;
    packet.xacc = xacc;
    packet.yacc = yacc;
    packet.zacc = zacc;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HIL_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HIL_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HIL_STATE_MIN_LEN, MAVLINK_MSG_ID_HIL_STATE_LEN, MAVLINK_MSG_ID_HIL_STATE_CRC);
}

/**
 * @brief Pack a hil_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param roll Roll angle (rad)
 * @param pitch Pitch angle (rad)
 * @param yaw Yaw angle (rad)
 * @param rollspeed Body frame roll / phi angular speed (rad/s)
 * @param pitchspeed Body frame pitch / theta angular speed (rad/s)
 * @param yawspeed Body frame yaw / psi angular speed (rad/s)
 * @param lat Latitude, expressed as degrees * 1E7
 * @param lon Longitude, expressed as degrees * 1E7
 * @param alt Altitude in meters, expressed as * 1000 (millimeters)
 * @param vx Ground X Speed (Latitude), expressed as m/s * 100
 * @param vy Ground Y Speed (Longitude), expressed as m/s * 100
 * @param vz Ground Z Speed (Altitude), expressed as m/s * 100
 * @param xacc X acceleration (mg)
 * @param yacc Y acceleration (mg)
 * @param zacc Z acceleration (mg)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_hil_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,float roll,float pitch,float yaw,float rollspeed,float pitchspeed,float yawspeed,int32_t lat,int32_t lon,int32_t alt,int16_t vx,int16_t vy,int16_t vz,int16_t xacc,int16_t yacc,int16_t zacc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HIL_STATE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, roll);
    _mav_put_float(buf, 12, pitch);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, rollspeed);
    _mav_put_float(buf, 24, pitchspeed);
    _mav_put_float(buf, 28, yawspeed);
    _mav_put_int32_t(buf, 32, lat);
    _mav_put_int32_t(buf, 36, lon);
    _mav_put_int32_t(buf, 40, alt);
    _mav_put_int16_t(buf, 44, vx);
    _mav_put_int16_t(buf, 46, vy);
    _mav_put_int16_t(buf, 48, vz);
    _mav_put_int16_t(buf, 50, xacc);
    _mav_put_int16_t(buf, 52, yacc);
    _mav_put_int16_t(buf, 54, zacc);