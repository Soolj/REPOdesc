
#pragma once
// MESSAGE VISION_SPEED_ESTIMATE PACKING

#define MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE 103

MAVPACKED(
typedef struct __mavlink_vision_speed_estimate_t {
 uint64_t usec; /*< Timestamp (microseconds, synced to UNIX time or since system boot)*/
 float x; /*< Global X speed*/
 float y; /*< Global Y speed*/
 float z; /*< Global Z speed*/
}) mavlink_vision_speed_estimate_t;

#define MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE_LEN 20
#define MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE_MIN_LEN 20
#define MAVLINK_MSG_ID_103_LEN 20
#define MAVLINK_MSG_ID_103_MIN_LEN 20

#define MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE_CRC 208
#define MAVLINK_MSG_ID_103_CRC 208



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VISION_SPEED_ESTIMATE { \
    103, \
    "VISION_SPEED_ESTIMATE", \
    4, \
    {  { "usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_vision_speed_estimate_t, usec) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_vision_speed_estimate_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_vision_speed_estimate_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_vision_speed_estimate_t, z) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VISION_SPEED_ESTIMATE { \
    "VISION_SPEED_ESTIMATE", \
    4, \
    {  { "usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_vision_speed_estimate_t, usec) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_vision_speed_estimate_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_vision_speed_estimate_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_vision_speed_estimate_t, z) }, \
         } \
}
#endif

/**
 * @brief Pack a vision_speed_estimate message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param usec Timestamp (microseconds, synced to UNIX time or since system boot)
 * @param x Global X speed
 * @param y Global Y speed
 * @param z Global Z speed
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vision_speed_estimate_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t usec, float x, float y, float z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE_LEN];
    _mav_put_uint64_t(buf, 0, usec);
    _mav_put_float(buf, 8, x);
    _mav_put_float(buf, 12, y);
    _mav_put_float(buf, 16, z);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE_LEN);
#else
    mavlink_vision_speed_estimate_t packet;
    packet.usec = usec;
    packet.x = x;
    packet.y = y;
    packet.z = z;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE_MIN_LEN, MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE_LEN, MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE_CRC);
}

/**
 * @brief Pack a vision_speed_estimate message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param usec Timestamp (microseconds, synced to UNIX time or since system boot)
 * @param x Global X speed
 * @param y Global Y speed
 * @param z Global Z speed
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vision_speed_estimate_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t usec,float x,float y,float z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE_LEN];
    _mav_put_uint64_t(buf, 0, usec);
    _mav_put_float(buf, 8, x);
    _mav_put_float(buf, 12, y);
    _mav_put_float(buf, 16, z);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE_LEN);
#else
    mavlink_vision_speed_estimate_t packet;
    packet.usec = usec;
    packet.x = x;
    packet.y = y;
    packet.z = z;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE;