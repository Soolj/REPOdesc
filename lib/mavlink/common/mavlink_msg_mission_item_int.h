
#pragma once
// MESSAGE MISSION_ITEM_INT PACKING

#define MAVLINK_MSG_ID_MISSION_ITEM_INT 73

MAVPACKED(
typedef struct __mavlink_mission_item_int_t {
 float param1; /*< PARAM1, see MAV_CMD enum*/
 float param2; /*< PARAM2, see MAV_CMD enum*/
 float param3; /*< PARAM3, see MAV_CMD enum*/
 float param4; /*< PARAM4, see MAV_CMD enum*/
 int32_t x; /*< PARAM5 / local: x position in meters * 1e4, global: latitude in degrees * 10^7*/
 int32_t y; /*< PARAM6 / y position: local: x position in meters * 1e4, global: longitude in degrees *10^7*/
 float z; /*< PARAM7 / z position: global: altitude in meters (relative or absolute, depending on frame.*/
 uint16_t seq; /*< Waypoint ID (sequence number). Starts at zero. Increases monotonically for each waypoint, no gaps in the sequence (0,1,2,3,4).*/
 uint16_t command; /*< The scheduled action for the waypoint. see MAV_CMD in common.xml MAVLink specs*/
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 uint8_t frame; /*< The coordinate system of the waypoint. see MAV_FRAME in mavlink_types.h*/
 uint8_t current; /*< false:0, true:1*/
 uint8_t autocontinue; /*< autocontinue to next wp*/
 uint8_t mission_type; /*< Mission type, see MAV_MISSION_TYPE*/
}) mavlink_mission_item_int_t;

#define MAVLINK_MSG_ID_MISSION_ITEM_INT_LEN 38
#define MAVLINK_MSG_ID_MISSION_ITEM_INT_MIN_LEN 37
#define MAVLINK_MSG_ID_73_LEN 38
#define MAVLINK_MSG_ID_73_MIN_LEN 37

#define MAVLINK_MSG_ID_MISSION_ITEM_INT_CRC 38
#define MAVLINK_MSG_ID_73_CRC 38



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MISSION_ITEM_INT { \
    73, \
    "MISSION_ITEM_INT", \
    15, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_mission_item_int_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_mission_item_int_t, target_component) }, \
         { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_mission_item_int_t, seq) }, \
         { "frame", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_mission_item_int_t, frame) }, \
         { "command", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_mission_item_int_t, command) }, \
         { "current", NULL, MAVLINK_TYPE_UINT8_T, 0, 35, offsetof(mavlink_mission_item_int_t, current) }, \
         { "autocontinue", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_mission_item_int_t, autocontinue) }, \
         { "param1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_mission_item_int_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_mission_item_int_t, param2) }, \
         { "param3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_mission_item_int_t, param3) }, \
         { "param4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_mission_item_int_t, param4) }, \
         { "x", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_mission_item_int_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_mission_item_int_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_mission_item_int_t, z) }, \
         { "mission_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 37, offsetof(mavlink_mission_item_int_t, mission_type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MISSION_ITEM_INT { \
    "MISSION_ITEM_INT", \
    15, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_mission_item_int_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_mission_item_int_t, target_component) }, \
         { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_mission_item_int_t, seq) }, \
         { "frame", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_mission_item_int_t, frame) }, \
         { "command", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_mission_item_int_t, command) }, \
         { "current", NULL, MAVLINK_TYPE_UINT8_T, 0, 35, offsetof(mavlink_mission_item_int_t, current) }, \
         { "autocontinue", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_mission_item_int_t, autocontinue) }, \
         { "param1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_mission_item_int_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_mission_item_int_t, param2) }, \
         { "param3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_mission_item_int_t, param3) }, \
         { "param4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_mission_item_int_t, param4) }, \
         { "x", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_mission_item_int_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_mission_item_int_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_mission_item_int_t, z) }, \
         { "mission_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 37, offsetof(mavlink_mission_item_int_t, mission_type) }, \
         } \