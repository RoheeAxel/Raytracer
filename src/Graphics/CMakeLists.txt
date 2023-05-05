cmake_minimum_required(VERSION 3.5)
project(graphics)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -g -pthread -fdiagnostics-color=always")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/src/Graphics/Button)
include_directories(${CMAKE_SOURCE_DIR}/src/Graphics/ClusterWindow)
include_directories(${CMAKE_SOURCE_DIR}/src/Graphics/ImagePpm)
include_directories(${CMAKE_SOURCE_DIR}/src/Graphics/Input)
include_directories(${CMAKE_SOURCE_DIR}/src/Graphics/MainWindow)
include_directories(${CMAKE_SOURCE_DIR}/src/Graphics/ThreadWindow)

include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Camera)
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Camera/Screen)

include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Factories)
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Factories/Shape)
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Factories/Light)
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Factories/Material)

include_directories(${CMAKE_SOURCE_DIR}/src/Prog/ITexture)
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/ITexture/Dammier)

include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Exceptions)

include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Lights)
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Lights/DirLight)
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Lights/PointLight)
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Lights/AmbientLight)

include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Materials)
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Materials/Lambertian)
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Materials/Normal)
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Materials/Plastic)
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Materials/Glass)
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Materials/Emitive)

include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Network)

include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Parser)

include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Scene)

include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Shapes)
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Shapes/Quad)
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Shapes/Sphere)
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Shapes/Triangle)
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Shapes/Plan)
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Shapes/BVH)
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Shapes/AABB)

include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Utils)

include_directories(${CMAKE_SOURCE_DIR}/src/Graphics/Raytracer)

# Find and install Zenity package
if(UNIX)
    if(EXISTS "/etc/lsb-release")
        execute_process(COMMAND grep "DISTRIB_ID" "/etc/lsb-release" OUTPUT_VARIABLE LSB_RELEASE_ID)
        string(REGEX REPLACE "DISTRIB_ID=([^\n]+)\n" "\\1" LSB_RELEASE_ID "${LSB_RELEASE_ID}")
        if("${LSB_RELEASE_ID}" STREQUAL "Ubuntu")
            execute_process(COMMAND apt-get install zenity)
        elseif(EXISTS "/etc/fedora-release")
            execute_process(COMMAND dnf install zenity)
        endif()
    endif()
endif()

file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/Graphics/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/Prog/Camera/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/Prog/Exceptions/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/Prog/Factories/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/Prog/ITexture/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/Prog/Lights/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/Prog/Materials/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/Prog/Parser/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/Prog/Scene/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/Prog/Shapes/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/Prog/Utils/*.cpp")
add_executable(graphics ${SOURCES})

find_package(SFML REQUIRED COMPONENTS graphics window system)
target_link_libraries(graphics config++)
target_link_libraries(graphics sfml-graphics sfml-window sfml-system)
set_target_properties(graphics PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")
