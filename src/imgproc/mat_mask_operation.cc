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
    cout<<__FILE__<<endl;
}

void sharpen(const Mat& inputImage, Mat& result) {

}

int main() {
    help();
    Mat image = imread(fileName, IMREAD_ANYCOLOR);
    namedWindow("input image", WINDOW_FREERATIO);
    imshow("input image", image);
    waitKey(0);
    destroyAllWindows();
    help();
    return 0;
}


