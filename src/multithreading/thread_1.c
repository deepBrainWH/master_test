//
// Created by wangheng on 7/20/19.
//
#include "thread_1.h"

void print_message_function(void *ptr) {
    for(int i = 0;i<5;i++){
        printf("%s:%d\n",(char*)ptr, i);
    }
}

void test_thread1() {
    int tmp1, tmp2;
    void* retval;
    pthread_t thread1, thread2;
    char* message1 = "thread1";
    char* message2 = "thread2";

    int ret_thrd1 = pthread_create(&thread1, NULL, (void*)&print_message_function, (void*)message1);
    int ret_thrd2 = pthread_create(&thread2, NULL, (void*)&print_message_function, (void*)message2);

    if(ret_thrd1 != 0){
        printf("The thread1 create fail.\n");
    }else{
        printf("Thread1 create successful!");
    }

    if(ret_thrd2 != 0){
        printf("The thread1 create fail.\n");
    }else{
        printf("Thread1 create successful!");
    }

    tmp1 = pthread_join(thread1, &retval);
    printf("thread1 return value(retval) is %d\n", (int)retval);
    printf("thread1 return value(tmp1) is %d\n", tmp1);

    if(tmp1 != 0){
        printf("cannot join with thread1\n");
    }
    printf("thread1 end\n");

    tmp2 = pthread_join(thread1, &retval);
    printf("thread2 return value(retval) is %d\n", (int)retval);
    printf("thread2 return value(tmp) is %d\n", tmp1);
    if (tmp2 != 0) {
        printf("cannot join with thread2\n");
    }
    printf("thread2 end\n");
}
