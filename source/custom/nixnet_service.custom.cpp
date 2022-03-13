#include <nixnet/nixnet_service.h>
#include <nixnet.pb.h>
#include <server/converters.h>
#include "custom/nixnet_converters.h"

namespace nixnet_grpc {
using nidevice_grpc::converters::convert_to_grpc;

void GetCanComm(const u32& input, nixnet_grpc::CanComm *output)
{
    output->set_comm_state(nxCANComm_Get_CommState(input));
    output->set_transceiver_error(nxCANComm_Get_TcvrErr(input));
    output->set_sleep(nxCANComm_Get_Sleep(input));
    output->set_last_error(nxCANComm_Get_LastErr(input));
    output->set_transmit_error_counter(nxCANComm_Get_TxErrCount(input));
    output->set_receive_error_counter(nxCANComm_Get_RxErrCount(input));
}

void GetFlexRayComm(const u32& input, nixnet_grpc::FlexRayComm *output)
{
    output->set_poc_state(nxFlexRayComm_Get_POCState(input));
    output->set_clock_correction_failed(nxFlexRayComm_Get_ClockCorrFailed(input));
    output->set_passive_to_active_count(nxFlexRayComm_Get_PassiveToActiveCount(input));
    output->set_channel_a_sleep(nxFlexRayComm_Get_ChannelASleep(input));
    output->set_channel_b_sleep(nxFlexRayComm_Get_ChannelBSleep(input));
}

void GetLinComm(const u32* input, nixnet_grpc::LinComm *output)
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

        u32 state_size = request->state_size();
        u64 time_stamp_100ns;
        u32 comm_state;
        CanComm can_comm;
        FlexRayComm flex_ray_comm;
        LinComm lin_comm;
        FlexRayStats flex_ray_stats;
        J1939CommState J1939_comm_state;
        TimeLocalNetwork time_local_network;
        void* raw_value;
        void* state_value;

        switch(state_id){
            case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_CURRENT : 
            case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_COMMUNICATING : 
            case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_START :{
                state_value, raw_value = &time_stamp_100ns;
                break;
            }
            case nixnet_grpc::ReadState::READ_STATE_STATE_CAN_COMM :{
                state_value, raw_value = &can_comm;
                break;
            }
            case nixnet_grpc::ReadState::READ_STATE_STATE_FLEX_RAY_COMM :{
                state_value, raw_value = &flex_ray_comm;
                break;
            }
            case nixnet_grpc::ReadState::READ_STATE_STATE_FLEX_RAY_STATS :{
                state_value, raw_value = &flex_ray_stats;
                break;
            }
            case nixnet_grpc::ReadState::READ_STATE_STATE_LIN_COMM :{
                state_value, raw_value = &lin_comm;
            }
            case nixnet_grpc::ReadState::READ_STATE_STATE_SESSION_INFO :{
                state_value, raw_value = &comm_state;
                break;
            }
            case nixnet_grpc::ReadState::READ_STATE_STATE_J1939_COMM :{
                state_value, raw_value = &J1939_comm_state;
                break;
            }
            case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_CURRENT_2 : 
            case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_COMMUNICATING_2 : 
            case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_START_2 :{
                state_value, raw_value = &time_local_network;
                break;
            }
            default:{
                return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for state_id was not specified or out of range");
                break;
            }
        }
        nxStatus_t fault {};
        auto status = library_->ReadState(session_ref, state_id, state_size, state_value, &fault);
        response->set_status(status);
        if (status == 0) {
            switch(state_id){
            case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_CURRENT :{
                response->mutable_state_value()->set_time_current(time_stamp_100ns);
                break;
            } 
            case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_COMMUNICATING :{
                response->mutable_state_value()->set_time_communicating(time_stamp_100ns);
                break;
            } 
            case nixnet_grpc::ReadState::READ_STATE_STATE_TIME_START :{
                response->mutable_state_value()->set_time_start(time_stamp_100ns);
                break;
            }
            case nixnet_grpc::ReadState::READ_STATE_STATE_CAN_COMM :{
                GetCanComm(*(u32*)state_value , response->mutable_state_value()->mutable_can_comm());
                break;
            }
            case nixnet_grpc::ReadState::READ_STATE_STATE_FLEX_RAY_COMM :{
                GetFlexRayComm(*(u32*)state_value , response->mutable_state_value()->mutable_flex_ray_comm());
                break;
            }
            case nixnet_grpc::ReadState::READ_STATE_STATE_LIN_COMM :{
                GetLinComm((u32*)state_value, response->mutable_state_value()->mutable_lin_comm());
                break;
            }
            case nixnet_grpc::ReadState::READ_STATE_STATE_SESSION_INFO :{
                response->mutable_state_value()->set_session_info(comm_state);
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