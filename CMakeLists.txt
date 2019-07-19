cmake_minimum_required(VERSION 3.7)

project(master_test C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -pedantic")

aux_source_directory(./src SRC)
add_subdirectory(src/array_list)

add_executable(master_test ${SRC})
target_link_libraries(master_test m array_list)