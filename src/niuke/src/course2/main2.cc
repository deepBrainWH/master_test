//
// Created by wangheng on 3/5/20.
//
#include <iostream>

using namespace std;

typedef struct datetime {
    int hour;
    int minute;
    int second;
} datetime;

typedef struct input_datetime {
    datetime a;
    datetime b;
} InputDatetime;

void calculate(InputDatetime d, datetime &result) {
    datetime &tmp1 = d.a;
    datetime &tmp2 = d.b;
    int seconds1 = tmp1.second + tmp1.minute * 60 + tmp1.hour * 60 * 60;
    int seconds2 = tmp2.second + tmp2.minute * 60 + tmp2.hour * 60 * 60;
    int plus = (seconds1 + seconds2) / 2;
    result.hour = plus / 3600;
    result.minute = (plus % 3600) / 60;
    result.second = (plus % 3600) % 60;
}

int main() {

    cout << "Input:" << endl;
    int n;
    cin >> n;
    InputDatetime *inputDatetimes = new InputDatetime[n];
    datetime *result = new datetime[n];
    cin.ignore();
    for (int i = 0; i < n; i++) {
        InputDatetime &tmp = inputDatetimes[i];
        cin >> tmp.a.hour >> tmp.a.minute >> tmp.a.second;
        cin >> tmp.b.hour >> tmp.b.minute >> tmp.b.second;
        calculate(tmp, result[i]);
    }
    cout<<"Output:"<<endl;
    for(int i = 0;i<n;i++){
        datetime& tmp = result[i];
        cout<<tmp.hour<<" "<<tmp.minute<<" "<<tmp.second<<endl;
    }
    return 0;
}
