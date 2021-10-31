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
 * @param grid_spacing Grid spacing in meters
 * @param gridbit bit within the terrain request mask
 * @param data Terrain data in meters AMSL
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_terrain_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int32_t lat, int32_t lon, uint16_t grid_spacing, uint8_t gridbit, const int16_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TERRAIN_DATA_LEN];
    _mav_put_int32_t(buf, 0, lat);
    _mav_put_int32_t(buf, 4, lon);
    _mav_put_uint16_t(buf, 8, grid_spacing);
    _mav_put_uint8_t(buf, 42, gridbit);
    _mav_put_int16_t_array(buf, 10, data, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TERRAIN_DATA_LEN);
#else
    mavlink_terrain_data_t packet;
    packet.lat = lat;
    packet.lon = lon;
    packet.grid_spacing = grid_spacing;
    packet.gridbit = gridbit;
    mav_array_memcpy(packet.data, data, sizeof(int16_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TERRAIN_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TERRAIN_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TERRAIN_DATA_MIN_LEN, MAVLINK_MSG_ID_TERRAIN_DATA_LEN, MAVLINK_MSG_ID_TERRAIN_DATA_CRC);
}

/**
 * @brief Pack a terrain_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lat Latitude of SW corner of first grid (degrees *10^7)
 * @param lon Longitude of SW corner of first grid (in degrees *10^7)
 * @param grid_spacing Grid spacing in meters
 * @param gridbit bit within the terrain request mask
 * @param data Terrain data in meters AMSL
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_terrain_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int32_t lat,int32_t lon,uint16_t grid_spacing,uint8_t gridbit,const int16_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TERRAIN_DATA_LEN];
    _mav_put_int32_t(buf, 0, lat);
    _mav_put_int32_t(buf, 4, lon);
    _mav_put_uint16_t(buf, 8, grid_spacing);
    _mav_put_uint8_t(buf, 42, gridbit);
    _mav_put_int16_t_array(buf, 10, data, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TERRAIN_DATA_LEN);
#else
    mavlink_terrain_data_t packet;
    packet.lat = lat;
    packet.lon = lon;
    packet.grid_spacing = grid_spacing;
    packet.gridbit = gridbit;
    mav_array_memcpy(packet.data, data, sizeof(int16_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TERRAIN_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TERRAIN_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TERRAI