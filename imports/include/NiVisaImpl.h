#if !defined(_NI_VISA_IMPLEMENTATION_H_)
#define _NI_VISA_IMPLEMENTATION_H_

#include <nibuild/platform.h>

/* Allows access to 64-bit return count on all platforms */
#define NI_ATTR_RET_COUNT_64           (0x3FFF4028UL) /* ViUInt64  */
#if defined(VI_ATTR_RET_COUNT_64)
#if (VI_ATTR_RET_COUNT_64 != NI_ATTR_RET_COUNT_64)
#error VI_ATTR_RET_COUNT_64 does not match NI_ATTR_RET_COUNT_64!
#endif
#else
#define VI_ATTR_RET_COUNT_64 NI_ATTR_RET_COUNT_64
#endif

/* Allows access to the attribute ID on 32-bit platforms */
/* THIS FEATURE IS NOT IMPLEMENTED FOR 32-BIT PLATFORMS  */
#define NI_ATTR_USER_DATA_64          (0x3FFF000AUL)  /* ViUInt64  */
#if defined(VI_ATTR_USER_DATA_64)
#if (VI_ATTR_USER_DATA_64 != NI_ATTR_USER_DATA_64)
#error VI_ATTR_USER_DATA_64 does not match NI_ATTR_USER_DATA_64!
#endif
#else
#define VI_ATTR_USER_DATA_64 NI_ATTR_USER_DATA_64
#endif

/* NI-VXI emulation layer uses the next 13 attributes */
#define VI_ATTR_SIGP_IS_SIGNAL         (0x3FFF409CUL) /* ViBoolean */
#define VI_ATTR_MXI_BLOCK_ALLOW_EN     (0x3FFF0160UL) /* ViBoolean */
#define VI_ATTR_WIN_NUM                (0x3FFF019EUL) /* ViUInt32  */
#define VI_ATTR_VXI_DEV_STATUS_STATE   (0x3FFF007BUL) /* ViInt16   */
#define VI_ATTR_VXI_TRIG_CNTR_SOURCE   (0x3FFF01C0UL) /* ViInt16   */
#define VI_ATTR_VXI_TRIG_CNTR_COUNT    (0x3FFF01C1UL) /* ViUInt16  */
#define VI_ATTR_VXI_TRIG_TICK_SOURCE   (0x3FFF01C2UL) /* ViInt16   */
#define VI_ATTR_VXI_TRIG_TICK_COUNT1   (0x3FFF01C3UL) /* ViUInt16  */
#define VI_ATTR_VXI_TRIG_TICK_COUNT2   (0x3FFF01C4UL) /* ViUInt16  */
#define VI_ATTR_VXI_TRIG_TICK_NOROLL   (0x3FFF01C5UL) /* ViUInt16  */
#define VI_ATTR_VXI_TRIG_ASSERT_MODE   (0x3FFF01C6UL) /* ViUInt32  */
#define VI_ATTR_VXI_TRIG_EXT_CONFIG    (0x3FFF01C7UL) /* ViUInt32  */
#define VI_ATTR_LAST_MOVE_MODE         (0x3FFF01C8UL) /* ViUInt16  */
#define VI_ATTR_SRC_UPPER_OFFSET_A64   (0x3FFF01C9UL) /* ViUInt32  */
#define VI_ATTR_DEST_UPPER_OFFSET_A64  (0x3FFF01CAUL) /* ViUInt32  */
#define VI_ATTR_WIN_UPPER_OFFSET_A64   (0x3FFF01CBUL) /* ViUInt32  */
#define VI_ATTR_2ESST_RATE             (0x3FFF01CCUL) /* ViUInt32  */
#define VI_ATTR_MAP_SIZE_IS_HINT       (0x3FFF01CDUL) /* ViBoolean */

/* NI-VXI emulation layer uses the next 1 event */
#define VI_EVENT_BERR                  (0x3FFF2007UL)

/* NI-DAQ uses the next 8 attributes */
#define VI_ATTR_UNSAFE_CALLBACK_EN     (0x3FFF0008UL) /* ViBoolean */
#define VI_ATTR_UNSAFE_QUEUE_EN        (0x3FFF0009UL) /* ViBoolean */
#define VI_ATTR_KRNL_VIIN8_ADDR        (0x3FFF810AUL) /* ViAddr    */
#define VI_ATTR_KRNL_VIIN16_ADDR       (0x3FFF810BUL) /* ViAddr    */
#define VI_ATTR_KRNL_VIIN32_ADDR       (0x3FFF810CUL) /* ViAddr    */
#define VI_ATTR_KRNL_VIOUT8_ADDR       (0x3FFF810DUL) /* ViAddr    */
#define VI_ATTR_KRNL_VIOUT16_ADDR      (0x3FFF810EUL) /* ViAddr    */
#define VI_ATTR_KRNL_VIOUT32_ADDR      (0x3FFF810FUL) /* ViAddr    */
#define VI_ATTR_RESMAN_STATUS          (0x3FFF8110UL) /* ViUInt32  */

/* MAX and NI-VXI use the next 4 attributes */
#define VI_ATTR_INTR_LEVELS            (0x3FFF81A0UL) /* ViInt16   */
#define VI_ATTR_EXTENDER_INFO          (0x3FFF81A1UL) /* ViInt16   */
#define VI_ATTR_RORA_LEVELS            (0x3FFF81A2UL) /* ViUInt16  */
#define VI_ATTR_RORA_REENABLE          (0x3FFF81A3UL) /* ViUInt16  */

/* VISA and IVI internals use the next 7 attributes */
#define VI_ATTR_PEEKPOKE_MACROS_AT_0   (0x3FFF8ABCUL) /* ViBoolean */
#define VI_ATTR_IO_INTR_SIGNAL_NUM     (0x3FFF8ABDUL) /* ViUInt32  */
#define VI_ATTR_SPY_GET_USER_DATA      (0x3FFF8ACEUL) /* ViBoolean */
#define VI_ATTR_FREE_PASSPORTS_IF_LAST (0x3FFF018CUL) /* ViBoolean */
#define VI_ATTR_FRAMEWORK_PATH         (0x3FFF018DUL) /* ViString  */
#define VI_ATTR_RSRC_USER_ALIAS        (0x3FFF018EUL) /* ViString  */
#define VI_ATTR_LOADED_ALL_PASSPORTS   (0x3FFF0191UL) /* ViBoolean */
#define VI_ATTR_NUM_SUP_EVENTS         (0x3FFF019CUL) /* ViUInt16  */
#define VI_ATTR_SUP_EVENTS             (0x3FFF019DUL) /* ViAEventType */

/* NI-VXI 2.x (legacy) and 3.x (VVGL) Passports use the next 18 trigger IDs */
#define VI_TRIG_ECL2                   (10)
#define VI_TRIG_ECL3                   (11)
#define VI_TRIG_ECL4                   (12)
#define VI_TRIG_ECL5                   (13)
#define VI_TRIG_VXI_GPIO0              (40) /* aka Front Panel In   */
#define VI_TRIG_VXI_GPIO1              (41) /* aka Front Panel Out  */
#define VI_TRIG_VXI_GPIO2              (42) /* aka ECL FP Bypass    */
#define VI_TRIG_VXI_GPIO3              (43) /* aka EXTCLK Connect   */
#define VI_TRIG_VXI_GPIO4              (44) /* first truly GP       */
#define VI_TRIG_VXI_GPIO5              (45)
#define VI_TRIG_VXI_GPIO6              (46)
#define VI_TRIG_VXI_GPIO7              (47)
#define VI_TRIG_VXI_GPIO8              (48)
#define VI_TRIG_VXI_GPIO9              (49) /* last truly GP        */
#define VI_TRIG_TIC_TCNTR              (50) /* counter pulse output */
#define VI_TRIG_TIC_GCNTR              (51) /* counter finished     */
#define VI_TRIG_TIC_TICK1              (60) /* TICK1 timer output   */
#define VI_TRIG_TIC_TICK2              (61) /* TICK2 timer output   */

/* NI-VXI 3.x (VVGL) Passport uses the next few definitions for VXI 3.0 spec support */
#define VI_XAM_2EVME                   (8)  /* 2e extended address modifiers */
#define VI_XAM_2ESST                   (9)  /* 2e extended address modifiers */
#define VI_XAM_2ESST_BROADCAST         (10) /* 2e extended address modifiers */
#define VI_2ESST_RATE_SST160           (0x0 << 29)
#define VI_2ESST_RATE_SST267           (0x1 << 29)
#define VI_2ESST_RATE_SST320           (0x2 << 29)

/* PXI and 1394 Passports use the next 1 attribute */
/* Note that the old name for this was VI_ATTR_PXI_DEV_IS_REGISTERED */
#define VI_ATTR_DEV_IS_REGISTERED      (0x3FFF0200UL) /* ViBoolean */

/* PXI Passport uses the next 1 attribute */
#define VI_ATTR_PXI_EMERGENCY_INTR_DISARM (0x3FFF820FUL) /* ViBoolean */

/* PXI passport uses the next 2 constants as possible return values from VI_ATTR_PXI_STAR_TRIG_LINE */
#define VI_PXI_STAR_TRIG_LINE_UNKNOWN  (-1)
#define VI_PXI_STAR_TRIG_CONTROLLER    (1413)  /* arbitrarily large number chosen */

/* PXI passport uses the next 1 constant as possible return values from VI_ATTR_PXI_SLOT_LBUS_LEFT and VI_ATTR_PXI_SLOT_LBUS_RIGHT */
#define VI_PXI_LBUS_SCXI               (2000)  /* "SCXI" */

/* PXI Passport uses the next 1 address space */
#define VI_PXI_IO_SPACE                (8)   /* absolute address, inp and outp */

/* USB Passport uses this attribute for a unique ID per USB device */
#define VI_ATTR_USB_LOCATION_ID        (0x3FFF01B1UL)

/* NI-VXI 2.x (legacy) and 3.x (VVGL) Passports use the next 4 address spaces  */
#define VI_PCI_ABSOLUTE_SPACE          (0x0A) /* absolute address, such as 1394 */
#define VI_BOARD_REG_SPACE             (0x0B) /* board address relative to MITE */
#define VI_LOCAL_LA_SPACE              (0x0C) /* space for VXIinLR and VXIoutLR */
#define VI_VXI_VME_INTR_ACK_SPACE      (0x0D) /* manually acknowledge interrupt */
#define VI_FX2_DIRECT_SPACE            (0x50) /* decimal 80, FX2 pass-through   */
#define VI_FX2_INDIRECT_SPACE          (0x52) /* decimal 82, FX2 pass-through   */
#define VI_FX2_EXTERNAL_SPACE          (0x54) /* decimal 84, FX2 pass-through   */
#define VI_FX2_CODE_SPACE              (0x56) /* decimal 86, FX2 pass-through   */
#define VI_BOARD_REG_SPACE_NOCACHE     (0xBB) /* since BOARD_REG_SPACE is 0xB   */

/* LabVIEW uses the next 2 attributes */
#define VI_ATTR_FIND_NEEDS_REFRESH     (0x3FFF018FUL) /* ViBoolean, read-only */
#define VI_ATTR_FIND_RSRC_MODE         (0x3FFF0190UL) /* ViUInt16, read-write */

/* The following are bit field definitions for the behavior of viFindRsrc */
#define VI_FIND_SEARCH_NORMAL          (0x0000) /* default spec behavior          */
#define VI_FIND_NOSEARCH_CFG_ONLY      (0x0001) /* INI file only, no bus activity */
#define VI_FIND_ALIAS_IF_EXISTS        (0x0002) /* else return canonical names    */
#define VI_FIND_INCLUDE_ALL_ALIASES    (0x0004) /* even those not matching expr   */
/* The following bits are new to NI-VISA 3.0 and higher */
#define VI_FIND_ADVANCED_RSRCS         (0x0008) /* include non-typical resources  */
#define VI_FIND_NON_INTRUSIVE_SEARCH   (0x0010) /* try to avoid destructive find  */
#define VI_FIND_RESERVED_BITS          (0x7FE0) /* not defined, so do not use     */
#define VI_FIND_USES_BITFIELD_FLAGS    (0x8000) /* else ignore bits 0x7FF8        */

/* The following are combinations of the above fields for backward compatibility */
#define VI_FIND_SEARCH_NOALIAS         (VI_FIND_SEARCH_NORMAL)
#define VI_FIND_SEARCH_MATCHALIASES    (VI_FIND_SEARCH_NORMAL|VI_FIND_ALIAS_IF_EXISTS)
#define VI_FIND_NOSEARCH_ALLALIASES    (VI_FIND_NOSEARCH_CFG_ONLY|VI_FIND_ALIAS_IF_EXISTS)
#define VI_FIND_SEARCH_ALLALIASES      (VI_FIND_SEARCH_NORMAL|VI_FIND_ALIAS_IF_EXISTS|VI_FIND_INCLUDE_ALL_ALIASES)

/* Use the LEN_ macros to avoid calling strlen on a string constant */
/* WARNING TO DEVELOPERS:  MAKE SURE THESE CONSTANTS ARE CORRECT!!! */
#define RSRC_PREFIX_LOCAL              "visa:/"
#define LEN_PREFIX_LOCAL               6
#define RSRC_PREFIX_LOCAL_SHORT        "/"
#define LEN_PREFIX_LOCAL_SHORT         1
#define RSRC_PREFIX_REMOTE             "visa://"
#define LEN_PREFIX_REMOTE              7
#define RSRC_PREFIX_REMOTE_SHORT       "//"
#define LEN_PREFIX_REMOTE_SHORT        2

/* RIO Passport uses the next 2 attributes and 5 events */
#define  VI_ATTR_RIO_SERIAL_NUM     (0x3FFF0F02UL)
#define  VI_ATTR_RIO_DEVICE_TYPE    (0x3FFF0F03UL)

#define VI_EVENT_RIO_FPGA           (0x3FFF2F00UL)
#define VI_EVENT_RIO_DMA1           (0x3FFF2F11UL)
#define VI_EVENT_RIO_DMA2           (0x3FFF2F12UL)
#define VI_EVENT_RIO_DMA3           (0x3FFF2F13UL)
#define VI_EVENT_RIO_DMA4           (0x3FFF2F14UL)

#if defined(_VISA_ENV_IS_64_BIT) // 64-bit

#if (kNIOSLinux || kNIOSMacOSX)
#include <inttypes.h>
#define PRIVi32Mod
#define PRIViBusSzFmtu PRIu64
#define PRIViBusSzFmtX PRIX64
#else
#define PRIVi32Mod    "l"
#define PRIViBusSzFmtu "llu"
#define PRIViBusSzFmtX "llX"
#endif

#else // 32-bit

#define PRIVi32Mod    "l"
#define PRIViBusSzFmtu "lu"
#define PRIViBusSzFmtX "lX"
#endif

#endif
