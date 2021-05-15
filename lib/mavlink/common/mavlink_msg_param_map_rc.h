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
#define MAVLINK_MSG_ID_PARAM_MAP_RC_MIN_L