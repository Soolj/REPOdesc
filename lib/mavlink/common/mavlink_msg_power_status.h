#pragma once
// MESSAGE POWER_STATUS PACKING

#define MAVLINK_MSG_ID_POWER_STATUS 125

MAVPACKED(
typedef struct __mavlink_power_status_t {
 uint16_t Vcc; /*< 5V rail voltage in millivolts*/
 uint16_t Vservo; /*< servo rail voltage in millivolts*/
 uint16_t flags; /*< power supply status flags (see MAV_POWER_STATUS enum)*/
}) mavlink_power_status_t;

#define MAVLINK_MSG_ID_POWER_STATUS_LEN 6
#define MAVLINK_MSG_ID_POWER_STATUS_MIN_LEN 6
#define MAVLINK_MSG_ID_125_LEN 6
#define MAVLINK_MSG_ID_125_MIN_LEN 6

#define MAVLINK_MSG_ID_POWER_STATUS_CRC 203
#define MAVLINK_MSG_ID_125_CRC 203



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_POWER_STATUS { \
    125, \
    "POWER_STATUS", \
    3, \
    {  { "Vcc", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_power_status_t, Vcc) }, \
         { "Vservo", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_power_status_t, Vservo) }, \
         { "flags", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_power_status_t, flags) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_POWER_STATUS { \
    "POWER_STATUS", \
    3, \
    {  { "Vcc", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_power_status_t, Vcc) }, \
         { "Vservo", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_power_status_t, Vservo) }, \
         { "flags", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_power_status_t, flags) }, \
         } \
}
#endif

/**
 * @brief Pack a power_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Vcc 5V rail voltage in millivolts
 * @param Vservo servo rail voltage in millivolts
 * @param flags power supply status flags (see MAV_POWER_STATUS enum)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_power_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t Vcc, uint16_t Vservo, uint16_t flags)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_POWER_STATUS_LEN];
    _mav_put_uint16_t(buf, 0, Vcc);
    _mav_put_uint16_t(buf, 2, Vservo);
    _mav_put_uint16_t(buf, 4, flags);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_POWER_STATUS_LEN);
#else
    mavlink_power_status_t packet;
    packet.Vcc = Vcc;
    packet.Vservo = Vservo;
    packet.flags = flags;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_POWER_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_POWER_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_POWER_STATUS_MIN_LEN, MAVLINK_MSG_ID_POWER_STATUS_LEN, MAVLINK_MSG_ID_POWER_STATUS_CRC);
}

/**
 * @brief Pack a power_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Vcc 5V rail voltage in millivolts
 * @param Vservo servo rail voltage in millivolts
 * @param flags power supply status flags (see MAV_POWER_STATUS enum)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_power_status_pack_chan(uint8_t system_id, u