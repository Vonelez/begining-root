cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(events)

add_executable(main.cpp src/generate_event.cpp src/read_data.cpp)

set(CMAKE_CXX_STANDARD 14)

list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})

find_package(ROOT REQUIRED COMPONENTS RIO Net)

include(${ROOT_USE_FILE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
