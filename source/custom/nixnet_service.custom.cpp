#include <nixnet/nixnet_service.h>
#include <server/converters.h>

#include <atomic>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace nixnet_grpc {

// Returns true if it's safe to use outputs of a method with the given status.
inline bool status_ok(int32 status)
{
  return status >= 0;
}

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

    u32 property_size{};
    auto status = library_->GetPropertySize(session_ref, property_id, &property_size);
    if (!status_ok(status)) {
      response->set_status(status);
      return ::grpc::Status::OK;
    }

    switch (property_type_map_[property_id]) {
      case u32_: {
        u32 property_value{};
        status = library_->GetProperty(session_ref, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        response->set_u32_scalar(property_value);
        break;
      }
      case boolean_: {
        bool property_value{};
        status = library_->GetProperty(session_ref, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        response->set_bool_scalar(property_value);
        break;
      }
      case u64_: {
        u64 property_value{};
        status = library_->GetProperty(session_ref, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        response->set_u64_scalar(property_value);
        break;
      }
      case i32_: {
        i32 property_value{};
        status = library_->GetProperty(session_ref, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        response->set_i32_scalar(property_value);
        break;
      }
      case f64_: {
        f64 property_value{};
        status = library_->GetProperty(session_ref, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        response->set_f64_scalar(property_value);
        break;
      }
      case string_: {
        std::string property_value = "";
        property_value.resize(property_size, '0');
        status = library_->GetProperty(session_ref, property_id, property_size, property_value.data());
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        response->set_str(property_value.c_str());
        break;
      }
      case u32_array_: {
        response->mutable_u32_array()->mutable_u32_array()->Clear();
        response->mutable_u32_array()->mutable_u32_array()->Resize(property_size, 0);
        u32* property_value = reinterpret_cast<u32*>(response->mutable_u32_array()->mutable_u32_array()->mutable_data());
        status = library_->GetProperty(session_ref, property_id, property_size, property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        break;
      }
      case ref_: {
        u32 property_value{};
        status = library_->GetProperty(session_ref, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        response->mutable_ref()->set_id(property_value);
        break;
      }
      case string_array_: {
        std::string property_value = "";
        property_value.resize(property_size, '0');
        status = library_->GetProperty(session_ref, property_id, property_size, property_value.data());
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        response->set_string_array(property_value.c_str());
        break;
      }
      case ref_array_: {
        std::vector<u32> property_value(property_size, 0);
        status = library_->GetProperty(session_ref, property_id, property_size, property_value.data());
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        auto response_iterator = response->mutable_ref_array()->mutable_ref()->begin();
        for (auto it = property_value.begin(); it != property_value.end(); it++, response_iterator++) {
          response_iterator->set_id(*it);
        }
        break;
      }
    }
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

}  // namespace nixnet_grpc