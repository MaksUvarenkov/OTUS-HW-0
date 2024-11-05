cmake_minimum_required(VERSION 3.24)

project(HelloTask
    LANGUAGES CXX
)

#https://webhostinggeeks.com/howto/how-to-upgrade-gcc-on-ubuntu/
if (CMAKE_COMPILER_IS_GNUCXX AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 13.1)
    message(FATAL_ERROR "Require at least gcc-13.1")
endif()

set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 119)
set(PROJECT_VERSION_BUILD 115)

message(PROJECT_SOURCE_DIR="${PROJECT_SOURCE_DIR}")
configure_file(${PROJECT_SOURCE_DIR}/src/versioning/ProjectVersion.h.in ${PROJECT_SOURCE_DIR}/src/versioning/ProjectVersion.h)


set(CMAKE_CXX_STANDARD 23)

add_executable(HelloTask src/main.cpp
        src/versioning/Version.h)

target_include_directories(HelloTask PRIVATE src)





