#ifndef NIDEVICE_GRPC_DEVICE_COMMON_TYPES_H
#define NIDEVICE_GRPC_DEVICE_COMMON_TYPES_H
#include <ivi.h>

// Note: these are defined with similar guards in several ivi-based driver
// headers that share these types.
#if !defined(_NIComplexNumber)
  #define _NIComplexNumber

  #pragma pack(push, 8)
typedef struct NIComplexNumber_struct {
  ViReal64 real;
  ViReal64 imaginary;
} NIComplexNumber;
  #pragma pack(pop)

#endif

#if !defined(_NIComplexNumberF32)
  #define _NIComplexNumberF32
typedef struct NIComplexNumberF32_struct {
  ViReal32 real;
  ViReal32 imaginary;
} NIComplexNumberF32;

#endif

#endif /* NIDEVICE_GRPC_DEVICE_COMMON_TYPES_H */
