//
// Created by wangheng on 9/3/19.
//

#ifndef MASTER_TEST_STACK_DATA_STRUCTURE_H
#define MASTER_TEST_STACK_DATA_STRUCTURE_H
#if defined(LINEEDIT_H)
typedef char SElementType;
#elif defined(CONVERSION_H)
typedef int SElementType;
#endif

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"


#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10


typedef struct {
    SElementType * base;
    SElementType * top;
    int stack_size;
}SqStack;

Status InitStack(SqStack &S);

Status DestroyStack(SqStack &S);

Status ClearStack(SqStack &S);

Status StackEmpty(SqStack &S);

int StackLength(SqStack &S);

Status GetTop(SqStack &S, SElementType &e);

Status Push(SqStack &S, SElementType e);

Status Pop(SqStack &S, SElementType &e);

Status StackTraverse(SqStack &S, Status (visit)(SElementType p));

#endif //MASTER_TEST_STACK_DATA_STRUCTURE_H
