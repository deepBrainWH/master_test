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
    int mode = 1;            //拍照模式选择：0为常规模式，1为连续帧平均模式。
    int frame_number = 1;    //连续帧平均模式下的帧数计数
    int frame_top = 20;        //定义连续帧平均模式下的帧数上限
    int num_photo = 1;        //计算拍照总数
    int num_top = 1;        //定义需要照片的数量
    string num;        //为拍摄的照片取名字
    VideoCapture capture(0);    //定义一个相机
    //摄像头的基本设置
    capture.set(CAP_PROP_FRAME_WIDTH, 960);//像素数量设置
    capture.set(CAP_PROP_FRAME_HEIGHT, 720);
    capture.set(CAP_PROP_CONTRAST, 90);//对比度设置
    Mat frame;        //定义一个抓取图像的容器矩阵
    Mat average = Mat::zeros(720, 960, CV_8UC3);    //定义一个用于做平均的容器，初始值置零
    Mat tmp = Mat::zeros(720, 960, CV_8UC3);    //定义一个用于暂存的容器，初始值置零
    if (mode == 1) //如果是连续帧平均模式
    {
        while (true)    //反复执行程序
        {
            capture >> frame;
            imshow("实时图像", frame);    //remember, imshow() needs a window name for its first parameter
//            if (waitKey(30) >= 0)//如果有按键
//            {
            average = Mat::zeros(720, 960, CV_8UC3);    //做平均的容器在每次使用时初始值置零
            for (frame_number = 1; frame_number <= frame_top; frame_number++) //累积一定数量的相邻帧图片
            {
                capture >> frame; //读取一帧新的图
                frame.convertTo(tmp, CV_8UC3); //强制类型转换，防止饱和，转换后的内容存放在暂存容器tmp中
                average = average + tmp; //将tmp累积在平均容器中
            }
            average = average / frame_top;
            if (num_photo < 10)
                num = "0" + to_string(num_photo);
            else
                num = to_string(num_photo);
            average.convertTo(frame, CV_8UC3);
            imwrite("image" + num + ".jpg", frame);
            num_photo++;
//            }

            if (num_photo == (num_top + 1))//结束条件
                break;
        }
    } else  //如果是普通拍照模式
    {
        while (true)    //用来反复执行程序
        {
            capture >> frame;
            imshow("实时图像", frame);    //remember, imshow() needs a window name for its first parameter

            if (waitKey(30) >= 0)//如果有按键
            {
                if (num_photo < 10)
                    num = "0" + to_string(num_photo);
                else
                    num = to_string(num_photo);

                imwrite("imagea" + num + ".jpg", frame);
                num_photo++;

            }
            if (num_photo == (num_top + 1))//结束条件
                break;
        }
    }
    capture.release();
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
    task2_2();
    return 0;
}


