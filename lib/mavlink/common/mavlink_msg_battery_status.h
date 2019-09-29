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
#define MAVLINK_MSG_ID_147_MIN_LEN 36

#define MAVLINK_MSG_ID_BATTERY_STATUS_CRC 154
#define MAVLINK_MSG_ID_147_CRC 154

#define MAVLINK_MSG_BATTERY_STATUS_FIELD_VOLTAGES_LEN 10

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_BATTERY_STATUS { \
    147, \
    "BATTERY_STATUS", \
    9, \
    {  { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_battery_status_t, id) }, \
         { "battery_function", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_battery_status_t, battery_function) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_battery_status_t, type) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_battery_status_t, temperature) }, \
         { "voltages", NULL, MAVLINK_TYPE_UINT16_T, 10, 10, offsetof(mavlink_battery_status_t, voltages) }, \
         { "current_battery", NULL, MAVLINK_TYPE_INT16_T, 0, 30, offsetof(mavlink_battery_status_t, current_battery) }, \
         { "current_consumed", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_battery_status_t, current_consumed) }, \
         { "energy_consumed", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_battery_status_t, energy_consumed) }, \
         { "battery_remaining", NULL, MAVLINK_TYPE_INT8_T, 0, 35, offsetof(mavlink_battery_status_t, battery_remaining) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_BATTERY_STATUS { \
    "BATTERY_STATUS", \
    9, \
    {  { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_battery_status_t, id) }, \
         { "battery_function", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_battery_status_t, battery_function) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_battery_status_t, type) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_battery_status_t, temperature) }, \
         { "voltages", NULL, MAVLINK_TYPE_UINT16_T, 10, 10, offsetof(mavlink_battery_status_t, voltages) }, \
         { "current_battery", NULL, MAVLINK_TYPE_INT16_T, 0, 30, offsetof(mavlink_battery_status_t, current_battery) }, \
         { "current_consumed", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_battery_status_t, current_consumed) }, \
         { "energy_consumed", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_battery_status_t, energy_consumed) }, \
         { "battery_remaining", NULL, MAVLINK_TYPE_INT8_T, 0, 35, offsetof(mavlink_battery_status_t, battery_remaining) }, \
         } \
}
#endif

/**
 * @brief Pack a battery_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param id Battery ID
 * @param battery_function Function of the battery
 * @param type Type (chemistry) of the battery
 * @param temperature Temperature of the battery in centi-degrees celsius. INT16_MAX for unknown temperature.
 * @param voltages Battery voltage of cells, in millivolts (1 = 1 millivolt). Cells above the valid cell count for this battery should have the UINT16_MAX value.
 * @param current_battery Battery current, in 10*milliamperes (1 = 