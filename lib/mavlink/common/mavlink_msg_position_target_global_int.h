#pragma once
// MESSAGE POSITION_TARGET_GLOBAL_INT PACKING

#define MAVLINK_MSG_ID_POSITION_TARGET_GLOBAL_INT 87

MAVPACKED(
typedef struct __mavlink_position_target_global_int_t {
 uint32_t time_boot_ms; /*< Timestamp in milliseconds since system boot. The rationale for the timestamp in the setpoint is to allow the system to compensate for the transport delay of the setpoint. This allows the system to compensate processing latency.*/
 int32_t lat_int; /*< X Position in WGS84 frame in 1e7 * degrees*/
 int32_t lon_int; /*< Y Position in WGS84 frame in 1e7 * degrees*/
 float alt; /*< Altitude in meters in AMSL altitude, not WGS84 if absolute or relative, above terrain if GLOBAL_TERRAIN_ALT_INT*/
 float vx; /*< X velocity in NED frame in meter / s*/
 float vy; /*< Y velocity in NED frame in meter / s*/
 float vz; /*< Z velocity in NED frame in mete