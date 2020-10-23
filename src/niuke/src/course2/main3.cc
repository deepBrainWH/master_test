//
// Created by wangheng on 3/5/20.
//
#include <iostream>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;

void de_blank(string &str) {
    int i = 0;
    int j = i;
    while (j != str.length()) {
        if (str[j] != ' ') {
            str[i++] = str[j];
        }
        j++;
    }
    str[i + 1] = '\0';
}

double string2double(string s) {
    stringstream ss;
    double result;
    ss << s;
    ss >> result;
    return result;
}

string char2string(char c) {
    stringstream ss;
    ss << c;
    return ss.str();
}

string double2string(double num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

int get_in_prior(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '(') {
        return 0;
    } else {
        throw "There is an error at character";
    }
}

int get_out_prior(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '(' || c == ')') {
        return 3;
    } else {
        throw "There is an error at character";
    }
}

void calculate(string expression, double &res) {
    queue<string> last;
    stack<char> ops;
    stack<double> numbers;

    string tmp = "";
    for (int i = 0; i < expression.length(); i++) {
        char t = expression[i];
        if (t == '+' || t == '-' || t == '*' || t == '/' || t == '(' || t == ')') {
            if (tmp != "") {
                last.push(tmp);
                tmp = "";
            }
            if (ops.size() == 0) {
                ops.push(t);
                continue;
            }
            char top = ops.top();
            if (t != ')') {
                while (ops.size() > 0 && get_in_prior(top) >= get_out_prior(t)) {
                    last.push(char2string(top));
                    ops.pop();
                    if (ops.size() > 0) {
                        top = ops.top();
                    }
                }
                ops.push(t);
            } else {
                while (top != '(') {
                    last.push(char2string(top));
                    ops.pop();
                    top = ops.top();
                }
                ops.pop();//pop '('
            }
        } else {
            tmp += t;
        }
    }
    if (tmp != "") {
        last.push(tmp);
    }
    while (ops.size() > 0) {
        last.push(char2string(ops.top()));
        ops.pop();
    }

    while (last.size() > 0) {
        string front = last.front();
        if (front != "+" && front != "-" && front != "*" && front != "/") {
            numbers.push(string2double(front));
        } else {
            double &b = numbers.top();
            numbers.pop();
            double &a = numbers.top();
            numbers.pop();
            if (front == "+") {
                numbers.push(a + b);
            } else if (front == "-") {
                numbers.push(a - b);
            } else if (front == "*") {
                numbers.push(a * b);
            } else {
                numbers.push(a / b);
            }
        }
        last.pop();
    }
    res = numbers.top();
}


int main() {
    int n;
    cout << "Input:" << endl;
    cin >> n;
    cin.ignore();
    string *expressions = new string[n];
    double *result = new double[n];
    for (int i = 0; i < n; i++) {
        cin >> expressions[i];
        calculate(expressions[i], result[i]);
    }
    cout << "Output:" << endl;
    for (int i = 0; i < n; i++) {
        cout << result[i] << endl;
    }
    return 0;
}

