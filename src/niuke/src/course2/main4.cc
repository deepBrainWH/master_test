//
// Created by wangheng on 3/8/20.
//
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;


int main(){
    cout<<"Input:"<<endl;
    int n;
    cin>>n;
    double** triangles = new double*[n];
    double * result = new double [n];
    cin.ignore();
    for(int i = 0;i<n;i++){
        double * &tmp = triangles[i];
        tmp = new double [3];
        cin>>tmp[0]>>tmp[1]>>tmp[2];
        sort(tmp, tmp+3);
        if(tmp[0] + tmp[1] <= tmp[2]){
            result[i] = 0.00;
        }else{
            double p = (tmp[0] + tmp[1] + tmp[2])/2.0;
            double s = sqrt(p * (p-tmp[0]) * (p-tmp[1]) * (p-tmp[2]));
            result[i] = s;
        }
    }
    cout<<"Output:"<<endl;
    for(int i = 0;i<n;i++){
        cout<<setiosflags(ios::fixed)<<setprecision(2)<<result[i]<<endl;
    }
    return 0;
}