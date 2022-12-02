#pragma once

// Common.h

// The purpose of this file is to improve the overall sanity of the other code
// by making compilers behave

#include <string>
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#ifndef __PX4_NUTTX
#include <sys/timeb.h>
#endif

#define SLR_ERROR0(A) SLR::PrintError(__FUNCTION__,__LINE__,A)
#define SLR_ERROR1(A,B) SLR::PrintError(__FUNCTION__,__LINE__,A,B)
#define SLR_ERROR2(A,B,C) SLR::PrintError(__FUNCTION__,__LINE__,A,B,C)
#define SLR_ERROR3(A,B,C,D) SLR::PrintError(__FUNCTION__,__LINE__,A,B,C,D)
#define SLR_ERROR4(A,B,C,D,E) SLR::PrintError(__FUNCTION__,__LINE__,A,B,C,D,E)
#define SLR_ERROR5(A,B,C,D,E,F) SLR::PrintError(__FUNCTION__,__LINE__,A,B,C,D,E,F)
#define SLR_ERROR6(A,B,C,D,E,F,G) SLR::PrintError(__FUNCTION__,__LINE__,A,B,C,D,E,F,G)

#define SLR_ERROR0S(S,A) SLR::PrintError(S,__LINE__,A)
#define SLR_ERROR1S(S,A,B) SLR::PrintError(S,__LINE__,A,B)
#define SLR_ERROR2S(S,A,B,C) SLR::PrintError(S,__LINE__,A,B,C)
#define SLR_ERROR3S(S,A,B,C,D) SLR::PrintError(S,__LINE__,A,B,C,D)
#define SLR_ERROR4S(S,A,B,C,D,E) SLR::PrintError(S,__LINE__,A,B,C,D,E)
#define SLR_ERROR5S(S,A,B,C,D,E,F) SLR::PrintError(S,__LINE__,A,B,C,D,E,F)
#define SLR_ERROR6S(S,A,B,C,D,E,F,G) SLR::PrintError(S,__LINE__,A,B,C,D,E,F,G)

#define SLR_WARNING0(A) SLR::PrintWarning(__FUNCTION__,__LINE__,A)
#define SLR_WARNING1(A,B) SLR::PrintWarning(__FUNCTION__,__LINE__,A,B)
#define SLR_WARNING2(A,B,C) SLR::PrintWarning(__FUNCTION__,__LINE__,A,B,C)
#define SLR_WARNING3(A,B,C,D) SLR::PrintWarning(__FUNCTION__,__LINE__