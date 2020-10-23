//
// Created by wangheng on 1/30/20.
// 字符串翻转: 给定n组字符串, 每组字符串字符个数不超过20, 输出每组字符串的反串
#include <iostream>
#include <string>

using namespace std;

void revert_string(string &str) {
    unsigned int len = str.length();
    for (int i = 0; i < len / 2; i++) {
        char tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
}

int main() {
    int n;
    cin >> n;
    string *s = new string[n];
    cin.ignore(1, '\n');
    for (int i = 0; i < n; i++) {
        getline(cin, s[i]);
        revert_string(s[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << s[i] << "\n";
    }
    cout << endl;
}
