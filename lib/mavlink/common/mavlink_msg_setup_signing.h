
#pragma once
// MESSAGE SETUP_SIGNING PACKING

#define MAVLINK_MSG_ID_SETUP_SIGNING 256

MAVPACKED(
typedef struct __mavlink_setup_signing_t {
 uint64_t initial_timestamp; /*< initial timestamp*/
 uint8_t target_system; /*< system id of the target*/
 uint8_t target_component; /*< component ID of the target*/
 uint8_t secret_key[32]; /*< signing key*/
}) mavlink_setup_signing_t;

#define MAVLINK_MSG_ID_SETUP_SIGNING_LEN 42
#define MAVLINK_MSG_ID_SETUP_SIGNING_MIN_LEN 42
#define MAVLINK_MSG_ID_256_LEN 42
#define MAVLINK_MSG_ID_256_MIN_LEN 42

#define MAVLINK_MSG_ID_SETUP_SIGNING_CRC 71
#define MAVLINK_MSG_ID_256_CRC 71

#define MAVLINK_MSG_SETUP_SIGNING_FIELD_SECRET_KEY_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SETUP_SIGNING { \
    256, \
    "SETUP_SIGNING", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_setup_signing_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_setup_signing_t, target_component) }, \
         { "secret_key", NULL, MAVLINK_TYPE_UINT8_T, 32, 10, offsetof(mavlink_setup_signing_t, secret_key) }, \
         { "initial_timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_setup_signing_t, initial_timestamp) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SETUP_SIGNING { \
    "SETUP_SIGNING", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_setup_signing_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_setup_signing_t, target_component) }, \
         { "secret_key", NULL, MAVLINK_TYPE_UINT8_T, 32, 10, offsetof(mavlink_setup_signing_t, secret_key) }, \
         { "initial_timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_setup_signing_t, initial_timestamp) }, \
         } \
}
#endif

/**
 * @brief Pack a setup_signing message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system system id of the target
 * @param target_component component ID of the target
 * @param secret_key signing key
 * @param initial_timestamp initial timestamp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_setup_signing_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, const uint8_t *secret_key, uint64_t initial_timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SETUP_SIGNING_LEN];
    _mav_put_uint64_t(buf, 0, initial_timestamp);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, target_component);
    _mav_put_uint8_t_array(buf, 10, secret_key, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SETUP_SIGNING_LEN);
#else
    mavlink_setup_signing_t packet;
    packet.initial_timestamp = initial_timestamp;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.secret_key, secret_key, sizeof(uint8_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SETUP_SIGNING_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SETUP_SIGNING;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SETUP_SIGNING_MIN_LEN, MAVLINK_MSG_ID_SETUP_SIGNING_LEN, MAVLINK_MSG_ID_SETUP_SIGNING_CRC);
}

/**
 * @brief Pack a setup_signing message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system system id of the target
 * @param target_component component ID of the target
 * @param secret_key signing key
 * @param initial_timestamp initial timestamp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_setup_signing_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,const uint8_t *secret_key,uint64_t initial_timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SETUP_SIGNING_LEN];
    _mav_put_uint64_t(buf, 0, initial_timestamp);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, target_component);
    _mav_put_uint8_t_array(buf, 10, secret_key, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SETUP_SIGNING_LEN);
#else
    mavlink_setup_signing_t packet;
    packet.initial_timestamp = initial_timestamp;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.secret_key, secret_key, sizeof(uint8_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SETUP_SIGNING_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SETUP_SIGNING;