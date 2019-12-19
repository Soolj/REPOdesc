
#pragma once
// MESSAGE DISTANCE_SENSOR PACKING

#define MAVLINK_MSG_ID_DISTANCE_SENSOR 132

MAVPACKED(
typedef struct __mavlink_distance_sensor_t {
 uint32_t time_boot_ms; /*< Time since system boot*/
 uint16_t min_distance; /*< Minimum distance the sensor can measure in centimeters*/
 uint16_t max_distance; /*< Maximum distance the sensor can measure in centimeters*/
 uint16_t current_distance; /*< Current distance reading*/
 uint8_t type; /*< Type from MAV_DISTANCE_SENSOR enum.*/
 uint8_t id; /*< Onboard ID of the sensor*/
 uint8_t orientation; /*< Direction the sensor faces from MAV_SENSOR_ORIENTATION enum. downward-facing: ROTATION_PITCH_270, upward-facing: ROTATION_PITCH_90, backward-facing: ROTATION_PITCH_180, forward-facing: ROTATION_NONE, left-facing: ROTATION_YAW_90, right-facing: ROTATION_YAW_270*/
 uint8_t covariance; /*< Measurement covariance in centimeters, 0 for unknown / invalid readings*/
}) mavlink_distance_sensor_t;

#define MAVLINK_MSG_ID_DISTANCE_SENSOR_LEN 14
#define MAVLINK_MSG_ID_DISTANCE_SENSOR_MIN_LEN 14
#define MAVLINK_MSG_ID_132_LEN 14
#define MAVLINK_MSG_ID_132_MIN_LEN 14

#define MAVLINK_MSG_ID_DISTANCE_SENSOR_CRC 85
#define MAVLINK_MSG_ID_132_CRC 85



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DISTANCE_SENSOR { \
    132, \
    "DISTANCE_SENSOR", \
    8, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_distance_sensor_t, time_boot_ms) }, \
         { "min_distance", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_distance_sensor_t, min_distance) }, \
         { "max_distance", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_distance_sensor_t, max_distance) }, \
         { "current_distance", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_distance_sensor_t, current_distance) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_distance_sensor_t, type) }, \
         { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_distance_sensor_t, id) }, \
         { "orientation", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_distance_sensor_t, orientation) }, \
         { "covariance", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_distance_sensor_t, covariance) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DISTANCE_SENSOR { \
    "DISTANCE_SENSOR", \
    8, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_distance_sensor_t, time_boot_ms) }, \
         { "min_distance", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_distance_sensor_t, min_distance) }, \
         { "max_distance", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_distance_sensor_t, max_distance) }, \
         { "current_distance", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_distance_sensor_t, current_distance) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_distance_sensor_t, type) }, \
         { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_distance_sensor_t, id) }, \
         { "orientation", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_distance_sensor_t, orientation) }, \
         { "covariance", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_distance_sensor_t, covariance) }, \
         } \
}
#endif

/**
 * @brief Pack a distance_sensor message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms Time since system boot
 * @param min_distance Minimum distance the sensor can measure in centimeters
 * @param max_distance Maximum distance the sensor can measure in centimeters
 * @param current_distance Current distance reading
 * @param type Type from MAV_DISTANCE_SENSOR enum.
 * @param id Onboard ID of the sensor
 * @param orientation Direction the sensor faces from MAV_SENSOR_ORIENTATION enum. downward-facing: ROTATION_PITCH_270, upward-facing: ROTATION_PITCH_90, backward-facing: ROTATION_PITCH_180, forward-facing: ROTATION_NONE, left-facing: ROTATION_YAW_90, right-facing: ROTATION_YAW_270
 * @param covariance Measurement covariance in centimeters, 0 for unknown / invalid readings
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_distance_sensor_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint16_t min_distance, uint16_t max_distance, uint16_t current_distance, uint8_t type, uint8_t id, uint8_t orientation, uint8_t covariance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DISTANCE_SENSOR_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint16_t(buf, 4, min_distance);
    _mav_put_uint16_t(buf, 6, max_distance);
    _mav_put_uint16_t(buf, 8, current_distance);
    _mav_put_uint8_t(buf, 10, type);
    _mav_put_uint8_t(buf, 11, id);
    _mav_put_uint8_t(buf, 12, orientation);
    _mav_put_uint8_t(buf, 13, covariance);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DISTANCE_SENSOR_LEN);
#else
    mavlink_distance_sensor_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.min_distance = min_distance;
    packet.max_distance = max_distance;
    packet.current_distance = current_distance;
    packet.type = type;
    packet.id = id;
    packet.orientation = orientation;
    packet.covariance = covariance;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DISTANCE_SENSOR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DISTANCE_SENSOR;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DISTANCE_SENSOR_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_CRC);
}

/**
 * @brief Pack a distance_sensor message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms Time since system boot
 * @param min_distance Minimum distance the sensor can measure in centimeters
 * @param max_distance Maximum distance the sensor can measure in centimeters
 * @param current_distance Current distance reading
 * @param type Type from MAV_DISTANCE_SENSOR enum.
 * @param id Onboard ID of the sensor
 * @param orientation Direction the sensor faces from MAV_SENSOR_ORIENTATION enum. downward-facing: ROTATION_PITCH_270, upward-facing: ROTATION_PITCH_90, backward-facing: ROTATION_PITCH_180, forward-facing: ROTATION_NONE, left-facing: ROTATION_YAW_90, right-facing: ROTATION_YAW_270
 * @param covariance Measurement covariance in centimeters, 0 for unknown / invalid readings
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_distance_sensor_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint16_t min_distance,uint16_t max_distance,uint16_t current_distance,uint8_t type,uint8_t id,uint8_t orientation,uint8_t covariance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DISTANCE_SENSOR_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint16_t(buf, 4, min_distance);
    _mav_put_uint16_t(buf, 6, max_distance);
    _mav_put_uint16_t(buf, 8, current_distance);
    _mav_put_uint8_t(buf, 10, type);
    _mav_put_uint8_t(buf, 11, id);
    _mav_put_uint8_t(buf, 12, orientation);
    _mav_put_uint8_t(buf, 13, covariance);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DISTANCE_SENSOR_LEN);
#else
    mavlink_distance_sensor_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.min_distance = min_distance;
    packet.max_distance = max_distance;
    packet.current_distance = current_distance;
    packet.type = type;
    packet.id = id;
    packet.orientation = orientation;
    packet.covariance = covariance;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DISTANCE_SENSOR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DISTANCE_SENSOR;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DISTANCE_SENSOR_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_CRC);
}

/**
 * @brief Encode a distance_sensor struct
 *