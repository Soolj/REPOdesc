#pragma once
// MESSAGE GPS_INJECT_DATA PACKING

#define MAVLINK_MSG_ID_GPS_INJECT_DATA 123

MAVPACKED(
typedef struct __mavlink_gps_inject_data_t {
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 uint8_t len; /*< data length*/
 uint8_t data[110]; /*< raw data (110 is enough for 12 satellites of RTCMv2)*/
}) mavlink_gps_inject_data_t;

#define MAVLINK_MSG_ID_GPS_INJECT_DATA_LEN 113
#define MAVLINK_MSG_ID_GPS_INJECT_DATA_MIN_LEN 113
#define MAVLINK_MSG_ID_123_LEN 113
#define MAVLINK_MSG_ID_123_MIN_LEN 113

#define MAVLINK_MSG_ID_GPS_INJECT_DATA_CRC 250
#define MAVLINK_MSG_ID_123_CRC 250

#define MAVLINK_MSG_GPS_INJECT_DATA_FIELD_DATA_LEN 110

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GPS_INJECT_DATA { \
    123, \
    "GPS_INJECT_DATA", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_gps_inject_data_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_gps_inject_data_t, target_component) }, \
         { "len", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_gps_inject_data_t, len) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 110, 3, offsetof(mavlink_gps_inject_data_t, data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GPS_INJECT_DATA { \
    "GPS_INJECT_DATA", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_gps_inject_data_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_gps_inject_data_t, target_component) }, \
         { "len", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_gps_inject_data_t, len) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 110, 3, offsetof(mavlink_gps_inject_data_t, data) }, \
         } \
}
#endif

/**
 * @brief Pack a gps_inject_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress