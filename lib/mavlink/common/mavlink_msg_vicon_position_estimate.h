#pragma once
// MESSAGE VICON_POSITION_ESTIMATE PACKING

#define MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE 104

MAVPACKED(
typedef struct __mavlink_vicon_position_estimate_t {
 uint64_t usec; /*< Timestamp (microseconds, synced to UNIX time or since system boot)*/
 float x; /*< Global X position*/
 float y; /*< Global Y position*/
 float z; /*< Global Z position*/
 float roll; /*< Roll angle in rad*/
 float pitch; /*< Pitch angle in rad*/
 float yaw; /*< Yaw angle in rad*/
}) mavlink_vicon_position_estimate_t;

#define MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE_LEN 32
#define MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE_MIN_LEN 32
#define MAVLINK_MSG_ID_104_LEN 32
#define MAVLINK_MSG_ID_104_MIN_LEN 32

#define MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE_CRC 56
#define MAVLINK_MSG_ID_104_CRC 56



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VICON_POSITION_ESTIMATE { \
    104, \
    "VICON_POSITION_ESTIMATE", \
    7, \
    {  { "usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_vicon_position_estimate_t, usec) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_vicon_position_estimate_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_vicon_position_estimate_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_vicon_position_estimate_t, z) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_vicon_position_estimate_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_vicon_position_estimate_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_vicon_position_estimate_t, yaw) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VICON_POSITION_ESTIMATE { \
    "VICON_POSITION_ESTIMATE", \
    7, \
    {  { "usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_vicon_position_estimate_t, usec) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_vicon_posi