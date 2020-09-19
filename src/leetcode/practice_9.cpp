//
// Created by wangheng on 2020/9/19.
// https://leetcode-cn.com/problems/na-ying-bi/
#include <iostream>
#include <vector>

using namespace std;

int minCount(vector<int> &coins) {
    int result = 0;
    for (int a:coins) {
        if(a % 2 == 0){
            result += a / 2;
        }else{
            result += (a / 2 + 1);
        }
    }
    return result;
}

int main(int argc, char **argv) {
    vector<int> a = {4,2,1,5};
    cout<<minCount(a)<<endl;
    return 0;
}

