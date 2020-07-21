set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -pedantic -march=native")

include_directories(/home/wangheng/app/opencv4/include/opencv4)
link_directories("/home/wangheng/app/opencv4/lib")

add_executable(mat_mask_operation mat_mask_operation.cc)
target_link_libraries(mat_mask_operation -lopencv_core -lopencv_imgproc -lopencv_imgcodecs
        -lopencv_highgui)
