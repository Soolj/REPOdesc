#pragma once
// MESSAGE MISSION_WRITE_PARTIAL_LIST PACKING

#define MAVLINK_MSG_ID_MISSION_WRITE_PARTIAL_LIST 38

MAVPACKED(
typedef struct __mavlink_mission_write_partial_list_t {
 int16_t start_index; /*< Start index, 0 by default and smaller / equal to the largest index of the current onboard list.*/
 int16_t end_index; /*< End index, equal or greater than start index.*/
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 uint8_t mission_type; /*< Mission type, see MAV_MISSION_TYPE*/
}) mavlink_mission_write_partial_list_t;

#define MAVLINK_MSG_ID_MISSION_WRITE_PARTIAL_LIST_LEN 7
#define MAVLINK_MSG_ID_MISSION_WRITE_PARTIAL_LIST_MIN_LEN 6
#define MAVLINK_MSG_ID_38_LEN 7
#define MAVLINK_MSG_ID_38_MIN_LEN 6

#define MAVLINK_MSG_ID_MISSION_WRITE_PARTIAL_LIST_CRC 9
#define MAVLINK_MSG_ID_38_CRC 9



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MISSION_WRITE_PARTIAL_LIST { \
    38, \
    "MISSION_WRITE_PARTIAL_LIST", \
    5, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_mission_write_partial_list_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_mission_write_partial_list_t, target_component) }, \
         { "start_index", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_mission_write_partial_list_t, start_index) }, \
         { "end_index", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_mission_write_partial_list_t, end_index) }, \
         { "mission_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_mission_write_partial_list_t, mission_type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MISSION_WRITE_PARTIAL_LIST { \
    "MISSION_WRITE_PARTIAL_LIST", \
    5, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_mission_write_partial_list_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_mission_write_partial_list_t, target_component) }, \
         { "start_index", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_mission_write_partial_list_t, start_index) }, \
         { "end_in