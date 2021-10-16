#pragma once
// MESSAGE STATUSTEXT PACKING

#define MAVLINK_MSG_ID_STATUSTEXT 253

MAVPACKED(
typedef struct __mavlink_statustext_t {
 uint8_t severity; /*< Severity of status. Relies on the definitions within RFC-5424. See enum MAV_SEVERITY.*/
 char text[50]; /*< Status text message, without null termination character*/
}) mavlink_statustext_t;

#define MAVLINK_MSG_ID_STATUSTEXT_LEN 51
#define MAVLINK_MSG_ID_STATUSTEXT_MIN_LEN 51
#define MAVLINK_MSG_ID_253_LEN 51
#define MAVLINK_MSG_ID_253_MIN_LEN 51

#define MAVLINK_MSG_ID_STATUSTEXT_CRC 83
#define MAVLINK_MSG_ID_253_CRC 83

#define MAVLINK_MSG_STATUSTEXT_FIELD_TEXT_LEN 50

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_STATUSTEXT { \
    253, \
    "STATUSTEXT", \
    2, \
    {  { "severity", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_statustext_t, severity) }, \
         { "text", NULL, MAVLINK_TYPE_CHAR, 50, 1, offsetof(mavlink_statustext_t, text) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_STATUSTEXT { \
    "STATUSTEXT", \
    2, \
    {  { "severity", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_statustext_t, severity) }, \
         { "text", NULL, MAVLINK_TYPE_CHAR, 50, 1, offsetof(mavlink_statustext_t, text) }, \
         } \
}
#endif

/**
 * @brief Pack a statustext message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param severity Severity of status. Relies on the definitions within RFC-5424. See enum MAV_SEVERITY.
 * @param text Status text message, without null termination character
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_statustext_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t severity, const char *text)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_STATUSTEXT_LEN];
    _mav_put_uint8_t(buf, 0, severity);
    _mav_put_char_array(buf, 1, text, 50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG