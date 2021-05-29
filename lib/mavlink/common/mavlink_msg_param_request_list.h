#pragma once
// MESSAGE PARAM_REQUEST_LIST PACKING

#define MAVLINK_MSG_ID_PARAM_REQUEST_LIST 21

MAVPACKED(
typedef struct __mavlink_param_request_list_t {
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
}) mavlink_param_request_list_t;

#define MAVLINK_MSG_ID_PARAM_REQUEST_LIST_LEN 2
#define MAVLINK_MSG_ID_PARAM_REQUEST_LIST_MIN_LEN 2
#define MAVLINK_MSG_ID_21_LEN 2
#define MAVLINK_MSG_ID_21_MIN_LEN 2

#define MAVLINK_MSG_ID_PARAM_REQUEST_LIST_CRC 159
#define MAVLINK_MSG_ID_21_CRC 159



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PARAM_REQUEST_LIST { \
    21, \
    "PARAM_REQUEST_LIST", \
    2, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_param_request_list_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_param_request_list_t, target_component) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PARAM_REQUEST_LIST { \
    "PARAM_REQUEST_LIST", \
    2, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_param_request_list_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_param_request_list_t, target_component) }, \
         } \
}
#endif

/**
 * @brief Pack a param_request_list message
 