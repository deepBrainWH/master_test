//
// Created by wangheng on 3/18/20.
//
#include <iostream>
#include <vector>
using namespace std;
int first;
int last;
long long min_num = 999999999999999999;

long long sum(vector<int> &nums){
    long long sum = 0;
    for(int a:nums){
        sum += a;
    }
    return sum;
}

long long minimumValueAfterDispel(vector<int> &nums){
    int tmp1, tmp2;
    vector<int> tmp11 = nums;
    for(int i = 0;i<tmp11.size();i++){
        tmp1 = tmp11[i];
        for(int j = 0;j<tmp11.size();j++){
            if(tmp11[j]>=tmp1){
                tmp11[j] -= tmp1;
            }
        }
        vector<int> tmp22 = tmp11;
        for(int k = 0;k<tmp22.size();k++){
            tmp2 = tmp22[k];
            for(int l = 0;l<tmp22.size();l++){
                if(tmp22[l]>=tmp2){
                    tmp22[l] -= tmp2;
                }
            }
            long long tmp_sum = sum(tmp22);
            if(tmp_sum<min_num){
                min_num = tmp_sum;
            }
            tmp22 = tmp11;
        }
        tmp11 = nums;
    }
    return min_num;
}

int main(){
    vector<int> a;
    a.push_back(2);
    a.push_back(1);
    a.push_back(3);
    long long int min = minimumValueAfterDispel(a);
    cout<<min<<endl;
    return 0;
}

