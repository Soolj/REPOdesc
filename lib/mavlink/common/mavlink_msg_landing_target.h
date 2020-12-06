
#pragma once
// MESSAGE LANDING_TARGET PACKING

#define MAVLINK_MSG_ID_LANDING_TARGET 149

MAVPACKED(
typedef struct __mavlink_landing_target_t {
 uint64_t time_usec; /*< Timestamp (micros since boot or Unix epoch)*/
 float angle_x; /*< X-axis angular offset (in radians) of the target from the center of the image*/
 float angle_y; /*< Y-axis angular offset (in radians) of the target from the center of the image*/
 float distance; /*< Distance to the target from the vehicle in meters*/
 float size_x; /*< Size in radians of target along x-axis*/
 float size_y; /*< Size in radians of target along y-axis*/
 uint8_t target_num; /*< The ID of the target if multiple targets are present*/
 uint8_t frame; /*< MAV_FRAME enum specifying the whether the following feilds are earth-frame, body-frame, etc.*/
 float x; /*< X Position of the landing target on MAV_FRAME*/
 float y; /*< Y Position of the landing target on MAV_FRAME*/
 float z; /*< Z Position of the landing target on MAV_FRAME*/
 float q[4]; /*< Quaternion of landing target orientation (w, x, y, z order, zero-rotation is 1, 0, 0, 0)*/
 uint8_t type; /*< LANDING_TARGET_TYPE enum specifying the type of landing target*/
 uint8_t position_valid; /*< Boolean indicating known position (1) or default unkown position (0), for validation of positioning of the landing target*/
}) mavlink_landing_target_t;

#define MAVLINK_MSG_ID_LANDING_TARGET_LEN 60
#define MAVLINK_MSG_ID_LANDING_TARGET_MIN_LEN 30
#define MAVLINK_MSG_ID_149_LEN 60
#define MAVLINK_MSG_ID_149_MIN_LEN 30

#define MAVLINK_MSG_ID_LANDING_TARGET_CRC 200
#define MAVLINK_MSG_ID_149_CRC 200

#define MAVLINK_MSG_LANDING_TARGET_FIELD_Q_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LANDING_TARGET { \
    149, \
    "LANDING_TARGET", \
    14, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_landing_target_t, time_usec) }, \
         { "target_num", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_landing_target_t, target_num) }, \
         { "frame", NULL, MAVLINK_TYPE_UINT8_T, 0, 29, offsetof(mavlink_landing_target_t, frame) }, \
         { "angle_x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_landing_target_t, angle_x) }, \
         { "angle_y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_landing_target_t, angle_y) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_landing_target_t, distance) }, \
         { "size_x", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_landing_target_t, size_x) }, \
         { "size_y", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_landing_target_t, size_y) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 30, offsetof(mavlink_landing_target_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 34, offsetof(mavlink_landing_target_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 38, offsetof(mavlink_landing_target_t, z) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 42, offsetof(mavlink_landing_target_t, q) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 58, offsetof(mavlink_landing_target_t, type) }, \
         { "position_valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 59, offsetof(mavlink_landing_target_t, position_valid) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LANDING_TARGET { \
    "LANDING_TARGET", \
    14, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_landing_target_t, time_usec) }, \
         { "target_num", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_landing_target_t, target_num) }, \
         { "frame", NULL, MAVLINK_TYPE_UINT8_T, 0, 29, offsetof(mavlink_landing_target_t, frame) }, \
         { "angle_x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_landing_target_t, angle_x) }, \
         { "angle_y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_landing_target_t, angle_y) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_landing_target_t, distance) }, \
         { "size_x", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_landing_target_t, size_x) }, \
         { "size_y", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_landing_target_t, size_y) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 30, offsetof(mavlink_landing_target_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 34, offsetof(mavlink_landing_target_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 38, offsetof(mavlink_landing_target_t, z) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 42, offsetof(mavlink_landing_target_t, q) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 58, offsetof(mavlink_landing_target_t, type) }, \
         { "position_valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 59, offsetof(mavlink_landing_target_t, position_valid) }, \
         } \
}
#endif

/**
 * @brief Pack a landing_target message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param target_num The ID of the target if multiple targets are present
 * @param frame MAV_FRAME enum specifying the whether the following feilds are earth-frame, body-frame, etc.
 * @param angle_x X-axis angular offset (in radians) of the target from the center of the image
 * @param angle_y Y-axis angular offset (in radians) of the target from the center of the image
 * @param distance Distance to the target from the vehicle in meters
 * @param size_x Size in radians of target along x-axis
 * @param size_y Size in radians of target along y-axis
 * @param x X Position of the landing target on MAV_FRAME
 * @param y Y Position of the landing target on MAV_FRAME
 * @param z Z Position of the landing target on MAV_FRAME
 * @param q Quaternion of landing target orientation (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 * @param type LANDING_TARGET_TYPE enum specifying the type of landing target
 * @param position_valid Boolean indicating known position (1) or default unkown position (0), for validation of positioning of the landing target
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_landing_target_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint8_t target_num, uint8_t frame, float angle_x, float angle_y, float distance, float size_x, float size_y, float x, float y, float z, const float *q, uint8_t type, uint8_t position_valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LANDING_TARGET_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, angle_x);
    _mav_put_float(buf, 12, angle_y);
    _mav_put_float(buf, 16, distance);
    _mav_put_float(buf, 20, size_x);
    _mav_put_float(buf, 24, size_y);
    _mav_put_uint8_t(buf, 28, target_num);
    _mav_put_uint8_t(buf, 29, frame);
    _mav_put_float(buf, 30, x);
    _mav_put_float(buf, 34, y);
    _mav_put_float(buf, 38, z);
    _mav_put_uint8_t(buf, 58, type);
    _mav_put_uint8_t(buf, 59, position_valid);
    _mav_put_float_array(buf, 42, q, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LANDING_TARGET_LEN);
#else
    mavlink_landing_target_t packet;
    packet.time_usec = time_usec;
    packet.angle_x = angle_x;
    packet.angle_y = angle_y;
    packet.distance = distance;
    packet.size_x = size_x;
    packet.size_y = size_y;
    packet.target_num = target_num;
    packet.frame = frame;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.type = type;
    packet.position_valid = position_valid;
    mav_array_memcpy(packet.q, q, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LANDING_TARGET_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LANDING_TARGET;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LANDING_TARGET_MIN_LEN, MAVLINK_MSG_ID_LANDING_TARGET_LEN, MAVLINK_MSG_ID_LANDING_TARGET_CRC);
}

/**
 * @brief Pack a landing_target message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param target_num The ID of the target if multiple targets are present
 * @param frame MAV_FRAME enum specifying the whether the following feilds are earth-frame, body-frame, etc.
 * @param angle_x X-axis angular offset (in radians) of the target from the center of the image
 * @param angle_y Y-axis angular offset (in radians) of the target from the center of the image
 * @param distance Distance to the target from the vehicle in meters
 * @param size_x Size in radians of target along x-axis
 * @param size_y Size in radians of target along y-axis
 * @param x X Position of the landing target on MAV_FRAME
 * @param y Y Position of the landing target on MAV_FRAME
 * @param z Z Position of the landing target on MAV_FRAME
 * @param q Quaternion of landing target orientation (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 * @param type LANDING_TARGET_TYPE enum specifying the type of landing target
 * @param position_valid Boolean indicating known position (1) or default unkown position (0), for validation of positioning of the landing target
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_landing_target_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint8_t target_num,uint8_t frame,float angle_x,float angle_y,float distance,float size_x,float size_y,float x,float y,float z,const float *q,uint8_t type,uint8_t position_valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LANDING_TARGET_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, angle_x);
    _mav_put_float(buf, 12, angle_y);
    _mav_put_float(buf, 16, distance);
    _mav_put_float(buf, 20, size_x);
    _mav_put_float(buf, 24, size_y);
    _mav_put_uint8_t(buf, 28, target_num);
    _mav_put_uint8_t(buf, 29, frame);
    _mav_put_float(buf, 30, x);
    _mav_put_float(buf, 34, y);
    _mav_put_float(buf, 38, z);