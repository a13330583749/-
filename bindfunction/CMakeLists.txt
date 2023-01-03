cmake_minimum_required(VERSION 3.1)

project(bindfunction)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER "g++")
add_compile_options(-Wall -g)

add_executable(main main.cpp)