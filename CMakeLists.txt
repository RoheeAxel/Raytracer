cmake_minimum_required(VERSION 3.5)
project("raytracer")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -g")

# Include directories
include_directories("src/Utils")
include_directories("src/Scene")
include_directories("src/Raytracer")
include_directories("src/Lights")
include_directories("src/Shapes")
include_directories("src/Camera")
include_directories("src/Camera/Screen")

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(raytracer ${SOURCES})