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
#define MAVLINK_MSG_ID_BUTTON_CHANGE_MI