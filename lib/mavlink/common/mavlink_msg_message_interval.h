#pragma once
// MESSAGE MESSAGE_INTERVAL PACKING

#define MAVLINK_MSG_ID_MESSAGE_INTERVAL 244

MAVPACKED(
typedef struct __mavlink_message_interval_t {
 int32_t interval_us; /*< The interval between two messages, in microseconds. A value of -1 indicates this stream is disabled, 0 indicates it is not available, > 0 indicates the in