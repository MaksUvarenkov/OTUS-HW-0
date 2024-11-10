cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 23)

project(HelloTask
    LANGUAGES CXX
)

option(WITH_BOOST_TEST "Whether to build Boost test" ON)

#https://webhostinggeeks.com/howto/how-to-upgrade-gcc-on-ubuntu/
if (CMAKE_COMPILER_IS_GNUCXX AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 13.1)
    message(FATAL_ERROR "Require at least gcc-13.1")
endif()

set(PROJECT_VERSION_MAJOR ${HW0_PROJECT_VERSION_MAJOR})
set(PROJECT_VERSION_MINOR ${HW0_PROJECT_VERSION_MINOR})
set(PROJECT_VERSION_BUILD ${HW0_PROJECT_VERSION_BUILD})

set(DEFAULT_TARGET_NAME HelloTask)
set(DEFAULT_BOOST_TESTS_NAME BoostTestsRun)

configure_file(${PROJECT_SOURCE_DIR}/src/versioning/ProjectVersion.h.in ${PROJECT_SOURCE_DIR}/src/versioning/ProjectVersion.h)

if (DEFINED MAIN_TARGET_EXECUTABLE_NAME)
    set(TARGET_EXEC_NAME ${MAIN_TARGET_EXECUTABLE_NAME})
else()
    set(TARGET_EXEC_NAME ${DEFAULT_TARGET_NAME})
endif()

if (DEFINED BOOST_TESTS_EXEC_NAME)
    set(BOOST_TESTS_EXEC_NAME ${BOOST_TESTS_EXEC_NAME} CACHE INTERNAL "")
else()
    set(BOOST_TESTS_EXEC_NAME ${DEFAULT_BOOST_TESTS_NAME} CACHE INTERNAL "")
endif()

message("-- Target name: ${TARGET_EXEC_NAME}")
message("-- Boost tests name: ${BOOST_TESTS_EXEC_NAME}")


add_executable(${TARGET_EXEC_NAME} src/main.cpp
        src/versioning/Version.h)

if(WITH_BOOST_TEST)
    message("Adding tests")
    add_subdirectory(tests/boost)
#    How to add it properly in top-level CmakeLists,txt?
    add_dependencies(${TARGET_EXEC_NAME} ${BOOST_TESTS_EXEC_NAME})
endif()


if (DEFINED HW0_INSTALL_PREFIX)
    set(CMAKE_INSTALL_PREFIX ${HW0_INSTALL_PREFIX})
    install(TARGETS ${TARGET_EXEC_NAME} ${BOOST_TESTS_EXEC_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX})
else()
    set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)
    install(TARGETS ${TARGET_EXEC_NAME} ${BOOST_TESTS_EXEC_NAME} DESTINATION ${PROJECT_SOURCE_DIR}/install)
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





