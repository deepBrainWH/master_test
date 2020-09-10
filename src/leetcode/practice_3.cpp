//
// Created by wangheng on 2020/9/10.
//https://leetcode-cn.com/problems/number-of-good-pairs/
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int numIdenticalPairs(vector<int>& nums){
        int result = 0;
        int i = 0;
        int j;
        while(i<nums.size()){
            j = nums.size()-1;
            while (j>i){
                if(nums[i] == nums[j]){
                    result ++;
                }
                j--;
            }
            i++;
        }
        return result;
    }
};

int main(){
    vector<int> nums = {1,1,1,1,1,1};
    Solution s;
    int result = s.numIdenticalPairs(nums);
    cout<<result<<endl;
    return 0;
}

