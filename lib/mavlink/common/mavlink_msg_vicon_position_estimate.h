#pragma once
// MESSAGE VICON_POSITION_ESTIMATE PACKING

#define MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE 104

MAVPACKED(
typedef struct __mavlink_vicon_position_estimate_t {
 uint64_t usec; /*< Timestamp (microseconds, synced to UNIX time or since system boot)*/
 float x; /*< Global X position*/
 float y; /*< Global Y position*/
 float z; /*< Global Z p