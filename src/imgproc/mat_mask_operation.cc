//
// Created by wangheng on 7/21/20.
//
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;


const string fileName = "/home/wangheng/workspace/CLionProjects/master_test/data/ziqi.jpg";

inline void help() {
    cout << endl
         << "This program shows how to filter image with mask"
         << endl;
    cout << __FILE__ << endl;
}

void sharpen(const Mat& inputImage, Mat& result) {
    CV_Assert(inputImage.depth() == CV_8U);
    const int channels = inputImage.channels();
    result.create(inputImage.size(), inputImage.type());
    for (int j = 1; j < inputImage.rows - 1; j++) {
        const uchar* previous = inputImage.ptr<uchar>(j - 1);
        const uchar* current = inputImage.ptr<uchar>(j);
        const uchar* next = inputImage.ptr<uchar>(j + 1);
        uchar* output = result.ptr<uchar>(j);
        for (int i = channels; i < channels * (inputImage.cols - 1); ++i) {
            *output = saturate_cast<uchar>(5 * current[i] -
                                           current[i - channels] -
                                           current[i + channels] -
                                           previous[i] - next[i]);
            output++;
        }
    }
    result.row(0).setTo(Scalar(0));
    result.row(result.rows - 1).setTo(Scalar(0));
    result.col(0).setTo(Scalar(0));
    result.col(result.cols - 1).setTo(Scalar(0));
}

int main() {
    help();
    Mat image = imread(fileName, IMREAD_ANYCOLOR);
    Mat dst0, dst1;
    namedWindow("input image", WINDOW_FREERATIO);
    namedWindow("output image", WINDOW_FREERATIO);
    namedWindow("dst1", WINDOW_FREERATIO);
    imshow("input image", image);
    sharpen(image,dst0);
    Mat kernel = (Mat_<char>(3, 3) <<
                                   0, -1, 0,
            -1, 5, -1,
            0, -1, 0);
    filter2D(image, dst1, image.depth(), kernel);
    imshow("output image", dst0);
    imshow("dst1", dst1);
    waitKey(0);
    destroyAllWindows();
    help();
    return 0;
}


