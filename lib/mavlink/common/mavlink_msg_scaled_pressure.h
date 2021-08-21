#pragma once
// MESSAGE SCALED_PRESSURE PACKING

#define MAVLINK_MSG_ID_SCALED_PRESSURE 29

MAVPACKED(
typedef struct __mavlink_scaled_pressure_t {
 uint32_t time_boot_ms; /*< Timestamp (milliseconds since system boot)*/
 float press_abs; /*< Absolute pressure (hectopascal)*/
 float press_diff; /*< Differential pressure 1 (hectopascal)*/
 int16_t temperature; /*< Temperature measurement (0.01 degrees celsius)*/
}) mavlink_scaled_pressure_t;

#define MAVLINK_MSG_ID_SCALED_PRESSURE_LEN 14
#define MAVLINK_MSG_ID_SCALED_PRESSURE_MIN_LEN 14
#define MAVLINK_MSG_ID_29_LEN 14
#define MAVLINK_MSG_ID_29_MIN_LEN 14

#define MAVLINK_MSG_ID_SCALED_PRESSURE_CRC 115
#define MAVLINK_MSG_ID_29_CRC 115



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SCALED_PRESSURE { \
    29, \
    "SCALED_PRESSURE", \
    4, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_scaled_pressure_t, time_boot_ms) }, \
         { "press_abs", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_scaled_pressure_t, press_abs) }, \
         { "press_diff", NULL, MA