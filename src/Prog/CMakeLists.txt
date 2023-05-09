cmake_minimum_required(VERSION 3.5)
project(raytracer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -g -fdiagnostics-color=always -Ofast")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(Camera)
include_directories(Camera/Screen)

include_directories(Exceptions)

include_directories(Factories)
include_directories(Factories/Material)
include_directories(Factories/Light)
include_directories(Factories/Shape)

include_directories(Lights)
include_directories(Lights/DirLight)
include_directories(Lights/PointLight)
include_directories(Lights/AmbientLight)

include_directories(Materials)
include_directories(Materials/Lambertian)
include_directories(Materials/Normal)
include_directories(Materials/Glass)
include_directories(Materials/Emitive)

include_directories(Parser)

include_directories(Raytracer)

include_directories(Scene)

include_directories(Shapes)
include_directories(Shapes/Sphere)
include_directories(Shapes/Plan)
include_directories(Shapes/AABB)
include_directories(Shapes/BVH)
include_directories(Shapes/Triangle)
include_directories(Shapes/Quad)
include_directories(Shapes/Cylinder)
# include_directories(Shapes/OBJ)

include_directories(ITexture)
include_directories(ITexture/Dammier)
include_directories(ITexture/Image)

include_directories(Utils)

file(GLOB_RECURSE SOURCES "*.cpp")
add_executable(raytracer ${SOURCES})

target_link_libraries(raytracer pthread)
target_link_libraries(raytracer dl)
target_link_libraries(raytracer config++)
target_link_libraries(raytracer sfml-system)
target_link_libraries(raytracer sfml-network)

set_target_properties(raytracer PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")
