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
 int16_t target_altitude; /*< Altitude setpoint*/
 uint16_t target_distance; /*< Distance to target waypoint or position (meters / 10)*/
 uint16_t wp_num; /*< Current waypoint number*/
 uint16_t failure_flags; /*< Indicates failures as defined in HL_FAILURE_FLAG ENUM. */
 uint8_t type; /*< Type of the MAV (quadrotor, helicopter, etc., up to 15 types, defined in MAV_TYPE ENUM)*/
 uint8_t autopilot; /*< Autopilot type / class. defined in MAV_AUTOPILOT ENUM*/
 uint8_t heading; /*< Heading (degrees / 2)*/
 uint8_t target_heading; /*< Heading setpoint (degrees / 2)*/
 uint8_t throttle; /*< Throttle (percentage)*/
 uint8_t airspeed; /*< Airspeed (m/s * 5)*/
 uint8_t airspeed_sp; /*< Airspeed setpoint (m/s * 5)*/
 uint8_t groundspeed; /*< Groundspeed (m/s * 5)*/
 uint8_t windspeed; /*< Windspeed (m/s * 5)*/
 uint8_t wind_heading; /*< Wind heading (deg / 2)*/
 uint8_t eph; /*< Maximum error horizontal position since last message (m * 10)*/
 uint8_t epv; /*< Maximum error vertical position since last message (m * 10)*/
 int8_t temperature_air; /*< Air temperature (degrees C) from airspeed sensor*/
 int8_t climb_rate; /*< Maximum climb rate magnitude since last message (m/s * 10)*/
 int8_t battery; /*< Battery (percentage, -1 for DNU)*/
 int8_t custom0; /*< Field for custom payload.*/
 int8_t custom1; /*< Field for custom payload.*/
 int8_t custom2; /*< Field for custom payload.*/
}) mavlink_high_latency2_t;

#define MAVLINK_MSG_ID_HIGH_LATENCY2_LEN 42
#define MAVLINK_MSG_ID_HIGH_LATENCY2_MIN_LEN 42
#define MAVLINK_MSG_ID_235_LEN 42
#define MAVLINK_MSG_ID_235_MIN_LEN 42

#define MAVLINK_MSG_ID_HIGH_LATENCY2_CRC 1