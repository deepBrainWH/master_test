//
// Created by wangheng on 3/1/20.
//
#include <iostream>
#include <cmath>

using namespace std;

bool check_num(unsigned long long a){
    long long stop = sqrt(a) + 1;
    if(a == 2){
        return true;
    }
    if(a % 2 == 0){
        return false;
    }
    for(long long i = 3;i<stop;i+=2){
        if(a % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    cout<<"Input:"<<endl;
    long long m, n;
    cin>>m>>n;
    cin.ignore();
    long long * result = new long long[n];
    for(int i = 0;i<n;i++){
        while (!check_num(m))
            m++;
        result[i] = m;
        m+=1;
    }
    cout<<"Output:"<<endl;
    for(int i = 0;i<n;i++){
        cout<<result[i]<<endl;
    }
    return 0;
}
