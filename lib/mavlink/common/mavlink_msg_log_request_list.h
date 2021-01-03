#pragma once
// MESSAGE LOG_REQUEST_LIST PACKING

#define MAVLINK_MSG_ID_LOG_REQUEST_LIST 117

MAVPACKED(
typedef struct __mavlink_log_request_list_t {
 uint16_t start; /*< First log id (0 for first available)*/
 uint16_t end; /*< Last log id (0xffff for last available)*/
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
}) mavlink_log_request_list_t;

#define MAVLINK_MSG_ID_LOG_REQUEST_LIST_LEN 6
#define MAVLINK_MSG_ID_LOG_REQUEST_LIST_MIN_LEN 6
#define MAVLINK_MSG_ID_117_LEN 6
#define MAVLINK_MSG_ID_117_MIN_LEN 6

#define MAVLINK_M