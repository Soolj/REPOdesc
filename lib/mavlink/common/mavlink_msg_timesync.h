#pragma once
// MESSAGE TIMESYNC PACKING

#define MAVLINK_MSG_ID_TIMESYNC 111

MAVPACKED(
typedef struct __mavlink_timesync_t {
 int64_t tc1; /*< Time sync timestamp 1*/
 int64_t ts1; /*< Time sync timestamp 2*/
}) mavlink_timesync_t;

#define MAVLINK_MSG_ID_TIMESYNC_LEN 16
#define MAVLINK_MSG_ID_TIMESYNC_MIN_LEN 16
#define MAVLINK_MSG_ID_111_LEN 16
#define MAVLINK_MSG_ID_111_MIN_LEN 16

#define MAVLINK_MSG_ID_TIMESYNC_CRC 34
#define MAVLINK_MSG_ID_111_CRC 34



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TIMESYNC { \
    111, \
    "TIMESYNC", \
    2, \
    {  { "tc1", NULL, MAVLINK_TYPE_INT64_T, 0, 0, offsetof(mavlink_timesync_t, tc1) }, \
         { "ts1", NULL, MAVLINK_TYPE_INT64_T, 0, 8, offsetof(mavlink_timesync_t, ts1) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TIMESYNC { \
    "TIMESYNC", \
    2, \
    {  { "tc1", NULL, MAVLINK_TYPE_INT64_T, 0, 0, offsetof(mavlink_timesync_t, tc1) }, \
         { "ts1", NULL, MAVLINK_TYPE_INT64_T, 0, 8, offsetof(mavlink_timesync_t, ts1) }, \
         } \
}
#endif

/**
 * @brief Pack a timesync message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param tc1 Time sync timestamp 1
 * @param ts1 Time sync timestamp 2
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_timesync_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int64_t tc1, int64_t ts1)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TIMESYNC_LEN];
    _mav_put_int64_t(buf, 0, tc1);
    _mav_put_int64_t(buf, 8, ts1);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TIMESYNC_LEN);
#else
    mavlink_timesync_t packet;
    packet.tc1 = tc1;
    packet.ts1 = ts1;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TIMESYNC_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TIMESYNC;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TIMESYNC_MIN_LEN, MAVLINK_MSG_ID_TIMESYNC_LEN, MAVLINK_MSG_ID_TIMESYNC_CRC);
}

/**
 * @brief Pack a timesync message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tc1 Time sync timestamp 1
 * @param ts1 Time sync timestamp 2
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_timesync_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int64_t tc1,int64_t ts1)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TIMESYNC_LEN];
    _mav_put_int64_t(buf, 0, tc1);
    _mav_put_int64_t(buf, 8, ts1);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TIMESYNC_LEN);
#else
    mavlink_timesync_t packet;
    packet.tc1 = tc1;
 