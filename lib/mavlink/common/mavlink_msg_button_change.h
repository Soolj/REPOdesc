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
static inline uint16_t mavlink_msg_button_cha