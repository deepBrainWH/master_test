//
// Created by wangheng on 1/30/20.
// 给定n组数, 每组有m个, 对每一组数从小到大排序后输出
#include <iostream>

using namespace std;

void insert_sort(int *a, int len) {
    int i, j;
    int x;
    for (i = 1; i < len; i++) {
        x = a[i];
        j = i - 1;
        while (j >= 0 && x < a[j]) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

void print_result(int *a, int len) {
    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int **nInt = new int *[n];
    for (int i = 0; i < n; i++) {
        nInt[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cin >> nInt[i][j];
        }
        insert_sort(nInt[i], m);
    }
    cout << "============Output:==============\n";
    for (int i = 0; i < n; i++) {
        print_result(nInt[i], m);
        cout << endl;
    }
    return 0;
}
