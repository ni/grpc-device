cmake_minimum_required(VERSION 3.5.1)

project(Main C CXX)

add_executable(Main Source/main.cpp)

# Add googletest unit tests
enable_testing()
add_subdirectory(third_party/gtest ${CMAKE_CURRENT_BINARY_DIR}/gtest} EXCLUDE_FROM_ALL)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_executable(UnitTests Tests/RunAllGoogleTests.cpp Tests/SampleGoogleTestCase.cpp)

# Link test executable against gtest
target_link_libraries(UnitTests gtest)

# Add test so the google test runner hooks up to CTest
add_test( NAME UnitTests COMMAND UnitTests )