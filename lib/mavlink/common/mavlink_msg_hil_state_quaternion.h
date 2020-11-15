#pragma once
// MESSAGE HIL_STATE_QUATERNION PACKING

#define MAVLINK_MSG_ID_HIL_STATE_QUATERNION 115

MAVPACKED(
typedef struct __mavlink_hil_state_quaternion_t {
 uint64_t time_usec; /*< Timestamp (microseconds since UNIX epoch or microseconds since system boot)*/
 float attitude_quaternion[4]; /*< Vehicle attitude expressed as normalized quaternion in w, x, y, z order (with 1 0 0 0 being the null-rotation)*/
 float rollspeed; /*< Body frame roll / phi angular speed (rad/s)*/
 float pitchspeed; /*< Body frame pitch / theta angular speed (rad/s)*/
 float yawspeed; /*< Body frame yaw / psi angular speed (rad/s)*/
 int32_t lat; /*< Latitude, expressed as degrees * 1E7*/
 int32_t lon; /*< Longitude, expressed as degrees * 1E7*/
 int32_t alt; /*< Altitude in meters, expressed as * 1000 (millimeters)*/
 int16_t vx; /*< Ground X Speed (Latitude), expressed as cm/s*/
 int16_t vy; /*< Ground Y Speed (Longitude), expressed as cm/s*/
 int16_t vz; /*< Ground Z Speed (Altitude), expressed as cm/s*/
 uint16_t ind_airspeed; /*< Indicated airspeed, expressed as cm/s*/
 uint16_t true_airspeed; /*< True airspeed, expressed as cm/s*/
 int16_t xacc; /*< X acceleration (mg)*/
 int16_t yacc; /*< Y acceleration (mg)*/
 int16_t zacc; /*< Z acceleration (mg)*/
}) mavlink_hil_state_quaternion_t;

#define MAVLINK_MSG_ID_HIL_STATE_QUATERNION_LEN 64
#define MAVLINK_MSG_ID_HIL_STATE_QUATERNION_MIN_LEN 64
#define MAVLINK_MSG_ID_115_LEN 64
#define MAVLINK_MSG_ID_115_MIN_LEN 64

#define MAVLINK_MSG_ID_HIL_STATE_QUATERNION_CRC 4
#define MAVLINK_MSG_ID_115_CRC 4

#define MAVLINK_MSG_HIL_STATE_QUATERNION_FIELD_ATTITUDE_QUATERNION_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_HIL_STATE_QUATERNION { \
    115, \
    "HIL_STATE_QUATERNION", \
    16, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_hil_state_quaternion_t, time_usec) }, \
         { "attitude_quaternion", NULL, MAVLINK_TYPE_FLOAT, 4, 8, offsetof(mavlink_hil_state_quaternion_t, attitude_quaternion) }, \
         { "rollspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_hil_state_quaternion_t, rollspeed) }, \
         { "pitchspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_hil_state_quaternion_t, pitchspeed) }, \
         { "yawspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_hil_state_quaternion_t, yawspeed) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 36, offsetof(mavlink_hil_state_quaternion_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 40, offsetof(mavlink_hil_state_quaternion_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 44, offsetof(mavlink_hil_state_quaternion_t, alt) }, \
         { "vx", NULL, MAVLINK_TYPE_INT16_T, 0, 48, offsetof(mavlink_hil_state_quaternion_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_INT16_T, 0, 50, offsetof(mavlink_hil_state_quaternion_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_INT16_T, 0, 52, offsetof(mavlink_hil_state_quaternion_t, vz) }, \
         { "ind_airspeed", NULL, MAVLINK_TYPE_UINT16_T, 0, 54, offsetof(mavlink_hil_state_quaternion_t, ind_airspeed) }, \
         { "true_airspeed", NULL, MAVLINK_TYPE_UINT16_T, 0, 56, offsetof(mavlink_hil_state_quaternion_t, true_airspeed) }, \
         { "xacc", NULL, MAVLINK_TYPE_INT16_T, 0, 58, offsetof(mavlink_hil_state_quaternion_t, xacc) }, \
         { "yacc", NULL, MAVLINK_TYPE_INT16_T, 0, 60, offsetof(mavlink_hil_state_quaternion_t, yacc) }, \
         { "zacc", NULL, MAVLINK_TYPE_INT16_T, 0, 62, offsetof(mavlink_hil_state_quaternion_t, zacc) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_HIL_STATE_QUATERNION { \
    "HIL_STATE_QUATERNION", \
    16, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_hil_state_quaternion_t, time_usec) }, \
         { "attitude_quaternion", NULL, MAVLINK_TYPE_FLOAT, 4, 8, offsetof(mavlink_hil_state_quaternion_t, attitude_quaternion) }, \
         { "rollspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_hil_state_quaternion_t, rollspeed) }, \
         { "pitchspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_hil_state_quaternion_t, pitchspeed) }, \
         { "yawspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_hil_state_quaternion_t, yawspeed) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 36, offsetof(mavlink_hil_state_quaternion_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 40, offsetof(mavlink_hil_state_quaternion_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 44, offsetof(mavlink_hil_state_quaternion_t, alt) }, \
         { "vx", NULL, MAVLINK_TYPE_INT16_T, 0, 48, offsetof(mavlink_hil_state_quaternion_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_INT16_T, 0, 50, offsetof(mavlink_hil_state_quaternion_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_INT16_T, 0, 52, offsetof(mavlink_hil_state_quaternion_t, vz) }, \
         { "ind_airspeed", NULL, MAVLINK_TYPE_UINT16_T, 0, 54, offsetof(mavlink_hil_state_quaternion_t, ind_airspeed) }, \
         { "true_airspeed", NULL, MAVLINK_TYPE_UINT16_T, 0, 56, offsetof(mavlink_hil_state_quaternion_t, true_airspeed) }, \
         { "xacc", NULL,