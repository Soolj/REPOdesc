
#pragma once
// MESSAGE SYS_STATUS PACKING

#define MAVLINK_MSG_ID_SYS_STATUS 1

MAVPACKED(
typedef struct __mavlink_sys_status_t {
 uint32_t onboard_control_sensors_present; /*< Bitmask showing which onboard controllers and sensors are present. Value of 0: not present. Value of 1: present. Indices defined by ENUM MAV_SYS_STATUS_SENSOR*/
 uint32_t onboard_control_sensors_enabled; /*< Bitmask showing which onboard controllers and sensors are enabled:  Value of 0: not enabled. Value of 1: enabled. Indices defined by ENUM MAV_SYS_STATUS_SENSOR*/
 uint32_t onboard_control_sensors_health; /*< Bitmask showing which onboard controllers and sensors are operational or have an error:  Value of 0: not enabled. Value of 1: enabled. Indices defined by ENUM MAV_SYS_STATUS_SENSOR*/
 uint16_t load; /*< Maximum usage in percent of the mainloop time, (0%: 0, 100%: 1000) should be always below 1000*/
 uint16_t voltage_battery; /*< Battery voltage, in millivolts (1 = 1 millivolt)*/
 int16_t current_battery; /*< Battery current, in 10*milliamperes (1 = 10 milliampere), -1: autopilot does not measure the current*/
 uint16_t drop_rate_comm; /*< Communication drops in percent, (0%: 0, 100%: 10'000), (UART, I2C, SPI, CAN), dropped packets on all links (packets that were corrupted on reception on the MAV)*/
 uint16_t errors_comm; /*< Communication errors (UART, I2C, SPI, CAN), dropped packets on all links (packets that were corrupted on reception on the MAV)*/
 uint16_t errors_count1; /*< Autopilot-specific errors*/
 uint16_t errors_count2; /*< Autopilot-specific errors*/
 uint16_t errors_count3; /*< Autopilot-specific errors*/
 uint16_t errors_count4; /*< Autopilot-specific errors*/
 int8_t battery_remaining; /*< Remaining battery energy: (0%: 0, 100%: 100), -1: autopilot estimate the remaining battery*/
}) mavlink_sys_status_t;

#define MAVLINK_MSG_ID_SYS_STATUS_LEN 31
#define MAVLINK_MSG_ID_SYS_STATUS_MIN_LEN 31
#define MAVLINK_MSG_ID_1_LEN 31
#define MAVLINK_MSG_ID_1_MIN_LEN 31

#define MAVLINK_MSG_ID_SYS_STATUS_CRC 124
#define MAVLINK_MSG_ID_1_CRC 124



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SYS_STATUS { \
    1, \
    "SYS_STATUS", \
    13, \
    {  { "onboard_control_sensors_present", "0x%04x", MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_sys_status_t, onboard_control_sensors_present) }, \
         { "onboard_control_sensors_enabled", "0x%04x", MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_sys_status_t, onboard_control_sensors_enabled) }, \
         { "onboard_control_sensors_health", "0x%04x", MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_sys_status_t, onboard_control_sensors_health) }, \
         { "load", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_sys_status_t, load) }, \
         { "voltage_battery", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_sys_status_t, voltage_battery) }, \
         { "current_battery", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_sys_status_t, current_battery) }, \
         { "battery_remaining", NULL, MAVLINK_TYPE_INT8_T, 0, 30, offsetof(mavlink_sys_status_t, battery_remaining) }, \
         { "drop_rate_comm", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_sys_status_t, drop_rate_comm) }, \
         { "errors_comm", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_sys_status_t, errors_comm) }, \
         { "errors_count1", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_sys_status_t, errors_count1) }, \
         { "errors_count2", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_sys_status_t, errors_count2) }, \
         { "errors_count3", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_sys_status_t, errors_count3) }, \
         { "errors_count4", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_sys_status_t, errors_count4) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SYS_STATUS { \
    "SYS_STATUS", \
    13, \
    {  { "onboard_control_sensors_present", "0x%04x", MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_sys_status_t, onboard_control_sensors_present) }, \
         { "onboard_control_sensors_enabled", "0x%04x", MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_sys_status_t, onboard_control_sensors_enabled) }, \
         { "onboard_control_sensors_health", "0x%04x", MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_sys_status_t, onboard_control_sensors_health) }, \
         { "load", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_sys_status_t, load) }, \
         { "voltage_battery", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_sys_status_t, voltage_battery) }, \
         { "current_battery", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_sys_status_t, current_battery) }, \
         { "battery_remaining", NULL, MAVLINK_TYPE_INT8_T, 0, 30, offsetof(mavlink_sys_status_t, battery_remaining) }, \
         { "drop_rate_comm", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_sys_status_t, drop_rate_comm) }, \
         { "errors_comm", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_sys_status_t, errors_comm) }, \
         { "errors_count1", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_sys_status_t, errors_count1) }, \
         { "errors_count2", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_sys_status_t, errors_count2) }, \
         { "errors_count3", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_sys_status_t, errors_count3) }, \
         { "errors_count4", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_sys_status_t, errors_count4) }, \
         } \
}
#endif

/**
 * @brief Pack a sys_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param onboard_control_sensors_present Bitmask showing which onboard controllers and sensors are present. Value of 0: not present. Value of 1: present. Indices defined by ENUM MAV_SYS_STATUS_SENSOR
 * @param onboard_control_sensors_enabled Bitmask showing which onboard controllers and sensors are enabled:  Value of 0: not enabled. Value of 1: enabled. Indices defined by ENUM MAV_SYS_STATUS_SENSOR
 * @param onboard_control_sensors_health Bitmask showing which onboard controllers and sensors are operational or have an error:  Value of 0: not enabled. Value of 1: enabled. Indices defined by ENUM MAV_SYS_STATUS_SENSOR
 * @param load Maximum usage in percent of the mainloop time, (0%: 0, 100%: 1000) should be always below 1000
 * @param voltage_battery Battery voltage, in millivolts (1 = 1 millivolt)
 * @param current_battery Battery current, in 10*milliamperes (1 = 10 milliampere), -1: autopilot does not measure the current
 * @param battery_remaining Remaining battery energy: (0%: 0, 100%: 100), -1: autopilot estimate the remaining battery
 * @param drop_rate_comm Communication drops in percent, (0%: 0, 100%: 10'000), (UART, I2C, SPI, CAN), dropped packets on all links (packets that were corrupted on reception on the MAV)
 * @param errors_comm Communication errors (UART, I2C, SPI, CAN), dropped packets on all links (packets that were corrupted on reception on the MAV)
 * @param errors_count1 Autopilot-specific errors
 * @param errors_count2 Autopilot-specific errors
 * @param errors_count3 Autopilot-specific errors
 * @param errors_count4 Autopilot-specific errors
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sys_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t onboard_control_sensors_present, uint32_t onboard_control_sensors_enabled, uint32_t onboard_control_sensors_health, uint16_t load, uint16_t voltage_battery, int16_t current_battery, int8_t battery_remaining, uint16_t drop_rate_comm, uint16_t errors_comm, uint16_t errors_count1, uint16_t errors_count2, uint16_t errors_count3, uint16_t errors_count4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYS_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, onboard_control_sensors_present);
    _mav_put_uint32_t(buf, 4, onboard_control_sensors_enabled);
    _mav_put_uint32_t(buf, 8, onboard_control_sensors_health);
    _mav_put_uint16_t(buf, 12, load);
    _mav_put_uint16_t(buf, 14, voltage_battery);
    _mav_put_int16_t(buf, 16, current_battery);
    _mav_put_uint16_t(buf, 18, drop_rate_comm);
    _mav_put_uint16_t(buf, 20, errors_comm);
    _mav_put_uint16_t(buf, 22, errors_count1);
    _mav_put_uint16_t(buf, 24, errors_count2);
    _mav_put_uint16_t(buf, 26, errors_count3);
    _mav_put_uint16_t(buf, 28, errors_count4);
    _mav_put_int8_t(buf, 30, battery_remaining);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SYS_STATUS_LEN);
#else
    mavlink_sys_status_t packet;
    packet.onboard_control_sensors_present = onboard_control_sensors_present;
    packet.onboard_control_sensors_enabled = onboard_control_sensors_enabled;
    packet.onboard_control_sensors_health = onboard_control_sensors_health;
    packet.load = load;
    packet.voltage_battery = voltage_battery;
    packet.current_battery = current_battery;
    packet.drop_rate_comm = drop_rate_comm;
    packet.errors_comm = errors_comm;
    packet.errors_count1 = errors_count1;
    packet.errors_count2 = errors_count2;
    packet.errors_count3 = errors_count3;
    packet.errors_count4 = errors_count4;
    packet.battery_remaining = battery_remaining;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SYS_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SYS_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SYS_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYS_STATUS_LEN, MAVLINK_MSG_ID_SYS_STATUS_CRC);
}

/**
 * @brief Pack a sys_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param onboard_control_sensors_present Bitmask showing which onboard controllers and sensors are present. Value of 0: not present. Value of 1: present. Indices defined by ENUM MAV_SYS_STATUS_SENSOR
 * @param onboard_control_sensors_enabled Bitmask showing which onboard controllers and sensors are enabled:  Value of 0: not enabled. Value of 1: enabled. Indices defined by ENUM MAV_SYS_STATUS_SENSOR
 * @param onboard_control_sensors_health Bitmask showing which onboard controllers and sensors are operational or have an error:  Value of 0: not enabled. Value of 1: enabled. Indices defined by ENUM MAV_SYS_STATUS_SENSOR
 * @param load Maximum usage in percent of the mainloop time, (0%: 0, 100%: 1000) should be always below 1000
 * @param voltage_battery Battery voltage, in millivolts (1 = 1 millivolt)
 * @param current_battery Battery current, in 10*milliamperes (1 = 10 milliampere), -1: autopilot does not measure the current
 * @param battery_remaining Remaining battery energy: (0%: 0, 100%: 100), -1: autopilot estimate the remaining battery
 * @param drop_rate_comm Communication drops in percent, (0%: 0, 100%: 10'000), (UART, I2C, SPI, CAN), dropped packets on all links (packets that were corrupted on reception on the MAV)
 * @param errors_comm Communication errors (UART, I2C, SPI, CAN), dropped packets on all links (packets that were corrupted on reception on the MAV)
 * @param errors_count1 Autopilot-specific errors
 * @param errors_count2 Autopilot-specific errors
 * @param errors_count3 Autopilot-specific errors
 * @param errors_count4 Autopilot-specific errors
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sys_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t onboard_control_sensors_present,uint32_t onboard_control_sensors_enabled,uint32_t onboard_control_sensors_health,uint16_t load,uint16_t voltage_battery,int16_t current_battery,int8_t battery_remaining,uint16_t drop_rate_comm,uint16_t errors_comm,uint16_t errors_count1,uint16_t errors_count2,uint16_t errors_count3,uint16_t errors_count4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYS_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, onboard_control_sensors_present);
    _mav_put_uint32_t(buf, 4, onboard_control_sensors_enabled);
    _mav_put_uint32_t(buf, 8, onboard_control_sensors_health);
    _mav_put_uint16_t(buf, 12, load);
    _mav_put_uint16_t(buf, 14, voltage_battery);
    _mav_put_int16_t(buf, 16, current_battery);
    _mav_put_uint16_t(buf, 18, drop_rate_comm);
    _mav_put_uint16_t(buf, 20, errors_comm);
    _mav_put_uint16_t(buf, 22, errors_count1);
    _mav_put_uint16_t(buf, 24, errors_count2);
    _mav_put_uint16_t(buf, 26, errors_count3);
    _mav_put_uint16_t(buf, 28, errors_count4);
    _mav_put_int8_t(buf, 30, battery_remaining);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SYS_STATUS_LEN);
#else
    mavlink_sys_status_t packet;
    packet.onboard_control_sensors_present = onboard_control_sensors_present;
    packet.onboard_control_sensors_enabled = onboard_control_sensors_enabled;
    packet.onboard_control_sensors_health = onboard_control_sensors_health;
    packet.load = load;
    packet.voltage_battery = voltage_battery;
    packet.current_battery = current_battery;
    packet.drop_rate_comm = drop_rate_comm;
    packet.errors_comm = errors_comm;
    packet.errors_count1 = errors_count1;
    packet.errors_count2 = errors_count2;
    packet.errors_count3 = errors_count3;
    packet.errors_count4 = errors_count4;
    packet.battery_remaining = battery_remaining;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SYS_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SYS_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SYS_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYS_STATUS_LEN, MAVLINK_MSG_ID_SYS_STATUS_CRC);
}

/**
 * @brief Encode a sys_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sys_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sys_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sys_status_t* sys_status)
{