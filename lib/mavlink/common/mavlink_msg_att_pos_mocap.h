#pragma once
// MESSAGE ATT_POS_MOCAP PACKING

#define MAVLINK_MSG_ID_ATT_POS_MOCAP 138

MAVPACKED(
typedef struct __mavlink_att_pos_mocap_t {
 uint64_t time_usec; /*< Timestamp (micros since boot or Unix epoch)*/
 float q[4]; /*< Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)*/
 float x; /*< X position in meters (NED)*/
 float y; /*< Y position in meters (NED)*/
 float z; /*< Z position in meters (NED)*/
}) mavlink_att_pos_mocap_t;

#define MAVLINK_MSG_ID_ATT_POS_MOCAP_LEN 36
#define MAVLINK_MSG_ID_ATT_POS_MOCAP_MIN_LEN 36
#define MAVLINK_MSG_ID_138_LEN 36
#define MAVLINK_MSG_ID_138_MIN_LEN 36

#define MAVLINK_MSG_ID_ATT_POS_MOCAP_CRC 109
#define MAVLINK_MSG_ID_138_CRC 109

#define MAVLINK_MSG_ATT_POS_MOCAP_FIELD_Q_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ATT_POS_MOCAP { \
    138, \
    "ATT_POS_MOCAP", \
    5, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_att_pos_mocap_t, time_usec) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 8, offsetof(mavlink_att_pos_mocap_t, q) }, \
