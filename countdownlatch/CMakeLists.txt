cmake_minimum_required(VERSION 3.25)
project(operator)

set(CXX_STANDARD 17)
add_compile_options(-Wall -g)

add_executable(operator operator.cpp)
#target_link_libraries(../threadtest2/Thread.h)