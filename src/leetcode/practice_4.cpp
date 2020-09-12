//
// Created by wangheng on 2020/9/11.
//https://leetcode-cn.com/problems/shuffle-the-array/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> shuffle(vector<int>& nums, int n){
        int i = 0;
        int j = n;
        vector<int> result;
        while(i<n){
            result.push_back(nums[i]);
            result.push_back(nums[j]);
            i++;
            j++;
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,5,1,3,4,7};
    int n = 3;
    vector<int> result = s.shuffle(nums, n);
    for(int r: result){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}