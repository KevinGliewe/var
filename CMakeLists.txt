cmake_minimum_required(VERSION 3.27)

# Set the path to the vcpkg toolchain file
if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "")
endif()

project(var
        VERSION 1.2.0
        LANGUAGES CXX)

# Enable testing
enable_testing()

# Add the var library
add_subdirectory(src)

# Add the example project
add_subdirectory(example)

# Add the tests project
add_subdirectory(tests)

# Find gtest
find_package(GTest CONFIG)

# Install the include directory
install(DIRECTORY include/ DESTINATION include)

# Install the library

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

install(
    TARGETS
        var
    EXPORT 
        var-targets)

install(
    EXPORT var-targets
    NAMESPACE var::
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/var")

export(
    EXPORT var-targets
    NAMESPACE var::)

export(PACKAGE var)

configure_package_config_file(cmake/var-config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/var-config.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/var"
)

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/var-config.cmake"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/var")