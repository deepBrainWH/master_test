//
// Created by wangheng on 2020/9/19.
// https://leetcode-cn.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

#include <iostream>

int subtractProductAndSum(int n) {
    int i = 1;
    int j = 0;
    while (n != 0) {
        i *= n % 10;
        j += n % 10;
        n = n / 10;
    }
    return i - j;
}

int main() {
    std::cout<<subtractProductAndSum(234)<<std::endl;
    return 0;
}


