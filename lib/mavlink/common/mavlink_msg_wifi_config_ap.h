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
 * @param system_id ID of 