#pragma once
// MESSAGE PARAM_EXT_REQUEST_READ PACKING

#define MAVLINK_MSG_ID_PARAM_EXT_REQUEST_READ 320

MAVPACKED(
typedef struct __mavlink_param_ext_request_read_t {
 int16_t param_index; /*< Parameter index. Set to -1 to use the Parameter ID field as identifier (else param_id will be ignored)*/
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 char param_id[16]; /*< Parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string*/
}) mavlink_param_ext_request_read_t;

#define MAVLINK_MSG_ID_PARAM_EXT_REQUEST_READ_LEN 20
#define MAVLINK_MSG_ID_PARAM_EXT_REQUEST_READ_MIN_LEN 20
#define MAVLINK_MSG_ID_320_LEN 20
#define MAVL