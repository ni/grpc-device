/*---------------------------------------------------------------------------*/
/* National Instruments NI-VISA Software                                     */
/* Do not modify the contents of this file.                                  */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/* Title   : NIVISASV.H                                                      */
/* Date    : 08-19-99                                                        */
/* Purpose : Include file for the VISA Passport Services Library             */
/*                                                                           */
/*---------------------------------------------------------------------------*/

#if !defined(_VISA_SERVICE_H_)
#define _VISA_SERVICE_H_

#include <nibuild/platform.h>

#if defined(__cplusplus) || defined(__cplusplus__)
   extern "C" {
#endif

/*- VISA Types and Definitions ----------------------------------------------*/

#if (defined(_WIN64) || defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)) && !defined(_NI_mswin16_)
#if !defined(_WINDOWS_)
#include <windows.h>
#endif
#if !defined(USE_DYNAMIC_LIBRARY_LOAD)
#define USE_DYNAMIC_LIBRARY_LOAD VI_TRUE
typedef HINSTANCE VISA_DLL_HANDLE;
#if defined(NIVISA_SERVICE_BACKWARD_COMPATIBILITY)
typedef HINSTANCE DLL_HANDLE;
#endif
#endif
#if !defined(USE_PROCESS_ID_INFO)
#define USE_PROCESS_ID_INFO VI_TRUE
typedef DWORD VISA_PROCESS_ID;
typedef DWORD VISA_THREAD_ID;
#if defined(NIVISA_SERVICE_BACKWARD_COMPATIBILITY)
typedef DWORD PROCESS_ID;
#endif
#endif
/* Win32/64 - must specify byte alignment for the structures defined below */
#if defined(_WIN64)
#pragma pack(push,8)
#else
#pragma pack(push,4)
#endif
/* Also want to turn off warning 4054, often seen when using visaRegisterOper */
#pragma warning(disable:4054)
#endif

/* Just define these macros so the attributes are always available. */
/* This is valid even on platforms that don't support these buses   */
/* natively.  For example, users can use the remote client there.   */
#if !defined(NIVISA_PXI)
#define NIVISA_PXI
#endif
#if !defined(NIVISA_USB)
#define NIVISA_USB
#endif

#if !defined(_VISA_LIBRARY_IMPL_H_)
#if defined(__VISA_HEADER__)
#error You must include NiVisaSv.h before including visa.h
#endif
/* The following lines allow ViObject and ViSession to be pointers */
/* in the implementation.  The order of these lines is important!  */
typedef struct implViSessionPublic *ViPSessionTbl, **ViPPSessionTbl;
typedef struct implViEventPublic   *ViPEventInfo,  **ViPPEventInfo;
#if !defined(__VISATYPE_HEADER__)
#include "visatype.h"
#endif
#if !defined(_VISA_ENV_IS_64_BIT)
#define ViObject           ViPSessionTbl
#define ViPObject          ViPPSessionTbl
#define ViSession          ViPSessionTbl
#define ViPSession         ViPPSessionTbl
#endif
#include "visa.h"
#endif

/* Used for I/O sessions */
struct implViSessionPublic
{
   ViAddr                  lolaStatus;       /* MUST be first in all structures for future binary compatibility */
   ViUInt16                reserved1;
   ViUInt16                reserved2;
   ViAddr                  ioSpecificData;   /* used by libraries to point to own data */
   ViAddr                  reserved3;
   ViAddr                  reserved4;
   ViUInt16                intfType;
   ViUInt16                intfNum;
};

/* Used for raising events to VISA */
struct implViEventPublic
{
   ViAddr                  reserved0;        /* MUST be first in all structures for future binary compatibility */
   ViUInt16                reserved1;
   ViUInt16                reserved2;
   ViAddr                  ioSpecificData;   /* used by libraries to point to own data */
   ViUInt16                reserved3;
   ViUInt16                reserved4;
   ViEventType             eventType;
   ViUInt32                contextU32;
   ViInt32                 contextI32;
   ViJobId                 contextJob;
   ViStatus                contextStat;
};

#ifndef _VI_MUTEX_DEFINED
typedef ViAddr             ViMutex;
typedef ViMutex _VI_PTR    ViPMutex;
#define _VI_MUTEX_DEFINED
#endif

#ifndef _VI_FUNCTBL_DEFINED
typedef ViAddr             ViFuncTbl;
typedef ViFuncTbl _VI_PTR  ViPFuncTbl;
#define _VI_FUNCTBL_DEFINED
#endif

/* Enumerations used for callback from visaMatchAttrExpr */
#define VI_ATTR_TYPE_I08   (1)
#define VI_ATTR_TYPE_U08   (2)
#define VI_ATTR_TYPE_I16   (3)
#define VI_ATTR_TYPE_U16   (4)
#define VI_ATTR_TYPE_I32   (5)
#define VI_ATTR_TYPE_U32   (6)
#define VI_ATTR_TYPE_I64   (7)
#define VI_ATTR_TYPE_U64   (8)
#define VI_ATTR_TYPE_R32   (9)
#define VI_ATTR_TYPE_R64   (10)
#define VI_ATTR_TYPE_STR   (11)

typedef ViStatus (_VI_FUNCH _VI_PTR ViSessEnumHndlr)
   (ViSession vi, ViAddr userHandle);
typedef ViStatus (_VI_FUNCH _VI_PTR ViMatchAttrInfoHndlr)
   (ViSession ioSesn, ViConstString attrName, ViPBoolean pIsGlobal,
    ViPUInt16 pAttrType, ViPAttr pAttrNum, ViAddr userHandle);

#if (defined(_WIN64) || defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)) && !defined(_NI_mswin16_)
/* Win32/64 - must specify byte alignment for the structures defined above */
#pragma pack(pop)
#endif

/*- Exported VISA Services --------------------------------------------------*/

/* Platform-independent version of ANSI memory-management functions. */
/* All memory you allocate with the following services you must explicitly free. */
ViAddr   _VI_FUNC visaCalloc           (ViBusSize num_elems, ViBusSize elem_size);
ViAddr   _VI_FUNC visaRealloc          (ViAddr addr, ViBusSize new_size);
void     _VI_FUNC visaFree             (ViAddr addr);

/* Simplified T/F string compares with case-insensitive algorithm. */
ViBoolean _VI_FUNC visaStricmp         (ViConstString str1, ViConstString str2);
ViBoolean _VI_FUNC visaStrnicmp        (ViConstString str1, ViConstString str2, ViInt32 count);

/* Get installation directory, such as C:\VXIpnp\WinNT or /opt/vxipnp/hpux. */
ViStatus _VI_FUNC visaFrameworkPath    (ViChar path[]);
ViStatus _VI_FUNC visaConfigIniPath    (ViChar path[]);
ViStatus _VI_FUNC visaResourceIdPath   (ViChar path[]);

/* Request a named block of global/shared (inter-process) memory. */
/* This shared memory will be automatically deallocated when VISA unloads. */
ViStatus _VI_FUNC visaAllocShared      (ViConstString regionName, ViInt32 regionSize, ViPAddr ptr, ViPBoolean bFirst);

/* Request a named semaphore for local (per-process) or global/shared (inter-process) communication. */
/* This semaphore will be automatically deallocated when VISA unloads. */
ViStatus _VI_FUNC visaSemAlloc         (ViConstString mutexName, ViBoolean isGlobal, ViBoolean canNest, ViPMutex mutexHdl);
ViStatus _VI_FUNC visaSemAcquire       (ViMutex mutexHdl, ViUInt32 TimeOut, ViPBoolean pHaveMutex);
ViStatus _VI_FUNC visaSemRelease       (ViMutex mutexHdl, ViPBoolean pHaveMutex);
/* You can optionally manually close a semaphore.  This works for local semaphores only. */
ViStatus _VI_FUNC visaSemFree          (ViMutex mutexHdl);

/* Register library's function table(s) and associated functions. */
/* The specver is needed to guarantee cross-version compatibility. */
ViStatus _VI_FUNC visaRegisterTable    (ViConstString tableName, ViVersion specver, ViBusAddress reserved, ViPFuncTbl pvtbl);
ViStatus _VI_FUNC visaRegisterOper     (ViFuncTbl vtbl, ViConstString operName, ViAddr operAddr);

/* From viOpen, specify the registered function table to use for a given session. */
/* Also specify resource-specific information (such as a bus-specific device address) for locking. */
ViStatus _VI_FUNC visaSetSessionInfo   (ViSession vi, ViFuncTbl vtbl, ViAddr reserved, ViUInt32 rsrcLockInfo1, ViUInt32 rsrcLockInfo2);

/* Services for use by viFindRsrc to verify a match and return it to VISA. */
/* Use the vtbl in visaRsrcFound if you want to add attributes to a ViFindList. */
void     _VI_FUNC visaSetFindInfo      (ViSession rmSesn, ViConstString szInfo);
ViStatus _VI_FUNC visaMatchRsrcExpr    (ViSession rmSesn, ViConstString exprString, ViConstRsrc rsrcString, ViPBoolean bNeedMatchAttr);
ViStatus _VI_FUNC visaMatchAttrExpr    (ViSession rmSesn, ViConstString exprString, ViConstRsrc rsrcString, ViMatchAttrInfoHndlr attrMatchFunc, ViAddr userHandle);
ViStatus _VI_FUNC visaRsrcFound        (ViFindList fl, ViConstRsrc rsrc, ViFuncTbl vtbl);
ViBoolean _VI_FUNC visaIsRsrcExprRemote(ViConstString rsrcOrExpr, ViChar szMachinePortion[], ViConstString *pszRsrcOrExprPortion);

/* Low-level VISA event services for supporting all event types. */
/* Use the vtbl if you want to add attributes to a ViEvent. */
ViStatus _VI_FUNC visaSupportEvents    (ViSession vi, ViUInt16 numEvents, ViEventType const arrEvents[], ViFuncTbl vtbl);
ViStatus _VI_FUNC visaGetEventMech     (ViSession vi, ViEventType etype, ViPUInt16 mech);
ViStatus _VI_FUNC visaGetEventHandlers (ViSession vi, ViEventType etype, ViUInt16 maxHndlrs, ViPUInt16 numHndlrs, ViHndlr arrHndlrs[], ViAddr arrData[]);
ViStatus _VI_FUNC visaCreateEvent      (ViSession vi, ViEventType eventType, ViPPEventInfo eventQueue, ViPPEventInfo eventCallback);
ViStatus _VI_FUNC visaRaiseEvent       (ViSession vi, ViPEventInfo pEventQueue, ViPEventInfo pEventCallback);

/* Low-level VISA lock services for manipulating sessions. */
ViStatus _VI_FUNC visaEnterLockOper    (ViSession vi, ViPBoolean pbNeedUnlock);
void     _VI_FUNC visaExitLockOper     (ViSession vi, ViBoolean  bNeedUnlock);

/* Enumerate all sessions for this process.  Return VI_SUCCESS to continue. */
/* Pass a specific vtbl if you want to see only sessions using it, or VI_NULL otherwise. */
ViStatus _VI_FUNC visaEnumSessions     (ViSessEnumHndlr enumFunc, ViFuncTbl vtbl, ViAddr userHandle);

/* Time services (in msec) to give up processor time and retrieve the time since system startup. */
void     _VI_FUNC visaSleep            (ViUInt32 TimeMsec);
ViUInt32 _VI_FUNC visaGetTickCount     (void);

/* Fake async I/O Routines in cases where a Passport wants to selectively implement async calls. */
ViStatus _VI_FUNC visaReadAsyncFake    (ViSession vi, ViPBuf buf, ViUInt32 cnt, ViPJobId jobId);
ViStatus _VI_FUNC visaWriteAsyncFake   (ViSession vi, ViConstBuf buf,  ViUInt32 cnt, ViPJobId jobId);
ViStatus _VI_FUNC visaMoveAsyncFake    (ViSession vi, ViUInt16 srcSpace, ViBusAddress srcOffset, ViUInt16 srcWidth, ViUInt16 dstSpace, ViBusAddress dstOffset, ViUInt16 dstWidth, ViBusSize srcLength, ViPJobId jobId);
ViStatus _VI_FUNC visaMoveAsyncExFake  (ViSession vi, ViUInt16 srcSpace, ViBusAddress64 srcOffset, ViUInt16 srcWidth, ViUInt16 dstSpace, ViBusAddress64 dstOffset, ViUInt16 dstWidth, ViBusSize srcLength, ViPJobId jobId);

/* Standard INI file services for reading configuration entries. */
void     _VI_FUNC visaRefreshIniFiles  (void);
void     _VI_FUNC visaGetIniShort      (ViConstString ini_file, ViConstString section, ViConstString key, ViUInt16 defval,      ViPUInt16 dest);
void     _VI_FUNC visaGetIniLong       (ViConstString ini_file, ViConstString section, ViConstString key, ViUInt32 defval,      ViPUInt32 dest);

/* Enhanced INI services for reading keys of the form Entry1, Entry2... */
void     _VI_FUNC visaGetIniIndexShort (ViConstString ini_file, ViConstString section, ViConstString key, ViUInt16 index, ViUInt16 defval,      ViPUInt16 dest);
void     _VI_FUNC visaGetIniIndexLong  (ViConstString ini_file, ViConstString section, ViConstString key, ViUInt16 index, ViUInt32 defval,      ViPUInt32 dest);

/* Deprecated configuration reading functions. Use the secure version below */
#if kNICompilerMSVC
   #define NIVISA_DEPRECATED(func) __declspec(deprecated) func
#elif kNICompilerApple || kNICompilerGNU || kNICompilerWindRiver
   #define NIVISA_DEPRECATED(func) func __attribute__((deprecated))
#else
   #define NIVISA_DEPRECATED(func) func
#endif
NIVISA_DEPRECATED(void _VI_FUNC visaGetIniString(ViConstString ini_file, ViConstString section, ViConstString key, ViConstString defval, ViChar dest[]));
NIVISA_DEPRECATED(void _VI_FUNC visaGetIniIndexString(ViConstString ini_file, ViConstString section, ViConstString key, ViUInt16 index, ViConstString defval, ViChar dest[]));

/* Declare secure versions of string ini functions. */
void _VI_FUNC visaGetIniStringIntoBuffer(ViConstString ini_file, ViConstString section, ViConstString key, ViConstString defval, ViChar dest[], int destSize);
void _VI_FUNC visaGetIniIndexStringIntoBuffer(ViConstString ini_file, ViConstString section, ViConstString key, ViUInt16 index, ViConstString defval, ViChar dest[], int destSize);

#if defined(_VI_INT64_UINT64_DEFINED)
ViStatus _VI_FUNC visaGetIniTimestamp  (ViConstString ini_file, ViUInt64 *pTimestamp);
#endif

#if defined(USE_DYNAMIC_LIBRARY_LOAD) && (USE_DYNAMIC_LIBRARY_LOAD)
/* Access external libraries such as a DLL or shared object.  */
/* Define VISA_DLL_HANDLE first, such as HINSTANCE on WinNT or shl_t on HPUX. */
ViStatus _VI_FUNC visaLibLoad          (ViConstString libName, VISA_DLL_HANDLE *pLib);
ViStatus _VI_FUNC visaLibSymbol        (VISA_DLL_HANDLE lib, ViConstString funcName, ViPAddr pFunc);
ViStatus _VI_FUNC visaLibFree          (VISA_DLL_HANDLE lib);

/* Call this function when the OS notifies your I/O library during unloading. */
/* The lib value can be VI_NULL if the OS does not pass it (such as Solaris). */
void     _VI_FUNC visaLibIsUnloading   (VISA_DLL_HANDLE lib);
#endif

#if defined(USE_PROCESS_ID_INFO) && (USE_PROCESS_ID_INFO)
/* Get the current process ID in the system and compare it with others. */
/* Define VISA_PROCESS_ID first, such as DWORD on WinNT or int on HPUX. */
VISA_PROCESS_ID _VI_FUNC visaProcGetID (void);
VISA_THREAD_ID _VI_FUNC visaThreadGetID(void);
ViBoolean  _VI_FUNC visaProcIsSame     (VISA_PROCESS_ID pid1, VISA_PROCESS_ID pid2);
ViStatus  _VI_FUNC visaProcIsAlive     (VISA_PROCESS_ID pid, ViPBoolean pbAlive);
#endif

#if defined(_VISA_ENV_IS_64_BIT)
ViPSessionTbl _VI_FUNC visaGetSesnImpl (ViSession vi);
ViPEventInfo  _VI_FUNC visaGetEventImpl(ViEvent evt);
#else
#define visaGetSesnImpl(vi)            ((ViPSessionTbl)(vi))
#define visaGetEventImpl(evt)          ((ViPEventInfo)(evt))
#endif

#if defined(__cplusplus) || defined(__cplusplus__)
   }
#endif

#endif
