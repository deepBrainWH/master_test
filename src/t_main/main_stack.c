//
// Created by wangheng on 7/21/19.
//
#include "stack_queue.h"

int main(){
    CircleQueue *pQueue = init_circle_queue();
    queue_element_t value = 0;
    while (value != -1){
        printf("\033[0;32mPlease input the value thay you want to put in queue:\033[0m\n");
        scanf("%d", &value);
        en_queue(pQueue, value);
    }
    
    while (value != -2){
        printf("\033[0;32mInput one key to de-queue, end by -2\033[0m\n");
        scanf("%d", &value);
        queue_element_t i = de_queue(pQueue);
        printf("\033[0;33m%d\033[0m\t", i);
    }
    printf("\n");
    
    
    return 0;
}

