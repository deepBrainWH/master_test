set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -pedantic -march=native")

#include_directories(/home/wangheng/app/opencv4/include/opencv4)
#link_directories("/home/wangheng/app/opencv4/lib")
set(OpenCV_DIR "/Users/wangheng/app/opencv3/share/OpenCV")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


add_executable(mat_mask_operation mat_mask_operation.cc)
target_link_libraries(mat_mask_operation ${OpenCV_LIBS})
#target_link_libraries(mat_mask_operation -lopencv_core -lopencv_imgproc -lopencv_imgcodecs
#        -lopencv_highgui)
