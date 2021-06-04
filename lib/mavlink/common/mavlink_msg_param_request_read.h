#pragma once
// MESSAGE PARAM_REQUEST_READ PACKING

#define MAVLINK_MSG_ID_PARAM_REQUEST_READ 20

MAVPACKED(
typedef struct __mavlink_param_request_read_t {
 int16_t param_index; /*< Parameter index. Send -1 to use the param ID field as identifier (else the param id will be ignored)*/
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 char param_id[16]; /*< Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string*/
}) mavlink_param_request_read_t;

#define MAVLINK_MSG_ID_PARAM_REQUEST_READ_LEN 20
#define MAVLINK_MSG_ID_PARAM_REQUEST_READ_MIN_LEN 20
#define MAVLINK_MSG_ID_20_LEN 20
#define MAVLINK_MSG_ID_20_MIN_LEN 20

#define MAVLINK_MSG_ID_PARAM_REQUEST_READ_CRC 214
#define MAVLINK_MSG_ID_20_CRC 214

#define MAVLINK_MSG_PARAM_REQUEST_READ_FIELD_PARAM_ID_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PARAM_REQUEST_READ { \
    20, \
    "PARAM_REQUEST_READ", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_param_request_read_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_param_request_read_t, target_component) }, \
         { "param_id", NULL, MAVLINK_TYPE_CHAR, 16, 4, offsetof(mavlink_param_request_read_t, param_id) }, \
         { "param_index", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_param_request_read_t, param_index) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PARAM_REQUEST_READ { \
    "PARAM_REQUEST_READ", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_param_request_read_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_param_request_read_t, target_component) }, \
         { "param_id", NULL, MAVLINK_TYPE_CHAR, 16, 4, offsetof(mavlink_param_request_read_t, param_id) }, \
         { "param_index", NULL,