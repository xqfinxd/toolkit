cmake_minimum_required(VERSION 3.10)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED 11)

# main project
include_directories($ENV{VULKAN_SDK}/Include)
link_directories($ENV{VULKAN_SDK}/Lib32)

project(sandbox)
add_executable(sandbox main.cc)

target_include_directories(sandbox PUBLIC
    "${PROJECT_BINARY_DIR}"
)

target_link_libraries(sandbox PUBLIC
    "vulkan-1.lib"
)

configure_file("test_config.h.cmake"
    "test_config.h" COPYONLY)