//
// Created by wangheng on 2020/9/11.
// https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
#include <iostream>
using namespace std;

class Solution{
public:
    string reverseLeftWords(string s, int n) {
        int i = 0;
        int j = n;
        char tmp;
        int len = s.length();
        for(;i<n/2;i++){
            tmp = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = tmp;
        }
        for(;j<(len + n) / 2;j++){
            tmp = s[j];
            s[j] = s[len-j+n-1];
            s[len-j+n-1] = tmp;
        }
        for(i = 0;i<len/2;i++){
            tmp = s[i];
            s[i] = s[len-i-1];
            s[len-i-1] = tmp;
        }
        return s;
    }

};

int main(){
    string s = "abcdefg";
    int n = 2;
    Solution ss;
    const string &retult = ss.reverseLeftWords(s, n);
    cout<<retult<<endl;
    
    return 0;
}

