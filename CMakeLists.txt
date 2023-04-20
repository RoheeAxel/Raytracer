cmake_minimum_required(VERSION 3.5)
project("raytracer")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -g -pthread")

# Include directories
include_directories("src/Utils")

include_directories("src/Scene")

include_directories("src/Raytracer")

include_directories("src/Lights")
include_directories("src/Lights/PointLight")
include_directories("src/Lights/DirLight")

include_directories("src/Shapes")
include_directories("src/Shapes/Sphere")

include_directories("src/Camera")

include_directories("src/Camera/Screen")

include_directories("src/Materials")
include_directories("src/Materials/Plastic")

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(raytracer ${SOURCES})