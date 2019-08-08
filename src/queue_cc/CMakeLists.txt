set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_COMPILER /usr/bin/g++)

add_library(queue_cc_lib STATIC MyQueue1.h MyQueue1.cpp)