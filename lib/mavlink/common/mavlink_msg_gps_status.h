#pragma once
// MESSAGE GPS_STATUS PACKING

#define MAVLINK_MSG_ID_GPS_STATUS 25

MAVPACKED(
typedef struct __mavlink_gps_status_t {
 uint8_t satellites_visible; /*< Number of satellites visible*/
 uint8_t satellite_prn[20]; /*< Global satellite ID*/
 uint8_t satellite_used[20]; /*< 0: Satellite not used, 1: used for localization*/
 uint8_t satellite_elevation[20]; /*< Elevation (0: right on top of receiver, 90: on the horizon) of satellite*/
 uint8_t satellite_azimuth[20]; /*< Direction of satellite, 0: 0 deg, 255: 360 deg.*/
 uint8_t satellite_snr[20]; /*< Signal to noise ratio of satellite*/
}) mavlink_gps_status_t;

#define MAVLINK_MSG_ID_GPS_STATUS_LEN 101
#define MAVLINK_MSG_ID_GPS_STATUS_MIN_LEN 101
#define MAVLINK_MSG_ID_25_LEN 101
#define MAVLINK_MSG_ID_25_MIN_LEN 101

#define MAVLINK_MSG_ID_GPS_STATUS_CRC 23
#define MAVLINK_MSG_ID_25_CRC 23

#define MAVLINK_MSG_GPS_STATUS_FIELD_SATELLITE_PRN_LEN 20
#define MAVLINK_MSG_GPS_STATUS_FIELD_SATELLITE_USED_LEN 20
#define MAVLINK_MSG_GPS_STATUS_FIELD_SATELLITE_ELEVATION_LEN 20
#define MAVLINK_MSG_GPS_STATUS_FIELD_SATELLITE_AZIMUTH_LEN 20
#define MAVLINK_MSG_GPS_STATUS_FIELD_SATELLITE_SNR_LEN 20

#if MAVLINK_COMMAND_24BIT
#define MA