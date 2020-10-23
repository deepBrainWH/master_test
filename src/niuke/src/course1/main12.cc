//
// Created by wangheng on 3/1/20.
//
#include <iostream>

using namespace std;

typedef struct date {
    int year;
    int month;
    int day;
} date;

typedef struct input_date {
    date date1;
    date date2;
} input_date;

bool check_valid(input_date d) {
    if(d.date1.year != d.date2.year)return false;
    else if(d.date1.month>d.date2.month)return false;
    else if(d.date1.day>d.date2.day)return false;
    return true;
}

int compute(date d) {
    int total1 = 0;
    if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0) {
        switch (d.month) {
            case 1:
                total1 = d.day;
                break;
            case 2:
                total1 = 31 + d.day;
                break;
            case 3:
                total1 = 31 + 29 + d.day;
                break;
            case 4:
                total1 = 31 + 29 + 31 + d.day;
                break;
            case 5:
                total1 = 31 + 29 + 31 + 30 + d.day;
                break;
            case 6:
                total1 = 31 + 29 + 31 + 30 + 31 + d.day;
                break;
            case 7:
                total1 = 31 + 29 + 31 + 30 + 31 + 30 + d.day;
                break;
            case 8:
                total1 = 31 + 29 + 31 + 30 + 31 + 30 + 31 + d.day;
                break;
            case 9:
                total1 = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + d.day;
                break;
            case 10:
                total1 = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + d.day;
                break;
            case 11:
                total1 = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + d.day;
                break;
            case 12:
                total1 = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + d.day;
                break;
        }
    } else {
        switch (d.month) {
            case 1:
                total1 = d.day;
                break;
            case 2:
                total1 = 31 + d.day;
                break;
            case 3:
                total1 = 31 + 28 + d.day;
                break;
            case 4:
                total1 = 31 + 28 + 31 + d.day;
                break;
            case 5:
                total1 = 31 + 28 + 31 + 30 + d.day;
                break;
            case 6:
                total1 = 31 + 28 + 31 + 30 + 31 + d.day;
                break;
            case 7:
                total1 = 31 + 28 + 31 + 30 + 31 + 30 + d.day;
                break;
            case 8:
                total1 = 31 + 28 + 31 + 30 + 31 + 30 + 31 + d.day;
                break;
            case 9:
                total1 = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + d.day;
                break;
            case 10:
                total1 = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + d.day;
                break;
            case 11:
                total1 = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + d.day;
                break;
            case 12:
                total1 = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + d.day;
                break;
        }
    }
    return total1;
}

int main() {
    cout << "Input:" << endl;
    int n;
    cin >> n;
    cin.ignore();
    input_date *inputDates = new input_date[n];
    int *result = new int[n];
    for (int i = 0; i < n; i++) {
        tm:
        input_date &tmp = inputDates[i];
        cin >> tmp.date1.year >> tmp.date1.month >> tmp.date1.day >> tmp.date2.year >> tmp.date2.month
            >> tmp.date2.day;
        if (!check_valid(tmp)){
            cout<<"Please input the correct numbers!"<<endl;
            goto tm;
        }
        int res = compute(tmp.date2) - compute(tmp.date1) + 1;
        result[i] = res;
    }
    cout<<"Output:"<<endl;
    for(int i = 0;i<n;i++){
        cout<<result[i]<<endl;
    }
    return 0;
}
