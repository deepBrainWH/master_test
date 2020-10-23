//
// Created by wangheng on 4/24/20.
//计算字符串最后一个单词的长度，单词以空格隔开。
#include <iostream>
#include <vector>

using namespace std;

inline void push_back(vector<string> &res, string value){
    if(res.size()>0){
        res.pop_back();
    }
    res.push_back(value);
}

int main(){
    cout<<"Input:"<<endl;
    string line;
    getline(cin, line);
    string tmp = "";
    vector<string> result;
    for(int i = 0;i<line.length();i++){
        if(line[i] == ' '){
            if(tmp != ""){
                push_back(result, tmp);
                tmp = "";
            }
        }else{
            tmp += line[i];
        }
    }
    if(tmp != ""){
        push_back(result, tmp);
    }
    cout<<"result is :"<<result.at(0)<<'\n'<<"size is :"<<result.at(0).length()<<endl;
    return 0;
}

