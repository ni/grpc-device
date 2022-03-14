#include <nixnet/nixnet_service.h>
#include <nixnet.pb.h>
#include <server/converters.h>
#include "custom/nixnet_converters.h"

namespace nixnet_grpc {
using nidevice_grpc::converters::convert_to_grpc;

void SetCanComm(const u32& input, nixnet_grpc::CanComm *output)
{
    output->set_comm_state(nxCANComm_Get_CommState(input));
    output->set_transceiver_error(nxCANComm_Get_TcvrErr(input));
    output->set_sleep(nxCANComm_Get_Sleep(input));
    output->set_last_error(nxCANComm_Get_LastErr(input));
    output->set_transmit_error_counter(nxCANComm_Get_TxErrCount(input));
    output->set_receive_error_counter(nxCANComm_Get_RxErrCount(input));
}

void SetFlexRayComm(const u32& input, nixnet_grpc::FlexRayComm *output)
{
    output->set_poc_state(nxFlexRayComm_Get_POCState(input));
    output->set_clock_correction_failed(nxFlexRayComm_Get_ClockCorrFailed(input));
    output->set_passive_to_active_count(nxFlexRayComm_Get_PassiveToActiveCount(input));
    output->set_channel_a_sleep(nxFlexRayComm_Get_ChannelASleep(input));
    output->set_channel_b_sleep(nxFlexRayComm_Get_ChannelBSleep(input));
}

void SetLinComm(const u32* input, nixnet_grpc::LinComm *output)
{
    output->set_sleep(nxLINComm_Get_Sleep(input[0]));
    output->set_comm_state(nxLINComm_Get_CommState(input[0]));
    output->set_last_error(nxLINComm_Get_LastErrCode(input[0]));
    output->set_last_error_received(nxLINComm_Get_LastErrReceived(input[0]));
    output->set_last_error_expected(nxLINComm_Get_LastErrExpected(input[0]));
    output->set_last_error_id(nxLINComm_Get_LastErrID(input[0]));
    output->set_transceiver_ready(nxLINComm_Get_TcvrRdy(input[0]));
    output->set_schedule_index(nxLINComm_Get2_ScheduleIndex(input[1]));
}

u32 GetStateSize(u32 state_id)
{
    u32 state_size;
    switch(state_id){
        case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_CURRENT : 
        case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_COMMUNICATING : 
        case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_START :{
            state_size = sizeof(nxTimestamp100ns_t);
            break;
        }
        case nixnet_grpc::ReadState::READ_STATE_STATE_CAN_COMM :
        case nixnet_grpc::ReadState::READ_STATE_STATE_FLEX_RAY_COMM :
        case nixnet_grpc::ReadState::READ_STATE_STATE_SESSION_INFO :{
            state_size = sizeof(u32);
            break;
        }
        case nixnet_grpc::ReadState::READ_STATE_STATE_FLEX_RAY_STATS :{
            state_size = sizeof(nxFlexRayStats_t);
            break;
        }
        case nixnet_grpc::ReadState::READ_STATE_STATE_LIN_COMM :{
            // The StateValue for nxState_LinComm should point to a u32 array with 2 elements.
            state_size = sizeof(u32)*2;
            break;
        }
        case nixnet_grpc::ReadState::READ_STATE_STATE_J1939_COMM :{
            state_size = sizeof(nxJ1939CommState_t);
            break;
        }
        case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_CURRENT_2 : 
        case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_COMMUNICATING_2 : 
        case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_START_2 :{
            state_size = sizeof(nxTimeLocalNetwork_t);
            break;
        }
        default:{
            return ::grpc::INVALID_ARGUMENT;
            break;
        }
    }
        return state_size;
}

// ReadState API has an output parameter of type void * called StateValue. Based on the value of StateID, 
// StateValue can point to u32, nxTimestamp100ns_t,  _nxFlexRayStats_t etc, which are of different sizes.
// Based on the StateID, we are setting the size of StateValue and after calling the ReadState API, the 
// response is set appropriately.
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

        u32 state_size = GetStateSize(state_id);
        // Since GetStateSize returns only u32, in case of error, we are returning a meaningful message
        if (state_size == ::grpc::INVALID_ARGUMENT)
        {
            return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for state_id was not specified or out of range");
        }
        response->mutable_state_value()->mutable_raw_value()->resize(state_size,0);
        nxStatus_t fault {};

        auto status = library_->ReadState(session_ref, state_id, state_size, response->mutable_state_value()->mutable_raw_value()->data(), &fault);

        response->set_status(status);
        if (status == 0) {
            void* state_value_raw = (void*)response->state_value().raw_value().data();
            switch(state_id){
                case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_CURRENT :{
                    response->mutable_state_value()->set_time_current(*(nxTimestamp100ns_t*)state_value_raw);
                    break;
                } 
                case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_COMMUNICATING :{
                    response->mutable_state_value()->set_time_communicating(*(nxTimestamp100ns_t*)state_value_raw);
                    break;
                } 
                case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_START :{
                    response->mutable_state_value()->set_time_start(*(nxTimestamp100ns_t*)state_value_raw);
                    break;
                }
                case nixnet_grpc::ReadState::READ_STATE_STATE_CAN_COMM :{
                    SetCanComm(*(u32*)state_value_raw , response->mutable_state_value()->mutable_can_comm());
                    break;
                }
                case nixnet_grpc::ReadState::READ_STATE_STATE_FLEX_RAY_COMM :{
                    SetFlexRayComm(*(u32*)state_value_raw , response->mutable_state_value()->mutable_flex_ray_comm());
                    break;
                }
                case nixnet_grpc::ReadState::READ_STATE_STATE_LIN_COMM :{
                    SetLinComm((u32*)state_value_raw, response->mutable_state_value()->mutable_lin_comm());
                    break;
                }
                case nixnet_grpc::ReadState::READ_STATE_STATE_SESSION_INFO :{
                    response->mutable_state_value()->set_session_info(*(u32*)state_value_raw);
                    break;
                }
                case nixnet_grpc::ReadState::READ_STATE_STATE_FLEX_RAY_STATS :{
                    convert_to_grpc(*(_nxFlexRayStats_t*)state_value_raw, response->mutable_state_value()->mutable_flex_ray_stat());
                    break;
                }
                case nixnet_grpc::ReadState::READ_STATE_STATE_J1939_COMM :{
                    convert_to_grpc(*(_nxJ1939CommState_t*)state_value_raw, response->mutable_state_value()->mutable_comm_stat());
                    break;
                }
                case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_CURRENT_2 :{
                    convert_to_grpc(*(_nxTimeLocalNetwork_t*)state_value_raw, response->mutable_state_value()->mutable_time_current2());
                    break;
                }
                case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_COMMUNICATING_2 :{
                    convert_to_grpc(*(_nxTimeLocalNetwork_t*)state_value_raw, response->mutable_state_value()->mutable_time_communicating2());
                    break;
                } 
                case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_START_2 :{
                    convert_to_grpc(*(_nxTimeLocalNetwork_t*)state_value_raw, response->mutable_state_value()->mutable_time_start2());
                    break;
                }
                default:{
                    return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for state_id was not specified or out of range");
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
::grpc::Status NiXnetService::WriteState(::grpc::ServerContext* context, const WriteStateRequest* request, WriteStateResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_ref_grpc_session = request->session_ref();
        nxSessionRef_t session_ref = session_repository_->access_session(session_ref_grpc_session.id(), session_ref_grpc_session.name());
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
        switch(request->state_value().value_case()){
            case nixnet_grpc::WriteStateValue::ValueCase::kLinScheduleChange : {
                if(state_id != nixnet_grpc::WriteState::WRITE_STATE_STATE_LIN_SCHEDULE_CHANGE) {
                    return ::grpc::Status(::grpc::INVALID_ARGUMENT, "StateValue for specified StateID is not set");
                }
                state_value = request->state_value().lin_schedule_change();
                break;
            }
            case nixnet_grpc::WriteStateValue::ValueCase::kFlexRaySymbol : {
                if(state_id != nixnet_grpc::WriteState::WRITE_STATE_STATE_FLEX_RAY_SYMBOL) {
                    return ::grpc::Status(::grpc::INVALID_ARGUMENT, "StateValue for specified StateID is not set");
                }
                state_value = request->state_value().flex_ray_symbol();
                break;
            }
            case nixnet_grpc::WriteStateValue::ValueCase::kLinDiagnosticScheduleChange : {
                if(state_id != nixnet_grpc::WriteState::WRITE_STATE_STATE_LIN_DIAGNOSTIC_SCHEDULE_CHANGE) {
                    return ::grpc::Status(::grpc::INVALID_ARGUMENT, "StateValue for specified StateID is not set");
                }
                state_value = request->state_value().lin_diagnostic_schedule_change();
                break;
            }
            case nixnet_grpc::WriteStateValue::ValueCase::kEthernetSleep : {
                if(state_id != nixnet_grpc::WriteState::WRITE_STATE_STATE_ETHERNET_SLEEP) {
                    return ::grpc::Status(::grpc::INVALID_ARGUMENT, "StateValue for specified StateID is not set");
                }
                state_value = request->state_value().ethernet_sleep();
                break;
            }
            case nixnet_grpc::WriteStateValue::ValueCase::kEthernetWake : {
                if(state_id != nixnet_grpc::WriteState::WRITE_STATE_STATE_ETHERNET_WAKE) {
                    return ::grpc::Status(::grpc::INVALID_ARGUMENT, "StateValue for specified StateID is not set");
                }
                state_value = request->state_value().ethernet_wake();
                break;
            }
            default:{
                return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for state_id was not specified or out of range");
                break;
            }
        }
        auto status = library_->WriteState(session_ref, state_id, state_size, &state_value);
        response->set_status(status);
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
    output->set_num_syntax_error_ch_a(input.NumSyntaxErrorChA);
    output->set_num_syntax_error_ch_b(input.NumSyntaxErrorChB);
    output->set_num_content_error_ch_a(input.NumContentErrorChA);
    output->set_num_content_error_ch_b(input.NumContentErrorChB);
    output->set_num_slot_boundary_violation_ch_a(input.NumSlotBoundaryViolationChA);
    output->set_num_slot_boundary_violation_ch_b(input.NumSlotBoundaryViolationChB);
}

template <>
void convert_to_grpc(const _nxJ1939CommState_t& input, nixnet_grpc::J1939CommState *output) 
{
    output->set_pgn(input.PGN);
    output->set_source_address(input.SourceAddress);
    output->set_destination_address(input.DestinationAddress);
    output->set_transmit_error(input.TransmitError);
    output->set_receive_error(input.ReceiveError);
}

} // converters
} // nidevice_grpc