
#pragma once
// MESSAGE PARAM_EXT_VALUE PACKING

#define MAVLINK_MSG_ID_PARAM_EXT_VALUE 322

MAVPACKED(
typedef struct __mavlink_param_ext_value_t {
 uint16_t param_count; /*< Total number of parameters*/
 uint16_t param_index; /*< Index of this parameter*/
 char param_id[16]; /*< Parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string*/
 char param_value[128]; /*< Parameter value*/
 uint8_t param_type; /*< Parameter type: see the MAV_PARAM_EXT_TYPE enum for supported data types.*/
}) mavlink_param_ext_value_t;

#define MAVLINK_MSG_ID_PARAM_EXT_VALUE_LEN 149
#define MAVLINK_MSG_ID_PARAM_EXT_VALUE_MIN_LEN 149
#define MAVLINK_MSG_ID_322_LEN 149
#define MAVLINK_MSG_ID_322_MIN_LEN 149

#define MAVLINK_MSG_ID_PARAM_EXT_VALUE_CRC 243
#define MAVLINK_MSG_ID_322_CRC 243

#define MAVLINK_MSG_PARAM_EXT_VALUE_FIELD_PARAM_ID_LEN 16
#define MAVLINK_MSG_PARAM_EXT_VALUE_FIELD_PARAM_VALUE_LEN 128

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PARAM_EXT_VALUE { \
    322, \
    "PARAM_EXT_VALUE", \
    5, \
    {  { "param_id", NULL, MAVLINK_TYPE_CHAR, 16, 4, offsetof(mavlink_param_ext_value_t, param_id) }, \
         { "param_value", NULL, MAVLINK_TYPE_CHAR, 128, 20, offsetof(mavlink_param_ext_value_t, param_value) }, \
         { "param_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 148, offsetof(mavlink_param_ext_value_t, param_type) }, \
         { "param_count", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_param_ext_value_t, param_count) }, \
         { "param_index", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_param_ext_value_t, param_index) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PARAM_EXT_VALUE { \
    "PARAM_EXT_VALUE", \
    5, \
    {  { "param_id", NULL, MAVLINK_TYPE_CHAR, 16, 4, offsetof(mavlink_param_ext_value_t, param_id) }, \
         { "param_value", NULL, MAVLINK_TYPE_CHAR, 128, 20, offsetof(mavlink_param_ext_value_t, param_value) }, \
         { "param_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 148, offsetof(mavlink_param_ext_value_t, param_type) }, \
         { "param_count", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_param_ext_value_t, param_count) }, \
         { "param_index", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_param_ext_value_t, param_index) }, \
         } \
}
#endif

/**
 * @brief Pack a param_ext_value message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param param_id Parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 * @param param_value Parameter value
 * @param param_type Parameter type: see the MAV_PARAM_EXT_TYPE enum for supported data types.
 * @param param_count Total number of parameters
 * @param param_index Index of this parameter
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_param_ext_value_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *param_id, const char *param_value, uint8_t param_type, uint16_t param_count, uint16_t param_index)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PARAM_EXT_VALUE_LEN];
    _mav_put_uint16_t(buf, 0, param_count);
    _mav_put_uint16_t(buf, 2, param_index);
    _mav_put_uint8_t(buf, 148, param_type);
    _mav_put_char_array(buf, 4, param_id, 16);
    _mav_put_char_array(buf, 20, param_value, 128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PARAM_EXT_VALUE_LEN);