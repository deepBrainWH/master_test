#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv/cv.hpp>
using namespace std;
using namespace cv;
//
void testAddr() {
    int a = 10;
    int &b = a;
    b = 20;
    int *c = &a;

    std::cout << &a << " " << a << std::endl;
    cout << &b << " " << b << endl;
    cout << c << " " << *c << endl;
    cout << (19 & 15) << endl;
}
//
int main() {
    testAddr();
    const Mat mat = imread("/home/wangheng/Pictures/256513.jpg");
    imshow("image", mat);
    waitKey(0);
    destroyAllWindows();

    return 0;
}
/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/
//#include <cstdio>
//
//int removeElement(int* nums, int numsSize, int val)
//{
//    int p = -1;
//    int q = 0;
//    if (numsSize == 0) {
//        return 0;
//    }
//    while (q < numsSize) {
//        if (nums[q] == val) {
//            q++;
//        } else {
//            nums[p + 1] = nums[q];
//            p++;
//            q++;
//        }
//    }
//    return p + 1;
//}
//
//int main()
//{
//    int a[5] = { 2, 0, 3, 4, 2 };
//    int res = removeElement(a, 5, 2);
//    for (int i = 0; i < res; i++) {
//        printf("%d ", a[i]);
//    }
//    printf(" \n");
//    return 0;
//}
//
