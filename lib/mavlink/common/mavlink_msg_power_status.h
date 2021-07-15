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
static inl