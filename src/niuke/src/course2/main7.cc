//
// Created by wangheng on 4/21/20.
// 用两个栈实现一个队列
#include <iostream>

using namespace std;

template<typename T>
class myQueue {
public:
    myQueue(int size) {
        if (size <= 0) {
            cerr << "栈大小分配失败：size=" << size;
        } else {
            stack1 = new T[size];
            stack2 = new T[size];
            top1 = -1;
            top2 = -1;
            defaultSize = size;
        }
    }

    myQueue() {
        this->stack1 = new T[defaultSize];
    }

    ~myQueue() {
        if (this->stack1 == NULL) {
            delete (this->stack1);
        }

        if (this->stack2 == NULL) {
            delete (this->stack2);
        }
    }

    bool is_full() {
        return (top1 + 1 == defaultSize) or (top2 + 1 == defaultSize);
    }

    bool is_empty() {
        return top1 == -1 and top2 == -1;
    }

    void enqueue(T data) {
        if (is_full()) {
            cerr << "队列已满！" << endl;
            return;
        }
        if (is_empty_stack2()) {
            push_stack1(data);
        } else {
            stack2_to_stack1();
            push_stack1(data);
        }
    }

    T dequeue() {
        if (is_empty_stack1()) {
            return pop_stack2();
        } else {
            stack1_to_stack2();
            return pop_stack2();
        }
    }

private:
    int defaultSize = 10;
    T *stack1 = NULL;
    T *stack2 = NULL;
    int top1;
    int top2;

    bool is_empty_stack1() {
        return top1 == -1;
    }

    bool is_empty_stack2() {
        return top2 == -1;
    };

    void push_stack1(const T data) {
        stack1[++top1] = data;
    }

    void push_stack2(const T data) {
        stack2[++top2] = data;
    }

    T pop_stack1() {
        return stack1[top1--];
    }

    T pop_stack2() {
        return stack2[top2--];
    }

    void stack2_to_stack1() {
        while (top2 != -1) {
            push_stack1(pop_stack2());
        }
    }

    void stack1_to_stack2() {
        while (top1 != -1) {
            push_stack2(pop_stack1());
        }
    }

};

int main() {
    myQueue<int> *pQueue = new myQueue<int>(20);
    pQueue->enqueue(5);
    pQueue->enqueue(6);
    pQueue->enqueue(7);
    pQueue->enqueue(8);
    cout << pQueue->dequeue() << endl;
    cout<<pQueue->dequeue()<<endl;
    pQueue->enqueue(9);
    cout<<pQueue->dequeue()<<endl;
    cout<<pQueue->dequeue()<<endl;
    cout<<pQueue->dequeue()<<endl;
    return 0;
}

