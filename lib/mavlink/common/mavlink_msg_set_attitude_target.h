#pragma once
// MESSAGE SET_ATTITUDE_TARGET PACKING

#define MAVLINK_MSG_ID_SET_ATTITUDE_TARGET 82

MAVPACKED(
typedef struct __mavlink_set_attitude_target_t {
 uint32_t time_boot_ms; /*< Timestamp in milliseconds since system boot*/
 float q[4]; /*< Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)*/
 float body_roll_rate; /*< Body roll rate in radians per second*/
 float body_pitch_rate; /*< Body pitch rate in radians per second*/
 float body_yaw_rate; /*< Body yaw rate in radians per second*/
 float thrust; /*< Collective thrust, normalized to 0 .. 1 (-1 .. 1 for vehicles capable of reverse trust)*/
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 uint8_t type_mask; /*< Mappings: If any of these bits are set, the corresponding input should be ignored: bit 1: body roll rate, bit 2: body pitch rate, bit 3: body yaw rate. bit 4-bit 6: reserved, bit 7: throttle, bit 8: attitude*/
}) mavlink_set_attitude_target_t;

#define MAVLINK_MSG_ID_SET_ATTITUDE_TARGET_LEN 39
#define MAVLINK_MSG_ID_SET_ATTITUDE_TARGET_MIN_LEN 39
#define MAVLINK_MSG_ID_82_LEN 39
#define MAVLINK_MSG_ID_82_MIN_LEN 39

#define MAVLINK_MSG_ID_SET_ATTITUDE_TARGET_CRC 49
#define MAVLINK_MSG_ID_82_CRC 49

#define MAVLINK_MSG_SET_ATTITUDE_TARGET_FIELD_Q_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SET_ATTITUDE_TARGET { \
    82, \
    "SET_ATTITUDE_TARGET", \
    9, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_set_attitude_target_t, time_boot_ms) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_set_attitude_target_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 37, offsetof(mavlink_set_attitude_target_t, target_component) }, \
         { "type_mask", NULL, MAVLINK_TYPE_UINT8_T, 0, 38, offsetof(mavlink_set_attitude_target_t, type_mask) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 4, offsetof(mavlink_set_attitude_target_t, q) }, \
         { "body_roll_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_set_attitude_target_t, body_roll_rate) }, \
         { "body_pitch_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_set_attitude_target_t, body_pitch_rate) }, \
         { "body_yaw_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_set_attitude_target_t, body_yaw_rate) }, \
         { "thrust", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_set_attitude_target_t, thrust) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SET_ATTITUDE_TARGET