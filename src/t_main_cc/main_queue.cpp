//
// Created by wangheng on 8/8/19.
//
//#include "MyQueue1.h"
//#include <iostream>
#include<iostream>

using namespace std;

void quick_sort(int* a, int low, int high){
    if(low<high){
        int i = low;
        int j = high;
        int tmp = a[low];

        while(j>=i && a[j] >= tmp)j--;
        if(j>i){
            a[i] =a[j];
            i++;
        }
        while (j>=i && a[i]<tmp)i++;
        if(i<j){
            a[j] = a[i];
            j--;
        }
        quick_sort(a, low, i-1);
        quick_sort(a, j+1, high);
    }
}

int main(){
    int a[10] = {2,4,1,5,7,3,4,1,9,6};
    quick_sort(a, 0, 9);
    for(int i = 0;i<10;i++){
        cout<<a[i]<<"\t";
    }
    cout<<endl;
    return 0;
}
//
//int main(){
//    MyQueue1<int>* queue1 = new MyQueue1<int>(5);
//    queue1->EnQueue(1);
//    queue1->EnQueue(2);
//    queue1->EnQueue(3);
//    queue1->EnQueue(4);
//    queue1->EnQueue(4);
//    queue1->EnQueue(4);
//    queue1->EnQueue(4);
//    queue1->EnQueue(4);
//
//
//    queue1->DeQueue();
//    queue1->DeQueue();
//    queue1->DeQueue();
//    queue1->DeQueue();
//    queue1->DeQueue();
//
//    return 0;
//}

