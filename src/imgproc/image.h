//
// Created by wangheng on 18-5-25.
//

#ifndef _IMAGE_H_
#define _IMAGE_H_
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<ctime>
#include<iostream>
#include<string>
using namespace std;
using namespace cv;
//图像基本操作的类
class EdgeDetection
{
public:
    EdgeDetection() = default;

    ~EdgeDetection() = default;
    void Sobel(Mat &src){
        Mat dst, edge, gray;
        dst.create(src.size(), src.type());
        //将原始图像转换为灰度图像
        cvtColor(src, gray, COLOR_BGR2GRAY);
        //使用3*3内核降噪
        blur(gray, edge, Size(3, 3));
        //运行Canny算子
        Canny(edge, edge, 3, 9, 3);
        //将dst所有元素设置为0
        dst = Scalar::all(255);
        src.copyTo(dst, edge);
        imshow("效果图：", dst);
        waitKey(0);
        destroyAllWindows();
    }
    //颜色空间缩减一
    void colorReduce_1(Mat &inputMat, Mat &outputMat, int div){//颜色空间缩减，方法一：用指针访问像素
        clock_t startTime, endTime;
        startTime = clock();
        outputMat = inputMat.clone();
        int rowNumber = outputMat.rows;
        int colNumber = outputMat.cols;
        for (int i = 0; i < rowNumber; i++){
            auto * data = outputMat.ptr<uchar>(i);//获取第i行的首地址
            for (int j = 0; j < colNumber; j++){
                data[j] = static_cast<uchar>(data[j] / div * div + div / 2);
            }
        }
        endTime = clock();
        cout << "使用指针访问像素耗时：" << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
        imshow("颜色缩减后的图片：", outputMat);
        waitKey(0);
        destroyAllWindows();
    }
    //颜色空间缩减方法二,用迭代器操作像素
    void colorReduce_2(const Mat &inputImg, Mat outputImg, int div){
        clock_t startTime, endTime;
        startTime = clock();
        outputImg = inputImg.clone();
        //获取迭代器
        Mat_<Vec3b>::iterator it = outputImg.begin<Vec3b>();//初始位置迭代器
        Mat_<Vec3b>::iterator itend = outputImg.end<Vec3b>();//结束位置迭代器
        for (; it != itend; it++){
            //==========开始处理每一个像素============
            (*it)[0] = static_cast<uchar>((*it)[0] / div * div + div / 2);
            (*it)[1] = static_cast<uchar>((*it)[1] / div * div + div / 2);
            (*it)[2] = static_cast<uchar>((*it)[2] / div * div + div / 2);
            //==========处理结束=====================
        }
        endTime = clock();
        cout << "使用迭代器访问像素耗时：" << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
        imshow("colorReduce_2:", outputImg);
        waitKey(0);
        destroyAllWindows();

    }
    //颜色空间缩减方法三，动态地址计算
    void colorReduce_3(Mat &inputImg, Mat &outputImg, int div){
        clock_t startTime, endTime;
        startTime = clock();
        outputImg = inputImg.clone();
        int rows = outputImg.rows;
        int cols = outputImg.cols;
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                //---------开始处理每个像素------BGR顺序处理-------
                outputImg.at<Vec3b>(i, j)[0] = outputImg.at<Vec3b>(i, j)[0] / div*div + div / 2;
                outputImg.at<Vec3b>(i, j)[1] = outputImg.at<Vec3b>(i, j)[1] / div*div + div / 2;
                outputImg.at<Vec3b>(i, j)[2] = outputImg.at<Vec3b>(i, j)[2] / div*div + div / 2;
            }
        }
        endTime = clock();
        cout << "使用动态地址计算访问像素耗时：" << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
        imshow("动态地址计算访问像素：", outputImg);
        waitKey(0);
        destroyAllWindows();
    }
    //==============================以下是三种线性滤波器============================
    //方框滤波
    void myBoxFilter(Mat &inputImage, Mat &outputImage, int kernel=5){
        namedWindow("方框滤波", 1);
        outputImage = inputImage.clone();
        boxFilter(inputImage, outputImage, -1, Size(kernel,kernel));
        imshow("原始图片：", inputImage);
        imshow("方框滤波", outputImage);
        waitKey(0);
        destroyAllWindows();
    }
    //均值滤波
    void myMeanFilter(Mat &inputImage, Mat &outputImage, int kernel=5){
        namedWindow("均值滤波"+to_string(kernel), 1);
        outputImage = inputImage.clone();
        blur(inputImage, outputImage, Size(kernel, kernel));
        imshow("原始图片", inputImage);
        imshow("均值滤波" + to_string(kernel), outputImage);
        waitKey(0);
        destroyAllWindows();
    }
    //高斯滤波
    void myGaussianFilter(Mat &inputImage, Mat &outputImage, int kernel_size, double sigmaX, double sigmaY){
        GaussianBlur(inputImage, outputImage, Size(kernel_size, kernel_size), sigmaX, sigmaY);
        imshow("高斯滤波", outputImage);
        imshow("原始图片", inputImage);
        waitKey(0);
        destroyAllWindows();
    }
    //==============================以上是三种线性滤波器============================

    //==============================以下是非线性滤波器==============================
    //中值滤波
    void myMediaFilter(Mat &inputImage, Mat &outputImage, int k = 3){
        if (k % 2 == 0){
            k = k + 1;
        }
        medianBlur(inputImage, outputImage, k);
        imshow("中值滤波", outputImage);
        imshow("原始图像", inputImage);
        waitKey(0);
        destroyAllWindows();
    }
    //双边滤波
    void myBilateralFilter(Mat &inputImage, Mat &outputImage, int d, double sigmaColor, double sigmaSpace){
        bilateralFilter(inputImage, outputImage, d, sigmaColor, sigmaSpace);
        imshow("双边滤波", outputImage);
        imshow("原图", inputImage);
        waitKey(0);
        destroyAllWindows();
    }
};
//图像形态学
class Morphology
{
public:
    Morphology() = default;

    ~Morphology(){}
    //====================形态学滤波（1）===========
    //图像的腐蚀
    void myErode(Mat &inputImage, Mat &outputImage, int kernel_size = 5){
        Mat element = getStructuringElement(MORPH_RECT, Size(kernel_size, kernel_size));
        erode(inputImage, outputImage, element);
        imshow("原始图片：", inputImage);
        imshow("腐蚀后效果图：", outputImage);
        waitKey(0);
        destroyAllWindows();
    }
    //图像膨胀
    void myDilate(Mat &inputImage, Mat &outputImage, int kernel_size = 5){
        Mat kernel = getStructuringElement(MORPH_RECT, Size(kernel_size, kernel_size));
        dilate(inputImage, outputImage, kernel);
        imshow("原图", inputImage);
        imshow("效果图", outputImage);
        waitKey(0);
        destroyAllWindows();
    }
    //====================形态学滤波（2）===========
    //形态学运算
    void myMorphologyEx(Mat &inputImage, Mat &outputImage, int op, int kernel_size=5){
        /*
            op为形态学运算类型
            MORPH_OPEN	开运算	先腐蚀后膨胀
            MORPH_CLOSE	闭运算	先膨胀后腐蚀
            MORPH_GRADIENT	形态学梯度	膨胀图与腐蚀图之差
            MORPH_TOPHAR	顶帽		原图与开运算结果图之差
            MORPH_BLACKHAT	黑帽		闭运算结果图与原图之差
            MORPH_ERODE		腐蚀
            MORPH_DILATE	膨胀
        */
        Mat element = getStructuringElement(MORPH_RECT, Size(kernel_size, kernel_size));
        morphologyEx(inputImage, outputImage, op, element);
        imshow("原图", inputImage);
        imshow("效果图", outputImage);
        waitKey(0);
        destroyAllWindows();
    }
    //漫水填充
    void myFloodFile(Mat inputImage){
        imshow("原始图片", inputImage);
        Rect ccomp;
        floodFill(inputImage, Point(5, 5), Scalar(255, 255, 255), &ccomp, Scalar(20, 20, 20), Scalar(20, 20, 20));
        imshow("效果图", inputImage);
        waitKey(0);
        destroyAllWindows();
    }
    //图像阈值操作
    void myAdaptiveThreshold(Mat &src, Mat &dst, double maxValu=255, int adaptiveMethod=1, int thresholdType=1, int blockSize=1, double C=1){
        /*
            maxValue:给像素赋满足条件的值
            adaptiveMethod:int类型，用于指定要使用的自适应阈值算法，可取值为：ADAPTIVE_THRESH_MEAN_C或ADAPTIVE_THRESH_GAUSSIAN_C
            thresholdType:阈值类型，取值必须为THRESH_BINARY, THRESH_BINARY_INV其中之一
            blockSize:用于计算阈值大小的一个像素的领域尺寸，取3，5，7等
            C:减去平均或加权平均值后的常数值。通常其为正数。
        */
        //adaptiveThreshold(src, dst, maxValu, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 5,1);
        threshold(src, dst, 130, 255, THRESH_BINARY);
        imshow("原始图像", src);
        imshow("dst", dst);
        Mat dst2;
        myErode(dst, dst2);
        waitKey(0);
        destroyAllWindows();
    }
};

#endif