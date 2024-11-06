cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 23)

project(HelloTask
    LANGUAGES CXX
)

option(WITH_BOOST_TEST "Whether to build Boost test" ON)

if(WITH_BOOST_TEST)
    add_subdirectory(tests/boost)
endif()

#https://webhostinggeeks.com/howto/how-to-upgrade-gcc-on-ubuntu/
if (CMAKE_COMPILER_IS_GNUCXX AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 13.1)
    message(FATAL_ERROR "Require at least gcc-13.1")
endif()

set(PROJECT_VERSION_MAJOR ${HW0_PROJECT_VERSION_MAJOR})
set(PROJECT_VERSION_MINOR ${HW0_PROJECT_VERSION_MINOR})
set(PROJECT_VERSION_BUILD ${HW0_PROJECT_VERSION_BUILD})

configure_file(${PROJECT_SOURCE_DIR}/src/versioning/ProjectVersion.h.in ${PROJECT_SOURCE_DIR}/src/versioning/ProjectVersion.h)

add_executable(HelloTask src/main.cpp
        src/versioning/Version.h)

if (DEFINED HW0_INSTALL_PREFIX)
    set(CMAKE_INSTALL_PREFIX ${HW0_INSTALL_PREFIX})
    install(TARGETS HelloTask DESTINATION ${CMAKE_INSTALL_PREFIX})
else()
    set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)
    install(TARGETS HelloTask DESTINATION ${PROJECT_SOURCE_DIR}/install)
endif (DEFINED HW0_INSTALL_PREFIX)
message("-- Install prefix is: ${CMAKE_INSTALL_PREFIX}")


#if(WITH_BOOST_TEST)
#    find_package(Boost COMPONENTS unit_test_framework REQUIRED)
#    add_executable(test_version test_version.cpp
#            tests/boost/version/test_version.cpp)
#
#    set_target_properties(test_version PROPERTIES
#            CXX_STANDARD 23
#            CXX_STANDARD_REQUIRED ON
#    )
#
#    set_target_properties(test_version PROPERTIES
#            COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
#            INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
#    )
#
#    target_link_libraries(test_version
#            ${Boost_LIBRARIES}
#            helloworld
#    )
#endif()

target_include_directories(HelloTask PRIVATE src)





