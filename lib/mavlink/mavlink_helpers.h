#pragma once

#include "string.h"
#include "checksum.h"
#include "mavlink_types.h"
#include "mavlink_conversions.h"
#include <stdio.h>

#ifndef MAVLINK_HELPER
#define MAVLINK_HELPER
#endif

#include "mavlink_sha256.h"

#ifdef MAVLINK_USE_CXX_NAM