#pragma once
// MESSAGE ATTITUDE_TARGET PACKING

#define MAVLINK_MSG_ID_ATTITUDE_TARGET 83

MAVPACKED(
typedef struct __mavlink_attitude_target_t {
 uint32_t time_boot_ms; /*< Timestamp in milliseconds since system boot*/
 float q[4]; /*< Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)*/
 float body_roll_rate; /*< Body roll 