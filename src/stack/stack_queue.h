//
// Created by wangheng on 7/21/19.
//

#ifndef MASTER_TEST_STACK_QUEUE_H
#define MASTER_TEST_STACK_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 5

typedef struct Stack Stack;
typedef struct circle_queue CircleQueue;
typedef int stack_element_t;
typedef int queue_element_t;

struct Stack {
    stack_element_t *a;
    int top;
};

struct circle_queue{
    queue_element_t* elements;
    int tag;
    int front;
    int rear;
};



void init_stack(Stack* s);

void push_stack(Stack* stack, stack_element_t element);

stack_element_t pop_stack(Stack* stack);

int is_empty_stack(Stack* stack);

void free_stack(Stack* stack);

CircleQueue* init_circle_queue();

int is_queue_empty(CircleQueue* queue);

void en_queue(CircleQueue* queue, queue_element_t element);

queue_element_t de_queue(CircleQueue* queue);

void is_valid_of_circle_queue(CircleQueue* queue);

void destroy_circle_queue(CircleQueue* queue);

#endif //MASTER_TEST_STACK_QUEUE_H
