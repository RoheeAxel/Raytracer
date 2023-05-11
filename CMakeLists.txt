cmake_minimum_required(VERSION 3.5)
project(final)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -fdiagnostics-color=always")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(src/Prog)
# add_subdirectory(src/Viewer)
# add_subdirectory(src/Graphics)

add_subdirectory(plugins/materials/reflective)
