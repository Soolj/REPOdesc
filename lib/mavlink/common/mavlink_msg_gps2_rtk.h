#pragma once
// MESSAGE GPS2_RTK PACKING

#define MAVLINK_MSG_ID_GPS2_RTK 128

MAVPACKED(
typedef struct __mavlink_gps2_rtk_t {
 uint32_t time_last_baseline_ms; /*< Time since boot of last baseline message received in ms.*/
 uint32_t tow; /*< GPS Time of Week of last baseline*/
 int32_t baseline_a_mm; /*< Current baseline in ECEF x or NED north component in mm.*/
 int32_t baseline_b_mm; /*< Current baseline in ECEF y or NED east component in mm.*/
 int32_t baseline_c_mm; /*< Current baseline