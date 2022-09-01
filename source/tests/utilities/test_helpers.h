#ifndef TEST_HELPERS
#define TEST_HELPERS

#include <gtest/gtest.h>  // For EXPECT matchers

#include "client_helpers.h"

inline void expect_driver_error(const nidevice_grpc::experimental::client::grpc_driver_error& ex, int32_t expected_error)
{
  EXPECT_EQ(::grpc::StatusCode::UNKNOWN, ex.StatusCode());
  EXPECT_LT(expected_error, 0);
  const auto& actual_error = ex.Trailers().find("ni-error")->second;
  EXPECT_EQ(expected_error, std::stoi(actual_error));
}

#endif
