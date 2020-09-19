//
// Created by wangheng on 2020/9/19.
// https://leetcode-cn.com/problems/defanging-an-ip-address/
#include <iostream>
using namespace std;

string defangIPAddr(string& address){
    string result;
    for(char a: address){
        if(a != '.'){
            result += a;
        }else{
            result = result + "[" + a + "]";
        }
    }
    return result;
}

int main(int argc, char** argv){
    string address = "1.1.1.1";
    cout<<defangIPAddr(address)<<endl;

    return 0;
}

