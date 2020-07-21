//
// Created by wangheng on 9/3/19.
//
#include <stdio.h>
#include "SeqStack/stack_data_structure.h"

int main(int len, char** argv){

    SqStack S;
    InitStack(S);
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);
    Push(S, 5);
    SElementType e;
    while (Pop(S, e))
    {
        printf("%d\n",e);
    }
    DestroyStack(S);
    return 0;
}
