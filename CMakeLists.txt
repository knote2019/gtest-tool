#-----------------------------------------------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.19 FATAL_ERROR)
project(gtest_tool LANGUAGES CXX VERSION 1.0.0)

# host information.
message("=============================================================")
cmake_host_system_information(RESULT HOSTNAME QUERY HOSTNAME)
message("hostname: ${HOSTNAME}")
message("rootpath: ${PROJECT_SOURCE_DIR}")
message("=============================================================")

# c++ settings.
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-std=c++17 -pthread")

# enable debug.
set(CMAKE_BUILD_TYPE Debug)
# used for add_library.
add_definitions(-fPIC)
# Convert relative paths to absolute for subdirectory `target_sources`
if(POLICY CMP0076)
    cmake_policy(SET CMP0076 NEW)
endif()

# set target.
add_executable(runTests)
target_include_directories(runTests PUBLIC
        gtest
        gtest/include
        include
        )
file(GLOB_RECURSE TEST_SRCS src/*.cpp)
target_sources(runTests PUBLIC
        gtest/src/gtest_main.cc
        gtest/src/gtest-all.cc
        ${TEST_SRCS}
        )
