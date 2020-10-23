//
// Created by wangheng on 2020/10/15.
// 视频转图像序列
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <iostream>
#include <sstream>

using namespace std;
using namespace cv;

//任务一: 将视频转换为图像序列
void task1() {
    const string &video_path = "/Users/wangheng/Documents/图像工程/video2imageSequence.mp4";
    cv::VideoCapture cap(video_path);
    if (!cap.isOpened()) {
        return;
    }
    int imageIndex(0);
    cv::Mat frame;
    cap >> frame;
    ostringstream oss;
    while (!frame.empty()) {
        oss << "/Users/wangheng/Documents/图像工程/作业3/video2imageSequence" << imageIndex << ".jpg";
        cv::imwrite(oss.str(), frame);
        oss.str("");
        imageIndex++;
        cap >> frame;
    }
}

//任务2-1:多帧图像加去除噪声
void task2_1() {
    int frame_top = 10;        //定义连续帧平均模式下的帧数上限
    VideoCapture capture(0);    //定义一个相机
    capture.set(CAP_PROP_FRAME_WIDTH, 500);
    capture.set(CAP_PROP_FRAME_HEIGHT, 300);

    Mat frame;        //定义一个抓取图像的容器矩阵
    Mat *frames = new Mat[frame_top];    //存储20帧图像
    int i = 0;
    Mat average;
    namedWindow("result_image", WINDOW_FREERATIO);
    while (true) {
        capture >> frame;
        if (frame.empty()) {
            continue;
        }
        frames[i % frame_top] = frame;
        i++;
        if (i > frame_top) {
            // 存储够一定数量的帧时再通过计算后显示降噪后的图像
            average = Mat::zeros(frame.rows, frame.cols, CV_8UC3);
            for (int j = 0; j < frame_top; j++) {
                average += frames[j];
            }
            average = average / frame_top;
            average.convertTo(average, CV_8UC3);
            imshow("result_image", average);
            if (waitKey(1) == 27) {
                break;
            }
        }
    }
    capture.release();
    destroyAllWindows();
}


//帧差法检测运动目标
void task2_2() {
//    VideoCapture capture("/Users/wangheng/Documents/图像工程/Laboratory_raw.avi");
    VideoCapture capture(0);
    Mat tempframe, currentframe, previousframe, difframe;
    Mat s3, difframe2, difframe3, tempframe2;
    Mat frame;
    while (true) {
        if (!capture.isOpened()) {
            cout << "read video failure" << endl;
            return;
        }
        capture >> frame;
        if (frame.empty())break;
        imshow("原始图像", frame);
        //三帧帧差法,前一帧
        previousframe = frame.clone();

        //第二帧
        capture >> frame;
        if (frame.empty())break;
        currentframe = frame.clone();

        cvtColor(previousframe, previousframe, COLOR_BGR2GRAY);
        cvtColor(currentframe, currentframe, COLOR_BGR2GRAY);

        absdiff(currentframe, previousframe, difframe);//计算当前帧和上一帧的帧差
        threshold(difframe, tempframe, 20, 255.0, THRESH_BINARY);

        dilate(tempframe, tempframe, Mat());//膨胀运算
        erode(tempframe, tempframe, Mat());//腐蚀运算

        capture >> frame;
        if (frame.empty())break;
        s3 = frame.clone();//第三帧
        cvtColor(s3, s3, COLOR_BGR2GRAY);
        absdiff(previousframe, s3, difframe2);//计算第三帧和第一帧的差值

        bitwise_and(difframe, difframe2, difframe3);
        threshold(difframe3, tempframe2, 20, 255.0, THRESH_BINARY);
        dilate(tempframe2, tempframe2, Mat());//����
        erode(tempframe2, tempframe2, Mat());//��ʴ

        imshow("image1", tempframe);
        imshow("image2", tempframe2);

        waitKey(50);
    }//end while
    destroyAllWindows();
    capture.release();
}


int main() {
    task2_1();
    return 0;
}


