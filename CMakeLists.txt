cmake_minimum_required(VERSION 3.24)
project(HelloTask)

set(CMAKE_CXX_STANDARD 23)

add_executable(HelloTask src/main.cpp src/templates/singleton/Singleton.h)


target_include_directories(HelloTask PRIVATE src)