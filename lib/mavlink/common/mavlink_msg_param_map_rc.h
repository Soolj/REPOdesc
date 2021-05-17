#pragma once
// MESSAGE PARAM_MAP_RC PACKING

#define MAVLINK_MSG_ID_PARAM_MAP_RC 50

MAVPACKED(
typedef struct __mavlink_param_map_rc_t {
 float param_value0; /*< Initial parameter value*/
 float scale; /*< Scale, maps the RC range [-1, 1] to a parameter value*/
 float param_value_min; /*< Minimum param value. The protocol does not define if this overwrites an onboard minimum value. (Depends on implementation)*/
 float param_value_max; /*< Maximum param value. The protocol does not define if this overwrites an onboard maximum value. (Depends on implementation)*/
 int16_t param_index; /*< Parameter index. Send -1 to use the param ID field as identifier (else the param id will be ignored), send -2 to disable any existing map for this rc_channel_index.*/
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 char param_id[16]; /*< Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string*/
 uint8_t parameter_rc_channel_index; /*< Index of parameter RC channel. Not equal to the RC channel id. Typically correpsonds to a potentiometer-knob on the RC.*/
}) mavlink_param_map_rc_t;

#define MAVLINK_MSG_ID_PARAM_MAP_RC_LEN 37
#define MAVLINK_MSG_ID_PARAM_MAP_RC_MIN_LEN 37
#define MAVLINK_MSG_ID_50_LEN 37
#define MAVLINK_MSG_ID_50_MIN_LEN 37

#define MAVLINK_MSG_ID_PARAM_MAP_RC_CRC 78
#define MAVLINK_MSG_ID_50_CRC 78

#define MAVLINK_MSG_PARAM_MAP_RC_FIELD_PARAM_ID_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PARAM_MAP_RC { \
    50, \
    "PARAM_MAP_RC", \
    9, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_param_map_rc_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 19, offsetof(mavlink_param_map_rc_t, target_component) }, \
         { "param_id", NULL, MAVLINK_TYPE_CHAR, 16, 20, offsetof(mavlink_param_map_rc_t, param_id) }, \
         { "param_index", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_param_map_rc_t, param_index) }, \
         { "parameter_rc_channel_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_param_map_rc_t, parameter_rc_channel_index) }, \
         { "param_value0", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_param_map_rc_t, param_value0) }, \
         { "scale", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_param_map_rc_t, scale) }, \
         { "param_value_min", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_param_map_rc_t, param_value_min) }, \
         { "param_value_max", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_param_map_rc_t, param_value_max) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PARAM_MAP_RC { \
    "PARAM_MAP_RC", \
    9, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_param_map_rc_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 19, offsetof(mavlink_param_map_rc_t, target_component) }, \
         { "param_id", NULL, MAVLINK_TYPE_CHAR, 16, 20, offsetof(mavlink_param_map_rc_t, param_id) }, \
         { "param_index", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_param_map_rc_t, param_index) }, \
         { "parameter_rc_channel_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_param_map_rc_t, parameter_rc_channel_index) }, \
         { "param_value0", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_param_map_rc_t, param_value0) }, \
         { "scale", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_param_map_rc_t, scale) }, \
         { "param_value_min", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_param_map_rc_t, param_value_min) }, \
         { "param_value_max", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_param_map_rc_t, param_value_max) }, \
         } \
}
#endif

/**
 * @brief Pack a param_map_rc message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param param_id Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 * @param param_index Parameter index. Send -1 to use the param ID f