cmake_minimum_required(VERSION 3.5.1)

project(Main C CXX)

add_executable(Main Source/main.cpp)

add_subdirectory(./third_party/gtest ${CMAKE_CURRENT_BINARY_DIR}/gtest} EXCLUDE_FROM_ALL)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
enable_testing()
add_subdirectory(Tests)