#pragma once
// MESSAGE HIL_STATE_QUATERNION PACKING

#define MAVLINK_MSG_ID_HIL_STATE_QUATERNION 115

MAVPACKED(
typedef struct __mavlink_hil_state_quaternion_t {
 uint64_t time_usec; /*< Timestamp (microseconds since UNIX epoch or microseconds since system boot)*/
 float attitude_quaternion[4]; /*< Vehicle attitude expressed as normalized quaternion in w, x, y, z order (with 1 0 0 0 being the null-rotation)*/
 float rollspeed; /*< Body frame roll / phi angular speed (rad/s)*/
 float pitchspeed; /*< Body frame pitch / theta angular speed (rad/s)*/
 float yawspeed; /*< Body frame yaw / psi angular speed (rad/s)*/
 int32_t lat; /*< Latitude, expressed as degrees * 1E7*/
 int32_t lon; /*< Longitude, expressed as degrees * 1E7*/
 int32_t alt; /*< Altitude in meters, expressed as * 1000 (millimeters)*/
 int16_t vx; /*< Ground X Speed (Latitude), expressed as cm/s*/
 int16_t vy; /*< Ground Y Speed (Longitude), expressed as cm/s*/
 int16_t vz; /*< Ground Z Speed (Altitude), expressed as cm/s*/
 uint16_t ind_airspeed; /*< Indicated airspeed, expressed as cm/s*/
 uint16_t true_airspeed; /*< True airspeed, expressed as cm/s*/
 int16_t xacc; /*< X acceleration (mg)*/
 int16_t yacc; /*< Y acceleration (mg)*/
 int16_t zacc; /*< Z acceleration (mg)*/
}) mavlink_hil_state_quaternion_t;

#define MAVLINK_MSG_ID_HIL_STATE_QUATERNION_LEN 64
#define MAVLINK_MSG_ID_HIL_STATE_QUATERNION_MIN_LEN 64
#define MAVLINK_MSG_ID_115_LEN 64
#define MAVLINK_MSG_ID_115_MIN_LEN 64

#define MAVLINK_MSG_ID_HIL_STATE_QUATERNION_CRC 4
#define MAVLINK_MSG_ID_115_CRC 4

#define MAVLINK_MSG_HIL_STATE_QUATERNION_FIELD_ATTITUDE_QUATERNION_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_HIL_STATE_QUATERNION { \
    115, \
    "HIL_STATE_QUATERNION", \
    16, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_hil_state_quaternion_t, time_usec) }, \
         { "attitude_quaternion", NULL, MAVLINK_TYPE_FLOAT, 4, 8, offsetof(mavlink_hil_state_quaternion_t, attitude_quaternion) }, \
         { "rollspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_hil_state_quaternion_t, rollspeed) }, \
         { "pitchspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_hil_state_quaternion_t, pitchspeed) }, \
         { "yawspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_hil_state_quaternion_t, yawspeed) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 36, offsetof(mavlink_hil_state_quaternion_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 40, offsetof(mavlink_hil_state_quaternion_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 44, offsetof(mavlink_hil_state_quaternion_t, alt) }, \
         { "vx", NULL, MAVLINK_TYPE_INT16_T, 0, 48, offsetof(mavlink_hil_state_quaternion_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_INT16_T, 0, 50, offsetof(mavlink_hil_state_quaternion_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_INT16_T, 0, 52, offsetof(mavlink_hil_state_quaternion_t, vz) }, \
         { "ind_airspeed", NULL, MAVLINK_TYPE_UINT16_T, 0, 54, offsetof(mavlink_hil_state_quaternion_t, ind_airspeed) }, \
         { "true_airspeed", NULL, MAVLINK_TYPE_UINT16_T, 0, 56, offsetof(mavlink_hil_state_quaternion_t, true_airspeed) }, \
         { "xacc", NULL, MAVLINK_TYPE_INT16_T, 0, 58, offsetof(mavlink_hil_state_quaternion_t, xacc) }, \
         { "yacc", NULL, MAVLINK_TYPE_INT16_T, 0, 60, offsetof(mavlink_hil_state_quaternion_t, yacc) }, \
         { "zacc", NULL, MAVLINK_TYPE_INT16_T, 0, 62, offsetof(mavlink_hil_state_quaternion_t, zacc) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_HIL_STATE_QUATERNION { \
    "HIL_STATE_QUATERNION", \
    16, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_hil_state_quaternion_t, time_usec) }, \
         { "attitude_quaternion", NULL, MAVLINK_TYPE_FLOAT, 4, 8, offsetof(mavlink_hil_state_quaternion_t, attitude_quaternion) }, \
         { "rollspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_hil_state_quaternion_t, rollspeed) }, \
         { "pitchspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_hil_state_quaternion_t, pitchspeed) }, \
         { "yawspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_hil_state_quaternion_t, yawspeed) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 36, offsetof(mavlink_hil_state_quaternion_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 40, offsetof(mavlink_hil_state_quaternion_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 44, offsetof(mavlink_hil_state_quaternion_t, alt) }, \
         { "vx", NULL, MAVLINK_TYPE_INT16_T, 0, 48, offsetof(mavlink_hil_state_quaternion_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_INT16_T, 0, 50, offsetof(mavlink_hil_state_quaternion_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_INT16_T, 0, 52, offsetof(mavlink_hil_state_quaternion_t, vz) }, \
         { "ind_airspeed", NULL, MAVLINK_TYPE_UINT16_T, 0, 54, offsetof(mavlink_hil_state_quaternion_t, ind_airspeed) }, \
         { "true_airspeed", NULL, MAVLINK_TYPE_UINT16_T, 0, 56, offsetof(mavlink_hil_state_quaternion_t, true_airspeed) }, \
         { "xacc", NULL, MAVLINK_TYPE_INT16_T, 0, 58, offsetof(mavlink_hil_state_quaternion_t, xacc) }, \
         { "yacc", NULL, MAVLINK_TYPE_INT16_T, 0, 60, offsetof(mavlink_hil_state_quaternion_t, yacc) }, \
         { "zacc", NULL, MAVLINK_TYPE_INT16_T, 0, 62, offsetof(mavlink_hil_state_quaternion_t, zacc) }, \
         } \
}
#endif

/**
 * @brief Pack a hil_state_quaternion message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param attitude_quaternion Vehicle attitude expressed as normalized quaternion in w, x, y, z order (with 1 0 0 0 being the null-rotation)
 * @param rollspeed Body frame roll / phi angular speed (rad/s)
 * @param pitchspeed Body frame pitch / theta angular speed (rad/s)
 * @param yawspeed Body frame yaw / psi angular speed (rad/s)
 * @param lat Latitude, expressed as degrees * 1E7
 * @param lon Longitude, expressed as degrees * 1E7
 * @param alt Altitude in meters, expressed as * 1000 (millimeters)
 * @param vx Ground X Speed (Latitude), expressed as cm/s
 * @param vy Ground Y Speed (Longitude), expressed as cm/s
 * @param vz Ground Z Speed (Altitude), expressed as cm/s
 * @param ind_airspeed Indicated airspeed, expressed as cm/s
 * @param true_airspeed True airspeed, expressed as cm/s
 * @param xacc X acceleration (mg)
 * @param yacc Y acceleration (mg)
 * @param zacc Z acceleration (mg)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_hil_state_quaternion_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, const float *attitude_quaternion, float rollspeed, float pitchspeed, float yawspeed, int32_t lat, int32_t lon, int32_t alt, int16_t vx, int16_t vy, int16_t vz, uint16_t ind_airspeed, uint16_t true_airspeed, int16_t xacc, int16_t yacc, int16_t zacc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HIL_STATE_QUATERNION_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 24, rollspeed);
    _mav_put_float(buf, 28, pitchspeed);
    _mav_put_float(buf, 32, yawspeed);
    _mav_put_int32_t(buf, 36, lat);
    _mav_put_int32_t(buf, 40, lon);
    _mav_put_int32_t(buf, 44, alt);
    _mav_put_int16_t(buf, 48, vx);
    _mav_put_int16_t(buf, 50, vy);
    _mav_put_int16_t(buf, 52, vz);
    _mav_put_uint16_t(buf, 54, ind_airspeed);
    _mav_put_uint16_t(buf, 56, true_airspeed);
    _mav_put_int16_t(buf, 58, xacc);
    _mav_put_int16_t(buf, 60, yacc);
    _mav_put_int16_t(buf, 62, zacc);
    _mav_put_float_array(buf, 8, attitude_quaternion, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HIL_STATE_QUATERNION_LEN);
#else
    mavlink_hil_state_quaternion_t packet;
    packet.time_usec = time_usec;
    packet.rollspeed = rollspeed;
    packet.pitchspeed = pitchspeed;
    packet.yawspeed = yawspeed;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.vx = vx;
    packet.vy = vy;
    packet.vz = vz;
    packet.ind_airspeed = ind_airspeed;
    packet.true_airspeed = true_airspeed;
    packet.xacc = xacc;
    packet.yacc = yacc;
    packet.zacc = zacc;
    mav_array_memcpy(packet.attitude_quaternion, attitude_quaternion, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HIL_STATE_QUATERNION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HIL_STATE_QUATERNION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HIL_STATE_QUATERNION_MIN_LEN, MAVLINK_MSG_ID_HIL_STATE_QUATERNION_LEN, MAVLINK_MSG_ID_HIL_STATE_QUATERNION_CRC);
}

/**
 * @brief Pack a hil_state_quaternion message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param attitude_quaternion Vehicle attitude expressed as normalized quaternion in w, x, y, z order (with 1 0 0 0 being the null-rotation)
 * @param rollspeed Body frame roll / phi angular speed (rad/s)
 * @param pitchspeed Body frame pitch / theta angular speed (rad/s)
 * @param yawspeed Body frame yaw / psi angular speed (rad/s)
 * @param lat Latitude, expressed as degrees * 1E7
 * @param lon Longitude, expressed as degrees * 1E7
 * @param alt Altitude in meters, expressed as * 1000 (millimeters)
 * @param vx Ground X Speed (Latitude), expressed as cm/s
 * @param vy Ground Y Speed (Longitude), expressed as cm/s
 * @param vz Ground Z Speed (Altitude), expressed as cm/s
 * @param ind_airspeed Indicated airspeed, expressed as cm/s
 * @param true_airspeed True airspeed, expressed as cm/s
 * @param xacc X acceleration (mg)
 * @param yacc Y acceleration (mg)
 * @param zacc Z acceleration (mg)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_hil_state_quaternion_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,const float *attitude_quaternion,float rollspeed,float pitchspeed,float yawspeed,int32_t lat,int32_t lon,int32_t alt,int16_t vx,int16_t vy,int16_t vz,uint16_t ind_airspeed,uint16_t true_airspeed,int16_t xacc,int16_t yacc,int16_t zacc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HIL_STATE_QUATERNION_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 24, rollspeed);
    _mav_put_float(buf, 28, pitchspeed);
    _mav_put_float(buf, 32, yawspeed);
    _mav_put_int32_t(buf, 36, lat);
    _mav_put_int32_t(buf, 40, lon);
    _mav_put_int32_t(buf, 44, alt);
    _mav_put_int16_t(buf, 48, vx);
    _mav_put_int16_t(buf, 50, vy);
    _mav_put_int16_t(buf, 52, vz);
    _mav_put_uint16_t(buf, 54, ind_airspeed);
    _mav_put_uint16_t(buf, 56, true_airspeed);
    _mav_put_int16_t(buf, 58, xacc);
    _mav_put_int16_t(buf, 60, yacc);
    _mav_put_int16_t(buf, 62, zacc);
    _mav_put_float_array(buf, 8, attitude_quaternion, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HIL_STATE_QUATERNION_LEN);
#else
    mavlink_hil_state_quaternion_t packet;
    packet.time_usec = time_usec;
    packet.rollspeed = rollspeed;
    packet.pitchspeed = pitchspeed;
    packet.yawspeed = yawspeed;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.vx = vx;
    packet.vy = vy;
    packet.vz = vz;
    packet.ind_airspeed = ind_airspeed;
    packet.true_airspeed = true_airspeed;
    packet.xacc = xacc;
    packet.yacc = yacc;
    packet.zacc = zacc;
    mav_array_memcpy(packet.attitude_quaternion, attitude_quaternion, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HIL_STATE_QUATERNION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HIL_STATE_QUATERNION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HIL_STATE_QUATERNION_MIN_LEN, MAVLINK_MSG_ID_HIL_STATE_QUATERNION_LEN, MAVLINK_MSG_ID_HIL_STATE_QUATERNION_CRC);
}

/**
 * @brief Encode a hil_state_quaternion struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param hil_state_quaternion C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_hil_state_quaternion_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_hil_state_quaternion_t* hil_state_quaternion)
{
    return mavlink_msg_hil_state_quaternion_pack(system_id, component_id, msg, hil_state_quaternion->time_usec, hil_state_quaternion->attitude_quaternion, hil_state_quaternion->rollspeed, hil_state_quaternion->pitchspeed, hil_state_quaternion->yawspeed, hil_state_quaternion->lat, hil_state_quaternion->lon, hil_state_quaternion->alt, hil_state_quaternion->vx, hil_state_quaternion->vy, hil_state_quaternion->vz, hil_state_quaternion->ind_airspeed, hil_state_quaternion->true_airspeed, hil_state_quaternion->xacc, hil_state_quaternion->yacc, hil_state_quaternion->zacc);
}

/**
 * @brief Encode a hil_state_quaternion struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param hil_state_quaternion C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_hil_state_quaternion_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_hil_state_quaternion_t* hil_state_quaternion)
{
    return mavlink_msg_hil_state_quaternion_pack_chan(system_id, component_id, chan, msg, hil_state_quaternion->time_usec, hil_state_quaternion->attitude_quaternion, hil_state_quaternion->rollspeed, hil_state_quaternion->pitchspeed, hil_state_quaternion->yawspeed, hil_state_quaternion->lat, hil_state_quaternion->lon, hil_state_quaternion->alt, hil_state_quaternion->vx, hil_state_quaternion->vy, hil_state_quaternion->vz, hil_state_quaternion->ind_airspeed, hil_state_quaternion->true_airspeed, hil_state_quaternion->xacc, hil_state_quaternion->yacc, hil_state_quaternion->zacc);
}

/**
 * @brief Send a hil_state_quaternion message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param attitude_quaternion Vehicle attitude expressed as normalized quaternion in w, x, y, z order (with 1 0 0 0 being the null-rotation)
 * @param rollspeed Body frame roll / phi angular speed (rad/s)
 * @param pitchspeed Body frame pitch / theta angular speed (rad/s)
 * @param yawspeed Body frame yaw / psi angular speed (rad/s)
 * @param lat Latitude, expressed as degrees * 1E7
 * @param lon Longitude, expressed as degrees * 1E7
 * @param alt Altitude in meters, expressed as * 1000 (millimeters)
 * @param vx Ground X Speed (Latitude), expressed as cm/s
 * @param vy Ground Y Speed (Longitude), expressed as cm/s
 * @param vz Ground Z Speed (Altitude), expressed as cm/s
 * @param ind_airspeed Indicated airspeed, expressed as cm/s
 * @param true_airspeed True airspeed, expressed as cm/s
 * @param xacc X acceleration (mg)
 * @param yacc Y acceleration (mg)
 * @param zacc Z acceleration (mg)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_hil_state_quaternion_send(mavlink_channel_t chan, uint64_t time_usec, const float *attitude_quaternion, float rollspeed, float pitchspeed, float yawspeed, int32_t lat, int32_t lon, int32_t alt, int16_t vx, int16_t vy, int16_t vz, uint16_t ind_airspeed, uint16_t true_airspeed, int16_t xacc, int16_t yacc, int16_t zacc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HIL_STATE_QUATERNION_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 24, rollspeed);
    _mav_put_float(buf, 28, pitchspeed);
    _mav_put_float(buf, 32, yawspeed);
    _mav_put_int32_t(buf, 36, lat);
    _mav_put_int32_t(buf, 40, lon);
    _mav_put_int32_t(buf, 44, alt);
    _mav_put_int16_t(buf, 48, vx);
    _mav_put_int16_t(buf, 50, vy);
    _mav_put_int16_t(buf, 52, vz);
    _mav_put_uint16_t(buf, 54, ind_airspeed);
    _mav_put_uint16_t(buf, 56, true_airspeed);
    _mav_put_int16_t(buf, 58, xacc);
    _mav_put_int16_t(buf, 60, yacc);
    _mav_put_int16_t(buf, 62, zacc);
    _mav_put_float_array(buf, 8, attitude_quaternion, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HIL_STATE_QUATERNION, buf, MAVLINK_MSG_ID_HIL_STATE_QUATERNION_MIN_LEN, MAVLINK_MSG_ID_HIL_STATE_QUATERNION_LEN, MAVLINK_MSG_ID_HIL_STATE_QUATERNION_CRC);
#else
    mavlink_hil_state_quaternion_t packet;
    packet.time_usec = time_usec;
    packet.rollspeed = rollspeed;
    packet.pitchspeed = pitchspeed;
    packet.yawspeed = yawspeed;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.vx = vx;
    packet.vy = vy;
    packet.vz = vz;
    packet.ind_airspeed = ind_airspeed;
    packet.true_airspeed = true_airspeed;
    packet.xacc = xacc;
    packet.yacc = yacc;
    packet.zacc = zacc;
    mav_array_memcpy(packet.attitude_quaternion, attitude_quaternion, sizeof(float)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HIL_STATE_QUATERNION, (const char *)&packet, MAVLINK_MSG_ID_HIL_STATE_QUATERNION_MIN_LEN, MAVLINK_MSG_ID_HIL_STATE_QUATERNION_LEN, MAVLINK_MSG_ID_HIL_STATE_QUATERNION_CRC);
#endif
}

/**
 * @brief Send a hil_state_quaternion message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_hil_state_quaternion_send_struct(mavlink_channel_t chan, const mavlink_hil_state_quaternion_t* hil_state_quaternion)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_hil_state_quaternion_send(chan, hil_state_quaternion->time_usec, hil_state_quaternion->attitude_quaternion, hil_state_quaternion->rollspeed, hil_state_quaternion->pitchspeed, hil_state_quaternion->yawspeed, hil_state_quaternion->lat, hil_state_quaternion->lon, hil_state_quaternion->alt, hil_state_quaternion->vx, hil_state_quaternion->vy, hil_state_quaternion->vz, hil_state_quaternion->ind_airspeed, hil_state_quaternion->true_airspeed, hil_state_quaternion->xacc, hil_state_quaternion->yacc, hil_state_quaternion->zacc);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HIL_STATE_QUATERNION, (const char *)hil_state_quaternion, MAVLINK_MSG_ID_HIL_STATE_QUATERNION_MIN_LEN, MAVLINK_MSG_ID_HIL_STATE_QUATERNION_LEN, MAVLINK_MSG_ID_HIL_STATE_QUATERNION_CRC);
#endif
}

#if MAVLINK_MSG_ID_HIL_STATE_QUATERNION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save