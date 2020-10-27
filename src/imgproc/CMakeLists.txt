set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -pedantic -march=native")

#include_directories(/home/wangheng/app/opencv4/include/opencv4)
#link_directories("/home/wangheng/app/opencv4/lib")
#set(OpenCV_DIR "/Users/wangheng/app/opencv3/share/OpenCV")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


add_executable(mat_mask_operation mat_mask_operation.cc)
target_link_libraries(mat_mask_operation ${OpenCV_LIBS})

add_executable(video2imageSequence video2imageSequence.cpp)
target_link_libraries(video2imageSequence ${OpenCV_LIBS})

add_executable(moving_object_detect moving_object_detect.cpp)
target_link_libraries(moving_object_detect ${OpenCV_LIBS})


add_executable(ros_region roi_region.cpp)
target_link_libraries(ros_region ${OpenCV_LIBS})