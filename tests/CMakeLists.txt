find_package(GTest CONFIG QUIET)

if(NOT GTest_FOUND)
  message(STATUS "GTest not found - skipping tests. Set VAR_BUILD_TESTS=OFF or provide GTest via vcpkg.")
  return()
endif()

add_executable(var_test
    var_constructor_test.cpp
    var_type_conversion_test.cpp
    var_arithmetic_test.cpp
    var_comparison_test.cpp
    var_methods_test.cpp
    var_exception_test.cpp
)

target_include_directories(var_test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_link_libraries(var_test PRIVATE
    var
    GTest::gtest
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(var_test)
