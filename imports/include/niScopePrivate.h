#pragma once

#define IVI_DO_NOT_INCLUDE_VISA_HEADERS
#include "ivi.h"
#undef IVI_DO_NOT_INCLUDE_VISA_HEADERS
#include "niScope.h"

// explicitly tell the make files what functions to export
extern "C"
{
ViStatus _VI_FUNC niScope_GetStartTimestampInformation(
   ViSession vi,
   ViUInt32* sysTimeIn128BitsT1,
   ViUInt32* sysTimeIn128BitsT2,
   ViUInt32* sysTimeIn128BitsT3,
   ViUInt32* sysTimeIn128BitsT4,
   ViReal64* deviceTimeInAbsoluteTimeUnits);
}