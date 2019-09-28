#pragma once
// MESSAGE BATTERY_STATUS PACKING

#define MAVLINK_MSG_ID_BATTERY_STATUS 147

MAVPACKED(
typedef struct __mavlink_battery_status_t {
 int32_t current_consumed; /*< Consumed charge, in milliampere hours (1 = 1 mAh), -1: autopilot does not provide mAh consumption estimate*/
 int32_t energy_consumed; /*< Consumed energy, in HectoJoules (intergrated U*I*dt)  (1 = 100 Joule), -1: autopilot does not provide energy consumption estimate*/
 int16_t temperature; /*< Temperature of the battery in centi-degrees celsius. INT16_MAX for unknown temperature.*/
 uint16_t voltages[10]; /*< Battery voltage of cells, in millivolts (1 = 1 millivolt). Cells above the valid cell count for this battery should have the UINT16_MAX value.*/
 int16_t current_battery; /*< Battery current, in 10*milliamperes (1 = 10 milliampere), -1: autopilot does not measure the current*/
 uint8_t id; /*< Battery ID*/
 uint8_t battery_function; /*< Function of the battery*/
 uint8_t type; /*< Type (chemistry) of the battery*/
 int8_t battery_remaining; /*< Remaining battery energy: (0%: 0, 100%: 100), -1: autopilot does not estimate the remaining battery*/
}) mavlink_battery_status_t;

#define MAVLINK_MSG_ID_BATTERY_STATUS_LEN 36
#define MAVLINK_MSG_ID_BATTERY_STATUS_MIN_LEN 36
#define MAVLINK_MSG_ID_147_LEN 36
#define 