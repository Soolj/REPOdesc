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
 float ve; /*< True velocity in m/s in EAST direc