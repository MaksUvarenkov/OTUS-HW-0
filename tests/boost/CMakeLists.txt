set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

add_executable (${BOOST_TESTS_EXEC_NAME} version/test_version.cpp)
target_link_libraries (${BOOST_TESTS_EXEC_NAME} ${Boost_LIBRARIES})
target_include_directories(${BOOST_TESTS_EXEC_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src)

add_test(
        NAME ${BOOST_TESTS_EXEC_NAME}
        COMMAND ${BOOST_TESTS_EXEC_NAME}
)

add_custom_command(
        TARGET ${BOOST_TESTS_EXEC_NAME}
        COMMENT "Run tests"
        POST_BUILD
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${BOOST_TESTS_EXEC_NAME}
)