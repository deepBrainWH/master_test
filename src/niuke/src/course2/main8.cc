//输入一个ip地址串，判断是否合法。
// Created by wangheng on 4/22/20.
//
#include <iostream>
#include <vector>

using namespace std;

vector<int> get_numbers(const string &s){
    vector<int> result;
    string tmp;
    for(char i : s){
        if(i == '.'){
            if(!tmp.empty()){
                result.push_back(std::stoi(tmp));
                tmp = "";
            }else{
                cout<<"ip 数据不合法！"<<endl;
                exit(1);
            }
        }else{
            tmp += i;
        }
    }
    return result;
}

string check_valid(const vector<int> &numbers){
    for(int n:numbers){
        if(!(n>=0 && n<=255)){
            return "No";
        }
    }
    return "Yes";
}

int main(){
    string ip = "255.255.256.255";
    vector<int> v = get_numbers(ip);
    cout<<check_valid(v)<<endl;
    return 0;
}
