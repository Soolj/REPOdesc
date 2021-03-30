#pragma once
// MESSAGE MISSION_WRITE_PARTIAL_LIST PACKING

#define MAVLINK_MSG_ID_MISSION_WRITE_PARTIAL_LIST 38

MAVPACKED(
typedef struct __mavlink_mission_write_partial_list_t {
 int16_t start_index; /*< Start index, 0 by default and smaller / equal to the largest index of the current onboard list.*/
 int16_t end_index; /*< End index, equal or greater than start index.*/
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 uint8_t mission_type; /*< Mission type, see MAV_MISSION_TYPE*/
}) mavlink_mission_write_partial_list_t;

#define MAVLINK_MSG_ID_MISSION_WRITE_PARTIAL_LIST_LEN 7
#define MAVLINK_MSG_ID_MISSION_WRITE_PARTIAL_LIST_MIN_LEN 6
#define MAVLINK_MSG_ID_38_LEN 7
#define MAVLINK_MSG_ID_38_MIN_LEN 6

#define MAVLINK_MSG_ID_MISSION_WRITE_PARTIAL_LIST_CRC 9
#define MAVLINK_MSG_ID_38_CRC 9



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MISSION_WRITE_PARTIAL_LIST { \
    38, \
    "MISSION_WRITE_PARTIAL_LIST", \
    5, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_mission_write_partial_list_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_mission_write_partial_list_t, target_component) }, \
         { "start_index", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_mission_write_partial_list_t, start_index) }, \
         { "end_index", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_mission_write_partial_list_t, end_index) }, \
         { "mission_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_mission_write_partial_list_t, mission_type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MISSION_WRITE_PARTIAL_LIST { \
    "MISSION_WRITE_PARTIAL_LIST", \
    5, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_mission_write_partial_list_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_mission_write_partial_list_t, target_component) }, \
         { "start_index", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_mission_write_partial_list_t, start_index) }, \
         { "end_index", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_mission_write_partial_list_t, end_index) }, \
         { "mission_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_mission_write_partial_list_t, mission_type) }, \
         } \
}
#endif

/**
 * @brief Pack a mission_write_partial_list message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param start_index Start index, 0 by default and smaller / equal to the largest index of the current onboard list.
 * @param end_index End index, equal or greater than start index.
 * @param mission_type Mission type, see MAV_MISSION_TYPE
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_write_partial_list_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, int16_t start_index, int16_t end_index, uint8_t mission_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MISSION_WRITE_PARTIAL_LIST_LEN];
    _mav_put_int16_t(buf, 0, start_index);
    _mav_put_int16_t(buf, 2, end_index);
    _mav_put_uint8_t(buf, 4, target_system);
    _mav_put_uint8_t(buf, 5, target_component);
    _mav_put_uint8_t(buf, 6, mission_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MISSION_WRITE_PARTIAL_LIST_LEN);
#e