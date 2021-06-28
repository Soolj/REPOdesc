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
 float vz; /*< Z velocity in NED frame in meter / s*/
 float afx; /*< X acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N*/
 float afy; /*< Y acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N*/
 float afz; /*< Z acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N*/
 float yaw; /*< yaw setpoint in rad*/
 float yaw_rate; /*< yaw rate setpoint in rad/s*/
 uint16_t type_mask; /*< Bitmask to indicate which dimensions should be ignored by the vehicle: a value of 0b0000000000000000 or 0b0000001000000000 indicates that none of the setpoint dimensions should be ignored. If bit 10 is set the floats afx afy afz should be interpreted as force instead of acceleration. Mapping: bit 1: x, bit 2: y, bit 3: z, bit 4: vx, bit 5: vy, bit 6: vz, bit 7: ax, bit 8: ay, bit 9: az, bit 10: is force setpoint, bit 11: yaw, bit 12: yaw rate*/
 uint8_t coordinate_frame; /*< Valid options are: MAV_FRAME_GLOBAL_INT = 5, MAV_FRAME_GLOBAL_RELATIVE_ALT_INT = 6, MAV_FRAME_GLOBAL_TERRAIN_ALT_INT = 11*/
}) mavlink_position_target_global_int_t;

#define MAVLINK_MSG_ID_POSITION_TARGET_GLOBAL_INT_LEN 51
#define MAVLINK_MSG_ID_POSITION_TARGET_GLOBAL_INT_MIN_LEN 51
#define MAVLINK_MSG_ID_87_LEN 51
#define MAVLINK_MSG_ID_87_MIN_LEN 51

#define MAVLINK_MSG_ID_POSITION_TARGET_GLOBAL_INT_CRC 150
#define MAVLINK_MSG_ID_87_CRC 150



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_POSITION_TARGET_GLOBAL_INT { \
    87, \
    "POSITION_TARGET_GLOBAL_INT", \
    14, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_position_target_global_int_t, time_boot_ms) }, \
         { "coordinate_frame", NULL, MAVLINK_TYPE_UINT8_T, 0, 50, offsetof(mavlink_position_target_global_int_t, coordinate_frame) }, \
         { "type_mask", NULL, MAVLINK_TYPE_UINT16_T, 0, 48, offsetof(mavlink_position_target_global_int_t, type_mask) }, \
         { "lat_int", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_position_target_global_int_t, lat_int) }, \
         { "lon_int", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_position_target_global_int_t, lon_int) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_position_target_global_int_t, alt) }, \
         { "vx", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_position_target_global_int_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_position_target_global_int_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_position_target_global_int_t, vz) }, \
         { "afx", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_position_target_global_int_t, afx) }, \
         { "afy", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_position_target_global_int_t, afy) }, \
         { "afz", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_position_target_global_int_t, afz) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_position_target_global_int_t, yaw) }, \
         { "yaw_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_position_target_global_int_t, yaw_rate) }, \
         } \
}
#else
#de