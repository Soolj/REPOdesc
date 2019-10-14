#pragma once
// MESSAGE BUTTON_CHANGE PACKING

#define MAVLINK_MSG_ID_BUTTON_CHANGE 257

MAVPACKED(
typedef struct __mavlink_button_change_t {
 uint32_t time_boot_ms; /*< Timestamp (milliseconds since system boot)*/
 uint32_t last_change_ms; /*< Time of last change of button state*/
 uint8_t state; /*< Bitmap state of buttons*/
}) mavlink_button_change_t;

#define MAVLINK_MSG_ID_BUTTON_CHANGE_LEN 9
#define MAVLINK_MSG_ID_BUTTON_CHANGE_MIN_LEN 9
#define MAVLINK_MSG_ID_257_LEN 9
#define MAVLINK_MSG_ID_257_MIN_LEN 9

#define MAVLINK_MSG_ID_BUTTON_CHANGE_CRC 131
#define MAVLINK_MSG_ID_257_CRC 131



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_BUTTON_CHANGE { \
    257, \
    "BUTTON_CHANGE", \
    3, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_button_change_t, time_boot_ms) }, \
         { "last_change_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_button_change_t, last_change_ms) }, \
         { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_button_change_t, state) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_BUTTON_CHANGE { \
    "BUTTON_CHANGE", \
    3, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_button_change_t, time_boot_ms) }, \
         { "last_change_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_button_change_t, last_change_ms) }, \
         { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_button_change_t, state) }, \
         } \
}
#endif

/**
 * @brief Pack a button_change message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms Timestamp (milliseconds since system boot)
 * @param last_change_ms Time of last change of button state
 * @param state Bitmap state of buttons
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_button_change_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint32_t last_change_ms, uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BUTTON_CHANGE_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, last_change_ms);
    _mav_put_uint8_t(buf, 8, state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BUTTON_CHANGE_LEN);
#else
    mavlink_button_change_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.last_change_ms = last_change_ms;
    packet.state = state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BUTTON_CHANGE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BUTTON_CHANGE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BUTTON_CHANGE_MIN_LEN, MAVLINK_MSG_ID_BUTTON_CHANGE_LEN, MAVLINK_MSG_ID_BUTTON_CHANGE_CRC);
}

/**
 * @brief Pack a button_change message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms Timestamp (milliseconds since system boot)
 * @param last_change_ms Time of last change of button state
 * @param state Bitmap state of buttons
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_button_change_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint32_t last_change_ms,uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BUTTON_CHANGE_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, last_change_ms);
    _mav_put_uint8_t(buf, 8, state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BUTTON_CHANGE_LEN);
#else
    mavlink_button_change_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.last_change_ms = last_change_ms;
    packet.state = state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BUTTON_CHANGE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BUTTON_CHANGE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BUTTON_CHANGE_MIN_LEN, MAVLINK_MSG_ID_BUTTON_CHANGE_LEN, MAVLINK_MSG_ID_BUTTON_CHANGE_CRC);
}

/**
 * @brief Encode a button_change struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param button_change C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_button_change_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_button_change_t* button_change)
{
    return mavlink_msg_button_change_pack(system_id, component_id, msg, button_change->time_boot_ms, button_change->last_change_ms, button_change->state);
}

/**
 * @brief Encode a button_change struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param button_change C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_button_change_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_button_change_t* button_change)
{
    return mavlink_msg_button_change_pack_chan(system_id, component_id, chan, msg, button_change->time_boot_ms, button_change->last_change_ms, button_change->state);
}

/**
 * @brief Send a button_change message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms Timestamp (milliseconds since system boot)
 * @param last_change_ms Time of last change of button state
 * @param state Bitmap state of buttons
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_button_change_send(mavlink_channel_t chan, uint32_t time_boot_ms, uint32_t last_change_ms, uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BUTTON_CHANGE_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, last_change_ms);
    _mav_put_uint8_t(buf, 8, state);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BUTTON_CHANGE, buf, MAVLINK_MSG_ID_BUTTON_CHANGE_MIN_LEN, MAVLI