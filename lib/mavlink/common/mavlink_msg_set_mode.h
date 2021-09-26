#pragma once
// MESSAGE SET_MODE PACKING

#define MAVLINK_MSG_ID_SET_MODE 11

MAVPACKED(
typedef struct __mavlink_set_mode_t {
 uint32_t custom_mode; /*< The new autopilot-specific mode. This field can be ignored by an autopilot.*/
 uint8_t target_system; /*< The system setting the mode*/
 uint8_t base_mode; /*< The new base mode*/
}) mavlink_set_mode_t;

#define MAVLINK_MSG_ID_SET_MODE_LEN 6
#define MAVLINK_MSG_ID_SET_MODE_MIN_LEN 6
#define MAVLINK_MSG_ID_11_LEN 6
#define MAVLINK_MSG_ID_11_MIN_LEN 6

#define MAVLINK_MSG_ID_SET_MODE_CRC 89
#define MAVLINK_MSG_ID_11_CRC 89



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SET_MODE { \
    11, \
    "SET_MODE", \
    3, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_set_mode_t, target_system) }, \
         { "base_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_set_mode_t, base_mode) }, \
         { "custom_mode", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_set_mode_t, custom_mode) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SET_MODE { \
    "SET_MODE", \
    3, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_set_mode_t, target_system) }, \
         { "base_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_set_mode_t, base_mode) }, \
         { "custom_mode", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_set_mode_t, custom_mode) }, \
         } \
}
#endif

/**
 * @brief Pack a set_mode message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system The system setting the mode
 * @param base_mode The new base mode
 * @param custom_mode The new autopilot-specific mode. This field can be ignored by an autopilot.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_mode_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t base_mode, uint32_t custom_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_MODE_LEN];
    _mav_put_uint32_t(buf, 0, custom_mode);
    _mav_put_uint8_t(buf, 4, target_system);
    _mav_put_uint8_t(buf, 5, base_mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_MODE_LEN);
#else
    mavlink_set_mode_t packet;
    packet.custom_mode = custom_mode;
    packet.target_system = target_system;
    packet.base_mode = base_mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_MODE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_MODE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SET_MODE_MIN_LEN, MAVLINK_MSG_ID_SET_MODE_LEN, MAVLINK_MSG_ID_SET_MODE_CRC);
}

/**
 * @brief Pack a set_mode message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system The system setting the mode
 * @param base_mode The new base mode
 * @param custom_mode The new autopilot-specific mode. This field can be ignored by an autopilot.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_mode_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t base_mode,uint32_t custom_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_MODE_LEN];
    _mav_put_uint32_t(buf, 0, custom_mode);
    _mav_put_uint8_t(buf, 4, target_system);
    _mav_put_uint8_t(buf, 5, base_mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_MODE_LEN);
#else
    mavlink_set_mode_t packet;
    packet.custom_mode = custom_mode;
    packet.target_system = target_system;
    packet.base_mode = b