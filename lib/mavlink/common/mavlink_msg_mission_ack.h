#pragma once
// MESSAGE MISSION_ACK PACKING

#define MAVLINK_MSG_ID_MISSION_ACK 47

MAVPACKED(
typedef struct __mavlink_mission_ack_t {
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 uint8_t type; /*< See MAV_MISSION_RESULT enum*/
 uint8_t mission_type; /*< Mission type, see MAV_MISSION_TYPE*/
}) mavlink_mission_ack_t;

#define MAVLINK_MSG_ID_MISSION_ACK_LEN 4
#define MAVLINK_MSG_ID_MISSION_ACK_MIN_LEN 3
#define MAVLINK_MSG_ID_47_LEN 4
#define MAVLINK_MSG_ID_47_MIN_LEN 3

#define MAVLINK_MSG_ID_MISSION_ACK_CRC 153
#define MAVLINK_MSG_ID_47_CRC 153



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MISSION_ACK { \
    47, \
    "MISSION_ACK", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_mission_ack_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_mission_ack_t, target_component) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_mission_ack_t, type) }, \
         { "mission_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_mission_ack_t, mission_type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MISSION_ACK { \
    "MISSION_ACK", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_mission_ack_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_mission_ack_t, target_component) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_mission_ack_t, type) }, \
         { "mission_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_mission_ack_t, mission_type) }, \
         } \
}
#endif

/**
 * @brief Pack a mission_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param type See MAV_MISSION_RESULT enum
 * @param mission_type Mission type, see MAV_MISSION_TYPE
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_ack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint8_t type, uint8_t mission_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MISSION_ACK_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, type);
    _mav_put_uint8_t(buf, 3, mission_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MISSION_ACK_LEN);
#else
    mavlink_mission_ack_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.type = type;
    packet.mission_type = mission_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MISSION_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MISSION_ACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MISSION_ACK_MIN_LEN, MAVLINK_MSG_ID_MISSION_ACK_LEN, MAVLINK_MSG_ID_MISSION_ACK_CRC);
}

/**
 * @brief Pack a mission_ack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param type See MAV_MISSION_RESULT enum
 * @param mission_type Mission type, see MAV_MISSION_TYPE
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_ack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint8_t type,uint8_t mission_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MISSION_ACK_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, type);
    _mav_put_uint8_t(buf, 3, mission_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MISSION_ACK_LEN);
#else
    mavlink_mission_ack_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.type = type;
    packet.mission_type = mission_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MISSION_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MISSION_ACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MISSION_ACK_MIN_LEN, MAVLINK_MSG_ID_MISSION_ACK_LEN, MAVLINK_MSG_ID_MISSION_ACK_CRC);
}

/**
 * @brief Encode a mission_ack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
