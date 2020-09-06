#pragma once
// MESSAGE HEARTBEAT PACKING

#define MAVLINK_MSG_ID_HEARTBEAT 0

MAVPACKED(
typedef struct __mavlink_heartbeat_t {
 uint32_t custom_mode; /*< A bitfield for use for autopilot-specific flags.*/
 uint8_t type; /*< Type of the MAV (quadrotor, helicopter, etc., up to 15 types, defined in MAV_TYPE ENUM)*/
 uint8_t autopilot; /*< Autopilot type / class. defined in MAV_AUTOPILOT ENUM*/
 uint8_t base_mode; /*< System mode bitfield, see MAV_MODE_FLAG ENUM in mavlink/include/mavlink_types.h*/
 uint8_t system_status; /*< System status flag, see MAV_STATE ENUM*/
 uint8_t mavlink_version; /*< MAVLink version, not writable by user, gets added by protocol because of magic data type: uint8_t_mavlink_version*/
}) mavlink_heartbeat_t;

#define MAVLINK_MSG_ID_HEARTBEAT_LEN 9
#define MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN 9
#define MAVLINK_MSG_ID_0_LEN 9
#define MAVLINK_MSG_ID_0_MIN_LEN 9

#define MAVLINK_MSG_ID_HEARTBEAT_CRC 50
#define MAVLINK_MSG_ID_0_CRC 50



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_HEARTBEAT { \
    0, \
    "HEARTBEAT", \
    6, \
    {  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_heartbeat_t, type) }, \
         { "autopilot", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_heartbeat_t, autopilot) }, \
         { "base_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_heartbeat_t, base_mode) }, \
         { "custom_mode", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_heartbeat_t, custom_mode) }, \
         { "system_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_heartbeat_t, system_status) }, \
         { "mavlink_version", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_heartbeat_t, mavlink_version) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_HEARTBEAT { \
    "HEARTBEAT", \
    6, \
    {  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_heartbeat_t, type) }, \
         { "autopilot", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_heartbeat_t, autopilot) }, \
         { "base_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_heartbeat_t, base_mode) }, \
         { "custom_mode", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_heartbeat_t, custom_mode) }, \
         { "system_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_heartbeat_t, system_status) }, \
         { "mavlink_version", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_heartbeat_t, mavlink_version) }, \
         } \
}
#endif

/**
 * @brief Pack a heartbeat message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param type Type of the MAV (quadrotor, helicopter, etc., up to 15 types, defined in MAV_TYPE ENUM)
 * @param autopilot Autopilot type / class. defined in MAV_AUTOPILOT ENUM
 * @param base_mode System mode bitfield, see MAV_MODE_FLAG ENUM in mavlink/include/mavlink_types.h
 * @param custom_mode A bitfield for use for autopilot-specific flags.
 * @param system_status System status flag, see MAV_STATE ENUM
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_heartbeat_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t type, uint8_t autopilot, uint8_t base_mode, uint32_t custom_mode, uint8_t system_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HEARTBEAT_LEN];
    _mav_put_uint32_t(buf, 0, custom_mode);
    _mav_put_uint8_t(buf, 4, type);
    _mav_put_uint8_t(buf, 5, autopilot);
    _mav_put_uint8_t(buf, 6, base_mode);
    _mav_put_uint8_t(buf, 7, system_status);
    _mav_put_uint8_t(buf, 8, 3);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HEARTBEAT_LEN);
#else
    mavlink_heartbeat_t packet;
    packet.custom_mode = custom_mode;
    packet.type = type;
    packet.autopilot = autopilot;
    packet.base_mode = base_mode;
    packet.system_status = system_status;
    packet.mavlink_version = 3;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HEARTBEAT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HEARTBEAT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
}

/**
 * @brief Pack a heartbeat message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param type Type of the MAV (quadrotor, helicopter, etc., up to 15 types, defined in MAV_TYPE ENUM)
 * @param autopilot Autopilot type / class. defined in MAV_AUTOPILOT ENUM
 * @param base_mode System mode bitfield, see MAV_MODE_FLAG ENUM in mavlink/include/mavlink_types.h
 * @param custom_mode A bitfield for use for autopilot-specific flags.
 * @param system_status System status flag, see MAV_STATE ENUM
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_heartbeat_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t type,uint8_t autopilot,uint8_t base_mode,uint32_t custom_mode,uint8_t system_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HEARTBEAT_LEN];
    _mav_put_uint32_t(buf, 0, custom_mode);
    _mav_put_uint8_t(buf, 4, type);
    _mav_put_uint8_t(buf, 5, autopilot);
    _mav_put_uint8_t(buf, 6, base_mode);
    _mav_put_uint8_t(buf, 7, system_status);
    _mav_put_uint8_t(buf, 8, 3);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HEARTBEAT_LEN);
#else
    mavlink_heartbeat_t packet;
    packet.custom_mode = custom_mode;
    packet.type = type;
    packet.autopilot = autopilot;
    packet.base_mode = base_mode;
    packet.system_status = system_status;
    packet.mavlink_version = 3;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HEARTBEAT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HEARTBEAT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBE