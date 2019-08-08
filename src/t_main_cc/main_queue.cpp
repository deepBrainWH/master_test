//
// Created by wangheng on 8/8/19.
//
#include "MyQueue1.h"

int main(){
    MyQueue1<int>* queue1 = new MyQueue1<int>(5);
    queue1->EnQueue(1);
    queue1->EnQueue(2);
    queue1->EnQueue(3);
    queue1->EnQueue(4);
    queue1->EnQueue(4);
    queue1->EnQueue(4);
    queue1->EnQueue(4);
    queue1->EnQueue(4);


    queue1->DeQueue();
    queue1->DeQueue();
    queue1->DeQueue();
    queue1->DeQueue();
    queue1->DeQueue();

    return 0;
}

