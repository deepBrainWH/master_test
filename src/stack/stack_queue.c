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
        printf("The capacity is fully! EnQueue ERROR!\n");
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
//p064-3-(2)
int judge_stack_operate_sequence_validation(char *seq) {
    int i = 0;
    int v = 0;
    while (seq[i] != '\0'){
        if(seq[i]=='I'){
            v++;
        }else if(seq[i]=='O'){
            v--;
            if (v<0){
                return 0;
            }
        }
        i++;
    }
    if(v != 0){
        return 0;
    }
    return 1;
}

StackNode *create_empty_top_head() {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->next = NULL;
    node->data = (void*)'a';
    return node;
}

void Push(StackNode *top_head, void *value) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->data = value;
    node->next = top_head->next;
    top_head->next = node;
}

void *Pop(StackNode *top_head) {
    StackNode* tmp = top_head->next;
    void * tmp_value = tmp->data;
    top_head->next = tmp->next;
    free(tmp);
    return tmp_value;
}

void free_stack_linked_list(StackNode *top_head) {
    StackNode* tmp = NULL;
    while (top_head ->next != NULL){
        tmp = top_head->next;
        if(tmp != NULL){
            top_head->next = tmp->next;
            free(tmp);
        }
    }
    free(top_head);
}

void shared_stack() {
    int capacity = 10;
    char* a = (char*)malloc(sizeof(char)*capacity);
    int s1 = 0;
    int s2 = 9;
    int label;
    char value;
    printf("\033[0;32mPlease input the stack label and the value which you want to EnQueue to stack:\033[0m\n");
    scanf("%d%c", &label,&value);
    while (1){
        if(s2-s1==1){
            printf("\033[1;31mThe shared stack have already fulled!\033[0m\n");
            break;
        }
        if(label == 1){
            private_push(a, 1, &s1, value);
        }else if(label == 2){
            private_push(a, 2, &s1, 'a');
        }else{
            break;
        }
        fflush(stdin);
        printf("\033[0;32mPlease input the stack label and the value which you want to EnQueue to stack:\033[0m;\n");
        scanf("%d%c", &label,&value);
    }
}
void private_push(char* a, int label, int* top, char value){
    if(label == 1){
        a[*top] = value;
        (*top) ++;
    }else if(label == 2){
        a[*top] = value;
        (*top) --;
    }
}



