cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 23)


project(HelloTask
    LANGUAGES CXX
)

#https://webhostinggeeks.com/howto/how-to-upgrade-gcc-on-ubuntu/
if (CMAKE_COMPILER_IS_GNUCXX AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 13.1)
    message(FATAL_ERROR "Require at least gcc-13.1")
endif()

set(PROJECT_VERSION_MAJOR ${HW0_PROJECT_VERSION_MAJOR})
set(PROJECT_VERSION_MINOR ${HW0_PROJECT_VERSION_MINOR})
set(PROJECT_VERSION_BUILD ${HW0_PROJECT_VERSION_BUILD})

set(HW0_DEFAULT_INSTALL_PREFIX install/hw0)

configure_file(${PROJECT_SOURCE_DIR}/src/versioning/ProjectVersion.h.in ${PROJECT_SOURCE_DIR}/src/versioning/ProjectVersion.h)

if (DEFINED HW0_INSTALL_PREFIX)
    set(CMAKE_INSTALL_PREFIX ${HW0_INSTALL_PREFIX})
endif (DEFINED HW0_INSTALL_PREFIX)

add_executable(HelloTask src/main.cpp
        src/versioning/Version.h)

target_include_directories(HelloTask PRIVATE src)





