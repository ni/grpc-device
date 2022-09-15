/*!
   \file
   \brief Status C definition and helper functions.
*/
/*
   Copyright (c) 2012-2012 National Instruments Corporation.
   All rights reserved.
*/

#ifndef NIERR_NIERR_STATUS_H_
#define NIERR_NIERR_STATUS_H_

#include <stdint.h>

extern "C" {
#define kNICCall

#if kNICompilerMSVC
   #define  kNIInlineC     __inline       /*!< Defined to specify that
                                          the following C function should be inlined. */
   #define  kNIForceInline __forceinline  /*!< Defined to force inline. */
#else
   #define  kNIInlineC     static inline
   #define  kNIForceInline __attribute__((always_inline))
#endif

struct nierr_Status;

/*! This function type is responsible to allocate/free json buffer and put the
 * buffer size into the capacity field for a given nierr_Status.
 * \return true if successful, else false. If size is 0, success is guaranteed.
 * \param[in] s status
 * \param[in] size if size>0, then it indicates minimum size to allocate. It may allocate more than size.
 *       If size is 0, then json buffer will be freed and capacity set to 0
 * \post if size is not 0, json field will be fully initialized jsonz buffer.
 * \post if size is 0, json field will be freed, and capacity reset to 0
 * \post if failed, nothing will be changed
 */
typedef bool (kNICCall nierr_ReallocJson)(struct nierr_Status * s, uint32_t size);

/*! nierr_Status structure for C code that can be used for status chaining
 * across DLL boundary.
 * For coding implementation, please use nierr::Status instead, because its
 * interface to stuff information into json is easier.
 * \sa nierr::Status
 */
typedef struct nierr_Status
{
   int32_t code;        /*!< status code */
   uint32_t capacity;   /*!< capacity of the json buffer in bytes total */
   nierr_ReallocJson *reallocJson; /*!< function pointer to realloc json
                                     buffer. Please refer to nierr_ReallocJson
                                     function type for more details.
                                     \sa nierr_ReallocJson */
   char* json;          /*!< pointer to description buffer in jsonz
                          format. Please allocate and initialize this buffer
                          using nierr_Status_jsonReserve() or
                          nierr_Status_jsonSet(). It's automatically freed by
                          nierr_Status_reset().
                          \warning Do not write to this buffer directly without
                          using jsonz library.
                          */
} nierr_Status;

void nierr_Status_initialize(struct nierr_Status * status);

/*! the function to be used for nierr_Status::reallocJson field.
 *  This function is responsible to allocate/free json buffer and put the
 * buffer size into the capacity field for a given nierr_Status.
 * \return true if successful, else false. If size is 0, success is guaranteed.
 * \param[in] s status
 * \param[in] size if size>0, then it indicates minimum size to allocate. It may allocate more than size.
 *       If size is 0, then json buffer will be freed and capacity set to 0
 * \post if size is not 0, json field will be fully initialized jsonz buffer.
 * \post if size is 0, json field will be freed, and capacity reset to 0
 * \post if failed, nothing will be changed
 */
bool kNICCall nierr_defaultReallocJson(struct nierr_Status * s, uint32_t size);

/*! free the json string
 * \param[in,out] s status
 */
kNIInlineC void nierr_Status_jsonFree(struct nierr_Status *s)
   { s->reallocJson(s,0); }

/*! whether nierr_Status code is fatal
 * \param s status
 * \return true if fatal (code<0), false otherwise
 */
kNIInlineC bool nierr_Status_isFatal(const struct nierr_Status *s)
   { return (bool) /* thx msvc71 */ (s->code < 0); }

/*! whether nierr_Status code is not fatal
 * \param s status
 * \return true if not fatal (code>=0), false otherwise
 */
kNIInlineC bool nierr_Status_isNotFatal(const struct nierr_Status *s)
   { return !nierr_Status_isFatal(s); }

/*! whether nierr_Status code is warning
 * \param s status
 * \return true if warning (code>0), false otherwise
 */
kNIInlineC bool nierr_Status_isWarning(const struct nierr_Status *s)
   { return (bool) /* thx msvc71 */ (s->code > 0); }

/*! whether nierr_Status code is not warning
 * \param s status
 * \return true if not warning (code<=0), false otherwise
 */
kNIInlineC bool nierr_Status_isNotWarning(const struct nierr_Status *s)
   { return !nierr_Status_isWarning(s); }

/*! whether nierr_Status code is success (0)
 * \param s status
 * \return true if success (code==0), false otherwise
 */
kNIInlineC bool nierr_Status_isSuccess(const struct nierr_Status *s)
   { return (bool) /* thx msvc71 */ (s->code == 0); }

/* JSON Descriptor Support =============================================== */

/*! Empty nierr::Status json string. Defined as "{}" */
#define NIERR_JSON_EMPTY "{}"

/*! Status json key for file name where error originated. The value needs to
 * be a string */
#define NIERR_JSON_KEY_FILE "file"

/*! Status json key for line number where error originated. The value needs
 * to be an integer */
#define NIERR_JSON_KEY_LINE "line"

/*! Status json key for component name where error originated, usually taken
 * from kComponentName define from mxBS. The value needs to be a string */
#define NIERR_JSON_KEY_COMPONENT "component"

/*! Status json key for error constant. The value shall be a string */
#define NIERR_JSON_KEY_ERROR_CONSTANT "error_constant"

/*! Status json key for translator module responsible to translate the json
 * information into human readable string. The value needs to be a string. */
#define NIERR_JSON_KEY_TRANSLATOR "translator"

/*! Status json key for info for translator module */
#define NIERR_JSON_KEY_TRANSLATOR_INFO "translator_info"

/*! Status json key to capture std::exception::what(), if we happen to
 * translate std::exception to nierr::Exception. The value is a string */
#define NIERR_JSON_KEY_STD_EXCEPTION_WHAT "std_exception_what"

/*! Status json key for nested error object */
#define NIERR_JSON_KEY_NESTED_ERROR "nested_error"
/*! Status json key for nested error code */
#define NIERR_JSON_KEY_NESTED_ERROR_CODE "code"

/*! Status json key for internal error object */
#define NIERR_JSON_KEY_INTERNAL_ERROR "internal_error"
/*! Status json key for internal error code */
#define NIERR_JSON_KEY_INTERNAL_ERROR_CODE "code"
/*! Status json key for internal error string */
#define NIERR_JSON_KEY_INTERNAL_ERROR_STRING "string"
/*! Status json key for internal error API */
#define NIERR_JSON_KEY_INTERNAL_ERROR_API "api"

/*! Status json value for internal error API for win32 */
#define NIERR_JSON_VALUE_INTERNAL_ERROR_API_WIN32 "win32"
/*! Status json value for internal error API for HRESULT */
#define NIERR_JSON_VALUE_INTERNAL_ERROR_API_HRESULT "hresult"
/*! Status json value for internal error API for mach */
#define NIERR_JSON_VALUE_INTERNAL_ERROR_API_MACH "mach"
/*! Status json value for internal error API for errno */
#define NIERR_JSON_VALUE_INTERNAL_ERROR_API_ERRNO "errno"

}

#endif // NIERR_NIERR_STATUS_H_