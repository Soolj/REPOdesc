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

#define MAVLINK_MSG_ID_HIGH_LATENCY2_CRC 179
#define MAVLINK_MSG_ID_235_CRC 179



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_HIGH_LATENCY2 { \
    235, \
    "HIGH_LATENCY2", \
    27, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_high_latency2_t, timestamp) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_high_latency2_t, type) }, \
         { "autopilot", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_high_latency2_t, autopilot) }, \
         { "custom_mode", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_high_latency2_t, custom_mode) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_high_latency2_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_high_latency2_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_high_latency2_t, altitude) }, \
         { "target_altitude", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_high_latency2_t, target_altitude) }, \
         { "heading", NULL, MAVLINK_TYPE_UINT8_T, 0, 26, offsetof(mavlink_high_latency2_t, heading) }, \
         { "target_heading", NULL, MAVLINK_TYPE_UINT8_T, 0, 27, offsetof(mavlink_high_latency2_t, target_heading) }, \
         { "target_distance", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_high_latency2_t, target_distance) }, \
         { "throttle", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_high_latency2_t, throttle) }, \
         { "airspeed", NULL, MAVLINK_TYPE_UINT8_T, 0, 29, offsetof(mavlink_high_latency2_t, airspeed) }, \
         { "airspeed_sp", NULL, MAVLINK_TYPE_UINT8_T, 0, 30, offsetof(mavlink_high_latency2_t, airspeed_sp) }, \
         { "groundspeed", NULL, MAVLINK_TYPE_UINT8_T, 0, 31, offsetof(mavlink_high_latency2_t, groundspeed) }, \
         { "windspeed", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_high_latency2_t, windspeed) }, \
         { "wind_heading", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_high_latency2_t, wind_heading) }, \
         { "eph", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_high_latency2_t, eph) }, \
         { "epv", NULL, MAVLINK_TYPE_UINT8_T, 0, 35, offsetof(mavlink_high_latency2_t, epv) }, \
         { "temperature_air", NULL, MAVLINK_TYPE_INT8_T, 0, 36, offsetof(mavlink_high_latency2_t, temperature_air) }, \
         { "climb_rate", NULL, MAVLINK_TYPE_INT8_T, 0, 37, offsetof(mavlink_high_latency2_t, climb_rate) }, \
         { "battery", NULL, MAVLINK_TYPE_INT8_T, 0, 38, offsetof(mavlink_high_latency2_t, battery) }, \
         { "wp_num", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_high_latency2_t, wp_num) }, \
         { "failure_flags", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_high_latency2_t, failure_flags) }, \
         { "custom0", NULL, MAVLINK_TYPE_INT8_T, 0, 39, offsetof(mavlink_high_latency2_t, custom0) }, \
         { "custom1", NULL, MAVLINK_TYPE_INT8_T, 0, 40, offsetof(mavlink_high_latency2_t, custom1) }, \
         { "custom2", NULL, MAVLINK_TYPE_INT8_T, 0, 41, offsetof(mavlink_high_latency2_t, custom2) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_HIGH_LATENCY2 { \
    "HIGH_LATENCY2", \
    27, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_high_latency2_t, timestamp) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_high_latency2_t, type) }, \
         { "autopilot", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_high_latency2_t, autopilot) }, \
         { "custom_mode", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_high_latency2_t, custom_mode) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_high_latency2_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_high_latency2_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_high_latency2_t, altitude) }, \
         { "target_altitude", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_high_latency2_t, target_altitude) }, \
         { "heading", NULL, MAVLINK_TYPE_UINT8_T, 0, 26, offsetof(mavlink_high_latency2_t, heading) }, \
         { "target_heading", NULL, MAVLINK_TYPE_UINT8_T, 0, 27, offsetof(mavlink_high_latency2_t, target_heading) }, \
         { "target_distance", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_high_latency2_t, target_distance) }, \
         { "throttle", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_high_latency2_t, throttle) }, \
         { "airspeed", NULL, MAVLINK_TYPE_UINT8_T, 0, 29, offsetof(mavlink_high_latency2_t, airspeed) }, \
         { "airspeed_sp", NULL, MAVLINK_TYPE_UINT8_T, 0, 30, offsetof(mavlink_high_latency2_t, airspeed_sp) }, \
         { "groundspeed", NULL, MAVLINK_TYPE_UINT8_T, 0, 31, offsetof(mavlink_high_latency2_t, groundspeed) }, \
         { "windspeed", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_high_latency2_t, windspeed) }, \
         { "wind_heading", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_high_latency2_t, wind_heading) }, \
         { "eph", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_high_latency2_t, eph) }, \
         { "epv", NULL, MAVLINK_TYPE_UINT8_T, 0, 35, offsetof(mavlink_high_latency2_t, epv) }, \
         { "temperature_air", NULL, MAVLINK_TYPE_INT8_T, 0, 36, offsetof(mavlink_high_latency2_t, temperature_air) }, \
         { "climb_rate", NULL, MAVLINK_TYPE_INT8_T, 0, 37, offsetof(mavlink_high_latency2_t, climb_rate) }, \
         { "battery", NULL, MAVLINK_TYPE_INT8_T, 0, 38, offsetof(mavlink_high_latency2_t, battery) }, \
         { "wp_num", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_high_latency2_t, wp_num) }, \
         { "failure_flags", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_high_latency2_t, failure_flags) }, \
         { "custom0", NULL, MAVLINK_TYPE_INT8_T, 0, 39, offsetof(mavlink_high_latency2_t, custom0) }, \
         { "custom1", NULL, MAVLINK_TYPE_INT8_T, 0, 40, offsetof(mavlink_high_latency2_t, custom1) }, \
         { "custom2", NULL, MAVLINK_TYPE_INT8_T, 0, 41, offsetof(mavlink_high_latency2_t, custom2) }, \
         } \
}
#endif

/**
 * @brief Pack a high_latency2 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp Timestamp (milliseconds since boot or Unix epoch)
 * @param type Type of the MAV (quadrotor, helicopter, etc., up to 15 types, defined in MAV_TYPE ENUM)
 * @param autopilot Autopilot type / class. defined in MAV_AUTOPILOT ENUM
 * @param custom_mode A bitfield for use for autopilot-specific flags (2 byte version).
 * @param latitude Latitude, expressed as degrees * 1E7
 * @param longitude Longitude, expressed as degrees * 1E7
 * @param altitude Altitude above mean sea level
 * @param target_altitude Altitude setpoint
 * @param heading Heading (degrees / 2)
 * @param target_heading Heading setpoint (degrees / 2)
 * @param target_distance Distance to target waypoint or position (meters / 10)
 * @param throttle Throttle (percentage)
 * @param airspeed Airspeed (m/s * 5)
 * @param airspeed_sp Airspeed setpoint (m/s * 5)
 * @param groundspeed Groundspeed (m/s * 5)
 * @param windspeed Windspeed (m/s * 5)
 * @param wind_heading Wind heading (deg / 2)
 * @param eph Maximum error horizontal position since last message (m * 10)
 * @param epv Maximum error vertical position since last message (m * 10)
 * @param temperature_air Air temperature (degrees C) from airspeed sensor
 * @param climb_rate Maximum climb rate magnitude since last message (m/s * 10)
 * @param battery Battery (percentage, -1 for DNU)
 * @param wp_num Current waypoint number
 * @param failure_flags Indicates failures as defined in HL_FAILURE_FLAG ENUM. 
 * @param custom0 Field for custom payload.
 * @param custom1 Field for custom payload.
 * @param custom2 Field for custom payload.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_high_latency2_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t timestamp, uint8_t type, uint8_t autopilot, uint16_t custom_mode, int32_t latitude, int32_t longitude, int16_t altitude, int16_t target_altitude, uint8_t heading, uint8_t target_heading, uint16_t target_distance, uint8_t throttle, uint8_t airspeed, uint8_t airspeed_sp, uint8_t groundspeed, uint8_t windspeed, uint8_t wind_heading, uint8_t eph, uint8_t epv, int8_t temperature_air, int8_t climb_rate, int8_t battery, uint16_t wp_num, uint16_t failure_flags, int8_t custom0, int8_t custom1, int8_t custom2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HIGH_LATENCY2_LEN];
    _mav_put_uint32_t(buf, 0, timestamp);
    _mav_put_int32_t(buf, 4, latitude);
    _mav_put_int32_t(buf, 8, longitude);
    _mav_put_uint16_t(buf, 12, custom_mode);
    _mav_put_int16_t(buf, 14, altitude);
    _mav_put_int16_t(buf, 16, target_altitude);
    _mav_put_uint16_t(buf, 18, target_distance);
    _mav_put_uint16_t(buf, 20, wp_num);
    _mav_put_uint16_t(buf, 22, failure_flags);
    _mav_put_uint8_t(buf, 24, type);
    _mav_put_uint8_t(buf, 25, autopilot);
    _mav_put_uint8_t(buf, 26, heading);
    _mav_put_uint8_t(buf, 27, target_heading);
    _mav_put_uint8_t(buf, 28, throttle);
    _mav_put_uint8_t(buf, 29, airspeed);
    _mav_put_uint8_t(buf, 30, airspeed_sp);
    _mav_put_uint8_t(buf, 31, groundspeed);
    _mav_put_uint8_t(buf, 32, windspeed);
    _mav_put_uint8_t(buf, 33, wind_heading);
    _mav_put_uint8_t(buf, 34, eph);
    _mav_put_uint8_t(buf, 35, epv);
    _mav_put_int8_t(buf, 36, temperature_air);
    _mav_put_int8_t(buf, 37, climb_rate);
    _mav_put_int8_t(buf, 38, battery);
    _mav_put_int8_t(buf, 39, custom0);
    _mav_put_int8_t(buf, 40, custom1);
    _mav_put_int8_t(buf, 41, custom2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HIGH_LATENCY2_LEN);
#else
    mavlink_high_latency2_t packet;
    packet.timestamp = timestamp;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.custom_mode = custom_mode;
    packet.altitude = altitude;
    packet.target_altitude = target_altitude;
    packet.target_distance = target_distance;
    packet.wp_num = wp_num;
    packet.failure_flags = failure_flags;
    packet.type = type;
    packet.autopilot = autopilot;
    packet.heading = heading;
    packet.target_heading = target_heading;
    packet.throttle = throttle;
    packet.airspeed = airspeed;
    packet.airspeed_sp = airspeed_sp;
    packet.groundspeed = groundspeed;
    packet.windspeed = windspeed;
    packet.wind_heading = wind_heading;
    packet.eph = eph;
    packet.epv = epv;
    packet.temperature_air = temperature_air;
    packet.climb_rate = climb_rate;
    packet.battery = battery;
    packet.custom0 = custom0;
    packet.custom1 = custom1;
    packet.custom2 = custom2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HIGH_LATENCY2_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HIGH_LATENCY2;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HIGH_LATENCY2_MIN_LEN, MAVLINK_MSG_ID_HIGH_LATENCY2_LEN, MAVLINK_MSG_ID_HIGH_LATENCY2_CRC);
}

/**
 * @brief Pack a high_latency2 message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp Timestamp (milliseconds since boot or Unix epoch)
 * @param type Type of the MAV (quadrotor, helicopter, etc., up to 15 types, defined in MAV_TYPE ENUM)
 * @param autopilot Autopilot type / class. defined in MAV_AUTOPILOT ENUM
 * @param custom_mode A bitfield for use for autopilot-specific flags (2 byte version).
 * @param latitude Latitude, expressed as degrees * 1E7
 * @param longitude Longitude, expressed as degrees * 1E7
 * @param altitude Altitude above mean sea level
 * @param target_altitude Altitude setpoint
 * @param heading Heading (degrees / 2)
 * @param target_heading Heading setpoint (degrees / 2)
 * @param target_distance Distance to target waypoint or position (meters / 10)
 * @param throttle Throttle (percentage)
 * @param airspeed Airspeed (m/s * 5)
 * @param airspeed_sp Airspeed setpoint (m/s * 5)
 * @param groundspeed Groundspeed (m/s * 5)
 * @param windspeed Windspeed (m/s 