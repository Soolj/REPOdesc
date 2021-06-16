#pragma once
// MESSAGE PARAM_SET PACKING

#define MAVLINK_MSG_ID_PARAM_SET 23

MAVPACKED(
typedef struct __mavlink_param_set_t {
 float param_value; /*< Onboard parameter value*/
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 char param_id[16]; /*< Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string*/
 uint8_t param_type; /*< Onboard parameter type: see the MAV_PARAM_TYPE enum for supported data types.*/
}) mavlink_param_set_t;

#define MAVLINK_MSG_ID_PARAM_SET_LEN 23
#define MAVLINK_MSG_ID_PARAM_SET_MIN_LEN 23
#define MAVLINK_MSG_ID_23_LEN 23
#define MAVLINK_MSG_ID_23_MIN_LEN 23

#define MAVLINK_MSG_ID_PARAM_SET_CRC 168
#define MAVLINK_MSG_ID_23_CRC 168

#define MAVLINK_MSG_PARAM_SET_FIELD_PARAM_ID_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PARAM_SET { \
    23, \
    "PARAM_SET", \
    5, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_param_set_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_param_set_t, target_component) }, \
         { "param_id", NULL, MAVLINK_TYPE_CHAR, 16, 6, offsetof(mavlink_param_set_t, param_id) }, \
         { "param_value", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_param_set_t, param_value) }, \
         { "param_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 22, offsetof(mavlink_param_set_t, param_type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PARAM_SET { \
    "PARAM_SET", \
    5, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_param_set_t, target_system) }, \
  