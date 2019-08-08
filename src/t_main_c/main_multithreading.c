//
// Created by wangheng on 7/20/19.
//
#include "../multithreading/thread_1.h"
#include "../multithreading/function_point.h"

int main(){

//    char* a = "hello world";
//    print_message_function(a);

//    test_thread1();
    fun_p1 p1;
    p1 = add;
    int result1 = p1(3, 4);
    p1 = sub;
    int result2 = p1(3,4);
    printf("the result1 is: %d, result2 is:%d\n", result1, result2);
    return 0;
}
