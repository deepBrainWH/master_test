//
// Created by wangheng on 4/10/20.
//
#include <thread>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef int callback1(int, int);


int add(int a, int b) {
    return a + b;
}

void print_a_b(int a[], int b[]) {
    for (int i = 0; i < 5; i++) {
        cout << a[i] + b[i] << "--" << endl;
    }
}

void sync_test(int a[], int b[], callback1 callback) {
//    std::thread async_thread(callback(a[0], b[0]));
    for (int i = 0; i < 5; i++) {
        cout << callback(a[i], b[i]) << endl;
    }
}

void async_test(int a[], int b[]) {
    thread test(print_a_b, a, b);
    test.detach();
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1, 2, 3, 4, 5};
//    sync_test(a, b, add);
    async_test(a, b);
    cout << "end" << endl;
    
    return 0;
}