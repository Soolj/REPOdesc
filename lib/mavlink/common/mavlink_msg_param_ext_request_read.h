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
#define MAVLINK_MSG_ID_320_MIN_LEN 20

#define MAVLINK_MSG_ID_PARAM_EXT_REQUEST_READ_CRC 243
#define MAVLINK_MSG_ID_320_CRC 243

#define MAVLINK_MSG_PARAM_EXT_REQUEST_READ_FIELD_PARAM_ID_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PARAM_EXT_REQUEST_READ { \
    320, \
    "PARAM_EXT_REQUEST_READ", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_param_ext_request_read_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_param_ext_request_read_t, target_component) }, \
         { "param_id", NULL, MAVLINK_TYPE_CHAR, 16, 4, offsetof(mavlink_param_ext_request_read_t, param_id) }, \
         { "param_index", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_param_ext_request_read_t, param_index) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PARAM_EXT_REQUEST_READ { \
    "PARAM_EXT_REQUEST_READ", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_param_ext_request_read_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_param_ext_request_read_t, target_component) }, \
         { "param_id", NULL, MAVLINK_TYPE_CHAR, 16, 4, offsetof(mavlink_param_ext_request_read_t, param_id) }, \
         { "param_index", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_param_ext_request_read_t, param_index) }, \
         } \
}
#endif

/**
 * @brief Pack a param_ext_request_read message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param param_id Parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 * @param param_index Parameter index. Set to -1 to use the Parameter ID field as identifier (else param_id will be ignored)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_param_ext_request_read_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, const char *param_id, int16_t param_index)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PARAM_EXT_REQUEST_READ_LEN];
    _mav_put_int16_t(buf, 0, param_index);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);
    _mav_put_char_array(buf, 4, param_id, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PARAM_EXT_REQUEST_READ_LEN);
#else
    mavlink_param_ext_request_read_t packet;
    packet.param_index = param_index;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.param_id, param_id, sizeof(char)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PARAM_EXT_REQUEST_READ_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PARAM_EXT_REQUEST_READ;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PARAM_EXT_REQUEST_READ_MIN_LEN, MAVLINK_MSG_ID_PARAM_EXT_REQUEST_READ_LEN, MAVLINK_MSG_ID_PARAM_EXT_REQUEST_READ_CRC);
}

/**
 * @brief Pack a param_ext_request_read message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param param_id Parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 * @param param_index Parameter index. Set to -1 to use the Parameter ID field as identifier (else param_id will be ignored)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_param_ext_request_read_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,const char *param_id,int16_t param_index)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PARAM_EXT_REQUEST_READ_LEN];
    _mav_put_int16_t(buf, 0, param_index);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);
    _mav_put_char_array(buf, 4, param_id, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PARAM_EXT_REQUEST_READ_LEN);
#else
    mavlink_param_ext_request_read_t packet;
    packet.param_index = param_index;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.param_id, param_id, sizeof(char)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PARAM_EXT_REQUEST_READ_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PARAM_EXT_REQUEST_READ;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PARAM_EXT_REQUEST_READ_MIN_LEN, MAVLINK_MSG_ID_PARAM_EXT_REQUEST_READ_LEN, MAVLINK_MSG_ID_PARAM_EXT_REQUEST_READ_CRC);
}

/**
 * @brief Encode a param_ext_request_read struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param param_ext_request_read C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_param_ext_request_read_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_param_ext_request_read_t* param_ext_request_read)
{
    return mavlink_msg_param_ext_request_read_pack(system_id, component_id, msg, param_ext_request_read->target_system, param_ext_request_read->target_component, param_ext_request_read->param_id, param_ext_request_read->param_index);
}

/**
 * @brief Encode a param_ext_request_read struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param param_ext_request_read C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_param_ext_request_read_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_param_ext_request_read_t* param_ext_request_read)
{
    return mavlink_msg_param_ext_request_read_pack_chan(system_id, component_id, chan, msg, param_ext_request_read->target_system, param_ext_request_read->target_component, param_ext_request_read->param_id, param_ext_request_read->param_index);
}

/**
 * @brief Send a param_ext_request_read message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param param_id Parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 * @param param_index Parameter index. Set to -1 to use the Parameter ID field as identifier (else param_id will be ignored)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_param_ext_request_read_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, const char *param_id, int16_t param_