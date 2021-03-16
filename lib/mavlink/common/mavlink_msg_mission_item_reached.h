#pragma once
// MESSAGE MISSION_ITEM_REACHED PACKING

#define MAVLINK_MSG_ID_MISSION_ITEM_REACHED 46

MAVPACKED(
typedef struct __mavlink_mission_item_reached_t {
 uint16_t seq; /*< Sequence*/
}) mavlink_mission_item_reached_t;

#define MAVLINK_MSG_ID_MISSION_ITEM_REACHED_LEN 2
#define MAVLINK_MSG_ID_MISSION_ITEM_REACHED_MIN_LEN 2
#define MAVLINK_MSG_ID_46_LEN 2
#define MAVLINK_MSG_ID_46_MIN_LEN 2

#define MAVLINK_MSG_ID_MISSION_ITEM_REACHED_CRC 11
#define MAVLINK_MSG_ID_46_CRC 11



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MISSION_ITEM_REACHED { \
    46, \
    "MISSION_ITEM_REACHED", \
    1, \
    {  { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_mission_item_reached_t, seq) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MISSION_ITEM_REACHED { \
    "MISSION_ITEM_REACHED", \
    1, \
    {  { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_mission_item_reached_t, seq) }, \
         } \
}
#endif

/**
 * @brief Pack a mission_item_reached message
 * @param system_id ID of this system
 * @param c