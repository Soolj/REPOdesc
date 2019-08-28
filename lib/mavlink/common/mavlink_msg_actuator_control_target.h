#pragma once
// MESSAGE ACTUATOR_CONTROL_TARGET PACKING

#define MAVLINK_MSG_ID_ACTUATOR_CONTROL_TARGET 140

MAVPACKED(
typedef struct __mavlink_actuator_control_target_t {
 uint64_t time_usec; /*< Timestamp (micros since boot or Unix epoch)*/
 float controls[8]; /*< Actuator controls. Normed to -1..+1 where 0 is neutral position. Throttle for single rotation direction motors is 0..1, negative range for reverse direction. Standard mapping for attitude controls (group 0): (index 0-7): roll, pitch, yaw, throttle, flaps, spoilers, airbrakes, landing gear. Load a pass-through mixer to repurpose them as generic outputs.*/
 uint8_t group_mlx; /*< Actuator group. The "_mlx" indicates this is a multi-instance message and a MAVLink parser should use this field to difference between instances.*/
}) mavlink_actuator_control_target_t;

#define MAVLINK_MSG_ID_ACTUATOR_CONTROL_TARGET_LEN 41
#define MAVLINK_MSG_ID_ACTUATOR_CONTROL_TARGET_MIN_LEN 41
#define MAVLINK_MSG_ID_140_LEN 41
#define MAVLINK_MSG_ID_140_MIN_LEN 41

#define MAVLINK_MSG_ID_ACTUATOR_CONTROL_TARGET_CRC 181
#define MAVLINK_MSG_ID_140_CRC 181

#define MAVLINK_MSG_ACTUATOR_CONTROL_TARGET_FIELD_CONTROLS_LEN 8

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ACTUATOR_CONTROL_TARGET { \
    140, \
    "ACTUATOR_CONTROL_TARGET", \
    3, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_actuator_control_target_t, time_usec) }, \
         { "group_mlx", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_actuator_control_target_t, group_mlx) }, \
         { "controls", NULL, MAVLINK_TYPE_FLOAT, 8, 8, offsetof(mavlink_actuator_control_target_t, controls) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ACTUATOR_CONTROL_TARGET { \
    "ACTUATOR_CONTROL_TARGET", \
    3, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_actuator_control_target_t, time_usec) }, \
         { "group_mlx", NULL, MAVL