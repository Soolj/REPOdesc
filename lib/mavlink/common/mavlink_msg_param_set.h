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
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_param_set_t, target_component) }, \
         { "param_id", NULL, MAVLINK_TYPE_CHAR, 16, 6, offsetof(mavlink_param_set_t, param_id) }, \
         { "param_value", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_param_set_t, param_value) }, \
         { "param_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 22, offsetof(mavlink_param_set_t, param_type) }, \
         } \
}
#endif

/**
 * @brief Pack a param_set message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param param_id Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 * @param param_value Onboard parameter value
 * @param param_type Onboard parameter type: see the MAV_PARAM_TYPE enum for supported data types.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_param_set_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, const char *param_id, float param_value, uint8_t param_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PARAM_SET_LEN]