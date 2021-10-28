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
#de