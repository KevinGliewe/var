cmake_minimum_required(VERSION 3.27)

# Define the example executable
add_executable(example
    main.cpp
)

target_include_directories(example PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(example
    var
)