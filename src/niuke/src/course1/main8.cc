//
// Created by wangheng on 2/2/20.
// d
#include <iostream>

using namespace std;

void select_sort(int *nums, int len) {
    int i, j, x;
    for (i = 1; i < len; i++) {
        j = i - 1;
        x = nums[i];
        while (j >= 0 && x < nums[j]) {
            nums[j + 1] = nums[j];
            j--;
        }
    }
}

void quick_sort(int *a, int left, int right) {
    if (left <= right)return;
    int i = left;
    int j = right;
    int x = a[left];
    int tmp;
    while (i < j) {
        while (i < j && a[j] > x)j--;
        if (i < j) {
            tmp = a[j];
            a[j] = a[i];
            a[i] = tmp;
            i++;
            j--;
        }
        while (i < j && a[i] < x)i++;
        if (i < j) {
            tmp = a[j];
            a[j] = a[i];
            a[i] = tmp;
            i++;
            j--;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int **group = new int *[n];
    for (int i = 0; i < n; i++) {
        group[i] = new int[8];
        for (int j = 0; j < 8; j++) {
            cin >> group[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        select_sort(group[i], 8);
    }

    return 0;
}