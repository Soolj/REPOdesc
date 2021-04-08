
#pragma once
// MESSAGE NAV_CONTROLLER_OUTPUT PACKING

#define MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT 62

MAVPACKED(
typedef struct __mavlink_nav_controller_output_t {
 float nav_roll; /*< Current desired roll in degrees*/
 float nav_pitch; /*< Current desired pitch in degrees*/
 float alt_error; /*< Current altitude error in meters*/
 float aspd_error; /*< Current airspeed error in meters/second*/
 float xtrack_error; /*< Current crosstrack error on x-y plane in meters*/
 int16_t nav_bearing; /*< Current desired heading in degrees*/
 int16_t target_bearing; /*< Bearing to current waypoint/target in degrees*/
 uint16_t wp_dist; /*< Distance to active waypoint in meters*/
}) mavlink_nav_controller_output_t;

#define MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT_LEN 26
#define MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT_MIN_LEN 26
#define MAVLINK_MSG_ID_62_LEN 26
#define MAVLINK_MSG_ID_62_MIN_LEN 26

#define MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT_CRC 183
#define MAVLINK_MSG_ID_62_CRC 183



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_NAV_CONTROLLER_OUTPUT { \
    62, \
    "NAV_CONTROLLER_OUTPUT", \
    8, \
    {  { "nav_roll", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_nav_controller_output_t, nav_roll) }, \
         { "nav_pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_nav_controller_output_t, nav_pitch) }, \
         { "nav_bearing", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_nav_controller_output_t, nav_bearing) }, \
         { "target_bearing", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_nav_controller_output_t, target_bearing) }, \
         { "wp_dist", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_nav_controller_output_t, wp_dist) }, \
         { "alt_error", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_nav_controller_output_t, alt_error) }, \
         { "aspd_error", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_nav_controller_output_t, aspd_error) }, \
         { "xtrack_error", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_nav_controller_output_t, xtrack_error) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_NAV_CONTROLLER_OUTPUT { \
    "NAV_CONTROLLER_OUTPUT", \
    8, \
    {  { "nav_roll", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_nav_controller_output_t, nav_roll) }, \
         { "nav_pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_nav_controller_output_t, nav_pitch) }, \
         { "nav_bearing", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_nav_controller_output_t, nav_bearing) }, \
         { "target_bearing", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_nav_controller_output_t, target_bearing) }, \
         { "wp_dist", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_nav_controller_output_t, wp_dist) }, \
         { "alt_error", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_nav_controller_output_t, alt_error) }, \
         { "aspd_error", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_nav_controller_output_t, aspd_error) }, \
         { "xtrack_error", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_nav_controller_output_t, xtrack_error) }, \
         } \
}
#endif

/**
 * @brief Pack a nav_controller_output message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param nav_roll Current desired roll in degrees
 * @param nav_pitch Current desired pitch in degrees
 * @param nav_bearing Current desired heading in degrees
 * @param target_bearing Bearing to current waypoint/target in degrees
 * @param wp_dist Distance to active waypoint in meters
 * @param alt_error Current altitude error in meters
 * @param aspd_error Current airspeed error in meters/second
 * @param xtrack_error Current crosstrack error on x-y plane in meters
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_nav_controller_output_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float nav_roll, float nav_pitch, int16_t nav_bearing, int16_t target_bearing, uint16_t wp_dist, float alt_error, float aspd_error, float xtrack_error)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT_LEN];
    _mav_put_float(buf, 0, nav_roll);
    _mav_put_float(buf, 4, nav_pitch);
    _mav_put_float(buf, 8, alt_error);
    _mav_put_float(buf, 12, aspd_error);
    _mav_put_float(buf, 16, xtrack_error);
    _mav_put_int16_t(buf, 20, nav_bearing);
    _mav_put_int16_t(buf, 22, target_bearing);
    _mav_put_uint16_t(buf, 24, wp_dist);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT_LEN);
#else
    mavlink_nav_controller_output_t packet;
    packet.nav_roll = nav_roll;
    packet.nav_pitch = nav_pitch;
    packet.alt_error = alt_error;
    packet.aspd_error = aspd_error;
    packet.xtrack_error = xtrack_error;
    packet.nav_bearing = nav_bearing;
    packet.target_bearing = target_bearing;
    packet.wp_dist = wp_dist;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT_MIN_LEN, MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT_LEN, MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT_CRC);
}

/**
 * @brief Pack a nav_controller_output message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param nav_roll Current desired roll in degrees
 * @param nav_pitch Current desired pitch in degrees
 * @param nav_bearing Current desired heading in degrees
 * @param target_bearing Bearing to current waypoint/target in degrees
 * @param wp_dist Distance to active waypoint in meters
 * @param alt_error Current altitude error in meters
 * @param aspd_error Current airspeed error in meters/second
 * @param xtrack_error Current crosstrack error on x-y plane in meters
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_nav_controller_output_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float nav_roll,float nav_pitch,int16_t nav_bearing,int16_t target_bearing,uint16_t wp_dist,float alt_error,float aspd_error,float xtrack_error)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT_LEN];
    _mav_put_float(buf, 0, nav_roll);
    _mav_put_float(buf, 4, nav_pitch);
    _mav_put_float(buf, 8, alt_error);
    _mav_put_float(buf, 12, aspd_error);
    _mav_put_float(buf, 16, xtrack_error);
    _mav_put_int16_t(buf, 20, nav_bearing);
    _mav_put_int16_t(buf, 22, target_bearing);
    _mav_put_uint16_t(buf, 24, wp_dist);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT_LEN);
#else
    mavlink_nav_controller_output_t packet;
    packet.nav_roll = nav_roll;
    packet.nav_pitch = nav_pitch;
    packet.alt_error = alt_error;
    packet.aspd_error = aspd_error;
    packet.xtrack_error = xtrack_error;
    packet.nav_bearing = nav_bearing;
    packet.target_bearing = target_bearing;
    packet.wp_dist = wp_dist;