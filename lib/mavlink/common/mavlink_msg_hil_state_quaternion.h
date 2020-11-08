#pragma once
// MESSAGE HIL_STATE_QUATERNION PACKING

#define MAVLINK_MSG_ID_HIL_STATE_QUATERNION 115

MAVPACKED(
typedef struct __mavlink_hil_state_quaternion_t {
 uint64_t time_usec; /*< Timestamp (microseconds since UNIX epoch or microseconds since system boot)*/
 float attitude_quaternion[4]; /*< Vehicle attitude expressed as normalized quaternion in w, x, y, z order 