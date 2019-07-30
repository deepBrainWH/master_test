//
// Created by wangheng on 7/21/19.
//

#include "stack_queue.h"

void init_stack(Stack *s) {
    s->a = (stack_element_t *)malloc(sizeof(stack_element_t)*MAX_CAPACITY);
    s->top = -1;
}

void push_stack(Stack *stack, stack_element_t element) {
    if (stack->top==MAX_CAPACITY-1){
        printf("The capacity is fully! push ERROR!\n");
    }else{
        stack->a[++stack->top] = element;
    }
}

stack_element_t pop_stack(Stack* stack){
    if(stack->top<0){
        printf("The stack is empty!\n");
        return -99999;
    }else{
        return stack->a[stack->top--];
    }
}

int is_empty_stack(Stack *stack) {
    return stack->top==-1?1:0;
}

void free_stack(Stack *stack) {
    free(stack->a);
    free(stack);
}

CircleQueue *init_circle_queue() {
    CircleQueue* queue = (CircleQueue*)malloc(sizeof(CircleQueue));
    queue->elements = (queue_element_t*)malloc(sizeof(queue_element_t)*MAX_CAPACITY);
    queue->front = 0;
    queue->rear = 0;
    queue->tag = 0;
    return queue;
}

int is_queue_empty(CircleQueue *queue) {
    if (queue->tag == 0){
        return 1;
    }
    return 0;
}

void en_queue(CircleQueue *queue, queue_element_t element) {
    is_valid_of_circle_queue(queue);
    if(queue->tag == MAX_CAPACITY){
        printf("\033[1;31mThe queue has already fulled\033[0m\n");
        return;
    }
    queue->elements[queue->rear] = element;
    queue->rear = (queue->rear+1) % MAX_CAPACITY;
    queue->tag ++;
}

queue_element_t de_queue(CircleQueue *queue) {
    is_valid_of_circle_queue(queue);
    if(queue->tag == 0){
        printf("\033[0;31mThis queue is empty!\033[0m\n");
        return (queue_element_t) NULL;
    }else{
        queue_element_t t = queue->elements[queue->front];
        queue->front = (queue->front+1) % MAX_CAPACITY;
        queue->tag--;
        return t;
    }
}

void is_valid_of_circle_queue(CircleQueue *queue) {
    if(queue==NULL){
        printf("\033[1;31mThe queue is NULL\033[0m\n");
        exit(-1);
    }
}

void destroy_circle_queue(CircleQueue *queue) {
    if(queue != NULL){
        free(queue->elements);
        free(queue);
    }
}



