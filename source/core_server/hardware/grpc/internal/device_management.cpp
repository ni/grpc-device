#include "device_management.h"
#include "shared_library.h"
#include <nisyscfg.h>

namespace ni
{
namespace hardware
{
namespace grpc
{
namespace internal
{
   using NISysCfgInitializeSessionPtr = NISysCfgStatus (*)(
      const char*                            targetName,                // NULL or "" => localhost
      const char*                            username,                  // NULL or "" => no credentials
      const char*                            password,                  // NULL or "" => no credentials
      NISysCfgLocale                         language,                  // LCID or 0 to indicate default.
      NISysCfgBool                           forcePropertyRefresh,
      unsigned int                           connectTimeoutMsec,
      NISysCfgEnumExpertHandle*              expertEnumHandle,          // Can be NULL
      NISysCfgSessionHandle*                 sessionHandle
      );
   using NISysCfgCreateFilterPtr = NISysCfgStatus(*)(
      NISysCfgSessionHandle                  sessionHandle,
      NISysCfgFilterHandle*                  filterHandle
       );
   using NISysCfgSetFilterPropertyPtr = NISysCfgStatus (*)(
      NISysCfgFilterHandle                   filterHandle,
      NISysCfgFilterProperty                 propertyID,
      ...
      );
   using NISysCfgFindHardwarePtr = NISysCfgStatus (*)(
      NISysCfgSessionHandle                  sessionHandle,
      NISysCfgFilterMode                     filterMode,                // Ignored if filter handle is NULL
      NISysCfgFilterHandle                   filterHandle,              // Can be NULL
      const char*                            expertNames,               // NULL or "" => all experts
      NISysCfgEnumResourceHandle*            resourceEnumHandle
      );
   using NISysCfgNextResourcePtr = NISysCfgStatus(*)(
      NISysCfgSessionHandle                  sessionHandle,
      NISysCfgEnumResourceHandle             resourceEnumHandle,
      NISysCfgResourceHandle*                resourceHandle
      );
   using NISysCfgGetResourceIndexedPropertyPtr = NISysCfgStatus(*)(
      NISysCfgResourceHandle                 resourceHandle,
      NISysCfgIndexedProperty                propertyID,
      unsigned int                           index,
      void *                                 value
      );
   using NISysCfgGetResourcePropertyPtr = NISysCfgStatus(*)(
      NISysCfgResourceHandle                 resourceHandle,
      NISysCfgResourceProperty               propertyID,
      void*                                  value
      );
   using NISysCfgCloseHandlePtr = NISysCfgStatus(*)(
      void*                                  syscfgHandle
      );
   using NISysCfgGetStatusDescriptionPtr = NISysCfgStatus(*)(
      NISysCfgSessionHandle                  sessionHandle,              // Can be NULL
      NISysCfgStatus                         status,
      char**                                 detailedDescription
      );
   using NISysCfgFreeDetailedStringPtr = NISysCfgStatus (*)(
      char                                   str[]
      );

#if defined(_MSC_VER)
   static const char * syscfg_library_name = "nisyscfg.dll";
#else
   static const char * syscfg_library_name = "./libnisyscfg.so";
#endif

   DeviceManagement::DeviceManagement()
   {
   }

   void DeviceManagement::enumerate_devices(::grpc::ServerContext* context, const EnumerateDevicesRequest* request, EnumerateDevicesResponse* response)
   {
      NISysCfgStatus status = NISysCfg_OK;
      NISysCfgSessionHandle session = NULL;
      NISysCfgEnumResourceHandle resources_handle = NULL;
      NISysCfgResourceHandle resource = NULL;
      NISysCfgFilterHandle filter = NULL;
      char expert_name[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
      char resource_name[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
      char alias[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
      char model[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
      char vendor[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
      char serial_number[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
      char* detailed_description = NULL;

      ni::hardware::grpc::internal::SharedLibrary library(syscfg_library_name);
      library.load();

      auto syscfg_initialize_session = reinterpret_cast<NISysCfgInitializeSessionPtr>(library.get_function_pointer("NISysCfgInitializeSession"));
      auto syscfg_create_filter = reinterpret_cast<NISysCfgCreateFilterPtr>(library.get_function_pointer("NISysCfgCreateFilter"));
      auto syscfg_set_filter_property = reinterpret_cast<NISysCfgSetFilterPropertyPtr>(library.get_function_pointer("NISysCfgSetFilterProperty"));
      auto syscfg_find_hardware = reinterpret_cast<NISysCfgFindHardwarePtr>(library.get_function_pointer("NISysCfgFindHardware"));
      auto sysycfg_next_resource = reinterpret_cast<NISysCfgNextResourcePtr>(library.get_function_pointer("NISysCfgNextResource"));
      auto sysycfg_get_resource_indexed_property = reinterpret_cast<NISysCfgGetResourceIndexedPropertyPtr>(library.get_function_pointer("NISysCfgGetResourceIndexedProperty"));
      auto sysycfg_get_resource_property = reinterpret_cast<NISysCfgGetResourcePropertyPtr>(library.get_function_pointer("NISysCfgGetResourceProperty"));
      auto sysycfg_close_handle = reinterpret_cast<NISysCfgCloseHandlePtr>(library.get_function_pointer("NISysCfgCloseHandle"));
      auto sysycfg_get_status_description = reinterpret_cast<NISysCfgGetStatusDescriptionPtr>(library.get_function_pointer("NISysCfgGetStatusDescription"));
      auto sysycfg_free_detailed_string = reinterpret_cast<NISysCfgFreeDetailedStringPtr>(library.get_function_pointer("NISysCfgFreeDetailedString"));

      if (NISysCfg_Succeeded(status = syscfg_initialize_session("localhost", NULL, NULL, NISysCfgLocaleEnglish, NISysCfgBoolTrue, 10000, NULL, &session)))
      {
         if (NISysCfg_Succeeded(status = syscfg_create_filter(session, &filter)))
         {
            syscfg_set_filter_property(filter, NISysCfgFilterPropertyIsDevice, NISysCfgBoolTrue);
            syscfg_set_filter_property(filter, NISysCfgFilterPropertyIsChassis, NISysCfgBoolTrue);
            if (NISysCfg_Succeeded(status = syscfg_find_hardware(session, NISysCfgFilterModeAny, filter, NULL, &resources_handle)))
            {
               while (NISysCfg_Succeeded(status) && (status = sysycfg_next_resource(session, resources_handle, &resource)) == NISysCfg_OK)
               {
                  sysycfg_get_resource_indexed_property(resource, NISysCfgIndexedPropertyExpertName, 0, expert_name);
                  if (strcmp(expert_name, "network") != 0)
                  {
                     auto properties = response->mutable_devices()->Add();
                     sysycfg_get_resource_indexed_property(resource, NISysCfgIndexedPropertyExpertResourceName, 0, resource_name);
                     sysycfg_get_resource_indexed_property(resource, NISysCfgIndexedPropertyExpertUserAlias, 0, alias);
                     sysycfg_get_resource_property(resource, NISysCfgResourcePropertyProductName, model);
                     sysycfg_get_resource_property(resource, NISysCfgResourcePropertyVendorName, vendor);
                     sysycfg_get_resource_property(resource, NISysCfgResourcePropertySerialNumber, serial_number);
                     properties->set_resourcename(resource_name);
                     properties->set_alias(alias);
                     properties->set_model(alias);
                     properties->set_vendor(vendor);
                     properties->set_serialnumber(serial_number);
                     status = sysycfg_close_handle(resource);
                  }
               }
            }
         }
      }
      if (NISysCfg_Failed(status))
      {
         sysycfg_get_status_description(session, status, &detailed_description);
         printf("Error: %s\n", detailed_description);
         sysycfg_free_detailed_string(detailed_description);
      }
      sysycfg_close_handle(filter);
      sysycfg_close_handle(resources_handle);
      sysycfg_close_handle(session);
   }
} // namespace internal
} // namespace grpc
} // namespace hardware
} // namespace ni
