cmake_minimum_required(VERSION 3.5)
project("raytracer")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -g")

include_directories("src/Utils")
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(raytracer ${SOURCES})