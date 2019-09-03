#pragma once
// MESSAGE ATT_POS_MOCAP PACKING

#define MAVLINK_MSG_ID_ATT_POS_MOCAP 138

MAVPACKED(
typedef struct __mavlink_att_pos_mocap_t {
 uint64_t time_usec; /*< Timestamp (micros since boot or Unix epoch)*/
 float q[4]; /*< Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)*/
 float x; /*< X position in meters (NED)*/
 float y; /*< Y position in meters (NED)*/
 float z; /*< Z position in meters (NED)*/
}) mavlink_att_pos_mocap_t;

#define MAVLINK_MSG_ID_ATT_POS_MOCAP_LEN 36
#define MAVLINK_MSG_ID_ATT_POS_MOCAP_MIN_LEN 36
#define MAVLINK_MSG_ID_138_LEN 36
#define MAVLINK_MSG_ID_138_MIN_LEN 36

#define MAVLINK_MSG_ID_ATT_POS_MOCAP_CRC 109
#define MAVLINK_MSG_ID_138_CRC 109

#define MAVLINK_MSG_ATT_POS_MOCAP_FIELD_Q_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ATT_POS_MOCAP { \
    138, \
    "ATT_POS_MOCAP", \
    5, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_att_pos_mocap_t, time_usec) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 8, offsetof(mavlink_att_pos_mocap_t, q) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_att_pos_mocap_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_att_pos_mocap_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_att_pos_mocap_t, z) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ATT_POS_MOCAP { \
    "ATT_POS_MOCAP", \
    5, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_att_pos_mocap_t, time_usec) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 8, offsetof(mavlink_att_pos_mocap_t, q) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_att_pos_mocap_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_att_pos_mocap_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_att_pos_mocap_t, z) }, \
         } \
}
#endif

/**
 * @brief Pack a att_pos_mocap message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param q Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 * @param x X position in meters (NED)
 * @param y Y position in meters (NED)
 * @param z Z position in meters (NED)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_att_pos_mocap_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, const float *q, float x, float y, float z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ATT_POS_MOCAP_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 24, x);
    _mav_put_float(buf, 28, y);
    _mav_put_float(buf, 32, z);
    _mav_put_float_array(buf, 8, q, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ATT_POS_MOCAP_LEN);
#else
    mavlink_att_pos_mocap_t packet;
    packet.time_usec = time_usec;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    mav_array_memcpy(packet.q, q, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ATT_POS_MOCAP_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ATT_POS_MOCAP;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ATT_POS_MOCAP_MIN_LEN, MAVLINK_MSG_ID_ATT_POS_MOCAP_LEN, MAVLINK_MSG_ID_ATT_POS_MOCAP_CRC);
}

/**
 * @brief Pack a att_pos_mocap message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param q Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 * @param x X position in meters (NED)
 * @param y Y position in meters (NED)
 * @param z Z position in meters (NED)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_att_pos_mocap_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,const float *q,float x,float y,float z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ATT_POS_MOCAP_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 24, x);
    _mav_put_float(buf, 28, y);
    _mav_put_float(buf, 32, z);
    _mav_put_float_array(buf, 8, q, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ATT_POS_MOCAP_LEN);
#else
    mavlink_att_pos_mocap_t packet;
    packet.time_usec = time_usec;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    mav_array_memcpy(packet.q, q, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ATT_POS_MOCAP_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ATT_POS_MOCAP;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ATT_POS_MOCAP_MIN_LEN, MAVLINK_MSG_ID_ATT_POS_MOCAP_LEN, MAVLINK_MSG_ID_ATT_POS_MOCAP_CRC);
}

/**
 * @brief Encode a att_pos_mocap struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param att_pos_mocap C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_att_pos_mocap_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_att_pos_mocap_t* att_pos_mocap)
{
    return mavlink_msg_att_pos_mocap_pack(system_id, component_id, msg, att_pos_mocap->time_usec, att_pos_mocap->