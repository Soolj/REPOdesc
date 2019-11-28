#pragma once
// MESSAGE DATA_TRANSMISSION_HANDSHAKE PACKING

#define MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE 130

MAVPACKED(
typedef struct __mavlink_data_transmission_handshake_t {
 uint32_t size; /*< total data size in bytes (set on ACK only)*/
 uint16_t width; /*< Width of a matrix or image*/
 uint16_t height; /*< Height of a matrix or image*/
 uint16_t packets; /*< number of packets beeing sent (set on ACK only)*/
 uint8_t type; /*< type of requested/acknowledged data (as defined in ENUM DATA_TYPES in mavlink/include/mavlink_types.h)*/
 uint8_t payload; /*< payload size per packet (normally 253 byte, see DATA field size in message ENCAPSULATED_DATA) (set on ACK only)*/
 uint8_t jpg_quality; /*< JPEG quality out of [1,100]*/
}) mavlink_data_transmission_handshake_t;

#define MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE_LEN 13
#define MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE_MIN_LEN 13
#define MAVLINK_MSG_ID_130_LEN 13
#define MAVLINK_M