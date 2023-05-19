#include <custom/nixnet_converters.h>
#include <nixnet.pb.h>
#include <nixnet/nixnet_service.h>
#include <server/converters.h>

#include <stdexcept>

using namespace nixnet_grpc::converters;

namespace nixnet_grpc {
using nidevice_grpc::converters::convert_from_grpc;
using nidevice_grpc::converters::convert_to_grpc;

namespace converters {
// Helper to read fields of u32 returned by nxReadState of nxState_CANComm and set them on gRPC message
void SetCanCommResponse(const u32 input, nixnet_grpc::CanCommResponse* output)
{
  u32 comm_state = nxCANComm_Get_CommState(input);
  u32 last_error = nxCANComm_Get_LastErr(input);

  output->set_comm_state(static_cast<nixnet_grpc::CanCommState>(comm_state));
  output->set_comm_state_raw(comm_state);
  output->set_transceiver_error(nxCANComm_Get_TcvrErr(input));
  output->set_sleep(nxCANComm_Get_Sleep(input));
  output->set_last_error(static_cast<nixnet_grpc::CanLastErr>(last_error));
  output->set_last_error_raw(last_error);
  output->set_transmit_error_counter(nxCANComm_Get_TxErrCount(input));
  output->set_receive_error_counter(nxCANComm_Get_RxErrCount(input));
}

// Helper to read fields of u32 returned by nxReadState of nxState_FlexRayComm and set them on gRPC message
void SetFlexRayCommResponse(const u32 input, nixnet_grpc::FlexRayCommResponse* output)
{
  u32 poc_state = nxFlexRayComm_Get_POCState(input);

  output->set_poc_state(static_cast<nixnet_grpc::FlexRayPocState>(poc_state));
  output->set_poc_state_raw(poc_state);
  output->set_clock_correction_failed(nxFlexRayComm_Get_ClockCorrFailed(input));
  output->set_passive_to_active_count(nxFlexRayComm_Get_PassiveToActiveCount(input));
  output->set_channel_a_sleep(nxFlexRayComm_Get_ChannelASleep(input));
  output->set_channel_b_sleep(nxFlexRayComm_Get_ChannelBSleep(input));
}

// Helper to read two fields of u32 returned by nxReadState of nxState_LINComm and set them on gRPC message
void SetLinCommResponse(const u32* input, nixnet_grpc::LinCommResponse* output)
{
  u32 comm_state = nxLINComm_Get_CommState(input[0]);
  output->set_sleep(nxLINComm_Get_Sleep(input[0]));
  output->set_comm_state(static_cast<nixnet_grpc::LinCommState>(comm_state));
  output->set_comm_state_raw(comm_state);
  output->set_last_error(nxLINComm_Get_LastErrCode(input[0]));
  output->set_last_error_received(nxLINComm_Get_LastErrReceived(input[0]));
  output->set_last_error_expected(nxLINComm_Get_LastErrExpected(input[0]));
  output->set_last_error_id(nxLINComm_Get_LastErrID(input[0]));
  output->set_transceiver_ready(nxLINComm_Get_TcvrRdy(input[0]));
  output->set_schedule_index(nxLINComm_Get2_ScheduleIndex(input[1]));
}

// Helper to read fields of u32 returned by nxReadState of nxState_SessionInfo and set them on gRPC message
void SetSessionInfoResponse(const u32& input, nixnet_grpc::SessionInfoResponse* output)
{
  output->set_info(static_cast<nixnet_grpc::SessionInfoState>(input));
  output->set_info_raw(input);
}
}  // namespace converters

// Returns true if it's safe to use outputs of a method with the given status.
inline bool status_ok(int32 status)
{
  return status >= 0;
}

// Helper to compute the StateSize based on the StateID
u32 GetStateSize(u32 state_id)
{
  u32 state_size;
  switch (state_id) {
    case nixnet_grpc::ReadState::READ_STATE_TIME_CURRENT:
    case nixnet_grpc::ReadState::READ_STATE_TIME_COMMUNICATING:
    case nixnet_grpc::ReadState::READ_STATE_TIME_START: {
      state_size = sizeof(nxTimestamp100ns_t);
      break;
    }
    case nixnet_grpc::ReadState::READ_STATE_CAN_COMM:
    case nixnet_grpc::ReadState::READ_STATE_FLEX_RAY_COMM:
    case nixnet_grpc::ReadState::READ_STATE_SESSION_INFO: {
      state_size = sizeof(u32);
      break;
    }
    case nixnet_grpc::ReadState::READ_STATE_FLEX_RAY_STATS: {
      state_size = sizeof(nxFlexRayStats_t);
      break;
    }
    case nixnet_grpc::ReadState::READ_STATE_LIN_COMM: {
      // The StateValue for nxState_LinComm should point to a u32 array with 2 elements.
      state_size = sizeof(u32) * 2;
      break;
    }
    case nixnet_grpc::ReadState::READ_STATE_J1939_COMM: {
      state_size = sizeof(nxJ1939CommState_t);
      break;
    }
    case nixnet_grpc::ReadState::READ_STATE_TIME_CURRENT_2:
    case nixnet_grpc::ReadState::READ_STATE_TIME_COMMUNICATING_2:
    case nixnet_grpc::ReadState::READ_STATE_TIME_START_2: {
      state_size = sizeof(nxTimeLocalNetwork_t);
      break;
    }
    default: {
      throw std::invalid_argument("The value for state_id was not specified or out of range");
    }
  }
  return state_size;
}

// Helper to get the LinDiagnosticScheduleChange value
u32 GetLinDiagnosticScheduleChangeValue(const WriteStateRequest* request)
{
  u32 state_value;
  switch (request->state_value().lin_diagnostic_schedule_change().schedule_enum_case()) {
    case nixnet_grpc::LinDiagnosticScheduleChangeRequest::ScheduleEnumCase::kSchedule: {
      state_value = static_cast<u32>(request->state_value().lin_diagnostic_schedule_change().schedule());
      break;
    }
    case nixnet_grpc::LinDiagnosticScheduleChangeRequest::ScheduleEnumCase::kScheduleRaw: {
      state_value = static_cast<u32>(request->state_value().lin_diagnostic_schedule_change().schedule_raw());
      break;
    }
    case nixnet_grpc::LinDiagnosticScheduleChangeRequest::ScheduleEnumCase::SCHEDULE_ENUM_NOT_SET: {
      throw std::invalid_argument("The value for Lin Diagnostic Schedule Change was not specified or out of range");
    }
  }
  return state_value;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
// ReadState API has an output parameter of type void * called StateValue. Based on the value of StateID,
// StateValue can point to u32, nxTimestamp100ns_t, _nxFlexRayStats_t, etc. which are of different sizes.
// Based on the StateID, we are setting the size of StateValue and after calling the ReadState API, the
// response is set appropriately.
::grpc::Status NiXnetService::ReadState(::grpc::ServerContext* context, const ReadStateRequest* request, ReadStateResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto session_grpc_session = request->session();
    nxSessionRef_t session = session_repository_->access_session(session_grpc_session.name());
    u32 state_id;
    switch (request->state_id_enum_case()) {
      case nixnet_grpc::ReadStateRequest::StateIdEnumCase::kStateId: {
        state_id = static_cast<u32>(request->state_id());
        break;
      }
      case nixnet_grpc::ReadStateRequest::StateIdEnumCase::kStateIdRaw: {
        state_id = static_cast<u32>(request->state_id_raw());
        break;
      }
      case nixnet_grpc::ReadStateRequest::StateIdEnumCase::STATE_ID_ENUM_NOT_SET: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for state_id was not specified or out of range");
        break;
      }
    }

    u32 state_size = GetStateSize(state_id);
    response->mutable_state_value()->mutable_state_value_raw()->resize(state_size, 0);
    nxStatus_t fault{};

    auto status = library_->ReadState(session, state_id, state_size, const_cast<char*>(response->mutable_state_value()->mutable_state_value_raw()->data()), &fault);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForNxSessionRef_t(context, status, session);
    }
    response->set_status(status);
    void* state_value_raw = (void*)response->state_value().state_value_raw().data();
    switch (state_id) {
      case nixnet_grpc::ReadState::READ_STATE_TIME_CURRENT: {
        response->mutable_state_value()->set_time_current(*(nxTimestamp100ns_t*)state_value_raw);
        break;
      }
      case nixnet_grpc::ReadState::READ_STATE_TIME_COMMUNICATING: {
        response->mutable_state_value()->set_time_communicating(*(nxTimestamp100ns_t*)state_value_raw);
        break;
      }
      case nixnet_grpc::ReadState::READ_STATE_TIME_START: {
        response->mutable_state_value()->set_time_start(*(nxTimestamp100ns_t*)state_value_raw);
        break;
      }
      case nixnet_grpc::ReadState::READ_STATE_CAN_COMM: {
        SetCanCommResponse(*(u32*)state_value_raw, response->mutable_state_value()->mutable_can_comm());
        break;
      }
      case nixnet_grpc::ReadState::READ_STATE_FLEX_RAY_COMM: {
        SetFlexRayCommResponse(*(u32*)state_value_raw, response->mutable_state_value()->mutable_flex_ray_comm());
        break;
      }
      case nixnet_grpc::ReadState::READ_STATE_LIN_COMM: {
        SetLinCommResponse((u32*)state_value_raw, response->mutable_state_value()->mutable_lin_comm());
        break;
      }
      case nixnet_grpc::ReadState::READ_STATE_SESSION_INFO: {
        SetSessionInfoResponse(*(u32*)state_value_raw, response->mutable_state_value()->mutable_session_info());
        break;
      }
      case nixnet_grpc::ReadState::READ_STATE_FLEX_RAY_STATS: {
        convert_to_grpc(*(_nxFlexRayStats_t*)state_value_raw, response->mutable_state_value()->mutable_flex_ray_stats());
        break;
      }
      case nixnet_grpc::ReadState::READ_STATE_J1939_COMM: {
        convert_to_grpc(*(_nxJ1939CommState_t*)state_value_raw, response->mutable_state_value()->mutable_j1939_comm_state());
        break;
      }
      case nixnet_grpc::ReadState::READ_STATE_TIME_CURRENT_2: {
        convert_to_grpc(*(_nxTimeLocalNetwork_t*)state_value_raw, response->mutable_state_value()->mutable_time_current2());
        break;
      }
      case nixnet_grpc::ReadState::READ_STATE_TIME_COMMUNICATING_2: {
        convert_to_grpc(*(_nxTimeLocalNetwork_t*)state_value_raw, response->mutable_state_value()->mutable_time_communicating2());
        break;
      }
      case nixnet_grpc::ReadState::READ_STATE_TIME_START_2: {
        convert_to_grpc(*(_nxTimeLocalNetwork_t*)state_value_raw, response->mutable_state_value()->mutable_time_start2());
        break;
      }
      default: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for state_id was not specified or out of range");
      }
    }
    response->set_fault(fault);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
// WriteState API has an input of type void * called StateValue. There are different possible values for
// StateValue based on the value of StateID passed in by user. We have defined complex message
// for StateValue with fields correponding to each of these StateIds in oneof. We have to assert that
// correct StateValue oneof is set by user based on StateId passed in. This requires custom implementation.
::grpc::Status NiXnetService::WriteState(::grpc::ServerContext* context, const WriteStateRequest* request, WriteStateResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto session_grpc_session = request->session();
    nxSessionRef_t session = session_repository_->access_session(session_grpc_session.name());
    u32 state_id;
    switch (request->state_id_enum_case()) {
      case nixnet_grpc::WriteStateRequest::StateIdEnumCase::kStateId: {
        state_id = static_cast<u32>(request->state_id());
        break;
      }
      case nixnet_grpc::WriteStateRequest::StateIdEnumCase::kStateIdRaw: {
        state_id = static_cast<u32>(request->state_id_raw());
        break;
      }
      case nixnet_grpc::WriteStateRequest::StateIdEnumCase::STATE_ID_ENUM_NOT_SET: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for state_id was not specified or out of range");
        break;
      }
    }

    u32 state_size = sizeof(u32);
    u32 state_value;
    switch (request->state_value().value_case()) {
      case nixnet_grpc::WriteStateValue::ValueCase::kLinScheduleChange: {
        if (state_id != nixnet_grpc::WriteState::WRITE_STATE_LIN_SCHEDULE_CHANGE) {
          return ::grpc::Status(::grpc::INVALID_ARGUMENT, "StateValue for specified StateID is not set");
        }
        state_value = request->state_value().lin_schedule_change();
        break;
      }
      case nixnet_grpc::WriteStateValue::ValueCase::kFlexRaySymbol: {
        if (state_id != nixnet_grpc::WriteState::WRITE_STATE_FLEX_RAY_SYMBOL) {
          return ::grpc::Status(::grpc::INVALID_ARGUMENT, "StateValue for specified StateID is not set");
        }
        state_value = request->state_value().flex_ray_symbol();
        break;
      }
      case nixnet_grpc::WriteStateValue::ValueCase::kLinDiagnosticScheduleChange: {
        if (state_id != nixnet_grpc::WriteState::WRITE_STATE_LIN_DIAGNOSTIC_SCHEDULE_CHANGE) {
          return ::grpc::Status(::grpc::INVALID_ARGUMENT, "StateValue for specified StateID is not set");
        }
        state_value = GetLinDiagnosticScheduleChangeValue(request);
        break;
      }
      case nixnet_grpc::WriteStateValue::ValueCase::kEthernetSleep: {
        if (state_id != nixnet_grpc::WriteState::WRITE_STATE_ETHERNET_SLEEP) {
          return ::grpc::Status(::grpc::INVALID_ARGUMENT, "StateValue for specified StateID is not set");
        }
        state_value = request->state_value().ethernet_sleep();
        break;
      }
      case nixnet_grpc::WriteStateValue::ValueCase::kEthernetWake: {
        if (state_id != nixnet_grpc::WriteState::WRITE_STATE_ETHERNET_WAKE) {
          return ::grpc::Status(::grpc::INVALID_ARGUMENT, "StateValue for specified StateID is not set");
        }
        state_value = request->state_value().ethernet_wake();
        break;
      }
      default: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for state_id was not specified or out of range");
      }
    }
    auto status = library_->WriteState(session, state_id, state_size, &state_value);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForNxSessionRef_t(context, status, session);
    }
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
// GetProperty API has an output of type void * which has different possible values based on PropertyId
// passed in by user. We have defined complex message with oneof corresponding to each of these possible
// value types. Based on PropertyId passed in, we need to interpret data returned by library and populate
// corresponding fields in the response. This requires custom implementation.
::grpc::Status NiXnetService::GetProperty(::grpc::ServerContext* context, const GetPropertyRequest* request, GetPropertyResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  nidevice_grpc::Session session_grpc_session;
  try {
    switch (request->session_repository_case()) {
      case nixnet_grpc::GetPropertyRequest::SessionRepositoryCase::kDevice: {
        session_grpc_session = request->device();
        break;
      }
      case nixnet_grpc::GetPropertyRequest::SessionRepositoryCase::kInterfaceRef: {
        session_grpc_session = request->interface_ref();
        break;
      }
      case nixnet_grpc::GetPropertyRequest::SessionRepositoryCase::kSession: {
        session_grpc_session = request->session();
        break;
      }
      case nixnet_grpc::GetPropertyRequest::SessionRepositoryCase::SESSION_REPOSITORY_NOT_SET: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for session/interface/device was not specified or out of range");
        break;
      }
    }
    // We store device, interface and session references in session_repository_ itself, either as owned session or
    // as dependent session. So we should always do a lookup in session_repository_.
    nxSessionRef_t session = session_repository_->access_session(session_grpc_session.name());
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
    auto status = library_->GetPropertySize(session, property_id, &property_size);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForNxSessionRef_t(context, status, session);
    }

    switch (property_type_map_[property_id]) {
      case u32_: {
        u32 property_value{};
        status = library_->GetProperty(session, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNxSessionRef_t(context, status, session);
        }
        response->set_u32_scalar(property_value);
        break;
      }
      case boolean_: {
        bool property_value{};
        status = library_->GetProperty(session, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNxSessionRef_t(context, status, session);
        }
        response->set_bool_scalar(property_value);
        break;
      }
      case u64_: {
        u64 property_value{};
        status = library_->GetProperty(session, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNxSessionRef_t(context, status, session);
        }
        response->set_u64_scalar(property_value);
        break;
      }
      case i32_: {
        i32 property_value{};
        status = library_->GetProperty(session, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNxSessionRef_t(context, status, session);
        }
        response->set_i32_scalar(property_value);
        break;
      }
      case f64_: {
        f64 property_value{};
        status = library_->GetProperty(session, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNxSessionRef_t(context, status, session);
        }
        response->set_f64_scalar(property_value);
        break;
      }
      case string_: {
        std::string property_value(property_size, '\0');
        status = library_->GetProperty(session, property_id, property_size, const_cast<char*>(property_value.c_str()));
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNxSessionRef_t(context, status, session);
        }
        std::string property_value_utf8;
        convert_to_grpc(property_value, &property_value_utf8);
        response->set_str(property_value_utf8);
        break;
      }
      case u32_array_: {
        int32_t number_of_elements = property_size / sizeof(u32);
        response->mutable_u32_array()->mutable_u32_array()->Clear();
        response->mutable_u32_array()->mutable_u32_array()->Resize(number_of_elements, 0);
        u32* property_value = reinterpret_cast<u32*>(response->mutable_u32_array()->mutable_u32_array()->mutable_data());
        status = library_->GetProperty(session, property_id, property_size, property_value);
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNxSessionRef_t(context, status, session);
        }
        break;
      }
      case db_ref_: {
        auto initiating_session_name = session_grpc_session.name();
        auto init_lambda = [&]() {
          nxDatabaseRef_t property_value;
          status = library_->GetProperty(session, property_id, property_size, &property_value);
          return std::make_tuple(status, property_value);
        };
        std::string session_name;
        status = nx_database_ref_t_resource_repository_->add_dependent_session(session_name, init_lambda, initiating_session_name);
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNxSessionRef_t(context, status, session);
        }
        response->mutable_db_ref()->set_name(session_name);
        break;
      }
      case db_ref_array_: {
        auto initiating_session_name = session_grpc_session.name();
        int32_t number_of_elements = property_size / sizeof(nxDatabaseRef_t);
        std::vector<nxDatabaseRef_t> property_value_vector(number_of_elements, 0U);
        nxDatabaseRef_t* property_value = static_cast<nxDatabaseRef_t*>(property_value_vector.data());
        status = library_->GetProperty(session, property_id, property_size, property_value);
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNxSessionRef_t(context, status, session);
        }
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
              std::string session_name;
              status = nx_database_ref_t_resource_repository_->add_dependent_session(session_name, init_lambda, initiating_session_name);
              nidevice_grpc::Session dependent_session{};
              dependent_session.set_name(session_name);
              return dependent_session;
            });
        break;
      }
      case dev_ref_: {
        auto initiating_session_name = session_grpc_session.name();
        auto init_lambda = [&]() {
          nxSessionRef_t property_value;
          status = library_->GetProperty(session, property_id, property_size, &property_value);
          return std::make_tuple(status, property_value);
        };
        std::string session_name;
        // We are adding it to session_repository_ and not to "device repository", because devices don't have a close API,
        // so it makes sense to tie their lifetime with session's lifetime.
        status = session_repository_->add_dependent_session(session_name, init_lambda, initiating_session_name);
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNxSessionRef_t(context, status, session);
        }
        response->mutable_dev_ref()->set_name(session_name);
        break;
      }
      case dev_ref_array_: {
        auto initiating_session_name = session_grpc_session.name();
        int32_t number_of_elements = property_size / sizeof(nxSessionRef_t);
        std::vector<nxSessionRef_t> property_value_vector(number_of_elements, 0U);
        nxSessionRef_t* property_value = property_value_vector.data();
        status = library_->GetProperty(session, property_id, property_size, property_value);
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNxSessionRef_t(context, status, session);
        }
        response->mutable_dev_ref_array()->mutable_dev_ref()->Clear();
        response->mutable_dev_ref_array()->mutable_dev_ref()->Reserve(number_of_elements);
        std::transform(
            property_value_vector.begin(),
            property_value_vector.end(),
            google::protobuf::RepeatedFieldBackInserter(response->mutable_dev_ref_array()->mutable_dev_ref()),
            [&](auto x) {
              auto init_lambda = [&]() {
                return std::make_tuple(status, x);
              };
              std::string session_name;
              // We are adding it to session_repository_ and not to "device repository", because devices don't have a close API,
              // so it makes sense to tie their lifetime with session's lifetime.
              status = session_repository_->add_dependent_session(session_name, init_lambda, initiating_session_name);
              nidevice_grpc::Session dependent_session{};
              dependent_session.set_name(session_name);
              return dependent_session;
            });
        break;
      }
      case intf_ref_array_: {
        auto initiating_session_name = session_grpc_session.name();
        int32_t number_of_elements = property_size / sizeof(nxSessionRef_t);
        std::vector<nxSessionRef_t> property_value_vector(number_of_elements, 0U);
        nxSessionRef_t* property_value = property_value_vector.data();
        status = library_->GetProperty(session, property_id, property_size, property_value);
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNxSessionRef_t(context, status, session);
        }
        response->mutable_intf_ref_array()->mutable_intf_ref()->Clear();
        response->mutable_intf_ref_array()->mutable_intf_ref()->Reserve(number_of_elements);
        std::transform(
            property_value_vector.begin(),
            property_value_vector.end(),
            google::protobuf::RepeatedFieldBackInserter(response->mutable_intf_ref_array()->mutable_intf_ref()),
            [&](auto x) {
              auto init_lambda = [&]() {
                return std::make_tuple(status, x);
              };
              std::string session_name;
              // We are adding it to session_repository_ and not to "interface repository", because interfaces don't have a close API,
              // so it makes sense to tie their lifetime with session's lifetime.
              status = session_repository_->add_dependent_session(session_name, init_lambda, initiating_session_name);
              nidevice_grpc::Session dependent_session{};
              dependent_session.set_name(session_name);
              return dependent_session;
            });
        break;
      }
      case nxEptRxFilter_Element_t_array_: {
        int32_t number_of_elements = property_size / sizeof(nxEptRxFilter_Element_t);
        std::vector<nxEptRxFilter_Element_t> property_value_vector(number_of_elements);
        nxEptRxFilter_Element_t* property_value = static_cast<nxEptRxFilter_Element_t*>(property_value_vector.data());
        status = library_->GetProperty(session, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNxSessionRef_t(context, status, session);
        }
        convert_to_grpc(property_value_vector, response->mutable_ept_rx_filter_array()->mutable_ept_rx_filter());
        break;
      }
      default: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "Specified property_id is not supported.");
        break;
      }
    }
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
// Custom implementation reason same as GetProperty API.
::grpc::Status NiXnetService::GetSubProperty(::grpc::ServerContext* context, const GetSubPropertyRequest* request, GetSubPropertyResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto session_grpc_session = request->session();
    nxSessionRef_t session = session_repository_->access_session(session_grpc_session.name());
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
    auto status = library_->GetSubPropertySize(session, active_index, property_id, &property_size);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForNxSessionRef_t(context, status, session);
    }

    switch (subproperty_type_map_[property_id]) {
      case u32_: {
        u32 property_value{};
        status = library_->GetSubProperty(session, active_index, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNxSessionRef_t(context, status, session);
        }
        response->set_u32_scalar(property_value);
        break;
      }
      case f64_: {
        f64 property_value{};
        status = library_->GetSubProperty(session, active_index, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNxSessionRef_t(context, status, session);
        }
        response->set_f64_scalar(property_value);
        break;
      }
      case string_: {
        std::string property_value(property_size, '\0');
        status = library_->GetSubProperty(session, active_index, property_id, property_size, const_cast<char*>(property_value.c_str()));
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNxSessionRef_t(context, status, session);
        }
        std::string property_value_utf8;
        convert_to_grpc(property_value, &property_value_utf8);
        response->set_str(property_value_utf8);
        break;
      }
      default: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "Specified property_id is not supported.");
        break;
      }
    }
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
// Custom implementation reason same as GetProperty API.
::grpc::Status NiXnetService::DbGetProperty(::grpc::ServerContext* context, const DbGetPropertyRequest* request, DbGetPropertyResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto dbobject_grpc_session = request->dbobject();
    nxDatabaseRef_t dbobject = nx_database_ref_t_resource_repository_->access_session(dbobject_grpc_session.name());
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
    auto status = library_->DbGetPropertySize(dbobject, property_id, &property_size);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForNxDatabaseRef_t(context, status, dbobject);
    }

    switch (dbproperty_type_map_[property_id]) {
      case u32_: {
        u32 property_value{};
        status = library_->DbGetProperty(dbobject, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNxDatabaseRef_t(context, status, dbobject);
        }
        response->set_u32_scalar(property_value);
        break;
      }
      case boolean_: {
        bool property_value{};
        status = library_->DbGetProperty(dbobject, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNxDatabaseRef_t(context, status, dbobject);
        }
        response->set_bool_scalar(property_value);
        break;
      }
      case u64_: {
        u64 property_value{};
        status = library_->DbGetProperty(dbobject, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNxDatabaseRef_t(context, status, dbobject);
        }
        response->set_u64_scalar(property_value);
        break;
      }
      case f64_: {
        f64 property_value{};
        status = library_->DbGetProperty(dbobject, property_id, property_size, &property_value);
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNxDatabaseRef_t(context, status, dbobject);
        }
        response->set_f64_scalar(property_value);
        break;
      }
      case string_: {
        std::string property_value(property_size, '\0');
        status = library_->DbGetProperty(dbobject, property_id, property_size, const_cast<char*>(property_value.c_str()));
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNxDatabaseRef_t(context, status, dbobject);
        }
        std::string property_value_utf8;
        convert_to_grpc(property_value, &property_value_utf8);
        response->set_str(property_value_utf8);
        break;
      }
      case u32_array_: {
        int32_t number_of_elements = property_size / sizeof(u32);
        response->mutable_u32_array()->mutable_u32_array()->Clear();
        response->mutable_u32_array()->mutable_u32_array()->Resize(number_of_elements, 0);
        u32* property_value = reinterpret_cast<u32*>(response->mutable_u32_array()->mutable_u32_array()->mutable_data());
        status = library_->DbGetProperty(dbobject, property_id, property_size, property_value);
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNxDatabaseRef_t(context, status, dbobject);
        }
        break;
      }
      case u8_array_: {
        int32_t number_of_elements = property_size / sizeof(u8);
        std::string property_value(number_of_elements, '\0');
        status = library_->DbGetProperty(dbobject, property_id, property_size, (u8*)property_value.data());
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNxDatabaseRef_t(context, status, dbobject);
        }
        response->set_u8_array(property_value);
      }
      case db_ref_: {
        auto initiating_session_name = dbobject_grpc_session.name();
        auto init_lambda = [&]() {
          nxDatabaseRef_t property_value;
          status = library_->DbGetProperty(dbobject, property_id, property_size, &property_value);
          return std::make_tuple(status, property_value);
        };
        std::string session_name;
        status = nx_database_ref_t_resource_repository_->add_dependent_session(session_name, init_lambda, initiating_session_name);
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNxDatabaseRef_t(context, status, dbobject);
        }
        response->mutable_db_ref()->set_name(session_name);
        break;
      }
      case db_ref_array_: {
        int32_t number_of_elements = property_size / sizeof(nxDatabaseRef_t);
        auto initiating_session_name = dbobject_grpc_session.name();
        std::vector<nxDatabaseRef_t> property_value_vector(number_of_elements, 0U);
        nxDatabaseRef_t* property_value = static_cast<nxDatabaseRef_t*>(property_value_vector.data());
        status = library_->DbGetProperty(dbobject, property_id, property_size, property_value);
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNxDatabaseRef_t(context, status, dbobject);
        }
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
              std::string session_name;
              status = nx_database_ref_t_resource_repository_->add_dependent_session(session_name, init_lambda, initiating_session_name);
              nidevice_grpc::Session dependent_session{};
              dependent_session.set_name(session_name);
              return dependent_session;
            });
        break;
      }
      default: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "Specified property_id is not supported.");
        break;
      }
    }
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
// SetProperty API has an input of type void * which has different possible values based on PropertyId
// passed in by user. We have defined complex message with oneof corresponding to each of these possible
// value types. We need to read data from correct oneof based on property PropertyId passed in by user.
// This requires custom implementation.
::grpc::Status NiXnetService::SetProperty(::grpc::ServerContext* context, const SetPropertyRequest* request, SetPropertyResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto session_grpc_session = request->session();
    nxSessionRef_t session = session_repository_->access_session(session_grpc_session.name());
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

    nxStatus_t status;
    switch (property_type_map_[property_id]) {
      case u32_: {
        u32 property_size = sizeof(u32);
        u32 property_value = request->u32_scalar();
        status = library_->SetProperty(session, property_id, property_size, &property_value);
        break;
      }
      case boolean_: {
        u32 property_size = sizeof(bool);
        bool property_value = request->bool_scalar();
        status = library_->SetProperty(session, property_id, property_size, &property_value);
        break;
      }
      case u64_: {
        u32 property_size = sizeof(u64);
        u64 property_value = request->u64_scalar();
        status = library_->SetProperty(session, property_id, property_size, &property_value);
        break;
      }
      case i32_: {
        u32 property_size = sizeof(i32);
        i32 property_value = request->i32_scalar();
        status = library_->SetProperty(session, property_id, property_size, &property_value);
        break;
      }
      case f64_: {
        u32 property_size = sizeof(f64);
        f64 property_value = request->f64_scalar();
        status = library_->SetProperty(session, property_id, property_size, &property_value);
        break;
      }
      case string_: {
        auto property_value_mbcs = convert_from_grpc<std::string>(request->str());
        u32 property_size = property_value_mbcs.size();
        status = library_->SetProperty(session, property_id, property_size, const_cast<char*>(property_value_mbcs.c_str()));
        break;
      }
      case u32_array_: {
        u32 property_size = request->u32_array().u32_array().size() * sizeof(u32);
        u32* property_value = const_cast<u32*>(request->u32_array().u32_array().data());
        status = library_->SetProperty(session, property_id, property_size, property_value);
        break;
      }
      case db_ref_: {
        u32 property_size = sizeof(nxDatabaseRef_t);
        auto db_ref = request->db_ref();
        nxDatabaseRef_t property_value = nx_database_ref_t_resource_repository_->access_session(db_ref.name());
        status = library_->SetProperty(session, property_id, property_size, &property_value);
        break;
      }
      case db_ref_array_: {
        int32_t number_of_elements = request->db_ref_array().db_ref().size();
        std::vector<nxDatabaseRef_t> property_value(number_of_elements, 0U);
        std::transform(
            request->db_ref_array().db_ref().begin(),
            request->db_ref_array().db_ref().begin() + number_of_elements,
            property_value.end(),
            [&](auto x) {
              nxDatabaseRef_t db_ref = nx_database_ref_t_resource_repository_->access_session(x.name());
              return db_ref;
            });
        u32 property_size = number_of_elements * sizeof(nxDatabaseRef_t);
        status = library_->SetProperty(session, property_id, property_size, static_cast<nxDatabaseRef_t*>(property_value.data()));
        break;
      }
      case nxEptRxFilter_Element_t_array_: {
        u32 property_size = request->ept_rx_filter_array().ept_rx_filter().size() * sizeof(nxEptRxFilter_Element_t);
        auto property_value = convert_from_grpc<nxEptRxFilter_Element_t>(request->ept_rx_filter_array().ept_rx_filter());
        status = library_->SetProperty(session, property_id, property_size, property_value.data());
        break;
      }
      default: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "Specified property_id is not supported.");
        break;
      }
    }
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForNxSessionRef_t(context, status, session);
    }
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
// Custom implementation reason same as SetProperty API.
::grpc::Status NiXnetService::SetSubProperty(::grpc::ServerContext* context, const SetSubPropertyRequest* request, SetSubPropertyResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto session_grpc_session = request->session();
    nxSessionRef_t session = session_repository_->access_session(session_grpc_session.name());
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

    nxStatus_t status;
    switch (subproperty_type_map_[property_id]) {
      case u32_: {
        u32 property_size = sizeof(u32);
        u32 property_value = request->u32_scalar();
        status = library_->SetSubProperty(session, active_index, property_id, property_size, &property_value);
        break;
      }
      case f64_: {
        u32 property_size = sizeof(f64);
        f64 property_value = request->f64_scalar();
        status = library_->SetSubProperty(session, active_index, property_id, property_size, &property_value);
        break;
      }
      case string_: {
        auto property_value_mbcs = convert_from_grpc<std::string>(request->str());
        u32 property_size = property_value_mbcs.size();
        status = library_->SetSubProperty(session, active_index, property_id, property_size, const_cast<char*>(property_value_mbcs.c_str()));
        break;
      }
      default: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "Specified property_id is not supported.");
        break;
      }
    }
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForNxSessionRef_t(context, status, session);
    }
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
// Custom implementation reason same as SetProperty API.
::grpc::Status NiXnetService::DbSetProperty(::grpc::ServerContext* context, const DbSetPropertyRequest* request, DbSetPropertyResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto dbobject_grpc_session = request->dbobject();
    nxDatabaseRef_t dbobject = nx_database_ref_t_resource_repository_->access_session(dbobject_grpc_session.name());
    u32 property_id;
    switch (request->dbproperty_id_enum_case()) {
      case nixnet_grpc::DbSetPropertyRequest::DbpropertyIdEnumCase::kPropertyId: {
        property_id = static_cast<u32>(request->property_id());
        break;
      }
      case nixnet_grpc::DbSetPropertyRequest::DbpropertyIdEnumCase::kPropertyIdRaw: {
        property_id = static_cast<u32>(request->property_id_raw());
        break;
      }
      case nixnet_grpc::DbSetPropertyRequest::DbpropertyIdEnumCase::DBPROPERTY_ID_ENUM_NOT_SET: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for property_id was not specified or out of range");
        break;
      }
    }

    nxStatus_t status;
    switch (dbproperty_type_map_[property_id]) {
      case u32_: {
        u32 property_size = sizeof(u32);
        u32 property_value = request->u32_scalar();
        status = library_->DbSetProperty(dbobject, property_id, property_size, &property_value);
        break;
      }
      case boolean_: {
        u32 property_size = sizeof(boolean_);
        bool property_value = request->bool_scalar();
        status = library_->DbSetProperty(dbobject, property_id, property_size, &property_value);
        break;
      }
      case u64_: {
        u32 property_size = sizeof(u64);
        u64 property_value = request->u64_scalar();
        status = library_->DbSetProperty(dbobject, property_id, property_size, &property_value);
        break;
      }
      case f64_: {
        u32 property_size = sizeof(f64);
        f64 property_value = request->f64_scalar();
        status = library_->DbSetProperty(dbobject, property_id, property_size, &property_value);
        break;
      }
      case string_: {
        auto property_value_mbcs = convert_from_grpc<std::string>(request->str());
        u32 property_size = property_value_mbcs.size();
        status = library_->DbSetProperty(dbobject, property_id, property_size, const_cast<char*>(property_value_mbcs.c_str()));
        break;
      }
      case u32_array_: {
        u32* property_value = const_cast<u32*>(request->u32_array().u32_array().data());
        u32 property_size = (u32)(request->u32_array().u32_array().size()) * sizeof(u32);
        status = library_->DbSetProperty(dbobject, property_id, property_size, property_value);
        break;
      }
      case u8_array_: {
        u8* property_value = (u8*)request->u8_array().c_str();
        u32 property_size = (u32)(request->u8_array().size());
        status = library_->DbSetProperty(dbobject, property_id, property_size, property_value);
      }
      case db_ref_: {
        u32 property_size = sizeof(nxDatabaseRef_t);
        auto db_ref = request->db_ref();
        nxDatabaseRef_t property_value = nx_database_ref_t_resource_repository_->access_session(db_ref.name());
        status = library_->DbSetProperty(dbobject, property_id, property_size, &property_value);
        break;
      }
      case db_ref_array_: {
        int32_t number_of_elements = request->db_ref_array().db_ref().size();
        std::vector<nxDatabaseRef_t> property_value(number_of_elements, 0U);
        std::transform(
            request->db_ref_array().db_ref().begin(),
            request->db_ref_array().db_ref().begin() + number_of_elements,
            property_value.end(),
            [&](auto x) {
              nxDatabaseRef_t db_ref = nx_database_ref_t_resource_repository_->access_session(x.name());
              return db_ref;
            });
        u32 property_size = number_of_elements * sizeof(nxDatabaseRef_t);
        status = library_->DbSetProperty(dbobject, property_id, property_size, static_cast<nxDatabaseRef_t*>(property_value.data()));
        break;
      }
    }
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForNxDatabaseRef_t(context, status, dbobject);
    }
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
// This API uses size mechanism similar to `ivi-datance` but needs to call a different API to get
// buffer size. This could potentially be implemented as `xnet-dance` in codegen. Right now no codegen
// mechanism exists, so added a custom implementation for now.
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
      return ConvertApiErrorStatusForNxDatabaseRef_t(context, status, 0);
    }

    std::string alias_buffer(size_of_alias_buffer, '\0');
    std::string file_path_buffer(size_of_file_path_buffer, '\0');
    u32 number_of_databases{};

    status = library_->DbGetDatabaseList(ip_address, size_of_alias_buffer, const_cast<char*>(alias_buffer.c_str()), size_of_file_path_buffer, const_cast<char*>(file_path_buffer.c_str()), &number_of_databases);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForNxDatabaseRef_t(context, status, 0);
    }
    response->set_status(status);
    std::string alias_buffer_utf8;
    convert_to_grpc(alias_buffer, &alias_buffer_utf8);
    response->set_alias_buffer(alias_buffer_utf8.c_str());
    std::string file_path_buffer_utf8;
    convert_to_grpc(file_path_buffer, &file_path_buffer_utf8);
    response->set_filepath_buffer(file_path_buffer_utf8.c_str());
    response->set_number_of_databases(number_of_databases);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
// Custom implementation reason same as DbGetDatabaseList API.
::grpc::Status NiXnetService::DbGetDBCAttribute(::grpc::ServerContext* context, const DbGetDBCAttributeRequest* request, DbGetDBCAttributeResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto db_object_grpc_session = request->db_object();
    nxDatabaseRef_t dbobject = nx_database_ref_t_resource_repository_->access_session(db_object_grpc_session.name());
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

    auto attribute_name_mbcs = convert_from_grpc<std::string>(request->attribute_name());
    auto attribute_name = attribute_name_mbcs.c_str();
    u32 attribute_text_size{};
    auto status = library_->DbGetDBCAttributeSize(dbobject, mode, attribute_name, &attribute_text_size);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForNxDatabaseRef_t(context, status, dbobject);
    }

    std::string attribute_text(attribute_text_size, '\0');
    u32 is_default{};

    status = library_->DbGetDBCAttribute(dbobject, mode, attribute_name, attribute_text_size, const_cast<char*>(attribute_text.c_str()), &is_default);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForNxDatabaseRef_t(context, status, dbobject);
    }
    response->set_status(status);
    response->set_is_default(is_default);
    std::string attribute_text_utf8;
    convert_to_grpc(attribute_text, &attribute_text_utf8);
    response->set_attribute_text(attribute_text_utf8.c_str());
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

::grpc::Status NiXnetService::ConvertApiErrorStatusForNxSessionRef_t(::grpc::ServerContextBase* context, int32_t status, nxSessionRef_t session)
{
  static_assert(nidevice_grpc::kMaxGrpcErrorDescriptionSize >= 2048, "StatusToString expects a minimum buffer size.");
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  library_->StatusToString(status, nidevice_grpc::kMaxGrpcErrorDescriptionSize, &description[0]);
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

::grpc::Status NiXnetService::ConvertApiErrorStatusForNxDatabaseRef_t(::grpc::ServerContextBase* context, int32_t status, nxDatabaseRef_t session)
{
  static_assert(nidevice_grpc::kMaxGrpcErrorDescriptionSize >= 2048, "StatusToString expects a minimum buffer size.");
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  library_->StatusToString(status, nidevice_grpc::kMaxGrpcErrorDescriptionSize, &description[0]);
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

void convert_to_grpc(std::vector<u8>& input, google::protobuf::RepeatedPtrField<nixnet_grpc::FrameBufferResponse>* output, u32 number_of_bytes, u32 protocol, std::map<std::int32_t, std::int32_t> enetflags_output_map)
{
  auto buffer_ptr = (void*)input.data();
  while (buffer_ptr < input.data() + number_of_bytes) {
    auto frame_buffer = new FrameBufferResponse();
    convert_to_grpc(buffer_ptr, frame_buffer, protocol, enetflags_output_map);
    output->AddAllocated(frame_buffer);
    if (protocol == nixnet_grpc::Protocol::PROTOCOL_ENET) {
      auto enet_frame_ptr = (nxFrameEnet_t*)buffer_ptr;
      buffer_ptr = nxFrameIterateEthernetRead(enet_frame_ptr);
    }
    else {
      buffer_ptr = nxFrameIterate((nxFrameVar_t*)buffer_ptr);
    }
  }
}

void convert_enet_frame_to_grpc(const void* input, nixnet_grpc::FrameBufferResponse* output, u32 protocol, std::map<std::int32_t, std::int32_t> enetflags_output_map)
{
  nixnet_grpc::EnetFrameResponse* enet_frame = new nixnet_grpc::EnetFrameResponse();
  nxFrameEnet_t* nxEnetFrame = (nxFrameEnet_t*)input;
  enet_frame->set_type(static_cast<nixnet_grpc::EnetFrameType>(nxEnetFrame->Type));
  enet_frame->set_type_raw(nxEnetFrame->Type);
  enet_frame->set_device_timestamp(nxEnetFrame->DeviceTimestamp);
  enet_frame->set_network_timestamp(nxEnetFrame->NetworkTimestamp);
  if (nxEnetFrame->Flags & 0x80000000) {
    auto enet_flags_enum_omap_it = enetflags_output_map.find(0x80000000);
    if (enet_flags_enum_omap_it != enetflags_output_map.end()) {
      enet_frame->add_flags_mapped(EnetFlags::ENET_FLAGS_TRANSMIT);
    }
  }
  if (nxEnetFrame->Flags & 0x40000000) {
    auto enet_flags_enum_omap_it = enetflags_output_map.find(0x40000000);
    if (enet_flags_enum_omap_it != enetflags_output_map.end()) {
      enet_frame->add_flags_mapped(EnetFlags::ENET_FLAGS_RECEIVE);
    }
  }
  if (nxEnetFrame->Flags & 0x00800000) {
    auto enet_flags_enum_omap_it = enetflags_output_map.find(0x00800000);
    if (enet_flags_enum_omap_it != enetflags_output_map.end()) {
      enet_frame->add_flags_mapped(EnetFlags::ENET_FLAGS_NETWORK_SYNCED);
    }
  }
  if (nxEnetFrame->Flags & 0x00010000) {
    auto enet_flags_enum_omap_it = enetflags_output_map.find(0x00010000);
    if (enet_flags_enum_omap_it != enetflags_output_map.end()) {
      enet_frame->add_flags_mapped(EnetFlags::ENET_FLAGS_ERROR);
    }
  }
  enet_frame->set_flags_raw(nxEnetFrame->Flags);
  auto frame_data_length = nxEnetFrame->Length - ENET_FRAME_HEADER_LENGTH - ENET_FRAME_FCS_SIZE;
  enet_frame->mutable_frame_data()->assign((const char*)nxEnetFrame->FrameData, frame_data_length);

  output->set_allocated_enet(enet_frame);
}

void convert_frame_to_grpc(const void* input, nixnet_grpc::FrameBufferResponse* output, u32 protocol, std::map<std::int32_t, std::int32_t> enetflags_output_map)
{
  nxFrameVar_t* nxFrame = (nxFrameVar_t*)input;
  nixnet_grpc::FrameResponse* frame = new nixnet_grpc::FrameResponse();
  frame->set_timestamp(nxFrame->Timestamp);
  frame->set_identifier(nxFrame->Identifier);
  frame->set_type(static_cast<nixnet_grpc::FrameType>(nxFrame->Type));
  frame->set_type_raw(nxFrame->Type);
  if (nxFrame->Flags & 0x01) {
    frame->add_flags(FrameFlags::FRAME_FLAGS_FLEX_RAY_STARTUP);
  }
  if (nxFrame->Flags & 0x02) {
    frame->add_flags(FrameFlags::FRAME_FLAGS_FLEX_RAY_SYNC);
  }
  if (nxFrame->Flags & 0x04) {
    frame->add_flags(FrameFlags::FRAME_FLAGS_FLEX_RAY_PREAMBLE);
  }
  if (nxFrame->Flags & 0x10) {
    frame->add_flags(FrameFlags::FRAME_FLAGS_FLEX_RAY_CH_A);
  }
  if (nxFrame->Flags & 0x20) {
    frame->add_flags(FrameFlags::FRAME_FLAGS_FLEX_RAY_CH_B);
  }
  frame->set_flags_raw(nxFrame->Flags);
  frame->set_info(nxFrame->Info);
  auto payload_length = nxFrameGetPayloadLength(nxFrame);
  frame->mutable_payload()->assign((const char*)nxFrame->Payload, payload_length);

  switch (protocol) {
    case nixnet_grpc::Protocol::PROTOCOL_CAN:
      output->set_allocated_can(frame);
      break;
    case nixnet_grpc::Protocol::PROTOCOL_LIN:
      output->set_allocated_lin(frame);
      break;
    case nixnet_grpc::Protocol::PROTOCOL_FLEX_RAY:
      output->set_allocated_flex_ray(frame);
      break;
    case nixnet_grpc::Protocol::PROTOCOL_J1939:
      output->set_allocated_j1939(frame);
      break;
    default:
      throw std::invalid_argument("The value for protocol was not specified or out of range");
      break;
  }
}

void convert_to_grpc(const void* input, nixnet_grpc::FrameBufferResponse* output, u32 protocol, std::map<std::int32_t, std::int32_t> enetflags_output_map)
{
  if (protocol == nixnet_grpc::Protocol::PROTOCOL_ENET) {
    convert_enet_frame_to_grpc(input, output, protocol, enetflags_output_map);
  }
  else {
    convert_frame_to_grpc(input, output, protocol, enetflags_output_map);
  }
}

void convert_to_grpc(std::vector<f64>& input, google::protobuf::RepeatedField<double>* output, u32 number_of_values_returned, u32 number_of_signals)
{
  output->Resize(number_of_signals * number_of_values_returned, 0U);
  std::transform(
      input.begin(),
      input.begin() + (number_of_signals * number_of_values_returned),
      google::protobuf::RepeatedFieldBackInserter(output),
      [&](auto x) {
        return x;
      });
}

u32 get_frame_buffer_size(int32 number_of_frames, u32 max_payload_per_frame, u32 protocol)
{
  if (protocol == Protocol::PROTOCOL_ENET) {
    return number_of_frames * (ENET_FRAME_HEADER_LENGTH + ENET_FRAME_FCS_SIZE + max_payload_per_frame);
  }
  else {
    return number_of_frames * nxFrameSize(max_payload_per_frame);
  }
}
}  // namespace nixnet_grpc

namespace nidevice_grpc {
namespace converters {
template <>
void convert_to_grpc(const _nxFlexRayStats_t& input, nixnet_grpc::FlexRayStats* output)
{
  output->set_num_syntax_error_ch_a(input.NumSyntaxErrorChA);
  output->set_num_syntax_error_ch_b(input.NumSyntaxErrorChB);
  output->set_num_content_error_ch_a(input.NumContentErrorChA);
  output->set_num_content_error_ch_b(input.NumContentErrorChB);
  output->set_num_slot_boundary_violation_ch_a(input.NumSlotBoundaryViolationChA);
  output->set_num_slot_boundary_violation_ch_b(input.NumSlotBoundaryViolationChB);
}

template <>
void convert_to_grpc(const _nxJ1939CommState_t& input, nixnet_grpc::J1939CommState* output)
{
  output->set_pgn(input.PGN);
  output->set_source_address(input.SourceAddress);
  output->set_destination_address(input.DestinationAddress);
  output->set_transmit_error(input.TransmitError);
  output->set_receive_error(input.ReceiveError);
}

template <>
void convert_to_grpc(const nxEptRxFilter_Element_t& input, nixnet_grpc::EptRxFilter* output)
{
  output->set_use_flags(input.UseFlags);
  output->set_vid(input.VID);
  output->set_priority(input.Priority);
  output->mutable_destination_mac()->copy((char*)input.DestinationMAC, sizeof(nxMACAddress_t));
}

template <>
nxEptRxFilter_Element_t convert_from_grpc(const nixnet_grpc::EptRxFilter& input)
{
  auto output = nxEptRxFilter_Element_t();
  output.UseFlags = input.use_flags();
  output.VID = input.vid();
  output.Priority = input.priority();
  memcpy(output.DestinationMAC, input.destination_mac().c_str(), sizeof(nxMACAddress_t));
  return output;
}

}  // namespace converters
}  // namespace nidevice_grpc
