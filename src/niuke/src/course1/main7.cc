// 括号匹配, 给定n组数, 每组一个字符串, 测试3种括号: {}, [], (),
// 且顺序只能是前左括号, 后右括号, 括号间可以嵌套, 若匹配, 输出yes, 否则输出no
// Created by wangheng on 1/30/20.
//
#include <iostream>

using namespace std;

int main(int argv, char **argc) {
    char stack[100];//字符栈
    int top = -1;//栈顶
    int n;//组数
    cout << "Input:\n";
    cin >> n;
    string *ss = new string[n];//字符串数组
    cin.ignore(1, '\n');
    for (int i = 0; i < n; i++) {
        getline(cin, ss[i]);
    }

    bool result;
    for (int i = 0; i < n; i++) {
        result = true;
        for (int j = 0; j < ss[i].length(); j++) {
            string tmp = ss[i];
            if (tmp[j] == '{' || tmp[j] == '(' || tmp[j] == '[') {
                stack[++top] = tmp[j];
            } else if (tmp[j] == '}') {
                if (top >= 0 && stack[top] == '{') {
                    top--;
                } else {
                    result = false;
                    break;
                }
            } else if (tmp[j] == ']') {
                if (top >= 0 && stack[top] == '[') {
                    top--;//出栈
                } else {
                    result = false;
                    break;
                }
            } else if (tmp[j] == ')') {
                if (top >= 0 && stack[top] == '(') {
                    top--;//出栈
                } else {
                    result = false;
                    break;
                }
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

