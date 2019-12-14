#pragma once
// MESSAGE DEBUG PACKING

#define MAVLINK_MSG_ID_DEBUG 254

MAVPACKED(
typedef struct __mavlink_debug_t {
 uint32_t time_boot_ms; /*< Timestamp (milliseconds since system boot)*/
 float value; /*< DEBUG value*/
 uint8_t ind; /*< index of debug variable*/
}) mavlink_debug_t;

#define MAVLINK_MSG_ID_DE