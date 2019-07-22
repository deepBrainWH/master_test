//
// Created by wangheng on 7/21/19.
//

#include "stack_queue.h"

void init_stack(Stack *s) {
    s->a = malloc(sizeof(stack_element_t)*MAX_CAPACITY);
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

