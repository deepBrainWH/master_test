set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -pedantic -march=native")

add_library(link_list STATIC link_list.h link_list.c)
target_link_libraries(link_list stack_queue)