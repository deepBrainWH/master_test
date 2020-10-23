//
// Created by wangheng on 2/28/20.
//
#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>

typedef struct coefficient {
    double a;
    double b;
    double c;
} coefficient;

using namespace std;

string double2string(double a) {
    stringstream ss;
    ss << setiosflags(ios::fixed) << setprecision(2) << a;
    return ss.str();
}

void calculate(coefficient c, string &result) {
    double delta = c.b * c.b - 4 * c.a * c.c;
    if (delta < 0) {
        result = "NaN";
    } else {
        double a1 = ((-1) * c.b + sqrt(delta)) / (2 * c.a);
        double a2 = ((-1) * c.b - sqrt(delta)) / (2 * c.a);
        result = double2string(a1) + " " + double2string(a2);
    }
}

int main() {
    cout << "Input: " << endl;
    int n;
    cin >> n;
    if (n <= 0)throw new string("there is an error at input number n");
    coefficient *equation = new coefficient[n];
    string *result = new string[n];
    for (int i = 0; i < n; i++) {
        cin >> equation[i].a >> equation[i].b >> equation[i].c;
        calculate(equation[i], result[i]);
    }
    cout << "Output:" << endl;
    for (int i = 0; i < n; i++) {
        cout << result[i] << endl;
    }
    return 0;
}
