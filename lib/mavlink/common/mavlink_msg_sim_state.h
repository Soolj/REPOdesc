#pragma once
// MESSAGE SIM_STATE PACKING

#define MAVLINK_MSG_ID_SIM_STATE 108

MAVPACKED(
typedef struct __mavlink_sim_state_t {
 float q1; /*< True attitude quaternion component 1, w (1 in null-rotation)*/
 float q2; /*< True attitude quaternion component 2, x (0 in null-rotation)*/
 float q3; /*< True attitude quaternion component 3, y (0 in null-rotation)*/
 float q4; /*< True attitude quaternion component 4, z (0 in null-rotation)*/
 float roll; /*< Attitude roll expressed as Euler angles, not recommended except for human-readable outputs*/
 float pitch; /*< Attitude pitch expressed as Euler angles, not recommended except for human-readable outputs*/
 float yaw; /*< Attitude yaw expressed as Euler angles, not recommended except for human-readable outputs*/
 float xacc; /*< X acceleration m/s/s*/
 float yacc; /*< Y acceleration m/s/s*/
 float zacc; /*< Z acceleration m/s/s*/
 float xgyro; /*< Angular speed around X axis rad/s*/
 float ygyro; /*< Angular speed around Y axis rad/s*/
 float zgyro; /*< Angular speed around Z axis rad/s*/
 float lat; /*< Latitude in degrees*/
 float lon; /*< Longitude in degrees*/
 float alt; /*< Altitude in meters*/
 float std_dev_horz; /*< Horizontal position standard deviation*/
 float std_dev_vert; /*< Vertical position standard deviation*/
 float vn; /*< True velocity in m/s in NORTH direction in earth-fixed NED frame*/
 float ve; /*< True velocity in m/s in EAST direction in earth-fixed NED frame*/
 float vd; /*< True velocity in m/s in DOWN direction in earth-fixed NED frame*/
}) mavlink_sim_state_t;

#define MAVLINK_MSG_ID_SIM_STATE_LEN 84
#define MAVLINK_MSG_ID_SIM_STATE_MIN_LEN 84
#define MAVLINK_MSG_ID_108_LEN 84
#define MAVLINK_MSG_ID_108_MIN_LEN 84

#define MAVLINK_MSG_ID_SIM_STATE_CRC 32
#define MAVLINK_MSG_ID_108_CRC 32



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SIM_STATE { \
    108, \
    "SIM_STATE", \
    21, \
    {  { "q1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_sim_state_t, q1) }, \
         { "q2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_sim_state_t, q2) }, \
         { "q3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_sim_state_t, q3) }, \
         { "q4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_sim_state_t, q4) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_sim_state_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_sim_state_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_sim_state_t, yaw) }, \
         { "xacc", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_sim_state_t, xacc) }, \
         { "yacc", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_sim_state_t, yacc) }, \
         { "zacc", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_sim_state_t, zacc) }, \
         { "xgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_sim_state_t, xgyro) }, \
         { "ygyro", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_sim_state_t, ygyro) }, \
         { "zgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_sim_state_t, zgyro) }, \
         { "lat", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_sim_state_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_sim_state_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_sim_state_t, alt) }, \
         { "std_dev_horz", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_sim_state_t, std_dev_horz) }, \
         { "std_dev_vert", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_sim_state_t, std_dev_vert) }, \
         { "vn", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_sim_state_t, vn) }, \
         { "ve", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_sim_state_t, ve) }, \
         { "vd", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_sim_state_t, vd) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SIM_STATE { \
    "SIM_STATE", \
    21, \
    {  { "q1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_sim_state_t, q1) }, \
         { "q2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_sim_state_t, q2) }, \
         { "q3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_sim_state_t, q3) }, \
         { "q4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_sim_state_t, q4) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_sim_state_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_sim_state_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_sim_state_t, yaw) }, \
         { "xacc", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_sim_state_t, xacc) }, \
         { "yacc", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_sim_state_t, yacc) }, \
         { "zacc", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_sim_state_t, zacc) }, \
         { "xgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_sim_state_t, xgyro) }, \
         { "ygyro", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_sim_state_t, ygyro) }, \
         { "zgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_sim_state_t, zgyro) }, \
         { "lat", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_sim_state_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_sim_state_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_sim_state_t, alt) }, \
         { "std_dev_horz", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_sim_state_t, std_dev_horz) }, \
         { "std_dev_vert", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_sim_state_t, std_dev_vert) }, \
         { "vn", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_sim_state_t, vn) }, \
         { "ve", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_sim_state_t, ve) }, \
         { "vd", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_sim_state_t, vd) }, \
         } \
}
#endif

/**
 * @brief Pack a sim_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param q1 True attitude quaternion component 1, w (1 in null-rotation)
 * @param q2 True attitude quaternion component 2, x (0 in null-rotation)
 * @param q3 True attitude quaternion component 3, y (0 in null-rotation)
 * @param q4 True attitude quaternion component 4, z (0 in null-rotation)
 * @param roll Attitude roll expressed as Euler angles, not recommended except for human-readable outputs
 * @param pitch Attitude pitch expressed as Euler angles, not recommended except for human-readable outputs
 * @param yaw Attitude yaw expressed as Euler angles, not recommended except for human-readable outputs
 * @param xacc X acceleration m/s/s
 * @param yacc Y acceleration m/s/s
 * @param zacc Z acceleration m/s/s
 * @param xgyro Angular speed around X axis rad/s
 * @param ygyro Angular speed around Y axis rad/s
 * @param zgyro Angular speed around Z axis rad/s
 * @param lat Latitude in degrees
 * @param lon Longitude in degrees
 * @param alt Altitude in meters
 * @param std_dev_horz Horizontal position standard deviation
 * @param std_dev_vert Vertical position standard deviation
 * @param vn True velocity in m/s in NORTH direction in earth-fixed NED frame
 * @param ve True velocity in m/s in EAST direction in earth-fixed NED frame
 * @param vd True velocity in m/s in DOWN direction in earth-fixed NED frame
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sim_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float q1, float q2, float q3, float q4, float roll, float pitch, float yaw, float xacc, float yacc, float zacc, float xgyro, float ygyro, float zgyro, float lat, float lon, float alt, float std_dev_horz, float std_dev_vert, float vn, float ve, float vd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SIM_STATE_LEN];
    _mav_put_float(buf, 0, q1);
    _mav_put_float(buf, 4, q2);
    _mav_put_float(buf, 8, q3);
    _mav_put_float(buf, 12, q4);
    _mav_put_float(buf, 16, roll);
    _mav_put_float(buf, 20, pitch);
    _mav_put_float(buf, 24, yaw);
    _mav_put_float(buf, 28, xacc);
    _mav_put_float(buf, 32, yacc);
    _mav_put_float(buf, 36, zacc);
    _mav_put_float(buf, 40, xgyro);
    _mav_put_float(buf, 44, ygyro);
    _mav_put_float(buf, 48, zgyro);
    _mav_put_float(buf, 52, lat);
    _mav_put_float(buf, 56, lon);
    _mav_put_float(buf, 60, alt);
    _mav_put_float(buf, 64, std_dev_horz);
    _mav_put_float(buf, 68, std_dev_vert);
    _mav_put_float(buf, 72, vn);
    _mav_put_float(buf, 76, ve);
    _mav_put_float(buf, 80, vd);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SIM_STATE_LEN);
#else
    mavlink_sim_state_t packet;
    packet.q1 = q1;
    packet.q2 = q2;
    packet.q3 = q3;
    packet.q4 = q4;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.xacc = xacc;
    packet.yacc = yacc;
    packet.zacc = zacc;
    packet.xgyro = xgyro;
    packet.ygyro = ygyro;
    packet.zgyro = zgyro;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.std_dev_horz = std_dev_horz;
    packet.std_dev_vert = std_dev_vert;
    packet.vn = vn;
    packet.ve = ve;
    packet.vd = vd;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SIM_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SIM_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SIM_STATE_MIN_LEN, MAVLINK_MSG_ID_SIM_STATE_LEN, MAVLINK_MSG_ID_SIM_STATE_CRC);
}

/**
 * @brief Pack a sim_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param q1 True attitude quaternion component 1, w (1 in null-rotation)
 * @param q2 True attitude quaternion component 2, x (0 in null-rotation)
 * @param q3 True attitude quaternion component 3, y (0 in null-rotation)
 * @param q4 True attitude quaternion component 4, z (0 in null-rotation)
 * @param roll Attitude roll expressed as Euler angles, not recommended except for human-readable outputs
 * @param pitch Attitude pitch expressed as Euler angles, not recommended except for human-readable outputs
 * @param yaw Attitude yaw expressed as Euler angles, not recommended except for human-readable outputs
 * @param xacc X acceleration m/s/s
 * @param yacc Y acceleration m/s/s
 * @param zacc Z acceleration m/s/s
 * @param xgyro Angular speed around X axis rad/s
 * @param ygyro Angular speed around Y axis rad/s
 * @param zgyro Angular speed around Z axis rad/s
 * @param lat Latitu