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
