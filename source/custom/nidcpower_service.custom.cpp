#include <nidcpower/nidcpower_service.h>

#include <stdexcept>

namespace nidcpower_grpc {

class DriverErrorException : public std::runtime_error{
  private:
    int status_ = 0;

  public:
    DriverErrorException(int status) : std::runtime_error(""), status_(status) { }
    int status() const
    {
      return status_;
    }
};

static void CheckStatus(int status)
{
  if (status != 0) {
    throw DriverErrorException(status);
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiDCPowerService::MeasureMultiple(::grpc::ServerContext* context, const MeasureMultipleRequest* request, MeasureMultipleResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString channel_name = request->channel_name().c_str();

      ViUInt32 number_of_channels;
      CheckStatus(library_->ParseChannelCount(vi, channel_name, &number_of_channels));
      response->mutable_voltage_measurements()->Resize(number_of_channels, 0.0);
      ViReal64* voltage_measurements = response->mutable_voltage_measurements()->mutable_data();
      response->mutable_current_measurements()->Resize(number_of_channels, 0.0);
      ViReal64* current_measurements = response->mutable_current_measurements()->mutable_data();

      auto status = library_->MeasureMultiple(vi, channel_name, voltage_measurements, current_measurements);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
    catch (const DriverErrorException& ex) {
      response->set_status(ex.status());
      return ::grpc::Status::OK;
    }
  }

}  // namespace nidcpower_grpc
