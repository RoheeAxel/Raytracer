cmake_minimum_required(VERSION 3.5)
project(viewer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -g -fdiagnostics-color=always")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/src/Graphics)
include_directories(${CMAKE_SOURCE_DIR}/src/Viewer)

file(GLOB_RECURSE SOURCES "*.cpp")
add_executable(viewer ${SOURCES})

find_package(SFML REQUIRED COMPONENTS graphics window system)
target_link_libraries(viewer sfml-graphics sfml-window sfml-system)
set_target_properties(viewer PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")
