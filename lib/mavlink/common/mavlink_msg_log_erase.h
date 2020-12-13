#pragma once
// MESSAGE LOG_ERASE PACKING

#define MAVLINK_MSG_ID_LOG_ERASE 121

MAVPACKED(
typedef struct __mavlink_log_erase_t {
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
}) mavlink_log_erase_t;

#define MAVLINK_MSG_ID_LOG_ERASE_LEN 2
#define MAVLINK_MSG_ID_LOG_ERASE_MIN_LEN 2
#define MAVLINK_MSG_ID_121_LEN 2
#define MAVLINK_MSG_ID_121_MIN_LEN 2

#define MAVLINK_MSG_ID_LOG_ERASE_CRC 237
#define MAVLINK_MSG_ID_121_CRC 237



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LOG_ERASE { \
    121, \
    "LOG_ERASE", \
    2, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_log_erase_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_log_erase_t, target_component) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LOG_ERASE { \
    "LOG_ERASE", \
    2, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_log_erase_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_log_erase_t, target_component) }, \
         } \
}
#endif

/**
 * @brief Pack a log_erase message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_log_erase_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LOG_ERASE_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LOG_ERASE_LEN);
#else
    mavlink_log_erase_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LOG_ERASE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LOG_ERASE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LOG_ERASE_MIN_LEN, MAVLINK_MSG_ID_LOG_ERASE_LEN, MAVLINK_MSG_ID_LOG_ERASE_CRC);
}

/**
 * @brief Pack a log_erase message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this c