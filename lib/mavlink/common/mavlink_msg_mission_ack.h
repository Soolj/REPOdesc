#pragma once
// MESSAGE MISSION_ACK PACKING

#define MAVLINK_MSG_ID_MISSION_ACK 47

MAVPACKED(
typedef struct __mavlink_mission_ack_t {
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 uint8_t type; /*< See MAV_MISSION_RESULT enum*/
 uint8_t mission_type; /*< Mission type, see MAV_MISSION_TYPE*/
}) mavlink_mission_ack_t;

#define MAVLINK_MSG_ID_MISSION_ACK_LEN 4
#define MAVLINK_MSG_ID_MISSION_ACK_MIN_LEN 3
#define MAVLINK_MSG_ID_47_LEN 4