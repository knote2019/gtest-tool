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
set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-std=c++17 -pthread -fpic")
set(CMAKE_BUILD_TYPE Debug)
# target_sources: Convert relative paths to absolute.
if(POLICY CMP0076)
    cmake_policy(SET CMP0076 NEW)
endif()

# set GLIBCXX_USE_CXX11_ABI.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_USE_CXX11_ABI=1")

# set openmp.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

#-----------------------------------------------------------------------------------------------------------------------
# 3pp.

#-----------------------------------------------------------------------------------------------------------------------
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
target_link_libraries(runTests PUBLIC
        "")
