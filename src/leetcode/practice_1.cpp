//
// Created by wangheng on 2020/9/10.
//https://leetcode-cn.com/problems/running-sum-of-1d-array
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> runningSum(vector<int>& nums){
        vector<int> result = vector<int>(nums.size());
        result[0] = nums[0];
        for(int i = 1;i<nums.size();i++){
            result[i] = result[i-1]+nums[i];
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    vector<int> result = s.runningSum(nums);
    for(int a: result){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}



