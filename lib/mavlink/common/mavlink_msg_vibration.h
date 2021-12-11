#pragma once
// MESSAGE VIBRATION PACKING

#define MAVLINK_MSG_ID_VIBRATION 241

MAVPACKED(
typedef struct __mavlink_vibration_t {
 uint64_t time_usec; /*< Timestamp (micros since boot or Unix epoch)*/
 float vibration_x; /*< Vibration levels on X-axis*/
 float vibration_y; /*< Vibration levels on Y-axis*/
 float vibration_z; /*< Vibration levels on Z-axis*/
 uint32_t clipping_0; /*< first accelerometer clipping count*/
 uint32_t clipping_1; /*< second accelerometer clipping count*/
 uint32_t clipping_2; /*< third accelerometer clipping count*/
}) mavlink_vibration_t;

#define MAVLINK_MSG_ID_VIBRATION_LEN 32
#define MAVLINK_MSG_ID_VIBRATION_MIN_LEN 32
#define MAVLINK_MSG_ID_241_LEN 32
#define MAVLINK_MSG_ID_241_MIN_LEN 32

#define MAVLINK_MSG_ID_VIBRATION_CRC 90
#define MAVLINK_MSG_ID_241_CRC 90



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VIBRATION { \
    241, \
    "VIBRATION", \
    7, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_vibration_t, time_usec) }, \
         { "vibration_x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_vibration_t, vibration_x) }, \
         { "vibration_y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_vibration_t, vibration_y) }, \
         { "vibration_z", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_vibration_t, vibration_z) }, \
         { "clipping_0", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_vibration_t, clipping_0) }, \
         