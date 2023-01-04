cmake_minimum_required(VERSION 3.25)
project(thread)

set(CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER C:/MinGW/MinGW/bin/g++.exe)

set(CMAKE_BUILD_TYPE Debug)

add_compile_options(-Wall)
add_executable(thread main.cpp Thread.cpp Thread.h)
#target_link_libraries(pthread.h)