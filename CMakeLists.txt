cmake_minimum_required(VERSION 3.24)
project(HelloTask
    LANGUAGES CXX
)

set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 2)
set(PROJECT_VERSION_BUILD 115)

message(PROJECT_SOURCE_DIR="${PROJECT_SOURCE_DIR}")
configure_file(${PROJECT_SOURCE_DIR}/src/versioning/ProjectVersion.h.in ${PROJECT_SOURCE_DIR}/src/versioning/ProjectVersion.h)



set(CMAKE_CXX_STANDARD 23)

add_executable(HelloTask src/main.cpp)

target_include_directories(HelloTask PRIVATE src)





