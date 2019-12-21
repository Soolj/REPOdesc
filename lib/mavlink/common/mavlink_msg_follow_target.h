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
#define