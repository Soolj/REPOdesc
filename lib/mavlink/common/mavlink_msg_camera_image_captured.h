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
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_camera_image_captured_t, time_boot_ms) }, \
         { "time_utc", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_camera_image_captured_t, time_utc) }, \
         { "camera_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 48, offsetof(mavlink_camera_image_captured_t, camera_id) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_camera_image_captured_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_camera_image_captured_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_camera_image_captured_t, alt) }, \
         { "relative_alt", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_camera_image_captured_t, relative_alt) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 28, offsetof(mavlink_camera_image_captured_t, q) }, \
         { "image_index", NULL, MAVLINK_TYPE_INT32_T, 0, 44, offsetof(mavlink_camera_image_captured_t, image_index) }, \
         { "capture_result", NULL, MAVLINK_TYPE_INT8_T, 0, 49, offsetof(mavlink_camera_image_captured_t, capture_result) }, \
         { "file_url", NULL, MAVLINK_TYPE_CHAR, 205, 50, offsetof(mavlink_camera_image_captured_t, file_url) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CAMERA_IMAGE_CAPTURED { \
    "CAMERA_IMAGE_CAPTURED", \
    11, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_camera_image_captured_t, time_boot_ms) }, \
         { "time_utc", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_camera_image_captured_t, time_utc) }, \
         { "camera_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 48, offsetof(mavlink_camera_image_captured_t, camera_id) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_camera_image_captured_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_camera_image_captured_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_camera_image_captured_t, alt) }, \
         { "relative_alt", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_camera_image_captured_t, relative_alt) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 28, offsetof(mavlink_camera_image_captured_t, q) }, \
         { "image_index", NULL, MAVLINK_TYPE_INT32_T, 0, 44, offsetof(mavlink_camera_image_captured_t, image_index) }, \
         { "capture_result", NULL, MAVLINK_TYPE_INT8_T, 0, 49, offsetof(mavlink_camera_image_captured_t, capture_result) }, \
         { "file_url", NULL, MAVLINK_TYPE_CHAR, 205, 50, offsetof(mavlink_camera_image_captured_t, file_url) }, \
         } \
}
#endif

/**
 * @brief Pack a camera_image_captured message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms Timestamp (milliseconds since system boot)
 * @param time_utc Timestamp (microseconds since UNIX epoch) in UTC. 0 for unknown.
 * @param camera_id Camera ID (1 for first, 2 for second, etc.)
 * @param lat Latitude, expressed as degrees * 1E7 where image was taken
 * @param lon Longitude, expressed as degrees * 1E7 where capture was taken
 * @param alt Altitude in meters, expressed as * 1E3 (AMSL, not WGS84) where image was taken
 * @param relative_alt Altitude above ground in meters, expressed as * 1E3 where image was taken
 * @param q Quaternion of camera orientation (w, x, y, z order, zero-rotation is 0, 0, 0, 0)
 * @param image_index Zero based index of this image (image count since armed -1)
 * @param capture_result Boolean indicating success (1) or failure (0) while capturing this image.
 * @param file_url URL of image taken. Either local storage or http://foo.jpg if camera provides an HTTP interface.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_camera_image_captured_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint64_t time_utc, uint8_t camera_id, int32_t lat, int32_t lon, int32_t alt, int32_t relative_alt, const float *q, int32_t image_index, int8_t capture_result, const char *file_url)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CAMERA_IMAGE_CAPTURED_LEN];
    _mav_put_uint64_t(buf, 0, time_utc);
    _mav_put_uint32_t(buf, 8, time_boot_ms);
    _mav_put_int32_t(buf, 12, lat);
    _mav_put_int32_t(buf, 16, lon);
    _mav_put_int32_t(buf, 20, alt);
    _mav_put_int32_t(buf, 24, relative_alt);
    _mav_put_int32_t(buf, 44, image_index);
    _mav_put_uint8_t(buf, 48, camera_id);
    _mav_put_int8_t(buf, 49, capture_result);
    _mav_put_float_array(buf, 28, q, 4);
    _mav_put_char_array(buf, 50, file_url, 205);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CAMERA_IMAGE_CAPTURED_LEN);
#else
    mavlink_camera_image_captured_t packet;
    packet.time_utc = time_utc;
    packet.time_boot_ms = time_boot_ms;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.relative_alt = relative_alt;
    packet.image_index = image_index;
    packet.camera_id = camera_id;
    packet.capture_result = capture_result;
    mav_array_memcpy(packet.q, q, sizeof(float)*4);
    mav_array_memcpy(packet.file_url, file_url, sizeof(char)*205);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CAMERA_IMAGE_CAPTURED_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CAMERA_IMAGE_CAPTURED;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CAMERA_IMAGE_CAPTURED_MIN_LEN, MAVLINK_MSG_ID_CAMERA_IMAGE_CAPTURED_LEN, MAVLINK_MSG_ID_CAMERA_IMAGE_CAPTURED_CRC);
}

/**
 * @brief Pack a camera_image_captured message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms Timestamp (milliseconds since system boot)
 * @param time_utc Timestamp (microseconds since UNIX epoch) in UTC. 0 for unknown.
 * @param camera_id Camera ID (1 for first, 2 for second, etc.)
 * @param lat Latitude, expressed as degrees * 1E7 where image was taken
 * @param lon Longitude, expressed as degrees * 1E7 where capture was taken
 * @param alt Altitude in meters, expressed as * 1E3 (AMSL, not WGS84) where image was taken
 * @param relative_alt Altitude above ground in meters, expressed as * 1E3 where image was taken
 * @param q Quaternion of camera orientation (w, x, y, z order, zero-rotation is 0, 0, 0, 0)
 * @param image_index Zero based index of this image (image count since armed -1)
 * @param capture_result Boolean indicating success (1) or failure (0) while capturing this image.
 * @param file_url URL of image taken. Either local storage or http://foo.jpg if camera provides an HTTP interface.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_camera_image_captured_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint64_t time_utc,uint8_t camera_id,int32_t lat,int32_t lon,int32_t alt,int32_t relative_alt,const float *q,int32_t image_index,int8_t capture_result,const char *file_url)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CAMERA_IMAGE_CAPTURED_LEN];
    _mav_put_uint64_t(buf, 0, time_utc);
    _mav_put_uint32_t(buf, 8, time_boot_ms);
    _mav_put_int32_t(buf, 12, lat);
    _mav_put_int32_t(buf, 16, lon);
    _mav_put_int32_t(buf, 20, alt);
    _mav_put_int32_t(buf, 24, relative_alt);
    _mav_put_int32_t(buf, 44, image_index);
    _mav_put_uint8_t(buf, 48, camera_id);
    _mav_put_int8_t(buf, 49, capture_result);
    _mav_