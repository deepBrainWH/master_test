set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_COMPILER /usr/bin/g++)

add_executable(queue_t_main_cc main_queue.cpp)
target_link_libraries(queue_t_main_cc queue_cc_lib)
target_include_directories(queue_t_main_cc PUBLIC
        ../queue_cc)
