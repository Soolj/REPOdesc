#pragma once
// MESSAGE PARAM_SET PACKING

#define MAVLINK_MSG_ID_PARAM_SET 23

MAVPACKED(
typedef struct __mavlink_param_set_t {
 float param_value; /*< Onboard parameter value*/
 uint8_t t