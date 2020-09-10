//
// Created by wangheng on 2020/9/10.
//https://leetcode-cn.com/problems/kids-with-the-greatest-number-of-candies/
//
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies){
        int init_max = this->get_max_num(candies);
        vector<bool> result = vector<bool>(candies.size());
        for(int i = 0;i<candies.size();i++){
            result[i] = candies[i] + extraCandies >= init_max;
        }
        return result;
    }

private:
    inline int get_max_num(vector<int>& candies){
        int max = 0;
        for(int a: candies){
            if(a>max)
                max = a;
        }
        return max;
    }
};

int main(){
    vector<int> candies = {2,3,5,1,3};
    int extraCandies = 3;
    Solution s;
    const vector<bool> result = s.kidsWithCandies(candies, extraCandies);
    for(bool a:result){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}

