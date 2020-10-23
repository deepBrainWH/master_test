//
// Created by wangheng on 2/28/20.
//
#include <iostream>

using namespace std;
struct date {
    int year;
    int month;
    int day;
    int hour;
    int minus;
};
typedef struct date date;

void calculate(date input, date &result) {
    result.minus = input.minus;
    result.hour = input.hour - 16;
    if (result.hour < 0) {
        input.day -= 1;
        result.hour += 24;
    }
    if (input.day <= 0) {
        input.month -= 1;
        if(input.month>0){
            if (input.year % 4 == 0 && input.month == 2) {
                input.day += 29;
            } else if (input.year % 4 != 0 && input.month == 2) {
                input.day += 28;
            } else if (input.month == 1 || input.month == 3 || input.month == 5 || input.month == 7 || input.month == 8 ||
                       input.month == 10 || input.month == 12) {
                input.day += 31;
            } else {
                input.day += 30;
            }
            result.day = input.day;
            result.month = input.month;
            result.year = input.year;
            return;
        }else{
            result.year = input.year-1;
            result.month = 12;
            result.day = input.day + 31;
            return;
        }
    }else{
        result.day = input.day;
        result.month = input.month;
        result.year = input.year;
    }
}

int main() {
    cout << "Input:" << endl;
    int n = 0;
    cin >> n;
    date *input_dates = new date[n];
    date *result_dates = new date[n];
    for (int i = 0; i < n; i++) {
        cin >> input_dates[i].year >> input_dates[i].month >> input_dates[i].day >> input_dates[i].hour
            >> input_dates[i].minus;
        calculate(input_dates[i], result_dates[i]);
    }

    cout<<"Output:"<<endl;
    for(int i = 0;i<n;i++){
        cout<<result_dates[i].year<<" ";
        if(result_dates[i].month>=10){
            cout<<result_dates[i].month<<" ";
        } else{
            cout<<"0"<<result_dates[i].month<<" ";
        }
        if(result_dates[i].day>=10){
            cout<<result_dates[i].day<<" ";
        }else{
            cout<<"0"<<result_dates[i].day<<" ";
        }
        if(result_dates[i].hour>=10){
            cout<<result_dates[i].hour<<" ";
        }else{
            cout<<"0"<<result_dates[i].hour<<" ";
        }
        if(result_dates[i].minus>=10){
            cout<<result_dates[i].minus<<" ";
        }else{
            cout<<"0"<<result_dates[i].minus<<" ";
        }
        cout<<endl;
    }
    return 0;
}

