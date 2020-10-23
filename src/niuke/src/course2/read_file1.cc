//
// Created by wangheng on 4/21/20.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int string2int(const string &str_data) {
    stringstream ss;
    int res;
    ss << str_data;
    ss >> res;
    return res;
}

//字符串转数字数组
vector<int> get_numbers(string &line) {
    vector<int> result;
    string tmp = "";
    for (int i = 0; i < line.length(); i++) {
        char c = line[i];
        if (c == ' ') {
            //遇到空格，切割前面的一个数字
            if (tmp != "") {
                result.push_back(string2int(tmp));
                tmp = "";
            }
        } else {
            tmp = tmp + c;
        }
    }
    return result;
}

int get_result(const vector<int> &nums) {
    int max = -99999;
    for (int i = 2; i < 9; i++) {
        if (nums[i] % 2 == 0 && nums[i] > max) {
            max = nums[i];
        }
    }
    return max;
}

int main() {
    //input file stream
    string file_path = "/home/wangheng/CLionProjects/nwpu/data_file/111.txt";
    ifstream file(file_path);
    if (file.is_open()) {
        string line;
        getline(file, line);
        cout << "读取的数据为：\n" << line << endl;
        vector<int> numbers = get_numbers(line);
        int result = get_result(numbers);
        cout<<"程序输出结果为："<<result<<endl;
    }
    file.close();
    return 0;
}
