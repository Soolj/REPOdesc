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
 uint16_t throttle; /*< Current th