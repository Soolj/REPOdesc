#pragma once
// MESSAGE ATTITUDE_TARGET PACKING

#define MAVLINK_MSG_ID_ATTITUDE_TARGET 83

MAVPACKED(
typedef struct __mavlink_attitude_target_t {
 uint32_t time_boot_ms; /*< Timestamp in milliseconds since system boot*/
 float q[4]; /*< Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)*/
 float body_roll_rate; /*< Body roll rate in radians per second*/
 float body_pitch_rate; /*< Body pitch rate in radians per second*/
 float body_yaw_rate; /*< Body yaw rate in radians per second*/
 float thrust; /*< Collective thrust, normalized to 0 .. 1 (-1 .. 1 for vehicles capable of reverse trust)*/
 uint8_t type_mask; /*< Mappings: If any of these bits are set, the corresponding input should be ignored: bit 1: body roll rate, bit 2: body pitch rate, bit 3: body yaw rate. bit 4-bit 7: reserved, bit 8: attitude*/
}) mavlink_attitude_target_t;

#define MAVLINK_MSG_ID_ATTITUDE_TARGET_LEN 37
#define MAVLINK_MSG_ID_ATTITUDE_TARGET_MIN_LEN 37
#define MAVLINK_MSG_ID_83_LEN 37
#define MAVLINK_MSG_ID_83_MIN_LEN 37

#define MAVLINK_MSG_ID_ATTITUDE_TARGET_CRC 22
#define MAVLINK_MSG_ID_83_CRC 22

#define MAVLINK_MSG_ATTITUDE_TARGET_FIELD_Q_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ATTITUDE_TARGET { \
    83, \
    "ATTITUDE_TARGET", \
    7, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_attitude_target_t, time_boot_ms) }, \
         { "type_mask", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_attitude_target_t, type_mask) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 4, offsetof(mavlink_attitude_target_t, q) }, \
         { "body_roll_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_attitude_target_t, body_roll_rate) }, \
         { "body_pitch_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_attitude_target_t, body_pitch_rate) }, \
         { "body_yaw_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_attitude_target_t, body_yaw_rate) }, \
         { "thrust", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_attitude_target_t, thrust) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ATTITUDE_TARGET { \
    "ATTITUDE_TARGET", \
    7, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_attitude_target_t, time_boot_ms) }, \
         { "type_mask", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_attitude_target_t, type_mask) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 4, offsetof(mavlink_attitude_target_t, q) }, \
         { "body_roll_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_attitude_target_t, body_roll_rate) }, \
         { "body_pitch_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_attitude_target_t, body_pitch_rate) }, \
         { "body_yaw_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_attitude_target_t, body_yaw_rate) }, \
         { "thrust", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_attitude_target_t, thrust) }, \
         } \
}
#endif

/**
 * @brief Pack a attitude_target message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms Timestamp in milliseconds since system boot
 * @param type_mask Mappings: If any of these bits are set, the corresponding input should be ignored: bit 1: body roll rate, bit 2: body pitch rate, bit 3: body yaw rate. bit 4-bit 7: reserved, bit 8: attitude
 * @param q Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 *