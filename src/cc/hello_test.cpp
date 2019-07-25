//
// Created by wangheng on 7/25/19.
//

#include "hello_test.h"

void hello_test::print_hello() {
    std::cout<<"hello world"<<std::endl;
}

int main(){
    hello_test* test = new hello_test;
    test->print_hello();
    return 0;
}