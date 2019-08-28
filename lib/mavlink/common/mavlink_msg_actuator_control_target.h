#pragma once
// MESSAGE ACTUATOR_CONTROL_TARGET PACKING

#define MAVLINK_MSG_ID_ACTUATOR_CONTROL_TARGET 140

MAVPACKED(
typedef struct __mavlink_actuator_control_target_t {
 uint64_t time_usec; /*< Timestamp (micros since boot or Unix epoch)*/
 float controls[8]; /*< Actuator controls. Normed to -1..+1 where 0 is neutral position. Throttle for single rotation direction motors is 0..1, negative range for r