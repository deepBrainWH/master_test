cmake_minimum_required(VERSION 3.14)
project(master_test C)

set(CMAKE_C_STANDARD 99)

add_executable(master_test main.c single_direct_linked_list.h single_direct_linked_list.c array_list.c array_list.h)