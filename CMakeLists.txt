cmake_minimum_required(VERSION 3.10)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED 11)

project(sandbox)

if(NOT DEFINED ${CMAKE_BUILD_TYPE})
    SET(CMAKE_BUILD_TYPE "Debug")
endif()

if(WIN32 AND (${CMAKE_GENERATOR} STREQUAL "MinGW Makefiles"
    OR ${CMAKE_GENERATOR} STREQUAL "MSYS Makefiles"))
    SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
    SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
endif()
if(NOT WIN32)
    SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
    SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third-party/lua-5.4.0/)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third-party/lua-5.4.0/include)

add_executable(sandbox main.cc)

target_include_directories(sandbox
    INTERFACE ${PROJECT_BINARY_DIR}
)

target_link_libraries(sandbox
    PUBLIC lua
)

configure_file("test_config.h.cmake"
    "test_config.h" COPYONLY)
