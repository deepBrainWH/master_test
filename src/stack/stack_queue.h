//
// Created by wangheng on 7/21/19.
//

#ifndef MASTER_TEST_STACK_QUEUE_H
#define MASTER_TEST_STACK_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 100

typedef struct Stack Stack;
typedef int stack_element_t;

struct Stack {
    stack_element_t *a;
    int top;
};



void init_stack(Stack* s);

void push_stack(Stack* stack, stack_element_t element);

stack_element_t pop_stack(Stack* stack);

int is_empty_stack(Stack* stack);

void free_stack(Stack* stack);

#endif //MASTER_TEST_STACK_QUEUE_H
