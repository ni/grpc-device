/*============================================================================*/
/*                               I V I                                        */
/*----------------------------------------------------------------------------*/
/*    Copyright (c) 1998-2020 National Instruments.  All Rights Reserved.     */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Title:       ivi.h                                                         */
/* Purpose:     Declarations for the Interchangeable Virtual Instruments      */
/*              (IVI) Library.                                                */
/*                                                                            */
/*============================================================================*/

/* This is intentionally placed outside of the include guard so that customers
 * can include driver headers in any order, even if some drivers do not want to
 * include VISA headers and others do.
 */
#ifndef IVI_DO_NOT_INCLUDE_VISA_HEADERS
#include "visa.h"
#endif

#ifndef IVI_HEADER
#define IVI_HEADER

#include "IviVisaType.h"

#ifdef _CVI_
#pragma EnableLibraryRuntimeChecking
#endif

#ifdef __cplusplus
    extern "C" {
#endif

/* Define IVI development environment */
#ifdef _VI_INT64_UINT64_DEFINED
#define _IVI_64BIT_ATTR_DEFINED_
#endif

#ifndef IviDll
#define IviDll
#endif

/*****************************************************************************/
/* Useful constants                                                 ======== */
/*****************************************************************************/
#define IVI_ENGINE_MAJOR_VERSION        20
#define IVI_ENGINE_MINOR_VERSION        0

#define IVI_VIREAL64_MAX        1.79769313486231570814527423732e+308  /* Maximum possible ViReal64 value */
#define IVI_VIREAL64_MAX_NEG    (-IVI_VIREAL64_MAX)                   /* Maximum possible negative ViReal64 value */

    /* Defined values for powerline frequency */
#define IVI_VAL_50_HERTZ                50.0
#define IVI_VAL_60_HERTZ                60.0
#define IVI_VAL_400_HERTZ               400.0

    /* Defined values for I/O Session Type    */
#define IVI_VAL_VISA_SESSION_TYPE       "VISA"
#define IVI_VAL_NI4882_SESSION_TYPE     "NI-488.2"
#define IVI_VAL_NIVXI_SESSION_TYPE      "NI-VXI"
#define IVI_VAL_NIDAQ_SESSION_TYPE      "NI-DAQ"
#define IVI_VAL_NISERIAL_SESSION_TYPE   "NI-Serial"

#define IVI_MAX_MESSAGE_LEN             255
#define IVI_MAX_MESSAGE_BUF_SIZE        (IVI_MAX_MESSAGE_LEN + 1)

#define IVI_VAL_NO_WAIT                 0
#define IVI_VAL_WAIT_FOREVER            IVI_VIREAL64_MAX

/* Duplicated from visa.h to ensure that visa.h is not a required header file */
#ifndef VI_TMO_INFINITE
#define VI_TMO_INFINITE             (0xFFFFFFFFUL)
#endif

#ifndef VI_TMO_IMMEDIATE
#define VI_TMO_IMMEDIATE            (0L)
#endif

#define IVI_VAL_MAX_TIME_INFINITE       VI_TMO_INFINITE
#define IVI_VAL_MAX_TIME_IMMEDIATE      VI_TMO_IMMEDIATE

#define IVI_MAX_PATHNAME_LEN    260   /* includes nul byte */
#define IVI_MAX_DRIVENAME_LEN     3   /* includes nul byte */
#define IVI_MAX_DIRNAME_LEN     256   /* includes nul byte */
#define IVI_MAX_FILENAME_LEN    256   /* includes nul byte */

/* Duplicated from visa.h to ensure that visa.h is not a required header file */
#define VI_ERROR_ALLOC            (_VI_ERROR+0x3FFF003CL)

/*****************************************************************************/

#define IVI_VAL_TYPE_NORMAL     0
#define IVI_VAL_TYPE_NAN        1
#define IVI_VAL_TYPE_PINF       2
#define IVI_VAL_TYPE_NINF       3

#define IVI_VAL_NAN             (*Ivi_GetPtrToSpecialViReal64Value(IVI_VAL_TYPE_NAN))
#define IVI_VAL_PINF            (*Ivi_GetPtrToSpecialViReal64Value(IVI_VAL_TYPE_PINF))
#define IVI_VAL_NINF            (*Ivi_GetPtrToSpecialViReal64Value(IVI_VAL_TYPE_NINF))

/*****************************************************************************/
/*  Interchange Warning Codes: The Ivi_GetNextInterchangeWarning function    */
/*  returns these values to identify the type of interchangeability warning. */
/*****************************************************************************/

#define IVI_VAL_NOT_IN_USER_SPECIFIED_STATE             1
#define IVI_VAL_READ_ONLY_ATTR_SET_BY_USER              2
#define IVI_VAL_ATTR_SET_TO_INSTR_SPECIFIC_VALUE        3
#define IVI_VAL_FAILURE_APPLYING_UNUSED_EXTENSION_VALUE 4
#define IVI_VAL_CLASS_DEFINED_INTERCHANGE_WARNING       5

/*****************************************************************************/

#ifndef _VI_CONST_STRING_DEFINED
typedef const ViChar * ViConstString;
#define _VI_CONST_STRING_DEFINED
#endif

/*****************************************************************************/
/*= Typedefs and related constants for the range tables             ======== */
/*****************************************************************************/

/* Defined values for the type of IviRangeTable */
#define IVI_VAL_DISCRETE            0       /* Discrete set - discreteOrMinValue, and cmdString (or cmdValue) fields used */
#define IVI_VAL_RANGED              1       /* Ranged value - discreteOrMinValue, maxValue, and cmdString (or cmdValue) fields used */
#define IVI_VAL_COERCED             2       /* Coerced value - discreteOrMinValue, maxValue, coercedValue, and cmdString (or cmdValue) fields used */

typedef struct      /* IviRangeTable contains an array of IviRangeTableEntry structures */
{
    ViReal64     discreteOrMinValue;
    ViReal64     maxValue;
    ViReal64     coercedValue;
    ViString     cmdString;          /* optional */
    ViInt32      cmdValue;           /* optional */
} IviRangeTableEntry;

#ifdef _IVI_64BIT_ATTR_DEFINED_
typedef struct      /* IviRangeTable contains an array of IviRangeTableEntry structures */
{
    ViInt64     discreteOrMinValue;
    ViInt64     maxValue;
    ViInt64     coercedValue;
    ViString    cmdString;          /* optional */
    ViInt32     cmdValue;           /* optional */
} IviRangeTableEntryViInt64;
#endif

typedef struct
    {
    ViInt32                     type;
    ViBoolean                   hasMin;
    ViBoolean                   hasMax;
    /* The hasMin and hasMax fields are used by the                      */
    /* Ivi_GetAttrMinMaxViInt32 and Ivi_GetAttrMinMaxViReal64 functions  */
    /* to determine whether they can calculate the minimum and maximum   */
    /* values that the instrument implements for an attribute.           */
    /* They are NOT used to indicate the inclusion or exclusion of the   */
    /* boundary value in the range                                       */
    ViString                    customInfo;
    void*                       rangeValues;
    /* the end of rangeValues[] is marked by the entry  */
    /* IVI_RANGE_TABLE_LAST_ENTRY                       */
    /*                                                  */
    } IviRangeTable;

typedef IviRangeTable*  IviRangeTablePtr;

typedef void* IviConfigStoreHandle;

#define IVI_RANGE_TABLE_END_STRING      ((ViString)(-1))  /* The value for the command string of the last entry in an IviRangeTable */
#define IVI_RANGE_TABLE_LAST_ENTRY      VI_NULL, VI_NULL, VI_NULL, IVI_RANGE_TABLE_END_STRING, VI_NULL  /* Marks the last entry in an IviRangeTable */

/*****************************************************************************/
/*= Typedefs for string-value tables.                              ========= */
/*****************************************************************************/
typedef struct
    {
    ViInt32     value;
    ViString    string;
    } IviStringValueEntry;

typedef IviStringValueEntry IviStringValueTable[];

/*****************************************************************************/
/*= Typedef and related constants for the IVI attribute flags.     ========= */
/*= The flags determine how the attributes operate.                ========= */
/*****************************************************************************/
typedef ViInt32 IviAttrFlags;

#define IVI_VAL_NOT_SUPPORTED                (1L << 0)  /* attribute automatically returns IVI_ERROR_ATTRIBUTE_NOT_SUPPORTED when Set/Get/Checked/Invalidated */
#define IVI_VAL_NOT_READABLE                 (1L << 1)  /* attribute cannot be Got */
#define IVI_VAL_NOT_WRITABLE                 (1L << 2)  /* attribute cannot be Set */
#define IVI_VAL_NOT_USER_READABLE            (1L << 3)  /* attribute cannot be Got by end-user */
#define IVI_VAL_NOT_USER_WRITABLE            (1L << 4)  /* attribute cannot be Set by end-user */
#define IVI_VAL_NEVER_CACHE                  (1L << 5)  /* always write/read to set/get attribute, i.e., never use a cached value, regardless of the state of IVI_ATTR_CACHE */
#define IVI_VAL_ALWAYS_CACHE                 (1L << 6)  /* specifies to always cache the value, regardless of the state of IVI_ATTR_CACHE */
#define IVI_VAL_NO_DEFERRED_UPDATE           (1L << 7)  /* always write the attribute immediately when it is set */
#define IVI_VAL_DONT_RETURN_DEFERRED_VALUE   (1L << 8)  /* don't return a set value that hasn't been updated to the instrument, return the instrument's current value */
#define IVI_VAL_FLUSH_ON_WRITE               (1L << 9)  /* send IVI_MSG_FLUSH to the BufferIOCallback (which by default calls viFlush) after the write callback */
#define IVI_VAL_MULTI_CHANNEL                (1L << 10) /* specified when the attribute is added.  If set, the attribute has a separate value for each channel */
#define IVI_VAL_COERCEABLE_ONLY_BY_INSTR     (1L << 11) /* specifies that the instrument coerces the attribue value in a way that the driver cannot anticipate in software.  Do NOT use this flag UNLESS ABSOLUTELY NECESSARY !!! */
#define IVI_VAL_WAIT_FOR_OPC_BEFORE_READS    (1L << 12) /* specifies to wait for operation complete before reads */
#define IVI_VAL_WAIT_FOR_OPC_AFTER_WRITES    (1L << 13) /* specifies to wait for operation complete after writes */
#define IVI_VAL_USE_CALLBACKS_FOR_SIMULATION (1L << 14) /* specifies to call the read and write callbacks even in simulation mode */
#define IVI_VAL_DONT_CHECK_STATUS            (1L << 15) /* specifies to not call the checkStatus callback even when IVI_ATTR_QUERY_INSTR_STATUS is VI_TRUE */

#define IVI_VAL_HIDDEN     (IVI_VAL_NOT_USER_READABLE | IVI_VAL_NOT_USER_WRITABLE)

/*****************************************************************************/
/*= Constants for optionFlags argument to Set/Check/GetAttribute functions ==*/
/*****************************************************************************/
#define IVI_VAL_DIRECT_USER_CALL            (1<<0)  /* applies to Set/Check/Get;  if 1, then:  the IVI_VAL_NOT_USER_READABLE/WRITEABLE flags can apply,                                                   */
                                                    /* and the engine automatically checks status on a Set if IVI_ATTR_QUERY_INSTR_STATUS is TRUE and the attribute's IVI_VAL_DONT_CHECK_STATUS flag is 0 */
#define IVI_VAL_SET_CACHE_ONLY              (1<<1)  /* applies to Set only;  if 1, then only the cached value is set and no instrument I/O is performed;                                               */
                                                    /* use this when you set multiple instrument attributes with one I/O command;  if you call Set calls with this flag, the update is never deferred */
#define IVI_VAL_DONT_MARK_AS_SET_BY_USER    (1<<2)  /* applies to Set only;  if 0 (which is the typical case), then Ivi_AttributeWasSetByUser will return TRUE;  important for interchangeability checking  */

/*****************************************************************************/
/*= Constants for channels.                                        ========= */
/*****************************************************************************/
#define IVI_VAL_ALL_CHANNELS    "IVI_ALL_CHANNELS" /* special channel string */
#define IVI_VAL_ALL_INSTANCES   IVI_VAL_ALL_CHANNELS

/*****************************************************************************/
/*= Typedef for adding an attribute invalidation                   ========= */
/*****************************************************************************/
typedef struct
    {
    ViAttr      attribute;
    ViBoolean   allChannels;   /* if nonzero, invalidate on all channels;   */
                               /* otherwise, invalidate only on the channel */
                               /* which caused the invalidation to occur    */
    } IviInvalEntry;

/*****************************************************************************/
/*= Typedef for getting list of logical names.                     ========= */
/*****************************************************************************/
typedef struct
    {
    ViString    logicalName;
    ViBoolean   fromFile;   /* VI_TRUE if logical name was in configuration file;  VI_FALSE if was from Ivi_DefineLogicalName */
    } IviLogicalNameEntry;

/*****************************************************************************/
/*= Typedef and related constants for data types.                   ======== */
/*****************************************************************************/
typedef ViInt32 IviValueType;

#define IVI_VAL_INT32                           1L
#define IVI_VAL_INT64                           2L
#define IVI_VAL_REAL64                          4L
#define IVI_VAL_STRING                          5L
#define IVI_VAL_ADDR                            10L
#define IVI_VAL_SESSION                         11L
#define IVI_VAL_BOOLEAN                         13L
#define IVI_VAL_UNKNOWN_TYPE                    14L

/*****************************************************************************/
/*= Typedef and related constants for the callback types.          ========= */
/*****************************************************************************/
typedef ViInt32 IviCallbackType;   /* type used to identify which callback to set or get*/

#define IVI_VAL_READ_CALLBACK                   1
#define IVI_VAL_WRITE_CALLBACK                  2
#define IVI_VAL_COMPARE_CALLBACK                3
#define IVI_VAL_CHECK_CALLBACK                  4
#define IVI_VAL_COERCE_CALLBACK                 5
#define IVI_VAL_RANGE_TABLE_CALLBACK            6

/*****************************************************************************/
/*= Constants for the Ivi_ReadToFile function.                     ========= */
/*****************************************************************************/
/* fileAction */
#define IVI_VAL_TRUNCATE                        1
#define IVI_VAL_APPEND                          2

/*****************************************************************************/
/*= Constants for the Ivi_PerformClassInterchangeCheck function.         === */
/*****************************************************************************/
/* IVI Class API */
#define IVI_VAL_CLASS_API_DCPWR                 1
#define IVI_VAL_CLASS_API_DMM                   2
#define IVI_VAL_CLASS_API_FGEN                  3
#define IVI_VAL_CLASS_API_SCOPE                 4
#define IVI_VAL_CLASS_API_SWTCH                 5

/*****************************************************************************/
/*= Error constants                                                ========= */
/*****************************************************************************/
#define IVI_STATUS_CODE_BASE                    0x3FFA0000L

#define IVI_WARN_BASE                           (IVI_STATUS_CODE_BASE)
#define IVI_CROSS_CLASS_WARN_BASE               (IVI_WARN_BASE + 0x1000)
#define IVI_CLASS_WARN_BASE                     (IVI_WARN_BASE + 0x2000)
#define IVI_SPECIFIC_WARN_BASE                  (IVI_WARN_BASE + 0x4000)
#define IVI_MAX_SPECIFIC_WARN_CODE              (IVI_WARN_BASE + 0x7FFF)
#define IVI_NI_WARN_BASE                        (IVI_WARN_BASE + 0x6000)

#define IVI_ERROR_BASE                          (_VI_ERROR + IVI_STATUS_CODE_BASE)
#define IVI_CROSS_CLASS_ERROR_BASE              (IVI_ERROR_BASE + 0x1000)
#define IVI_CLASS_ERROR_BASE                    (IVI_ERROR_BASE + 0x2000)
#define IVI_SPECIFIC_ERROR_BASE                 (IVI_ERROR_BASE + 0x4000)
#define IVI_MAX_SPECIFIC_ERROR_CODE             (IVI_ERROR_BASE + 0x7FFF)
#define IVI_NI_ERROR_BASE                       (IVI_ERROR_BASE + 0x6000)
#define IVI_SHARED_COMPONENT_ERROR_BASE         (IVI_ERROR_BASE + 0x1000)

    /* IVI Foundation defined warnings */
#define IVI_WARN_NSUP_ID_QUERY                  (IVI_WARN_BASE + 0x65)
#define IVI_WARN_NSUP_RESET                     (IVI_WARN_BASE + 0x66)
#define IVI_WARN_NSUP_SELF_TEST                 (IVI_WARN_BASE + 0x67)
#define IVI_WARN_NSUP_ERROR_QUERY               (IVI_WARN_BASE + 0x68)
#define IVI_WARN_NSUP_REV_QUERY                 (IVI_WARN_BASE + 0x69)

    /* IVI Foundation defined errors */
#define IVI_ERROR_CANNOT_RECOVER                (IVI_ERROR_BASE + 0x00)
#define IVI_ERROR_INSTRUMENT_STATUS             (IVI_ERROR_BASE + 0x01)
#define IVI_ERROR_CANNOT_OPEN_FILE              (IVI_ERROR_BASE + 0x02)
#define IVI_ERROR_READING_FILE                  (IVI_ERROR_BASE + 0x03)
#define IVI_ERROR_WRITING_FILE                  (IVI_ERROR_BASE + 0x04)
#define IVI_ERROR_INVALID_PATHNAME              (IVI_ERROR_BASE + 0x0B)
#define IVI_ERROR_INVALID_ATTRIBUTE             (IVI_ERROR_BASE + 0x0C)
#define IVI_ERROR_IVI_ATTR_NOT_WRITABLE         (IVI_ERROR_BASE + 0x0D)
#define IVI_ERROR_IVI_ATTR_NOT_READABLE         (IVI_ERROR_BASE + 0x0E)
#define IVI_ERROR_INVALID_VALUE                 (IVI_ERROR_BASE + 0x10)
#define IVI_ERROR_FUNCTION_NOT_SUPPORTED        (IVI_ERROR_BASE + 0x11)
#define IVI_ERROR_ATTRIBUTE_NOT_SUPPORTED       (IVI_ERROR_BASE + 0x12)
#define IVI_ERROR_VALUE_NOT_SUPPORTED           (IVI_ERROR_BASE + 0x13)
#define IVI_ERROR_TYPES_DO_NOT_MATCH            (IVI_ERROR_BASE + 0x15)
#define IVI_ERROR_NOT_INITIALIZED               (IVI_ERROR_BASE + 0x1D)
#define IVI_ERROR_UNKNOWN_CHANNEL_NAME          (IVI_ERROR_BASE + 0x20)
#define IVI_ERROR_TOO_MANY_OPEN_FILES           (IVI_ERROR_BASE + 0x23)
#define IVI_ERROR_CHANNEL_NAME_REQUIRED         (IVI_ERROR_BASE + 0x44)
#define IVI_ERROR_CHANNEL_NAME_NOT_ALLOWED      (IVI_ERROR_BASE + 0x45)
#define IVI_ERROR_MISSING_OPTION_NAME           (IVI_ERROR_BASE + 0x49)
#define IVI_ERROR_MISSING_OPTION_VALUE          (IVI_ERROR_BASE + 0x4A)
#define IVI_ERROR_BAD_OPTION_NAME               (IVI_ERROR_BASE + 0x4B)
#define IVI_ERROR_BAD_OPTION_VALUE              (IVI_ERROR_BASE + 0x4C)
#define IVI_ERROR_OUT_OF_MEMORY                 (IVI_ERROR_BASE + 0x56)
#define IVI_ERROR_OPERATION_PENDING             (IVI_ERROR_BASE + 0x57)
#define IVI_ERROR_NULL_POINTER                  (IVI_ERROR_BASE + 0x58)
#define IVI_ERROR_UNEXPECTED_RESPONSE           (IVI_ERROR_BASE + 0x59)
#define IVI_ERROR_FILE_NOT_FOUND                (IVI_ERROR_BASE + 0x5B)
#define IVI_ERROR_INVALID_FILE_FORMAT           (IVI_ERROR_BASE + 0x5C)
#define IVI_ERROR_STATUS_NOT_AVAILABLE          (IVI_ERROR_BASE + 0x5D)
#define IVI_ERROR_ID_QUERY_FAILED               (IVI_ERROR_BASE + 0x5E)
#define IVI_ERROR_RESET_FAILED                  (IVI_ERROR_BASE + 0x5F)
#define IVI_ERROR_RESOURCE_UNKNOWN              (IVI_ERROR_BASE + 0x60)
#define IVI_ERROR_CANNOT_CHANGE_SIMULATION_STATE       (IVI_ERROR_BASE + 0x62)
#define IVI_ERROR_INVALID_NUMBER_OF_LEVELS_IN_SELECTOR (IVI_ERROR_BASE + 0x63)
#define IVI_ERROR_INVALID_RANGE_IN_SELECTOR     (IVI_ERROR_BASE + 0x64)
#define IVI_ERROR_UNKOWN_NAME_IN_SELECTOR       (IVI_ERROR_BASE + 0x65)
#define IVI_ERROR_BADLY_FORMED_SELECTOR         (IVI_ERROR_BASE + 0x66)
#define IVI_ERROR_UNKNOWN_PHYSICAL_IDENTIFIER   (IVI_ERROR_BASE + 0x67)

/* IVI Foundation reserved (grandfathered) errors */
#define IVI_ERROR_DRIVER_MODULE_NOT_FOUND       (IVI_ERROR_BASE + 0x05)
#define IVI_ERROR_CANNOT_OPEN_DRIVER_MODULE     (IVI_ERROR_BASE + 0x06)
#define IVI_ERROR_INVALID_DRIVER_MODULE         (IVI_ERROR_BASE + 0x07)
#define IVI_ERROR_UNDEFINED_REFERENCES          (IVI_ERROR_BASE + 0x08)
#define IVI_ERROR_FUNCTION_NOT_FOUND            (IVI_ERROR_BASE + 0x09)
#define IVI_ERROR_LOADING_DRIVER_MODULE         (IVI_ERROR_BASE + 0x0A)
#define IVI_ERROR_INVALID_PARAMETER             (IVI_ERROR_BASE + 0x0F)
#define IVI_ERROR_INVALID_TYPE                  (IVI_ERROR_BASE + 0x14)
#define IVI_ERROR_MULTIPLE_DEFERRED_SETTING     (IVI_ERROR_BASE + 0x16)
#define IVI_ERROR_ITEM_ALREADY_EXISTS           (IVI_ERROR_BASE + 0x17)
#define IVI_ERROR_INVALID_CONFIGURATION         (IVI_ERROR_BASE + 0x18)
#define IVI_ERROR_VALUE_NOT_AVAILABLE           (IVI_ERROR_BASE + 0x19)
#define IVI_ERROR_ATTRIBUTE_VALUE_NOT_KNOWN     (IVI_ERROR_BASE + 0x1A)
#define IVI_ERROR_NO_RANGE_TABLE                (IVI_ERROR_BASE + 0x1B)
#define IVI_ERROR_INVALID_RANGE_TABLE           (IVI_ERROR_BASE + 0x1C)
#define IVI_ERROR_NON_INTERCHANGEABLE_BEHAVIOR  (IVI_ERROR_BASE + 0x1E)
#define IVI_ERROR_NO_CHANNEL_TABLE              (IVI_ERROR_BASE + 0x1F)
#define IVI_ERROR_SYS_RSRC_ALLOC                (IVI_ERROR_BASE + 0x21)
#define IVI_ERROR_ACCESS_DENIED                 (IVI_ERROR_BASE + 0x22)
#define IVI_ERROR_UNABLE_TO_CREATE_TEMP_FILE    (IVI_ERROR_BASE + 0x24)
#define IVI_ERROR_NO_UNUSED_TEMP_FILENAMES      (IVI_ERROR_BASE + 0x25)
#define IVI_ERROR_DISK_FULL                     (IVI_ERROR_BASE + 0x26)
#define IVI_ERROR_CONFIG_FILE_NOT_FOUND         (IVI_ERROR_BASE + 0x27)
#define IVI_ERROR_CANNOT_OPEN_CONFIG_FILE       (IVI_ERROR_BASE + 0x28)
#define IVI_ERROR_ERROR_READING_CONFIG_FILE     (IVI_ERROR_BASE + 0x29)
#define IVI_ERROR_BAD_INTEGER_IN_CONFIG_FILE    (IVI_ERROR_BASE + 0x2A)
#define IVI_ERROR_BAD_DOUBLE_IN_CONFIG_FILE     (IVI_ERROR_BASE + 0x2B)
#define IVI_ERROR_BAD_BOOLEAN_IN_CONFIG_FILE    (IVI_ERROR_BASE + 0x2C)
#define IVI_ERROR_CONFIG_ENTRY_NOT_FOUND        (IVI_ERROR_BASE + 0x2D)
#define IVI_ERROR_DRIVER_DLL_INIT_FAILED        (IVI_ERROR_BASE + 0x2E)
#define IVI_ERROR_DRIVER_UNRESOLVED_SYMBOL      (IVI_ERROR_BASE + 0x2F)
#define IVI_ERROR_CANNOT_FIND_CVI_RTE           (IVI_ERROR_BASE + 0x30)
#define IVI_ERROR_CANNOT_OPEN_CVI_RTE           (IVI_ERROR_BASE + 0x31)
#define IVI_ERROR_CVI_RTE_INVALID_FORMAT        (IVI_ERROR_BASE + 0x32)
#define IVI_ERROR_CVI_RTE_MISSING_FUNCTION      (IVI_ERROR_BASE + 0x33)
#define IVI_ERROR_CVI_RTE_INIT_FAILED           (IVI_ERROR_BASE + 0x34)
#define IVI_ERROR_CVI_RTE_UNRESOLVED_SYMBOL     (IVI_ERROR_BASE + 0x35)
#define IVI_ERROR_LOADING_CVI_RTE               (IVI_ERROR_BASE + 0x36)
#define IVI_ERROR_CANNOT_OPEN_DLL_FOR_EXPORTS   (IVI_ERROR_BASE + 0x37)
#define IVI_ERROR_DLL_CORRUPTED                 (IVI_ERROR_BASE + 0x38)
#define IVI_ERROR_NO_DLL_EXPORT_TABLE           (IVI_ERROR_BASE + 0x39)
#define IVI_ERROR_UNKNOWN_DEFAULT_SETUP_ATTR    (IVI_ERROR_BASE + 0x3A)
#define IVI_ERROR_INVALID_DEFAULT_SETUP_VAL     (IVI_ERROR_BASE + 0x3B)
#define IVI_ERROR_UNKNOWN_MEMORY_PTR            (IVI_ERROR_BASE + 0x3C)
#define IVI_ERROR_EMPTY_CHANNEL_LIST            (IVI_ERROR_BASE + 0x3D)
#define IVI_ERROR_DUPLICATE_CHANNEL_STRING      (IVI_ERROR_BASE + 0x3E)
#define IVI_ERROR_DUPLICATE_VIRT_CHAN_NAME      (IVI_ERROR_BASE + 0x3F)
#define IVI_ERROR_MISSING_VIRT_CHAN_NAME        (IVI_ERROR_BASE + 0x40)
#define IVI_ERROR_BAD_VIRT_CHAN_NAME            (IVI_ERROR_BASE + 0x41)
#define IVI_ERROR_UNASSIGNED_VIRT_CHAN_NAME     (IVI_ERROR_BASE + 0x42)
#define IVI_ERROR_BAD_VIRT_CHAN_ASSIGNMENT      (IVI_ERROR_BASE + 0x43)
#define IVI_ERROR_ATTR_NOT_VALID_FOR_CHANNEL    (IVI_ERROR_BASE + 0x46)
#define IVI_ERROR_ATTR_MUST_BE_CHANNEL_BASED    (IVI_ERROR_BASE + 0x47)
#define IVI_ERROR_CHANNEL_ALREADY_EXCLUDED      (IVI_ERROR_BASE + 0x48)
#define IVI_ERROR_NOT_CREATED_BY_CLASS          (IVI_ERROR_BASE + 0x4D)
#define IVI_ERROR_IVI_INI_IS_RESERVED           (IVI_ERROR_BASE + 0x4E)
#define IVI_ERROR_DUP_RUNTIME_CONFIG_ENTRY      (IVI_ERROR_BASE + 0x4F)
#define IVI_ERROR_INDEX_IS_ONE_BASED            (IVI_ERROR_BASE + 0x50)
#define IVI_ERROR_INDEX_IS_TOO_HIGH             (IVI_ERROR_BASE + 0x51)
#define IVI_ERROR_ATTR_NOT_CACHEABLE            (IVI_ERROR_BASE + 0x52)
#define IVI_ERROR_ADDR_ATTRS_MUST_BE_HIDDEN     (IVI_ERROR_BASE + 0x53)
#define IVI_ERROR_BAD_CHANNEL_NAME              (IVI_ERROR_BASE + 0x54)
#define IVI_ERROR_BAD_PREFIX_IN_CONFIG_FILE     (IVI_ERROR_BASE + 0x55)

/* NI-Specific errors */
#define IVI_ERROR_CANNOT_MODIFY_REPEATED_CAPABILITY_TABLE  (IVI_NI_ERROR_BASE + 0)
#define IVI_ERROR_CANNOT_RESTRICT_ATTRIBUTE_TWICE          (IVI_NI_ERROR_BASE + 1)
#define IVI_ERROR_REPEATED_CAPABILITY_ALREADY_EXISTS       (IVI_NI_ERROR_BASE + 2)
#define IVI_ERROR_REPEATED_CAPABILITY_NOT_DEFINED          (IVI_NI_ERROR_BASE + 3)
#define IVI_ERROR_INVALID_REPEATED_CAPABILITY_NAME         (IVI_NI_ERROR_BASE + 4)
#define IVI_ERROR_CONFIG_SERVER_NOT_PRESENT                (IVI_NI_ERROR_BASE + 0xD)

/* NI-Specific renamed errors.  */
#define IVI_ERROR_REPEATED_CAPABILITY_NAME_REQUIRED        IVI_ERROR_CHANNEL_NAME_REQUIRED
#define IVI_ERROR_UNKNOWN_REPEATED_CAPABILITY_NAME         IVI_ERROR_UNKNOWN_CHANNEL_NAME
#define IVI_ERROR_EMPTY_REPEATED_CAPABILITY_LIST           IVI_ERROR_EMPTY_CHANNEL_LIST
#define IVI_ERROR_DUPLICATE_REPEATED_CAPABILITY_IDENTIFIER IVI_ERROR_DUPLICATE_CHANNEL_STRING
#define IVI_ERROR_REPEATED_CAPABILITY_NAME_NOT_ALLOWED     IVI_ERROR_CHANNEL_NAME_NOT_ALLOWED
#define IVI_ERROR_ATTR_NOT_VALID_FOR_REPEATED_CAPABILITY   IVI_ERROR_ATTR_NOT_VALID_FOR_CHANNEL
#define IVI_ERROR_ATTR_MUST_BE_REPEATED_CAPABILITY_BASED   IVI_ERROR_ATTR_MUST_BE_CHANNEL_BASED
#define IVI_ERROR_BAD_REPEATED_CAPABILITY_NAME             IVI_ERROR_BAD_CHANNEL_NAME

/*  renamed errors. Do not use these identifiers in your drivers and applications. */
#define IVI_ERROR_CANNOT_LOAD_IVI_ENGINE        (IVI_ERROR_BASE + 0x00)
#define IVI_ERROR_INSTR_SPECIFIC                (IVI_ERROR_BASE + 0x01)
#define IVI_ERROR_TOO_MANY_FILES_OPEN           (IVI_ERROR_BASE + 0x23)

/*  obsolete errors. Do not use these identifiers in your drivers and applications. */
#define IVI_ERROR_ALREADY_INITIALIZED                      (IVI_ERROR_BASE + 0x61)

/*****************************************************************************/
/*= Macros for checking for errors.                                 ======== */
/*= The checkErr and viCheckErr macros discard warnings.            ======== */
/*= The checkWarn and viCheckWarn macros preserve warnings.         ======== */
/*****************************************************************************/

#ifndef _IVI_USE_LEGACY_ERROR_MACROS_

/* Redefined error macros in IVI Engine 2.4.0 (ICP 2.3) */

#ifndef checkAlloc
#define checkAlloc(fCall)    if ((fCall) == 0) \
                                 {error = VI_ERROR_ALLOC; goto Error;}  else error = error
#endif

#ifndef checkErr
#define checkErr(fCall)      if (VI_SUCCESS != (error = (fCall), (error = (error < 0) ? error : VI_SUCCESS))) \
                                 {goto Error;}  else error = error
#endif

#ifndef checkWarn
#define checkWarn(fCall)     if ((void)1,1) {ViStatus _code_; if (_code_ = (fCall), _code_ < 0)    \
                                                {error = _code_;goto Error;}        \
                                               else error = (error==0)?_code_:error;} else error = error
#endif

#ifndef viCheckAlloc
#define viCheckAlloc(fCall)  if ((fCall) == 0) \
                                 {error = VI_ERROR_ALLOC; Ivi_SetErrorInfo(vi, VI_FALSE, error, 0, VI_NULL); goto Error;}  else error = error
#endif

#ifndef viCheckErr
#define viCheckErr(fCall)    if (VI_SUCCESS != (error = (fCall), (error = (error < 0) ? error : VI_SUCCESS))) \
                                 {Ivi_SetErrorInfo(vi, VI_FALSE, error, 0, VI_NULL); goto Error;}  else error = error
#endif

#ifndef viCheckErrElab
#define viCheckErrElab(fCall, elab) \
                             if (VI_SUCCESS != (error = (fCall), (error = (error < 0) ? error : VI_SUCCESS))) \
                                 {Ivi_SetErrorInfo(vi, VI_FALSE, error, 0, elab); goto Error;}  else error = error
#endif

#ifndef viCheckParm
#define viCheckParm(fCall, parameterPosition, parameterName) \
                             if (VI_SUCCESS != (error = (fCall), (error = (error < 0) ? (error) : VI_SUCCESS))) \
                                 {Ivi_SetErrorInfo(vi, VI_FALSE, error, Ivi_ParamPositionError(parameterPosition), parameterName); goto Error;}  else error = error
#endif

#ifndef viCheckWarn
#define viCheckWarn(fCall)   if ((void)1,1) {ViStatus _code_; if (_code_ = (fCall), _code_?Ivi_SetErrorInfo(vi, VI_FALSE, _code_, 0, VI_NULL) : 0, _code_ < 0)    \
                                                {error = _code_;goto Error;}        \
                                               else error = (error==0)?_code_:error;} else error = error
#endif

#else /* _IVI_USE_LEGACY_ERROR_MACROS_ */

/* Legacy error macros defined in IVI Engine 2.3.0 (ICP 2.2) and earlier */

#ifndef checkAlloc
#define checkAlloc(fCall)    if ((fCall) == 0) \
                                 {error = VI_ERROR_ALLOC; goto Error;}  else
#endif

#ifndef checkErr
#define checkErr(fCall)      if (VI_SUCCESS != (error = (fCall), (error = (error < 0) ? error : VI_SUCCESS))) \
                                 {goto Error;}  else
#endif

#ifndef checkWarn
#define checkWarn(fCall)     if (error = (fCall), error < 0) \
                                 {goto Error;}  else
#endif

#ifndef viCheckAlloc
#define viCheckAlloc(fCall)  if ((fCall) == 0) \
                                 {error = VI_ERROR_ALLOC; Ivi_SetErrorInfo(vi, VI_FALSE, error, 0, VI_NULL); goto Error;}  else
#endif

#ifndef viCheckErr
#define viCheckErr(fCall)    if (VI_SUCCESS != (error = (fCall), (error = (error < 0) ? error : VI_SUCCESS))) \
                                 {Ivi_SetErrorInfo(vi, VI_FALSE, error, 0, VI_NULL); goto Error;}  else
#endif

#ifndef viCheckErrElab
#define viCheckErrElab(fCall, elab) \
                             if (VI_SUCCESS != (error = (fCall), (error = (error < 0) ? error : VI_SUCCESS))) \
                                 {Ivi_SetErrorInfo(vi, VI_FALSE, error, 0, elab); goto Error;}  else
#endif

#ifndef viCheckParm
#define viCheckParm(fCall, parameterPosition, parameterName) \
                             if (VI_SUCCESS != (error = (fCall), (error = (error < 0) ? (error) : VI_SUCCESS))) \
                                 {Ivi_SetErrorInfo(vi, VI_FALSE, error, Ivi_ParamPositionError(parameterPosition), parameterName); goto Error;}  else
#endif

#ifndef viCheckWarn
#define viCheckWarn(fCall)   if (error = (fCall), (error ? Ivi_SetErrorInfo(vi, VI_FALSE, error, 0, VI_NULL) : 0), error < 0) \
                                 {goto Error;}  else
#endif

#endif /* _IVI_USE_LEGACY_ERROR_MACROS_ */

/*****************************************************************************/
/*= Function pointer typedefs for standard instrument driver functions. ==== */
/*****************************************************************************/
typedef ViStatus (_VI_FUNC *Ivi_InitFuncPtr)        (   ViRsrc resourceName, ViBoolean IDQuery,
                                                        ViBoolean resetDevice,
                                                        ViSession *vi);
typedef ViStatus (_VI_FUNC *Ivi_InitWithOptionsFuncPtr)(ViRsrc resourceName, ViBoolean IDQuery,
                                                        ViBoolean resetDevice, ViString optionString,
                                                        ViSession *vi);
typedef ViStatus (_VI_FUNC *Ivi_CloseFuncPtr)       (   ViSession vi);
typedef ViStatus (_VI_FUNC *Ivi_ResetFuncPtr)       (   ViSession vi);
typedef ViStatus (_VI_FUNC *Ivi_SelfTestFuncPtr)    (   ViSession vi,
                                                        ViInt16 * selfTestResult,
                                                        ViChar selfTestMessage[]);
typedef ViStatus (_VI_FUNC *Ivi_ErrorQueryFuncPtr)  (   ViSession vi,
                                                        ViInt32  *errorCode,
                                                        ViChar errorMessage[]);
typedef ViStatus (_VI_FUNC *Ivi_ErrorMessageFuncPtr)(   ViSession vi,
                                                        ViStatus statusCode,
                                                        ViChar message[]);
typedef ViStatus (_VI_FUNC *Ivi_RevisionQueryFuncPtr)(  ViSession vi,
                                                        ViChar driverRev[],
                                                        ViChar instrRev[]);
/*****************************************************************************/
/*= Function pointer typedefs for IVI Required instrument driver functions.= */
/*****************************************************************************/

typedef ViStatus (_VI_FUNC *Ivi_GetAttributeViInt32FuncPtr) (ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 *value);

#ifdef _IVI_64BIT_ATTR_DEFINED_
typedef ViStatus (_VI_FUNC *Ivi_GetAttributeViInt64FuncPtr) (ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt64 *value);
#endif

typedef ViStatus (_VI_FUNC *Ivi_GetAttributeViReal64FuncPtr) (ViSession vi, ViConstString repCapName, ViAttr attributeId, ViReal64 *value);

typedef ViStatus (_VI_FUNC *Ivi_GetAttributeViStringFuncPtr) (ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 bufSize, ViChar value[]);

typedef ViStatus (_VI_FUNC *Ivi_GetAttributeViBooleanFuncPtr) (ViSession vi, ViConstString repCapName, ViAttr attributeId, ViBoolean *value);

typedef ViStatus (_VI_FUNC *Ivi_GetAttributeViSessionFuncPtr) (ViSession vi, ViConstString repCapName, ViAttr attributeId, ViSession *value);

typedef ViStatus (_VI_FUNC *Ivi_SetAttributeViInt32FuncPtr) (ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 value);

#ifdef _IVI_64BIT_ATTR_DEFINED_
typedef ViStatus (_VI_FUNC *Ivi_SetAttributeViInt64FuncPtr) (ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt64 value);
#endif

typedef ViStatus (_VI_FUNC *Ivi_SetAttributeViReal64FuncPtr) (ViSession vi, ViConstString repCapName, ViAttr attributeId, ViReal64 value);

typedef ViStatus (_VI_FUNC *Ivi_SetAttributeViStringFuncPtr) (ViSession vi, ViConstString repCapName, ViAttr attributeId, ViConstString value);

typedef ViStatus (_VI_FUNC *Ivi_SetAttributeViBooleanFuncPtr) (ViSession vi, ViConstString repCapName, ViAttr attributeId, ViBoolean value);

typedef ViStatus (_VI_FUNC *Ivi_SetAttributeViSessionFuncPtr) (ViSession vi, ViConstString repCapName, ViAttr attributeId, ViSession value);

typedef ViStatus (_VI_FUNC *Ivi_CheckAttributeViInt32FuncPtr) (ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 value);

#ifdef _IVI_64BIT_ATTR_DEFINED_
typedef ViStatus (_VI_FUNC *Ivi_CheckAttributeViInt64FuncPtr) (ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt64 value);
#endif

typedef ViStatus (_VI_FUNC *Ivi_CheckAttributeViReal64FuncPtr) (ViSession vi, ViConstString repCapName, ViAttr attributeId, ViReal64 value);

typedef ViStatus (_VI_FUNC *Ivi_CheckAttributeViStringFuncPtr) (ViSession vi, ViConstString repCapName, ViAttr attributeId, ViConstString value);

typedef ViStatus (_VI_FUNC *Ivi_CheckAttributeViBooleanFuncPtr) (ViSession vi, ViConstString repCapName, ViAttr attributeId, ViBoolean value);

typedef ViStatus (_VI_FUNC *Ivi_CheckAttributeViSessionFuncPtr) (ViSession vi, ViConstString repCapName, ViAttr attributeId, ViSession value);

typedef ViStatus (_VI_FUNC *Ivi_GetErrorInfoFuncPtr) (ViSession vi, ViStatus *primaryError, ViStatus *secondaryError, ViChar errorElaboration[IVI_MAX_MESSAGE_BUF_SIZE]);

typedef ViStatus (_VI_FUNC *Ivi_ClearErrorInfoFuncPtr) (ViSession vi);

typedef ViStatus (_VI_FUNC *Ivi_LockSessionFuncPtr) (ViSession vi, ViBoolean *callerHasLock);

typedef ViStatus (_VI_FUNC *Ivi_UnlockSessionFuncPtr) (ViSession vi, ViBoolean *callerHasLock);

typedef ViStatus (_VI_FUNC *Ivi_GetNextCoercionRecordFuncPtr) (ViSession vi, ViInt32 bufferSize, ViChar recordBuf[]);

typedef ViStatus (_VI_FUNC *Ivi_GetNextInterchangeWarningPtr) (ViSession vi, ViInt32 bufferSize, ViChar buffer[]);

typedef ViStatus (_VI_FUNC *Ivi_ResetInterchangeCheckPtr) (ViSession vi);


/*****************************************************************************/
/*= Typedef for function pointer passed to Ivi_BuildChannelTable    ======== */
/*= when you want to allow virtual channel names in the IVI         ======== */
/*= configuration file to reference channel strings not passed      ======== */
/*= into Ivi_BuildChannelTable.                                     ======== */
/*****************************************************************************/
typedef ViStatus    (_VI_FUNC *Ivi_ValidateChannelStringFunc)(ViSession vi, ViConstString channelString, ViBoolean *isValid, ViStatus *secondaryError);
    /*
        You should return an error code only if you are unable to determine
        whether the channel string is valid or not.
        If the channel string is not a valid one, you should set *isValid
        to VI_FALSE but return VI_SUCCESS.
        If you set *isValid to VI_FALSE, IVI sets the primary error to
        IVI_ERROR_BAD_VIRT_CHAN_ASSIGNMENT and formats the error elaboration
        to include both the virtual channel name and the channel string.
        You can optionally set *secondaryError to specify what is wrong
        with the channel string.
    */

/*****************************************************************************/
/*= Typedef for function pointer passed to ReadAttrViStringCallback ======== */
/*= and CoerceAttrViStringCallback.  The callback uses this         ======== */
/*= function pointer to set the string value.                       ======== */
/*****************************************************************************/
typedef ViStatus    (_VI_FUNC *Ivi_SetValInStringCallbackFunc)(ViSession vi, ViAttr attributeId, ViConstString value);

/*****************************************************************************/
/*= Function pointer typedefs for ViInt32 attribute callbacks       ======== */
/*****************************************************************************/
typedef ViStatus    (_VI_FUNC *ReadAttrViInt32_CallbackPtr)(ViSession vi, ViSession io, ViConstString repCapName, ViAttr attributeId, ViInt32 *value);
typedef ViStatus    (_VI_FUNC *WriteAttrViInt32_CallbackPtr)(ViSession vi, ViSession io, ViConstString repCapName, ViAttr attributeId, ViInt32 value);
typedef ViStatus    (_VI_FUNC *CheckAttrViInt32_CallbackPtr)(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 value);
typedef ViStatus    (_VI_FUNC *CompareAttrViInt32_CallbackPtr)(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 coercedNewValue, ViInt32 cacheValue, ViInt32 *result);
typedef ViStatus    (_VI_FUNC *CoerceAttrViInt32_CallbackPtr)(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 value, ViInt32 *coercedValue);

/*****************************************************************************/
/*= Function pointer typedefs for ViInt64 attribute callbacks       ======== */
/*****************************************************************************/
#ifdef _IVI_64BIT_ATTR_DEFINED_
typedef ViStatus    (_VI_FUNC *ReadAttrViInt64_CallbackPtr)(ViSession vi, ViSession io, ViConstString repCapName, ViAttr attributeId, ViInt64 *value);
typedef ViStatus    (_VI_FUNC *WriteAttrViInt64_CallbackPtr)(ViSession vi, ViSession io, ViConstString repCapName, ViAttr attributeId, ViInt64 value);
typedef ViStatus    (_VI_FUNC *CheckAttrViInt64_CallbackPtr)(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt64 value);
typedef ViStatus    (_VI_FUNC *CompareAttrViInt64_CallbackPtr)(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt64 coercedNewValue, ViInt64 cacheValue, ViInt32 *result);
typedef ViStatus    (_VI_FUNC *CoerceAttrViInt64_CallbackPtr)(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt64 value, ViInt64 *coercedValue);
#endif
/*****************************************************************************/
/*= Function pointer typedefs for ViReal64 attribute callbacks      ======== */
/*****************************************************************************/
typedef ViStatus    (_VI_FUNC *ReadAttrViReal64_CallbackPtr)(ViSession vi, ViSession io, ViConstString repCapName, ViAttr attributeId, ViReal64 *value);
typedef ViStatus    (_VI_FUNC *WriteAttrViReal64_CallbackPtr)(ViSession vi, ViSession io, ViConstString repCapName, ViAttr attributeId, ViReal64 value);
typedef ViStatus    (_VI_FUNC *CheckAttrViReal64_CallbackPtr)(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViReal64 value);
typedef ViStatus    (_VI_FUNC *CompareAttrViReal64_CallbackPtr)(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViReal64 coercedNewValue, ViReal64 cacheValue, ViInt32 *result);
typedef ViStatus    (_VI_FUNC *CoerceAttrViReal64_CallbackPtr)(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViReal64 value, ViReal64 *coercedValue);

/*****************************************************************************/
/*= Function pointer typedefs for ViString attribute callbacks      ======== */
/*****************************************************************************/
typedef ViStatus    (_VI_FUNC *ReadAttrViString_CallbackPtr)(ViSession vi, ViSession io, ViConstString repCapName, ViAttr attributeId, const ViConstString cacheValue);
typedef ViStatus    (_VI_FUNC *WriteAttrViString_CallbackPtr)(ViSession vi, ViSession io, ViConstString repCapName, ViAttr attributeId, ViConstString value);
typedef ViStatus    (_VI_FUNC *CheckAttrViString_CallbackPtr)(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViConstString value);
typedef ViStatus    (_VI_FUNC *CompareAttrViString_CallbackPtr)(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViConstString coercedNewValue, ViConstString cacheValue, ViInt32 *result);
typedef ViStatus    (_VI_FUNC *CoerceAttrViString_CallbackPtr)(ViSession vi, ViConstString repCapName, ViAttr attributeId, const ViConstString value);

/*****************************************************************************/
/*= Function pointer typedefs for ViBoolean attribute callbacks     ======== */
/*****************************************************************************/
typedef ViStatus    (_VI_FUNC *ReadAttrViBoolean_CallbackPtr)(ViSession vi, ViSession io, ViConstString repCapName, ViAttr attributeId, ViBoolean *value);
typedef ViStatus    (_VI_FUNC *WriteAttrViBoolean_CallbackPtr)(ViSession vi, ViSession io, ViConstString repCapName, ViAttr attributeId, ViBoolean value);
typedef ViStatus    (_VI_FUNC *CheckAttrViBoolean_CallbackPtr)(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViBoolean value);
typedef ViStatus    (_VI_FUNC *CompareAttrViBoolean_CallbackPtr)(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViBoolean coercedNewValue, ViBoolean cacheValue, ViInt32 *result);
typedef ViStatus    (_VI_FUNC *CoerceAttrViBoolean_CallbackPtr)(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViBoolean value, ViBoolean *coercedValue);

/*****************************************************************************/
/*= Function pointer typedefs for ViSession attribute callbacks     ======== */
/*****************************************************************************/
typedef ViStatus    (_VI_FUNC *ReadAttrViSession_CallbackPtr)(ViSession vi, ViSession io, ViConstString repCapName, ViAttr attributeId, ViSession *value);
typedef ViStatus    (_VI_FUNC *WriteAttrViSession_CallbackPtr)(ViSession vi, ViSession io, ViConstString repCapName, ViAttr attributeId, ViSession value);
typedef ViStatus    (_VI_FUNC *CheckAttrViSession_CallbackPtr)(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViSession value);
typedef ViStatus    (_VI_FUNC *CompareAttrViSession_CallbackPtr)(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViSession coercedNewValue, ViSession cacheValue, ViInt32 *result);
typedef ViStatus    (_VI_FUNC *CoerceAttrViSession_CallbackPtr)(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViSession value, ViSession *coercedValue);

/*****************************************************************************/
/*= Function pointer typedefs for ViAddr attribute callbacks        ======== */
/*****************************************************************************/
typedef ViStatus    (_VI_FUNC *ReadAttrViAddr_CallbackPtr)(ViSession vi, ViSession io, ViConstString repCapName, ViAttr attributeId, ViAddr *value);
typedef ViStatus    (_VI_FUNC *WriteAttrViAddr_CallbackPtr)(ViSession vi, ViSession io, ViConstString repCapName, ViAttr attributeId, ViAddr value);
typedef ViStatus    (_VI_FUNC *CheckAttrViAddr_CallbackPtr)(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViAddr value);
typedef ViStatus    (_VI_FUNC *CompareAttrViAddr_CallbackPtr)(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViAddr coercedNewValue, ViAddr cacheValue, ViInt32 *result);
typedef ViStatus    (_VI_FUNC *CoerceAttrViAddr_CallbackPtr)(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViAddr value, ViAddr *coercedValue);

/*****************************************************************************/
/*= Function pointer typedef for the callback that retrieves        ======== */
/*= the range table.   Applies only to ViInt32, ViReal64,           ======== */
/*= ViInt64, and ViBoolean attributes.                              ======== */
/*****************************************************************************/
typedef ViStatus    (_VI_FUNC *RangeTable_CallbackPtr)(ViSession vi, ViConstString repCapName, ViAttr attributeId, IviRangeTablePtr *rangeTablePtr);

/*****************************************************************************/
/* Function pointer typedef for the Operation Complete (OPC)        ======== */
/* callback.  The OPC callback is called after writing an           ======== */
/* attribute value to the instrument (if the                        ======== */
/* IVI_VAL_WAIT_FOR_OPC_AFTER_WRITES flag is set for the attribute) ======== */
/* and before reading an attribute value from the instrument (if    ======== */
/* the IVI_VAL_WAIT_FOR_OPC_BEFORE_READS flag is set for the        ======== */
/* attribute).  You can install an OPC callback by setting the      ======== */
/* IVI_ATTR_OPC_CALLBACK attribute for the instrument.              ======== */
/*****************************************************************************/
typedef ViStatus (_VI_FUNC *Ivi_OPCCallbackPtr)(ViSession vi, ViSession io);


/*****************************************************************************/
/* Function pointer typedef for the Check Status callback.          ======== */
/* This Check Status callback is called after interaction with      ======== */
/* the instrument if the IVI_ATTR_QUERY_INSTR_STATUS is set to      ======== */
/* VI_TRUE.  The callback queries the instrument to determine if    ======== */
/* the instrument encountered an error.   You can install a Check   ======== */
/* Status callback by using the IVI_ATTR_CHECK_STATUS_CALLBACK      ======== */
/* attribute for the instrument.                                    ======== */
/*****************************************************************************/
typedef ViStatus (_VI_FUNC *Ivi_CheckStatusCallbackPtr)(ViSession vi, ViSession io);

/*****************************************************************************/
/* Function pointer typedef for the Interchange Check callback.     ======== */
/*****************************************************************************/
typedef ViStatus (_VI_FUNC *Ivi_InterchangeCheckCallbackPtr)(ViSession vi, ViInt32 funcEnum,
                                    ViConstString repCapName, ViAttr attributeId);

/*****************************************************************************/
/*= Base values for attribute constants.                            ======== */
/*= A private attribute is one that is defined for use within       ======== */
/*= that module and is not exported via an include file.            ======== */
/*****************************************************************************/
#define IVI_ATTR_BASE                   1000000
#define IVI_ENGINE_PRIVATE_ATTR_BASE    (IVI_ATTR_BASE +  00000)   /* base for private attributes of the IVI engine */
#define IVI_ENGINE_PUBLIC_ATTR_BASE     (IVI_ATTR_BASE +  50000)   /* base for public attributes of the IVI engine */
#define IVI_SPECIFIC_PUBLIC_ATTR_BASE   (IVI_ATTR_BASE + 150000)   /* base for public attributes of specific drivers */
#define IVI_SPECIFIC_PRIVATE_ATTR_BASE  (IVI_ATTR_BASE + 200000)   /* base for private attributes of specific drivers */
                                                                   /* This value was changed from IVI_ATTR_BASE + 100000 in the version of this file released in August 2013 (ICP 4.6). */
                                                                   /* A private attribute, by its very definition, should not be passed to another module; it should stay private to the compiled module. */
#define IVI_CLASS_PUBLIC_ATTR_BASE      (IVI_ATTR_BASE + 250000)   /* base for public attributes of class drivers */
#define IVI_CLASS_PRIVATE_ATTR_BASE     (IVI_ATTR_BASE + 300000)   /* base for private attributes of class drivers */
                                                                   /* This value was changed from IVI_ATTR_BASE + 200000 in the version of this file released in August 2013 (ICP 4.6). */
                                                                   /* A private attribute, by its very definition, should not be passed to another module; it should stay private to the compiled module. */

/*****************************************************************************/
/*= Public IVI engine attributes                                    ======== */
/*= The data type of each attribute is listed, followed by the      ======== */
/*= default value or a remark.                                      ======== */
/*= Note:  "hidden" means not readable or writable by the end-user. ======== */
/*****************************************************************************/
#define IVI_ATTR_NONE                   /* no attribute */              0xFFFFFFFF

#define IVI_ATTR_RANGE_CHECK            /* ViBoolean, VI_TRUE */        (IVI_ENGINE_PUBLIC_ATTR_BASE + 2)
#define IVI_ATTR_QUERY_INSTRUMENT_STATUS /* ViBoolean, VI_FALSE */      (IVI_ENGINE_PUBLIC_ATTR_BASE + 3)   /* If VI_TRUE, the specific driver is allowed to query the instrument error status after each operation */
#define IVI_ATTR_CACHE                  /* ViBoolean, VI_TRUE */        (IVI_ENGINE_PUBLIC_ATTR_BASE + 4)
#define IVI_ATTR_SIMULATE               /* ViBoolean, VI_FALSE */       (IVI_ENGINE_PUBLIC_ATTR_BASE + 5)
#define IVI_ATTR_RECORD_COERCIONS       /* ViBoolean, VI_FALSE */       (IVI_ENGINE_PUBLIC_ATTR_BASE + 6)
#define IVI_ATTR_DRIVER_SETUP           /* ViString,  "" */             (IVI_ENGINE_PUBLIC_ATTR_BASE + 7)

#define IVI_ATTR_INTERCHANGE_CHECK      /* ViBoolean, VI_TRUE */        (IVI_ENGINE_PUBLIC_ATTR_BASE + 21)
#define IVI_ATTR_SPY                    /* ViBoolean, VI_FALSE */       (IVI_ENGINE_PUBLIC_ATTR_BASE + 22)
#define IVI_ATTR_USE_SPECIFIC_SIMULATION  /* ViBoolean */               (IVI_ENGINE_PUBLIC_ATTR_BASE + 23)  /* simulate values in specific rather than class driver;  default is VI_TRUE if session opened through class driver, VI_FALSE otherwise */

#define IVI_ATTR_PRIMARY_ERROR          /* ViInt32  */                  (IVI_ENGINE_PUBLIC_ATTR_BASE + 101)
#define IVI_ATTR_SECONDARY_ERROR        /* VIInt32  */                  (IVI_ENGINE_PUBLIC_ATTR_BASE + 102)
#define IVI_ATTR_ERROR_ELABORATION      /* ViString */                  (IVI_ENGINE_PUBLIC_ATTR_BASE + 103)

#define IVI_ATTR_CHANNEL_COUNT          /* ViInt32,  not writable*/     (IVI_ENGINE_PUBLIC_ATTR_BASE + 203)   /* set by the specific-driver;  default: 1 */

#define IVI_ATTR_CLASS_DRIVER_PREFIX    /* ViString, not writable*/     (IVI_ENGINE_PUBLIC_ATTR_BASE + 301)  /* instrument prefix for the class driver;  empty string if not using class driver */
#define IVI_ATTR_SPECIFIC_DRIVER_PREFIX /* ViString, not writable*/     (IVI_ENGINE_PUBLIC_ATTR_BASE + 302)  /* instrument prefix for the specific driver */
#define IVI_ATTR_SPECIFIC_DRIVER_LOCATOR/* ViString, not writable*/     (IVI_ENGINE_PUBLIC_ATTR_BASE + 303)  /* the pathnname of the specific driver code module; from the configuration file */
#define IVI_ATTR_IO_RESOURCE_DESCRIPTOR /* ViString, not writable*/     (IVI_ENGINE_PUBLIC_ATTR_BASE + 304)  /* the string that describes how to find the physical instrument; from the configuration file */
#define IVI_ATTR_LOGICAL_NAME           /* ViString, not writable*/     (IVI_ENGINE_PUBLIC_ATTR_BASE + 305)  /* for class drivers, the logical name used in the Init call to identify the specific instrument */
#define IVI_ATTR_VISA_RM_SESSION        /* ViSession,hidden      */     (IVI_ENGINE_PUBLIC_ATTR_BASE + 321)
#define IVI_ATTR_SYSTEM_IO_SESSION      /* ViSession,not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 322)
#define IVI_ATTR_IO_SESSION_TYPE        /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 324)
#define IVI_ATTR_SYSTEM_IO_TIMEOUT      /* ViInt32 */                   (IVI_ENGINE_PUBLIC_ATTR_BASE + 325)
#define IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS   /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 327)

#define IVI_ATTR_GROUP_CAPABILITIES     /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 401)
#define IVI_ATTR_FUNCTION_CAPABILITIES  /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 402)

#define IVI_ATTR_ENGINE_MAJOR_VERSION       /* ViInt32,  not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 501)
#define IVI_ATTR_ENGINE_MINOR_VERSION       /* ViInt32,  not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 502)
#define IVI_ATTR_SPECIFIC_DRIVER_MAJOR_VERSION /* ViInt32,  not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 503)
#define IVI_ATTR_SPECIFIC_DRIVER_MINOR_VERSION /* ViInt32,  not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 504)
#define IVI_ATTR_CLASS_DRIVER_MAJOR_VERSION /* ViInt32,  not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 505)
#define IVI_ATTR_CLASS_DRIVER_MINOR_VERSION /* ViInt32,  not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 506)

#define IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 510)
#define IVI_ATTR_INSTRUMENT_MANUFACTURER    /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 511)
#define IVI_ATTR_INSTRUMENT_MODEL           /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 512)
#define IVI_ATTR_SPECIFIC_DRIVER_VENDOR     /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 513)
#define IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION/* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 514)
#define IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION /* ViInt32, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 515)
#define IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION /* ViInt32, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 516)
#define IVI_ATTR_CLASS_DRIVER_VENDOR        /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 517)
#define IVI_ATTR_CLASS_DRIVER_DESCRIPTION   /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 518)
#define IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION /* ViInt32, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 519)
#define IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION /* ViInt32, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 520)

#define IVI_ATTR_SPECIFIC_DRIVER_REVISION   /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 551)
#define IVI_ATTR_CLASS_DRIVER_REVISION      /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 552)
#define IVI_ATTR_ENGINE_REVISION            /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 553)

#define IVI_ATTR_OPC_CALLBACK               /* ViAddr,    hidden */     (IVI_ENGINE_PUBLIC_ATTR_BASE + 602)  /* see Ivi_OPCCallbackPtr  typedef */
#define IVI_ATTR_CHECK_STATUS_CALLBACK      /* ViAddr,    hidden */     (IVI_ENGINE_PUBLIC_ATTR_BASE + 603)  /* see Ivi_CheckStatusCallbackPtr  typedef */

#define IVI_ATTR_USER_INTERCHANGE_CHECK_CALLBACK /* ViAddr, hidden */   (IVI_ENGINE_PUBLIC_ATTR_BASE + 801)  /* see Ivi_InterchangeCheckCallbackPtr typedef */

/*****************************************************************************/
/*= Public IVI Engine Functions                                     ======== */
/*= These functions have a function panel                                    */
/*****************************************************************************/
/*****************************************************************************/
/*= Specific   Drivers                                              ======== */
/*****************************************************************************/
ViStatus IviDll _VI_FUNC    Ivi_SpecificDriverNew(ViConstString specificPrefix, ViConstString optionsString, ViSession *vi);
ViStatus IviDll _VI_FUNC    Ivi_ApplyDefaultSetup (ViSession vi);
ViStatus IviDll _VI_FUNC    Ivi_GetSpecificDriverStatusDesc (ViSession vi, ViStatus statusCode, ViChar messageBuf[IVI_MAX_MESSAGE_BUF_SIZE],
                                                             IviStringValueTable additionalTableToSearch);

    /*= Status Checking Control                                     ======== */
ViBoolean IviDll _VI_FUNC   Ivi_NeedToCheckStatus(ViSession vi);
ViStatus  IviDll _VI_FUNC   Ivi_SetNeedToCheckStatus(ViSession vi, ViBoolean needToCheckStatus);

    /*= Instrument Specific Error Queue                            ========= */
ViStatus IviDll _VI_FUNC    Ivi_QueueInstrSpecificError(ViSession vi, ViInt32 instrumentError, ViConstString message);
ViStatus IviDll _VI_FUNC    Ivi_DequeueInstrSpecificError(ViSession vi, ViInt32 *instrumentError, ViChar message[IVI_MAX_MESSAGE_BUF_SIZE]);
ViStatus IviDll _VI_FUNC    Ivi_ClearInstrSpecificErrorQueue (ViSession vi);
ViStatus IviDll _VI_FUNC    Ivi_InstrSpecificErrorQueueSize(ViSession vi, ViInt32 *numErrors);

    /*= Direct Instrument I/O                                      ========= */
ViStatus  IviDll _VI_FUNC   Ivi_WriteInstrData (ViSession vi, ViConstString writeBuffer);
ViStatus  IviDll _VI_FUNC   Ivi_ReadInstrData (ViSession vi, ViInt32 numBytes, ViChar rdBuf[], ViInt32 *bytesRead);
ViStatus  IviDll _VI_FUNC   Ivi_ReadToFile (ViSession vi, ViConstString filename, ViInt32 maxBytesToRead,
                                            ViInt32 fileAction, ViInt32 *totalBytesWritten);
ViStatus  IviDll _VI_FUNC   Ivi_WriteFromFile (ViSession vi, ViConstString filename, ViInt32 maxBytesToWrite,
                                               ViInt32 byteOffset, ViInt32 *totalBytesWritten);
ViStatus  IviDll _VI_FUNC   Ivi_viWrite (ViSession vi, ViByte buffer[], ViInt64 count, ViInt64 *returnCount);
ViStatus  IviDll _VI_FUNC   Ivi_viRead (ViSession vi, ViInt64 bufferSize, ViByte buffer[], ViInt64 *returnCount);

    /*= IVI Class Compliant Driver Helpers                                == */
ViStatus  IviDll _VI_FUNC   Ivi_PerformClassInterchangeCheck (ViSession vi, ViInt32 classAPI, ViConstString funcName);

/*****************************************************************************/
/*= Class Drivers                                                   ======== */
/*****************************************************************************/
ViStatus  IviDll _VI_FUNC   Ivi_ClassDriverNew(ViConstString logicalOrVInstrName, ViConstString classPrefix, ViString functionList[], ViSession *vi);
ViStatus  IviDll _VI_FUNC   Ivi_ClassFunctionCapabilities (ViSession vi, IviStringValueTable functionTable, ViChar capabilityString[], ViBoolean *allFound);
ViStatus  IviDll _VI_FUNC   Ivi_GetClassDriverStatusDesc(ViSession vi, ViStatus statusCode, ViChar messageBuf[IVI_MAX_MESSAGE_BUF_SIZE], IviStringValueTable additionalTableToSearch);

    /*= Specific Driver Session                                     ======== */
ViSession IviDll _VI_FUNC   Ivi_SpecificDriverSession(ViSession vi);
ViStatus  IviDll _VI_FUNC   Ivi_SetSpecificDriverSession(ViSession vi, ViSession specificDriver);

    /*= Simulation Driver Management                                ======== */
ViStatus  IviDll _VI_FUNC   Ivi_LoadSimulationDriver(ViSession vi, ViConstString defaultSwModule, ViString functionList[]);
ViStatus  IviDll _VI_FUNC   Ivi_GetSimulationSession (ViSession vi, ViSession* simVi);
ViStatus  IviDll _VI_FUNC   Ivi_CloseSimulationSession (ViSession vi);

    /*= Dynamic Load and Dispatch                                   ======== */
ViStatus  IviDll _VI_FUNC   Ivi_GetFunctionPtr(ViSession vi, ViInt32 functionId, ViAddr *functionPtr);
ViStatus  IviDll _VI_FUNC   Ivi_GetFunctionPtrByName(ViSession vi, ViConstString name, ViBoolean addPrefix, ViAddr *functionPtr);
ViStatus  IviDll _VI_FUNC   Ivi_GetSimulationDriverFunctionPtr(ViSession vi, ViConstString functionName, ViAddr* functionPtr);

/*****************************************************************************/
/*= Simulation Drivers                                              ======== */
/*****************************************************************************/
ViStatus  IviDll _VI_FUNC   Ivi_SimulationDriverNew(ViConstString logicalName, ViSession *vi);
ViStatus  IviDll _VI_FUNC   Ivi_ApplySimulationDriverDefaultSetup (ViSession vi, ViConstString name);

/*****************************************************************************/
/*= Sessions                                                 ======== */
/*****************************************************************************/
ViStatus IviDll _VI_FUNC    Ivi_ValidateSession (ViSession vi);
ViBoolean IviDll _VI_FUNC   Ivi_SessionIsAvailable (ViSession vi);
ViStatus IviDll _VI_FUNC    Ivi_Dispose(ViSession vi);

    /*= Locking                                                     ======== */
ViStatus  IviDll _VI_FUNC   Ivi_LockSession(ViSession vi, ViBoolean *callerHasLock);
ViStatus  IviDll _VI_FUNC   Ivi_UnlockSession(ViSession vi, ViBoolean *callerHasLock);

/*****************************************************************************/
/*= Channels                                                        ======== */
/*****************************************************************************/
ViStatus  IviDll _VI_FUNC   Ivi_BuildChannelTable(ViSession vi, ViConstString defaultChannelList, ViBoolean allowUnknownChannelStrings, Ivi_ValidateChannelStringFunc chanStrValidationFunc);
ViStatus  IviDll _VI_FUNC   Ivi_AddToChannelTable(ViSession vi, ViConstString channelStringsToAdd);
ViStatus  IviDll _VI_FUNC   Ivi_RestrictAttrToChannels(ViSession vi, ViAttr attributeId, ViConstString channelNameList);
ViStatus  IviDll _VI_FUNC   Ivi_ValidateAttrForChannel(ViSession vi, ViConstString channelName, ViAttr attributeId);

ViStatus  IviDll _VI_FUNC   Ivi_CoerceChannelName(ViSession vi, ViConstString channelName, ViConstString *channelString);
ViStatus  IviDll _VI_FUNC   Ivi_GetChannelIndex (ViSession vi, ViConstString channelName, ViInt32 *index);  /* 1-based index */
ViStatus  IviDll _VI_FUNC   Ivi_GetNthChannelString(ViSession vi, ViInt32 index, ViConstString *channelString);  /* 1-based index */
ViStatus  IviDll _VI_FUNC   Ivi_GetUserChannelName(ViSession vi, ViConstString channelString, ViConstString *userChannelName);

/*****************************************************************************/
/*= Repeated Capabilities                                           ======== */
/*****************************************************************************/
ViStatus IviDll _VI_FUNC    Ivi_BuildRepCapTable(ViSession vi, ViConstString repCapName, ViConstString names);
ViStatus IviDll _VI_FUNC    Ivi_AddToRepCapTable(ViSession vi, ViConstString repCapName, ViConstString namesToAdd);
ViStatus IviDll _VI_FUNC    Ivi_RestrictAttrToInstances(ViSession vi, ViAttr attributeId, ViConstString instances);
ViStatus IviDll _VI_FUNC    Ivi_ValidateAttrForRepCapName(ViSession vi, ViConstString repCapName, ViAttr attributeId);

ViStatus IviDll _VI_FUNC    Ivi_CoerceRepCapName(ViSession vi, ViConstString repCapName, ViConstString name, ViConstString *actualNameRef);
ViStatus IviDll _VI_FUNC    Ivi_GetRepCapIndex (ViSession vi, ViConstString repCapName, ViConstString name,  ViInt32 *indexRef);
ViStatus IviDll _VI_FUNC    Ivi_GetNthRepCapName(ViSession vi, ViConstString repCapName, ViInt32 index, ViConstString *nameRef);
ViStatus IviDll _VI_FUNC    Ivi_GetAttributeRepCapName(ViSession vi, ViAttr attributeId, ViConstString *repCapName);

/*****************************************************************************/
/*= Attributes                                                      ======== */
/*****************************************************************************/
ViStatus IviDll _VI_FUNC    Ivi_ValidateAttribute(ViSession vi, ViAttr attrId, IviValueType expectedType);
ViBoolean IviDll _VI_FUNC   Ivi_AttributeIsAvailable(ViSession vi, ViAttr attrId);
ViStatus IviDll _VI_FUNC    Ivi_ResetAttribute(ViSession vi, ViConstString repCapName, ViAttr attributeId);
ViStatus IviDll _VI_FUNC    Ivi_DeleteAttribute(ViSession vi, ViAttr attributeId);

    /*= Creation                                                    ======== */
ViStatus IviDll _VI_FUNC    Ivi_AddAttributeViInt32(ViSession                       vi,
                                                    ViAttr                          id,
                                                    ViConstString                   attrName,
                                                    ViInt32                         defaultValue,
                                                    IviAttrFlags                    attributeFlags,
                                                    ReadAttrViInt32_CallbackPtr     readCallback,
                                                    WriteAttrViInt32_CallbackPtr    writeCallback,
                                                    IviRangeTablePtr                rangeTable);
#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus IviDll _VI_FUNC    Ivi_AddAttributeViInt64(ViSession                       vi,
                                                    ViAttr                          id,
                                                    ViConstString                   attrName,
                                                    ViInt64                         defaultValue,
                                                    IviAttrFlags                    attributeFlags,
                                                    ReadAttrViInt64_CallbackPtr     readCallback,
                                                    WriteAttrViInt64_CallbackPtr    writeCallback,
                                                    IviRangeTablePtr                rangeTable);
#endif
ViStatus IviDll _VI_FUNC    Ivi_AddAttributeViReal64(ViSession                       vi,
                                                     ViAttr                          id,
                                                     ViConstString                   attrName,
                                                     ViReal64                        defaultValue,
                                                     IviAttrFlags                    attributeFlags,
                                                     ReadAttrViReal64_CallbackPtr    readCallback,
                                                     WriteAttrViReal64_CallbackPtr   writeCallback,
                                                     IviRangeTablePtr                rangeTable,
                                                     ViInt32                         comparePrecision);

ViStatus IviDll _VI_FUNC    Ivi_AddAttributeViString(ViSession                       vi,
                                                     ViAttr                          id,
                                                     ViConstString                   attrName,
                                                     ViConstString                   defaultValue,
                                                     IviAttrFlags                    attributeFlags,
                                                     ReadAttrViString_CallbackPtr    readCallback,
                                                     WriteAttrViString_CallbackPtr   writeCallback);

ViStatus IviDll _VI_FUNC    Ivi_AddAttributeViBoolean(  ViSession                       vi,
                                                        ViAttr                          id,
                                                        ViConstString                   attrName,
                                                        ViBoolean                       defaultValue,
                                                        IviAttrFlags                    attributeFlags,
                                                        ReadAttrViBoolean_CallbackPtr   readCallback,
                                                        WriteAttrViBoolean_CallbackPtr  writeCallback);

ViStatus IviDll _VI_FUNC    Ivi_AddAttributeViSession(  ViSession                       vi,
                                                        ViAttr                          id,
                                                        ViConstString                   attrName,
                                                        ViSession                       defaultValue,
                                                        IviAttrFlags                    attributeFlags,
                                                        ReadAttrViSession_CallbackPtr   readCallback,
                                                        WriteAttrViSession_CallbackPtr  writeCallback);

ViStatus IviDll _VI_FUNC    Ivi_AddAttributeViAddr( ViSession                       vi,
                                                    ViAttr                          id,
                                                    ViConstString                   attrName,
                                                    ViAddr                          defaultValue,
                                                    IviAttrFlags                    attributeFlags,
                                                    ReadAttrViAddr_CallbackPtr      readCallback,
                                                    WriteAttrViAddr_CallbackPtr     writeCallback);

ViStatus IviDll _VI_FUNC    Ivi_AddRepeatedAttributeViInt32(ViSession                       vi,
                                                            ViConstString                   repCapName,
                                                            ViAttr                          id,
                                                            ViConstString                   attrName,
                                                            ViInt32                         defaultValue,
                                                            IviAttrFlags                    attributeFlags,
                                                            ReadAttrViInt32_CallbackPtr     readCallback,
                                                            WriteAttrViInt32_CallbackPtr    writeCallback,
                                                            IviRangeTablePtr                rangeTable);
#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus IviDll _VI_FUNC    Ivi_AddRepeatedAttributeViInt64(   ViSession                       vi,
                                                            ViConstString                   repCapName,
                                                            ViAttr                          id,
                                                            ViConstString                   attrName,
                                                            ViInt64                         defaultValue,
                                                            IviAttrFlags                    attributeFlags,
                                                            ReadAttrViInt64_CallbackPtr     readCallback,
                                                            WriteAttrViInt64_CallbackPtr    writeCallback,
                                                            IviRangeTablePtr                rangeTable);
#endif
ViStatus IviDll _VI_FUNC    Ivi_AddRepeatedAttributeViReal64(  ViSession                       vi,
                                                                ViConstString                   repCapName,
                                                                ViAttr                          id,
                                                                ViConstString                   attrName,
                                                                ViReal64                        defaultValue,
                                                                IviAttrFlags                    attributeFlags,
                                                                ReadAttrViReal64_CallbackPtr    readCallback,
                                                                WriteAttrViReal64_CallbackPtr   writeCallback,
                                                                IviRangeTablePtr                rangeTable,
                                                                ViInt32                         comparePrecision);

ViStatus IviDll _VI_FUNC    Ivi_AddRepeatedAttributeViString(  ViSession                       vi,
                                                                ViConstString                   repCapName,
                                                                ViAttr                          id,
                                                                ViConstString                   attrName,
                                                                ViConstString                   defaultValue,
                                                                IviAttrFlags                    attributeFlags,
                                                                ReadAttrViString_CallbackPtr    readCallback,
                                                                WriteAttrViString_CallbackPtr   writeCallback);

ViStatus IviDll _VI_FUNC    Ivi_AddRepeatedAttributeViBoolean( ViSession                       vi,
                                                                ViConstString                   repCapName,
                                                                ViAttr                          id,
                                                                ViConstString                   attrName,
                                                                ViBoolean                       defaultValue,
                                                                IviAttrFlags                    attributeFlags,
                                                                ReadAttrViBoolean_CallbackPtr   readCallback,
                                                                WriteAttrViBoolean_CallbackPtr  writeCallback);

ViStatus IviDll _VI_FUNC    Ivi_AddRepeatedAttributeViSession( ViSession                       vi,
                                                                ViConstString                   repCapName,
                                                                ViAttr                          id,
                                                                ViConstString                   attrName,
                                                                ViSession                       defaultValue,
                                                                IviAttrFlags                    attributeFlags,
                                                                ReadAttrViSession_CallbackPtr   readCallback,
                                                                WriteAttrViSession_CallbackPtr  writeCallback);

ViStatus IviDll _VI_FUNC    Ivi_AddRepeatedAttributeViAddr(ViSession                       vi,
                                                            ViConstString                   repCapName,
                                                            ViAttr                          id,
                                                            ViConstString                   attrName,
                                                            ViAddr                          defaultValue,
                                                            IviAttrFlags                    attributeFlags,
                                                            ReadAttrViAddr_CallbackPtr      readCallback,
                                                            WriteAttrViAddr_CallbackPtr     writeCallback);


    /*= Set/Get/Check Attribute                                         ======== */
        /*= Typesafe Set Attribute functions for use in drivers         ======== */
ViStatus IviDll _VI_FUNC    Ivi_SetAttributeViInt32(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 optionFlags, ViInt32 value);
#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus IviDll _VI_FUNC    Ivi_SetAttributeViInt64(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 optionFlags, ViInt64 value);
#endif
ViStatus IviDll _VI_FUNC    Ivi_SetAttributeViReal64(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 optionFlags, ViReal64 value);
ViStatus IviDll _VI_FUNC    Ivi_SetAttributeViString(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 optionFlags, ViConstString value);
ViStatus IviDll _VI_FUNC    Ivi_SetAttributeViBoolean(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 optionFlags, ViBoolean value);
ViStatus IviDll _VI_FUNC    Ivi_SetAttributeViSession(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 optionFlags, ViSession value);
ViStatus IviDll _VI_FUNC    Ivi_SetAttributeViAddr(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 optionFlags, ViAddr value);

        /*= Typesafe Check Attribute functions for use in drivers       ======== */
ViStatus IviDll _VI_FUNC    Ivi_CheckAttributeViInt32(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 optionFlags, ViInt32 value);
#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus IviDll _VI_FUNC    Ivi_CheckAttributeViInt64(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 optionFlags, ViInt64 value);
#endif
ViStatus IviDll _VI_FUNC    Ivi_CheckAttributeViReal64(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 optionFlags, ViReal64 value);
ViStatus IviDll _VI_FUNC    Ivi_CheckAttributeViString(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 optionFlags, ViConstString value);
ViStatus IviDll _VI_FUNC    Ivi_CheckAttributeViBoolean(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 optionFlags, ViBoolean value);
ViStatus IviDll _VI_FUNC    Ivi_CheckAttributeViSession(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 optionFlags, ViSession value);
ViStatus IviDll _VI_FUNC    Ivi_CheckAttributeViAddr(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 optionFlags, ViAddr value);

        /*= Typesafe Get Attribute functions for use in drivers         ======== */
ViStatus IviDll _VI_FUNC    Ivi_GetAttributeViInt32(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 optionFlags, ViInt32 *value);
#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus IviDll _VI_FUNC    Ivi_GetAttributeViInt64(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 optionFlags, ViInt64 *value);
#endif
ViStatus IviDll _VI_FUNC    Ivi_GetAttributeViReal64(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 optionFlags, ViReal64 *value);
ViStatus IviDll _VI_FUNC    Ivi_GetAttributeViString(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 optionFlags, ViInt32 bufSize, ViChar value[]);
ViStatus IviDll _VI_FUNC    Ivi_GetAttributeViBoolean(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 optionFlags, ViBoolean *value);
ViStatus IviDll _VI_FUNC    Ivi_GetAttributeViSession(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 optionFlags, ViSession *value);
ViStatus IviDll _VI_FUNC    Ivi_GetAttributeViAddr(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 optionFlags, ViAddr *value);

        /*= State Caching/Invalidations                                 ======== */
ViStatus IviDll _VI_FUNC    Ivi_InvalidateAttribute(ViSession vi, ViConstString repCapName, ViAttr attributeId);
ViStatus IviDll _VI_FUNC    Ivi_InvalidateAllAttributes(ViSession vi);

ViStatus IviDll _VI_FUNC    Ivi_AddAttributeInvalidation(ViSession vi, ViAttr attributeId, ViAttr attributeToInval, ViBoolean allChannels);
ViStatus IviDll _VI_FUNC    Ivi_DeleteAttributeInvalidation(ViSession vi, ViAttr attributeId, ViAttr attributeToDelete);
ViStatus IviDll _VI_FUNC    Ivi_GetInvalidationList(ViSession vi, ViAttr attributeId, IviInvalEntry **invalList, ViInt32 *numInvalEntries);
void     IviDll _VI_FUNC    Ivi_DisposeInvalidationList(IviInvalEntry *invalList);

ViStatus IviDll _VI_FUNC    Ivi_AttributeIsCached(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViBoolean *instrStateIsCurrentlyCached);

    /*= Coercion                                                    ======== */
ViStatus IviDll _VI_FUNC    Ivi_GetCoercedValViInt32(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 value, ViInt32 *coercedValue);
ViStatus IviDll _VI_FUNC    Ivi_GetCoercedValViReal64(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViReal64 value, ViReal64 *coercedValue);
ViStatus IviDll _VI_FUNC    Ivi_GetNextCoercionInfo(ViSession vi, ViAttr *attributeId, ViConstString *attributeName, ViConstString *channelString,
                                                  IviValueType *attrType, ViReal64 *desiredValue, ViReal64 *coercedValue);
ViStatus IviDll _VI_FUNC    Ivi_GetNextCoercionString (ViSession vi, ViInt32 bufSize, ViChar coercion[]);

    /*= Callbacks                                                   ======== */
        /*= One function is needed because it is typesafe for all attribute types */
ViStatus IviDll _VI_FUNC    Ivi_SetAttrRangeTableCallback (ViSession vi, ViAttr attributeId, RangeTable_CallbackPtr rangeTableCallback);

        /*= Default callbacks                                              ========= */
        /*= Prototypes for functions supplied as default callbacks.        ========= */
        /*= These default callbacks are installed when an attribute is     ========= */
        /*= added by the class or specific driver using one of the         ========= */
        /*= AddAttribute functions.                                        ========= */
        /*= For ViInt32 and ViReal64, the Default Check callback is        ========= */
        /*= installed when the attribute is added with a range table.      ========= */
        /*= If the range table is of type IVI_VAL_COERCED,                 ========= */
        /*= the Default Coerce callback is also installed.                 ========= */
        /*= For ViReal64, the Default Compare callback is always installed.========= */
        /*= For ViBoolean, the Default Coerce callback is always installed.========= */
        /*= Do not call these functions directly unless you have already   ========= */
        /*= Ivi_LockSession().                                             ========= */
ViStatus IviDll _VI_FUNC    Ivi_DefaultCheckCallbackViInt32    (ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 value);
ViStatus IviDll _VI_FUNC    Ivi_DefaultCoerceCallbackViInt32   (ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt32 value, ViInt32 *coercedValue);
#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus IviDll _VI_FUNC    Ivi_DefaultCheckCallbackViInt64    (ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt64 value);
ViStatus IviDll _VI_FUNC    Ivi_DefaultCoerceCallbackViInt64   (ViSession vi, ViConstString repCapName, ViAttr attributeId, ViInt64 value, ViInt64 *coercedValue);
#endif
ViStatus IviDll _VI_FUNC    Ivi_DefaultCheckCallbackViReal64   (ViSession vi, ViConstString repCapName, ViAttr attributeId, ViReal64 value);
ViStatus IviDll _VI_FUNC    Ivi_DefaultCoerceCallbackViReal64  (ViSession vi, ViConstString repCapName, ViAttr attributeId, ViReal64 value, ViReal64 *coercedValue);
ViStatus IviDll _VI_FUNC    Ivi_DefaultCompareCallbackViReal64 (ViSession vi, ViConstString repCapName, ViAttr attributeId, ViReal64 a, ViReal64 b, ViInt32 *result);
ViStatus IviDll _VI_FUNC    Ivi_DefaultCoerceCallbackViBoolean (ViSession vi, ViConstString repCapName, ViAttr attributeId, ViBoolean value, ViBoolean *coercedValue);

        /*= Set Attribute Read Callback functions                   ======== */
ViStatus IviDll _VI_FUNC    Ivi_SetAttrReadCallbackViInt32   (ViSession vi, ViAttr attributeId, ReadAttrViInt32_CallbackPtr readCallback);
#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus IviDll _VI_FUNC    Ivi_SetAttrReadCallbackViInt64   (ViSession vi, ViAttr attributeId, ReadAttrViInt64_CallbackPtr readCallback);
#endif
ViStatus IviDll _VI_FUNC    Ivi_SetAttrReadCallbackViReal64  (ViSession vi, ViAttr attributeId, ReadAttrViReal64_CallbackPtr readCallback);
ViStatus IviDll _VI_FUNC    Ivi_SetAttrReadCallbackViString  (ViSession vi, ViAttr attributeId, ReadAttrViString_CallbackPtr readCallback);
ViStatus IviDll _VI_FUNC    Ivi_SetAttrReadCallbackViBoolean (ViSession vi, ViAttr attributeId, ReadAttrViBoolean_CallbackPtr readCallback);
ViStatus IviDll _VI_FUNC    Ivi_SetAttrReadCallbackViSession (ViSession vi, ViAttr attributeId, ReadAttrViSession_CallbackPtr readCallback);
ViStatus IviDll _VI_FUNC    Ivi_SetAttrReadCallbackViAddr    (ViSession vi, ViAttr attributeId, ReadAttrViAddr_CallbackPtr readCallback);

        /*= Set Attribute Write Callback functions                  ======== */
ViStatus IviDll _VI_FUNC    Ivi_SetAttrWriteCallbackViInt32   (ViSession vi, ViAttr attributeId, WriteAttrViInt32_CallbackPtr writeCallback);
#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus IviDll _VI_FUNC    Ivi_SetAttrWriteCallbackViInt64   (ViSession vi, ViAttr attributeId, WriteAttrViInt64_CallbackPtr writeCallback);
#endif
ViStatus IviDll _VI_FUNC    Ivi_SetAttrWriteCallbackViReal64  (ViSession vi, ViAttr attributeId, WriteAttrViReal64_CallbackPtr writeCallback);
ViStatus IviDll _VI_FUNC    Ivi_SetAttrWriteCallbackViString  (ViSession vi, ViAttr attributeId, WriteAttrViString_CallbackPtr writeCallback);
ViStatus IviDll _VI_FUNC    Ivi_SetAttrWriteCallbackViBoolean (ViSession vi, ViAttr attributeId, WriteAttrViBoolean_CallbackPtr writeCallback);
ViStatus IviDll _VI_FUNC    Ivi_SetAttrWriteCallbackViSession (ViSession vi, ViAttr attributeId, WriteAttrViSession_CallbackPtr writeCallback);
ViStatus IviDll _VI_FUNC    Ivi_SetAttrWriteCallbackViAddr    (ViSession vi, ViAttr attributeId, WriteAttrViAddr_CallbackPtr writeCallback);

        /*= Set Attribute Check Callback functions                  ======== */
ViStatus IviDll _VI_FUNC    Ivi_SetAttrCheckCallbackViInt32   (ViSession vi, ViAttr attributeId, CheckAttrViInt32_CallbackPtr checkCallback);
#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus IviDll _VI_FUNC    Ivi_SetAttrCheckCallbackViInt64   (ViSession vi, ViAttr attributeId, CheckAttrViInt64_CallbackPtr checkCallback);
#endif
ViStatus IviDll _VI_FUNC    Ivi_SetAttrCheckCallbackViReal64  (ViSession vi, ViAttr attributeId, CheckAttrViReal64_CallbackPtr checkCallback);
ViStatus IviDll _VI_FUNC    Ivi_SetAttrCheckCallbackViString  (ViSession vi, ViAttr attributeId, CheckAttrViString_CallbackPtr checkCallback);
ViStatus IviDll _VI_FUNC    Ivi_SetAttrCheckCallbackViBoolean (ViSession vi, ViAttr attributeId, CheckAttrViBoolean_CallbackPtr checkCallback);
ViStatus IviDll _VI_FUNC    Ivi_SetAttrCheckCallbackViSession (ViSession vi, ViAttr attributeId, CheckAttrViSession_CallbackPtr checkCallback);
ViStatus IviDll _VI_FUNC    Ivi_SetAttrCheckCallbackViAddr    (ViSession vi, ViAttr attributeId, CheckAttrViAddr_CallbackPtr checkCallback);

        /*= Set Attribute Coerce Callback functions                 ======== */
ViStatus IviDll _VI_FUNC    Ivi_SetAttrCoerceCallbackViInt32   (ViSession vi, ViAttr attributeId, CoerceAttrViInt32_CallbackPtr coerceCallback);
#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus IviDll _VI_FUNC    Ivi_SetAttrCoerceCallbackViInt64   (ViSession vi, ViAttr attributeId, CoerceAttrViInt64_CallbackPtr coerceCallback);
#endif
ViStatus IviDll _VI_FUNC    Ivi_SetAttrCoerceCallbackViReal64  (ViSession vi, ViAttr attributeId, CoerceAttrViReal64_CallbackPtr coerceCallback);
ViStatus IviDll _VI_FUNC    Ivi_SetAttrCoerceCallbackViString  (ViSession vi, ViAttr attributeId, CoerceAttrViString_CallbackPtr coerceCallback);
ViStatus IviDll _VI_FUNC    Ivi_SetAttrCoerceCallbackViBoolean (ViSession vi, ViAttr attributeId, CoerceAttrViBoolean_CallbackPtr coerceCallback);
ViStatus IviDll _VI_FUNC    Ivi_SetAttrCoerceCallbackViAddr    (ViSession vi, ViAttr attributeId, CoerceAttrViAddr_CallbackPtr coerceCallback);
ViStatus IviDll _VI_FUNC    Ivi_SetAttrCoerceCallbackViSession (ViSession vi, ViAttr attributeId, CoerceAttrViSession_CallbackPtr coerceCallback);

        /*= Set Attribute Compare Callback functions                ======== */
ViStatus IviDll _VI_FUNC    Ivi_SetAttrCompareCallbackViInt32   (ViSession vi, ViAttr attributeId, CompareAttrViInt32_CallbackPtr compareCallback);
#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus IviDll _VI_FUNC    Ivi_SetAttrCompareCallbackViInt64   (ViSession vi, ViAttr attributeId, CompareAttrViInt64_CallbackPtr compareCallback);
#endif
ViStatus IviDll _VI_FUNC    Ivi_SetAttrCompareCallbackViReal64  (ViSession vi, ViAttr attributeId, CompareAttrViReal64_CallbackPtr compareCallback);
ViStatus IviDll _VI_FUNC    Ivi_SetAttrCompareCallbackViString  (ViSession vi, ViAttr attributeId, CompareAttrViString_CallbackPtr compareCallback);
ViStatus IviDll _VI_FUNC    Ivi_SetAttrCompareCallbackViBoolean (ViSession vi, ViAttr attributeId, CompareAttrViBoolean_CallbackPtr compareCallback);
ViStatus IviDll _VI_FUNC    Ivi_SetAttrCompareCallbackViSession (ViSession vi, ViAttr attributeId, CompareAttrViSession_CallbackPtr compareCallback);
ViStatus IviDll _VI_FUNC    Ivi_SetAttrCompareCallbackViAddr    (ViSession vi, ViAttr attributeId, CompareAttrViAddr_CallbackPtr compareCallback);

    /*= Inherent Attribute Accessors                                ======== */
ViSession IviDll _VI_FUNC   Ivi_IOSession (ViSession vi);
ViBoolean IviDll _VI_FUNC   Ivi_RangeChecking (ViSession vi);
ViBoolean IviDll _VI_FUNC   Ivi_QueryInstrStatus(ViSession vi);
ViBoolean IviDll _VI_FUNC   Ivi_Simulating(ViSession vi);
ViBoolean IviDll _VI_FUNC   Ivi_UseSpecificSimulation(ViSession vi);
ViBoolean IviDll _VI_FUNC   Ivi_Spying(ViSession vi);
ViBoolean IviDll _VI_FUNC   Ivi_InterchangeCheck(ViSession vi);

    /*= Comparison Precision                                        ======== */
ViStatus  IviDll _VI_FUNC   Ivi_SetAttrComparePrecision (ViSession vi, ViAttr attributeId, ViInt32 comparePrecision);
ViStatus  IviDll _VI_FUNC   Ivi_GetAttrComparePrecision (ViSession vi, ViAttr attributeId, ViInt32 *comparePrecision);

    /*= Information                                                 ======== */
ViStatus  IviDll _VI_FUNC   Ivi_GetNumAttributes(ViSession vi, ViInt32 *numAttributes);
ViStatus  IviDll _VI_FUNC   Ivi_GetNthAttribute(ViSession vi, ViInt32 index, ViAttr *attribute);
ViStatus  IviDll _VI_FUNC   Ivi_GetAttributeFlags(ViSession vi, ViAttr attributeId, IviAttrFlags *flags);
ViStatus  IviDll _VI_FUNC   Ivi_SetAttributeFlags(ViSession iviSession, ViAttr attributeId, IviAttrFlags flags);
ViStatus  IviDll _VI_FUNC   Ivi_GetAttributeType(ViSession vi, ViAttr attributeId, IviValueType *type);
ViStatus  IviDll _VI_FUNC   Ivi_GetAttributeName(ViSession vi, ViAttr attributeId, ViChar nameBuf[], ViInt32 bufSize);
ViStatus  IviDll _VI_FUNC   Ivi_GetAttrMinMaxViInt32(ViSession vi, ViConstString repCapName, ViAttr attr, ViInt32 *min, ViInt32 *max, ViBoolean *hasMin, ViBoolean *hasMax);
#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus  IviDll _VI_FUNC   Ivi_GetAttrMinMaxViInt64(ViSession vi, ViConstString repCapName, ViAttr attr, ViInt64 *min, ViInt64 *max, ViBoolean *hasMin, ViBoolean *hasMax);
#endif
ViStatus  IviDll _VI_FUNC   Ivi_GetAttrMinMaxViReal64(ViSession vi, ViConstString repCapName, ViAttr attr, ViReal64 *min, ViReal64 *max, ViBoolean *hasMin, ViBoolean *hasMax);
ViBoolean IviDll _VI_FUNC   Ivi_AttributeWasSetByUser (ViSession vi, ViConstString repCapName, ViAttr attributeId);
ViBoolean IviDll _VI_FUNC   Ivi_AttributeEverSetByUser (ViSession vi, ViConstString repCapName, ViAttr attributeId);

/*****************************************************************************/
/*= Error Information                                              ========= */
/*****************************************************************************/
ViStatus IviDll _VI_FUNC    Ivi_SetErrorInfo(ViSession vi, ViBoolean overWrite, ViStatus primaryError, ViStatus secondaryError, ViConstString errorElaboration);
ViStatus IviDll _VI_FUNC    Ivi_GetErrorInfo(ViSession vi, ViStatus *primaryError, ViStatus *secondaryError, ViChar errorElaboration[IVI_MAX_MESSAGE_BUF_SIZE]);
ViStatus IviDll _VI_FUNC    Ivi_ClearErrorInfo(ViSession vi);
ViStatus IviDll _VI_FUNC    Ivi_GetErrorMessage(ViStatus statusCode, ViChar messageBuf[IVI_MAX_MESSAGE_BUF_SIZE]);

/*****************************************************************************/
/*= Range Tables                                                    ======== */
/*****************************************************************************/
    /*  GetAttrRangeTable gets the range table that the engine uses for the  */
    /*  attribute. If there is a RangeTableCallback, GetAttrRangeTable       */
    /*  callback invokes it. Otherwise, it returns the stored range table    */
    /*  pointer.                                                             */
ViStatus  IviDll _VI_FUNC   Ivi_GetAttrRangeTable (ViSession vi, ViConstString repCapName, ViAttr attributeId, IviRangeTablePtr *rangeTable);
ViStatus  IviDll _VI_FUNC   Ivi_ValidateRangeTable (IviRangeTablePtr rangeTable);

    /*= Range Table Entries                                         ======== */
ViStatus  IviDll _VI_FUNC   Ivi_GetRangeTableNumEntries (IviRangeTablePtr table, ViInt32 *numEntries);

ViStatus  IviDll _VI_FUNC   Ivi_GetViInt32EntryFromValue (ViInt32 value, IviRangeTablePtr table, ViInt32 *discreteOrMin, ViInt32 *max,
                                                          ViInt32 *coercedValue, ViInt32 *tableIndex, ViString *cmdString, ViInt32 *cmdValue);
ViStatus  IviDll _VI_FUNC   Ivi_GetViInt32EntryFromString (ViConstString cmdString, IviRangeTablePtr table, ViInt32 *discreteOrMin, ViInt32 *max,
                                                           ViInt32 *coercedValue, ViInt32 *tableIndex, ViInt32 *cmdValue);
ViStatus  IviDll _VI_FUNC   Ivi_GetViInt32EntryFromIndex (ViInt32 tableIndex, IviRangeTablePtr table, ViInt32 *discreteOrMin, ViInt32 *max,
                                                          ViInt32 *coercedValue, ViString *cmdString, ViInt32 *cmdValue);
ViStatus  IviDll _VI_FUNC   Ivi_GetViInt32EntryFromCmdValue (ViInt32 cmdValue, IviRangeTablePtr table, ViInt32 *discreteOrMin, ViInt32 *max,
                                                             ViInt32 *coercedValue, ViInt32 *tableIndex, ViString *cmdString);
ViStatus  IviDll _VI_FUNC   Ivi_GetViInt32EntryFromCoercedVal (ViInt32 coercedValue, IviRangeTablePtr table, ViInt32 *discreteOrMin, ViInt32 *max,
                                                               ViInt32 *tableIndex, ViString *cmdString, ViInt32 *cmdValue);

#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus  IviDll _VI_FUNC   Ivi_GetViInt64EntryFromValue (ViInt64 value, IviRangeTablePtr table, ViInt64 *discreteOrMin, ViInt64 *max,
                                                          ViInt64 *coercedValue, ViInt32 *tableIndex, ViString *cmdString, ViInt32 *cmdValue);
ViStatus  IviDll _VI_FUNC   Ivi_GetViInt64EntryFromString (ViConstString cmdString, IviRangeTablePtr table, ViInt64 *discreteOrMin, ViInt64 *max,
                                                           ViInt64 *coercedValue, ViInt32 *tableIndex, ViInt32 *cmdValue);
ViStatus  IviDll _VI_FUNC   Ivi_GetViInt64EntryFromIndex (ViInt32 tableIndex, IviRangeTablePtr table, ViInt64 *discreteOrMin, ViInt64 *max,
                                                          ViInt64 *coercedValue, ViString *cmdString, ViInt32 *cmdValue);
ViStatus  IviDll _VI_FUNC   Ivi_GetViInt64EntryFromCmdValue (ViInt32 cmdValue, IviRangeTablePtr table, ViInt64 *discreteOrMin, ViInt64 *max,
                                                             ViInt64 *coercedValue, ViInt32 *tableIndex, ViString *cmdString);
ViStatus  IviDll _VI_FUNC   Ivi_GetViInt64EntryFromCoercedVal (ViInt64 coercedValue, IviRangeTablePtr table, ViInt64 *discreteOrMin, ViInt64 *max,
                                                              ViInt32 *tableIndex, ViString *cmdString, ViInt32 *cmdValue);
#endif

ViStatus  IviDll _VI_FUNC   Ivi_GetViReal64EntryFromValue (ViReal64 value, IviRangeTablePtr table, ViReal64 *discreteOrMin, ViReal64 *max,
                                                           ViReal64 *coercedValue, ViInt32 *tableIndex, ViString *cmdString, ViInt32 *cmdValue);
ViStatus  IviDll _VI_FUNC   Ivi_GetViReal64EntryFromString (ViConstString cmdString, IviRangeTablePtr table, ViReal64 *discreteOrMin,
                                                            ViReal64 *max, ViReal64 *coercedValue, ViInt32 *tableIndex, ViInt32 *cmdValue);
ViStatus  IviDll _VI_FUNC   Ivi_GetViReal64EntryFromIndex (ViInt32 tableIndex, IviRangeTablePtr table, ViReal64 *discreteOrMin,
                                                           ViReal64 *max, ViReal64 *coercedValue, ViString *cmdString, ViInt32 *cmdValue);
ViStatus  IviDll _VI_FUNC   Ivi_GetViReal64EntryFromCmdValue (ViInt32 cmdVal, IviRangeTablePtr table, ViReal64 *discreteOrMin, ViReal64 *max,
                                                              ViReal64 *coercedValue, ViInt32 *tableIndex, ViString *cmdString);
ViStatus  IviDll _VI_FUNC   Ivi_GetViReal64EntryFromCoercedVal (ViReal64 coercedValue, IviRangeTablePtr table, ViReal64 *discreteOrMin, ViReal64 *max,
                                                               ViInt32 *tableIndex, ViString *cmdString, ViInt32 *cmdValue);

    /*= Range Table Pointer                                         ======== */
ViStatus  IviDll _VI_FUNC   Ivi_GetStoredRangeTablePtr (ViSession vi, ViAttr attributeId, IviRangeTablePtr *rangeTable);  /* bypasses callback */
ViStatus  IviDll _VI_FUNC   Ivi_SetStoredRangeTablePtr (ViSession vi, ViAttr attributeId, IviRangeTablePtr  rangeTable);

    /*= Dynamic Range Tables                                        ======== */
ViStatus  IviDll _VI_FUNC   Ivi_RangeTableNew (ViSession vi, ViInt32 numRangeValueEntries, ViInt32 type, ViBoolean hasMin,
                                               ViBoolean hasMax, IviRangeTablePtr *rangeTable);
ViStatus  IviDll _VI_FUNC   Ivi_RangeTableFree (ViSession vi, IviRangeTablePtr rangeTable, ViBoolean freeCmdStrings);
ViStatus  IviDll _VI_FUNC   Ivi_SetRangeTableEntry (IviRangeTablePtr rangeTable, ViInt32 tableIndex, ViReal64 discreteOrMin,
                                                    ViReal64 max, ViReal64 coercedValue, ViConstString cmdString, ViInt32 cmdValue);
#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus  IviDll _VI_FUNC   Ivi_SetRangeTableEntryViInt64 (IviRangeTablePtr rangeTable, ViInt32 tableIndex, ViInt64 discreteOrMin,
                                                           ViInt64 max, ViInt64 coercedValue, ViConstString cmdString, ViInt32 cmdValue);
#endif
ViStatus  IviDll _VI_FUNC   Ivi_SetRangeTableEnd (IviRangeTablePtr rangeTable, ViInt32 endIndex);

/*****************************************************************************/
/*= Configuration Store                                             ======== */
/*****************************************************************************/
ViStatus  IviDll _VI_FUNC   Ivi_GetConfigStoreHandle(IviConfigStoreHandle* handle);
ViStatus  IviDll _VI_FUNC   Ivi_AttachToConfigStoreHandle (IviConfigStoreHandle handle, ViBoolean discardExistingHandle);
ViStatus  IviDll _VI_FUNC   Ivi_GetInfoFromResourceName(ViRsrc resourceName, ViString optionString,
                                                        ViChar newResourceName[IVI_MAX_MESSAGE_BUF_SIZE],
                                                        ViChar newOptionString[IVI_MAX_MESSAGE_BUF_SIZE],
                                                        ViBoolean *isLogicalName);
    /*= Logical Names                                               ======== */
ViStatus  IviDll _VI_FUNC   Ivi_GetLogicalNamesList(IviLogicalNameEntry **logicalNamesList, ViInt32 *numLogicalNames);
ViStatus  IviDll _VI_FUNC   Ivi_GetNthLogicalName(IviLogicalNameEntry *logicalNamesList, ViInt32 index, ViChar nameBuf[], ViInt32 bufSize, ViBoolean *fromFile);
void      IviDll _VI_FUNC   Ivi_DisposeLogicalNamesList(IviLogicalNameEntry *logicalNamesList);

/*****************************************************************************/
/*= Interchangeability Warnings                                     ======== */
/*****************************************************************************/
ViStatus  IviDll _VI_FUNC   Ivi_GetNextInterchangeCheckString (ViSession vi, ViInt32 bufSize, ViChar interchangeWarning[]);
ViStatus  IviDll _VI_FUNC   Ivi_ClearInterchangeWarnings (ViSession vi);
ViStatus  IviDll _VI_FUNC   Ivi_ResetInterchangeCheck (ViSession vi);
ViStatus  IviDll _VI_FUNC   Ivi_LogInterchangeWarning (ViSession vi, ViInt32 warningType, ViInt32 funcEnum, ViConstString repCapName, ViAttr attributeId, ViConstString elab);

/*****************************************************************************/
/*= Helper Functions                                                ======== */
/*****************************************************************************/
    /*= Memory Allocation                                               ======== */
    /*= Functions for allocating memory dynamically                     ======== */
    /*= and associating it with a session.                              ======== */
    /*= If you do not explicitly free all of the memory,                ======== */
    /*= Ivi_Dispose frees it.                                           ======== */
ViStatus  IviDll _VI_FUNC   Ivi_Alloc (ViSession vi, ViInt32 memBlockSize, ViAddr *memBlockPtr);
ViStatus  IviDll _VI_FUNC   Ivi_Free (ViSession vi, ViAddr memBlockPtr);
ViStatus  IviDll _VI_FUNC   Ivi_FreeAll (ViSession vi);

    /*= String Callbacks                                            ======== */
ViStatus  IviDll _VI_FUNC   Ivi_SetValInStringCallback (ViSession vi, ViAttr attributeId, ViConstString value);

    /*= String/Value Tables                                         ======== */
ViStatus  IviDll _VI_FUNC   Ivi_GetStringFromTable(IviStringValueTable table, ViInt32 value, ViString *string);
ViStatus  IviDll _VI_FUNC   Ivi_GetValueFromTable(IviStringValueTable table, ViConstString string, ViInt32 *value);

    /*= Value Manipulation                                         ======== */
ViStatus  IviDll _VI_FUNC   Ivi_CheckNumericRange (ViReal64 value, ViReal64 min, ViReal64 max, ViStatus errorCode);
ViStatus  IviDll _VI_FUNC   Ivi_CheckBooleanRange (ViBoolean value, ViStatus errorCode);
ViStatus  IviDll _VI_FUNC   Ivi_CoerceBoolean (ViBoolean  *value);
ViStatus  IviDll _VI_FUNC   Ivi_CompareWithPrecision (ViInt32 comparePrecision, ViReal64 a, ViReal64 b, ViInt32 *result);
ViStatus  IviDll _VI_FUNC   Ivi_GetViReal64Type (ViReal64 number, ViInt32 *typeOfDouble);
ViReal64* IviDll _VI_FUNC   Ivi_GetPtrToSpecialViReal64Value (ViInt32 typeOfDouble);

/*****************************************************************************/
/*= Functions that do not have a function panel                    ========= */
/*= These are internal, unsafe, functions                          ========= */
/*****************************************************************************/
    /*= Locking                                                     ======== */
ViStatus  IviDll _VI_FUNC   Ivi_LockSession_Class(ViSession vi, ViBoolean *callerHasLock);
ViStatus  IviDll _VI_FUNC   Ivi_UnlockSession_Class(ViSession vi, ViBoolean *callerHasLock);

    /*= Non-typesafe, generic Set/Get Attribute Callback functions ========= */
ViStatus IviDll _VI_FUNC    Ivi_SetAttrCallback (ViSession vi, ViAttr attributeId, IviValueType attrType, IviCallbackType callbackType, ViAddr callback);
ViStatus IviDll _VI_FUNC    Ivi_GetAttrCallback (ViSession vi, ViAttr attributeId, IviValueType attrType, IviCallbackType callbackType, ViAddr *callback);

    /*= Localized error messages                                   ========= */
    /* Constants for languages.                                              */
#define IVI_VAL_LANG_ENGLISH   				1L
#define IVI_VAL_LANG_FRENCH					2L
#define IVI_VAL_LANG_GERMAN					3L
#define IVI_VAL_LANG_JAPANESE				4L
#define IVI_VAL_LANG_KOREAN					5L
#define IVI_VAL_LANG_CHINESE_SIMPLIFIED		6L

ViStatus IviDll _VI_FUNC    Ivi_GetErrorMessageLocalized(ViStatus statusCode, ViUInt32 locale, ViInt32 bufSize, ViChar messageBuf[]);

    /*= NI-Spy support functions                                   ========= */
ViStatus  IviDll _VI_FUNC   Ivi_GetSpyingFromLogicalName (ViConstString logicalName, ViBoolean *isSpying);

    /*= Logging interchange check warnings                         ========= */
ViStatus  IviDll _VI_FUNC   Ivi_LogInterchangeWarning2 (ViSession vi, ViInt32 warningType, ViConstString funcName, ViConstString repCapName, ViAttr attributeId, ViConstString elab);

    /*= Parameter position                                         ========= */
ViStatus IviDll _VI_FUNC    Ivi_ParamPositionError(ViInt32 parameterPosition);  /* returns one of VI_ERROR_PARAMETER1, VI_ERROR_PARAMETER2, ..., VI_ERROR_PARAMETER8, IVI_ERROR_INVALID_PARAMETER */

/*****************************************************************************/
/*= Obsolete Functions and Defintions                              ========= */
/*****************************************************************************/
/* Function pointers */
typedef ViStatus (_VI_FUNC *Ivi_IviInitFuncPtr)     (   ViRsrc resourceName, ViBoolean IDQuery,
                                                        ViBoolean resetDevice,
                                                        ViSession vi);
typedef ViStatus (_VI_FUNC *Ivi_IviCloseFuncPtr)    (   ViSession vi);

/* Deferred I/O Updates */
#define IVI_ATTR_DEFER_UPDATE               /* ViBoolean, hidden */     (IVI_ENGINE_PUBLIC_ATTR_BASE + 51)
#define IVI_ATTR_RETURN_DEFERRED_VALUES     /* ViBoolean, hidden */     (IVI_ENGINE_PUBLIC_ATTR_BASE + 52)   /* if VI_TRUE, then when get an attribute value while a deferred update is pending, return the coerced deferred value */
#define IVI_ATTR_BUFFERED_IO_CALLBACK       /* ViAddr,    hidden */     (IVI_ENGINE_PUBLIC_ATTR_BASE + 601)  /* see Ivi_BufferedIOCallbackPtr typedef */
#define IVI_ATTR_SUPPORTS_WR_BUF_OPER_MODE  /* ViBoolean, hidden */     (IVI_ENGINE_PUBLIC_ATTR_BASE + 704)  /* indicates whether instrument supports VISA buffered writes (VISA's VI_ATTR_WR_BUF_OPER_MODE) */
#define IVI_ATTR_UPDATING_VALUES            /* ViBoolean, hidden */     (IVI_ENGINE_PUBLIC_ATTR_BASE + 708)  /* is VI_TRUE while in Ivi_Update() */

/*****************************************************************************/
/*= Typedefs and contants for the Buffered I/O callback.           ========= */
/*= The Buffered I/O callback is called when the I/O buffer needs  ========= */
/*= to be flushed and before/after processing deferred updates.    ========= */
/*= Different message parameters are passed to the callback to     ========= */
/*= indicate the context in which it was called.                   ========= */
/*= A Default Buffered I/O callback is installed automatically.    ========= */
/*= The default callback assumes VISA buffered I/O.                ========= */
/*= If a specific instrument does not used VISA message-based      ========= */
/*= I/O, use the IVI_ATTR_BUFFERED_IO_CALLBACK attribute to        ========= */
/*= to set the callback function pointer to VI_NULL.               ========= */
/*****************************************************************************/
typedef ViInt32 IviMessage;

typedef ViStatus (_VI_FUNC *Ivi_BufferedIOCallbackPtr)(ViSession vi, IviMessage message);

#define IVI_MSG_START_UPDATE    1  /*  sent by Ivi_Update before processing deferred updates; Ivi_DefaultBufferedIOCallback responds by disabling VISA flush-on-write option; */
                                   /*  note:  if the buffered I/O callback returns an error, the update is aborted */
#define IVI_MSG_END_UPDATE      2  /*  sent by Ivi_Update after processing deferred updates;  Ivi_DefaultBufferedIOCallback responds by restoring the original state of the VISA I/O session */
#define IVI_MSG_SUSPEND         3  /*  sent by Ivi_Update before invoking opc callback, check status callback, and read callbacks */
                                   /*  note:  nested suspend/resume pairs can occur */
#define IVI_MSG_RESUME          4  /*  sent by Ivi_Update after invoking opc callback, check status callback, and read callbacks */
#define IVI_MSG_FLUSH           5  /*  sent by Ivi_Update after invoking the write callback for an attribute that is marked with the IVI_VAL_FLUSH_ON_WRITE flag */


/* These functions are not supported on Linux and MacOSX */
#if !defined (_IVI_linux_) && !defined(_IVI_MacOSX_)

/* prototype for the default buffered I/O callback */
ViStatus  IviDll _VI_FUNC    Ivi_DefaultBufferedIOCallback(ViSession vi, IviMessage message);

ViStatus  IviDll _VI_FUNC   Ivi_AttributeUpdateIsPending(ViSession vi, ViConstString repCapName, ViAttr attributeId, ViBoolean *updatePending);
ViStatus  IviDll _VI_FUNC   Ivi_Update(ViSession vi);

    /*
        Define a buffered write call in IVI that will be used until it is implemented in VISA.
        Driver developers should not call the Ivi_BufWrite function directly and use the
        VISA named function (viBufWrite) instead.
        This function is obsolete and should not be used. Use viBufWrite instead
    */
#if (VI_SPEC_VERSION < 0x00200000L)
#define viBufWrite Ivi_BufWrite
#endif

ViStatus  IviDll _VI_FUNC   Ivi_BufWrite (ViSession vi, ViBuf buf, ViUInt32 count, ViUInt32 *rc);

#endif
/*= Interchangeability Checking                                     ======== */
/*****************************************************************************/
/*  Interchange Check Methods: The class drivers pass the following values   */
/*  to the Ivi_SetInterchangeCheckMethod function to identify the type of the*/
/*  interchange checking that the IVI Engine performs when the class driver  */
/*  calls the Ivi_PerformInterchangeCheck function.                          */
/*****************************************************************************/
#define IVI_VAL_CHECK_IN_USER_SPECIFIED_STATE   1
#define IVI_VAL_CHECK_READ_ONLY_ATTR_NEVER_SET  2
#define IVI_VAL_CHECK_CALL_CLASS_CALLBACK       3
#define IVI_VAL_CHECK_EXEMPT                    4

ViStatus  IviDll _VI_FUNC   Ivi_InterchangeCheckAttribute (ViSession vi, ViConstString repCapName,
                                                           ViAttr attrId, ViInt32 method, ViInt32 funcEnum);
ViStatus  IviDll _VI_FUNC   Ivi_PerformInterchangeCheck (ViSession vi, IviStringValueTable attributes, ViInt32 funcEnum);
ViStatus  IviDll _VI_FUNC   Ivi_SetInterchangeCheckMethod (ViSession vi, ViConstString repCapName, ViAttr attrId, ViInt32 method);

void IviDll _VI_FUNC IviDCPwr_InterchangeCheck (ViSession vi, ViConstString funcName);
void IviDll _VI_FUNC IviDmm_InterchangeCheck (ViSession vi, ViConstString funcName);
void IviDll _VI_FUNC IviFgen_InterchangeCheck (ViSession vi, ViConstString funcName);
void IviDll _VI_FUNC IviScope_InterchangeCheck (ViSession vi, ViConstString funcName);
void IviDll _VI_FUNC IviSwtch_InterchangeCheck (ViSession vi, ViConstString funcName);

void IviDll _VI_FUNC IviDmm_DisableUnusedExtensions (ViSession vi, ViConstString funcName);
void IviDll _VI_FUNC IviFgen_DisableUnusedExtensions (ViSession vi, ViConstString funcName);
void IviDll _VI_FUNC IviScope_DisableUnusedExtensions (ViSession vi, ViConstString funcName);

/*****************************************************************************/
/*= Shortcut macros for class and specific instrument drivers       ======== */
/*****************************************************************************/

#define Ivi_Decimalize(x)         (((x>>8)*100)+(((x >> 4) & 0xF)*10)+(x & 0xF))

#define Ivi_ConvertVISAVer(x)     ((((x>>20)*100)+(((x >> 8) & 0xFFF)*10)+(x & 0xFF))/100.0)

#if defined (_CVI_)
    #define IVI_COMPILER_NAME       "CVI"
    #define IVI_COMPILER_VER_NUM    ((_CVI_)/100.0)
#elif defined(__WATCOMC__)
    #define IVI_COMPILER_NAME       "Watcom"
    #define IVI_COMPILER_VER_NUM    ((__WATCOMC__)/100.0)
#elif defined(_MSC_VER)
    #define IVI_COMPILER_NAME       "MSVC"
    #define IVI_COMPILER_VER_NUM    (14.0)
#elif defined(__BORLANDC__)
    #define IVI_COMPILER_NAME       "Borland"
    #define IVI_COMPILER_VER_NUM    ((Ivi_Decimalize(__BORLANDC__))/100.0)
#elif defined(__SC__)
    #define IVI_COMPILER_NAME       "Symantec"
    #define IVI_COMPILER_VER_NUM    ((Ivi_Decimalize(__SC__))/100.0)
#elif defined(__SUNPRO_C)
    #define IVI_COMPILER_NAME       "Sun C"
    #define IVI_COMPILER_VER_NUM    ((Ivi_Decimalize(__SUNPRO_C))/100.0)
#else
    #define IVI_COMPILER_NAME       "Unknown"
    #define IVI_COMPILER_VER_NUM    1.0
#endif



/*  This section lists all attributes and values that became obsolete. Do not use   */
/*  those attributes and values in your drivers and applications.                   */
/*  IVI_ATTR_CLASS_PREFIX is obsolete. Use IVI_ATTR_CLASS_DRIVER_PREFIX instead     */
#define IVI_ATTR_CLASS_PREFIX           /* ViString, not writable*/     (IVI_ENGINE_PUBLIC_ATTR_BASE + 301)  /* instrument prefix for the class driver;  empty string if not using class driver */
/*  IVI_ATTR_SPECIFIC_PREFIX is obsolete. Use IVI_ATTR_SPECIFIC_DRIVER_PREFIX instead */
#define IVI_ATTR_SPECIFIC_PREFIX        /* ViString, not writable*/     (IVI_ENGINE_PUBLIC_ATTR_BASE + 302)  /* instrument prefix for the specific driver */
/*  IVI_ATTR_MODULE_PATHNAME is obsolete. Use IVI_ATTR_SPECIFIC_DRIVER_LOCATOR instead */
#define IVI_ATTR_MODULE_PATHNAME        /* ViString, not writable*/     (IVI_ENGINE_PUBLIC_ATTR_BASE + 303)  /* the pathnname of the specific driver code module; from the configuration file */
/*  IVI_ATTR_DRIVER_MAJOR_VERSION is obsolete. Use IVI_ATTR_SPECIFIC_DRIVER_MAJOR_VERSION instead */
#define IVI_ATTR_DRIVER_MAJOR_VERSION       /* ViInt32,  not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 503)
/*  IVI_ATTR_DRIVER_MINOR_VERSION is obsolete. Use IVI_ATTR_SPECIFIC_DRIVER_MINOR_VERSION instead */
#define IVI_ATTR_DRIVER_MINOR_VERSION       /* ViInt32,  not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 504)
/*  IVI_ATTR_CLASS_MAJOR_VERSION is obsolete. Use IVI_ATTR_CLASS_DRIVER_MAJOR_VERSION instead */
#define IVI_ATTR_CLASS_MAJOR_VERSION        /* ViInt32,  not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 505)
/*  IVI_ATTR_CLASS_MINOR_VERSION is obsolete. Use IVI_ATTR_CLASS_DRIVER_MINOR_VERSION instead */
#define IVI_ATTR_CLASS_MINOR_VERSION        /* ViInt32,  not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 506)
/*  IVI_ATTR_DRIVER_REVISION is obsolete. Use IVI_ATTR_SPECIFIC_DRIVER_REVISION instead */
#define IVI_ATTR_DRIVER_REVISION            /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 551)
/*  IVI_ATTR_CLASS_REVISION is obsolete. Use IVI_ATTR_CLASS_DRIVER_REVISION instead */
#define IVI_ATTR_CLASS_REVISION             /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 552)
/*  IVI_ATTR_FIRMWARE_REVISION is obsolete. Use IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION instead */
#define IVI_ATTR_FIRMWARE_REVISION          /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 510)
/*  IVI_ATTR_SUPPORTED_CLASSES is obsolete. */
#define IVI_ATTR_SUPPORTED_CLASSES      /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 323)
/*  IVI_ATTR_NUM_CHANNELS is obsolete. Use IVI_ATTR_CHANNEL_COUNT instead */
#define IVI_ATTR_NUM_CHANNELS           /* ViInt32,  not writable*/     (IVI_ENGINE_PUBLIC_ATTR_BASE + 203)   /* set by the specific-driver;  default: 1 */

/*  IVI_ATTR_QUERY_INSTR_STATUS is obsolete. Use IVI_ATTR_QUERY_INSTRUMENT_STATUS instead */
#define IVI_ATTR_QUERY_INSTR_STATUS IVI_ATTR_QUERY_INSTRUMENT_STATUS
/*  IVI_ATTR_RESOURCE_DESCRIPTOR is obsolete. Use IVI_ATTR_IO_RESOURCE_DESCRIPTOR instead */
#define IVI_ATTR_RESOURCE_DESCRIPTOR IVI_ATTR_IO_RESOURCE_DESCRIPTOR
/*  IVI_ATTR_IO_SESSION is obsolete. Use IVI_ATTR_SYSTEM_IO_SESSION instead */
#define IVI_ATTR_IO_SESSION IVI_ATTR_SYSTEM_IO_SESSION
#define IVI_ATTR_ATTRIBUTE_CAPABILITIES /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 403)


#ifdef __cplusplus
    }
#endif

#endif /* IVI_HEADER */

