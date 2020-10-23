#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

void str2int(vector<string> input, vector<int> &output) {
    stringstream ss;
    int a;
    for (int i = 0; i < input.size(); i++) {
        ss << input[i] << endl;
        ss >> a;
        output.push_back(a);
    }
}

string vector_int2string(vector<int> numbers){
    stringstream ss;
    string result = "";
    string tmp;
    for(int a:numbers){
        ss<<a<<endl;
        ss>>tmp;
        result = result + tmp+" ";
    }
    return result;
}

template <class my_type>
void swap(vector<my_type> &numbers, int i, int j){
    my_type tmp = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = tmp;
}

void quick_sort(vector<int> &numbers, int left, int right) {
    if (left < right) {
        int i = left;
        int j = right;
        int tmp = numbers[left];
        while(i<j) {
            while (i < j && numbers[j] > tmp) {
                j--;
            }
            if (i < j) {
                numbers[i] = numbers[j];
                i++;
            }
            while (i < j && numbers[i] < tmp) {
                i++;
            }
            if (i < j) {
                numbers[j] = numbers[i];
                j--;
            }
        }
        numbers[i] = tmp;
        quick_sort(numbers, left, i-1);
        quick_sort(numbers, i+1, right);
    }
}

vector<string> split(string str, char s) {
    vector<string> result;
    int left = 0;
    int len = str.length();
    string tmp = "";
    for (int i = 0; i < len; i++) {
        if (str[i] != s) {
            tmp += str[i];
        } else {
            if (tmp != "") {
                result.push_back(tmp);
                tmp = "";
            }
        }
    }
    return result;
}


int main() {
    ifstream *file1 = new ifstream("/home/wangheng/workspace/CLionProjects/niuke/data_file/data1");
    ifstream *file2 = new ifstream("/home/wangheng/workspace/CLionProjects/niuke/data_file/data2");
    ofstream *file3 = new ofstream("/home/wangheng/workspace/CLionProjects/niuke/data_file/data3");
    string tmp;
    if (!file1->is_open()) {
        cout << "文件1打开失败!" << endl;
    }
    if (!file2->is_open()) {
        cout << "文件2打开失败!" << endl;
    }
    vector<int> all_numbers;
    while (getline(*file1, tmp)) {
        vector<string> vec = split(tmp, ' ');
        str2int(vec, all_numbers);
    }

    while (getline(*file2, tmp)) {
        vector<string> vec = split(tmp, ' ');
        str2int(vec, all_numbers);
    }
    quick_sort(all_numbers, 0, all_numbers.size()-1);
    const string &basicString = vector_int2string(all_numbers);
    (*file3)<<basicString<<endl;
    file1->close();
    file2->close();
    file3->close();
    return 0;
}