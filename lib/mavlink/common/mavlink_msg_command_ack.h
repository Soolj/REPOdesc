
#pragma once
// MESSAGE COMMAND_ACK PACKING

#define MAVLINK_MSG_ID_COMMAND_ACK 77

MAVPACKED(
typedef struct __mavlink_command_ack_t {
 uint16_t command; /*< Command ID, as defined by MAV_CMD enum.*/
 uint8_t result; /*< See MAV_RESULT enum*/
 uint8_t progress; /*< WIP: Also used as result_param1, it can be set with a enum containing the errors reasons of why the command was denied or the progress percentage or 255 if unknown the progress when result is MAV_RESULT_IN_PROGRESS.*/
 int32_t result_param2; /*< WIP: Additional parameter of the result, example: which parameter of MAV_CMD_NAV_WAYPOINT caused it to be denied.*/
 uint8_t target_system; /*< WIP: System which requested the command to be executed*/
 uint8_t target_component; /*< WIP: Component which requested the command to be executed*/
}) mavlink_command_ack_t;