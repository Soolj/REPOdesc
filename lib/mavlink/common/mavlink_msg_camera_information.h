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
#define MAVLINK_