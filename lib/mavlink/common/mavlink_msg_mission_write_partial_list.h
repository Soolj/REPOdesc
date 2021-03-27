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

#define MAVLI