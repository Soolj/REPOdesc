#pragma once
// MESSAGE MISSION_SET_CURRENT PACKING

#define MAVLINK_MSG_ID_MISSION_SET_CURRENT 41

MAVPACKED(
typedef struct __mavlink_mission_set_current_t {
 uint16_t seq; /*< Sequence*/
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
}) mavlink_mission_set_current_t;

#define MAVLINK_MSG_ID_MISSION_SET_CURRENT_LEN 4
#define MAVLINK_MSG_ID_MISSION_SET_CURRENT_MIN_LEN 4
#define MAVLINK_MSG_ID_41_LEN 4
#define MAVLINK_MSG_ID_41_MIN_LEN 4

#define MAVLINK_MSG_ID_MISSION_SET_CURRENT_CRC 28
#define MAVLINK_MSG_ID_41_CRC 28



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MISSION_SET_CURRENT { \
    41, \
    "MISSION_SET_CURRENT", \
    3, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_mission_set_current_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_mission_set_current_t, target_component) }, \
         { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_mission_set_current_t, seq) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MISSION_SET_CURRENT { \
    "MISSION_SET_CURRENT", \
    3, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_mission_set_current_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_mission_set_current_t, target_component) }, \
         { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_mission_set_current_t, seq) }, \
         } \
}
#endif

/**
 * @brief Pack a mission_set_current message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param seq Sequence
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_set_current_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint16_t seq)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MISSION_SET_CURRENT_LEN];
    _mav_put_uint16_t(buf, 0, seq);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MISSION_SET_CURRENT_LEN);
#else
    mavlink_mission_set_current_t packet;
    packet.seq = seq;
    packet.target_system = target_system;
    packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MISSION_SET_CURRENT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MISSION_SET_CURRENT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MISSION_SET_CURRENT_MIN_LEN, MAVLINK_MSG_ID_MISSION_SET_CURRENT_LEN, MAVLINK_MSG_ID_MISSION_SET_CURRENT_CRC);
}

/**
 * @brief Pack a mission_set_current message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param seq Sequence
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_set_current_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint16_t seq)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MISSION_SET_CURRENT_LEN];
    _mav_put_uint16_t(buf, 0, seq);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MISSION_SET_CURRENT_LEN);
#else
    mavlink_mission_set_current_t packet;
    packet.seq = seq;
    packet.target_system = target_system;
    packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MISSION_SET_CURRENT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MISSION_SET_CURRENT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MISSION_SET_CURRENT_MIN_LEN, MAVLINK_MSG_ID_MISSION_SET_CURRENT_LEN, MAVLINK_MSG_ID_MISSION_SET_CURRENT_CRC);
}

/**
 * @brief Encode a mission_set_current struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mission_set_current C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mission_set_current_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mission_set_current_t* mission_set_current)
{
    return mavlink_msg_mission_set_current_pack(system_id, component_id, msg, mission_set_current->target_system, mission_set_current->target_component, mission_set_current->seq);
}

/**
 * @brief Encode a mission_set_current struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g.