//
// Created by wangheng on 7/21/19.
//
#include "stack_queue.h"

int main() {
//    CircleQueue *pQueue = init_circle_queue();
//    queue_element_t value = 0;
//    while (value != -1){
//        printf("\033[0;32mPlease input the value thay you want to put in queue:\033[0m\n");
//        scanf("%d", &value);
//        en_queue(pQueue, value);
//    }
//    
//    while (value != -2){
//        printf("\033[0;32mInput one key to de-queue, end by -2\033[0m\n");
//        scanf("%d", &value);
//        queue_element_t i = de_queue(pQueue);
//        printf("\033[0;33m%d\033[0m\t", i);
//    }
//    printf("\n");
//============================
//    char* seq = "IIIOOIOOI";
//    int i = judge_stack_operate_sequence_validation(seq);
//    if(i==1){
//        printf("\033[0;31mThis operate sequence is validation.\033[0m\n");
//    }else{
//        printf("\033[0;32mThis operate sequence is invalid!.\033[0m\n");
//    }
//========================
//    StackNode *empty_head = create_empty_top_head();
//    char seq[] = "xyxxy";
//    int len = sizeof(seq) - 1;
//    for (int i = 0; i < len; i++) {
//        Push(empty_head, (void *) seq[i]);
//    }
//    int i = 0;
//    if (len % 2 == 0) {
//        i = len / 2;
//    } else if (len % 2 != 0) {
//        i = len / 2 + 1;
//    }
//    while (i < len) {
//        if (seq[i] != (char) Pop(empty_head)) {
//            printf("No\n");
//            return 0;
//        }
//        i++;
//    }
//    printf("Yes\n");
//    return 0;
//    free_stack_linked_list(empty_head);
    //===============================
    shared_stack();
    return 0;
}
