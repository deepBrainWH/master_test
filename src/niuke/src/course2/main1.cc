//
// Created by wangheng on 3/3/20.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct point {
    double x;
    double y;
} Point;

typedef struct rectangular {
    Point A;
    Point B;
    Point C;
    Point D;
} Rectangular;

void calculate(Rectangular rec, string &result) {
    vector<double> lines(6);
    lines[0] = (rec.A.x - rec.B.x) * (rec.A.x - rec.B.x) + (rec.A.y - rec.B.y) * (rec.A.y - rec.B.y);
    lines[1] = (rec.A.x - rec.C.x) * (rec.A.x - rec.C.x) + (rec.A.y - rec.C.y) * (rec.A.y - rec.C.y);
    lines[2] = (rec.A.x - rec.D.x) * (rec.A.x - rec.D.x) + (rec.A.y - rec.D.y) * (rec.A.y - rec.D.y);
    lines[3] = (rec.B.x - rec.C.x) * (rec.B.x - rec.C.x) + (rec.B.y - rec.C.y) * (rec.B.y - rec.C.y);
    lines[4] = (rec.B.x - rec.D.x) * (rec.B.x - rec.D.x) + (rec.B.y - rec.D.y) * (rec.B.y - rec.D.y);
    lines[5] = (rec.C.x - rec.D.x) * (rec.C.x - rec.D.x) + (rec.C.y - rec.D.y) * (rec.C.y - rec.D.y);
    sort(lines.begin(), lines.end());
    if (lines[0] == lines[1] && lines[0] == lines[2] && lines[0] == lines[3]
        && lines[4] == lines[5] && lines[4] == lines[6]) {
        result = "yes";
    } else {
        result = "no";
    }

}

int main() {
    cout << "Input:" << endl;
    int n;
    cin >> n;
    string *result = new string[n];
    Rectangular *rectangulars = new Rectangular[n];
    cin.ignore();
    for (int i = 0; i < n; i++) {
        Rectangular &tmp = rectangulars[i];
        cin >> tmp.A.x >> tmp.A.y;
        cin >> tmp.B.x >> tmp.B.y;
        cin >> tmp.C.x >> tmp.C.y;
        cin >> tmp.D.x >> tmp.D.y;
        calculate(tmp, result[i]);
    }
    cout << "Output:" << endl;
    for (int i = 0; i < n; i++) {
        cout << result[i] << endl;
    }
    return 0;
}
