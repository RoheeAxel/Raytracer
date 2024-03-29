CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -fdiagnostics-color=always -fno-gnu-unique")
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/plugins/shapes)

add_library(lcone SHARED
        src/lCone.cpp
        ${PROJECT_SOURCE_DIR}/src/Prog/Utils/Ray.cpp
        ${PROJECT_SOURCE_DIR}/src/Prog/Utils/Vec3.cpp
        ${PROJECT_SOURCE_DIR}/src/Prog/Utils/ParsingUtils.cpp
        ${PROJECT_SOURCE_DIR}/src/Prog/Utils/CustomRandom.cpp
        ${PROJECT_SOURCE_DIR}/src/Prog/Shapes/AShape.cpp
        )

set_target_properties(lcone PROPERTIES PREFIX "")

target_include_directories(lcone PRIVATE ${CMAKE_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/src/Prog/Shapes
        ${PROJECT_SOURCE_DIR}/src/Prog/Shapes/AABB
        ${PROJECT_SOURCE_DIR}/src/Prog/Utils
        ${PROJECT_SOURCE_DIR}/src/Prog/Exceptions
        ${PROJECT_SOURCE_DIR}/src/Prog/Materials)