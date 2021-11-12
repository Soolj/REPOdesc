#pragma once
// MESSAGE UAVCAN_NODE_INFO PACKING

#define MAVLINK_MSG_ID_UAVCAN_NODE_INFO 311

MAVPACKED(
typedef struct __mavlink_uavcan_node_info_t {
 uint64_t time_usec; /*< Timestamp (microseconds since UNIX epoch or microseconds since system boot)*/
 uint32_t uptime_sec; /*< The number of seconds since the start-up of the node.*/
 uint32_t sw_vcs_commit; /*< Version control system (VCS) revision identifier (e.g. git short commit hash). Zero if unknown.*/
 char name[80]; /*< Node name string. For example, "sapog.px4.io".*/
 uint8_t hw_version_major; /*< Hardware major version number.*/
 uint8_t hw_version_minor; /*< Hardware minor version number.*/
 uint8_t hw_unique_id[16]; /*< Hardware unique 128-bit ID.*/
 uint8_t sw_version_major; /*< Software major version number.*/
 uint8_t sw_version_minor; /*< Software minor version number.*/
}) mavlink_uavcan_node_info_t;

#define MAVLINK_MSG_ID_UAVCAN_NODE_INFO_LEN 116
#define MAVLINK_MSG_ID_UAVCAN_NODE_INFO_MIN_LEN 116
#define MAVLINK_MSG_ID_311_LEN 116
#define MAVLINK_MSG_ID_311_MIN_LEN 116

#define MAVLINK_MSG_ID_UAVCAN_NODE_INFO_CRC 95
#define MAVLINK_MSG_ID_311_CRC 95

#define MAVLINK_MSG_UAVCAN_