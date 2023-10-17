cmake_minimum_required(VERSION 3.27)

# Define the library
add_library(var STATIC
    var.cpp
#    vmap.cpp
)

# Define the include DIRs
target_include_directories(var PUBLIC
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
)

# Install the library and headers
install(TARGETS var
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY ../include/ DESTINATION include)
