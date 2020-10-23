//
// Created by wangheng on 4/26/20.
//
#include <iostream>
using namespace std;

void topn_1(int* nums, int length, int n){
    //使用冒泡排序的方法计算topN, 时间复杂度在O(n) ～ O(n^2)之间
    for(int i = 0;i<n;i++){
        for(int j = 0;j<length-i-1;j++){
            if(nums[j] > nums[j+1]){
                int t = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = t;
            }
        }
    }
}

void topn_2(int* nums, int length, int n){
    //使用堆排序

}

int main(){
    int a[] = {3,4,5,1,2,3,4,5,6,7,8,202,1,234,2,12};
    int size_a = sizeof(a) / sizeof(int);

    topn_1(a, size_a, 5);
    for(int i = size_a - 1;i>=size_a-5;i--){
        cout<<a[i]<<" ";
    }

//    cout<<"\n"<<size_a<<endl;

    return 0;
}

