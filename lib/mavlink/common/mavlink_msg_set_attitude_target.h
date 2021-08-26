#pragma once
// MESSAGE SET_ATTITUDE_TARGET PACKING

#define MAVLINK_MSG_ID_SET_ATTITUDE_TARGET 82

MAVPACKED(
typedef struct __mavlink_set_attitude_target_t {
 uint32_t time_boot_ms; /*< Timestamp in milliseconds since system boot*/
 float q[4]; /*< Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)*/
 float body_roll_rate; /*< Body roll rate in radians per second*/
 float body_pitch_rate; /*< Body pitch rate in radians per second*/
 float body_yaw_rate; /*< Body yaw rate in radians per second*/
 float thrust; /*< Collective thrust, normalized to 0 .. 1 (-1 .. 1 for vehicles capable of reverse trust)*/
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 uint8_t type_mask; /*< Mappings: If any of these bits are set, the corresponding input should be ignored: bit 1: body roll rate, bit 2: body pitch rate, bit 3: body yaw rate. bit 4-bit 6: reserved, bit 7: throttle, bit 8: attitude*/
}) mavlink_set_att