#include "stack_data_structure.h"

Status InitStack(SqStack &S) {
    S.base = (SElementType*)malloc(STACK_INIT_SIZE * sizeof(SElementType));
    if(!S.base)
        exit(OVERFLOW);
    S.top = S.base;
    S.stack_size = STACK_INIT_SIZE;
    return OK;
}

Status DestroyStack(SqStack &S) {
    free(S.base);
    S.base = NULL;
    S.top = NULL;
    S.stack_size = 0;
    return OK;
}

Status ClearStack(SqStack &S) {
    S.top = S.base;
    return OK;
}

Status StackEmpty(SqStack &S) {
    if(S.top == S.base)
        return TRUE;
    return FALSE;
}

int StackLength(SqStack &S) {
    return S.top - S.base;
}

Status StackTraverse(SqStack &S, void (*visit)(int)) {
    SElementType *p = S.base;
    while (p<S.top){
        visit(*p++);
    }
    return OK;
}

Status GetTop(SqStack &S, SElementType &e) {
    if(S.top == S.base)
        return ERROR;
    e = *(S.top-1);
    return OK;
}

Status Push(SqStack &S, SElementType e) {
    if(S.top - S.base >= S.stack_size){
        S.base = (SElementType*)realloc(S.base, (S.stack_size + STACK_INCREMENT) * sizeof(SElementType));
        if(!S.base)
            exit(OVERFLOW);
        S.top = S.base + S.stack_size;
        S.stack_size += STACK_INCREMENT;
    }
    *(S.top) = e;
    S.top ++;
    return OK;
}

Status Pop(SqStack &S, SElementType &e) {
    if(S.top == S.base)
        return ERROR;
    e = *(--S.top);
    return OK;
}

Status StackTraverse(SqStack &S, Status (*visit)(SElementType e)) {
    SElementType * p = S.base;
    while (p<S.top){
        visit(*p++);
    }
    printf("\n");
    return OK;
}
