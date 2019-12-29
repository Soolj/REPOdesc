#pragma once
// MESSAGE FOLLOW_TARGET PACKING

#define MAVLINK_MSG_ID_FOLLOW_TARGET 144

MAVPACKED(
typedef struct __mavlink_follow_target_t {
 uint64_t timestamp; /*< Timestamp in milliseconds since system boot*/
 uint64_t custom_state; /*< button states or switches of a tracker device*/
 int32_t lat; /*< Latitude (WGS84), in degrees * 1E7*/
 int32_t lon; /*< Longitude (WGS84), in degrees * 1E7*/
 float alt; /*< AMSL, in meters*/
 float vel[3]; /*< target velocity (0,0,0) for unknown*/
 float acc[3]; /*< linear target acceleration (0,0,0) for unknown*/
 float attitude_q[4]; /*< (1 0 0 0 for unknown)*/
 float rates[3]; /*< (0 0 0 for unknown)*/
 float position_cov[3]; /*< eph epv*/
 uint8_t est_capabilities; /*< bit positions for tracker reporting capabilities (POS = 0, VEL = 1, ACCEL = 2, ATT + RATES = 3)*/
}) mavlink_follow_target_t;

#define MAVLINK_MSG_ID_FOLLOW_TARGET_LEN 93
#define MAVLINK_MSG_ID_FOLLOW_TARGET_MIN_LEN 93
#define MAVLINK_MSG_ID_144_LEN 93
#define MAVLINK_MSG_ID_144_MIN_LEN 93

#define MAVLINK_MSG_ID_FOLLOW_TARGET_CRC 127
#define MAVLINK_MSG_ID_144_CRC 127

#define MAVLINK_MSG_FOLLOW_TARGET_FIELD_VEL_LEN 3
#define MAVLINK_MSG_FOLLOW_TARGET_FIELD_ACC_LEN 3
#define MAVLINK_MSG_FOLLOW_TARGET_FIELD_ATTITUDE_Q_LEN 4
#define MAVLINK_MSG_FOLLOW_TARGET_FIELD_RATES_LEN 3
#define MAVLINK_MSG_FOLLOW_TARGET_FIELD_POSITION_COV_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_FOLLOW_TARGET { \
    144, \
    "FOLLOW_TARGET", \
    11, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_follow_target_t, timestamp) }, \
         { "est_capabilities", NULL, MAVLINK_TYPE_UINT8_T, 0, 92, offsetof(mavlink_follow_target_t, est_capabilities) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_follow_target_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_follow_target_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_follow_target_t, alt) }, \
         { "vel", NULL, MAVLINK_TYPE_FLOAT, 3, 28, offsetof(mavlink_follow_target_t, vel) }, \
         { "acc", NULL, MAVLINK_TYPE_FLOAT, 3, 40, offsetof(mavlink_follow_target_t, acc) }, \
         { "attitude_q", NULL, MAVLINK_TYPE_FLOAT, 4, 52, offsetof(mavlink_follow_target_t, attitude_q) }, \
         { "rates", NULL, MAVLINK_TYPE_FLOAT, 3, 68, offsetof(mavlink_follow_target_t, rates) }, \
         { "position_cov", NULL, MAVLINK_TYPE_FLOAT, 3, 80, offsetof(mavlink_follow_target_t, position_cov) }, \
         { "custom_state", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_follow_target_t, custom_state) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_FOLLOW_TARGET { \
    "FOLLOW_TARGET", \
    11, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_follow_target_t, timestamp) }, \
         { "est_capabilities", NULL, MAVLINK_TYPE_UINT8_T, 0, 92, offsetof(mavlink_follow_target_t, est_capabilities) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_follow_target_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_follow_target_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_follow_target_t, alt) }, \
         { "vel", NULL, MAVLINK_TYPE_FLOAT, 3, 28, offsetof(mavlink_follow_target_t, vel) }, \
         { "acc", NULL, MAVLINK_TYPE_FLOAT, 3, 40, offsetof(mavlink_follow_target_t, acc) }, \
         { "attitude_q", NULL, MAVLINK_TYPE_FLOAT, 4, 52, offsetof(mavlink_follow_target_t, attitude_q) }, \
         { "rates", NULL, MAVLINK_TYPE_FLOAT, 3, 68, offsetof(mavlink_follow_target_t, rates) }, \
         { "position_cov", NULL, MAVLINK_TYPE_FLOAT, 3, 80, offsetof(mavlink_follow_target_t, position_cov) }, \
         { "custom_state", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_follow_target_t, custom_state) }, \
         } \
}
#endif

/**
 * @brief Pack a follow_target message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp Timestamp in milliseconds since system boot
 * @param est_capabilities bit positions for tracker reporting capabilities (POS = 0, VEL = 1, ACCEL = 2, ATT + RATES = 3)
 * @param lat Latitude (WGS84), in degrees * 1E7
 * @param lon Longitude (WGS84), in degrees * 1E7
 * @param alt AMSL, in meters
 * @param vel target velocity (0,0,0) for unknown
 * @param acc linear target acceleration (0,0,0) for unknown
 * @param attitude_q (1 0 0 0 for unknown)
 * @param rates (0 0 0 for unknown)
 * @param position_cov eph epv
 * @param custom_state button states or switches of a tracker device
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_follow_target_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, uint8_t est_capabilities, int32_t lat, int32_t lon, float alt, const float *vel, const float *acc, const float *attitude_q, const float *rates, const float *position_cov, uint64_t custom_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FOLLOW_TARGET_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint64_t(buf, 8, custom_state);
    _mav_put_int32_t(buf, 16, lat);
    _mav_put_int32_t(buf, 20, lon);
    _mav_put_float(buf, 24, alt);
    _mav_put_uint8_t(buf, 92, est_capabilities);
    _mav_put_float_array(buf, 28, vel, 3);
    _mav_put_float_array(buf, 40, acc, 3);
    _mav_put_float_array(buf, 52, attitude_q, 4);
    _mav_put_float_array(buf, 68, rates, 3);
    _mav_put_float_array(buf, 80, position_cov, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FOLLOW_TARGET_LEN);
#else
    mavlink_follow_target_t packet;
    packet.timestamp = timestamp;
    packet.custom_state = custom_state;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.est_capabilities = est_capabilities;
    mav_array_memcpy(packet.vel, vel, sizeof(float)*3);
    mav_array_memcpy(packet.acc, acc, sizeof(float)*3);
    mav_array_memcpy(packet.attitude_q, attitude_q, sizeof(float)*4);
    mav_array_memcpy(packet.rates, rates, sizeof(float)*3);
    mav_array_memcpy(packet.position_cov, position_cov, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FOLLOW_TARGET_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FOLLOW_TARGET;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_FOLLOW_TARGET_MIN_LEN, MAVLINK_MSG_ID_FOLLOW_TARGET_LEN, MAVLINK_MSG_ID_FOLLOW_TARGET_CRC);
}

/**
 * @brief Pack a follow_target message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp Timestamp in milliseconds since system boot
 * @param est_capabilities bit positions for tracker reporting capabilities (POS = 0, VEL = 1, ACCEL = 2, ATT + RATES = 3)
 * @param lat Latitude (WGS84), in degrees * 1E7
 * @param lon Longitude (WGS84), in degrees * 1E7
 * @param alt AMSL, in meters
 * @param vel target velocity (0,0,0) for unknown
 * @param acc linear target acceleration (0,0,0) for unknown
 * @param attitude_q (1 0 0 0 for unknown)
 * @param rates (0 0 0 for unknown)
 * @param position_cov eph epv
 * @param custom_state button states or switches of a tracker device
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_follow_target_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,uint8_t est_capabilities,int32_t lat,int32_t lon,float alt,const float *vel,const float *acc,const float *attitude_q,const float *rates,const float *position_cov,uint64_t custom_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FOLLOW_TARGET_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint64_t(buf, 8, custom_state);
    _mav_put_int32_t(buf, 16, lat);
    _mav_put_int32_t(buf, 20, lon);
    _mav_put_float(buf, 24, alt);
    _mav_put_uint8_t(buf, 92, est_capabilities);
    _mav_put_float_array(buf, 28, vel, 3);
    _mav_put_float_array(buf, 40, acc, 3);
    _mav_put_float_array(buf, 52, attitude_q, 4);
    _mav_put_float_array(buf, 68, rates, 3);
    _mav_put_float_array(buf, 80, position_cov, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FOLLOW_TARGET_LEN);
#else
    mavlink_follow_target_t packet;
    packet.timestamp = timestamp;
    packet.custom_state = custom_state;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.est_capabilities = est_capabilities;
    mav_array_memcpy(packet.vel, vel, sizeof(float)*3);
    mav_array_memcpy(packet.acc, acc, sizeof(float)*3);
    mav_array_memcpy(packet.attitude_q, attitude_q, sizeof(float)*4);
    mav_array_memcpy(packet.rates, rates, sizeof(float)*3);
    mav_array_memcpy(packet.position_cov, position_cov, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FOLLOW_TARGET_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FOLLOW_TARGET;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_FOLLOW_TARGET_MIN_LEN, MAVLINK_MSG_ID_FOLLOW_TARGET_LEN, MAVLINK_MSG_ID_FOLLOW_TARGET_CRC);
}

/**
 * @brief Encode a follow_target struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param follow_target C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_follow_target_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_follow_target_t* follow_target)
{
    return mavlink_msg_follow_target_pack(system_id, component_id, msg, follow_target->timestamp, follow_target->est_capabilities, follow_target->lat, follow_target->lon, follow_target->alt, follow_target->vel, follow_target->acc, follow_target->attitude_q, follow_target->rates, follow_target->position_cov, follow_target->custom_state);
}

/**
 * @brief Encode a follow_target struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param follow_target C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_follow_target_encode_chan(uint8_t system_id, uint8_t com