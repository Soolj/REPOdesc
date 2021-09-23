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
         { "custom_mode", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_set_mode_t, c