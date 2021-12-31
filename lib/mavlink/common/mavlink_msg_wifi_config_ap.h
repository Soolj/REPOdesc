#pragma once
// MESSAGE WIFI_CONFIG_AP PACKING

#define MAVLINK_MSG_ID_WIFI_CONFIG_AP 299

MAVPACKED(
typedef struct __mavlink_wifi_config_ap_t {
 char ssid[32]; /*< Name of Wi-Fi network (SSID). Leave it blank to leave it unchanged.*/
 char password[64]; /*< Password. Leave it blank for an open AP.*/
}) mavlink_wifi_config_ap_t;

#define MAVLINK_MSG_ID_WIFI_CONFIG_AP_LEN 96
#define MAVLINK_MSG_ID_WIFI_CONFIG_AP_MIN_LEN 96
#define MAVLINK_MSG_ID_299_LEN 96
#define MAVLINK_MSG_ID_299_MIN_LEN 96

#define MAVLINK_MSG_ID_WIFI_CONFIG_AP_CRC 19
#define MAVLINK_MSG_ID_299_CRC 19

#define MAVLINK_MSG_WIFI_CONFIG_AP_FIELD_SSID_LEN 32
#define MAVLINK_MSG_WIFI_CONFIG_AP_FIELD_PASSWORD_LEN 64

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WIFI_CONFIG_AP { \
    299, \
    "WIFI_CONFIG_AP", \
    2, \
    {  { "ssid", NULL, MAVLINK_TYPE_CHAR, 32, 0, offsetof(mavlink_wifi_config_ap_t, ssid) }, \
         { "password", NULL, MAVLINK_TYPE_CHAR, 64, 32, offsetof(mavlink_wifi_config_ap_t, password) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WIFI_CONFIG_AP { \
    "WIFI_CONFIG_AP", \
    2, \
    {  { "ssid", NULL, MAVLINK_TYPE_CHAR, 32, 0, offsetof(mavlink_wifi_config_ap_t, ssid) }, \
         { "password", NULL, MAVLINK_TYPE_CHAR, 64, 32, offsetof(mavlink_wifi_config_ap_t, password) }, \
         } \
}
#endif

/**
 * @brief Pack a wifi_config_ap message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ssid Name of Wi-Fi network (SSID). Leave it blank to leave it unchanged.
 * @param password Password. Leave it blank for an open AP.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wifi_config_ap_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *ssid, const char *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIFI_CONFIG_AP_LEN];

    _mav_put_char_array(buf, 0, ssid, 32);
    _mav_put_char_array(buf, 32, password, 64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WIFI_CONFIG_AP_LEN);
#else
    mavlink_wifi_config_ap_t packet;

    mav_array_memcpy(packet.ssid, ssid, sizeof(char)*32);
    mav_array_memcpy(packet.password, password, sizeof(char)*64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WIFI_CONFIG_AP_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WIFI_CONFIG_AP;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WIFI_CONFIG_AP_MIN_LEN, MAVLINK_MSG_ID_WIFI_CONFIG_AP_LEN, MAVLINK_MSG_ID_WIFI_CONFIG_AP_CRC);
}

/**
 * @brief Pack a wifi_config_ap message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ssid Name of Wi-Fi network (SSID). Leave it blank to leave it unchanged.
 * @param password Password. Leave it blank for an open AP.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wifi_config_ap_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *ssid,const char *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIFI_CONFIG_AP_LEN];

    _mav_put_char_array(buf, 0, ssid, 32);
    _mav_put_char_array(buf, 32, password, 64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WIFI_CONFIG_AP_LEN);
#else
    mavlink_wifi_config_ap_t packet;

    mav_array_memcpy(packet.ssid, ssid, sizeof(char)*32);
    mav_array_memcpy(packet.password, password, sizeof(char)*64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WIFI_CONFIG_AP_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WIFI_CONFIG_AP;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WIFI_CONFIG_AP_MIN_LEN, MAVLINK_MSG_ID_WIFI_CONFIG_AP_LEN, MAVLINK_MSG_ID_WIFI_CONFIG_AP_CRC);
}

/**
 * @brief Encode a wifi_config_ap struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wifi_config_ap C-struct 