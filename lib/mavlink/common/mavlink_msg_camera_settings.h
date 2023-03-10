
#pragma once
// MESSAGE CAMERA_SETTINGS PACKING

#define MAVLINK_MSG_ID_CAMERA_SETTINGS 260

MAVPACKED(
typedef struct __mavlink_camera_settings_t {
 uint32_t time_boot_ms; /*< Timestamp (milliseconds since system boot)*/
 uint8_t mode_id; /*< Camera mode (CAMERA_MODE)*/
}) mavlink_camera_settings_t;

#define MAVLINK_MSG_ID_CAMERA_SETTINGS_LEN 5
#define MAVLINK_MSG_ID_CAMERA_SETTINGS_MIN_LEN 5
#define MAVLINK_MSG_ID_260_LEN 5
#define MAVLINK_MSG_ID_260_MIN_LEN 5

#define MAVLINK_MSG_ID_CAMERA_SETTINGS_CRC 146
#define MAVLINK_MSG_ID_260_CRC 146



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CAMERA_SETTINGS { \
    260, \
    "CAMERA_SETTINGS", \
    2, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_camera_settings_t, time_boot_ms) }, \
         { "mode_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_camera_settings_t, mode_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CAMERA_SETTINGS { \
    "CAMERA_SETTINGS", \
    2, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_camera_settings_t, time_boot_ms) }, \
         { "mode_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_camera_settings_t, mode_id) }, \
         } \
}
#endif

/**
 * @brief Pack a camera_settings message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms Timestamp (milliseconds since system boot)
 * @param mode_id Camera mode (CAMERA_MODE)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_camera_settings_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint8_t mode_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CAMERA_SETTINGS_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint8_t(buf, 4, mode_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CAMERA_SETTINGS_LEN);
#else
    mavlink_camera_settings_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.mode_id = mode_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CAMERA_SETTINGS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CAMERA_SETTINGS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CAMERA_SETTINGS_MIN_LEN, MAVLINK_MSG_ID_CAMERA_SETTINGS_LEN, MAVLINK_MSG_ID_CAMERA_SETTINGS_CRC);
}

/**
 * @brief Pack a camera_settings message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms Timestamp (milliseconds since system boot)
 * @param mode_id Camera mode (CAMERA_MODE)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_camera_settings_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint8_t mode_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CAMERA_SETTINGS_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint8_t(buf, 4, mode_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CAMERA_SETTINGS_LEN);
#else
    mavlink_camera_settings_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.mode_id = mode_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CAMERA_SETTINGS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CAMERA_SETTINGS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CAMERA_SETTINGS_MIN_LEN, MAVLINK_MSG_ID_CAMERA_SETTINGS_LEN, MAVLINK_MSG_ID_CAMERA_SETTINGS_CRC);
}

/**
 * @brief Encode a camera_settings struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param camera_settings C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_camera_settings_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_camera_settings_t* camera_settings)
{
    return mavlink_msg_camera_settings_pack(system_id, component_id, msg, camera_settings->time_boot_ms, camera_settings->mode_id);
}

/**
 * @brief Encode a camera_settings struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param camera_settings C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_camera_settings_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_camera_settings_t* camera_settings)
{
    return mavlink_msg_camera_settings_pack_chan(system_id, component_id, chan, msg, camera_settings->time_boot_ms, camera_settings->mode_id);
}

/**
 * @brief Send a camera_settings message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms Timestamp (milliseconds since system boot)
 * @param mode_id Camera mode (CAMERA_MODE)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_camera_settings_send(mavlink_channel_t chan, uint32_t time_boot_ms, uint8_t mode_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CAMERA_SETTINGS_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint8_t(buf, 4, mode_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CAMERA_SETTINGS, buf, MAVLINK_MSG_ID_CAMERA_SETTINGS_MIN_LEN, MAVLINK_MSG_ID_CAMERA_SETTINGS_LEN, MAVLINK_MSG_ID_CAMERA_SETTINGS_CRC);
#else
    mavlink_camera_settings_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.mode_id = mode_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CAMERA_SETTINGS, (const char *)&packet, MAVLINK_MSG_ID_CAMERA_SETTINGS_MIN_LEN, MAVLINK_MSG_ID_CAMERA_SETTINGS_LEN, MAVLINK_MSG_ID_CAMERA_SETTINGS_CRC);
#endif
}

/**
 * @brief Send a camera_settings message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_camera_settings_send_struct(mavlink_channel_t chan, const mavlink_camera_settings_t* camera_settings)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_camera_settings_send(chan, camera_settings->time_boot_ms, camera_settings->mode_id);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CAMERA_SETTINGS, (const char *)camera_settings, MAVLINK_MSG_ID_CAMERA_SETTINGS_MIN_LEN, MAVLINK_MSG_ID_CAMERA_SETTINGS_LEN, MAVLINK_MSG_ID_CAMERA_SETTINGS_CRC);
#endif
}

#if MAVLINK_MSG_ID_CAMERA_SETTINGS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_camera_settings_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, uint8_t mode_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint8_t(buf, 4, mode_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CAMERA_SETTINGS, buf, MAVLINK_MSG_ID_CAMERA_SETTINGS_MIN_LEN, MAVLINK_MSG_ID_CAMERA_SETTINGS_LEN, MAVLINK_MSG_ID_CAMERA_SETTINGS_CRC);
#else
    mavlink_camera_settings_t *packet = (mavlink_camera_settings_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->mode_id = mode_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CAMERA_SETTINGS, (const char *)packet, MAVLINK_MSG_ID_CAMERA_SETTINGS_MIN_LEN, MAVLINK_MSG_ID_CAMERA_SETTINGS_LEN, MAVLINK_MSG_ID_CAMERA_SETTINGS_CRC);
#endif
}
#endif

#endif

// MESSAGE CAMERA_SETTINGS UNPACKING


/**
 * @brief Get field time_boot_ms from camera_settings message
 *
 * @return Timestamp (milliseconds since system boot)
 */
static inline uint32_t mavlink_msg_camera_settings_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field mode_id from camera_settings message
 *
 * @return Camera mode (CAMERA_MODE)
 */
static inline uint8_t mavlink_msg_camera_settings_get_mode_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Decode a camera_settings message into a struct
 *
 * @param msg The message to decode
 * @param camera_settings C-struct to decode the message contents into
 */
static inline void mavlink_msg_camera_settings_decode(const mavlink_message_t* msg, mavlink_camera_settings_t* camera_settings)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    camera_settings->time_boot_ms = mavlink_msg_camera_settings_get_time_boot_ms(msg);
    camera_settings->mode_id = mavlink_msg_camera_settings_get_mode_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CAMERA_SETTINGS_LEN? msg->len : MAVLINK_MSG_ID_CAMERA_SETTINGS_LEN;
        memset(camera_settings, 0, MAVLINK_MSG_ID_CAMERA_SETTINGS_LEN);
    memcpy(camera_settings, _MAV_PAYLOAD(msg), len);
#endif
}