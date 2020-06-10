#pragma once
// MESSAGE GPS2_RTK PACKING

#define MAVLINK_MSG_ID_GPS2_RTK 128

MAVPACKED(
typedef struct __mavlink_gps2_rtk_t {
 uint32_t time_last_baseline_ms; /*< Time since boot of last baseline message received in ms.*/
 uint32_t tow; /*< GPS Time of Week of last baseline*/
 int32_t baseline_a_mm; /*< Current baseline in ECEF x or NED north component in mm.*/
 int32_t baseline_b_mm; /*< Current baseline in ECEF y or NED east component in mm.*/
 int32_t baseline_c_mm; /*< Current baseline in ECEF z or NED down component in mm.*/
 uint32_t accuracy; /*< Current estimate of baseline accuracy.*/
 int32_t iar_num_hypotheses; /*< Current number of integer ambiguity hypotheses.*/
 uint16_t wn; /*< GPS Week Number of last baseline*/
 uint8_t rtk_receiver_id; /*< Identification of connected RTK receiver.*/
 uint8_t rtk_health; /*< GPS-specific health report for RTK data.*/
 uint8_t rtk_rate; /*< Rate of baseline messages being received by GPS, in HZ*/
 uint8_t nsats; /*< Current number of sats used for RTK calculation.*/
 uint8_t baseline_coords_type; /*< Coordinate system of baseline*/
}) mavlink_gps2_rtk_t;

#define MAVLINK_MSG_ID_GPS2_RTK_LEN 35
#define MAVLINK_MSG_ID_GPS2_RTK_MIN_LEN 35
#define MAVLINK_MSG_ID_128_LEN 35
#define MAVLINK_MSG_ID_128_MIN_LEN 35

#define MAVLINK_MSG_ID_GPS2_RTK_CRC 226
#define MAVLINK_MSG_ID_128_CRC 226



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GPS2_RTK { \
    128, \
    "GPS2_RTK", \
    13, \
    {  { "time_last_baseline_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_gps2_rtk_t, time_last_baseline_ms) }, \
         { "rtk_receiver_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 30, offsetof(mavlink_gps2_rtk_t, rtk_receiver_id) }, \
         { "wn", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_gps2_rtk_t, wn) }, \
         { "tow", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_gps2_rtk_t, tow) }, \
         { "rtk_health", NULL, MAVLINK_TYPE_UINT8_T, 0, 31, offsetof(mavlink_gps2_rtk_t, rtk_health) }, \
         { "rtk_rate", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_gps2_rtk_t, rtk_rate) }, \
         { "nsats", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_gps2_rtk_t, nsats) }, \
         { "baseline_coords_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_gps2_rtk_t, baseline_coords_type) }, \
         { "baseline_a_mm", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_gps2_rtk_t, baseline_a_mm) }, \
         { "baseline_b_mm", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_gps2_rtk_t, baseline_b_mm) }, \
         { "baseline_c_mm", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_gps2_rtk_t, baseline_c_mm) }, \
         { "accuracy", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_gps2_rtk_t, accuracy) }, \
         { "iar_num_hypotheses", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_gps2_rtk_t, iar_num_hypotheses) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GPS2_RTK { \
    "GPS2_RTK", \
    13, \
    {  { "time_last_baseline_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_gps2_rtk_t, time_last_baseline_ms) }, \
         { "rtk_receiver_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 30, offsetof(mavlink_gps2_rtk_t, rtk_receiver_id) }, \
         { "wn", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_gps2_rtk_t, wn) }, \
         { "tow", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_gps2_rtk_t, tow) }, \
         { "rtk_health", NULL, MAVLINK_TYPE_UINT8_T, 0, 31, offsetof(mavlink_gps2_rtk_t, rtk_health) }, \
         { "rtk_rate", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_gps2_rtk_t, rtk_rate) }, \
         { "nsats", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_gps2_rtk_t, nsats) }, \
         { "baseline_coords_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_gps2_rtk_t, baseline_coords_type) }, \
         { "baseline_a_mm", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_gps2_rtk_t, baseline_a_mm) }, \
         { "baseline_b_mm", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_gps2_rtk_t, baseline_b_mm) }, \
         { "baseline_c_mm", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_gps2_rtk_t, baseline_c_mm) }, \
         { "accuracy", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_gps2_rtk_t, accuracy) }, \
         { "iar_num_hypotheses", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_gps2_rtk_t, iar_num_hypotheses) }, \
         } \
}
#endif

/**
 * @brief Pack a gps2_rtk message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_last_baseline_ms Time since boot of last baseline message received in ms.
 * @param rtk_receiver_id Identification of connected RTK receiver.
 * @param wn GPS Week Number of last baseline
 * @param tow GPS Time of Week of last baseline
 * @param rtk_health GPS-specific health report for RTK data.
 * @param rtk_rate Rate of baseline messages being received by GPS, in HZ
 * @param nsats Current number of sats used for RTK calculation.
 * @param baseline_coords_type Coordinate system of baseline
 * @param baseline_a_mm Current baseline in ECEF x or NED north component in mm.
 * @param baseline_b_mm Current baseline in ECEF y or NED east component in mm.
 * @param baseline_c_mm Current baseline in ECEF z or NED down component in mm.
 * @param accuracy Current estimate of baseline accuracy.
 * @param iar_num_hypotheses Current number of integer ambiguity hypotheses.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps2_rtk_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_last_baseline_ms, uint8_t rtk_receiver_id, uint16_t wn, uint32_t tow, uint8_t rtk_health, uint8_t rtk_rate, uint8_t nsats, uint8_t baseline_coords_type, int32_t baseline_a_mm, int32_t baseline_b_mm, int32_t baseline_c_mm, uint32_t accuracy, int32_t iar_num_hypotheses)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GPS2_RTK_LEN];
    _mav_put_uint32_t(buf, 0, time_last_baseline_ms);
    _mav_put_uint32_t(buf, 4, tow);
    _mav_put_int32_t(buf, 8, baseline_a_mm);
    _mav_put_int32_t(buf, 12, baseline_b_mm);
    _mav_put_int32_t(buf, 16, baseline_c_mm);
    _mav_put_uint32_t(buf, 20, accuracy);
    _mav_put_int32_t(buf, 24, iar_num_hypotheses);
    _mav_put_uint16_t(buf, 28, wn);
    _mav_put_uint8_t(buf, 30, rtk_receiver_id);
    _mav_put_uint8_t(buf, 31, rtk_health);
    _mav_put_uint8_t(buf, 32, rtk_rate);
    _mav_put_uint8_t(buf, 33, nsats);
    _mav_put_uint8_t(buf, 34, baseline_coords_type);

  