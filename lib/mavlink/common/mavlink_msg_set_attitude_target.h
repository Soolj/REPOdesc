#pragma once
// MESSAGE SET_ATTITUDE_TARGET PACKING

#define MAVLINK_MSG_ID_SET_ATTITUDE_TARGET 82

MAVPACKED(
typedef struct __mavlink_set_attitude_target_t {
 uint32_t time_boot_ms; /*< Timestamp in milliseconds since system boot*/
 float q[4]; /*< Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)*/
 float body_roll_rate; /*< Body roll rate in radians per second*/
 float body_pitch_rate; /*< Body pitch rate in radians per second*/
 float body_yaw_rate; /*< Body yaw rate in radians per second*/
 float thrust; /*< Collective thrust, normalized to 0 .. 1 (-1 .. 1 for vehicles capable of reverse trust)*/
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 uint8_t type_mask; /*< Mappings: If any of these bits are set, the corresponding input should be ignored: bit 1: body roll rate, bit 2: body pitch rate, bit 3: body yaw rate. bit 4-bit 6: reserved, bit 7: throttle, bit 8: attitude*/
}) mavlink_set_attitude_target_t;

#define MAVLINK_MSG_ID_SET_ATTITUDE_TARGET_LEN 39
#define MAVLINK_MSG_ID_SET_ATTITUDE_TARGET_MIN_LEN 39
#define MAVLINK_MSG_ID_82_LEN 39
#define MAVLINK_MSG_ID_82_MIN_LEN 39

#define MAVLINK_MSG_ID_SET_ATTITUDE_TARGET_CRC 49
#define MAVLINK_MSG_ID_82_CRC 49

#define MAVLINK_MSG_SET_ATTITUDE_TARGET_FIELD_Q_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SET_ATTITUDE_TARGET { \
    82, \
    "SET_ATTITUDE_TARGET", \
    9, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_set_attitude_target_t, time_boot_ms) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_set_attitude_target_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 37, offsetof(mavlink_set_attitude_target_t, target_component) }, \
         { "type_mask", NULL, MAVLINK_TYPE_UINT8_T, 0, 38, offsetof(mavlink_set_attitude_target_t, type_mask) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 4, offsetof(mavlink_set_attitude_target_t, q) }, \
         { "body_roll_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_set_attitude_target_t, body_roll_rate) }, \
         { "body_pitch_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_set_attitude_target_t, body_pitch_rate) }, \
         { "body_yaw_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_set_attitude_target_t, body_yaw_rate) }, \
         { "thrust", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_set_attitude_target_t, thrust) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SET_ATTITUDE_TARGET { \
    "SET_ATTITUDE_TARGET", \
    9, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_set_attitude_target_t, time_boot_ms) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_set_attitude_target_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 37, offsetof(mavlink_set_attitude_target_t, target_component) }, \
         { "type_mask", NULL, MAVLINK_TYPE_UINT8_T, 0, 38, offsetof(mavlink_set_attitude_target_t, type_mask) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 4, offsetof(mavlink_set_attitude_target_t, q) }, \
         { "body_roll_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_set_attitude_target_t, body_roll_rate) }, \
         { "body_pitch_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_set_attitude_target_t, body_pitch_rate) }, \
         { "body_yaw_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_set_attitude_target_t, body_yaw_rate) }, \
         { "thrust", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_set_attitude_target_t, thrust) }, \
         } \
}
#endif

/**
 * @brief Pack a set_attitude_target message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms Timestamp in milliseconds since system boot
 * @param target_system System ID
 * @param target_component Component ID
 * @param type_mask Mappings: If any of these bits are set, the corresponding input should be ignored: bit 1: body roll rate, bit 2: body pitch rate, bit 3: body yaw rate. bit 4-bit 6: reserved, bit 7: throttle, bit 8: attitude
 * @param q Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 * @param body_roll_rate Body roll rate in radians per second
 * @param body_pitch_rate Body pitch rate in radians per second
 * @param body_yaw_rate Body yaw rate in radians per second
 * @param thrust Collective thrust, normalized to 0 .. 1 (-1 .. 1 for vehicles capable of reverse trust)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_attitude_target_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint8_t target_system, uint8_t target_component, uint8_t type_mask, const float *q, float body_roll_rate, float body_pitch_rate, float body_yaw_rate, float thrust)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_ATTITUDE_TARGET_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 20, body_roll_rate);
    _mav_put_float(buf, 24, body_pitch_rate);
    _mav_put_float(buf, 28, body_yaw_rate);
    _mav_put_float(buf, 32, thrust);
    _mav_put_uint8_t(buf, 36, target_system);
    _mav_put_uint8_t(buf, 37, target_component);
    _mav_put_uint8_t(buf, 38, type_mask);
    _mav_put_float_array(buf, 4, q, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_ATTITUDE_TARGET_LEN);
#else
    mavlink_set_attitude_target_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.body_roll_rate = body_roll_rate;
    packet.body_pitch_rate = body_pitch_rate;
    packet.body_yaw_rate = body_yaw_rate;
    packet.thrust = thrust;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.type_mask = type_mask;
    mav_array_memcpy(packet.q, q, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_ATTITUDE_TARGET_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_ATTITUDE_TARGET;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SET_ATTITUDE_TARGET_MIN_LEN, MAVLINK_MSG_ID_SET_ATTITUDE_TARGET_LEN, MAVLINK_MSG_ID_SET_ATTITUDE_TARGET_CRC);
}

/**
 * @brief Pack a set_attitude_target message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms Timestamp in milliseconds since system boot
 * @param target_system System ID
 * @param target_component Component ID
 * @param type_mask Mappings: If any of these bits are set, the corresponding input should be ignored: bit 1: body roll rate, bit 2: body pitch rate, bit 3: body yaw rate. bit 4-bit 6: reserved, bit 7: throttle, bit 8: attitude
 * @param q Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 * @param body_roll_rate Body roll rate in radians per second
 * @param body_pitch_rate Body pitch rate in radians per second
 * @param body_yaw_rate Body yaw rate in radians per second
 * @param thrust Collective thrust, normalized to 0 .. 1 (-1 .. 1 for vehicles capable of reverse trust)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_attitude_target_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint8_t target_system,uint8_t target_component,uint8_t type_mask,const float *q,float body_roll_rate,float body_pitch_rate,float body_yaw_rate,float thrust)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_ATTITUDE_TARGET_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 20, body_roll_rate);
    _mav_put_float(buf, 24, body_pitch_rate);
    _mav_put_float(buf, 28, body_yaw_rate);
    _mav_put_float(buf, 32, thrust);
    _mav_put_uint8_t(buf, 36, target_system);
    _mav_put_uint8_t(buf, 37, target_component);
    _mav_put_uint8_t(buf, 38, type_mask);
    _mav_put_float_array(buf, 4, q, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_ATTITUDE_TARGET_LEN);
#else
    mavlink_set_attitude_target_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.body_roll_rate = body_roll_rate;
    packet.body_pitch_rate = body_pitch_rate;
    packet.body_yaw_rate = body_yaw_rate;
    packet.thrust = thrust;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.type_mask = type_mask;
    mav_array_memcpy(packet.q, q, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_ATTITUDE_TARGET_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_ATTITUDE_TARGET;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SET_ATTITUDE_TARGET_MIN_LEN, MAVLINK_MSG_ID_SET_ATTITUDE_TARGET_LEN, MAVLINK_MSG_ID_SET_ATTITUDE_TARGET_CRC);
}

/**
 * @brief Encode a set_attitude_target struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param set_attitude_target C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_attitude_target_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_set_attitude_target_t* set_attitude_target)
{
    return mavlink_msg_set_attitude_target_pack(system_id, component_id, msg, set_attitude_target->time_boot_ms, set_attitude_target->target_system, set_attitude_target->target_component, set_attitude_target->type_mask, set_attitude_target->q, set_attitude_target->body_roll_rate, set_attitude_target->body_pitch_rate, set_attitude_target->body_yaw_rate, set_attitude_target->thrust);
}

/**
 * @brief Encode a set_attitude_target struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink