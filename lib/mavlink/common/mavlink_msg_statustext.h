#pragma once
// MESSAGE STATUSTEXT PACKING

#define MAVLINK_MSG_ID_STATUSTEXT 253

MAVPACKED(
typedef struct __mavlink_statustext_t {
 uint8_t severity; /*< Severity of status. Relies on the definitions within RFC-5424. See enum MAV_SEVERITY.*/
 char text[50]; /*< Status text message, without null termination character*/
}) mavlink_statustext_t;

#define MAVLINK_MSG_ID_STATUSTEXT_LEN 51
#define MAVLINK_MSG_ID_STATUSTEXT_MIN_LEN 51
#define MAVLINK_MSG_ID_253_LEN 51
#define MAVLINK_MSG_ID_253_MIN_LEN 51

#define MAV