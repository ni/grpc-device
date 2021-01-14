add_executable(UnitTests RunAllGoogleTests.cpp SampleGoogleTestCase.cpp)

# Link test executable against gtest
target_link_libraries(UnitTests gtest)

# Add test so the google test runner hooks up to CTest
add_test( NAME UnitTests COMMAND UnitTests )