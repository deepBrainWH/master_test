cmake_minimum_required(VERSION 3.7)

project(master_test C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -pedantic")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)


add_subdirectory(src/array_list)
add_subdirectory(src/link_list)


add_executable(array_list_test ./src/main.c)
add_executable(link_list_test ./src/main2.c)
target_link_libraries(array_list_test m array_list link_list)