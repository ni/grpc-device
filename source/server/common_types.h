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

#if !defined(_NIComplexI16)
  #define _NIComplexI16
typedef struct NIComplexI16_struct {
  ViInt16 real;
  ViInt16 imaginary;
} NIComplexI16;
#endif

// Structs from niRFmxInstr.h

#ifndef _NI_float64_DEFINED_
  #define _NI_float64_DEFINED_
typedef double float64;
#endif

#ifndef _NI_float32_DEFINED_
  #define _NI_float32_DEFINED_
typedef float float32;
#endif

#if !defined(_NIComplexSinglePrecision)
  #define _NIComplexSinglePrecision

  #ifndef _WIN64
    #pragma pack(push, 1)
  #endif

typedef struct NIComplexSingle_struct {
  float32 real;
  float32 imaginary;
} NIComplexSingle;

  #ifndef _WIN64
    #pragma pack(pop)
  #endif

#endif

#if !defined(_NIComplexDoublePrecision)
  #define _NIComplexDoublePrecision

  #ifndef _WIN64
    #pragma pack(push, 1)
  #endif

typedef struct NIComplexDouble_struct {
  float64 real;
  float64 imaginary;
} NIComplexDouble;

  #ifndef _WIN64
    #pragma pack(pop)
  #endif

#endif

#endif /* NIDEVICE_GRPC_DEVICE_COMMON_TYPES_H */
