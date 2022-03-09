#include <nixnet/nixnet_service.h>

#include <sstream>
#include <fstream>
#include <iostream>
#include <atomic>
#include <vector>
#include "custom/xnet_converters.h"
#include <server/converters.h>

namespace nixnet_grpc {

  // using nidevice_grpc::converters::calculate_linked_array_size;
  // using nidevice_grpc::converters::convert_from_grpc;
  // using nidevice_grpc::converters::convert_to_grpc;
  // using nidevice_grpc::converters::MatchState;

  // NiXnetService::NiXnetService(
  //     NiXnetLibraryInterface* library,
  //     ResourceRepositorySharedPtr session_repository, 
  //     const NiXnetFeatureToggles& feature_toggles)
  //     : library_(library),
  //     session_repository_(session_repository),
  //     feature_toggles_(feature_toggles)
  // {
  // }

  // NiXnetService::~NiXnetService()
  // {
  // }

  // Returns true if it's safe to use outputs of a method with the given status.
  inline bool status_ok(int32 status)
  {
    return status >= 0;
  }

  // template <typename TEnum>
  // void NiXnetService::CopyBytesToEnums(const std::string& input, google::protobuf::RepeatedField<TEnum>* output)
  // {
  //   for (auto item : input)
  //   {
  //     output->Add(item);
  //   }
  // }


  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiXnetService::GetProperty(::grpc::ServerContext* context, const GetPropertyRequest* request, GetPropertyResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_ref_grpc_session = request->session_ref();
      nxSessionRef_t session_ref = session_repository_->access_session(session_ref_grpc_session.id(), session_ref_grpc_session.name());
      u32 property_id;
      switch (request->property_id_enum_case()) {
        case nixnet_grpc::GetPropertySizeRequest::PropertyIdEnumCase::kPropertyId: {
          property_id = static_cast<u32>(request->property_id());
          break;
        }
        case nixnet_grpc::GetPropertySizeRequest::PropertyIdEnumCase::kPropertyIdRaw: {
          property_id = static_cast<u32>(request->property_id_raw());
          break;
        }
        case nixnet_grpc::GetPropertySizeRequest::PropertyIdEnumCase::PROPERTY_ID_ENUM_NOT_SET: {
          return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for property_id was not specified or out of range");
          break;
        }
      }

      u32 property_size {};
      auto status = library_->GetPropertySize(session_ref, property_id, &property_size);
      if(!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
      }
      
      void* property_value {};
      status = library_->GetProperty(session_ref, property_id, property_size, property_value);
      response->set_status(status);
      if (status_ok(status)) {
        // switch(property_type_map_[property_id]) {
        //     case "u32": {
        //         response->set_u32_scalar(*const_cast<uint32_t*>property_value);
        //     }
        // }
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

}  // namespace nixnet_grpc