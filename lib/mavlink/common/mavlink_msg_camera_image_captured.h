#pragma once
// MESSAGE CAMERA_IMAGE_CAPTURED PACKING

#define MAVLINK_MSG_ID_CAMERA_IMAGE_CAPTURED 263

MAVPACKED(
typedef struct __mavlink_camera_image_captured_t {
 uint64_t time_utc; /*< Timestamp (microseconds since UNIX epoch) in UTC. 0 for unknown.*/
 uint32_t time_boot_ms; /*< Timestamp (milliseconds since system boot)*/
 int32_t lat; /*< Latitude, expressed as degrees * 1E7 where image was taken*/
 int32_t lon; /*< Longitude, expressed as degrees * 1E7 where capture was taken*/
 int32_t alt; /*< Altitude in meters, expressed as * 1E3 (AMSL, not WGS84) where image was taken*/
 int32_t relative_alt; /*< Altitude above ground in meters, expressed as * 1E3 where image was taken*/
 float q[4]; /*< Quaternion of camera orientation (w, x, y, z order, zero-rotation is 0, 0, 0, 0)*/
 int32_t image_index; /*< Zero based index of this image (image count since armed -1)*/
 uint8_t camera_id; /*< Camera ID (1 for first, 2 for second, etc.)*/
 int8_t capture_result; /*< Boolean indicating success (1) or failure (0) while capturing this image.*/
 char file_url[205]; /*< URL of image taken. Either local storage or http://foo.jpg if camera provides an HTTP interface.*/
}) mavlink_camera_image_captured_t;

#define MAVLINK_MSG_ID_CAMERA_IMAGE_CAPTURED_LEN 255
#define MAVLINK_MSG_ID_CAMERA_IMAGE_CAPTURED_MIN_LEN 255
#define MAVLINK_MSG_ID_263_LEN 255
#define MAVLINK_MSG_ID_263_MIN_LEN 255

#define MAVLINK_MSG_ID_CAMERA_IMAGE_CAPTURED_CRC 133
#define MAVLINK_MSG_ID_263_CRC 133

#define MAVLINK_MSG_CAMERA_IMAGE_CAPTURED_FIELD_Q_LEN 4
#define MAVLINK_MSG_CAMERA_IMAGE_CAPTURED_FIELD_FILE_URL_LEN 205

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CAMERA_IMAGE_CAPTURED { \
    263, \
    "CAMERA_IMAGE_CAPTURED", \
    11, \
    {  { "time_boot_ms"