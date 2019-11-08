#pragma once
// MESSAGE CAMERA_INFORMATION PACKING

#define MAVLINK_MSG_ID_CAMERA_INFORMATION 259

MAVPACKED(
typedef struct __mavlink_camera_information_t {
 uint32_t time_boot_ms; /*< Timestamp (milliseconds since system boot)*/
 uint32_t firmware_version; /*< Version of the camera firmware (v << 24 & 0xff = Dev, v << 16 & 0xff = Patch, v << 8 & 0xff = Minor, v & 0xff = Major)*/
 float focal_length; /*< Focal length in mm*/
 float sensor_size_h; /*< Image sensor size horizontal in mm*/
 float sensor_size_v; /*< Image sensor size vertical in mm*/
 uint32_t flags; /*< CAMERA_CAP_FLAGS enum flags (bitmap) describing camera capabilities.*/
 uint16_t resolution_h; /*< Image resolution in pixels horizontal*/
 uint16_t resolution_v; /*< Image resolution in pixels vertical*/
 uint16_t cam_definition_version; /*< Camera definition version (iteration)*/
 uint8_t vendor_name[32]; /*< Name of the camera vendor*/
 uint8_t model_name[32]; /*< Name of the camera model*/
 uint8_t lens_id; /*< Reserved for a lens ID*/
 char cam_definition_uri[140]; /*< Camera definition URI (if any, otherwise only basic functions will be available).*/
}) mavlink_camera_information_t;

#define MAVLINK_MSG_ID_CAMERA_INFORMATION_LEN 235
#define MAVLINK_MSG_ID_CAMERA_INFORMATION_MIN_LEN 235
#define MAVLINK_MSG_ID_259_LEN 235
#define MAVLINK_MSG_ID_259_MIN_LEN 235

#define MAVLINK_MSG_ID_CAMERA_INFORMATION_CRC 92
#define MAVLINK_MSG_ID_259_CRC 92

#define MAVLINK_MSG_CAMERA_INFORMATION_FIELD_VENDOR_NAME_LEN 32
#define MAVLINK_MSG_CAMERA_INFORMATION_FIELD_MODEL_NAME_LEN 32
#define MAVLINK_MSG_CAMERA_INFORMATION_FIELD_CAM_DEFINITION_URI_LEN 140

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CAMERA_INFORMATION { \
    259, \
    "CAMERA_INFORMATION", \
    13, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_camera_information_t, time_boot_ms) }, \
         { "vendor_name", NULL, MAVLINK_TYPE_UINT8_T, 32, 30, offsetof(mavlink_camera_information_t, vendor_name) }, \
         { "model_name", NULL, MAVLINK_TYPE_UINT8_T, 32, 62, offsetof(mavlink_camera_information_t, model_name) }, \
         { "firmware_version", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_camera_information_t, firmware_version) }, \
         { "focal_length", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_camera_information_t, focal_length) }, \
         { "sensor_size_h", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_camera_information_t, sensor_size_h) }, \
         { "sensor_size_v", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_camera_information_t, sensor_size_v) }, \
         { "resolution_h", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_camera_information_t, resolution_h) }, \
         { "resolution_v", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_camera_information_t, resolution_v) }, \
         { "lens_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 94, offsetof(mavlink_camera_information_t, lens_id) }, \
         { "flags", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_camera_information_t, flags) }, \
         { "cam_definition_version", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_camera_information_t, cam_definition_version) }, \
         { "cam_definition_uri", NULL, MAVLINK_TYPE_CHAR, 140, 95, offsetof(mavlink_camera_information_t, cam_definition_uri) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CAMERA_INFORMATION { \
    "CAMERA_INFORMATION", \
    13, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_camera_information_t, time_boot_ms) }, \
         { "vendor_name", NULL, MAVLINK_TYPE_UINT8_T, 32, 30, offsetof(mavlink_camera_information_t, vendor_name) }, \
         { "model_name", NULL, MAVLINK_TYPE_UINT8_T, 32, 62, offsetof(mavlink_camera_information_t, model_name) }, \
         { "firmware_version", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_camera_information_t, firmware_version) }, \
         { "focal_length", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_camera_information_t, focal_length) }, \
         { "sensor_size_h", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_camera_information_t, sensor_size_h) }, \
         { "sensor_size_v", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_camera_information_t, sensor_size_v) }, \
         { "resolution_h", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_camera_information_t, resolution_h) }, \
         { "resolution_v", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_camera_information_t, resolution_v) }, \
         { "lens_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 94, offsetof(mavlink_camera_information_t, lens_id) }, \
         { "flags", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_camera_information_t, flags) }, \
         { "cam_definition_version", NULL, MAVLINK_TYPE_UINT16