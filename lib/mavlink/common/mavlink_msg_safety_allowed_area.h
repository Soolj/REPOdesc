
#pragma once
// MESSAGE SAFETY_ALLOWED_AREA PACKING

#define MAVLINK_MSG_ID_SAFETY_ALLOWED_AREA 55

MAVPACKED(
typedef struct __mavlink_safety_allowed_area_t {
 float p1x; /*< x position 1 / Latitude 1*/
 float p1y; /*< y position 1 / Longitude 1*/
 float p1z; /*< z position 1 / Altitude 1*/
 float p2x; /*< x position 2 / Latitude 2*/
 float p2y; /*< y position 2 / Longitude 2*/
 float p2z; /*< z position 2 / Altitude 2*/
 uint8_t frame; /*< Coordinate frame, as defined by MAV_FRAME enum in mavlink_types.h. Can be either global, GPS, right-handed with Z axis up or local, right handed, Z axis down.*/
}) mavlink_safety_allowed_area_t;

#define MAVLINK_MSG_ID_SAFETY_ALLOWED_AREA_LEN 25
#define MAVLINK_MSG_ID_SAFETY_ALLOWED_AREA_MIN_LEN 25
#define MAVLINK_MSG_ID_55_LEN 25
#define MAVLINK_MSG_ID_55_MIN_LEN 25

#define MAVLINK_MSG_ID_SAFETY_ALLOWED_AREA_CRC 3
#define MAVLINK_MSG_ID_55_CRC 3



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SAFETY_ALLOWED_AREA { \
    55, \
    "SAFETY_ALLOWED_AREA", \
    7, \
    {  { "frame", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_safety_allowed_area_t, frame) }, \
         { "p1x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_safety_allowed_area_t, p1x) }, \