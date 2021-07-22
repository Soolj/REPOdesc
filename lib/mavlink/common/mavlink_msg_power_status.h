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
static inline uint16_t mavlink_msg_power_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t Vcc,uint16_t Vservo,uint16_t flags)
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
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_POWER_STATUS_MIN_LEN, MAVLINK_MSG_ID_POWER_STATUS_LEN, MAVLINK_MSG_ID_POWER_STATUS_CRC);
}

/**
 * @brief Encode a power_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param power_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_power_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_power_status_t* power_status)
{
    return mavlink_msg_power_status_pack(system_id, component_id, msg, power_status->Vcc, power_status->Vservo, power_status->flags);
}

/**
 * @brief Encode a power_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param power_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_power_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_power_status_t* power_status)
{
    return mavlink_msg_power_status_pack_chan(system_id, component_id, chan, msg, power_status->Vcc, power_status->Vservo, power_status->flags);
}

/**
 * @brief Send a power_status message
 * @param chan MAVLink channel to send the message
 *
 * @param Vcc 5V rail voltage in millivolts
 * @param Vservo servo rail voltage in millivolts
 * @param flags power supply status flags (see MAV_POWER_STATUS enum)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_power_status_send(mavlink_channel_t chan, uint16_t Vcc, uint16_t Vservo, uint16_t flags)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_POWER_STATUS_LEN];
    _mav_put_uint16_t(buf, 0, Vcc);
    _mav_put_uint16_t(buf, 2, Vservo);
    _mav_put_uint16_t(buf, 4, flags);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POWER_STATUS, buf, MAVLINK_MSG_ID_POWER_STATUS_MIN_LEN, MAVLINK_MSG_ID_POWER_STATUS_LEN, MAVLINK_MSG_ID_POWER_STATUS_CRC);
#else
    mavlink_power_status_t packet;
    packet.Vcc = Vcc;
    packet.Vservo = Vservo;
    packet.flags = flags;

    _mav_finalize_message_chan_se