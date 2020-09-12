//
// Created by wangheng on 2020/9/11.
// https://leetcode-cn.com/problems/xor-operation-in-an-array/

#include <iostream>
using namespace std;

class Solution{
public:
    int xorOperation(int n, int start){
        int ans = 0;
        for(int i=0;i<n;i++){
            ans ^= (start + i * 2);
        }
        return ans;
    }
};

int main(){
    Solution s;
    int result =s.xorOperation(5, 0);
    cout<<result<<endl;
    return 0;
}