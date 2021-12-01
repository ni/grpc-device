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

#ifndef _NI_int8_DEFINED_
#define _NI_int8_DEFINED_
	typedef signed char        int8;
#endif
#ifndef _NI_uInt8_DEFINED_
#define _NI_uInt8_DEFINED_
	typedef unsigned char      uInt8;
#endif
#ifndef _NI_int16_DEFINED_
#define _NI_int16_DEFINED_
	typedef signed short       int16;
#endif
#ifndef _NI_uInt16_DEFINED_
#define _NI_uInt16_DEFINED_
	typedef unsigned short     uInt16;
#endif
#ifndef _NI_int32_DEFINED_
#define _NI_int32_DEFINED_
#if ((defined(__GNUG__) || defined(__GNUC__)) && defined(__x86_64__))
	typedef signed int         int32;
#else
	typedef signed long        int32;
#endif
#endif
#ifndef _NI_uInt32_DEFINED_
#define _NI_uInt32_DEFINED_
#if ((defined(__GNUG__) || defined(__GNUC__)) && defined(__x86_64__))
	typedef unsigned int       uInt32;
#else
	typedef unsigned long      uInt32;
#endif
#endif
#ifndef _NI_float32_DEFINED_
#define _NI_float32_DEFINED_
	typedef float              float32;
#endif
#ifndef _NI_float64_DEFINED_
#define _NI_float64_DEFINED_
	typedef double             float64;
#endif
#ifndef _NI_int64_DEFINED_
#define _NI_int64_DEFINED_
#if defined(__linux__) || defined(__APPLE__)
	typedef long long int      int64;
#else
	typedef __int64            int64;
#endif
#endif
#ifndef _NI_uInt64_DEFINED_
#define _NI_uInt64_DEFINED_
#if defined(__linux__) || defined(__APPLE__)
	typedef unsigned long long uInt64;
#else
	typedef unsigned __int64   uInt64;
#endif
#endif

/*- Time Structures and Helpers ----------------------------------*/

// Please visit ni.com/info and enter the Info Code NI_BTF for more information
#ifndef CVITime_DECLARED
  #define CVITime_DECLARED
typedef struct CVITime {
  uInt64 lsb;
  uInt64 msb;
} CVITime;
#endif
#ifndef CVIAbsoluteTime_DECLARED
  #define CVIAbsoluteTime_DECLARED
typedef union CVIAbsoluteTime {
  CVITime cviTime;
  unsigned int u32Data[4];
} CVIAbsoluteTime;
#endif

#endif /* NIDEVICE_GRPC_DEVICE_COMMON_TYPES_H */
