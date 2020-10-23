//
// Created by wangheng on 4/11/20.
//
#include <iostream>
#include <thread>

using namespace std;

void function_1() {
    cout << "Beauty is only skin-deep" << endl;
}

class Fctor {
public:
    void operator()() {
        for (int i = 0; i < 100; i++) {
            cout << "From t1 " << i << endl;
        }
    }
};

int main() {
//    Fctor fctor;
    thread t1((Fctor()));
    for (int i = 0; i < 100; i++) {
        cout << "From main thread: " << i << endl;
    }
    t1.join();//main thread waiting t1 finished.
    return 0;
}