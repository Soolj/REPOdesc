#pragma once
// MESSAGE MESSAGE_INTERVAL PACKING

#define MAVLINK_MSG_ID_MESSAGE_INTERVAL 244

MAVPACKED(
typedef struct __mavlink_message_interval_t {
 int32_t interval_us; /*< The interval between two messages, in microseconds. A value of -1 indicates this stream is disabled, 0 indicates it is not available, > 0 indicates the interval at which it is sent.*/
 uint16_t message_id; /*< The ID of the requested MAVLink message. v1.0 is limited to 254 messages.*/
}) mavlink_message_interval_t;

#define MAVLINK_MSG_ID_MESSAGE_INTERVAL_LEN 6
#define MAVLINK_MSG_ID_MESSAGE_INTERVAL_MIN_LEN 6
#define MAVLINK_MSG_ID_244_LEN 6
#define MAVLINK_MSG_ID_244_MIN_LEN 6

#define MAVLINK_MSG_ID_MESSAGE_INTERVAL_CRC 95
#define MAVLINK_MSG_ID_244_CRC 95



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MESSAGE_INTERVAL { \
    244, \
    "MESSAGE_INTERVAL", \
    2, \
    {  { "message_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_message_interval_t, message_id) }, \
         { "interval_us", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_message_interval_t, interval_us) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MESSAGE_INTERVAL { \
    "MESSAGE_INTERVAL", \
    2, \
    {  { "message_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_message_interval_t, message_id) }, \
         { "interval_us", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_message_interval_t, interval_us) }, \
         } \
}
#endif

/**
 * @brief Pack a message_interval message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param message_id The ID of the requested MAVLink message. v1.0 is limited to 254 messages.
 * @param interval_us The interval between two messages, in microseconds. A value of -1 indicates this stream is disabled, 0 indicates it is 