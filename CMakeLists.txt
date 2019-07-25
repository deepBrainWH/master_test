cmake_minimum_required(VERSION 3.7)

project(master_test)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_DEBUG_POSTFIX "_d")

set(CMAKE_SYSTEM_NAME Linux)

add_subdirectory(src/array_list)
add_subdirectory(src/link_list)
add_subdirectory(src/multithreading)
add_subdirectory(src/stack)
add_subdirectory(src/special_pointer)
add_subdirectory(src/t_main)
add_subdirectory(src/cc)