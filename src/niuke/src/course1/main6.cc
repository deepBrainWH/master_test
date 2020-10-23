//
// Created by wangheng on 1/30/20.
// 判断是否回文: 给定n组字符串, 对每一组字符串判断是否回文(从左往右, 从右往左看都一样, 包括空格, 英文, 数字, 符号)
#include <iostream>

using namespace std;

int main(int argv, char **argc) {
    int n;
    cin >> n;
    cin.ignore(1, '\n');
    string *ss = new string[n];
    for (int i = 0; i < n; i++) {
        getline(cin, ss[i]);
    }

    for (int i = 0; i < n; i++) {
        string tmp = ss[i];
        int len = tmp.length();
        bool result = true;
        for (int j = 0; j < len / 2; j++) {
            if (tmp[j] != tmp[len - j - 1]) {
                result = false;
                break;
            }
        }
        if (result) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}

