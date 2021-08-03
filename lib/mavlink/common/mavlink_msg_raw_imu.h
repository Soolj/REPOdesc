#pragma once
// MESSAGE RAW_IMU PACKING

#define MAVLINK_MSG_ID_RAW_IMU 27

MAVPACKED(
typedef struct __mavlink_raw_imu_t {
 uint64_t time_usec; /*< Timestamp (microseconds since UNIX epoch or microseconds since system boot)*/
 int16_t xacc; /*< X acceleration (raw)*/
 int16_t yacc; /*< Y acceleration (raw)*/
 int16_t zacc; /*< Z acceleration (raw)*/
 int16_t xgyro; /*< Angular speed around X axis (raw)*/
 int16_t ygyro; /*< Angular speed around Y axis (raw)*/
 int16_t zgyro; /*< Angular speed around Z axis (raw)*/
 int16_t xmag; /*< X Magnetic field (raw)*/
 int16_t ymag; /*< Y Magnetic field (raw)*/
 int16_t zmag; /*< Z Magnetic field (raw)*/
}) mavlink_raw_imu_t;

#define MAVLINK_MSG_ID_RAW_IMU_LEN 26
#define MAVLINK_MSG_ID_RAW_IMU_MIN_LEN 26
#define MAVLINK_MSG_ID_27_LEN 26
#define MAVLINK_MSG_ID_27_MIN_LEN 26

#define MAVLINK_MSG_ID_RAW_IMU_CRC 144
#define MAVLINK_MSG_ID_27_CRC 144



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RAW_IMU { \
    27, \
    "RAW_IMU", \
    10, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_raw_imu_t, time_usec) }, \
         { "xacc", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_raw_imu_t, xacc) }, \
         { "yacc", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_raw_imu_t, yacc) }, \
         { "zacc", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_raw_imu_t, zacc) }, \
         { "xgyro", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_raw_imu_t, xgyro) }, \
         { "ygyro", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_raw_imu_t, ygyro) }, \
         { "zgyro", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_raw_imu_t, zgyro) }, \
         { "xmag", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_raw_imu_t, xmag) }, \
         { "ymag", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_raw_imu_t, ymag) }, \
         { "zmag", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_raw_imu_t, zmag) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RAW_IMU { \
    "RAW_IMU", \
    10, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_raw_imu_t, time_usec) }, \
         { "xacc", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_raw_imu_t, xacc) }, \
         { "yacc", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_raw_imu_t, yacc) }, \
         { "zacc", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_raw_imu_t, zacc) }, \
         { "xgyro", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_raw_imu_t, xgyro) }, \
         { "ygyro", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_raw_imu_t, ygyro) }, \
         { "zgyro", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_raw_imu_t, zgyro) }, \
         { "xmag", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_raw_imu_t, xmag) }, \
         { "ymag", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_raw_imu_t, ymag) }, \
         { "zmag", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_raw_imu_t, zmag) }, \
         } \
}
#endif

/**
 * @brief Pack a raw_imu message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param xacc X acceleration (raw)
 * @param yacc Y acceleration (raw)
 * @param zacc Z acceleration (raw)
 * @param xgyro Angular speed around X axis (raw)
 * @param ygyro Angular speed around Y axis (raw)
 * @param zgyro Angular speed around Z axis (raw)
 * @param xmag X Magnetic field (raw)
 * @param ymag Y Magnetic field (raw)
 * @param zmag Z Magnetic field (raw)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_raw_imu_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, int16_t xacc, int16_t yacc, int16_t zacc, int16_t xgyro, int16_t ygyro, int16_t zgyro, int16_t xmag, int16_t ymag, int16_t zmag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RAW_IMU_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int16_t(buf, 8, xacc);
    _mav_put_int16_t(buf, 10, yacc);
    _mav_put_int16_t(buf, 12, zacc);
    _mav_put_int16_t(buf, 14, xgyro);
    _mav_put_int16_t(buf, 16, ygyro);
    _mav_put_int16_t(buf, 18, zgyro);
    _mav_put_int16_t(buf, 20, xmag);
    _mav_put_int16_t(buf, 22, ymag);
    _mav_put_int16_t(buf, 24, zmag);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RAW_IMU_LEN);
#else
    mavlink_raw_imu_t packet;
    packet.time_usec = time_usec;
    packet.xacc = xacc;
    packet.yacc = yacc;
    packet.zacc = zacc;
    packet.xgyro = xgyro;
    packet.ygyro = ygyro;
    packet.zgyro = zgyro;
    packet.xmag = xmag;
    packet.ymag = ymag;
    packet.zmag = zmag;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RAW_IMU_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RAW_IMU;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RAW_IMU_MIN_LEN, MAVLINK_MSG_ID_RAW_IMU_LEN, MAVLINK_MSG_ID_RAW_IMU_CRC);
}

/**
 * @brief Pack a raw_imu message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param xacc X acceleration (raw)
 * @param yacc Y acceleration (raw)
 * @param zacc Z acceleration (raw)
 * @param xgyro Angular speed around X axis (raw)
 * @param ygyro Angular speed around Y axis (raw)
 * @param zgyro Angular speed around Z axis (raw)
 * @param xmag X Magnetic field (raw)
 * @param ymag Y Magnetic field (raw)
 * @param zmag Z Magnetic field (raw)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_raw_imu_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,int16_t xacc,int16_t yacc,int16_t zacc,int16_t xgyro,int16_t ygyro,int16_t zgyro,int16_t xmag,int16_t ymag,int16_t zmag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RAW_IMU_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int16_t(buf, 8, xacc);
    _mav_put_int16_t(buf, 10, yacc);
    _mav_put_int16_t(buf, 12, zacc);
    _mav_put_int16_t(buf, 14, xgyro);
    _mav_put_int16_t(buf, 16, ygyro);
    _mav_put_int16_t(buf, 18, zgyro);
    _mav_put_int16_t(buf, 20, xmag);
    _mav_put_int16_t(buf, 22, ymag);
    _mav_put_int16_t(buf, 24, zmag);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RAW_IMU_LEN);
#else
    mavlink_raw_imu_t packet;
    packet.time_usec = time_usec;
    packet.xacc = xacc;
    packet.yacc = yacc;
    packet.zacc = zacc;
    packet.xgyro = xgyro;
    packet.ygyro = ygyro;
    packet.zgyro = zgyro;
    packet.xmag = xmag;
    packet.ymag = ymag;
    packet.zmag = zmag;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RAW_IMU_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RAW_IMU;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RAW_IMU_MIN_LEN, MAVLINK_MSG_ID_RAW_IMU_LEN, MAVLINK_MSG_ID_RAW_IMU_CRC);
}

/**
 * @brief Encode a raw_imu struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param raw_imu C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_raw_imu_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_raw_imu_t* raw_imu)
{
    return mavlink_msg_raw_imu_pack(system_id, component_id, msg, raw_imu->time_usec, raw_imu->xacc, raw_imu->yacc, raw_imu->zacc, raw_imu->xgyro, raw_imu->ygyro, raw_imu->zgyro, raw_imu->xmag, raw_imu->ymag, raw_imu->zmag);
}

/**
 * @brief Encode a raw_imu struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param raw_imu C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_raw_imu_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_raw_imu_t* raw_imu)
{
    return mavlink_msg_raw_imu_pack_chan(system_id, component_id, chan, msg, raw_imu->time_usec, raw_imu->xacc, raw_imu->yacc, raw_imu->zacc, raw_imu->xgyro, raw_imu->ygyro, raw_imu->zgyro, raw_imu->xmag, raw_imu->ymag, raw_imu->zmag);
}

/**
 * @brief Send a raw_imu message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param xacc X acceleration (raw)
 * @param yacc Y acceleration (raw)
 * @param zacc Z acceleration (raw)
 * @param xgyro Angular speed around X axis (raw)
 * @param ygyro Angular speed around Y axis (raw)
 * @param zgyro Angular speed around Z axis (raw)
 * @param xmag X Magnetic field (raw)
 * @param ymag Y Magnetic field (raw)
 * @param zmag Z Magnetic field (raw)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_raw_imu_send(mavlink_channel_t chan, uint64_t time_usec, int16_t xacc, int16_t yacc, int16_t zacc, int16_t xgyro, int16_t ygyro, int16_t zgyro, int16_t xmag, int16_t ymag, int16_t zmag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RAW_IMU_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int16_t(buf, 8, xacc);
    _mav_put_int16_t(buf, 10, yacc);
    _mav_put_int16_t(buf, 12, zacc);
    _mav_put_int16_t(buf, 14, xgyro);
    _mav_put_int16_t(buf, 16, ygyro);
    _mav_put_int16_t(buf, 18, zgyro);
    _mav_put_int16_t(buf, 20, xmag);
    _mav_put_int16_t(buf, 22, ymag);
    _mav_put_int16_t(buf, 24, zmag);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RAW_IMU, buf, MAVLINK_MSG_ID_RAW_IMU_MIN_LEN, MAVLINK_MSG_ID_RAW_IMU_LEN, MAVLINK_MSG_ID_RAW_IMU_CRC);
#else
    mavlink_raw_imu_t packet;
    packet.time_usec = time_usec;
    packet.xacc = xacc;
    packet.yacc = yacc;
    packet.zacc = zacc;
    packet.xgyro = xgyro;
    packet.ygyro = ygyro;
    packet.zgyro = zgyro;
    packet.xmag = xmag;
    packet.ymag = ymag;
    packet.zmag = zmag;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RAW_IMU, (const char *)&packet, MAVLINK_MSG_ID_RAW_IMU_MIN_LEN, MAVLINK_MSG_ID_RAW_IMU_LEN, MAVLINK_MSG_ID_RAW_IMU_CRC);
#endif
}

/**
 * @brief Send a raw_imu message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_raw_imu_send_struct(mavlink_channel_t chan, const mavlink_raw_imu_t* raw_imu)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_raw_imu_send(chan, raw_imu->time_usec, raw