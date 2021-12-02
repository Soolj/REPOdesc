#pragma once
// MESSAGE VFR_HUD PACKING

#define MAVLINK_MSG_ID_VFR_HUD 74

MAVPACKED(
typedef struct __mavlink_vfr_hud_t {
 float airspeed; /*< Current airspeed in m/s*/
 float groundspeed; /*< Current ground speed in m/s*/
 float alt; /*< Current altitude (MSL), in meters*/
 float climb; /*< Current climb rate in meters/second*/
 int16_t heading; /*< Current heading in degrees, in compass units (0..360, 0=north)*/
 uint16_t throttle; /*< Current throttle setting in integer percent, 0 to 100*/
}) mavlink_vfr_hud_t;

#define MAVLINK_MSG_ID_VFR_HUD_LEN 20
#define MAVLINK_MSG_ID_VFR_HUD_MIN_LEN 20
#define MAVLINK_MSG_ID_74_LEN 20
#define MAVLINK_MSG_ID_74_MIN_LEN 20

#define MAVLINK_MSG_ID_VFR_HUD_CRC 20
#define MAVLINK_MSG_ID_74_CRC 20



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VFR_HUD { \
    74, \
    "VFR_HUD", \
    6, \
    {  { "airspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_vfr_hud_t, airspeed) }, \
         { "groundspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_vfr_hud_t, groundspeed) }, \
         { "heading", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_vfr_hud_t, heading) }, \
         { "throttle", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_vfr_hud_t, throttle) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_vfr_hud_t, alt) }, \
         { "climb", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_vfr_hud_t, climb) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VFR_HUD { \
    "VFR_HUD", \
    6, \
    {  { "airspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_vfr_hud_t, airspeed) }, \
         { "groundspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_vfr_hud_t, groundspeed) }, \
         { "heading", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_vfr_hud_t, heading) }, \
         { "throttle", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_vfr_hud_t, throttle) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_vfr_hud_t, alt)