#pragma once
// MESSAGE SIM_STATE PACKING

#define MAVLINK_MSG_ID_SIM_STATE 108

MAVPACKED(
typedef struct __mavlink_sim_state_t {
 float q1; /*< True attitude quaternion component 1, w (1 in null-rotation)*/
 float q2; /*< True attitude quaternion component 2, x (0 in null-rotation)*/
 float q3; /*< True attitude quaternion component 3, y (0 in null-rotation)*/
 float q4; /*< True attitude quaternion component 4, z (0 in null-rotation)*/
 float roll; /*< Attitude roll expressed as Euler angles, not recommended except for human-readable outputs*/
 float pitch; /*< Attitude pitch expressed as Euler angles, not recommended except for human-readable outputs*/
 float yaw; /*< Attitude yaw expressed as Euler angles, not recommended except for human-readable outputs*/
 float xacc; /*< X acceleration m/s/s*/
 float yacc; /*< Y acceleration m/s/s*/
 float zacc; /*< Z acceleration m/s/s*/
 float xgyro; /*< Angular speed around X axis rad/s*/
 float ygyro; /*< Angular speed around Y axis rad/s*/
 float zgyro; /*< Angular speed around Z axis rad/s*/
 float lat; /*< Latitude in degrees*/
 float lon; /*< Longitude in degrees*/
 float alt; /*< Altitude in meters*/
 float std_dev_horz; /*< Horizontal position standard deviation*/
 float std_dev_vert; /*< Vertical position standard deviation*/
 float vn; /*< True velocity in m/s in NORTH direction in earth-fixed NED frame*/
 float ve; /*< True velocity in m/s in EAST direction in earth-fixed NED frame*/
 float vd; /*< True velocity in m/s in DOWN direction in earth-fixed NED frame*/
}) mavlink_sim_state_t;

#define MAVLINK_MSG_ID_SIM_STATE_LEN 84
#define MAVLINK_MSG_ID_SIM_STATE_MIN_LEN 84
#define MAVLINK_MSG_ID_108_LEN 84
#define MAVLINK_MSG_ID_108_MIN_LEN 84

#define MAVLINK_MSG_ID_SIM_STATE_CRC 32
#define MAVLINK_MSG_ID_108_CRC 32



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SIM_STATE { \
    108, \
    "SIM_STATE", \
    21, \
    {  { "q1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_sim_state_t, q1) }, \
         { "q2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_sim_state_t, q2) }, \
         { "q3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_sim_state_t, q3) }, \
         { "q4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_sim_state_t, q4) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_sim_state_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_sim_state_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_sim_state_t, yaw) }, \
         { "xacc", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_sim_state_t, xacc) }, \
         { "yacc", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_sim_state_t, yacc) }, \
         { "zacc", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_sim_state_t, zacc) }, \
         { "xgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_sim_state_t, xgyro) }, \
         { "ygyro", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_sim_state_t, ygyro) }, \
         { "zgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_sim_state_t, zgyro) }, \
         { "lat", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_sim_state_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_sim_state_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_sim_state_t, alt) }, \
         { "std_dev_horz", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_sim_state_t, std_dev_horz) }, \
         { "std_dev_vert", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_sim_state_t, std_dev_vert) }, \
         { "vn", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_sim_state_t, vn) }, \
         { "ve", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_sim_state_t, ve) }, \
         { "vd", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_sim_state_t, vd) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SIM_STATE { \
    "SIM_STATE", \
    21, \
    {  { "q1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_sim_state_t, q1) }, \
         { "q2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_sim_state_t, q2) }, \
         { "q3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_sim_state_t, q3) }, \
         { "q4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_sim_state_t, q4) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_sim_state_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_sim_state_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink