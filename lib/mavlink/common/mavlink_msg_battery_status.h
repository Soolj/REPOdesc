#pragma once
// MESSAGE BATTERY_STATUS PACKING

#define MAVLINK_MSG_ID_BATTERY_STATUS 147

MAVPACKED(
typedef struct __mavlink_battery_status_t {
 int32_t current_consumed; /*< Consumed charge, in milliampere hours (1 = 1 mAh), -1: autopilot does not provide mAh consumption estimate*/
 int32_t energy_consumed; /*< Consumed energy, in HectoJoules (intergrated U*I*dt)  (1 = 100 Joule), -1: autopilot does not provide energy consumption estimate*/
 int16_t temperature; /*< Temperature of the battery in centi-degrees celsius. INT16_MAX for unknown temperature.*/
 uint16_t voltages[10]; /*< Battery voltage of cells, in millivolts (1 = 1 millivolt). Cells above the valid cell count for this battery should have the UINT16_MAX value.*/
 int16_t current_battery; /*< Battery current, in 10*milliamperes (1 = 10 milliampere), -1: autopilot does not measure the current*/
 uint8_t id; /*< Battery ID*/
 uint8_t battery_function; /*< Function of the battery*/
 uint8_t type; /*< Type (chemistry) of the battery*/
 int8_t battery_remaining; /*< Remaining battery energy: (0%: 0, 100%: 100), -1: autopilot does not estimate the remaining battery*/
}) mavlink_battery_status_t;

#define MAVLINK_MSG_ID_BATTERY_STATUS_LEN 36
#define MAVLINK_MSG_ID_BATTERY_STATUS_MIN_LEN 36
#define MAVLINK_MSG_ID_147_LEN 36
#define MAVLINK_MSG_ID_147_MIN_LEN 36

#define MAVLINK_MSG_ID_BATTERY_STATUS_CRC 154
#define MAVLINK_MSG_ID_147_CRC 154

#define MAVLINK_MSG_BATTERY_STATUS_FIELD_VOLTAGES_LEN 10

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_BATTERY_STATUS { \
    147, \
    "BATTERY_STATUS", \
    9, \
    {  { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_battery_status_t, id) }, \
         { "battery_function", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_battery_status_t, battery_function) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_battery_status_t, type) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_battery_status_t, temperature) }, \
         { "voltages", NULL, MAVLINK_TYPE_UINT16_T, 10, 10, offsetof(mavlink_battery_status_t, voltages) }, \
         { "current_battery", NULL, MAVLINK_TYPE_INT16_T, 0, 30, offsetof(mavlink_battery_status_t, current_battery) }, \
         { "current_consumed", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_battery_status_t, current_consumed) }, \
         { "energy_consumed", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_battery_status_t, energy_consumed) }, \
         { "battery_remaining", NULL, MAVLINK_TYPE_INT8_T, 0, 35, offsetof(mavlink_battery_status_t, battery_remaining) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_BATTERY_STATUS { \
    "BATTERY_STATUS", \
    9, \
    {  { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_battery_status_t, id) }, \
         { "battery_function", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_battery_status_t, battery_function) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_battery_status_t, type) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_battery_status_t, temperature) }, \
         { "voltages", NULL, MAVLINK_TYPE_UINT16_T, 10, 10, offsetof(mavlink_battery_status_t, voltages) }, \
         { "current_battery", NULL, MAVLINK_TYPE_INT16_T, 0, 30, offsetof(mavlink_battery_status_t, current_battery) }, \
         { "current_consumed", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_battery_status_t, current_consumed) }, \
         { "energy_consumed", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_battery_status_t, energy_consumed) }, \
         { "battery_remaining", NULL, MAVLINK_TYPE_INT8_T, 0, 35, offsetof(mavlink_battery_status_t, battery_remaining) }, \
         } \
}
#endif

/**
 * @brief Pack a battery_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param id Battery ID
 * @param battery_function Function of the battery
 * @param type Type (chemistry) of the battery
 * @param temperature Temperature of the battery in centi-degrees celsius. INT16_MAX for unknown temperature.
 * @param voltages Battery voltage of cells, in millivolts (1 = 1 millivolt). Cells above the valid cell count for this battery should have the UINT16_MAX value.
 * @param current_battery Battery current, in 10*milliamperes (1 = 10 milliampere), -1: autopilot does not measure the current
 * @param current_consumed Consumed charge, in milliampere hours (1 = 1 mAh), -1: autopilot does not provide mAh consumption estimate
 * @param energy_consumed Consumed energy, in HectoJoules (intergrated U*I*dt)  (1 = 100 Joule), -1: autopilot does not provide energy consumption estimate
 * @param battery_remaining Remaining battery energy: (0%: 0, 100%: 100), -1: autopilot does not estimate the remaining battery
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_battery_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t id, uint8_t battery_function, uint8_t type, int16_t temperature, const uint16_t *voltages, int16_t current_battery, int32_t current_consumed, int32_t energy_consumed, int8_t battery_remaining)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BATTERY_STATUS_LEN];
    _mav_put_int32_t(buf, 0, current_consumed);
    _mav_put_int32_t(buf, 4, energy_consumed);
    _mav_put_int16_t(buf, 8, temperature);
    _mav_put_int16_t(buf, 30, current_battery);
    _mav_put_uint8_t(buf, 32, id);
    _mav_put_uint8_t(buf, 33, battery_function);
    _mav_put_uint8_t(buf, 34, type);
    _mav_put_int8_t(buf, 35, battery_remaining);
    _mav_put_uint16_t_array(buf, 10, voltages, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BATTERY_STATUS_LEN);
#else
    mavlink_battery_status_t packet;
    packet.current_consumed = current_consumed;
    packet.energy_consumed = energy_consumed;
    packet.temperature = temperature;
    packet.current_battery = current_battery;
    packet.id = id;
    packet.battery_function = battery_function;
    packet.type = type;
    packet.battery_remaining = battery_remaining;
    mav_array_memcpy(packet.voltages, voltages, sizeof(uint16_t)*10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BATTERY_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BATTERY_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BATTERY_STATUS_MIN_LEN, MAVLINK_MSG_ID_BATTERY_STATUS_LEN, MAVLINK_MSG_ID_BATTERY_STATUS_CRC);
}

/**
 * @brief Pack a battery_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param id Battery ID
 * @param battery_function Function of the battery
 * @param type Type (chemistry) of the battery
 * @param temperature Temperature of the battery in centi-degrees celsius. INT16_MAX for unknown temperature.
 * @param voltages Battery voltage of cells, in millivolts (1 = 1 millivolt). Cells above the valid cell count for this battery should have the UINT16_MAX value.
 * @param current_battery Battery current, in 10*milliamperes (1 = 10 milliampere), -1: autopilot does not measure the current
 * @param current_consumed Consumed charge, in milliampere hours (1 = 1 mAh), -1: autopilot does not provide mAh consumption estimate
 * @param energy_consumed Consumed energy, in HectoJoules (intergrated U*I*dt)  (1 = 100 Joule), -1: autopilot does not provide energy consumption estimate
 * @param battery_remaining Remaining battery energy: (0%: 0, 100%: 100), -1: autopilot does not estimate the remaining battery
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_battery_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t id,uint8_t battery_function,uint8_t type,int16_t temperature,const uint16_t *voltages,int16_t current_battery,int32_t current_consumed,int32_t energy_consumed,int8_t battery_remaining)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BATTERY_STATUS_LEN];
    _mav_put_int32_t(buf, 0, current_consumed);
    _mav_put_int32_t(buf, 4, energy_consumed);
    _mav_put_int16_t(buf, 8, temperature);
    _mav_put_int16_t(buf, 30, current_battery);
    _mav_put_uint8_t(buf, 32, id);
    _mav_put_uint8_t(buf, 33, battery_function);
    _mav_put_uint8_t(buf, 34, type);
    _mav_put_int8_t(buf, 35, battery_remaining);
    _mav_put_uint16_t_array(buf, 10, voltages, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BATTERY_STATUS_LEN);
#else
    mavlink_battery_status_t packet;
    packet.current_consumed = current_consumed;
    packet.energy_consumed = energy_consumed;
    packet.temperature = temperature;
    packet.current_battery = current_battery;
    packet.id = id;
    packet.battery_function = battery_function;
    packet.type = type;
    packet.battery_remaining = battery_remaining;
    mav_array_memcpy(packet.voltages, voltages, sizeof(uint16_t)*10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BATTERY_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BATTERY_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BATTERY_STATUS_MIN_LEN, MAVLINK_MSG_ID_BATTERY_STATUS_LEN, MAVLINK_MSG_ID_BATTERY_STATUS_CRC);
}

/**
 * @brief Encode a battery_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param battery_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_battery_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_battery_status_t* battery_status)
{
    return mavlink_msg_battery_status_pack(system_id, component_id, msg, battery_status->id, battery_status->battery_function, battery_status->type, battery_status->temperature, battery_status->voltages, battery_status->current_battery, battery_status->current_consumed, battery_status->energy_consumed, battery_status->battery_remaining);
}

/**
 * @brief Encode a battery_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param battery_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_battery_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_battery_status_t* battery_status)
{
    return mavlink_msg_battery_status_pack_chan(system_id, component_id, chan, msg, battery_status->id, battery_status->battery_function, battery_status->type, battery_status->temperature, battery_status->voltages, battery_status->current_battery, battery_status->current_consumed, battery_status->energy_consumed, battery_status->battery_remaining);
}

/**
 * @brief Send a battery_status message
 * @param chan MAVLink channel to send the message
 *
 * @param id Battery ID
 * @param battery_function Function of the battery
 * @param type Type (chemistry) of the battery
 * @param temperature Temperature of the battery in centi-degrees celsius. INT16_MAX for unknown temperature.
 * @param voltages Battery voltage of cells, in millivolts (1 = 1 millivolt). Cells above the valid cell count for this battery should have the UINT16_MAX value.
 * @param current_battery Battery current, in 10*milliamperes (1 = 10 milliampere), -1: autopilot does not measure the current
 * @param current_consumed Consumed charge, in milliampere hours (1 = 1 mAh), -1: autopilot does not provide mAh consumption estimate
 * @param energy_consumed Consumed energy, in HectoJoules (intergrated U*I*dt)  (1 = 100 Joule), -1: autopilot does not provide energy consumption estimate
 * @param battery_remaining Remaining battery energy: (0%: 0, 100%: 100), -1: autopilot does not estimate the remaining battery
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_battery_status_send(mavlink_channel_t chan, uint8_t id, uint8_t battery_function, uint8_t type, int16_t temperature, const uint16_t *voltages, int16_t current_battery, int32_t current_consumed, int32_t energy_consumed, int8_t battery_remaining)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BATTERY_STATUS_LEN];
    _mav_put_int32_t(buf, 0, current_consumed);
    _mav_put_int32_t(buf, 4, energy_consumed);
    _mav_put_int16_t(buf, 8, temperature);
    _mav_put_int16_t(buf, 30, current_battery);
    _mav_put_uint8_t(buf, 32, id);
    _mav_put_uint8_t(buf, 33, battery_function);
    _mav_put_uint8_t(buf, 34, type);
    _mav_put_int8_t(buf, 35, battery_remaining);
    _mav_put_uint16_t_array(buf, 10, voltages, 10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BATTERY_STATUS, buf, MAVLINK_MSG_ID_BATTERY_STATUS_MIN_LEN, MAVLINK_MSG_ID_BATTERY_STATUS_LEN, MAVLINK_MSG_ID_BATTERY_STATUS_CRC);
#else
    mavlink_battery_status_t packet;
    packet.current_consumed = current_consumed;
    packet.energy_consumed = energy_consumed;
    packet.temperature = temperature;
    packet.current_battery = current_battery;
    packet.id = id;
    packet.battery_function = battery_function;
    packet.type = type;
    packet.battery_remainin