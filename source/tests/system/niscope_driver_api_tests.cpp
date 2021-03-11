#include <gtest/gtest.h>

#include "niscope/niscope_library.h"
#include "niscope/niscope_service.h"

namespace ni {
namespace tests {
namespace system {

namespace scope = grpc::niscope;

const int kScopeDriverApiSuccess = 0;

class NiScopeDriverApiTest : public ::testing::Test {
 protected:
  NiScopeDriverApiTest()
  {
    ::grpc::ServerBuilder builder;
    session_repository_ = std::make_unique<grpc::nidevice::SessionRepository>();
    niscope_library_ = std::make_unique<scope::NiScopeLibrary>();
    niscope_service_ = std::make_unique<scope::NiScopeService>(niscope_library_.get(), session_repository_.get());
    builder.RegisterService(niscope_service_.get());

    server_ = builder.BuildAndStart();
    ResetStub();
  }

  virtual ~NiScopeDriverApiTest() {}

  void SetUp() override
  {
    initialize_driver_session();
  }

  void TearDown() override
  {
    close_driver_session();
  }

  void ResetStub()
  {
    channel_ = server_->InProcessChannel(::grpc::ChannelArguments());
    niscope_stub_ = scope::NiScope::NewStub(channel_);
  }

  std::unique_ptr<scope::NiScope::Stub>& GetStub()
  {
    return niscope_stub_;
  }

  int GetSessionId()
  {
    return driver_session_->id();
  }

  void initialize_driver_session()
  {
    ::grpc::ClientContext context;
    scope::InitWithOptionsRequest request;
    request.set_resource_name("FakeDevice");
    request.set_option_string("Simulate=1, DriverSetup=Model:5164; BoardType:PXIe");
    request.set_session_name("");
    request.set_reset_device(false);
    request.set_id_query(false);
    scope::InitWithOptionsResponse response;

    ::grpc::Status status = GetStub()->InitWithOptions(&context, request, &response);
    driver_session_ = std::make_unique<grpc::nidevice::Session>(response.vi());

    ASSERT_TRUE(status.ok());
    ASSERT_EQ(kScopeDriverApiSuccess, response.status());
  }

  void close_driver_session()
  {
    ::grpc::ClientContext context;
    scope::CloseRequest request;
    request.mutable_vi()->set_id(driver_session_->id());
    scope::CloseResponse response;

    ::grpc::Status status = GetStub()->Close(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kScopeDriverApiSuccess, response.status());
  }

  int get_actual_num_wfms(const char* channel_list)
  {
    ::grpc::ClientContext context;
    scope::ActualNumWfmsRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_list(channel_list);
    scope::ActualNumWfmsResponse response;
    auto status = GetStub()->ActualNumWfms(&context, request, &response);
    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kScopeDriverApiSuccess, response.status());
    EXPECT_EQ(1, response.num_wfms());
    return response.num_wfms();
  }

  int get_actual_measurement_waveform_size(grpc::niscope::ArrayMeasurement array_measurement)
  {
    ::grpc::ClientContext context;
    scope::ActualMeasWfmSizeRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_array_meas_function(array_measurement);
    scope::ActualMeasWfmSizeResponse response;
    auto status = GetStub()->ActualMeasWfmSize(&context, request, &response);
    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kScopeDriverApiSuccess, response.status());
    return response.meas_waveform_size();
  }

  void initiate_acquisition()
  {
    ::grpc::ClientContext context;
    scope::InitiateAcquisitionRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    scope::InitiateAcquisitionResponse response;
    auto status = GetStub()->InitiateAcquisition(&context, request, &response);
    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kScopeDriverApiSuccess, response.status());
  }

  void check_error_message(int error_status)
  {
    ::grpc::ClientContext context;
    scope::GetErrorMessageRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_error_code(error_status);
    scope::GetErrorMessageResponse response;

    ::grpc::Status status = GetStub()->GetErrorMessage(&context, request, &response);
    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kScopeDriverApiSuccess, response.status());
    EXPECT_STREQ("", response.error_message().c_str());
  }

  void auto_setup()
  {
    ::grpc::ClientContext context;
    scope::AutoSetupRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    scope::AutoSetupResponse response;

    ::grpc::Status status = GetStub()->AutoSetup(&context, request, &response);
    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kScopeDriverApiSuccess, response.status());
  }

 private:
  std::shared_ptr<::grpc::Channel> channel_;
  std::unique_ptr<::grpc::nidevice::Session> driver_session_;
  std::unique_ptr<scope::NiScope::Stub> niscope_stub_;
  std::unique_ptr<grpc::nidevice::SessionRepository> session_repository_;
  std::unique_ptr<scope::NiScopeLibrary> niscope_library_;
  std::unique_ptr<scope::NiScopeService> niscope_service_;
  std::unique_ptr<::grpc::Server> server_;
};

TEST_F(NiScopeDriverApiTest, NiScopeSelfTest_SendRequest_SelfTestCompletesSuccessfully)
{
  ::grpc::ClientContext context;
  scope::SelfTestRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  scope::SelfTestResponse response;

  ::grpc::Status status = GetStub()->SelfTest(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kScopeDriverApiSuccess, response.status());
  EXPECT_EQ(0, response.self_test_result());
  EXPECT_LT(0, strlen(response.self_test_message().c_str()));
}

TEST_F(NiScopeDriverApiTest, NiScopeReset_SendRequest_ResetCompletesSuccessfully)
{
  ::grpc::ClientContext context;
  scope::ResetRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  scope::ResetResponse response;

  ::grpc::Status status = GetStub()->Reset(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kScopeDriverApiSuccess, response.status());
}

TEST_F(NiScopeDriverApiTest, NiScopeRead_SendRequest_ReadCompletesWithCorrectSizes)
{
  const ViInt32 expected_num_samples = 100000;
  const char* channel_list = "0";
  const ViInt32 expected_num_waveforms = get_actual_num_wfms(channel_list);
  ::grpc::ClientContext context;
  scope::ReadRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_list(channel_list);
  request.set_timeout(10000);
  request.set_num_samples(expected_num_samples);
  scope::ReadResponse response;

  ::grpc::Status status = GetStub()->Read(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kScopeDriverApiSuccess, response.status());
  check_error_message(response.status());
  EXPECT_EQ(expected_num_samples * expected_num_waveforms, response.waveform_size());
  EXPECT_EQ(expected_num_waveforms, response.wfm_info_size());
}

TEST_F(NiScopeDriverApiTest, NiScopeFetchArrayMeasurement_SendRequest_FetchCompletesWithCorrectSizes)
{
  auto_setup();
  initiate_acquisition();
  const ViInt32 expected_num_samples = 100000;
  const char* channel_list = "0";
  const ViInt32 expected_num_waveforms = get_actual_num_wfms(channel_list);
  const grpc::niscope::ArrayMeasurement measurement_func = grpc::niscope::ArrayMeasurement::ARRAY_MEASUREMENT_NISCOPE_VAL_INVERSE;
  const ViInt32 expected_waveform_size = get_actual_measurement_waveform_size(measurement_func);
  ::grpc::ClientContext context;
  scope::FetchArrayMeasurementRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_list(channel_list);
  request.set_timeout(10000);
  request.set_array_meas_function(measurement_func);
  scope::FetchArrayMeasurementResponse response;

  ::grpc::Status status = GetStub()->FetchArrayMeasurement(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kScopeDriverApiSuccess, response.status());
  check_error_message(response.status());
  EXPECT_EQ(expected_num_waveforms * expected_waveform_size, response.meas_wfm_size());
  EXPECT_EQ(expected_waveform_size, response.wfm_info_size());
}

TEST_F(NiScopeDriverApiTest, NiScopeFetchBinary16_SendRequest_FetchCompletesWithCorrectSizes)
{
  auto_setup();
  initiate_acquisition();
  const ViInt32 expected_num_samples = 100000;
  const char* channel_list = "0";
  const ViInt32 expected_num_waveforms = get_actual_num_wfms(channel_list);
  ::grpc::ClientContext context;
  scope::FetchBinary16Request request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_list(channel_list);
  request.set_timeout(10000);
  request.set_num_samples(expected_num_samples);
  scope::FetchBinary16Response response;

  ::grpc::Status status = GetStub()->FetchBinary16(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kScopeDriverApiSuccess, response.status());
  check_error_message(response.status());
  EXPECT_EQ(expected_num_waveforms * expected_num_samples, response.waveform_size());
  EXPECT_EQ(expected_num_waveforms, response.wfm_info_size());
}

TEST_F(NiScopeDriverApiTest, NiScopeFetchBinary8_SendRequest_FetchCompletesWithCorrectSizes)
{
  auto_setup();
  initiate_acquisition();
  const ViInt32 expected_num_samples = 100000;
  const char* channel_list = "0";
  const ViInt32 expected_num_waveforms = get_actual_num_wfms(channel_list);
  ::grpc::ClientContext context;
  scope::FetchBinary8Request request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_list(channel_list);
  request.set_timeout(10000);
  request.set_num_samples(expected_num_samples);
  scope::FetchBinary8Response response;

  ::grpc::Status status = GetStub()->FetchBinary8(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kScopeDriverApiSuccess, response.status());
  check_error_message(response.status());
  EXPECT_EQ(expected_num_waveforms * expected_num_samples, response.waveform().size());
  EXPECT_EQ(expected_num_waveforms, response.wfm_info_size());
}

}  // namespace system
}  // namespace tests
}  // namespace ni