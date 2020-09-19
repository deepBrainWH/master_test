//
// Created by wangheng on 2020/9/19.
// https://leetcode-cn.com/problems/jewels-and-stones/
#include <iostream>
using namespace std;

int numJewelsStones(string &J, string &S){
    int result = 0;
    for(char a : J){
        for(char b : S){
            if(a == b)
                result ++;
        }
    }
    return result;
}

int main(int argc, char** argv){
    string J = "aA";
    string S = "aAbabbb";
    cout<<numJewelsStones(J, S)<<endl;
    return 0;
}
