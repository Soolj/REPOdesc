#pragma once
// MESSAGE VICON_POSITION_ESTIMATE PACKING

#define MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE 104

MAVPACKED(
typedef struct __mavlink_vicon_position_estimate_t {
 uint64_t usec; /*< Timestamp (microseconds, synced to UNIX time or since system boot)*/
 float x; /*< Global X position*/
 float y; /*< Global Y position*/
 float z; /*< Global Z position*/
 float roll; /*< Roll angle in rad*/
 float pitch; /*< Pitch angle in rad*/
 float yaw; /*< Yaw angle in rad*/
}) mavlink_vicon_position_estimate_t;

#define MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE_LEN 32
#define MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE_MIN_LEN 32
#define MAVLINK_MSG_ID_104_LEN 32
#define MAVLINK_MSG_ID_104_MIN_LEN 32

#define MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE_CRC 56
#define MAVLINK_MSG_ID_104_CRC 56



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VICON_POSITION_ESTIMATE { \
    104, \
    "VICON_POSITION_ESTIMATE", \
    7, \
    {  { "usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_vicon_position_estimate_t, usec) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_vicon_position_estimate_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_vicon_position_estimate_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_vicon_position_estimate_t, z) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_vicon_position_estimate_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_vicon_position_estimate_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_vicon_position_estimate_t, yaw) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VICON_POSITION_ESTIMATE { \
    "VICON_POSITION_ESTIMATE", \
    7, \
    {  { "usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_vicon_position_estimate_t, usec) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_vicon_position_estimate_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_vicon_position_estimate_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_vicon_position_estimate_t, z) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_vicon_position_estimate_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_vicon_position_estimate_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_vicon_position_estimate_t, yaw) }, \
         } \
}
#endif

/**
 * @brief Pack a vicon_position_estimate message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param usec Timestamp (microseconds, synced to UNIX time or since system boot)
 * @param x Global X position
 * @param y Global Y position
 * @param z Global Z position
 * @param roll Roll angle in rad
 * @param pitch Pitch angle in rad
 * @param yaw Yaw angle in rad
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vicon_position_estimate_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t usec, float x, float y, float z, float roll, float pitch, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE_LEN];
    _mav_put_uint64_t(buf, 0, usec);
    _mav_put_float(buf, 8, x);
    _mav_put_float(buf, 12, y);
    _mav_put_float(buf, 16, z);
    _mav_put_float(buf, 20, roll);
    _mav_put_float(buf, 24, pitch);
    _mav_put_float(buf, 28, yaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE_LEN);
#else
    mavlink_vicon_position_estimate_t packet;
    packet.usec = usec;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE_MIN_LEN, MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE_LEN, MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE_CRC);
}

/**
 * @brief Pack a vicon_position_estimate message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param usec Timestamp (microseconds, synced to UNIX time or since system boot)
 * @param x Global X position
 * @param y Global Y position
 * @param z Global Z position
 * @param roll Roll angle in rad
 * @param pitch Pitch angle in rad
 * @param yaw Yaw angle in rad
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vicon_position_estimate_pack_chan(uint8_t system_id, uint8_t com