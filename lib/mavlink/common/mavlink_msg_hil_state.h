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
 * @par