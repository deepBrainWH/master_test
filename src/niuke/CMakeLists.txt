add_executable(niuke src/course1/main.cc dynamic.h)
target_link_libraries(niuke -lopencv_dnn -lopencv_ml -lopencv_objdetect
        -lopencv_shape -lopencv_stitching -lopencv_superres -lopencv_videostab
        -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio
        -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_imgproc
        -lopencv_flann -lopencv_core)

add_executable(course1-main1 src/course1/main1.c)
add_executable(course1-main2 src/course1/main2.cc)
add_executable(course1-main3 src/course1/main3.cc)
add_executable(course1-main4 src/course1/main4.cc)
add_executable(course1-main5 src/course1/main5.cc)
add_executable(course1-main6 src/course1/main6.cc)
add_executable(course1-main7 src/course1/main7.cc)
add_executable(course1-main8 src/course1/main8.cc)
add_executable(course1-main9 src/course1/main9.cc)
add_executable(course1-main10 src/course1/main10.cc)
add_executable(course1-main11 src/course1/main11.cc)
add_executable(course1-main12 src/course1/main12.cc)
add_executable(course1-main13 src/course1/main13.cc)
add_executable(course1-main14 src/course1/main14.cc)
add_executable(course1-main15 src/course1/main15.cc)
add_executable(course1-main16 src/course1/main16.cc)

add_executable(course2-main1 src/course2/main1.cc)
add_executable(course2-main2 src/course2/main2.cc)
add_executable(course2-main3 src/course2/main3.cc)
add_executable(course2-main4 src/course2/main4.cc)
add_executable(course2-main5 src/course2/main5.cc)
add_executable(course2-main6 src/course2/main6.cc)
add_executable(course2-main7 src/course2/main7.cc)
add_executable(course2-main8 src/course2/main8.cc)
#target_link_libraries(niuke ${OpenCV_LIBS})