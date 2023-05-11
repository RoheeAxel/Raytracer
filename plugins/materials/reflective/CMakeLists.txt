CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -fdiagnostics-color=always -fno-gnu-unique")
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/plugins/materials)

add_library(reflective SHARED
        src/Reflective.cpp
        ${PROJECT_SOURCE_DIR}/src/Prog/Utils/Vec3.cpp
        ${PROJECT_SOURCE_DIR}/src/Prog/Utils/ParsingUtils.cpp
        ${PROJECT_SOURCE_DIR}/src/Prog/Utils/CustomRandom.cpp
        )

set_target_properties(reflective PROPERTIES PREFIX "")

target_include_directories(reflective PRIVATE ${CMAKE_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/src/Prog/Materials
        ${PROJECT_SOURCE_DIR}/src/Prog/Utils
        ${PROJECT_SOURCE_DIR}/src/Prog/Exceptions)