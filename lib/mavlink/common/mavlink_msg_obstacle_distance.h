#pragma once
// MESSAGE OBSTACLE_DISTANCE PACKING

#define MAVLINK_MSG_ID_OBSTACLE_DISTANCE 330

MAVPACKED(
typedef struct __mavlink_obstacle_distance_t {
 uint64_t time_usec; /*< Timestamp (microseconds since system boot or since UNIX epoch)*/
 uint16_t distances[72]; /*< Distance of obstacles in front of the sensor starting on the left side. A value of 0 means that the obstacle is right in front of the sensor. A value of max_distance +1 means no obstace is present. A value of UINT16_MAX for unknown/not used. In a array element, each unit corresponds to 1cm.*/
 uint16_t min_distance; /*< Minimum distance the sensor can measure in centimeters*/
 uint16_t max_distance; /*< Maximum distance the sensor can measure in centimeters*/
 uint8_t sensor_type; /*< Class id of the distance sensor type.*/
 uint8_t increment; /*< Angular width in degrees of each array element.*/
}) mavlink_obstacle_distance_t;

#define MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN 158
#define MAVLINK_MSG_ID_OBSTACLE_DISTANCE_MIN_LEN 158
#define MAVLINK_MSG_ID_330_LEN 158
#define MAVLINK_MSG_ID_330_MIN_LEN 158

#define MAVLINK_MSG_ID_OBSTACLE_DISTANCE_CRC 23
#define MAVLINK_MSG_ID_330_CRC 23

#define MAVLINK_MSG_OBSTACLE_DISTANCE_FIELD_DISTANCES_LEN 72

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_OBSTACLE_DISTANCE { \
    330, \
    "OBSTACLE_DISTANCE", \
    6, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_obstacle_distance_t, time_usec) }, \
         { "sensor_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 156, offsetof(mavlink_obstacle_distance_t, sensor_type) }, \
         { "distances", NULL, MAVLINK_TYPE_UINT16_T, 72, 8, offsetof(mavlink_obstacle_distance_t, distances) }, \
         { "increment", NULL, MAVLINK_TYPE_UINT8_T, 0, 157, offsetof(mavlink_obstacle_distance_t, increment) }, \
         { "min_distance", NULL, MAVLINK_TYPE_UINT16_T, 0, 152, offsetof(mavlink_obstacle_distance_t, min_distance) }, \
         { "max_distance", NULL, MAVLINK_TYPE_UINT16_T, 0, 154, offsetof(mavlink_obstacle_distance_t, max_distance) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_OBSTACLE_DISTANCE { \
    "OBSTACLE_DISTANCE", \
    6, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_obstacle_distance_t, time_usec) }, \
         { "sensor_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 156, offsetof(mavlink_obstacle_distance_t, sensor_type) }, \
         { "distances", NULL, MAVLINK_TYPE_UINT16_T, 72, 8, offsetof(mavlink_obstacle_distance_t, distances) }, \
         { "increment", NULL, MAVLINK_TYPE_UINT8_T, 0, 157, offsetof(mavlink_obstacle_distance_t, increment) }, \
         { "min_distance", NULL, MAVLINK_TYPE_UINT16_T, 0, 152, offsetof(mavlink_obstacle_distance_t, min_distance) }, \
         { "max_distance", NULL, MAVLINK_TYPE_UINT16_T, 0, 154, offsetof(mavlink_obstacle_distance_t, max_distance) }, \
         } \
}
#endif

/**
 * @brief Pack a obstacle_distance message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Timestamp (microseconds since system boot or since UNIX epoch)
 * @param sensor_type Class id of the distance sensor type.
 * @param distances Distance of obstacles in front of the sensor starting on the left side. A value of 0 means that the obstacle is right in front of the sensor. A value of max_distance +1 means no obstace is present. A value of UINT16_MAX for unknown/not used. In a array element, each unit corresponds to 1cm.
 * @param increment Angular width in degrees of each array element.
 * @param min_distance Minimum distance the sensor can measure in centimeters
 * @param max_distance Maximum distance the sensor can measure in centimeters
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_obstacle_distance_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint8_t sensor_type, const uint16_t *distances, uint8_t increment, uint16_t min_distance, uint16_t max_distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint16_t(buf, 152, min_distance);
    _mav_put_uint16_t(buf, 154, max_distance);
    _mav_put_uint8_t(buf, 156, sensor_type);
    _mav_put_uint8_t(buf, 157, increment);
    _mav_put_uint16_t_array(buf, 8, distances, 72);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN);
#else
    mavlink_obstacle_distance_t packet;
    packet.time_usec = time_usec;
    packet.min_distance = min_distance;
    packet.max_distance = max_distance;
    packet.sensor_type = sensor_type;
    packet.increment = increment;
    mav_array_memcpy(packet.distances, distances, sizeof(uint16_t)*72);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_OBSTACLE_DISTANCE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_MIN_LEN, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_CRC);
}

/**
 * @brief Pack a obstacle_distance message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Timestamp (microseconds since system boot or since UNIX epoch)
 * @param sensor_type Class id of the distance sensor type.
 * @param distances Distance of obstacles in front of the sensor starting on the left side. A value of 0 means that the obstacle is right in front of the sensor. A value of max_distance +1 means no obstace is present. A value of UINT16_MAX for unknown/not used. In a array element, each unit corresponds to 1cm.
 * @param increment Angular width in degrees of each array element.
 * @param min_distance Minimum distance the sensor can measure in centimeters
 * @param max_distance Maximum distance the sensor can measure in centimeters
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_obstacle_distance_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint8_t sensor_type,const uint16_t *distances,uint8_t increment,uint16_t min_distance,uint16_t max_distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint16_t(buf, 152, min_distance);
    _mav_put_uint16_t(buf, 154, max_distance);
    _mav_put_uint8_t(buf, 156, sensor_type);
    _mav_put_uint8_t(buf, 157, increment);
    _mav_put_uint16_t_array(buf, 8, distances, 72);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN);
#else
    mavlink_obstacle_distance_t packet;
    packet.time_usec = time_usec;
    packet.min_distance = min_distance;
    packet.max_distance = max_distance;
    packet.sensor_type = sensor_type;
    packet.increment = increment;
    mav_array_memcpy(packet.distances, distances, sizeof(uint16_t)*72);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_OBSTACLE_DISTANCE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_MIN_LEN, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_CRC);
}

/**
 * @brief Encode a obstacle_distance struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param obstacle_distance C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_obstacle_distance_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_obstacle_distance_t* obstacle_distance)
{
    return mavlink_msg_obstacle_distance_pack(system_id, component_id, msg, obstacle_distance->time_usec, obstacle_distance->sensor_type, obstacle_distance->distances, obstacle_distance->increment, obstacle_distance->min_distance, obstacle_distance->max_distance);
}

/**
 * @brief Encode a obstacle_distance struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param obstacle_distance C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_obstacle_distance_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_obstacle_distance_t* obstacle_distance)
{
    return mavlink_msg_obstacle_distance_pack_chan(system_id, component_id, chan, msg, obstacle_distance->time_usec, obstacle_distance->sensor_type, obstacle_distance->distances, obstacle_distance->increment, obstacle_distance->min_distance, obstacle_distance->max_distance);
}

/**
 * @brief Send a obstacle_distance message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Timestamp (microseconds since system boot or since UNIX epoch)
 * @param sensor_type Class id of the distance sensor type.
 * @param distances Distance of obstacles in front of the sensor starting on the left side. A value of 0 means that the obstacle is right in front of the sensor. A value of max_distance +1 means no obstace is present. A value of UINT16_MAX for unknown/not used. In a array element, each unit corresponds to 1cm.
 * @param increment Angular width in degrees of each array element.
 * @param min_distance Minimum distance the sensor can measure in centimeters
 * @param max_distance Maximum distance the sensor can measure in centimeters
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_obstacle_distance_send(mavlink_channel_t chan, uint64_t time_usec, uint8_t sensor_type, const uint16_t *distances, uint8_t increment, uint16_t min_distance, uint16_t max_distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint16_t(buf, 152, min_distance);
    _mav_put_uint16_t(buf, 154