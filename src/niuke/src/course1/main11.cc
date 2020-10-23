//
// Created by wangheng on 2/29/20.
//
#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

string double2string(double val) {
    stringstream ss;
    string result;
    ss << val;
    ss >> result;
    return result;
}

double string2double(string val){
    stringstream ss;
    double a;
    ss<<val;
    ss>>a;
    return a;
}

double compute(string equation){
    queue<string> result;
    stack<string> ops;
    int left = 0;
    int len = equation.length();
    while(left<len){
        int right = left;
        for(;right<len;right++){
            if(equation[right] != '+' && equation[right] != '-' && equation[right] != '*' && equation[right] != '/'){
                continue;
            }else{
                string str_val = equation.substr(left, right);
                result.push(str_val);
                left = right+1;
                break;
            }
        }
    }
}

int main(){
    cout<<"Input:"<<endl;
    int n;
    cin>>n;
    cin.ignore();
    string* equations = new string[n];
    for(int i = 0;i<n;i++){
        cin>>equations[i];
        compute(equations[i]);
    }
    return 0;
}
