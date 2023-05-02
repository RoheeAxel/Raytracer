cmake_minimum_required(VERSION 3.5)
project(raytracer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -g -pthread -fdiagnostics-color=always")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(Camera)
include_directories(Camera/Screen)

include_directories(Lights)
include_directories(Lights/DirLight)
include_directories(Lights/PointLight)
include_directories(Lights/AmbientLight)

include_directories(Materials)
include_directories(Materials/Lambertian)
include_directories(Materials/Normal)
include_directories(Materials/Plastic)
include_directories(Materials/Glass)

include_directories(Raytracer)

include_directories(Scene)

include_directories(Shapes)
include_directories(Shapes/Sphere)
include_directories(Shapes/Plan)

include_directories(Utils)

file(GLOB_RECURSE SOURCES "*.cpp")
add_executable(raytracer ${SOURCES})
set_target_properties(raytracer PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")
