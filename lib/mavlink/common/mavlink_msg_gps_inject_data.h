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
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param len data length
 * @param data raw data (110 is enough for 12 satellites of RTCMv2)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_inject_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint8_t len, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GPS_INJECT_DATA_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, len);
    _mav_put_uint8_t_array(buf, 3, data, 110);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPS_INJECT_DATA_LEN);
#else
    mavlink_gps_inject_data_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.len = len;
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*110);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPS_INJECT_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GPS_INJECT_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GPS_INJECT_DATA_MIN_LEN, MAVLINK_MSG_ID_GPS_INJECT_DATA_LEN, MAVLINK_MSG_ID_GPS_INJECT_DATA_CRC);
}

/**
 * @brief Pack a gps_inject_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param len data length
 * @param data raw data (110 is enough for 12 satellites of RTCMv2)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_inject_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint8_t len,const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GPS_INJECT_DATA_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, len);
    _mav_put_uint8_t_array(buf, 3, data, 110);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPS_INJECT_DATA_LEN);
#else
    mavlink_gps_inject_data_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.len = len;
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*110);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPS_INJECT_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GPS_INJECT_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GPS_INJECT_DATA_MIN_LEN, MAVLINK_MSG_ID_GPS_INJECT_DATA_LEN, MAVLINK_MSG_ID_GPS_INJECT