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
      case nixnet_grpc::GetPropertyRequest::PropertyIdEnumCase::kPropertyId: {
        property_id = static_cast<u32>(request->property_id());
        break;
      }
      case nixnet_grpc::GetPropertyRequest::PropertyIdEnumCase::kPropertyIdRaw: {
        property_id = static_cast<u32>(request->property_id_raw());
        break;
      }
      case nixnet_grpc::GetPropertyRequest::PropertyIdEnumCase::PROPERTY_ID_ENUM_NOT_SET: {
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
        std::string property_value(property_size, '\0');
        status = library_->GetProperty(session_ref, property_id, property_size, const_cast<char*>(property_value.c_str()));
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        response->set_str(property_value.c_str());
        break;
      }
      case u32_array_: {
        int32_t number_of_elements = property_size / sizeof(u32);
        response->mutable_u32_array()->mutable_u32_array()->Clear();
        response->mutable_u32_array()->mutable_u32_array()->Resize(number_of_elements, 0);
        u32* property_value = reinterpret_cast<u32*>(response->mutable_u32_array()->mutable_u32_array()->mutable_data());
        status = library_->GetProperty(session_ref, property_id, property_size, property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        break;
      }
      case string_array_: {
        std::string property_value(property_size, '\0');
        status = library_->GetProperty(session_ref, property_id, property_size, const_cast<char*>(property_value.c_str()));
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        response->set_string_array(property_value.c_str());
        break;
      }
      case db_ref_: {
        auto initiating_session_id = session_repository_->access_session_id(session_ref_grpc_session.id(), session_ref_grpc_session.name());
        auto init_lambda = [&]() {
          nxDatabaseRef_t property_value;
          status = library_->GetProperty(session_ref, property_id, property_size, &property_value);
          return std::make_tuple(status, property_value);
        };
        uint32_t session_id = 0;
        status = nx_database_ref_t_resource_repository_->add_dependent_session("", init_lambda, initiating_session_id, session_id);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        response->mutable_db_ref()->set_id(session_id);
        break;
      }
      case db_ref_array_: {
        int32_t number_of_elements = property_size / sizeof(nxDatabaseRef_t);
        auto initiating_session_id = session_repository_->access_session_id(session_ref_grpc_session.id(), session_ref_grpc_session.name());
        std::vector<nxDatabaseRef_t> property_value_vector(number_of_elements, 0U);
        nxDatabaseRef_t* property_value = static_cast<nxDatabaseRef_t*>(property_value_vector.data());
        status = library_->GetProperty(session_ref, property_id, property_size, property_value);
        response->mutable_db_ref_array()->mutable_db_ref()->Clear();
        response->mutable_db_ref_array()->mutable_db_ref()->Reserve(number_of_elements);
        std::transform(
          property_value_vector.begin(),
          property_value_vector.end(),
          google::protobuf::RepeatedFieldBackInserter(response->mutable_db_ref_array()->mutable_db_ref()),
          [&](auto x) {
            auto init_lambda = [&]() {
              return std::make_tuple(status, x);
            };
            uint32_t session_id{};
            status = nx_database_ref_t_resource_repository_->add_dependent_session("", init_lambda, initiating_session_id, session_id);
            nidevice_grpc::Session dependent_session{};
            dependent_session.set_id(session_id);
            return dependent_session;
          });
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
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

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiXnetService::GetSubProperty(::grpc::ServerContext* context, const GetSubPropertyRequest* request, GetSubPropertyResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto session_ref_grpc_session = request->session_ref();
    nxSessionRef_t session_ref = session_repository_->access_session(session_ref_grpc_session.id(), session_ref_grpc_session.name());
    u32 active_index = request->active_index();
    u32 property_id;
    switch (request->subproperty_id_enum_case()) {
      case nixnet_grpc::GetSubPropertyRequest::SubpropertyIdEnumCase::kPropertyId: {
        property_id = static_cast<u32>(request->property_id());
        break;
      }
      case nixnet_grpc::GetSubPropertyRequest::SubpropertyIdEnumCase::kPropertyIdRaw: {
        property_id = static_cast<u32>(request->property_id_raw());
        break;
      }
      case nixnet_grpc::GetSubPropertyRequest::SubpropertyIdEnumCase::SUBPROPERTY_ID_ENUM_NOT_SET: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for property_id was not specified or out of range");
        break;
      }
    }

    u32 property_size{};
    auto status = library_->GetSubPropertySize(session_ref, active_index, property_id, &property_size);
    if (!status_ok(status)) {
      response->set_status(status);
      return ::grpc::Status::OK;
    }

    switch (subproperty_type_map_[property_id]) {
      case u32_: {
        u32 property_value{};
        status = library_->GetSubProperty(session_ref, active_index, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        response->set_u32_scalar(property_value);
        break;
      }
      case f64_: {
        f64 property_value{};
        status = library_->GetSubProperty(session_ref, active_index, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        response->set_f64_scalar(property_value);
        break;
      }
      case string_: {
        std::string property_value(property_size, '\0');
        status = library_->GetSubProperty(session_ref, active_index, property_id, property_size, const_cast<char*>(property_value.c_str()));
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        response->set_str(property_value.c_str());
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

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiXnetService::DbGetProperty(::grpc::ServerContext* context, const DbGetPropertyRequest* request, DbGetPropertyResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto dbobject_ref_grpc_session = request->dbobject_ref();
    nxDatabaseRef_t dbobject_ref = nx_database_ref_t_resource_repository_->access_session(dbobject_ref_grpc_session.id(), dbobject_ref_grpc_session.name());
    u32 property_id;
    switch (request->dbproperty_id_enum_case()) {
      case nixnet_grpc::DbGetPropertyRequest::DbpropertyIdEnumCase::kPropertyId: {
        property_id = static_cast<u32>(request->property_id());
        break;
      }
      case nixnet_grpc::DbGetPropertyRequest::DbpropertyIdEnumCase::kPropertyIdRaw: {
        property_id = static_cast<u32>(request->property_id_raw());
        break;
      }
      case nixnet_grpc::DbGetPropertyRequest::DbpropertyIdEnumCase::DBPROPERTY_ID_ENUM_NOT_SET: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for property_id was not specified or out of range");
        break;
      }
    }

    u32 property_size{};
    auto status = library_->DbGetPropertySize(dbobject_ref, property_id, &property_size);
    if (!status_ok(status)) {
      response->set_status(status);
      return ::grpc::Status::OK;
    }

    switch (dbproperty_type_map_[property_id]) {
      case u32_: {
        u32 property_value{};
        status = library_->DbGetProperty(dbobject_ref, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        response->set_u32_scalar(property_value);
        break;
      }
      case boolean_: {
        bool property_value{};
        status = library_->DbGetProperty(dbobject_ref, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        response->set_bool_scalar(property_value);
        break;
      }
      case u64_: {
        u64 property_value{};
        status = library_->DbGetProperty(dbobject_ref, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        response->set_u64_scalar(property_value);
        break;
      }
      case f64_: {
        f64 property_value{};
        status = library_->DbGetProperty(dbobject_ref, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        response->set_f64_scalar(property_value);
        break;
      }
      case string_: {
        std::string property_value(property_size, '\0');
        status = library_->DbGetProperty(dbobject_ref, property_id, property_size, const_cast<char*>(property_value.c_str()));
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        response->set_str(property_value.c_str());
        break;
      }
      case u32_array_: {
        int32_t number_of_elements = property_size / sizeof(u32);
        response->mutable_u32_array()->mutable_u32_array()->Clear();
        response->mutable_u32_array()->mutable_u32_array()->Resize(number_of_elements, 0);
        u32* property_value = reinterpret_cast<u32*>(response->mutable_u32_array()->mutable_u32_array()->mutable_data());
        status = library_->DbGetProperty(dbobject_ref, property_id, property_size, property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        break;
      }
      case u8_array_: {
        int32_t number_of_elements = property_size / sizeof(u8);
        std::string property_value(number_of_elements, '\0');
        status = library_->DbGetProperty(dbobject_ref, property_id, property_size, (u8*)property_value.data());
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        response->set_u8_array(property_value);
      }
      case db_ref_: {
        auto initiating_session_id = nx_database_ref_t_resource_repository_->access_session_id(dbobject_ref_grpc_session.id(), dbobject_ref_grpc_session.name());
        auto init_lambda = [&]() {
          nxDatabaseRef_t property_value;
          status = library_->GetProperty(dbobject_ref, property_id, property_size, &property_value);
          return std::make_tuple(status, property_value);
        };
        uint32_t session_id = 0;
        status = nx_database_ref_t_resource_repository_->add_dependent_session("", init_lambda, initiating_session_id, session_id);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        response->mutable_db_ref()->set_id(session_id);
        break;
      }
      case db_ref_array_: {
        int32_t number_of_elements = property_size / sizeof(nxDatabaseRef_t);
        auto initiating_session_id = nx_database_ref_t_resource_repository_->access_session_id(dbobject_ref_grpc_session.id(), dbobject_ref_grpc_session.name());
        std::vector<nxDatabaseRef_t> property_value_vector(number_of_elements, 0U);
        nxDatabaseRef_t* property_value = static_cast<nxDatabaseRef_t*>(property_value_vector.data());
        status = library_->GetProperty(dbobject_ref, property_id, property_size, property_value);
        response->mutable_db_ref_array()->mutable_db_ref()->Clear();
        response->mutable_db_ref_array()->mutable_db_ref()->Reserve(number_of_elements);
        std::transform(
          property_value_vector.begin(),
          property_value_vector.end(),
          google::protobuf::RepeatedFieldBackInserter(response->mutable_db_ref_array()->mutable_db_ref()),
          [&](auto x) {
            auto init_lambda = [&]() {
              return std::make_tuple(status, x);
            };
            uint32_t session_id{};
            status = nx_database_ref_t_resource_repository_->add_dependent_session("", init_lambda, initiating_session_id, session_id);
            nidevice_grpc::Session dependent_session{};
            dependent_session.set_id(session_id);
            return dependent_session;
          });
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
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

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiXnetService::SetProperty(::grpc::ServerContext* context, const SetPropertyRequest* request, SetPropertyResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto session_ref_grpc_session = request->session_ref();
    nxSessionRef_t session_ref = session_repository_->access_session(session_ref_grpc_session.id(), session_ref_grpc_session.name());
    u32 property_id;
    switch (request->property_id_enum_case()) {
      case nixnet_grpc::SetPropertyRequest::PropertyIdEnumCase::kPropertyId: {
        property_id = static_cast<u32>(request->property_id());
        break;
      }
      case nixnet_grpc::SetPropertyRequest::PropertyIdEnumCase::kPropertyIdRaw: {
        property_id = static_cast<u32>(request->property_id_raw());
        break;
      }
      case nixnet_grpc::SetPropertyRequest::PropertyIdEnumCase::PROPERTY_ID_ENUM_NOT_SET: {
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
        u32 property_value = request->u32_scalar();
        status = library_->SetProperty(session_ref, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        break;
      }
      case boolean_: {
        bool property_value = request->bool_scalar();
        status = library_->SetProperty(session_ref, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        break;
      }
      case u64_: {
        u64 property_value = request->u64_scalar();
        status = library_->SetProperty(session_ref, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        break;
      }
      case i32_: {
        i32 property_value = request->i32_scalar();
        status = library_->SetProperty(session_ref, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        break;
      }
      case f64_: {
        f64 property_value = request->f64_scalar();
        status = library_->SetProperty(session_ref, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        break;
      }
      case string_: {
        std::string property_value = request->str();
        status = library_->SetProperty(session_ref, property_id, (u32)property_value.size(), const_cast<char*>(property_value.c_str()));
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        break;
      }
      case u32_array_: {
        u32* property_value = const_cast<u32*>(request->u32_array().u32_array().data());
        u32 property_value_size = (u32)request->u32_array().u32_array().size();
        status = library_->SetProperty(session_ref, property_id, property_value_size*sizeof(u32), property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        break;
      }
      case string_array_: {
        std::string property_value = request->string_array();
        status = library_->SetProperty(session_ref, property_id, (u32)property_value.size(), const_cast<char*>(property_value.c_str()));
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        break;
      }
      case db_ref_: {
        auto property_value = request->db_ref();
        nxDatabaseRef_t property_value_ref = nx_database_ref_t_resource_repository_->access_session(property_value.id(), property_value.name());
        status = library_->SetProperty(session_ref, property_id, property_size, &property_value_ref);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        break;
      }
      case db_ref_array_: {
        int32_t number_of_elements = request->db_ref_array().db_ref().size();
        std::vector<nxDatabaseRef_t> property_value(number_of_elements, 0U);
        std::transform(
          request->db_ref_array().db_ref().begin(),
          request->db_ref_array().db_ref().begin() + number_of_elements,
          property_value.rbegin(),
          [&](auto x) {
            nxDatabaseRef_t db_ref = nx_database_ref_t_resource_repository_->access_session(x.id(), x.name());
            return db_ref;
          });
        status = library_->SetProperty(session_ref, property_id, number_of_elements*sizeof(nxDatabaseRef_t), static_cast<nxDatabaseRef_t*>(property_value.data()));
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
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

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiXnetService::SetSubProperty(::grpc::ServerContext* context, const SetSubPropertyRequest* request, SetSubPropertyResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto session_ref_grpc_session = request->session_ref();
    nxSessionRef_t session_ref = session_repository_->access_session(session_ref_grpc_session.id(), session_ref_grpc_session.name());
    u32 active_index = request->active_index();
    u32 property_id;
    switch (request->subproperty_id_enum_case()) {
      case nixnet_grpc::SetSubPropertyRequest::SubpropertyIdEnumCase::kPropertyId: {
        property_id = static_cast<u32>(request->property_id());
        break;
      }
      case nixnet_grpc::SetSubPropertyRequest::SubpropertyIdEnumCase::kPropertyIdRaw: {
        property_id = static_cast<u32>(request->property_id_raw());
        break;
      }
      case nixnet_grpc::SetSubPropertyRequest::SubpropertyIdEnumCase::SUBPROPERTY_ID_ENUM_NOT_SET: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for property_id was not specified or out of range");
        break;
      }
    }

    u32 property_size{};
    auto status = library_->GetSubPropertySize(session_ref, active_index, property_id, &property_size);
    if (!status_ok(status)) {
      response->set_status(status);
      return ::grpc::Status::OK;
    }

    switch (subproperty_type_map_[property_id]) {
      case u32_: {
        u32 property_value = request->u32_scalar();
        status = library_->SetSubProperty(session_ref, active_index, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        break;
      }
      case f64_: {
        f64 property_value = request->f64_scalar();
        status = library_->SetSubProperty(session_ref, active_index, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        break;
      }
      case string_: {
        std::string property_value = request->str();
        status = library_->SetSubProperty(session_ref, active_index, property_id, (u32)property_value.size(), const_cast<char*>(property_value.c_str()));
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
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

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiXnetService::DbSetProperty(::grpc::ServerContext* context, const DbSetPropertyRequest* request, DbSetPropertyResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto dbobject_ref_grpc_session = request->dbobject_ref();
    nxDatabaseRef_t dbobject_ref = session_repository_->access_session(dbobject_ref_grpc_session.id(), dbobject_ref_grpc_session.name());
    u32 property_id;
    switch (request->dbproperty_id_enum_case()) {
      case nixnet_grpc::DbGetPropertyRequest::DbpropertyIdEnumCase::kPropertyId: {
        property_id = static_cast<u32>(request->property_id());
        break;
      }
      case nixnet_grpc::DbGetPropertyRequest::DbpropertyIdEnumCase::kPropertyIdRaw: {
        property_id = static_cast<u32>(request->property_id_raw());
        break;
      }
      case nixnet_grpc::DbGetPropertyRequest::DbpropertyIdEnumCase::DBPROPERTY_ID_ENUM_NOT_SET: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for property_id was not specified or out of range");
        break;
      }
    }

    u32 property_size{};
    auto status = library_->DbGetPropertySize(dbobject_ref, property_id, &property_size);
    if (!status_ok(status)) {
      response->set_status(status);
      return ::grpc::Status::OK;
    }

    switch (dbproperty_type_map_[property_id]) {
      case u32_: {
        u32 property_value = request->u32_scalar();
        status = library_->DbSetProperty(dbobject_ref, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        break;
      }
      case boolean_: {
        bool property_value = request->bool_scalar();
        status = library_->DbSetProperty(dbobject_ref, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        break;
      }
      case u64_: {
        u64 property_value = request->u64_scalar();
        status = library_->DbSetProperty(dbobject_ref, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        break;
      }
      case f64_: {
        f64 property_value = request->f64_scalar();
        status = library_->DbSetProperty(dbobject_ref, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        break;
      }
      case string_: {
        std::string property_value = request->str();
        status = library_->DbSetProperty(dbobject_ref, property_id, (u32)property_value.size(), const_cast<char*>(property_value.c_str()));
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        break;
      }
      case u32_array_: {
        u32* property_value = const_cast<u32*>(request->u32_array().u32_array().data());
        u32 property_value_buffer_size = (u32)(request->u32_array().u32_array().size())*sizeof(u32);
        status = library_->DbSetProperty(dbobject_ref, property_id, property_value_buffer_size, property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        break;
      }
      case u8_array_: {
        u8* property_value = (u8*)request->u8_array().c_str();
        u32 property_value_buffer_size = (u32)(request->u8_array().size());
        status = library_->DbSetProperty(dbobject_ref, property_id, property_value_buffer_size, property_value);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
      }
      case db_ref_: {
        auto property_value = request->db_ref();
        nxDatabaseRef_t property_value_ref = nx_database_ref_t_resource_repository_->access_session(property_value.id(), property_value.name());
        status = library_->SetProperty(dbobject_ref, property_id, property_size, &property_value_ref);
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        break;
      }
      case db_ref_array_: {
        int32_t number_of_elements = request->db_ref_array().db_ref().size();
        std::vector<nxDatabaseRef_t> property_value(number_of_elements, 0U);
        std::transform(
          request->db_ref_array().db_ref().begin(),
          request->db_ref_array().db_ref().begin() + number_of_elements,
          property_value.rbegin(),
          [&](auto x) {
            nxDatabaseRef_t db_ref = nx_database_ref_t_resource_repository_->access_session(x.id(), x.name());
            return db_ref;
          });
        status = library_->SetProperty(dbobject_ref, property_id, number_of_elements*sizeof(nxDatabaseRef_t), static_cast<nxDatabaseRef_t*>(property_value.data()));
        if (!status_ok(status)) {
          response->set_status(status);
          return ::grpc::Status::OK;
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

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiXnetService::DbGetDatabaseList(::grpc::ServerContext* context, const DbGetDatabaseListRequest* request, DbGetDatabaseListResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto ip_address = request->ip_address().c_str();
    u32 size_of_alias_buffer{};
    u32 size_of_file_path_buffer{};
    auto status = library_->DbGetDatabaseListSizes(ip_address, &size_of_alias_buffer, &size_of_file_path_buffer);
    if (!status_ok(status)) {
      response->set_status(status);
      return ::grpc::Status::OK;
    }

    std::string alias_buffer(size_of_alias_buffer, '\0');
    std::string file_path_buffer(size_of_file_path_buffer, '\0');
    u32 number_of_databases{};

    status = library_->DbGetDatabaseList(ip_address, size_of_alias_buffer, const_cast<char*>(alias_buffer.c_str()), size_of_file_path_buffer, const_cast<char*>(file_path_buffer.c_str()), &number_of_databases);
    response->set_status(status);
    if (status_ok(status)) {
      response->set_alias_buffer(alias_buffer.c_str());
      response->set_file_path_buffer(file_path_buffer.c_str());
      response->set_number_of_databases(number_of_databases);
    }
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiXnetService::DbGetDBCAttribute(::grpc::ServerContext* context, const DbGetDBCAttributeRequest* request, DbGetDBCAttributeResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto db_object_ref_grpc_session = request->db_object_ref();
    nxDatabaseRef_t db_object_ref = nx_database_ref_t_resource_repository_->access_session(db_object_ref_grpc_session.id(), db_object_ref_grpc_session.name());
    u32 mode;
    switch (request->mode_enum_case()) {
      case nixnet_grpc::DbGetDBCAttributeRequest::ModeEnumCase::kMode: {
        mode = static_cast<u32>(request->mode());
        break;
      }
      case nixnet_grpc::DbGetDBCAttributeRequest::ModeEnumCase::kModeRaw: {
        mode = static_cast<u32>(request->mode_raw());
        break;
      }
      case nixnet_grpc::DbGetDBCAttributeRequest::ModeEnumCase::MODE_ENUM_NOT_SET: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for mode was not specified or out of range");
        break;
      }
    }

    auto attribute_name = request->attribute_name().c_str();
    u32 attribute_text_size {};
    auto status = library_->DbGetDBCAttributeSize(db_object_ref, mode, attribute_name, &attribute_text_size);
    if (!status_ok(status)) {
      response->set_status(status);
      return ::grpc::Status::OK;
    }

    std::string attribute_text(attribute_text_size, '\0');
    u32 is_default{};
      
    status = library_->DbGetDBCAttribute(db_object_ref, mode, attribute_name, attribute_text_size, const_cast<char*>(attribute_text.c_str()), &is_default);
    response->set_status(status);
    if (status_ok(status)) {
      response->set_is_default(is_default);
      response->set_attribute_text(attribute_text.c_str());
    }
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

}  // namespace nixnet_grpc