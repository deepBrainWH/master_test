//
// Created by wangheng on 4/24/20.
//写出一个程序，接受一个由字母和数字组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。
#include <iostream>

using namespace std;

int main() {
    string line;
    char a;
    int res = 0;
    cin >> line >> a;
    for(int i = 0;i<line.length();i++){
        if(a==line[i] or a+32==line[i] or a==line[i]+32){
            res++;
        }
    }
    cout<<res;
    return 0;
}
