cmake_minimum_required(VERSION 3.7)

project(master_test C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -pedantic -march=native -pthread")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_DEBUG_POSTFIX "_d")

add_subdirectory(src/array_list)
add_subdirectory(src/link_list)
add_subdirectory(src/multithreading)
add_subdirectory(src/stack)
add_subdirectory(src/special_pointer)

add_executable(array_list_test src/main_array_list.c)
target_link_libraries(array_list_test m array_list)

add_executable(link_list_test src/main_link_list.c)
target_link_libraries(link_list_test link_list)

add_executable(multithreading_exe src/main_multithreading.c)
target_link_libraries(multithreading_exe multithreading)

add_executable(stack_exe src/main_stack.c)
target_link_libraries(stack_exe stack_queue)