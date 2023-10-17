cmake_minimum_required(VERSION 3.27)

# Find gtest
find_package(GTest CONFIG)

if (GTest_FOUND)

# Find all cpp files for the tests
file(GLOB_RECURSE var_test_cpp
    "./**.cpp"
)

# Define the test executable
add_executable(var_test
    ${var_test_cpp}
)

target_include_directories(var_test PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
    $<INSTALL_INTERFACE:include>
)

# Link gtest and gtest_main
target_link_libraries(var_test
    var
    GTest::gtest
    GTest::gtest_main
)

# Discover tests
include(GoogleTest)
gtest_discover_tests(var_test)

endif()
