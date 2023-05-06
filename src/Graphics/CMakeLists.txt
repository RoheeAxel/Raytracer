cmake_minimum_required(VERSION 3.5)
project(graphics)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -g -pthread -fdiagnostics-color=always")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Camera)
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Camera/Screen)

include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Lights)
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Lights/DirLight)
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Lights/PointLight)

include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Materials)
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Materials/Lambertian)
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Materials/Normal)
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Materials/Reflective)

include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Raytracer)

include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Scene)

include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Shapes)
include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Shapes/Sphere)

include_directories(${CMAKE_SOURCE_DIR}/src/Prog/Utils)

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

file(GLOB_RECURSE SOURCES "*.cpp")
add_executable(graphics ${SOURCES})

find_package(SFML REQUIRED COMPONENTS graphics window system)
target_link_libraries(graphics sfml-graphics sfml-window sfml-system)
set_target_properties(graphics PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")
