cmake_minimum_required(VERSION 3.14)
project(master_test C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -pedantic")

add_executable(master_test main.c link_list.h link_list.c array_list.c array_list.h)
target_link_libraries(master_test m)