//
// Created by wangheng on 8/8/19.
//

#ifndef MASTER_TEST_MYQUEUE1_H
#define MASTER_TEST_MYQUEUE1_H

#include <iostream>
using namespace std;

template <class T>
class MyQueue1 {
private:
    T* queue = nullptr;
    int max_capicity;
    int front;
    int rear;
    void init_queue(int max_capacity){
        this->queue = new T[max_capacity];
    }
    bool is_fulled(){
        return (this->rear + 1) % this->max_capicity == this->front;
    }
public:

    MyQueue1(int max_capicity=10){
        if(max_capicity<=0 || max_capicity > 999999){
            cout<<"\033[0;31m"<<"There is an error in max_capicity:"<<max_capicity<<"\033[0m"<<endl;
        }
        this->init_queue(max_capicity);
        this->rear = 0;
        this->front = 0;
        this->max_capicity = max_capicity;
    }

    bool is_empty(){
        return this->rear == this->front;
    }

    void EnQueue(T value){
        if(is_fulled()){
            cout<<"\n\033[0;31m"<<"This queue has already fulled!"<<"\033[0m"<<endl;
            exit(-1);
        }else{
            this->queue[rear] = value;
            this->rear = (this->rear + 1) % max_capicity;
        }
    }

    T DeQueue(){
        if(is_empty()){
            cout<<"\n\033[0;31m"<<"This queue is empty!"<<"\033[0m\n"<<endl;
        }else{
            cout<<this->queue[front]<<"\t";
            front = (front+1) % max_capicity;
        }
    }

    ~MyQueue1(){
        if(this->queue != nullptr){
            delete(this->queue);
        }
    }
};


#endif //MASTER_TEST_MYQUEUE1_H
