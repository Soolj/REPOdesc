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
 int16_t ygyro; /*< Angular speed around Y axis (raw)*/
 int16_t zgyro; /*< Angular speed around Z axis (raw)*/
 int16_t xmag; /*< X Magnetic field (raw)*/
 int16_t ymag; /*< Y Magnetic field (raw)*/
 int16_t zmag; /*< Z Magnetic field (raw)*/
}) mavlink_raw_imu_t;

#define MAVLINK_MSG_ID_RAW_IMU_LEN 26
#define MAVLINK_MSG_ID_RAW_IMU_MIN_LEN 26
#define MAVLINK_MSG_ID_27_LEN 26
#define MAVLINK_MSG_ID_27_MIN_LEN 26

#define MAVLINK_MSG_ID_RAW_IMU_CRC 144
#define MAVLINK_MSG_ID_27_CRC 144



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RAW_IMU { \
    27, \
    "RAW_IMU", \
    10, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_raw_imu_t, time_usec) }, \
         { "xacc", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_raw_imu_t, xacc) }, \
         { "yacc", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_raw_imu_t, yacc) }, \
         { "zacc", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_raw_imu_t, zacc) }, \
         { "xgyro", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_raw_imu_t, xgyro) }, \
         { "ygyro", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_raw_imu_t, ygyro) }, \
         { "zgyro", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_raw_imu_t, zgyro) }, \
         { "xmag", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_raw_imu_t, xmag) }, \
         { "ymag", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_raw_imu_t, ymag) }, \
         { "zmag", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_raw_imu_t, zmag) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RA