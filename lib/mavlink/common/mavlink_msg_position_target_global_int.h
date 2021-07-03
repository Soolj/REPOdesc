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
#define MAVLINK_MESSAGE_INFO_POSITION_TARGET_GLOBAL_INT { \
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
#endif

/**
 * @brief Pack a position_target_global_int message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms Timestamp in milliseconds since system boot. The rationale for the timestamp in the setpoint is to allow the system to compensate for the transport delay of the setpoint. This allows the system to compensate processing latency.
 * @param coordinate_frame Valid options are: MAV_FRAME_GLOBAL_INT = 5, MAV_FRAME_GLOBAL_RELATIVE_ALT_INT = 6, MAV_FRAME_GLOBAL_TERRAIN_ALT_INT = 11
 * @param type_mask Bitmask to indicate which dimensions should be ignored by the vehicle: a value of 0b0000000000000000 or 0b0000001000000000 indicates that none of the setpoint dimensions should be ignored. If bit 10 is set the floats afx afy afz should be interpreted as force instead of acceleration. Mapping: bit 1: x, bit 2: y, bit 3: z, bit 4: vx, bit 5: vy, bit 6: vz, bit 7: ax, bit 8: ay, bit 9: az, bit 10: is force setpoint, bit 11: yaw, bit 12: yaw rate
 * @param lat_int X Position in WGS84 frame in 1e7 * degrees
 * @param lon_int Y Position in WGS84 frame in 1e7 * degrees
 * @param alt Altitude in meters in AMSL altitude, not WGS84 if absolute or relative, above terrain if GLOBAL_TERRAIN_ALT_INT
 * @param vx X velocity in NED frame in meter / s
 * @param vy Y velocity in NED frame in meter / s
 * @param vz Z velocity in NED frame in meter / s
 * @param afx X acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N
 * @param afy Y acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N
 * @param afz Z acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N
 * @param yaw yaw setpoint in rad
 * @param yaw_rate yaw rate setpoint in rad/s
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_position_target_global_int_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint8_t coordinate_frame, uint16_t type_mask, int32_t lat_int, int32_t lon_int, float alt, float vx, float vy, float vz, float afx, float afy, float afz, float yaw, float yaw_rate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_POSITION_TARGET_GLOBAL_INT_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_int32_t(buf, 4, lat_int);
    _mav_put_int32_t(buf, 8, lon_int);
    _mav_put_float(buf, 12, alt);
    _mav_put_float(buf, 16, vx);
    _mav_put_float(buf, 20, vy);
    _mav_put_float(buf, 24, vz);
    _mav_put_float(buf, 28, afx);
    _mav_put_float(buf, 32, afy);
    _mav_put_float(buf, 36, afz);
    _mav_put_float(buf, 40, yaw);
    _mav_put_float(buf, 44, yaw_rate);
    _mav_put_uint16_t(buf, 48, type_mask);
    _mav_put_uint8_t(buf, 50, coordinate_frame);

     