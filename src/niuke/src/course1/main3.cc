//
// Created by wangheng on 1/30/20.
// C(n, m):求出n个数中任取m个数的不同取法
#include <iostream>

using namespace std;

int cal_a(int n, int m) {
    if (n < m) {
        cerr << "请输入合法数据!" << endl;
        return -1;
    } else if (n == m) {
        return 1;
    } else {
        int result = 1;
        for (int i = 0; i < m; i++) {
            result *= n;
            n = n - 1;
        }
        return result;
    }
}

int cal_b(int num) {
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

int main() {
    int n, m;
    cin >> n >> m;
    int a, b;
    a = cal_a(n, m);
    b = cal_b(m);
    int result = a / b;
    cout << result << endl;
    return 0;
}

