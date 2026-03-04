cmake_minimum_required(VERSION 3.21)

# Set the path to the vcpkg toolchain file (optional, for standalone builds)
if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      CACHE STRING "")
endif()

project(var
    VERSION 1.2.0
    LANGUAGES CXX
    DESCRIPTION "JavaScript-like variant type for C++")

# Options: when used as FetchContent subproject, tests/examples are OFF by default
if(NOT DEFINED VAR_BUILD_TESTS)
  if(PROJECT_IS_TOP_LEVEL)
    set(VAR_BUILD_TESTS ON)
  else()
    set(VAR_BUILD_TESTS OFF)
  endif()
endif()
option(VAR_BUILD_TESTS "Build the test suite" ${VAR_BUILD_TESTS})

if(NOT DEFINED VAR_BUILD_EXAMPLES)
  if(PROJECT_IS_TOP_LEVEL)
    set(VAR_BUILD_EXAMPLES ON)
  else()
    set(VAR_BUILD_EXAMPLES OFF)
  endif()
endif()
option(VAR_BUILD_EXAMPLES "Build the example executable" ${VAR_BUILD_EXAMPLES})

# Core library (always built)
add_subdirectory(src)

# Optional components
if(VAR_BUILD_EXAMPLES)
  add_subdirectory(example)
endif()

if(VAR_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

# Install and package config
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

install(
    TARGETS var
    EXPORT var-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(
    EXPORT var-targets
    NAMESPACE var::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/var
)

export(
    EXPORT var-targets
    NAMESPACE var::
)

export(PACKAGE var)

configure_package_config_file(
    cmake/var-config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/var-config.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/var
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/var-config.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/var
)
