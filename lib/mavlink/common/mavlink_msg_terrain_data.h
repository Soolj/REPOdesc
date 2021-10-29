#pragma once
// MESSAGE TERRAIN_DATA PACKING

#define MAVLINK_MSG_ID_TERRAIN_DATA 134

MAVPACKED(
typedef struct __mavlink_terrain_data_t {
 int32_t lat; /*< Latitude of SW corner of first grid (degrees *10^7)*/
 int32_t lon; /*< Longitude of SW corner of first grid (in degrees *10^7)*/
 uint16_t grid_spacing; /*< Grid spacing in meters*/
 int16_t data[16]; /*< Terrain data in meters AMSL*/
 uint8_t gridbit; /*< bit within the terrain request mask*/
}) mavlink_terrain_data_t;

#define MAVLINK_MSG_ID_TERRAIN_DATA_LEN 43
#define MAVLINK_MSG_ID_TERRAIN_DATA_MIN_LEN 43
#define MAVLINK_MSG_ID_134_LEN 43
#define MAVLINK_MSG_ID_134_MIN_LEN 43

#define MAVLINK_MSG_ID_TERRAIN_DATA_CRC 229
#define MAVLINK_MSG_ID_134_CRC 229

#define MAVLINK_MSG_TERRAIN_DATA_FIELD_DATA_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TERRAIN_DATA { \
    134, \
    "TERRAIN_DATA", \
    5, \
    {  { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_terrain_data_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_terrain_data_t, lon) }, \
         { "grid_spacing", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_terrain_data_t, grid_spacing) }, \
         { "gridbit", NULL, MAVLINK_TYPE_UINT8_T, 0, 42, offsetof(mavlink_terrain_data_t, gridbit) }, \
         { "data", NULL, MAVLINK_TYPE_INT16_T, 16, 10, offsetof(mavlink_terrain_data_t, data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TERRAIN_DATA { \
    "TERRAIN_DATA", \
    5, \
    {  { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_terrain_data_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_terrain_data_t, lon) }, \
         { "grid_spacing", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_terrain_data_t, grid_spacing) }, \
         { "gridbit", NULL, MAVLINK_TYPE_UINT8_T, 0, 42, offsetof(mavlink_terrain_data_t, gridbit) }, \
         { "data", NULL, MAVLINK_TYPE_INT16_T, 16, 10, offsetof(mavlink_terrain_data_t, data) }, \
         } \
}
#endif

/**
 * @brief Pack a terrain_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param lat Latitude of SW corner of first grid (degrees *10^7)
 * @param lon Longitude of SW corner of first grid (in degrees *10^7)
 * @param grid_spacing