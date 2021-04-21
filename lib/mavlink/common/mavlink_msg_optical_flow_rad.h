#pragma once
// MESSAGE OPTICAL_FLOW_RAD PACKING

#define MAVLINK_MSG_ID_OPTICAL_FLOW_RAD 106

MAVPACKED(
typedef struct __mavlink_optical_flow_rad_t {
 uint64_t time_usec; /*< Timestamp (microseconds, synced to UNIX time or since system boot)*/
 uint32_t integration_time_us; /*< Integration time in microseconds. Divide integrated_x and integrated_y by the integration time to obtain average flow. The integration time also indicates the.*/
 float integrated_x; /*< Flow in radians around X axis (Sensor RH rotation about the X axis induces a positive flow. Sensor linear motion along the positive Y axis induces a negative flow.)*/
 float integrated_y; /*< Flow in radians around Y axis (Sensor RH rotation about the Y axis induces a positive flow. Sensor linear motion along the po