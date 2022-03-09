#include <nixnet/nixnet_service.h>
#include <nixnet.pb.h>
#include <server/converters.h>
#include "custom/nixnet_converters.h"

namespace nixnet_grpc {
using nidevice_grpc::converters::convert_to_grpc;
    
::grpc::Status NiXnetService::ReadState(::grpc::ServerContext* context, const ReadStateRequest* request, ReadStateResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_ref_grpc_session = request->session_ref();
        nxSessionRef_t session_ref = session_repository_->access_session(session_ref_grpc_session.id(), session_ref_grpc_session.name());
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

        u32 state_size = request->state_size();
        u64 time_stamp_100ns;
        u32 comm_state;
        FlexRayStats flex_ray_stats;
        J1939CommState J1939_comm_state;
        TimeLocalNetwork time_local_network;
        void* state_value;

        switch(state_id){
            case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_CURRENT : 
            case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_COMMUNICATING : 
            case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_START :{
                state_value = &time_stamp_100ns;
                break;
            }
            case nixnet_grpc::ReadState::READ_STATE_STATE_CAN_COMM :
            case nixnet_grpc::ReadState::READ_STATE_STATE_FLEX_RAY_COMM :
            case nixnet_grpc::ReadState::READ_STATE_STATE_LIN_COMM :
            case nixnet_grpc::ReadState::READ_STATE_STATE_SESSION_INFO :{
                state_value = &comm_state;
                break;
            }
            case nixnet_grpc::ReadState::READ_STATE_STATE_FLEX_RAY_STATS :{
                state_value = &flex_ray_stats;
                break;
            }
            case nixnet_grpc::ReadState::READ_STATE_STATE_J1939_COMM :{
                state_value = &J1939_comm_state;
                break;
            }
            case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_CURRENT_2 : 
            case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_COMMUNICATING_2 : 
            case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_START_2 :{
                state_value = &time_local_network;
                break;
            }
        }
        nxStatus_t fault {};
        auto status = library_->ReadState(session_ref, state_id, state_size, state_value, &fault);
        response->set_status(status);
        if (status == 0) {
            switch(state_id){
            case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_CURRENT :{
                response->mutable_state_value()->set_time_current(*((u64*)state_value));
                break;
            } 
            case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_COMMUNICATING :{
                response->mutable_state_value()->set_time_communicating(*((u64*)state_value));
                break;
            } 
            case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_START :{
                response->mutable_state_value()->set_time_start(*((u64*)state_value));
                break;
            }
            case nixnet_grpc::ReadState::READ_STATE_STATE_CAN_COMM :{
                response->mutable_state_value()->set_can_comm(*((u32*)state_value));
                break;
            }
            case nixnet_grpc::ReadState::READ_STATE_STATE_FLEX_RAY_COMM :{
                response->mutable_state_value()->set_flex_ray_comm(*((u32*)state_value));
                break;
            }
            case nixnet_grpc::ReadState::READ_STATE_STATE_LIN_COMM :{
                response->mutable_state_value()->set_lin_comm(*((u32*)state_value));
                break;
            }
            case nixnet_grpc::ReadState::READ_STATE_STATE_SESSION_INFO :{
                response->mutable_state_value()->set_session_info(*((u32*)state_value));
                break;
            }
            case nixnet_grpc::ReadState::READ_STATE_STATE_FLEX_RAY_STATS :{
                convert_to_grpc(*(_nxFlexRayStats_t*)state_value, response->mutable_state_value()->mutable_flex_ray_stat());
                break;
            }
            case nixnet_grpc::ReadState::READ_STATE_STATE_J1939_COMM :{
                convert_to_grpc(*(_nxJ1939CommState_t*)state_value, response->mutable_state_value()->mutable_comm_stat());
                break;
            }
            case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_CURRENT_2 :{
                convert_to_grpc(*(_nxTimeLocalNetwork_t*)state_value, response->mutable_state_value()->mutable_time_current2());
                break;
            }
            case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_COMMUNICATING_2 :{
                convert_to_grpc(*(_nxTimeLocalNetwork_t*)state_value, response->mutable_state_value()->mutable_time_communicating2());
                break;
            } 
            case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_START_2 :{
                convert_to_grpc(*(_nxTimeLocalNetwork_t*)state_value, response->mutable_state_value()->mutable_time_start2());
                break;
            }
        }
            response->set_fault(fault);
        }
        return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
        return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiXnetService::ReadStateTimeTrigger(::grpc::ServerContext* context, const ReadStateTimeTriggerRequest* request, ReadStateTimeTriggerResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_ref_grpc_session = request->session_ref();
        nxSessionRef_t session_ref = session_repository_->access_session(session_ref_grpc_session.id(), session_ref_grpc_session.name());
        f64 timeout;
        switch (request->timeout_enum_case()) {
            case nixnet_grpc::ReadStateTimeTriggerRequest::TimeoutEnumCase::kTimeout: {
                timeout = static_cast<f64>(request->timeout());
                break;
            }
            case nixnet_grpc::ReadStateTimeTriggerRequest::TimeoutEnumCase::kTimeoutRaw: {
                timeout = static_cast<f64>(request->timeout_raw());
                break;
            }
            case nixnet_grpc::ReadStateTimeTriggerRequest::TimeoutEnumCase::TIMEOUT_ENUM_NOT_SET: {
                return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for timeout was not specified or out of range");
                break;
            }
        }

        u32 state_size = request->state_size();
        TimeLocalNetwork* state_value;
        auto status = library_->ReadStateTimeTrigger(session_ref, timeout, state_size, state_value);
        response->set_status(status);
        if (status == 0) {
            convert_to_grpc(*state_value, response->mutable_state_value());
        }
        return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
        return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
}
}  // namespace nixnet_grpc

namespace nidevice_grpc {
namespace converters {
template <>
void convert_to_grpc(const _nxFlexRayStats_t& input, nixnet_grpc::FlexRayStats *output) 
{
  output->set_numsyntaxerrorcha(input.NumSyntaxErrorChA);
  output->set_numsyntaxerrorchb(input.NumSyntaxErrorChB);
  output->set_numcontenterrorcha(input.NumContentErrorChA);
  output->set_numcontenterrorchb(input.NumContentErrorChB);
  output->set_numslotboundaryviolationcha(input.NumSlotBoundaryViolationChA);
  output->set_numslotboundaryviolationchb(input.NumSlotBoundaryViolationChB);
}

template <>
void convert_to_grpc(const _nxJ1939CommState_t& input, nixnet_grpc::J1939CommState *output) 
{
    output->set_pgn(input.PGN);
    output->set_sourceaddress(input.SourceAddress);
    output->set_destinationaddress(input.DestinationAddress);
    output->set_transmiterror(input.TransmitError);
    output->set_receiveerror(input.ReceiveError);
    output->set_reserved1(input.Reserved1);
    output->set_reserved2(input.Reserved2);
}

template <>
void convert_to_grpc(const _nxTimeLocalNetwork_t& input, nixnet_grpc::TimeLocalNetwork *output) 
{
    output->set_localtime(input.LocalTime);
    output->set_networktime(input.NetworkTime);
    output->set_flags(input.Flags);
}
} // converters
} // nidevice_grpc