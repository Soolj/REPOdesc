#pragma once
// MESSAGE POWER_STATUS PACKING

#define MAVLINK_MSG_ID_POWER_STATUS 125

MAVPACKED(
typedef struct __mavlink_power_status_t {
 uint16_t Vcc; /*< 5V rail voltage in millivolts*/
 uint16_t Vservo; /*< servo rail voltage in millivolts*/
 uint16_t flags; /*< power supply status flags (see MAV_POWER_STATUS enum)*/
}) mavlink_power_status_t;

#define MAVLINK_MS