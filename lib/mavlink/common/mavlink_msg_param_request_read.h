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
         { "param_index", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_param_request_read_t, param_index) }, \
         } \
}
#endif

/**
 * @brief Pack a param_request_read message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param param_id Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 * @param param_index Parameter index. Send -1 to use the param ID field as identifier (else the param id will be ignored)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_param_request_read_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, const char *param_id, int16_t param_index)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PARAM_REQUEST_READ_LEN];
    _mav_put_int16_t(buf, 0, param_index);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);
    _mav_put_char_array(buf, 4, param_id, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PARAM_REQUEST_READ_LEN);
#else
    mavlink_param_request_read_t packet;
    packet.param_index = param_