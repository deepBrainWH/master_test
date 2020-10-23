//
// Created by wangheng on 4/22/20.
//题目描述
//小Q得到一个神奇的数列: 1, 12, 123,...12345678910,1234567891011...。
//
//并且小Q对于能否被3整除这个性质很感兴趣。
//
//小Q现在希望你能帮他计算一下从数列的第l个到第r个(包含端点)有多少个数可以被3整除。
//
//输入描述:
//输入包括两个整数l和r(1 <= l <= r <= 1e9), 表示要求解的区间两端。
//输出描述:
//输出一个整数, 表示区间内能被3整除的数字个数。
//示例1
//输入
//复制
//2 5
//输出
//复制
//3
//说明
//1, 12, 123, 1234, 12345, 123456
//其中12, 123, 12345能被3整除。
#include <iostream>

using namespace std;

string reduce_string(string s) {
    while (s.length() >= 3) {
        int r = 0;
        int t;
        for (int i = 0; i < s.length(); i++) {
            t = s[i] - '0';
            r += t;
        }
        s = to_string(r);
    }
    return s;
}

int main() {
    cout << "Input:" << endl;
    int l, r;
    cin >> l >> r;
    int res = 0;
    string s = "";
    if (l <= r and r <= 1e9) {
        for (; l <= r; l++) {
            s += to_string(l);
            if(s.length()>=5){
                s = reduce_string(s);
            }
            if(stoi(s) % 3 == 0){
                res ++;
            }
        }
        cout << res << endl;
    }
    return 0;
}

