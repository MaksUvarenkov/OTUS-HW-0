cmake_minimum_required(VERSION 3.24)

#https://stackoverflow.com/questions/73952766/code-wont-run-after-run-task-error-invalid-value-c23-in-std-c
# We can't use C++23 for now with clang-tidy-15 for example
# That's why static analyser is disabled here.
# And std::from_chars has constexpr variant in C++23 only. I like it.
set(CMAKE_CXX_STANDARD 23)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(HelloTask
    LANGUAGES CXX
)

option(WITH_BOOST_TEST "Whether to build Boost test" ON)
option(WITH_DEFAULT_NON_ZERO_BUILD_NUMBER "Clion config helper for the tests to automatically pass" ON)

#Check the build

#https://webhostinggeeks.com/howto/how-to-upgrade-gcc-on-ubuntu/
if (CMAKE_COMPILER_IS_GNUCXX AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 13.1)
    message(FATAL_ERROR "Require at least gcc-13.1")
endif()

set(DEFAULT_PROJECT_VERSION_MAJOR 1)
set(DEFAULT_PROJECT_VERSION_MINOR 119)

if(WITH_DEFAULT_NON_ZERO_BUILD_NUMBER)
    set(DEFAULT_PROJECT_VERSION_BUILD 117)
else()
    set(DEFAULT_PROJECT_VERSION_BUILD 0)
endif()

if (DEFINED HW0_PROJECT_VERSION_MAJOR)
    set(PROJECT_VERSION_MAJOR ${HW0_PROJECT_VERSION_MAJOR})
else ()
    set(PROJECT_VERSION_MAJOR ${DEFAULT_PROJECT_VERSION_MAJOR})
endif ()

if (DEFINED HW0_PROJECT_VERSION_MINOR)
    set(PROJECT_VERSION_MINOR ${HW0_PROJECT_VERSION_MINOR})
else ()
    set(PROJECT_VERSION_MINOR ${DEFAULT_PROJECT_VERSION_MINOR})
endif ()

if (DEFINED HW0_PROJECT_VERSION_BUILD)
    set(PROJECT_VERSION_BUILD ${HW0_PROJECT_VERSION_BUILD})
else ()
    set(PROJECT_VERSION_BUILD ${DEFAULT_PROJECT_VERSION_BUILD})
endif ()

set(DEFAULT_TARGET_NAME HelloTask)
set(DEFAULT_BOOST_TESTS_NAME BoostRunTests)

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

add_executable(${TARGET_EXEC_NAME} src/main.cpp)
target_include_directories(${TARGET_EXEC_NAME} PRIVATE src)

set(TARGET_LIST ${TARGET_EXEC_NAME})

if(WITH_BOOST_TEST)
    add_subdirectory(tests/boost)
    set(TARGET_LIST ${TARGET_LIST} "${BOOST_TESTS_EXEC_NAME}")
    #    How to add it properly in top-level CmakeLists,txt?
    add_dependencies(${TARGET_EXEC_NAME} ${BOOST_TESTS_EXEC_NAME})
    message("-- Adding tests")
    enable_testing()
endif()


if (DEFINED HW0_INSTALL_PREFIX)
    set(CMAKE_INSTALL_PREFIX ${HW0_INSTALL_PREFIX})
    install(TARGETS ${TARGET_LIST} DESTINATION ${CMAKE_INSTALL_PREFIX})
else()
    set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)
    install(TARGETS ${TARGET_LIST} DESTINATION ${PROJECT_SOURCE_DIR}/install)
endif (DEFINED HW0_INSTALL_PREFIX)
message("-- Install prefix is: ${CMAKE_INSTALL_PREFIX}")

