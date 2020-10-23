//
// Created by wangheng on 3/1/20.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int string2int(string &val){
    stringstream ss;
    ss<<val<<endl;
    int result;
    ss>>result;
    return result;
}

int main(){
    const string a = "/home/wangheng/workspace/CLionProjects/niuke/data_file/a.txt";
    const string b = "/home/wangheng/workspace/CLionProjects/niuke/data_file/b.txt";
    auto* in_file = new ifstream();
    vector<int> a_numbers;
    vector<int> b_numbers;

    in_file->open(a);
    string tmp = "";
    char t;
    while (!in_file->eof()){
        in_file->get(t);
        if(t != ' ' && t != '\n'){
            tmp += t;
        }else{
            if(tmp != ""){
                a_numbers.push_back(string2int(tmp));
                tmp = "";
            }
        }
    }
    in_file->close();
    in_file->open(b);
    while (!in_file->eof()){
        in_file->get(t);
        if(t != ' ' && t != '\n'){
            tmp += t;
        }else{
            if(tmp != ""){
                b_numbers.push_back(string2int(tmp));
                tmp = "";
            }
        }
    }
    for(int t_a: a_numbers){
        cout<<t_a<<" ";
    }
    cout<<"\n";
    for(int t_b: b_numbers){
        cout<<t_b<<" ";
    }
    cout<<endl;
    in_file->close();
    return 0;
}

