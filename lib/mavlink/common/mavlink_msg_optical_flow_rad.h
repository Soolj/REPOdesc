#pragma once
// MESSAGE OPTICAL_FLOW_RAD PACKING

#define MAVLINK_MSG_ID_OPTICAL_FLOW_RAD 106

MAVPACKED(
typedef struct __mavlink_optical_flow_rad_t {
 uint64_t time_usec; /*< Timestamp (microseconds, synced to UNIX time or since system boot)*/
 uint32_t integration_time_us; /*< Integration time in microseconds. Divide integrated_x and integrated_y by the integration time to obtain average flow. The integration time also indicates the.*/
 float integrated_x; /*< Flow in radians around X axis (Sensor RH rotation about the X axis induces a positive flow. Sensor linear motion along the positive Y axis induces a negative flow.)*/
 float integrated_y; /*< Flow in radians around Y axis (Sensor RH rotation about the Y axis induces a positive flow. Sensor linear motion along the positive X axis induces a positive flow.)*/
 float integrated_xgyro; /*< RH rotation around X axis (rad)*/
 float integrated_ygyro; /*< RH rotation around Y axis (rad)*/
 float integrated_zgyro; /*< RH rotation around Z axis (rad)*/
 uint32_t time_delta_distance_us; /*< Time in microseconds since the distance was sampled.*/
 float distance; /*< Distance to the center of the flow field in meters. Positive value (including zero): distance known. Negative value: Unknown distance.*/
 int16_t temperature; /*< Temperature * 100 in centi-degrees Celsius*/
 uint8_t sensor_id; /*< Sensor ID*/
 uint8_t quality; /*< Optical flow quality / confidence. 0: no valid flow, 255: maximum quality*/
}) mavlink_optical_flow_rad_t;

#define MAVLINK_MSG_ID_OPTICAL_FLOW_RAD_LEN 44
#define MAVLINK_MSG_ID_OPTICAL_FLOW_RAD_MIN_LEN 44
#define MAVLINK_MSG_ID_106_LEN 44
#define MAVLINK_MSG_ID_106_MIN_LEN 44

#define MAVLINK_MSG_ID_OPTICAL_FLOW_RAD_CRC 138
#define MAVLINK_MSG_ID_106_CRC 138



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_OPTICAL_FLOW_RAD { \
    106, \
    "OPTICAL_FLOW_RAD", \
    12, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_optical_flow_rad_t, time_usec) }, \
         { "sensor_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 42, offsetof(mavlink_optical_flow_rad_t, sensor_id) }, \
         { "integration_time_us", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_optical_flow_rad_t, integration_time_us) }, \
         { "integrated_x", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_optical_flow_rad_t, integrated_x) }, \
         { "integrated_y", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_optical_flow_rad_t, integrated_y) }, \
         { "integrated_xgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_optical_flow_rad_t, integrated_xgyro) }, \
         { "integrated_ygyro", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_optical_flow_rad_t, integrated_ygyro) }, \
         { "integrated_zgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_optical_flow_rad_t, integrated_zgyro) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 40, offsetof(mavlink_optical_flow_rad_t, temperature) }, \
         { "quality", NULL, MAVLINK_TYPE_UINT8_T, 0, 43, offsetof(mavlink_optical_flow_rad_t, quality) }, \
         { "time_delta_distance_us", NULL, MAVLINK_TYPE_UINT32_T, 0, 32, offsetof(mavlink_optical_flow_rad_t, time_delta_distance_us) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_optical_flow_rad_t, distance) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_OPTICAL_FLOW_RAD { \
    "OPTICAL_FLOW_RAD", \
    12, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_optical_flow_rad_t, time_usec) }, \
         { "sensor_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 42, offsetof(mavlink_optical_flow_rad_t, sensor_id) }, \
         { "integration_time_us", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_optical_flow_rad_t, integration_time_us) }, \
         { "integrated_x", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_optical_flow_rad_t, integrated_x) }, \
         { "integrated_y", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_optical_flow_rad_t, integrated_y) }, \
         { "integrated_xgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_optical_flow_rad_t, integrated_xgyro) }, \
         { "integrated_ygyro", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_optical_flow_rad_t, integrated_ygyro) }, \
         { "integrated_zgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_optical_flow_rad_t, integrated_zgyro) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 40, offsetof(mavlink_optical_flow_rad_t, temperature) }, \
         { "quality", NULL, MAVLINK_TYPE_UINT8_T, 0, 43, offsetof(mavlink_optical_flow_rad_t, quality) }, \
         { "time_delta_distance_us", NULL, MAVLINK_TYPE_UINT32_T, 0, 32, offsetof(mavlink_optical_flow_rad_t, time_delta_distance_us) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_optical_flow_rad_t, distance) }, \
         } \
}
#endif

/**
 * @brief Pack a optical_flow_rad message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Timestamp (microseconds, synced to UNIX time or since system boot)
 * @param sensor_id Sensor ID
 * @param integration_time_us Integration time in microseconds. Divide integrated_x and integrated_y by the integration time to obtain average flow. The integration time also indicates the.
 * @param integrated_x Flow in radians around X axis (Sensor RH rotation about the X axis induces a positive flow. Sensor linear motion al