//
// Created by wangheng on 1/30/20.
// 给定n组数, 每组一个整数, 计算该组数的阶乘
#include <iostream>

using namespace std;
#define MAX 999

int cal(int num) {
    if (num < 0) {
        return -1;
    }
    if (num == 0 || num == 1) {
        return 1;
    } else {
        int result = 1;
        for (int i = 1; i <= num; i++) {
            result *= i;
        }
        return result;
    }
}

void print_result(int* result, int n){
    for(int i = 0;i<n;i++){
        cout<<result[i]<<endl;
    }
}

int main() {
    int n;
    int num;
    int result[MAX];
    cout << "请输入n组数:";
    cin >> n;
    if (n > MAX) {
        cerr << "n值过大, 程序异常退出" << endl;
        return -1;
    }
    for (int i = 0; i < n; i++) {
        cin >> num;
        result[i] = cal(num);
    }
    print_result(result, n);
    return 0;
}

