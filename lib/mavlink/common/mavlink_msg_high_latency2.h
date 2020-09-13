#pragma once
// MESSAGE HIGH_LATENCY2 PACKING

#define MAVLINK_MSG_ID_HIGH_LATENCY2 235

MAVPACKED(
typedef struct __mavlink_high_latency2_t {
 uint32_t timestamp; /*< Timestamp (milliseconds since boot or Unix epoch)*/
 int32_t latitude; /*< Latitude, expressed as degrees * 1E7*/
 int32_t longitude; /*< Longitude, expressed as degrees * 1E7*/
 uint16_t custom_mode; /*< A bitfield for use for autopilot-specific flags (2 byte version).*/
 int16_t altitude; /*< Altitude above mean sea level*/
 int16_t target_altitude; /*< Altitude setpoint*