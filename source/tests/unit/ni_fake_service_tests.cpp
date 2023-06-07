#include <grpcpp/impl/grpc_library.h>
#include <gtest/gtest.h>
#include <nifake/nifake_mock_library.h>
#include <nifake/nifake_service.h>
#include <nifake_extension/nifake_extension_mock_library.h>
#include <nifake_extension/nifake_extension_service.h>
#include <server/session_repository.h>

#include <array>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

using namespace ::nlohmann;

// fixes seg faults caused by https://github.com/grpc/grpc/issues/14633
static grpc::internal::GrpcLibraryInitializer g_gli_initializer;

namespace nifake_grpc {
bool operator==(const nifake_grpc::FakeCustomStruct& first, const nifake_grpc::FakeCustomStruct& second)
{
  return first.struct_int() == second.struct_int() && first.struct_double() == second.struct_double();
}
bool operator==(const nifake_grpc::CustomStructTypedef& first, const nifake_grpc::CustomStructTypedef& second)
{
  return first.struct_int() == second.struct_int() && first.struct_double() == second.struct_double();
}
bool operator==(const nifake_grpc::CustomStructNestedTypedef& first, const nifake_grpc::CustomStructNestedTypedef& second)
{
  return first.struct_custom_struct() == second.struct_custom_struct() && first.struct_custom_struct_typedef() == second.struct_custom_struct_typedef();
}
}  // namespace nifake_grpc
// Adding operator for matching Custom Structs
bool operator==(const CustomStruct& first, const CustomStruct& second)
{
  return first.structInt == second.structInt && first.structDouble == second.structDouble;
}

bool operator==(const nifake_grpc::FakeCustomStruct& first, const CustomStruct& second)
{
  return first.struct_int() == second.structInt && first.struct_double() == second.structDouble;
}

bool operator==(const CustomStruct& first, const nifake_grpc::FakeCustomStruct& second)
{
  return second == first;
}

// Adding operator for matching CustomStructTypedef
bool operator==(const CustomStructTypedef_struct& first, const CustomStructTypedef_struct& second)
{
  return first.structDouble == second.structDouble && first.structInt == second.structInt;
}

bool operator==(const nifake_grpc::CustomStructTypedef& first, const CustomStructTypedef_struct& second)
{
  return first.struct_double() == second.structDouble && first.struct_int() == second.structInt;
}

bool operator==(const CustomStructTypedef_struct& first, const nifake_grpc::CustomStructTypedef& second)
{
  return second == first;
}

// Adding operator for matching CustomStructNestedTypedef
bool operator==(const CustomStructNestedTypedef_struct& first, const CustomStructNestedTypedef_struct& second)
{
  return first.structCustomStruct == second.structCustomStruct && first.structCustomStructTypedef == second.structCustomStructTypedef;
}

bool operator==(const nifake_grpc::CustomStructNestedTypedef& first, const CustomStructNestedTypedef_struct& second)
{
  return first.struct_custom_struct() == second.structCustomStruct && first.struct_custom_struct_typedef() == second.structCustomStructTypedef;
}

bool operator==(const CustomStructNestedTypedef_struct& first, const nifake_grpc::CustomStructNestedTypedef& second)
{
  return second == first;
}

using ::testing::StrEq;

namespace ni {
namespace tests {
namespace unit {

using namespace nifake_grpc;
namespace pb = google::protobuf;

using ::testing::_;
using ::testing::AllOf;
using ::testing::Args;
using ::testing::DoAll;
using ::testing::ElementsAre;
using ::testing::ElementsAreArray;
using ::testing::Eq;
using ::testing::HasSubstr;
using ::testing::IsEmpty;
using ::testing::Pointee;
using ::testing::Return;
using ::testing::SetArgPointee;
using ::testing::SetArrayArgument;
using ::testing::Throw;

using FakeResourceRepository = nidevice_grpc::SessionResourceRepository<ViSession>;

const std::uint32_t kTestViSession = 12345678;
const std::uint32_t kDriverSuccess = 0;
const std::uint32_t kDriverFailure = -1;
const std::uint32_t kDriverWarning = 123456;
const char* kTestChannelName = "channel";

std::string create_session(
    const std::shared_ptr<NiFakeMockLibrary>& library,
    nifake_grpc::NiFakeService& service,
    const std::string& session_name)
{
  const char* resource_name = "Dev0";
  const char* option_string = "Simulate = 1";
  bool id_query = false, reset_device = true;
  EXPECT_CALL(*library, InitWithOptions(Pointee(*resource_name), id_query, reset_device, Pointee(*option_string), _))
      .WillOnce(DoAll(SetArgPointee<4>(std::atoi(session_name.c_str())), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::InitWithOptionsRequest request;
  request.set_resource_name(resource_name);
  request.set_id_query(id_query);
  request.set_reset_device(reset_device);
  request.set_option_string(option_string);
  request.set_session_name(session_name.c_str());
  nifake_grpc::InitWithOptionsResponse response;
  ::grpc::Status status = service.InitWithOptions(&context, &request, &response);

  return response.vi().name();
}

std::string create_session(
    const std::shared_ptr<NiFakeMockLibrary>& library,
    nifake_grpc::NiFakeService& service,
    std::uint32_t session_name)
{
  return create_session(library, service, std::to_string(session_name));
}

// Init and Close function tests
TEST(NiFakeServiceTests, NiFakeService_InitWithOptionsSucceeds_CreatesAndStoresSession)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  const char* resource_name = "Dev0";
  const char* option_string = "Simulate = 1";
  bool id_query = false, reset_device = true;
  const char* session_name = "sessionName";
  EXPECT_CALL(*library, InitWithOptions(Pointee(*resource_name), id_query, reset_device, Pointee(*option_string), _))
      .WillOnce(DoAll(SetArgPointee<4>(kTestViSession), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::InitWithOptionsRequest request;
  request.set_resource_name(resource_name);
  request.set_id_query(id_query);
  request.set_reset_device(reset_device);
  request.set_option_string(option_string);
  request.set_session_name(session_name);
  nifake_grpc::InitWithOptionsResponse response;
  ::grpc::Status status = service.InitWithOptions(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  nidevice_grpc::Session session = response.vi();
  EXPECT_NE("", session_repository->access_session(session.name()));
  EXPECT_NE("", session_repository->access_session(session_name));
  EXPECT_TRUE(response.new_session_initialized());
}

TEST(NiFakeServiceTests, NiFakeService_InitWithOptionsWithAttachBehavior_DoesNotCallIntoDriverAndReturnsFailedPreconditionError)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  const char* resource_name = "Dev0";
  const char* option_string = "Simulate = 1";
  bool id_query = false, reset_device = true;
  const char* session_name = "sessionName";
  EXPECT_CALL(*library, InitWithOptions)
      .Times(0);

  ::grpc::ServerContext context;
  nifake_grpc::InitWithOptionsRequest request;
  request.set_resource_name(resource_name);
  request.set_id_query(id_query);
  request.set_reset_device(reset_device);
  request.set_option_string(option_string);
  request.set_session_name(session_name);
  request.set_initialization_behavior(nidevice_grpc::SESSION_INITIALIZATION_BEHAVIOR_ATTACH_TO_EXISTING);
  nifake_grpc::InitWithOptionsResponse response;
  ::grpc::Status status = service.InitWithOptions(&context, &request, &response);

  EXPECT_FALSE(status.ok());
  EXPECT_EQ(::grpc::StatusCode::FAILED_PRECONDITION, status.error_code());
  const char* expected_error_message = "Cannot attach to 'sessionName' because a session has not been initialized.";
  EXPECT_STREQ(expected_error_message, status.error_message().c_str());
}

TEST(NiFakeServiceTests, NiFakeService_InitWithOptionsWithInitializeBehavior_CreatesAndStoresSession)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  const char* resource_name = "Dev0";
  const char* option_string = "Simulate = 1";
  bool id_query = false, reset_device = true;
  const char* session_name = "sessionName";
  EXPECT_CALL(*library, InitWithOptions(Pointee(*resource_name), id_query, reset_device, Pointee(*option_string), _))
      .WillOnce(DoAll(SetArgPointee<4>(kTestViSession), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::InitWithOptionsRequest request;
  request.set_resource_name(resource_name);
  request.set_id_query(id_query);
  request.set_reset_device(reset_device);
  request.set_option_string(option_string);
  request.set_session_name(session_name);
  request.set_initialization_behavior(nidevice_grpc::SESSION_INITIALIZATION_BEHAVIOR_INITIALIZE_NEW);
  nifake_grpc::InitWithOptionsResponse response;
  ::grpc::Status status = service.InitWithOptions(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  nidevice_grpc::Session session = response.vi();
  EXPECT_NE("", session_repository->access_session(session.name()));
  EXPECT_NE("", session_repository->access_session(session_name));
  EXPECT_TRUE(response.new_session_initialized());
}

TEST(NiFakeServiceTests, NiFakeServiceWithSession_InitWithOptionsWithInitializeBehavior_ReturnsAlreadyExistsError)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  const char* default_session_name = "sessionName";
  auto session_name = create_session(library, service, default_session_name);
  const char* resource_name = "Dev0";
  const char* option_string = "Simulate = 1";
  bool id_query = false, reset_device = true;
  EXPECT_CALL(*library, InitWithOptions)
      .Times(0);

  ::grpc::ServerContext context;
  nifake_grpc::InitWithOptionsRequest request;
  request.set_resource_name(resource_name);
  request.set_id_query(id_query);
  request.set_reset_device(reset_device);
  request.set_option_string(option_string);
  request.set_session_name(session_name);
  request.set_initialization_behavior(nidevice_grpc::SESSION_INITIALIZATION_BEHAVIOR_INITIALIZE_NEW);
  nifake_grpc::InitWithOptionsResponse response;
  ::grpc::Status status = service.InitWithOptions(&context, &request, &response);

  EXPECT_FALSE(status.ok());
  EXPECT_EQ(::grpc::StatusCode::ALREADY_EXISTS, status.error_code());
  const char* expected_error_message = "Cannot initialize 'sessionName' when a session already exists.";
  EXPECT_STREQ(expected_error_message, status.error_message().c_str());
}

TEST(NiFakeServiceTests, NiFakeServiceWithSession_InitWithOptionsWithAttachBehavior_ReturnsAlreadyInitializedSession)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  const char* default_session_name = "sessionName";
  auto session_name = create_session(library, service, default_session_name);
  const char* resource_name = "Dev0";
  const char* option_string = "Simulate = 1";
  bool id_query = false, reset_device = true;

  EXPECT_CALL(*library, InitWithOptions)
      .Times(0);

  ::grpc::ServerContext context;
  nifake_grpc::InitWithOptionsRequest request;
  request.set_resource_name(resource_name);
  request.set_id_query(id_query);
  request.set_reset_device(reset_device);
  request.set_option_string(option_string);
  request.set_session_name(session_name);
  request.set_initialization_behavior(nidevice_grpc::SESSION_INITIALIZATION_BEHAVIOR_ATTACH_TO_EXISTING);
  nifake_grpc::InitWithOptionsResponse response;
  ::grpc::Status status = service.InitWithOptions(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  nidevice_grpc::Session session = response.vi();
  EXPECT_NE("", session_repository->access_session(session.name()));
  EXPECT_NE("", session_repository->access_session(session_name));
  EXPECT_FALSE(response.new_session_initialized());
}

TEST(NiFakeServiceTests, NiFakeService_InitWithOptionsFails_NoSessionIsStored)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  const char* message = "Exception!";
  EXPECT_CALL(*library, InitWithOptions)
      .WillOnce(DoAll(SetArgPointee<4>(kTestViSession), Throw(nidevice_grpc::LibraryLoadException(message))));

  ::grpc::ServerContext context;
  nifake_grpc::InitWithOptionsRequest request;
  nifake_grpc::InitWithOptionsResponse response;
  ::grpc::Status status = service.InitWithOptions(&context, &request, &response);

  EXPECT_EQ(::grpc::StatusCode::NOT_FOUND, status.error_code());
  EXPECT_EQ(message, status.error_message());
  nidevice_grpc::Session session = response.vi();
  EXPECT_EQ("", session_repository->access_session(session.name()));
}

TEST(NiFakeServiceTests, NiFakeService_InitWithOptionsAndResetServer_SessionIsClosed)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  const char* session_name = "sessionName";
  EXPECT_CALL(*library, InitWithOptions)
      .WillOnce(DoAll(SetArgPointee<4>(kTestViSession), Return(kDriverSuccess)));
  EXPECT_CALL(*library, Close(kTestViSession))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::InitWithOptionsRequest request;
  request.set_session_name(session_name);
  nifake_grpc::InitWithOptionsResponse response;
  ::grpc::Status init_status = service.InitWithOptions(&context, &request, &response);
  EXPECT_TRUE(init_status.ok());
  nidevice_grpc::Session session = response.vi();
  EXPECT_NE("", session_repository->access_session(session.name()));
  EXPECT_NE("", session_repository->access_session(session_name));
  bool reset_status = session_repository->reset_server();

  EXPECT_TRUE(reset_status);
  EXPECT_EQ("", session_repository->access_session(session.name()));
}

TEST(NiFakeServiceTests, NiFakeService_InitExtCalAndResetServer_SessionIsClosed)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  const char* session_name = "sessionName";
  EXPECT_CALL(*library, InitExtCal)
      .WillOnce(DoAll(SetArgPointee<2>(kTestViSession), Return(kDriverSuccess)));
  EXPECT_CALL(*library, CloseExtCal(kTestViSession, 0))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::InitExtCalRequest request;
  request.set_session_name(session_name);
  nifake_grpc::InitExtCalResponse response;
  ::grpc::Status init_status = service.InitExtCal(&context, &request, &response);
  EXPECT_TRUE(init_status.ok());
  nidevice_grpc::Session session = response.vi();
  EXPECT_NE("", session_repository->access_session(session.name()));
  EXPECT_NE("", session_repository->access_session(session_name));
  bool reset_status = session_repository->reset_server();

  EXPECT_TRUE(reset_status);
  EXPECT_EQ("", session_repository->access_session(session.name()));
  EXPECT_EQ("", session_repository->access_session(session_name));
}

TEST(NiFakeServiceTests, NiFakeService_InitWithOptionsThenClose_SessionIsClosed)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  std::string session_name = "sessionName";
  EXPECT_CALL(*library, InitWithOptions)
      .WillOnce(DoAll(SetArgPointee<4>(kTestViSession), Return(kDriverSuccess)));
  EXPECT_CALL(*library, Close(kTestViSession))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::InitWithOptionsRequest init_request;
  init_request.set_session_name(session_name);
  nifake_grpc::InitWithOptionsResponse init_response;
  ::grpc::Status init_status = service.InitWithOptions(&context, &init_request, &init_response);
  EXPECT_TRUE(init_status.ok());
  nidevice_grpc::Session session = init_response.vi();
  EXPECT_NE("", session_repository->access_session(session.name()));
  EXPECT_NE("", session_repository->access_session(session_name));
  nifake_grpc::CloseRequest close_request;
  close_request.mutable_vi()->set_name(session.name());
  nifake_grpc::CloseResponse close_response;
  ::grpc::Status close_status = service.Close(&context, &close_request, &close_response);

  EXPECT_TRUE(close_status.ok());
  EXPECT_EQ(kDriverSuccess, close_response.status());
  EXPECT_EQ("", session_repository->access_session(session.name()));
}

TEST(NiFakeServiceTests, NiFakeService_InitExtCalThenCloseExtCal_SessionIsClosed)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  std::string session_name = "sessionName";
  ViInt32 action = 1;
  EXPECT_CALL(*library, InitExtCal)
      .WillOnce(DoAll(SetArgPointee<2>(kTestViSession), Return(kDriverSuccess)));
  EXPECT_CALL(*library, CloseExtCal(kTestViSession, action))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::InitExtCalRequest init_request;
  init_request.set_session_name(session_name);
  nifake_grpc::InitExtCalResponse init_response;
  ::grpc::Status init_status = service.InitExtCal(&context, &init_request, &init_response);
  EXPECT_TRUE(init_status.ok());
  nidevice_grpc::Session session = init_response.vi();
  EXPECT_NE("", session_repository->access_session(session.name()));
  EXPECT_NE("", session_repository->access_session(session_name));
  nifake_grpc::CloseExtCalRequest close_request;
  close_request.mutable_vi()->set_name(session.name());
  close_request.set_action(action);
  nifake_grpc::CloseExtCalResponse close_response;
  ::grpc::Status close_status = service.CloseExtCal(&context, &close_request, &close_response);

  EXPECT_TRUE(close_status.ok());
  EXPECT_EQ(kDriverSuccess, close_response.status());
  EXPECT_EQ("", session_repository->access_session(session.name()));
  EXPECT_EQ("", session_repository->access_session(session_name));
}

TEST(NiFakeServiceTests, NiFakeService_InitWithVarArgsWithOneArgument_SucceedsAndCreatesAndStoresSession)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  const char* resource_name = "Dev0";
  const char* session_name = "sessionName";
  nifake_grpc::Turtle defaultTurtle = nifake_grpc::Turtle::TURTLE_LEONARDO;
  EXPECT_CALL(*library, InitWithVarArgs(Pointee(*resource_name), _, StrEq("SomeStringArg"), nifake_grpc::Turtle::TURTLE_DONATELLO, nullptr, defaultTurtle, nullptr, defaultTurtle, nullptr, defaultTurtle))
      .WillOnce(DoAll(SetArgPointee<1>(kTestViSession), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::InitWithVarArgsRequest request;
  request.set_resource_name(resource_name);
  request.set_session_name(session_name);
  auto nameAndTurtle = request.add_name_and_turtle();
  nameAndTurtle->set_string_arg("SomeStringArg");
  nameAndTurtle->set_turtle(nifake_grpc::Turtle::TURTLE_DONATELLO);
  nifake_grpc::InitWithVarArgsResponse response;
  ::grpc::Status status = service.InitWithVarArgs(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  nidevice_grpc::Session session = response.vi();
  EXPECT_NE("", session_repository->access_session(session.name()));
  EXPECT_NE("", session_repository->access_session(session_name));
}

TEST(NiFakeServiceTests, NiFakeService_InitWithVarArgsWithThreeArguments_SucceedsAndCreatesAndStoresSession)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  const char* resource_name = "Dev0";
  const char* session_name = "sessionName";
  nifake_grpc::Turtle defaultTurtle = nifake_grpc::Turtle::TURTLE_LEONARDO;
  EXPECT_CALL(*library, InitWithVarArgs(Pointee(*resource_name), _, StrEq("SomeStringArg"), nifake_grpc::Turtle::TURTLE_DONATELLO, StrEq("SomeStringArg2"), nifake_grpc::Turtle::TURTLE_MICHELANGELO, StrEq("SomeStringArg3"), nifake_grpc::Turtle::TURTLE_RAPHAEL, nullptr, defaultTurtle))
      .WillOnce(DoAll(SetArgPointee<1>(kTestViSession), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::InitWithVarArgsRequest request;
  request.set_resource_name(resource_name);
  request.set_session_name(session_name);
  auto nameAndTurtle = request.add_name_and_turtle();
  nameAndTurtle->set_string_arg("SomeStringArg");
  nameAndTurtle->set_turtle(nifake_grpc::Turtle::TURTLE_DONATELLO);
  nameAndTurtle = request.add_name_and_turtle();
  nameAndTurtle->set_string_arg("SomeStringArg2");
  nameAndTurtle->set_turtle(nifake_grpc::Turtle::TURTLE_MICHELANGELO);
  nameAndTurtle = request.add_name_and_turtle();
  nameAndTurtle->set_string_arg("SomeStringArg3");
  nameAndTurtle->set_turtle(nifake_grpc::Turtle::TURTLE_RAPHAEL);
  nifake_grpc::InitWithVarArgsResponse response;
  ::grpc::Status status = service.InitWithVarArgs(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  nidevice_grpc::Session session = response.vi();
  EXPECT_NE("", session_repository->access_session(session.name()));
  EXPECT_NE("", session_repository->access_session(session_name));
}

TEST(NiFakeServiceTests, NiFakeService_InitWithVarArgsWithNoArguments_FailsAndDoesNotStoreSession)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  const char* resource_name = "Dev0";
  const char* session_name = "sessionName";
  nifake_grpc::Turtle defaultTurtle = nifake_grpc::Turtle::TURTLE_LEONARDO;
  EXPECT_CALL(*library, InitWithVarArgs)
      .Times(0);

  ::grpc::ServerContext context;
  nifake_grpc::InitWithVarArgsRequest request;
  request.set_resource_name(resource_name);
  request.set_session_name(session_name);
  nifake_grpc::InitWithVarArgsResponse response;
  ::grpc::Status status = service.InitWithVarArgs(&context, &request, &response);

  EXPECT_EQ(grpc::StatusCode::INVALID_ARGUMENT, status.error_code());
  nidevice_grpc::Session session = response.vi();
  EXPECT_EQ("", session_repository->access_session(session.name()));
}

TEST(NiFakeServiceTests, NiFakeService_InitWithVarArgsWithFourArguments_FailsAndDoesNotStoreSession)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  const char* resource_name = "Dev0";
  const char* session_name = "sessionName";
  nifake_grpc::Turtle defaultTurtle = nifake_grpc::Turtle::TURTLE_LEONARDO;
  EXPECT_CALL(*library, InitWithVarArgs)
      .Times(0);

  ::grpc::ServerContext context;
  nifake_grpc::InitWithVarArgsRequest request;
  request.set_resource_name(resource_name);
  request.set_session_name(session_name);
  for (int i = 0; i < 4; ++i) {
    request.add_name_and_turtle();
  }
  nifake_grpc::InitWithVarArgsResponse response;
  ::grpc::Status status = service.InitWithVarArgs(&context, &request, &response);

  EXPECT_EQ(grpc::StatusCode::INVALID_ARGUMENT, status.error_code());
  nidevice_grpc::Session session = response.vi();
  EXPECT_EQ("", session_repository->access_session(session.name()));
}

// Error logic tests using GetABoolean
TEST(NiFakeServiceTests, NiFakeService_FunctionNotFound_DoesNotCallFunction)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  const char* message = "Exception!";
  EXPECT_CALL(*library, GetABoolean)
      .WillOnce(Throw(nidevice_grpc::LibraryLoadException(message)));

  ::grpc::ServerContext context;
  nifake_grpc::GetABooleanRequest request;
  request.mutable_vi()->set_name(session_name);
  nifake_grpc::GetABooleanResponse response;
  ::grpc::Status status = service.GetABoolean(&context, &request, &response);

  EXPECT_EQ(::grpc::StatusCode::NOT_FOUND, status.error_code());
  EXPECT_EQ(message, status.error_message());
}

TEST(NiFakeServiceTests, NiFakeService_FunctionCallErrors_ResponseValuesNotSet)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  bool a_boolean = true;
  EXPECT_CALL(*library, GetABoolean(kTestViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(a_boolean), Return(kDriverFailure)));

  ::grpc::ServerContext context;
  nifake_grpc::GetABooleanRequest request;
  request.mutable_vi()->set_name(session_name);
  nifake_grpc::GetABooleanResponse response;
  ::grpc::Status status = service.GetABoolean(&context, &request, &response);

  EXPECT_FALSE(status.ok());
  EXPECT_EQ(::grpc::StatusCode::UNKNOWN, status.error_code());
  EXPECT_NE(kDriverFailure, response.status());
  EXPECT_NE(a_boolean, response.a_boolean());
}

TEST(NiFakeServiceTests, NiFakeService_FunctionCallReturnsWarning_ResponseValueSet)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  bool a_boolean = true;
  EXPECT_CALL(*library, GetABoolean(kTestViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(a_boolean), Return(kDriverWarning)));

  ::grpc::ServerContext context;
  nifake_grpc::GetABooleanRequest request;
  request.mutable_vi()->set_name(session_name);
  nifake_grpc::GetABooleanResponse response;
  ::grpc::Status status = service.GetABoolean(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverWarning, response.status());
  EXPECT_EQ(a_boolean, response.a_boolean());
}

TEST(NiFakeServiceTests, NiFakeService_GetABoolean_CallsGetABoolean)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  bool a_boolean = true;
  EXPECT_CALL(*library, GetABoolean(kTestViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(a_boolean), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetABooleanRequest request;
  request.mutable_vi()->set_name(session_name);
  nifake_grpc::GetABooleanResponse response;
  ::grpc::Status status = service.GetABoolean(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(a_boolean, response.a_boolean());
}

// Simple Input and Output Type Function Tests
TEST(NiFakeServiceTests, NiFakeService_Abort_CallsAbort)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  EXPECT_CALL(*library, Abort(kTestViSession))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::AbortRequest request;
  request.mutable_vi()->set_name(session_name);
  nifake_grpc::AbortResponse response;
  ::grpc::Status status = service.Abort(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_GetANumber_CallsGetANumber)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  std::int16_t a_number = 15;
  EXPECT_CALL(*library, GetANumber(kTestViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(a_number), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetANumberRequest request;
  request.mutable_vi()->set_name(session_name);
  nifake_grpc::GetANumberResponse response;
  ::grpc::Status status = service.GetANumber(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(a_number, response.a_number());
}

TEST(NiFakeServiceTests, NiFakeService_GetArraySizeForCustomCode_CallsGetArraySizeForCustomCode)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  std::int32_t array_size = 1000;
  EXPECT_CALL(*library, GetArraySizeForCustomCode(kTestViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(array_size), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetArraySizeForCustomCodeRequest request;
  request.mutable_vi()->set_name(session_name);
  nifake_grpc::GetArraySizeForCustomCodeResponse response;
  ::grpc::Status status = service.GetArraySizeForCustomCode(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(array_size, response.size_out());
}

TEST(NiFakeServiceTests, NiFakeService_GetAttributeViBoolean_CallsGetAttributeViBoolean)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  nifake_grpc::NiFakeAttribute attribute_id = nifake_grpc::NIFAKE_ATTRIBUTE_READ_WRITE_BOOL;
  bool attribute_value = true;
  EXPECT_CALL(*library, GetAttributeViBoolean(kTestViSession, Pointee(*kTestChannelName), attribute_id, _))
      .WillOnce(DoAll(SetArgPointee<3>(attribute_value), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAttributeViBooleanRequest request;
  request.mutable_vi()->set_name(session_name);
  request.set_channel_name(kTestChannelName);
  request.set_attribute_id(attribute_id);
  nifake_grpc::GetAttributeViBooleanResponse response;
  ::grpc::Status status = service.GetAttributeViBoolean(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(attribute_value, response.attribute_value());
}

TEST(NiFakeServiceTests, NiFakeService_GetAttributeViInt32_CallsGetAttributeViInt32)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  nifake_grpc::NiFakeAttribute attribute_id = nifake_grpc::NIFAKE_ATTRIBUTE_READ_WRITE_INTEGER;
  std::int32_t attribute_value = 12345;
  EXPECT_CALL(*library, GetAttributeViInt32(kTestViSession, Pointee(*kTestChannelName), attribute_id, _))
      .WillOnce(DoAll(SetArgPointee<3>(attribute_value), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAttributeViInt32Request request;
  request.mutable_vi()->set_name(session_name);
  request.set_channel_name(kTestChannelName);
  request.set_attribute_id(attribute_id);
  nifake_grpc::GetAttributeViInt32Response response;
  ::grpc::Status status = service.GetAttributeViInt32(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(attribute_value, response.attribute_value());
}

TEST(NiFakeServiceTests, NiFakeService_GetAttributeViInt64_CallsGetAttributeViInt64)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  nifake_grpc::NiFakeAttribute attribute_id = nifake_grpc::NIFAKE_ATTRIBUTE_READ_WRITE_INT64;
  std::int64_t attribute_value = -12345;
  EXPECT_CALL(*library, GetAttributeViInt64(kTestViSession, Pointee(*kTestChannelName), attribute_id, _))
      .WillOnce(DoAll(SetArgPointee<3>(attribute_value), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAttributeViInt64Request request;
  request.mutable_vi()->set_name(session_name);
  request.set_channel_name(kTestChannelName);
  request.set_attribute_id(attribute_id);
  nifake_grpc::GetAttributeViInt64Response response;
  ::grpc::Status status = service.GetAttributeViInt64(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(attribute_value, response.attribute_value());
}

TEST(NiFakeServiceTests, NiFakeService_GetAttributeViReal64_CallsGetAttributeViReal64)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  nifake_grpc::NiFakeAttribute attribute_id = nifake_grpc::NIFAKE_ATTRIBUTE_READ_WRITE_DOUBLE;
  double attribute_value = 12.345;
  EXPECT_CALL(*library, GetAttributeViReal64(kTestViSession, Pointee(*kTestChannelName), attribute_id, _))
      .WillOnce(DoAll(SetArgPointee<3>(attribute_value), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAttributeViReal64Request request;
  request.mutable_vi()->set_name(session_name);
  request.set_channel_name(kTestChannelName);
  request.set_attribute_id(attribute_id);
  nifake_grpc::GetAttributeViReal64Response response;
  ::grpc::Status status = service.GetAttributeViReal64(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(attribute_value, response.attribute_value());
}

TEST(NiFakeServiceTests, NiFakeService_GetCalDateAndTime_CallsGetCalDateAndTime)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  std::int32_t cal_type = 0;
  std::int32_t month = 1, day = 17, year = 2021, hour = 0, minute = 0;
  EXPECT_CALL(*library, GetCalDateAndTime(kTestViSession, cal_type, _, _, _, _, _))
      .WillOnce(DoAll(
          SetArgPointee<2>(month),
          SetArgPointee<3>(day),
          SetArgPointee<4>(year),
          SetArgPointee<5>(hour),
          SetArgPointee<6>(minute),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetCalDateAndTimeRequest request;
  request.mutable_vi()->set_name(session_name);
  request.set_cal_type(cal_type);
  nifake_grpc::GetCalDateAndTimeResponse response;
  ::grpc::Status status = service.GetCalDateAndTime(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(month, response.month());
  EXPECT_EQ(day, response.day());
  EXPECT_EQ(year, response.year());
  EXPECT_EQ(hour, response.hour());
  EXPECT_EQ(minute, response.minute());
}

TEST(NiFakeServiceTests, NiFakeService_GetCalInterval_CallsGetCalInterval)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  nifake_grpc::NiFakeAttribute attribute_id = nifake_grpc::NIFAKE_ATTRIBUTE_READ_WRITE_DOUBLE;
  std::int32_t months = 24;
  EXPECT_CALL(*library, GetCalInterval(kTestViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(months), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetCalIntervalRequest request;
  request.mutable_vi()->set_name(session_name);
  nifake_grpc::GetCalIntervalResponse response;
  ::grpc::Status status = service.GetCalInterval(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(months, response.months());
}

TEST(NiFakeServiceTests, NiFakeService_GetEnumValue_CallsGetEnumValue)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  std::int32_t a_quantity = 123;
  std::int16_t a_turtle = NIFAKE_VAL_LEONARDO;
  EXPECT_CALL(*library, GetEnumValue(kTestViSession, _, _))
      .WillOnce(DoAll(SetArgPointee<1>(a_quantity), SetArgPointee<2>(a_turtle), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetEnumValueRequest request;
  request.mutable_vi()->set_name(session_name);
  nifake_grpc::GetEnumValueResponse response;
  ::grpc::Status status = service.GetEnumValue(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(a_quantity, response.a_quantity());
  EXPECT_EQ(a_turtle, response.a_turtle());
  EXPECT_EQ(a_turtle, response.a_turtle_raw());
}

TEST(NiFakeServiceTests, NiFakeService_GetEnumValueNotInEnum_CallsGetEnumValue)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  std::int32_t a_quantity = 123;
  std::int16_t a_turtle = 5;
  EXPECT_CALL(*library, GetEnumValue(kTestViSession, _, _))
      .WillOnce(DoAll(SetArgPointee<1>(a_quantity), SetArgPointee<2>(a_turtle), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetEnumValueRequest request;
  request.mutable_vi()->set_name(session_name);
  nifake_grpc::GetEnumValueResponse response;
  ::grpc::Status status = service.GetEnumValue(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(a_quantity, response.a_quantity());
  EXPECT_EQ(a_turtle, response.a_turtle());
  EXPECT_EQ(a_turtle, response.a_turtle_raw());
}

// Array input and output tests
TEST(NiFakeServiceTests, NiFakeService_AcceptListOfDurationsInSeconds_CallsAcceptListOfDurationsInSeconds)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  const double delays[] = {1, 2, 3, 4, 5};
  std::int32_t expected_size = 5;
  EXPECT_CALL(*library, AcceptListOfDurationsInSeconds(kTestViSession, expected_size, _))
      .With(Args<2, 1>(ElementsAreArray(delays)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::AcceptListOfDurationsInSecondsRequest request;
  request.mutable_vi()->set_name(session_name);
  for (double delay : delays) {
    request.add_delays(delay);
  }
  nifake_grpc::AcceptListOfDurationsInSecondsResponse response;
  ::grpc::Status status = service.AcceptListOfDurationsInSeconds(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_BoolArrayOutputFunction_CallsBoolArrayOutputFunction)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  ViInt32 number_of_elements = 3;
  ViBoolean an_array[] = {VI_FALSE, VI_TRUE, VI_TRUE};
  EXPECT_CALL(*library, BoolArrayOutputFunction(kTestViSession, number_of_elements, _))
      .WillOnce(DoAll(
          SetArrayArgument<2>(an_array, an_array + number_of_elements),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::BoolArrayOutputFunctionRequest request;
  request.mutable_vi()->set_name(session_name);
  request.set_number_of_elements(number_of_elements);
  nifake_grpc::BoolArrayOutputFunctionResponse response;
  ::grpc::Status status = service.BoolArrayOutputFunction(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  bool expected_response_booleans[] = {false, true, true};
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(response.an_array_size(), number_of_elements);
  EXPECT_THAT(response.an_array(), ElementsAreArray(expected_response_booleans, number_of_elements));
}

TEST(NiFakeServiceTests, NiFakeService_BoolArrayInputFunction_CallsBoolArrayInputFunction)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  ViInt32 number_of_elements = 3;
  ViBoolean expected_array[] = {VI_FALSE, VI_TRUE, VI_TRUE};
  EXPECT_CALL(*library, BoolArrayInputFunction(kTestViSession, number_of_elements, _))
      .With(Args<2, 1>(ElementsAreArray(expected_array)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::BoolArrayInputFunctionRequest request;
  request.mutable_vi()->set_name(session_name);
  request.set_number_of_elements(number_of_elements);
  request.add_an_array(false);
  request.add_an_array(true);
  request.add_an_array(true);
  nifake_grpc::BoolArrayInputFunctionResponse response;
  ::grpc::Status status = service.BoolArrayInputFunction(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_DoubleAllTheNums_CallsDoubleAllTheNums)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  const double numbers[] = {1, 2, 3, 4, 5};
  std::int32_t expected_size = 5;
  EXPECT_CALL(*library, DoubleAllTheNums(kTestViSession, expected_size, _))
      .With(Args<2, 1>(ElementsAreArray(numbers)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::DoubleAllTheNumsRequest request;
  request.mutable_vi()->set_name(session_name);
  for (double number : numbers) {
    request.add_numbers(number);
  }
  nifake_grpc::DoubleAllTheNumsResponse response;
  ::grpc::Status status = service.DoubleAllTheNums(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_GetAStringOfFixedMaximumSize_CallsGetAStringOfFixedMaximumSize)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  char output_string[256] = "Hello World!";
  EXPECT_CALL(*library, GetAStringOfFixedMaximumSize(kTestViSession, _))
      .WillOnce(DoAll(
          SetArrayArgument<1>(output_string, output_string + 256),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAStringOfFixedMaximumSizeRequest request;
  request.mutable_vi()->set_name(session_name);
  nifake_grpc::GetAStringOfFixedMaximumSizeResponse response;
  ::grpc::Status status = service.GetAStringOfFixedMaximumSize(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_STREQ(output_string, response.a_string().c_str());
}

TEST(NiFakeServiceTests, NiFakeService_GetCustomTypeArray_CallsGetCustomTypeArray)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  ViInt32 number_of_elements = 3;
  std::vector<CustomStruct> cs(number_of_elements);
  EXPECT_CALL(*library, GetCustomTypeArray(kTestViSession, number_of_elements, _))
      .WillOnce(DoAll(SetArgPointee<2>(*(cs.data())), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetCustomTypeArrayRequest request;
  request.mutable_vi()->set_name(session_name);
  request.set_number_of_elements(3);
  nifake_grpc::GetCustomTypeArrayResponse response;
  ::grpc::Status status = service.GetCustomTypeArray(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(response.cs_size(), cs.size());
}

TEST(NiFakeServiceTests, NiFakeService_ImportAttributeConfigurationBuffer_CallsImportAttributeConfigurationBuffer)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  const std::int8_t char_array[] = {'a', 'b', 'c'};
  std::int32_t expected_size = 3;
  EXPECT_CALL(*library, ImportAttributeConfigurationBuffer(kTestViSession, expected_size, _))
      .With(Args<2, 1>(ElementsAreArray(char_array)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::ImportAttributeConfigurationBufferRequest request;
  request.mutable_vi()->set_name(session_name);
  for (std::int8_t character : char_array) {
    request.mutable_configuration()->push_back(character);
  }
  nifake_grpc::ImportAttributeConfigurationBufferResponse response;
  ::grpc::Status status = service.ImportAttributeConfigurationBuffer(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

template <typename TRequest>
TRequest create_linked_array_request(
    std::string session_name,
    const std::vector<double>& values1,
    const std::vector<double>& values2,
    const std::vector<double>& values3,
    const std::vector<double>& values4)
{
  auto request = TRequest{};
  request.mutable_vi()->set_name(session_name);
  request.mutable_values1()->CopyFrom({values1.cbegin(), values1.cend()});
  request.mutable_values2()->CopyFrom({values2.cbegin(), values2.cend()});
  request.mutable_values3()->CopyFrom({values3.cbegin(), values3.cend()});
  request.mutable_values4()->CopyFrom({values4.cbegin(), values4.cend()});
  return request;
}

TEST(NiFakeServiceTests, NiFakeService_MultipleArraysSameSize_CallsMultipleArraysSameSize)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  const std::vector<double> doubles = {0.2, -2.3, 4.5};
  const auto expected_size = static_cast<std::int32_t>(doubles.size());
  EXPECT_CALL(*library, MultipleArraysSameSize(kTestViSession, _, _, _, _, expected_size))
      .With(AllOf(
          Args<1, 5>(ElementsAreArray(doubles.data(), expected_size)),
          Args<2, 5>(ElementsAreArray(doubles.data(), expected_size)),
          Args<3, 5>(ElementsAreArray(doubles.data(), expected_size)),
          Args<4, 5>(ElementsAreArray(doubles.data(), expected_size))))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  auto request = create_linked_array_request<MultipleArraysSameSizeRequest>(session_name, doubles, doubles, doubles, doubles);
  nifake_grpc::MultipleArraysSameSizeResponse response;
  ::grpc::Status status = service.MultipleArraysSameSize(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_MultipleArraysSameSize_OneArrayDifferentSizeFails)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  const std::vector<double> doubles = {0.2, -2.3, 4.5};
  EXPECT_CALL(*library, MultipleArraysSameSize)
      .Times(0);

  ::grpc::ServerContext context;
  const auto request = create_linked_array_request<MultipleArraysSameSizeRequest>(session_name, doubles, {doubles.begin() + 1, doubles.end()}, doubles, doubles);
  nifake_grpc::MultipleArraysSameSizeResponse response;
  ::grpc::Status status = service.MultipleArraysSameSize(&context, &request, &response);

  EXPECT_EQ(::grpc::INVALID_ARGUMENT, status.error_code());
}

TEST(NiFakeServiceTests, NiFakeService_MultipleArraysSameSize_OneArrayWithZeroSizeFails)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  const std::vector<double> doubles = {0.2, -2.3, 4.5};
  EXPECT_CALL(*library, MultipleArraysSameSize)
      .Times(0);

  ::grpc::ServerContext context;
  const auto request = create_linked_array_request<MultipleArraysSameSizeRequest>(session_name, {}, doubles, doubles, doubles);
  nifake_grpc::MultipleArraysSameSizeResponse response;
  ::grpc::Status status = service.MultipleArraysSameSize(&context, &request, &response);

  EXPECT_EQ(::grpc::INVALID_ARGUMENT, status.error_code());
}

FakeCustomStruct create_custom_struct(pb::int32 struct_int, double struct_double)
{
  auto custom_struct = FakeCustomStruct{};
  custom_struct.set_struct_int(struct_int);
  custom_struct.set_struct_double(struct_double);
  return custom_struct;
}

TEST(NiFakeServiceTests, NiFakeService_MultipleArraysSameSizeWithOptionals_OneArrayWithZeroSizePassesNull)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  const auto doubles = std::vector<double>{0.2, -2.3, 4.5};
  const auto fake_structs = std::vector<FakeCustomStruct>{
      create_custom_struct(1, 3.2),
      create_custom_struct(0, 10.0),
      create_custom_struct(100, 0.)};
  const auto expected_size = static_cast<std::int32_t>(doubles.size());
  EXPECT_CALL(*library, MultipleArraysSameSizeWithOptional(kTestViSession, _, _, _, nullptr, _, expected_size))
      .With(AllOf(
          Args<1, 6>(ElementsAreArray(doubles.data(), expected_size)),
          Args<2, 6>(ElementsAreArray(doubles.data(), expected_size)),
          Args<3, 6>(ElementsAreArray(doubles.data(), expected_size)),
          Args<5, 6>(ElementsAreArray(fake_structs.data(), expected_size))))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  auto request = create_linked_array_request<MultipleArraysSameSizeWithOptionalRequest>(session_name, doubles, doubles, doubles, {});
  request.mutable_values5()->CopyFrom({fake_structs.cbegin(), fake_structs.cend()});
  nifake_grpc::MultipleArraysSameSizeWithOptionalResponse response;
  ::grpc::Status status = service.MultipleArraysSameSizeWithOptional(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_MultipleArraysSameSizeWithOptionals_TwoZeroSizeArraysPassesNull)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  const std::vector<double> doubles = {0.2, -2.3, 4.5};
  const auto expected_size = static_cast<std::int32_t>(doubles.size());
  EXPECT_CALL(*library, MultipleArraysSameSizeWithOptional(kTestViSession, _, nullptr, nullptr, _, nullptr, expected_size))
      .With(AllOf(
          Args<1, 6>(ElementsAreArray(doubles.data(), expected_size)),
          Args<4, 6>(ElementsAreArray(doubles.data(), expected_size))))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  const auto request = create_linked_array_request<MultipleArraysSameSizeWithOptionalRequest>(session_name, doubles, {}, {}, doubles);
  nifake_grpc::MultipleArraysSameSizeWithOptionalResponse response;
  ::grpc::Status status = service.MultipleArraysSameSizeWithOptional(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_MultipleArraysSameSizeWithOptionals_DifferentNonZeroSizesFails)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  const std::vector<double> doubles = {1.2, 2.3, 4.5, 6};
  const auto expected_size = static_cast<std::int32_t>(doubles.size());
  EXPECT_CALL(*library, MultipleArraysSameSize)
      .Times(0);

  ::grpc::ServerContext context;
  const auto request = create_linked_array_request<MultipleArraysSameSizeWithOptionalRequest>(session_name, {}, doubles, {}, {doubles.begin() + 1, doubles.end()});
  nifake_grpc::MultipleArraysSameSizeWithOptionalResponse response;
  ::grpc::Status status = service.MultipleArraysSameSizeWithOptional(&context, &request, &response);

  EXPECT_EQ(::grpc::INVALID_ARGUMENT, status.error_code());
}

TEST(NiFakeServiceTests, NiFakeService_MultipleArraysSameSizeWithOptionals_AllEmptyArraysPassesEmpty)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  const std::vector<double> empty_doubles = {};
  const auto expected_size = static_cast<std::int32_t>(empty_doubles.size());
  EXPECT_CALL(*library, MultipleArraysSameSizeWithOptional(kTestViSession, _, _, _, _, nullptr, expected_size))
      .With(AllOf(
          Args<1, 6>(ElementsAreArray(empty_doubles.data(), expected_size)),
          Args<2, 6>(ElementsAreArray(empty_doubles.data(), expected_size)),
          Args<3, 6>(ElementsAreArray(empty_doubles.data(), expected_size)),
          Args<4, 6>(ElementsAreArray(empty_doubles.data(), expected_size))))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  const auto request = create_linked_array_request<MultipleArraysSameSizeWithOptionalRequest>(session_name, empty_doubles, empty_doubles, empty_doubles, empty_doubles);
  nifake_grpc::MultipleArraysSameSizeWithOptionalResponse response;
  ::grpc::Status status = service.MultipleArraysSameSizeWithOptional(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_ParametersAreMultipleTypes_CallsParametersAreMultipleTypes)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  bool a_boolean = true;
  std::int32_t an_int_32 = 35;
  std::int64_t an_int_64 = 42;
  nifake_grpc::Turtle an_int_enum = nifake_grpc::Turtle::TURTLE_MICHELANGELO;
  double a_float = 4.2;
  nifake_grpc::FloatEnum a_float_enum = nifake_grpc::FloatEnum::FLOAT_ENUM_SIX_POINT_FIVE;
  float expected_float_enum_value = 6.5;
  std::int32_t expected_string_size = 12;
  char a_string[] = "Hello There!";
  EXPECT_CALL(
      *library,
      ParametersAreMultipleTypes(
          kTestViSession,
          a_boolean,
          an_int_32,
          an_int_64,
          an_int_enum,
          a_float,
          expected_float_enum_value,
          StrEq(a_string)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::ParametersAreMultipleTypesRequest request;
  request.mutable_vi()->set_name(session_name);
  request.set_a_boolean(a_boolean);
  request.set_an_int32(an_int_32);
  request.set_an_int64(an_int_64);
  request.set_an_int_enum(an_int_enum);
  request.set_a_float(a_float);
  request.set_a_float_enum_mapped(a_float_enum);
  request.set_a_string(a_string);
  nifake_grpc::ParametersAreMultipleTypesResponse response;
  ::grpc::Status status = service.ParametersAreMultipleTypes(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_ParametersAreMultipleTypesWithRawValues_CallsParametersAreMultipleTypes)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  bool a_boolean = true;
  std::int32_t an_int_32 = 35;
  std::int64_t an_int_64 = 42;
  nifake_grpc::Turtle an_int_enum = nifake_grpc::Turtle::TURTLE_MICHELANGELO;
  double a_float = 4.2;
  float expected_float_enum_value = 6.5;
  std::int32_t expected_string_size = 12;
  char a_string[] = "Hello There!";
  EXPECT_CALL(
      *library,
      ParametersAreMultipleTypes(
          kTestViSession,
          a_boolean,
          an_int_32,
          an_int_64,
          an_int_enum,
          a_float,
          expected_float_enum_value,
          StrEq(a_string)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::ParametersAreMultipleTypesRequest request;
  request.mutable_vi()->set_name(session_name);
  request.set_a_boolean(a_boolean);
  request.set_an_int32(an_int_32);
  request.set_an_int64(an_int_64);
  request.set_an_int_enum_raw(an_int_enum);
  request.set_a_float(a_float);
  request.set_a_float_enum_raw(expected_float_enum_value);
  request.set_a_string(a_string);
  nifake_grpc::ParametersAreMultipleTypesResponse response;
  ::grpc::Status status = service.ParametersAreMultipleTypes(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_ParametersAreMultipleTypesWithRawValuesNotInEnum_CallsParametersAreMultipleTypes)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  bool a_boolean = true;
  std::int32_t an_int_32 = 35;
  std::int64_t an_int_64 = 42;
  std::int32_t expected_int_enum_value = 5;  // value not in enum
  double a_float = 4.2;
  float expected_float_enum_value = 8.5;  // value not in enum
  std::int32_t expected_string_size = 12;
  char a_string[] = "Hello There!";
  EXPECT_CALL(
      *library,
      ParametersAreMultipleTypes(
          kTestViSession,
          a_boolean,
          an_int_32,
          an_int_64,
          expected_int_enum_value,
          a_float,
          expected_float_enum_value,
          StrEq(a_string)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::ParametersAreMultipleTypesRequest request;
  request.mutable_vi()->set_name(session_name);
  request.set_a_boolean(a_boolean);
  request.set_an_int32(an_int_32);
  request.set_an_int64(an_int_64);
  request.set_an_int_enum_raw(expected_int_enum_value);
  request.set_a_float(a_float);
  request.set_a_float_enum_raw(expected_float_enum_value);
  request.set_a_string(a_string);
  nifake_grpc::ParametersAreMultipleTypesResponse response;
  ::grpc::Status status = service.ParametersAreMultipleTypes(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_ReturnANumberAndAString_CallsReturnANumberAndAString)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  std::int16_t a_number = 42;
  char a_string[256] = "Hello World!";
  EXPECT_CALL(*library, ReturnANumberAndAString(kTestViSession, _, _))
      .WillOnce(DoAll(
          SetArgPointee<1>(a_number),
          SetArrayArgument<2>(a_string, a_string + 256),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::ReturnANumberAndAStringRequest request;
  request.mutable_vi()->set_name(session_name);
  nifake_grpc::ReturnANumberAndAStringResponse response;
  ::grpc::Status status = service.ReturnANumberAndAString(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(a_number, response.a_number());
  EXPECT_STREQ(a_string, response.a_string().c_str());
}

TEST(NiFakeServiceTests, NiFakeService_ReturnListOfDurationsInSeconds_CallsReturnListOfDurationsInSeconds)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  ViInt32 number_of_elements = 3;
  ViReal64 timedeltas[] = {1.0, 2, -3.0};
  EXPECT_CALL(*library, ReturnListOfDurationsInSeconds(kTestViSession, number_of_elements, _))
      .WillOnce(DoAll(
          SetArrayArgument<2>(timedeltas, timedeltas + number_of_elements),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::ReturnListOfDurationsInSecondsRequest request;
  request.mutable_vi()->set_name(session_name);
  request.set_number_of_elements(3);
  nifake_grpc::ReturnListOfDurationsInSecondsResponse response;
  ::grpc::Status status = service.ReturnListOfDurationsInSeconds(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  double expected_response_doubles[] = {1.0, 2, -3.0};
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(response.timedeltas_size(), number_of_elements);
  EXPECT_THAT(response.timedeltas(), ElementsAreArray(expected_response_doubles, number_of_elements));
}

TEST(NiFakeServiceTests, NiFakeService_ReturnMultipleTypes_CallsReturnMultipleTypes)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  ViInt32 array_size = 3;
  ViBoolean a_boolean = false;
  ViInt32 an_int32 = 4;
  ViInt64 an_int64 = 5;
  ViInt16 an_int_enum = nifake_grpc::Turtle::TURTLE_MICHELANGELO;
  ViReal64 a_float = 7.2;
  ViReal64 a_float_enum = 6.5f;
  ViReal64 an_array[] = {1.0, 2, -3.0};
  char a_string[] = "Hello!";
  ViInt32 string_size = sizeof(a_string);
  // ivi-dance call
  EXPECT_CALL(*library, ReturnMultipleTypes(kTestViSession, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, nullptr, 0, nullptr))
      .WillOnce(Return(string_size));
  EXPECT_CALL(*library, ReturnMultipleTypes(kTestViSession, _, _, _, _, _, _, array_size, _, string_size, _))
      .WillOnce(DoAll(
          SetArgPointee<1>(a_boolean),
          SetArgPointee<2>(an_int32),
          SetArgPointee<3>(an_int64),
          SetArgPointee<4>(an_int_enum),
          SetArgPointee<5>(a_float),
          SetArgPointee<6>(a_float_enum),
          SetArrayArgument<8>(an_array, an_array + array_size),
          SetArrayArgument<10>(a_string, a_string + string_size),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::ReturnMultipleTypesRequest request;
  request.mutable_vi()->set_name(session_name);
  request.set_array_size(3);
  nifake_grpc::ReturnMultipleTypesResponse response;
  ::grpc::Status status = service.ReturnMultipleTypes(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(a_boolean, response.a_boolean());
  EXPECT_EQ(an_int32, response.an_int32());
  EXPECT_EQ(an_int64, response.an_int64());
  EXPECT_EQ(an_int_enum, response.an_int_enum());
  EXPECT_EQ(an_int_enum, response.an_int_enum_raw());
  EXPECT_EQ(a_float, response.a_float());
  EXPECT_EQ(nifake_grpc::FloatEnum::FLOAT_ENUM_SIX_POINT_FIVE, response.a_float_enum_mapped());
  EXPECT_EQ(a_float_enum, response.a_float_enum_raw());
  EXPECT_THAT(response.an_array(), ElementsAreArray(an_array, array_size));
  EXPECT_STREQ(response.a_string().c_str(), a_string);
  EXPECT_EQ(response.a_string().length(), string_size - 1);
}

TEST(NiFakeServiceTests, NiFakeService_WriteWaveform_CallsWriteWaveform)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  ViReal64 waveforms[] = {53.4, 42, -120.3};
  std::int32_t expected_number_of_samples = 3;
  EXPECT_CALL(*library, WriteWaveform(kTestViSession, expected_number_of_samples, _))
      .With(Args<2, 1>(ElementsAreArray(waveforms)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::WriteWaveformRequest request;
  request.mutable_vi()->set_name(session_name);
  for (double waveform : waveforms) {
    request.add_waveform(waveform);
  }
  nifake_grpc::WriteWaveformResponse response;
  ::grpc::Status status = service.WriteWaveform(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_FetchWaveform_CallsFetchWaveform)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  ViInt32 request_number_of_samples = 4;
  ViReal64 actual_doubles[] = {53.4, 42, -120.3};
  ViInt32 actual_number_of_samples = 3;
  EXPECT_CALL(*library, FetchWaveform(kTestViSession, request_number_of_samples, _, _))
      .WillOnce(DoAll(
          SetArrayArgument<2>(actual_doubles, actual_doubles + actual_number_of_samples),
          SetArgPointee<3>(actual_number_of_samples),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::FetchWaveformRequest request;
  request.mutable_vi()->set_name(session_name);
  request.set_number_of_samples(request_number_of_samples);
  nifake_grpc::FetchWaveformResponse response;
  ::grpc::Status status = service.FetchWaveform(&context, &request, &response);

  double expected_response_doubles[] = {actual_doubles[0], actual_doubles[1], actual_doubles[2], 0.0};
  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(response.actual_number_of_samples(), actual_number_of_samples);
  EXPECT_EQ(response.waveform_data_size(), request_number_of_samples);
  EXPECT_THAT(response.waveform_data(), ElementsAreArray(expected_response_doubles, request_number_of_samples));
}

// Non-int enum Tests
TEST(NiFakeServiceTests, NiFakeService_StringValuedEnumInputFunctionWithDefaultsWithInvalidEnumInput_ReturnsInvalidArgument)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  nifake_grpc::MobileOSNames a_mobile_o_s_name = nifake_grpc::MOBILE_OS_NAMES_UNSPECIFIED;
  EXPECT_CALL(*library, StringValuedEnumInputFunctionWithDefaults)
      .Times(0);

  ::grpc::ServerContext context;
  nifake_grpc::StringValuedEnumInputFunctionWithDefaultsRequest request;
  request.mutable_vi()->set_name(session_name);
  request.set_a_mobile_os_name_mapped(a_mobile_o_s_name);
  nifake_grpc::StringValuedEnumInputFunctionWithDefaultsResponse response;
  ::grpc::Status status = service.StringValuedEnumInputFunctionWithDefaults(&context, &request, &response);

  EXPECT_EQ(::grpc::INVALID_ARGUMENT, status.error_code());
  EXPECT_EQ(NULL, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_StringValuedEnumInputFunctionWithDefaultsWithValidEnumInput_CallsStringValuedEnumInputFunctionWithDefaults)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  nifake_grpc::MobileOSNames a_mobile_o_s_name = nifake_grpc::MOBILE_OS_NAMES_ANDROID;
  const char* expected_enum_value = NIFAKE_VAL_ANDROID;
  EXPECT_CALL(*library, StringValuedEnumInputFunctionWithDefaults(kTestViSession, Pointee(*expected_enum_value)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::StringValuedEnumInputFunctionWithDefaultsRequest request;
  request.mutable_vi()->set_name(session_name);
  request.set_a_mobile_os_name_mapped(a_mobile_o_s_name);
  nifake_grpc::StringValuedEnumInputFunctionWithDefaultsResponse response;
  ::grpc::Status status = service.StringValuedEnumInputFunctionWithDefaults(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

// Array methods using ivi-dance mechanism
TEST(NiFakeServiceTests, NiFakeService_ExportAttributeConfigurationBuffer_CallsExportAttributeConfigurationBuffer)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  ViInt8 config_buffer[] = {'A', 'B', 'C'};
  ViInt32 expected_size = 3;
  // ivi-dance call
  EXPECT_CALL(*library, ExportAttributeConfigurationBuffer(kTestViSession, 0, nullptr))
      .WillOnce(Return(expected_size));
  // follow up call with size returned from ivi-dance setup.
  EXPECT_CALL(*library, ExportAttributeConfigurationBuffer(kTestViSession, expected_size, _))
      .WillOnce(DoAll(
          SetArrayArgument<2>(config_buffer, config_buffer + expected_size),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::ExportAttributeConfigurationBufferRequest request;
  request.mutable_vi()->set_name(session_name);
  nifake_grpc::ExportAttributeConfigurationBufferResponse response;
  ::grpc::Status status = service.ExportAttributeConfigurationBuffer(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_THAT(response.configuration(), ElementsAreArray(config_buffer, expected_size));
}

TEST(NiFakeServiceTests, NiFakeService_GetAnIviDanceString_CallsGetAnIviDanceString)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  ViChar char_array[] = {'H', 'E', 'L', 'L', 'O', '\0'};
  ViInt32 expected_size = sizeof(char_array);
  // ivi-dance call
  EXPECT_CALL(*library, GetAnIviDanceString(kTestViSession, 0, nullptr))
      .WillOnce(Return(expected_size));
  // follow up call with size returned from ivi-dance setup.
  EXPECT_CALL(*library, GetAnIviDanceString(kTestViSession, expected_size, _))
      .WillOnce(DoAll(
          SetArrayArgument<2>(char_array, char_array + expected_size),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAnIviDanceStringRequest request;
  request.mutable_vi()->set_name(session_name);
  nifake_grpc::GetAnIviDanceStringResponse response;
  ::grpc::Status status = service.GetAnIviDanceString(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_STREQ(response.a_string().c_str(), char_array);
  EXPECT_EQ(response.a_string().length(), expected_size - 1);
}

TEST(NiFakeServiceTests, NiFakeService_GetArrayUsingIviDance_CallsGetArrayUsingIviDance)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  ViReal64 doubles[] = {53.4, 42, -120.3};
  ViInt32 expected_size = 3;
  // ivi-dance call
  EXPECT_CALL(*library, GetArrayUsingIviDance(kTestViSession, 0, nullptr))
      .WillOnce(Return(expected_size));
  // follow up call with size returned from ivi-dance setup.
  EXPECT_CALL(*library, GetArrayUsingIviDance(kTestViSession, expected_size, _))
      .WillOnce(DoAll(
          SetArrayArgument<2>(doubles, doubles + expected_size),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetArrayUsingIviDanceRequest request;
  request.mutable_vi()->set_name(session_name);
  nifake_grpc::GetArrayUsingIviDanceResponse response;
  ::grpc::Status status = service.GetArrayUsingIviDance(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_THAT(response.array_out(), ElementsAreArray(doubles, expected_size));
}

TEST(NiFakeServiceTests, NiFakeService_GetArrayUsingIviDanceWithChangingSizesByReturnValue_CallsGetArrayUsingIviDance)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  ViReal64 doubles[] = {53.4, 42, -120.3};
  ViInt32 expected_old_size = 2;
  ViInt32 expected_new_size = 3;
  // ivi-dance call
  EXPECT_CALL(*library, GetArrayUsingIviDance(kTestViSession, 0, nullptr))
      .WillOnce(Return(expected_old_size))
      .WillOnce(Return(expected_new_size));
  // follow up call - return that the array now needs to be bigger, so the ivi-dance
  // call will be made again.
  ::testing::Expectation first_real_call = EXPECT_CALL(*library, GetArrayUsingIviDance(kTestViSession, expected_old_size, _))
                                               .WillOnce(Return(expected_new_size));
  // follow up call with size returned from ivi-dance setup.
  EXPECT_CALL(*library, GetArrayUsingIviDance(kTestViSession, expected_new_size, _))
      .After(first_real_call)
      .WillOnce(DoAll(
          SetArrayArgument<2>(doubles, doubles + expected_new_size),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetArrayUsingIviDanceRequest request;
  request.mutable_vi()->set_name(session_name);
  nifake_grpc::GetArrayUsingIviDanceResponse response;
  ::grpc::Status status = service.GetArrayUsingIviDance(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_THAT(response.array_out(), ElementsAreArray(doubles, expected_new_size));
}

TEST(NiFakeServiceTests, NiFakeService_GetArrayUsingIviDanceWithChangingSizesByError_CallsGetArrayUsingIviDance)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  ViReal64 doubles[] = {53.4, 42, -120.3};
  ViInt32 expected_old_size = 2;
  ViInt32 expected_new_size = 3;
  // ivi-dance call
  EXPECT_CALL(*library, GetArrayUsingIviDance(kTestViSession, 0, nullptr))
      .WillOnce(Return(expected_old_size))
      .WillOnce(Return(expected_new_size));
  // follow up call - return that the array now needs to be bigger, so the ivi-dance
  // call will be made again.
  // Use the value of the error here to ensure that it doesn't change.
  ::testing::Expectation first_real_call = EXPECT_CALL(*library, GetArrayUsingIviDance(kTestViSession, expected_old_size, _))
                                               .WillOnce(Return(-200229));
  // follow up call with size returned from ivi-dance setup.
  EXPECT_CALL(*library, GetArrayUsingIviDance(kTestViSession, expected_new_size, _))
      .After(first_real_call)
      .WillOnce(DoAll(
          SetArrayArgument<2>(doubles, doubles + expected_new_size),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetArrayUsingIviDanceRequest request;
  request.mutable_vi()->set_name(session_name);
  nifake_grpc::GetArrayUsingIviDanceResponse response;
  ::grpc::Status status = service.GetArrayUsingIviDance(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_THAT(response.array_out(), ElementsAreArray(doubles, expected_new_size));
}

TEST(NiFakeServiceTests, NiFakeService_GetAttributeViString_CallsGetAttributeViString)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  nifake_grpc::NiFakeAttribute attributeId = nifake_grpc::NIFAKE_ATTRIBUTE_READ_WRITE_DOUBLE;
  ViChar attribute_char_array[] = {'H', 'E', 'L', 'L', 'O', '\0'};
  ViInt32 expected_size = sizeof(attribute_char_array);
  // ivi-dance call
  EXPECT_CALL(*library, GetAttributeViString(kTestViSession, Pointee(*kTestChannelName), attributeId, 0, nullptr))
      .WillOnce(Return(expected_size));
  // follow up call with size returned from ivi-dance setup.
  EXPECT_CALL(*library, GetAttributeViString(kTestViSession, Pointee(*kTestChannelName), attributeId, expected_size, _))
      .WillOnce(DoAll(
          SetArrayArgument<4>(attribute_char_array, attribute_char_array + expected_size),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAttributeViStringRequest request;
  request.mutable_vi()->set_name(session_name);
  request.set_channel_name(kTestChannelName);
  request.set_attribute_id(attributeId);
  nifake_grpc::GetAttributeViStringResponse response;
  ::grpc::Status status = service.GetAttributeViString(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_STREQ(response.attribute_value().c_str(), attribute_char_array);
  EXPECT_EQ(response.attribute_value().length(), expected_size - 1);
}

TEST(NiFakeServiceTests, NiFakeService_GetViUInt8_CallsGetViUInt8)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  ViUInt8 a_ViUInt8_number = 0xFF;
  EXPECT_CALL(*library, GetViUInt8(kTestViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(a_ViUInt8_number), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetViUInt8Request request;
  request.mutable_vi()->set_name(session_name);
  nifake_grpc::GetViUInt8Response response;
  ::grpc::Status status = service.GetViUInt8(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(a_ViUInt8_number, response.a_uint8_number());
}

TEST(NiFakeServiceTests, NiFakeService_ViUInt8ArrayInputFunction_CallsViUInt8ArrayInputFunction)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  ViInt32 number_of_elements = 3;
  ViUInt8 expected_array[] = {0, 127, 0xFF};
  EXPECT_CALL(*library, ViUInt8ArrayInputFunction(kTestViSession, number_of_elements, _))
      .With(Args<2, 1>(ElementsAreArray(expected_array)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::ViUInt8ArrayInputFunctionRequest request;
  request.mutable_vi()->set_name(session_name);
  request.set_number_of_elements(number_of_elements);
  std::string input_array;
  input_array.push_back(0);
  input_array.push_back(127);
  input_array.push_back(static_cast<char>(0xFF));
  request.set_an_array(input_array);
  nifake_grpc::ViUInt8ArrayInputFunctionResponse response;
  ::grpc::Status status = service.ViUInt8ArrayInputFunction(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_ViUInt8ArrayOutputFunction_CallsViUInt8ArrayOutputFunction)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  ViInt32 number_of_elements = 3;
  ViUInt8 an_array[] = {0, 127, 0xFF};
  EXPECT_CALL(*library, ViUInt8ArrayOutputFunction(kTestViSession, number_of_elements, _))
      .WillOnce(DoAll(
          SetArrayArgument<2>(an_array, an_array + number_of_elements),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::ViUInt8ArrayOutputFunctionRequest request;
  request.mutable_vi()->set_name(session_name);
  request.set_number_of_elements(number_of_elements);
  nifake_grpc::ViUInt8ArrayOutputFunctionResponse response;
  ::grpc::Status status = service.ViUInt8ArrayOutputFunction(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(response.an_array().size(), number_of_elements);
  EXPECT_THAT(response.an_array(), ElementsAreArray(an_array, number_of_elements));
}

TEST(NiFakeServiceTests, NiFakeService_AcceptViUInt32Array_CallsAcceptViUInt32Array)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  std::uint32_t uint32_array[] = {0, 1, 0xFFFFFFFD, 0xFFFFFFFE, 0xFFFFFFFF};
  std::int32_t array_len = 5;
  EXPECT_CALL(*library, AcceptViUInt32Array(kTestViSession, array_len, _))
      .With(Args<2, 1>(ElementsAreArray(uint32_array)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::AcceptViUInt32ArrayRequest request;
  request.mutable_vi()->set_name(session_name);
  request.mutable_u_int32_array()->CopyFrom(google::protobuf::RepeatedField<google::protobuf::uint32>(uint32_array, uint32_array + 5));
  nifake_grpc::AcceptViUInt32ArrayResponse response;
  ::grpc::Status status = service.AcceptViUInt32Array(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_GetViInt32Array_CallsGetViInt32Array)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  int array_len = 4;
  std::int32_t int32_array[] = {-2147483646, -2147483645, 2147483646, 2147483647};
  EXPECT_CALL(*library, GetViInt32Array(kTestViSession, array_len, _))
      .WillOnce(DoAll(SetArrayArgument<2>(int32_array, int32_array + array_len), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetViInt32ArrayRequest request;
  request.mutable_vi()->set_name(session_name);
  request.set_array_len(array_len);
  nifake_grpc::GetViInt32ArrayResponse response;
  ::grpc::Status status = service.GetViInt32Array(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_THAT(response.int32_array(), ElementsAreArray(int32_array, array_len));
}

TEST(NiFakeServiceTests, NiFakeService_GetViUInt32Array_CallsGetViUInt32Array)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  int array_len = 4;
  std::uint32_t uint32_array[] = {0, 1, 0xFFFFFFFE, 0xFFFFFFFF};
  EXPECT_CALL(*library, GetViUInt32Array(kTestViSession, array_len, _))
      .WillOnce(DoAll(SetArrayArgument<2>(uint32_array, uint32_array + array_len), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetViUInt32ArrayRequest request;
  request.mutable_vi()->set_name(session_name);
  request.set_array_len(array_len);
  nifake_grpc::GetViUInt32ArrayResponse response;
  ::grpc::Status status = service.GetViUInt32Array(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_THAT(response.u_int32_array(), ElementsAreArray(uint32_array, array_len));
}

TEST(NiFakeServiceTests, NiFakeService_AcceptViSessionArray_CallsAcceptViSessionArray)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  std::array<std::uint32_t, 3> vi_session_array{12345671, 12345672, 12345673};
  auto session_name1 = create_session(library, service, vi_session_array[0]);
  auto session_name2 = create_session(library, service, vi_session_array[1]);
  auto session_name3 = create_session(library, service, vi_session_array[2]);

  std::uint32_t session_count = 3;
  EXPECT_CALL(*library, AcceptViSessionArray(session_count, _))
      .With(Args<1, 0>(ElementsAreArray(vi_session_array)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::AcceptViSessionArrayRequest request;
  request.set_session_count(session_count);
  request.add_session_array()->set_name(session_name1);
  request.add_session_array()->set_name(session_name2);
  request.add_session_array()->set_name(session_name3);
  nifake_grpc::AcceptViSessionArrayResponse response;
  ::grpc::Status status = service.AcceptViSessionArray(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

MATCHER_P2(MatchesArray, array, array_size, "")
{
  for (int i = 0; i < array_size; i++) {
    if (arg[i] != array[i]) {
      return false;
    }
  }
  return true;
}

// Test for two-dimension mechanism to ensure we validate size correctly
TEST(NiFakeServiceTests, NiFakeService_UseTwoDimensionWithCorrectSize_CallsUseATwoDimensionParameter)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  ViInt32 array[] = {1, 2, 2, 3, 3, 3};
  ViInt32 array_lengths[] = {1, 2, 3};
  ViInt32 array_size = 3;
  // two-dimension call
  EXPECT_CALL(*library, UseATwoDimensionParameter(kTestViSession, MatchesArray(array, 6), _, array_size))
      .With(Args<2, 3>(ElementsAreArray(array_lengths)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::UseATwoDimensionParameterRequest request;
  request.mutable_vi()->set_name(session_name);
  for (int arrayval : array) {
    request.add_array(arrayval);
  }
  for (int length : array_lengths) {
    request.add_array_lengths(length);
  }
  nifake_grpc::UseATwoDimensionParameterResponse response;
  ::grpc::Status status = service.UseATwoDimensionParameter(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

// Test for two-dimension mechanism failure when the sum of array sizes of the two dimensional array don't match the actual size
TEST(NiFakeServiceTests, NiFakeService_UseTwoDimensionWithIncorrectSize_FailsUseATwoDimensionParameter)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  ViInt32 array[] = {1, 2, 2, 3, 3, 3};
  ViInt32 array_lengths[] = {2, 5, 6};

  EXPECT_CALL(*library, UseATwoDimensionParameter(kTestViSession, _, _, _))
      .Times(0);

  ::grpc::ServerContext context;
  nifake_grpc::UseATwoDimensionParameterRequest request;
  request.mutable_vi()->set_name(session_name);
  for (int arrayval : array) {
    request.add_array(arrayval);
  }
  for (int length : array_lengths) {
    request.add_array_lengths(length);
  }
  nifake_grpc::UseATwoDimensionParameterResponse response;
  ::grpc::Status status = service.UseATwoDimensionParameter(&context, &request, &response);

  EXPECT_FALSE(status.ok());
  EXPECT_EQ(::grpc::INVALID_ARGUMENT, status.error_code());
  EXPECT_THAT(status.error_message(), HasSubstr("The total size of the two-dimensional array"));
}

// Test for ivi-dance-with-a-twist mechanism
TEST(NiFakeServiceTests, NiFakeService_GetAnIviDanceWithATwistArray_CallsGetAnIviDanceWithATwistArray)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  const char* a_string = "abc";
  ViInt32 array_out[] = {1, 2, 3};
  ViInt32 expected_size = 3;
  // ivi-dance-with-a-twist call
  EXPECT_CALL(*library, GetAnIviDanceWithATwistArray(kTestViSession, Pointee(*a_string), 0, nullptr, _))
      .WillOnce(DoAll(
          SetArgPointee<4>(expected_size),
          Return(kDriverSuccess)));
  // follow up call with size returned from ivi-dance-with-a-twist setup.
  EXPECT_CALL(*library, GetAnIviDanceWithATwistArray(kTestViSession, Pointee(*a_string), expected_size, _, _))
      .WillOnce(DoAll(
          SetArrayArgument<3>(array_out, array_out + expected_size),
          SetArgPointee<4>(expected_size),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAnIviDanceWithATwistArrayRequest request;
  request.mutable_vi()->set_name(session_name);
  request.set_a_string(a_string);
  nifake_grpc::GetAnIviDanceWithATwistArrayResponse response;
  ::grpc::Status status = service.GetAnIviDanceWithATwistArray(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_THAT(response.array_out(), ElementsAreArray(array_out, expected_size));
  EXPECT_EQ(response.actual_size(), expected_size);
}

TEST(NiFakeServiceTests, NiFakeService_GetAnIviDanceWithATwistArrayWithWarning_CallsGetAnIviDanceWithATwistArray)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  const char* a_string = "abc";
  const auto data_in = std::array<ViInt32, 4>{0, -1, 100, 5};
  ViInt32 input_size = 2;
  ViInt32 array_out[] = {1, 2, 3};
  ViInt32 expected_size = 3;

  // ivi-dance-with-a-twist call
  EXPECT_CALL(*library, GetAnIviDanceWithATwistArray(kTestViSession, Pointee(*a_string), 0, nullptr, _))
      .WillOnce(DoAll(
          SetArgPointee<4>(expected_size),
          Return(kDriverSuccess)));
  // follow up call with size returned from ivi-dance-with-a-twist setup.
  EXPECT_CALL(*library, GetAnIviDanceWithATwistArray(kTestViSession, Pointee(*a_string), expected_size, _, _))
      .WillOnce(DoAll(
          SetArrayArgument<3>(array_out, array_out + expected_size),
          SetArgPointee<4>(expected_size),
          Return(kDriverWarning)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAnIviDanceWithATwistArrayRequest request;
  request.mutable_vi()->set_name(session_name);
  request.set_a_string(a_string);
  nifake_grpc::GetAnIviDanceWithATwistArrayResponse response;
  ::grpc::Status status = service.GetAnIviDanceWithATwistArray(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverWarning, response.status());
  EXPECT_THAT(response.array_out(), ElementsAreArray(array_out, expected_size));
  EXPECT_EQ(response.actual_size(), expected_size);
}

TEST(NiFakeServiceTests, NiFakeService_GetAnIviDanceWithATwistArrayWithInputArray_PassesArrayInputOnFirstPass_CallsGetAnIviDanceWithATwistArray)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  const auto data_in = std::array<ViInt32, 4>{0, -1, 100, 5};
  ViInt32 input_size = 2;
  ViInt32 array_out[] = {1, 2, 3};
  ViInt32 expected_size = 3;
  // ivi-dance-with-a-twist call: ensure that data and size are passed in.
  EXPECT_CALL(*library, GetAnIviDanceWithATwistArrayWithInputArray(_, _, 0, nullptr, _))
      .With(Args<0, 1>(ElementsAreArray(data_in)))
      .WillOnce(DoAll(
          SetArgPointee<4>(expected_size),
          Return(kDriverSuccess)));
  EXPECT_CALL(*library, GetAnIviDanceWithATwistArrayWithInputArray(_, _, expected_size, _, _))
      .With(Args<0, 1>(ElementsAreArray(data_in)))
      .WillOnce(DoAll(
          SetArrayArgument<3>(array_out, array_out + expected_size),
          SetArgPointee<4>(expected_size),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAnIviDanceWithATwistArrayWithInputArrayRequest request;
  request.mutable_data_in()->CopyFrom({data_in.begin(), data_in.end()});
  nifake_grpc::GetAnIviDanceWithATwistArrayWithInputArrayResponse response;
  ::grpc::Status status = service.GetAnIviDanceWithATwistArrayWithInputArray(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_THAT(response.array_out(), ElementsAreArray(array_out, expected_size));
  EXPECT_EQ(response.actual_size(), expected_size);
}

TEST(NiFakeServiceTests, NiFakeService_GetAnIviDanceWithATwistArrayWithBiggerSizes_CallsGetAnIviDanceWithATwistArray)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  const char* a_string = "abc";
  ViInt32 array_out[] = {1, 2, 3};
  ViInt32 expected_old_size = 2;
  ViInt32 expected_new_size = 3;
  // ivi-dance-with-a-twist call
  EXPECT_CALL(*library, GetAnIviDanceWithATwistArray(kTestViSession, Pointee(*a_string), 0, nullptr, _))
      .WillOnce(DoAll(
          SetArgPointee<4>(expected_old_size),
          Return(kDriverSuccess)))
      .WillOnce(DoAll(
          SetArgPointee<4>(expected_new_size),
          Return(kDriverSuccess)));
  // follow up call - return that the array now needs to be bigger, so the ivi-dance
  // call will be made again.
  // Use the value of the error here to ensure that it doesn't change.
  ::testing::Expectation first_real_call = EXPECT_CALL(*library, GetAnIviDanceWithATwistArray(kTestViSession, Pointee(*a_string), expected_old_size, _, _))
                                               .WillOnce(Return(-200229));
  // follow up call with size returned from ivi-dance-with-a-twist setup.
  EXPECT_CALL(*library, GetAnIviDanceWithATwistArray(kTestViSession, Pointee(*a_string), expected_new_size, _, _))
      .After(first_real_call)
      .WillOnce(DoAll(
          SetArrayArgument<3>(array_out, array_out + expected_new_size),
          SetArgPointee<4>(expected_new_size),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAnIviDanceWithATwistArrayRequest request;
  request.mutable_vi()->set_name(session_name);
  request.set_a_string(a_string);
  nifake_grpc::GetAnIviDanceWithATwistArrayResponse response;
  ::grpc::Status status = service.GetAnIviDanceWithATwistArray(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_THAT(response.array_out(), ElementsAreArray(array_out, expected_new_size));
  EXPECT_EQ(response.actual_size(), expected_new_size);
}

TEST(NiFakeServiceTests, NiFakeService_GetAnIviDanceWithATwistArrayWithSmallerSizes_CallsGetAnIviDanceWithATwistArray)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  const char* a_string = "abc";
  ViInt32 array_out[] = {1, 2, 3};
  ViInt32 expected_old_size = 3;
  ViInt32 expected_new_size = 2;
  // ivi-dance-with-a-twist call
  EXPECT_CALL(*library, GetAnIviDanceWithATwistArray(kTestViSession, Pointee(*a_string), 0, nullptr, _))
      .WillOnce(DoAll(
          SetArgPointee<4>(expected_old_size),
          Return(kDriverSuccess)));
  // follow up call - return that the array now needs to be smaller.
  EXPECT_CALL(*library, GetAnIviDanceWithATwistArray(kTestViSession, Pointee(*a_string), expected_old_size, _, _))
      .WillOnce(DoAll(
          SetArrayArgument<3>(array_out, array_out + expected_new_size),
          SetArgPointee<4>(expected_new_size),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAnIviDanceWithATwistArrayRequest request;
  request.mutable_vi()->set_name(session_name);
  request.set_a_string(a_string);
  nifake_grpc::GetAnIviDanceWithATwistArrayResponse response;
  ::grpc::Status status = service.GetAnIviDanceWithATwistArray(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_THAT(response.array_out(), ElementsAreArray(array_out, expected_new_size));
  EXPECT_EQ(response.actual_size(), expected_new_size);
}

TEST(NiFakeServiceTests, NiFakeService_GetAnIviDanceWithATwistByteArrayWithSmallerSizes_CallsGetAnIviDanceWithATwistByteArray)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  const auto DATA = std::vector<char>{'a', 'b'};
  const auto NEW_SIZE = static_cast<ViInt32>(DATA.size());
  const auto OLD_SIZE = NEW_SIZE + 1;
  // ivi-dance-with-a-twist call
  EXPECT_CALL(*library, GetAnIviDanceWithATwistByteArray(0, nullptr, _))
      .WillOnce(DoAll(
          SetArgPointee<2>(OLD_SIZE),
          Return(kDriverSuccess)));
  // follow up call - return that the array now needs to be smaller.
  EXPECT_CALL(*library, GetAnIviDanceWithATwistByteArray(OLD_SIZE, _, _))
      .WillOnce(DoAll(
          SetArrayArgument<1>(DATA.cbegin(), DATA.cend()),
          SetArgPointee<2>(NEW_SIZE),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAnIviDanceWithATwistByteArrayRequest request;
  nifake_grpc::GetAnIviDanceWithATwistByteArrayResponse response;
  ::grpc::Status status = service.GetAnIviDanceWithATwistByteArray(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(
      DATA,
      std::vector<char>(response.array_out().cbegin(), response.array_out().cend()));
  EXPECT_EQ(response.actual_size(), NEW_SIZE);
}

TEST(NiFakeServiceTests, NiFakeService_GetAnIviDanceWithATwistStringWithSmallerSizes_CallsGetAnIviDanceWithATwistString)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  const auto DATA = std::string("ab");
  // +1 to include null terminator.
  const auto NEW_SIZE = static_cast<ViInt32>(DATA.size() + 1);
  const auto OLD_SIZE = NEW_SIZE + 1;
  // ivi-dance-with-a-twist call
  EXPECT_CALL(*library, GetAnIviDanceWithATwistString(kTestViSession, 0, nullptr, _))
      .WillOnce(DoAll(
          SetArgPointee<3>(OLD_SIZE),
          Return(kDriverSuccess)));
  // follow up call - return that the array now needs to be smaller.
  EXPECT_CALL(*library, GetAnIviDanceWithATwistString(kTestViSession, OLD_SIZE, _, _))
      .WillOnce(DoAll(
          SetArrayArgument<2>(DATA.c_str(), DATA.c_str() + NEW_SIZE),
          SetArgPointee<3>(NEW_SIZE),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAnIviDanceWithATwistStringRequest request;
  request.mutable_vi()->set_name(session_name);
  nifake_grpc::GetAnIviDanceWithATwistStringResponse response;
  ::grpc::Status status = service.GetAnIviDanceWithATwistString(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(DATA, response.a_string());
  EXPECT_EQ(response.actual_size(), NEW_SIZE);
}

TEST(NiFakeServiceTests, NiFakeService_GetAnIviDanceWithATwistStrlenBug_ReturnsCorrectString)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  const auto DATA = std::string("abcdef");
  // Oops forgot the +1!
  const auto SIZE = static_cast<ViInt32>(DATA.size());
  EXPECT_CALL(*library, GetAnIviDanceWithATwistStringStrlenBug(0, nullptr, _))
      .WillOnce(DoAll(
          SetArgPointee<2>(SIZE),
          Return(kDriverSuccess)));
  EXPECT_CALL(*library, GetAnIviDanceWithATwistStringStrlenBug(SIZE, _, _))
      .WillOnce(DoAll(
          SetArrayArgument<1>(DATA.c_str(), DATA.c_str() + SIZE + 1),
          SetArgPointee<2>(SIZE),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAnIviDanceWithATwistStringStrlenBugRequest request;
  nifake_grpc::GetAnIviDanceWithATwistStringStrlenBugResponse response;
  ::grpc::Status status = service.GetAnIviDanceWithATwistStringStrlenBug(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(DATA, response.string_out());
  EXPECT_EQ(response.actual_size(), SIZE);
}

TEST(NiFakeServiceTests, NiFakeService_GetAnIviDanceWithATwistStrlenBugIsFixed_ReturnsCorrectString)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  const auto DATA = std::string("abcdef");
  // Someone fixed the bug to add the null terminator!
  const auto SIZE = static_cast<ViInt32>(DATA.size() + 1);
  EXPECT_CALL(*library, GetAnIviDanceWithATwistStringStrlenBug(0, nullptr, _))
      .WillOnce(DoAll(
          SetArgPointee<2>(SIZE),
          Return(kDriverSuccess)));
  EXPECT_CALL(*library, GetAnIviDanceWithATwistStringStrlenBug(SIZE, _, _))
      .WillOnce(DoAll(
          SetArrayArgument<1>(DATA.c_str(), DATA.c_str() + SIZE + 1),
          SetArgPointee<2>(SIZE),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAnIviDanceWithATwistStringStrlenBugRequest request;
  nifake_grpc::GetAnIviDanceWithATwistStringStrlenBugResponse response;
  ::grpc::Status status = service.GetAnIviDanceWithATwistStringStrlenBug(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(DATA, response.string_out());
  EXPECT_EQ(response.actual_size(), SIZE);
}

TEST(NiFakeServiceTests, NiFakeService_GetAnIviDanceWithATwistArrayWithChangingSizesAndWarning_CallsGetAnIviDanceWithATwistArray)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  const char* a_string = "abc";
  ViInt32 array_out[] = {1, 2, 3};
  ViInt32 expected_old_size = 2;
  ViInt32 expected_new_size = 3;
  // ivi-dance-with-a-twist call
  EXPECT_CALL(*library, GetAnIviDanceWithATwistArray(kTestViSession, Pointee(*a_string), 0, nullptr, _))
      .WillOnce(DoAll(
          SetArgPointee<4>(expected_old_size),
          Return(kDriverSuccess)))
      .WillOnce(DoAll(
          SetArgPointee<4>(expected_new_size),
          Return(kDriverSuccess)));
  // follow up call - return that the array now needs to be bigger, so the ivi-dance
  // call will be made again.
  // Use the value of the warning here to ensure that it doesn't change.
  ::testing::Expectation first_real_call = EXPECT_CALL(*library, GetAnIviDanceWithATwistArray(kTestViSession, Pointee(*a_string), expected_old_size, _, _))
                                               .WillOnce(Return(200026));
  // follow up call with size returned from ivi-dance-with-a-twist setup.
  EXPECT_CALL(*library, GetAnIviDanceWithATwistArray(kTestViSession, Pointee(*a_string), expected_new_size, _, _))
      .After(first_real_call)
      .WillOnce(DoAll(
          SetArrayArgument<3>(array_out, array_out + expected_new_size),
          SetArgPointee<4>(expected_new_size),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAnIviDanceWithATwistArrayRequest request;
  request.mutable_vi()->set_name(session_name);
  request.set_a_string(a_string);
  nifake_grpc::GetAnIviDanceWithATwistArrayResponse response;
  ::grpc::Status status = service.GetAnIviDanceWithATwistArray(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_THAT(response.array_out(), ElementsAreArray(array_out, expected_new_size));
  EXPECT_EQ(response.actual_size(), expected_new_size);
}

// Test for ivi-dance-with-a-twist mechanism
TEST(NiFakeServiceTests, NiFakeService_GetAnIviDanceWithATwistArrayOfCustomType_CallsGetAnIviDanceWithATwistArrayOfCustomType)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  CustomStruct array_out[] = {{-1, -2.0}, {0, 0.5}, {70000, 32768.0}};
  ViInt32 expected_size = 3;
  // ivi-dance-with-a-twist call
  EXPECT_CALL(*library, GetAnIviDanceWithATwistArrayOfCustomType(kTestViSession, 0, nullptr, _))
      .WillOnce(DoAll(
          SetArgPointee<3>(expected_size),
          Return(kDriverSuccess)));
  // follow up call with size returned from ivi-dance-with-a-twist setup.
  EXPECT_CALL(*library, GetAnIviDanceWithATwistArrayOfCustomType(kTestViSession, expected_size, _, _))
      .WillOnce(DoAll(
          SetArrayArgument<2>(array_out, array_out + expected_size),
          SetArgPointee<3>(expected_size),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAnIviDanceWithATwistArrayOfCustomTypeRequest request;
  request.mutable_vi()->set_name(session_name);
  nifake_grpc::GetAnIviDanceWithATwistArrayOfCustomTypeResponse response;
  ::grpc::Status status = service.GetAnIviDanceWithATwistArrayOfCustomType(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_THAT(response.array_out(), ElementsAreArray(array_out, expected_size));
  EXPECT_EQ(response.actual_size(), expected_size);
}

TEST(NiFakeServiceTests, NiFakeService_GetAnIviDanceWithATwistArrayOfCustomTypeWithBiggerSizes_CallsGetAnIviDanceWithATwistArrayOfCustomType)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  CustomStruct array_out[] = {{-1, -2.0}, {0, 0.5}, {70000, 32768.0}};
  ViInt32 expected_old_size = 2;
  ViInt32 expected_new_size = 3;
  // ivi-dance-with-a-twist call
  EXPECT_CALL(*library, GetAnIviDanceWithATwistArrayOfCustomType(kTestViSession, 0, nullptr, _))
      .WillOnce(DoAll(
          SetArgPointee<3>(expected_old_size),
          Return(kDriverSuccess)))
      .WillOnce(DoAll(
          SetArgPointee<3>(expected_new_size),
          Return(kDriverSuccess)));
  // follow up call - return that the array now needs to be bigger, so the ivi-dance
  // call will be made again.
  // Use the value of the error here to ensure that it doesn't change.
  ::testing::Expectation first_real_call = EXPECT_CALL(*library, GetAnIviDanceWithATwistArrayOfCustomType(kTestViSession, expected_old_size, _, _))
                                               .WillOnce(Return(-200229));
  // follow up call with size returned from ivi-dance-with-a-twist setup.
  EXPECT_CALL(*library, GetAnIviDanceWithATwistArrayOfCustomType(kTestViSession, expected_new_size, _, _))
      .After(first_real_call)
      .WillOnce(DoAll(
          SetArrayArgument<2>(array_out, array_out + expected_new_size),
          SetArgPointee<3>(expected_new_size),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAnIviDanceWithATwistArrayOfCustomTypeRequest request;
  request.mutable_vi()->set_name(session_name);
  nifake_grpc::GetAnIviDanceWithATwistArrayOfCustomTypeResponse response;
  ::grpc::Status status = service.GetAnIviDanceWithATwistArrayOfCustomType(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_THAT(response.array_out(), ElementsAreArray(array_out, expected_new_size));
  EXPECT_EQ(response.actual_size(), expected_new_size);
}

TEST(NiFakeServiceTests, NiFakeService_GetAnIviDanceWithATwistArrayOfCustomTypeWithSmallerSizes_CallsGetAnIviDanceWithATwistArrayOfCustomType)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  CustomStruct array_out[] = {{-1, -2.0}, {0, 0.5}};
  ViInt32 expected_old_size = 3;
  ViInt32 expected_new_size = 2;
  // ivi-dance-with-a-twist call
  EXPECT_CALL(*library, GetAnIviDanceWithATwistArrayOfCustomType(kTestViSession, 0, nullptr, _))
      .WillOnce(DoAll(
          SetArgPointee<3>(expected_old_size),
          Return(kDriverSuccess)));
  // follow up call - return that the array now needs to be smaller.
  EXPECT_CALL(*library, GetAnIviDanceWithATwistArrayOfCustomType(kTestViSession, expected_old_size, _, _))
      .WillOnce(DoAll(
          SetArrayArgument<2>(array_out, array_out + expected_new_size),
          SetArgPointee<3>(expected_new_size),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAnIviDanceWithATwistArrayOfCustomTypeRequest request;
  request.mutable_vi()->set_name(session_name);
  nifake_grpc::GetAnIviDanceWithATwistArrayOfCustomTypeResponse response;
  ::grpc::Status status = service.GetAnIviDanceWithATwistArrayOfCustomType(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_THAT(response.array_out(), ElementsAreArray(array_out, expected_new_size));
  EXPECT_EQ(response.actual_size(), expected_new_size);
}

TEST(NiFakeServiceTests, NiFakeService_AcceptViInt16Array_CallsAcceptViInt16Array)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  std::int16_t int16_array[] = {0, 1, -0x8000, 0x7FFF};
  std::int32_t array_len = 4;
  EXPECT_CALL(*library, ViInt16ArrayInputFunction(kTestViSession, array_len, _))
      .With(Args<2, 1>(ElementsAreArray(int16_array)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::ViInt16ArrayInputFunctionRequest request;
  request.mutable_vi()->set_name(session_name);
  request.mutable_an_array()->CopyFrom(google::protobuf::RepeatedField<google::protobuf::int32>(int16_array, int16_array + 4));
  nifake_grpc::ViInt16ArrayInputFunctionResponse response;
  ::grpc::Status status = service.ViInt16ArrayInputFunction(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_SetCustomTypeArray_CallsSetCustomTypeArray)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  ViInt32 number_of_elements = 2;
  CustomStruct cs_array[] = {{5, 8.0}, {15, 19.7}};
  EXPECT_CALL(*library, SetCustomTypeArray(kTestViSession, number_of_elements, _))
      .With(Args<2, 1>(ElementsAreArray(cs_array)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::SetCustomTypeArrayRequest request;
  request.mutable_vi()->set_name(session_name);
  for (int i = 0; i < number_of_elements; i++) {
    request.add_cs();
    request.mutable_cs(i)->set_struct_int(cs_array[i].structInt);
    request.mutable_cs(i)->set_struct_double(cs_array[i].structDouble);
  }
  nifake_grpc::SetCustomTypeArrayResponse response;
  ::grpc::Status status = service.SetCustomTypeArray(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_GetArrayViUInt8WithEnum_CallsGetArrayViUInt8WithEnum)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  int array_len = 3;
  ViUInt8 uint8_array[] = {
      nifake_grpc::GrpcColorOverride::GRPC_COLOR_OVERRIDE_RED,
      nifake_grpc::GrpcColorOverride::GRPC_COLOR_OVERRIDE_BLACK,
      nifake_grpc::GrpcColorOverride::GRPC_COLOR_OVERRIDE_BLUE,
  };
  nifake_grpc::GrpcColorOverride enum_array[] = {
      nifake_grpc::GrpcColorOverride::GRPC_COLOR_OVERRIDE_RED,
      nifake_grpc::GrpcColorOverride::GRPC_COLOR_OVERRIDE_BLACK,
      nifake_grpc::GrpcColorOverride::GRPC_COLOR_OVERRIDE_BLUE,
  };
  EXPECT_CALL(*library, GetArrayViUInt8WithEnum(kTestViSession, array_len, _))
      .WillOnce(
          DoAll(
              SetArrayArgument<2>(uint8_array, uint8_array + array_len),
              Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetArrayViUInt8WithEnumRequest request;
  request.mutable_vi()->set_name(session_name);
  request.set_array_len(array_len);
  nifake_grpc::GetArrayViUInt8WithEnumResponse response;
  ::grpc::Status status = service.GetArrayViUInt8WithEnum(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_THAT(response.u_int8_enum_array(), ElementsAreArray(enum_array, array_len));
  EXPECT_EQ(std::string(uint8_array, uint8_array + array_len), response.u_int8_enum_array_raw());
}

TEST(NiFakeServiceTests, NiFakeService_GetAttributeViSession_ReturnsSessionId)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  nifake_grpc::NiFakeAttribute attribute_id = nifake_grpc::NIFAKE_ATTRIBUTE_READ_WRITE_STRING;
  EXPECT_CALL(*library, GetAttributeViSession(kTestViSession, Pointee(*kTestChannelName), attribute_id, _))
      .WillOnce(
          DoAll(
              SetArgPointee<3>(kTestViSession),
              Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAttributeViSessionRequest request;
  request.mutable_vi()->set_name(session_name);
  request.set_attribute_id(attribute_id);
  request.set_channel_name(kTestChannelName);
  nifake_grpc::GetAttributeViSessionResponse response;
  auto status = service.GetAttributeViSession(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(session_name, response.attribute_value().name());
}

TEST(NiFakeServiceTests, NiFakeExtensionService_CallMethodWithSesionStartedByNIFakeService_PassesThroughSession)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto extension_library = std::make_shared<NiFakeExtensionMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  nifake_extension_grpc::NiFakeExtensionService extension_service(extension_library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  const ViInt32 kParam = 1234;
  EXPECT_CALL(*extension_library, AddCoolFunctionality(kTestViSession, kParam))
      .WillOnce(
          DoAll(
              Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_extension_grpc::AddCoolFunctionalityRequest request;
  request.mutable_vi()->set_name(session_name);
  request.set_param(kParam);
  nifake_extension_grpc::AddCoolFunctionalityResponse response;
  auto status = extension_service.AddCoolFunctionality(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_CallMethodWithReservedPassNullParam_PassesNull)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<NiFakeMockLibrary>();
  auto resource_repository = std::make_shared<FakeResourceRepository>(session_repository);
  nifake_grpc::NiFakeService service(library, resource_repository);
  auto session_name = create_session(library, service, kTestViSession);
  EXPECT_CALL(*library, CommandWithReservedParam(kTestViSession, nullptr))
      .WillOnce(
          DoAll(
              Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::CommandWithReservedParamRequest request;
  request.mutable_vi()->set_name(session_name);
  nifake_grpc::CommandWithReservedParamResponse response;
  auto status = service.CommandWithReservedParam(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

struct FakeServiceHolder {
  FakeServiceHolder()
      : session_repository(std::make_shared<nidevice_grpc::SessionRepository>()),
        library(std::make_shared<NiFakeMockLibrary>()),
        resource_repository(std::make_shared<FakeResourceRepository>(session_repository)),
        service(library, resource_repository)
  {
  }
  std::shared_ptr<nidevice_grpc::SessionRepository> session_repository;
  std::shared_ptr<NiFakeMockLibrary> library;
  std::shared_ptr<FakeResourceRepository> resource_repository;
  nifake_grpc::NiFakeService service;
  grpc::ServerContext context;
};

// "In/Out" ivi-dance-with-a-twist is when the "value_twist" output is also the "value" input,
// I.e., it's a single in/out param instead of a separate input and output.
TEST(NiFakeServiceTests, FakeService_ReadDataWithInOutIviTwist_DoesTwistAndReturnsCorrectData)
{
  const auto BUFFER_SIZE = 10;
  ::google::protobuf::int32 DATA[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  FakeServiceHolder service_holder;
  // First call expects pointer-to-zero and sets the size.
  EXPECT_CALL(*service_holder.library, ReadDataWithInOutIviTwist(nullptr, Pointee(0)))
      .WillOnce(
          DoAll(
              SetArgPointee<1>(BUFFER_SIZE),
              Return(kDriverSuccess)));
  // Second call expects pointer-to-size and sets the output data.
  EXPECT_CALL(*service_holder.library, ReadDataWithInOutIviTwist(_, Pointee(BUFFER_SIZE)))
      .WillOnce(
          DoAll(
              SetArrayArgument<0>(DATA, DATA + BUFFER_SIZE),
              Return(kDriverSuccess)));

  auto request = ReadDataWithInOutIviTwistRequest{};
  auto response = ReadDataWithInOutIviTwistResponse{};
  service_holder.service.ReadDataWithInOutIviTwist(&service_holder.context, &request, &response);

  EXPECT_EQ(0, response.status());
  EXPECT_THAT(response.data(), ElementsAreArray(DATA, BUFFER_SIZE));
}

TEST(NiFakeServiceTests, FakeService_ReadDataWithMultipleIviTwistParamSets_DoesTwistAndReturnsCorrectData)
{
  const auto DATA = std::vector<::google::protobuf::int32>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  const auto OTHER_DATA = std::vector<::google::protobuf::int32>{100, 200, 300, 400};
  FakeServiceHolder service_holder;
  // First call expects pointer-to-zero and sets the size.
  EXPECT_CALL(*service_holder.library, ReadDataWithMultipleIviTwistParamSets(0, nullptr, _, 0, nullptr, _))
      .WillOnce(
          DoAll(
              SetArgPointee<2>(DATA.size()),
              SetArgPointee<5>(OTHER_DATA.size()),
              Return(kDriverSuccess)));
  // Second call expects pointer-to-size and sets the output data.
  EXPECT_CALL(*service_holder.library, ReadDataWithMultipleIviTwistParamSets(static_cast<ViInt32>(DATA.size()), _, _, static_cast<ViInt32>(OTHER_DATA.size()), _, _))
      .WillOnce(
          DoAll(
              SetArrayArgument<1>(DATA.cbegin(), DATA.cend()),
              SetArrayArgument<4>(OTHER_DATA.cbegin(), OTHER_DATA.cend()),
              Return(kDriverSuccess)));

  auto request = ReadDataWithMultipleIviTwistParamSetsRequest{};
  auto response = ReadDataWithMultipleIviTwistParamSetsResponse{};
  service_holder.service.ReadDataWithMultipleIviTwistParamSets(&service_holder.context, &request, &response);

  EXPECT_EQ(0, response.status());
  EXPECT_THAT(response.array_out(), ElementsAreArray(DATA.data(), DATA.size()));
  EXPECT_THAT(response.other_array_out(), ElementsAreArray(OTHER_DATA.data(), OTHER_DATA.size()));
}

TEST(NiFakeServiceTests, FakeService_CreateConfigurationList_PassesAttributeArray)
{
  const auto ATTRIBUTES = std::vector<NiFakeAttribute>{NiFakeAttribute::NIFAKE_ATTRIBUTE_READ_WRITE_BOOL, NiFakeAttribute::NIFAKE_ATTRIBUTE_READ_WRITE_COLOR};
  FakeServiceHolder service_holder;
  EXPECT_CALL(*service_holder.library, CreateConfigurationList(_, _))
      .With(Args<1, 0>(ElementsAreArray(ATTRIBUTES.data(), ATTRIBUTES.size())))
      .WillOnce(Return(kDriverSuccess));

  auto request = CreateConfigurationListRequest{};
  request.mutable_list_attribute_ids()->CopyFrom({ATTRIBUTES.cbegin(), ATTRIBUTES.cend()});
  auto response = CreateConfigurationListResponse{};
  service_holder.service.CreateConfigurationList(&service_holder.context, &request, &response);

  EXPECT_EQ(0, response.status());
}

TEST(NiFakeServiceTests, FakeService_GetCustomStruct_ReturnsCustomStruct)
{
  auto EXPECTED = CustomStruct{};
  EXPECTED.structDouble = 1.234;
  EXPECTED.structInt = 9999;
  FakeServiceHolder service_holder;
  EXPECT_CALL(*service_holder.library, GetCustomType(_, _))
      .WillOnce(DoAll(SetArgPointee<1>(EXPECTED), Return(kDriverSuccess)));

  auto request = GetCustomTypeRequest{};
  auto response = GetCustomTypeResponse{};
  service_holder.service.GetCustomType(&service_holder.context, &request, &response);

  EXPECT_EQ(0, response.status());
  EXPECT_EQ(response.cs(), EXPECTED);
}

TEST(NiFakeServiceTests, FakeService_GetCustomStructWithWarning_ReturnsCustomStruct)
{
  auto EXPECTED = CustomStruct{};
  EXPECTED.structDouble = 1.234;
  EXPECTED.structInt = 9999;
  FakeServiceHolder service_holder;
  EXPECT_CALL(*service_holder.library, GetCustomType(_, _))
      .WillOnce(DoAll(SetArgPointee<1>(EXPECTED), Return(kDriverWarning)));

  auto request = GetCustomTypeRequest{};
  auto response = GetCustomTypeResponse{};
  service_holder.service.GetCustomType(&service_holder.context, &request, &response);

  EXPECT_EQ(kDriverWarning, response.status());
  EXPECT_EQ(response.cs(), EXPECTED);
}

TEST(NiFakeServiceTests, FakeService_SetCustomStruct_PassesCustomStruct)
{
  auto EXPECTED = nifake_grpc::FakeCustomStruct{};
  EXPECTED.set_struct_double(1e6);
  EXPECTED.set_struct_int(500);
  FakeServiceHolder service_holder;
  EXPECT_CALL(*service_holder.library, SetCustomType(_, Eq(EXPECTED)))
      .WillOnce(Return(kDriverSuccess));

  auto request = SetCustomTypeRequest{};
  request.mutable_cs()->CopyFrom(EXPECTED);
  auto response = SetCustomTypeResponse{};
  service_holder.service.SetCustomType(&service_holder.context, &request, &response);

  EXPECT_EQ(0, response.status());
}

TEST(NiFakeServiceTests, FakeService_CustomNestedStructRoundtrip_PassesAndReceivesStruct)
{
  auto EXPECTED_INPUT = nifake_grpc::CustomStructNestedTypedef{};
  auto NESTED_CUSTOM_STRUCT = nifake_grpc::FakeCustomStruct();
  NESTED_CUSTOM_STRUCT.set_struct_double(1e6);
  NESTED_CUSTOM_STRUCT.set_struct_int(500);
  auto NESTED_CUSTOM_STRUCT_TYPEDEF = nifake_grpc::CustomStructTypedef();
  NESTED_CUSTOM_STRUCT_TYPEDEF.set_struct_double(2e6);
  NESTED_CUSTOM_STRUCT_TYPEDEF.set_struct_int(600);
  EXPECTED_INPUT.mutable_struct_custom_struct()->CopyFrom(NESTED_CUSTOM_STRUCT);
  EXPECTED_INPUT.mutable_struct_custom_struct_typedef()->CopyFrom(NESTED_CUSTOM_STRUCT_TYPEDEF);
  auto EXPECTED_OUTPUT = CustomStructNestedTypedef_struct{};
  EXPECTED_OUTPUT.structCustomStruct.structDouble = 1e6;
  EXPECTED_OUTPUT.structCustomStruct.structInt = 500;
  EXPECTED_OUTPUT.structCustomStructTypedef.structDouble = 2e6;
  EXPECTED_OUTPUT.structCustomStructTypedef.structInt = 600;
  FakeServiceHolder service_holder;
  EXPECT_CALL(*service_holder.library, CustomNestedStructRoundtrip(Eq(EXPECTED_INPUT), _))
      .WillOnce(DoAll(SetArgPointee<1>(EXPECTED_OUTPUT), Return(kDriverSuccess)));

  auto request = CustomNestedStructRoundtripRequest{};
  request.mutable_nested_custom_type_in()->CopyFrom(EXPECTED_INPUT);
  auto response = CustomNestedStructRoundtripResponse{};
  service_holder.service.CustomNestedStructRoundtrip(&service_holder.context, &request, &response);

  EXPECT_EQ(0, response.status());
  EXPECT_EQ(response.nested_custom_type_out(), EXPECTED_OUTPUT);
}

TEST(NiFakeServiceTests, GetBitfieldAsEnumArray_ZeroBitfield_ReturnsEmptyArray)
{
  constexpr auto ZERO_BITFIELD = 0x0;
  FakeServiceHolder service_holder;
  EXPECT_CALL(*service_holder.library, GetBitfieldAsEnumArray(_))
      .WillOnce(
          DoAll(
              SetArgPointee<0>(ZERO_BITFIELD),
              Return(kDriverSuccess)));
  auto request = GetBitfieldAsEnumArrayRequest{};
  auto response = GetBitfieldAsEnumArrayResponse{};
  service_holder.service.GetBitfieldAsEnumArray(&service_holder.context, &request, &response);

  EXPECT_EQ(0, response.status());
  EXPECT_THAT(response.flags_array(), IsEmpty());
  EXPECT_EQ(ZERO_BITFIELD, response.flags_raw());
}

TEST(NiFakeServiceTests, GetBitfieldAsEnumArray_MultipleFlagsSet_ReturnsArrayOfFlags)
{
  constexpr google::protobuf::int64 A_AND_C = 0x1ULL | 0x4ULL;
  const auto EXPECTED = std::vector<Bitfield>{Bitfield::BITFIELD_FLAG_A, Bitfield::BITFIELD_FLAG_C};
  FakeServiceHolder service_holder;
  EXPECT_CALL(*service_holder.library, GetBitfieldAsEnumArray(_))
      .WillOnce(
          DoAll(
              SetArgPointee<0>(A_AND_C),
              Return(kDriverSuccess)));
  auto request = GetBitfieldAsEnumArrayRequest{};
  auto response = GetBitfieldAsEnumArrayResponse{};
  service_holder.service.GetBitfieldAsEnumArray(&service_holder.context, &request, &response);

  EXPECT_EQ(0, response.status());
  EXPECT_THAT(
      response.flags_array(),
      ElementsAre(Bitfield::BITFIELD_FLAG_A, Bitfield::BITFIELD_FLAG_C));
  EXPECT_EQ(A_AND_C, response.flags_raw());
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
