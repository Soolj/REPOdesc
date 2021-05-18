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
 * @param param_index Parameter index. Send -1 to use the param ID field as identifier (else the param id will be ignored), send -2 to disable any existing map for this rc_channel_index.
 * @param parameter_rc_channel_index Index of parameter RC channel. Not equal to the RC channel id. Typically correpsonds to a potentiometer-knob on the RC.
 * @param param_value0 Initial parameter value
 * @param scale Scale, maps the RC range [-1, 1] to a parameter value
 * @param param_value_min Minimum param value. The protocol does not define if this overwrites an onboard minimum value. (Depends on implementation)
 * @param param_value_max Maximum param value. The protocol does not define if this overwrites an onboard maximum value. (Depends on implementation)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_param_map_rc_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, const char *param_id, int16_t param_index, uint8_t parameter_rc_channel_index, float param_value0, float scale, float param_value_min, float param_value_max)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PARAM_MAP_RC_LEN];
    _mav_put_float(buf, 0, param_value0);
    _mav_put_float(buf, 4, scale);
    _mav_put_float(buf, 8, param_value_min);
    _mav_put_float(buf, 12, param_value_max);
    _mav_put_int16_t(buf, 16, param_index);
    _mav_put_uint8_t(buf, 18, target_system);
    _mav_put_uint8_t(buf, 19, target_component);
    _mav_put_uint8_t(buf, 36, parameter_rc_channel_index);
    _mav_p