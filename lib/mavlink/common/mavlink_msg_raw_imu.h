#pragma once
// MESSAGE RAW_IMU PACKING

#define MAVLINK_MSG_ID_RAW_IMU 27

MAVPACKED(
typedef struct __mavlink_raw_imu_t {
 uint64_t time_usec; /*< Timestamp (microseconds since UNIX epoch or microseconds since system boot)*/
 int16_t xacc; /*< X acceleration (raw)*/
 int16_t yacc; /*< Y acceleration (raw)*/
 int16_t zacc; /*< Z acceleration (raw)*/
 int16_t xgyro; /*< Angular speed around X axis (raw)*/
 int16_t ygyro; /*< Angula