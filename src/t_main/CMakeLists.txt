set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -pedantic -march=native")

add_executable(array_list_test main_array_list.c)
target_link_libraries(array_list_test m array_list)
target_include_directories(array_list_test PRIVATE
        ../../src/array_list)

add_executable(link_list_test main_link_list.c)
target_link_libraries(link_list_test link_list)
target_include_directories(link_list_test PRIVATE
        ../link_list)

add_executable(multithreading_exe main_multithreading.c)
target_link_libraries(multithreading_exe multithreading)

add_executable(stack_exe main_stack.c)
target_link_libraries(stack_exe stack_queue)