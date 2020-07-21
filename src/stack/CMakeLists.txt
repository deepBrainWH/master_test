set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_COMPILER /usr/bin/g++)

add_library(stack_queue STATIC stack_queue.h stack_queue.c)