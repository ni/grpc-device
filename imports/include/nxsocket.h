/*============================================================================*/
/*                 National Instruments / NI-XNET BSD Socket API              */
/*----------------------------------------------------------------------------*/
/*    Copyright (c) National Instruments 2019-2020.  All Rights Reserved.     */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Title:       nxsocket.h                                                    */
/* Purpose:     Include file for NI-XNET BSD Socket API, including TCP/IP     */
/*              stack configuration                                           */
/*                                                                            */
/*============================================================================*/

#ifndef ___nxsocket_h___
#define ___nxsocket_h___

/*--------------------------------------------------------------------------*/
/*  Includes  */
/*--------------------------------------------------------------------------*/
#include <stddef.h>

/*--------------------------------------------------------------------------*/
/* nxsocket_errors.h contains all NI-XNET IP Stack error codes defined as   */
/* preprocessor constants                                                   */
/*--------------------------------------------------------------------------*/
#include "nxsocket_errors.h"

/****************************************************************************/
/*  Base type definitions                                                   */
/****************************************************************************/
#if defined(_MSC_VER)
   #if (_MSC_VER >= 1600)
      #include <stdint.h>
   #elif !defined(_STDINT_H_) && !defined(_STDINT_H) && !defined(_STDINT)
      typedef __int8           int8_t;
      typedef unsigned __int8  uint8_t;
      typedef __int16          int16_t;
      typedef unsigned __int16 uint16_t;
      typedef __int32          int32_t;
      typedef unsigned __int32 uint32_t;
      typedef __int64          int64_t;
      typedef unsigned __int64 uint64_t;
      #ifndef _INTPTR_T_DEFINED
         #if _WIN64
            typedef __int64 intptr_t;
         #else
            typedef __int32 intptr_t;
         #endif
         #define _INTPTR_T_DEFINED
      #endif
   #endif
#elif defined(_CVI_)
   #if (_CVI_ >= 910)
      /* If we're compiling using CVI, just use their C99 types. */
      #include <stdint.h>
   #else
      #error CVI Compiler is too old
   #endif
#elif defined(__GNUC__)
   #include <stdint.h>
#else
   #error Unsupported compiler
#endif

/* Needed for C++ to C (DLL) calls  */
#ifdef __cplusplus
   extern "C" {
#endif

/* Ensure consistent packing */
#pragma pack( push, 8 )

/* Function calling convention */
#if defined(_MSC_VER)
   #ifndef NI_CDECL
      #define NI_CDECL __cdecl
   #endif
#elif defined(__GNUC__)
   #ifndef NI_CDECL
      #define NI_CDECL
   #endif
#elif defined(_CVI_)
   #ifndef NI_CDECL
      #define NI_CDECL __cdecl
   #endif
#else
   #error Unsupported compiler
#endif


/****************************************************************************/
/*  IP Stack API                                                            */
/****************************************************************************/

/*--------------------------------------------------------------------------*/
/*  IP Stack defines                                                        */
/*--------------------------------------------------------------------------*/

/* nxIPSTACK_INFO_ID is passed to the infoID parameter of nxIpStackGetInfo.
* This identifies the struct version to return.
* If/when NI-XNET adds members to a struct, nxIPSTACK_INFO_ID will be
* incremented in this header. The NI-XNET driver will support older values,
* to ensure that applications using structs from a previous version
* work safely.
*/
#define nxIPSTACK_INFO_ID           1

/* For functions that take a millisecond timeout */
#define nxTIMEOUT_INFINITE (-1)

/* Link states */
#define nxOPERATIONAL_STATUS_DOWN           0
#define nxOPERATIONAL_STATUS_UP             1

#define nxINVALID_STACKREF ((nxIpStackRef_t)(0))

/* Format supported by nxIpStackGetAllStacksInfoStr */
#define nxIPSTACK_INFO_STR_FORMAT_JSON       0
#define nxIPSTACK_INFO_STR_FORMAT_TEXT       1

/*--------------------------------------------------------------------------*/
/*  IP Stack types                                                          */
/*--------------------------------------------------------------------------*/
typedef struct nxIpStackRef_t_struct* nxIpStackRef_t;

typedef struct _nxIPAddress_t {
      struct _nxIPAddress_t* nextIPAddress;  /* next address in list */
      uint32_t family;                       /* operational address family (nxAF_INET, nxAF_INET6) */
      char* address;                         /* operational address */
      char* netmask;                         /* operational netmask */
      uint32_t prefixLength;                 /* operational prefix length */
   } nxIPAddress_t;

typedef struct _nxGatewayAddress_t {
      struct _nxGatewayAddress_t* nextGatewayAddress; /* next gateway address in list */
      uint32_t family;                                /* address family (nxAF_INET, nxAF_INET6) */
      char* address;                                  /* gateway address */
   } nxGatewayAddress_t;

typedef struct _nxVirtualInterface_t {
      struct _nxVirtualInterface_t* nextVirtualInterface; /* next virtual interface in list */
      char* xnetInterfaceName;                            /* physical XNET interface used */
      char* vlanName;                                     /* name of the virtual interface */
      char* macAddress;                                   /* operational MAC address */
      uint32_t macMTU;                                    /* maximum size packet allowed */
      uint32_t operationalStatus;                         /* operational state of the link (nxOPERATIONAL_STATUS_UP/nxOPERATIONAL_STATUS_DOWN) */
      uint32_t ifIndex;                                   /* Unique identifier for this virtual interface */
      struct _nxIPAddress_t* firstIPAddress;              /* Linked list of the IP addresses in-use on this interface (or null) */
      struct _nxGatewayAddress_t* firstGatewayAddress;    /* Linked list of the gateway addresses in-use on this interface (or null) */
   } nxVirtualInterface_t;


/*--------------------------------------------------------------------------*/
/*  IP Stack functions  */
/*--------------------------------------------------------------------------*/

int32_t NI_CDECL nxIpStackCreate(const char* stackName, const char* config,
   nxIpStackRef_t* stackRef);
int32_t NI_CDECL nxIpStackOpen(const char* stackName, nxIpStackRef_t* stackRef);
int32_t NI_CDECL nxIpStackClear(nxIpStackRef_t stackRef);
int32_t NI_CDECL nxIpStackGetInfo(nxIpStackRef_t stackRef, uint32_t infoID,
   nxVirtualInterface_t** firstVirtualInterface);
int32_t NI_CDECL nxIpStackFreeInfo(nxVirtualInterface_t* firstVirtualInterface);
int32_t NI_CDECL nxIpStackGetAllStacksInfoStr(uint32_t formatType, char** info);
void NI_CDECL nxIpStackFreeAllStacksInfoStr(char* info);
int32_t NI_CDECL nxIpStackWaitForInterface(nxIpStackRef_t stackRef, const char* localInterface, int32_t timeoutMs);

/****************************************************************************/
/*  BSD-style Socket API                                                    */
/****************************************************************************/

/*--------------------------------------------------------------------------*/
/*  Socket defines                                                          */
/*--------------------------------------------------------------------------*/

#define nxINVALID_SOCKET            ((nxSOCKET)(-1))

/* Address families */
#define nxAF_UNSPEC                 0
#define nxAF_INET                   2
#define nxAF_INET6                  10

/* Protocol families */
#define nxPF_INET                   nxAF_INET
#define nxPF_INET6                  nxAF_INET6
#define nxPF_UNSPEC                 nxAF_UNSPEC

/* IP protocols */
#define nxIPPROTO_IP                0
#define nxIPPROTO_TCP               6
#define nxIPPROTO_UDP               8
#define nxIPPROTO_IPV6              12

/* IP address constants */
#define nxIPADDR_NONE               ((uint32_t)0xffffffffUL) /* 255.255.255.255 */
#define nxIPADDR_LOOPBACK           ((uint32_t)0x7f000001UL) /* 127.0.0.1 */
#define nxIPADDR_ANY                ((uint32_t)0x00000000UL) /* 0.0.0.0 */
#define nxIPADDR_BROADCAST          ((uint32_t)0xffffffffUL) /* 255.255.255.255 */
#define nxINADDR_NONE               nxIPADDR_NONE
#define nxINADDR_LOOPBACK           nxIPADDR_LOOPBACK
#define nxINADDR_ANY                nxIPADDR_ANY
#define nxINADDR_BROADCAST          nxIPADDR_BROADCAST
#define nxIN6ADDR_ANY_INIT          {}
#define nxINET_ADDRSTRLEN           16
#define nxINET6_ADDRSTRLEN          46

/* Socket protocol types (TCP is stream, UDP is dgram) */
#define nxSOCK_STREAM               1
#define nxSOCK_DGRAM                2

/* Level for socket option to apply to socket itself */
#define nxSOL_SOCKET                13     /* options for socket level */

/* Socket options (nxSOL_SOCKET) */
#define nxSO_RXDATA                 0x101  /* num bytes for next receive */
#define nxSO_RCVBUF                 0x102  /* receive buffer size */
#define nxSO_SNDBUF                 0x103  /* send buffer size */
#define nxSO_NONBLOCK               0x104  /* indicates/controls whether socket is non-blocking */
#define nxSO_BINDTODEVICE           0x105  /* binds the socket to a virtual interface by name */
#define nxSO_ERROR                  0x106  /* returns latest error on the socket */
#define nxSO_LINGER                 0x107  /* indicates/controls the linger option of a TCP socket */
#define nxSO_REUSEADDR              0x108  /* indicates/controls the reuse address option of a socket */

/* IPv4 options (nxIPPROTO_IP) */
#define nxIP_ADD_MEMBERSHIP         3
#define nxIP_DROP_MEMBERSHIP        4
#define nxIP_MULTICAST_IF           5
#define nxIP_MULTICAST_TTL          6

/* IPv6 options (nxIPPROTO_IPV6) */
#define nxIPV6_JOIN_GROUP           12
#define nxIPV6_LEAVE_GROUP          13
#define nxIPV6_ADD_MEMBERSHIP       nxIPV6_JOIN_GROUP
#define nxIPV6_DROP_MEMBERSHIP      nxIPV6_LEAVE_GROUP
#define nxIPV6_MULTICAST_IF         14
#define nxIPV6_MULTICAST_HOPS       15
#define nxIPV6_V6ONLY               16


/* TCP options (nxIPPROTO_TCP) */
#define nxTCP_NODELAY               0x01  /* don't delay send to coalesce packets */

/* Receive flags */
#define nxMSG_PEEK                  0x01  /* peek at message without reading */

/* nxshutdown how parameter */
#define nxSHUT_RD                   0
#define nxSHUT_WR                   1
#define nxSHUT_RDWR                 2

/* nxsockaddr_storage: maximum size and alignment, padding */
#define _nxSS_MAXSIZE               128
#define _nxSS_ALIGNSIZE             (sizeof (int64_t))
#define _nxSS_PAD1SIZE              (_nxSS_ALIGNSIZE - sizeof (uint16_t))
#define _nxSS_PAD2SIZE              (_nxSS_MAXSIZE - (sizeof (uint16_t) + \
                                    _nxSS_PAD1SIZE + _nxSS_ALIGNSIZE))

/* nxgetaddrinfo flags */
#define nxAI_PASSIVE       0x0001   /* returned socket address will be used in a bind() call */
#define nxAI_CANONNAME     0x0002   /* return canonical name in first ai_canonname */
#define nxAI_NUMERICHOST   0x0004   /* if specified, given node must be a numeric address */
#define nxAI_NUMERICSERV   0x0008   /* if specified, given service must be a numeric port */
#define nxAI_V4MAPPED      0x0010   /* if no matching ipv6 address is found, return an ipv4 mapped address */
#define nxAI_ALL           0x0020   /* if set with nxAI_V4MAPPED, return all ipv4 and ipv6 addresses */
#define nxAI_ADDRCONFIG    0x0040   /* if set, return ipv4 addresses only if a local ipv4 address is configured, likewise for ipv6 */
#define nxAI_LOCALQUERY    0x0080   /* only perform a local query for the DNS name */
#define nxAI_PREFER_V4     0x0100   /* if this flag is set and the query specifies nxAF_UNSPEC then perform A query first otherwise the resolver does AAAA query first */
#define nxAI_UNICAST_REPLY 0x0200   /* only relevant for mDNS. If this flag is set then the unicast reply bit will be set in questions to request the mDNS server unicasts its response */
#define nxAI_SHARED_RRSET  0x0400   /* only relevant for mDNS. If this flag is set it indicates there may be multiple mDNS responders so the client should attempt to process more than one response */
#define nxAI_BYPASS_CACHE  0x0800   /* causes the ip stack to bypass the cache when doing a name lookup */


/* nxgetnameinfo flags */
#define nxNI_NOFQDN        0x01     /* only return the nodename portion for local hosts */
#define nxNI_NUMERICHOST   0x02     /* return the numeric form of the host's address */
#define nxNI_NAMEREQD      0x04     /* error if the host's name is not in DNS */
#define nxNI_NUMERICSERV   0x08     /* return the numeric form of the service (port #) */
#define nxNI_DGRAM         0x10     /* service is a datagram (UDP) service */

/* fd_set macros
 *
 * Select uses arrays of nxSOCKETs.  These macros manipulate such
 * arrays. nxFD_SETSIZE may be defined by the user before including
 * this file if the default is not sufficient
 */
#ifndef nxFD_SETSIZE
#define nxFD_SETSIZE       64
#endif /* nxFD_SETSIZE */

#define nxFD_SET(fd, set) do { \
   uint32_t __i; \
   for (__i = 0; __i < ((set))->fd_count; __i++) { \
      if (((set))->fd_array[__i] == (fd)) { \
         break; \
      } \
   } \
   if (__i == ((set))->fd_count) { \
      if (((set))->fd_count < nxFD_SETSIZE) { \
         ((set))->fd_array[__i] = (fd); \
         ((set))->fd_count++; \
      } \
   } \
} while(0)

#define nxFD_CLR(fd, set) do { \
   uint32_t __i; \
   for (__i = 0; __i < ((set))->fd_count; __i++) { \
      if (((set))->fd_array[__i] == fd) { \
         while (__i < ((set))->fd_count-1) { \
            ((set))->fd_array[__i] = \
               ((set))->fd_array[__i+1]; \
            __i++; \
         } \
         ((set))->fd_count--; \
         break; \
      } \
   } \
} while(0)

#define nxFD_ZERO(set) (((set))->fd_count=0)

#define nxFD_ISSET(fd, set) nxfd_isset((nxSOCKET)(fd), (set))

/*--------------------------------------------------------------------------*/
/*  Socket types                                                            */
/*--------------------------------------------------------------------------*/
typedef intptr_t nxSOCKET;
typedef int32_t  nxsocklen_t;

/*--------------------------------------------------------------------------*/
/*  Socket structs                                                          */
/*--------------------------------------------------------------------------*/

/* Structure used to store IPv4 addresses (nxAF_INET) */
struct nxin_addr {
   uint32_t addr;
};

/* Structure used to store IPv6 addresses (nxAF_INET6) */
struct nxin6_addr {
   uint8_t  addr[16];                  /* IPv6 address */
};

/* Structure used to specify transport address and port for IPv4 (nxAF_INET) */
struct nxsockaddr_in {
   uint16_t             sin_family;    /* AF_INET                     */
   uint16_t             sin_port;      /* Port number                 */
   struct nxin_addr     sin_addr;      /* IPv4 address                */
   char                 sin_zero[8];   /* Reserved                    */
};

/* Structure used to specify transport address and port for IPv6 (nxAF_INET6) */
struct nxsockaddr_in6 {
   uint16_t             sin6_family;   /* AF_INET6                    */
   uint16_t             sin6_port;     /* Port number                 */
   uint32_t             sin6_flowinfo; /* IPv6 flow information       */
   struct nxin6_addr    sin6_addr;     /* IPv6 address                */
   uint32_t             sin6_scope_id; /* Scope ID                    */
};

/* Generic structure used to specify a transport address for any protocol.
*  NOTE: The sa_data member is not typically accessed directly. Instead,
*        the pointer is cast to/from the actual structure type for the
*        address family specified by sa_family.
*/
struct nxsockaddr {
   uint16_t             sa_family;
   char                 sa_data[16];   /* Opaque, see RFC 3493 */
};

/* Storage of family-independent sockaddr (see RFC 3493) */
struct nxsockaddr_storage {
   uint16_t            ss_family;     /* address family */
   /* Following fields are implementation-specific */
   char                __ss_pad1[_nxSS_PAD1SIZE]; /* 6 byte pad, this is to make implementation-specific pad up to alignment field that follows explicit in the data structure */
   int64_t             __ss_align;                /* field to force desired structure alignment */
   /* storage alignment */
   char                __ss_pad2[_nxSS_PAD2SIZE]; /* Padding to achieve desired size */
};

/* Structure used to add/join an IPv4 multicast group (nxIP_ADD_MEMBERSHIP/nxIP_DROP_MEMBERSHIP) */
struct nxip_mreq {
   struct nxin_addr     imr_multiaddr; /* IPv4 multicast address of group */
   struct nxin_addr     imr_interface; /* local IP address of interface */
};

/* Structure used to add/join an IPv6 multicast group (nxIPV6_JOIN_GROUP/nxIPV6_LEAVE_GROUP) */
struct nxipv6_mreq {
   struct nxin6_addr    ipv6mr_multiaddr; /* IPv6 multicast address */
   int32_t              ipv6mr_interface; /* interface index, or 0 to use first available */
};

/* Specifies a time value (used by nxselect) */
struct nxtimeval {
   int64_t              tv_sec;        /* seconds */
   int32_t              tv_usec;       /* microseconds */
};

/* Specifies a set of sockets (used by nxselect)
*  This structure should not be accessed directly, but rather via the nxFD_XXX macros
*/
struct nxfd_set {
   uint32_t             fd_count;
   nxSOCKET             fd_array[nxFD_SETSIZE];
};

/* Identifies an internet address (used by nxgetaddrinfo) */
struct nxaddrinfo {
   int32_t              ai_flags;      /* Options for nxgetaddrinfo */
   int32_t              ai_family;     /* Address family */
   int32_t              ai_socktype;   /* Socket type */
   int32_t              ai_protocol;   /* Protocol type */
   nxsocklen_t          ai_addrlen;    /* Length of ai_addr in bytes */
   struct nxsockaddr*   ai_addr;       /* The address of the host */
   char*                ai_canonname;  /* The canonical name for the host */
   struct nxaddrinfo*   ai_next;       /* Pointer to the next item in the linked list (or null) */
};

/* Structure used to specify how a TCP socket is closed (used with nxSO_LINGER) */
struct nxlinger {
    int l_onoff;    /* Linger option on or off */
    int l_linger;   /* Linger timeout value in seconds */
};

/*--------------------------------------------------------------------------*/
/*  Socket functions  */
/*--------------------------------------------------------------------------*/

nxSOCKET NI_CDECL nxsocket(nxIpStackRef_t stack_ref, int32_t domain, int32_t type, int32_t protocol);
int32_t NI_CDECL nxclose(nxSOCKET socket);
int32_t NI_CDECL nxbind(nxSOCKET socket, const struct nxsockaddr *name, nxsocklen_t namelen);
nxSOCKET NI_CDECL nxaccept(nxSOCKET socket, struct nxsockaddr *addr, nxsocklen_t *addrlen);
int32_t NI_CDECL nxconnect(nxSOCKET socket, const struct nxsockaddr *name, nxsocklen_t namelen);
int32_t NI_CDECL nxlisten(nxSOCKET socket, int32_t backlog);
int32_t NI_CDECL nxsendto(nxSOCKET socket, const void *dataptr, int32_t size, int32_t flags, const struct nxsockaddr *to, nxsocklen_t tolen);
int32_t NI_CDECL nxsend(nxSOCKET socket, const void *dataptr, int32_t size, int32_t flags);
int32_t NI_CDECL nxrecvfrom(nxSOCKET socket, void *mem, int32_t len, int32_t flags, struct nxsockaddr *from, nxsocklen_t *fromlen);
int32_t NI_CDECL nxrecv(nxSOCKET socket, void *mem, int32_t len, int32_t flags);
int32_t NI_CDECL nxsetsockopt(nxSOCKET socket, int32_t level, int32_t optname, const void *optval, nxsocklen_t optlen);
int32_t NI_CDECL nxgetsockopt(nxSOCKET socket, int32_t level, int32_t optname, void *optval, nxsocklen_t *optlen);
int32_t NI_CDECL nxgetsockname(nxSOCKET socket, struct nxsockaddr *addr, nxsocklen_t *addrlen);
int32_t NI_CDECL nxgetpeername(nxSOCKET socket, struct nxsockaddr *addr, nxsocklen_t *addrlen);
int32_t NI_CDECL nxshutdown(nxSOCKET socket, int32_t how);
int32_t NI_CDECL nxselect(int32_t nfds, struct nxfd_set *readfds, struct nxfd_set *writefds, struct nxfd_set *exceptfds, struct nxtimeval *timeout);
int32_t NI_CDECL nxfd_isset(nxSOCKET socket, struct nxfd_set *set);
int32_t NI_CDECL nxgetlasterrornum(void);
char* NI_CDECL nxgetlasterrorstr(char* buf, size_t buflen);
char* NI_CDECL nxstrerr_r(int errnum, char* buf, size_t buflen);

/*--------------------------------------------------------------------------*/
/*  Inet functions (address conversion)  */
/*--------------------------------------------------------------------------*/
uint32_t NI_CDECL nxinet_addr(nxIpStackRef_t stackRef, const char *cp);
char* NI_CDECL nxinet_ntoa(nxIpStackRef_t stackRef, struct nxin_addr in);
int NI_CDECL nxinet_aton(nxIpStackRef_t stackRef, const char *cp, struct nxin_addr *addr);
const char * NI_CDECL nxinet_ntop(nxIpStackRef_t stackRef, int32_t af, const void *src, char *dst, nxsocklen_t size);
int NI_CDECL nxinet_pton(nxIpStackRef_t stackRef, int32_t af, const char *src, void *dst);

/*--------------------------------------------------------------------------*/
/*  Name/Address Lookup functions                                           */
/*--------------------------------------------------------------------------*/
int32_t NI_CDECL nxgetaddrinfo(nxIpStackRef_t stackRef, const char *node, const char *service,
                               const struct nxaddrinfo *hints, struct nxaddrinfo **res);
void NI_CDECL nxfreeaddrinfo(struct nxaddrinfo *res);
int32_t NI_CDECL nxgetnameinfo(nxIpStackRef_t stackRef, const struct nxsockaddr *addr, nxsocklen_t addrlen,
                               char *host, nxsocklen_t hostlen,
                               char *serv, nxsocklen_t servlen, int32_t flags);

/* Restore packing */
#pragma pack( pop )

#ifdef __cplusplus
}
#endif

#endif
