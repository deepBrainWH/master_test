//
// Created by wangheng on 7/19/19.
//
#include <stdio.h>
#include <stdlib.h>
#include "link_list.h"

int main(){
//    LinkList * list2_without_head_node = create_link_list2();
//    print_list(list2_without_head_node, 0);

//    LinkList *list3_tail_insert = create_link_list3();
//    print_list(list3_tail_insert, 1);

//    LinkList *list4_tail_insert = create_link_list4();
//    print_list(list4_tail_insert, 0);

//    BiLinkList *pList = create_doubly_linked_list1();
//    print_doubly_linked_list(*pList);

//    BiLinkList *pList = create_double_linked_list2();
//    print_doubly_linked_list(*pList);

//    LinkList* list = create_cycle_s_d_linked_list();
//    print_cycle_single_direction_linked_list(list, 3);

//    delete_node_by_value(list3_tail_insert->next, 4);
//    print_list(list3_tail_insert, 1);
//    invert_print_linked_list(*(list3_tail_insert->next));

//    invert_print_linked_list2(list3_tail_insert->next);
//    Element_t delete_value = delete_the_minimum_node(list3_tail_insert);
//    print_list(list3_tail_insert, 1);
//    printf("Deleting node value is: %d\n", delete_value);
//    printf("Invert linked list.\n");
//    invert_linked_list(list3_tail_insert);
//    invert_linked_list2(list3_tail_insert);
//    print_list(list3_tail_insert, 1);

//    LinkList *pNode = create_linked_list_by_value_ascent();
//    print_list(pNode, 1);
//    delete_node_which_value_between_two_number(pNode, 7, 12);
//    print_list(pNode, 1);
//    LinkList* empty_head1 = (LinkList*)malloc(sizeof(Node));
//    LinkList* empty_head2 = (LinkList*)malloc(sizeof(Node));
//
//    empty_head1->val = -999;
//    empty_head2->val = -999;
//    empty_head1->next = NULL;
//    empty_head2->next = NULL;

//    create_Y_shape_linked_list(empty_head1, empty_head2);
//    print_list(empty_head1, 1);

//    print_list(empty_head1,1);
//    print_list(empty_head2, 1);

//    find_the_common_node(empty_head1, empty_head2);

//    print_the_linked_list_by_value_ASC(empty_head1);
//    LinkList* result1 = (LinkList*)malloc(sizeof(Node));
//    LinkList* result2 = (LinkList*)malloc(sizeof(Node));

//    divide_linked_list_to_2_linked_list(empty_head1, result1, result2);
//    print_list(result1, 1);
//    print_list(result2, 1);
//
//    destroy_linked_list(empty_head1);
//    destroy_linked_list(empty_head2);
//    divide_linked_list_to_2_linked_list_DESC(list_with_head_node, result1, result2);

//    print_list(result1, 1);
//    print_list(result2, 2);

//    LinkList *list1 = create_link_list3();
//    LinkList* list2 = create_link_list3();
//    print_list(list1, 1);
//    print_list(list2, 1);
//    remove_repeat_element_in_sorted_list(list1);
//    LinkList *result = merge_2_linked_list_and_sort_by_DESC(list1, list2);
//    merge_2_linked_list_intersection(list1, list2);
//    print_list(list1, 1);

//    int i = linked_list_subsequence(list1, list2);
//    char* result = i==1?"yes":"no";
//    printf("%s\n", result);
//    destroy_linked_list(list1);
//    destroy_linked_list(list2);
//    destroy_linked_list(result);
//    destroy_linked_list(result1);
//    destroy_linked_list(result2);

//===============
//    BiNode* empty_head = (BiNode*)malloc(sizeof(BiNode));
//    empty_head->next = empty_head;
//    empty_head->previous = empty_head;
//    create_circle_double_direction_linked_list_with_empty_head_node(empty_head);
//    print_cricle_double_direction_linked_list(empty_head, 0);
//    int i = if_linked_list_symmetry(empty_head);
//    printf("%d\n", i);
//==============
//    Node* empty_head = (Node*)malloc(sizeof(Node));
//    empty_head->next = empty_head;
//    empty_head->val = 9999;
//    create_circle_s_d_linked_list_with_empty_head_node(empty_head);
//    print_cricle_linked_list_by_value_ASC(empty_head);
//=====================
//    LinkList* list2 = create_cycle_s_d_linked_list();
//    combine_two_circle_linked_list(list1, list2);
//    print_cycle_single_direction_linked_list(list1, 1);

//================
//    FreqNode* empty_head = (FreqNode*)malloc(sizeof(FreqNode));
//    empty_head->next = NULL;
//    empty_head->pre = NULL;
//    empty_head->frequent = -1;
//    empty_head->value = -9999;
//
//    create_frequent_linked_list(empty_head);
//    print_frequent_linked_list(empty_head);
//
//    Element_t x;
//    printf("\033[0;34mPlease input the value that you want to locate:\n\033[0m");
//    scanf("%d", &x);
//    FreqNode *pNode = NULL;
//    while (1){
//        pNode = Locate(empty_head, x);
//        if(pNode != NULL){
//            printf("locate address is: %p\n", pNode);
//        }else{
//            break;
//        }
//        printf("===update linked list order===\n");
//        print_frequent_linked_list(empty_head);
//        printf("==========end==========\n");
//        printf("\033[0;34mPlease input the value that you want to locate:\n\033[0m");
//        scanf("%d", &x);
//    }

//================
//    LinkList *pNode = create_link_list3();
//    print_list(pNode, 1);
//    Element_t x;
//    printf("\033[0;34mPlease input the value that you want to locate:\n\033[0m");
//    scanf("%d", &x);
//
//    while (1){
//        if(x==9999)break;
//        find_Kth_backwards_value(pNode,x);
//        printf("\033[0;34mPlease input the Kth that you want to locate:\n\033[0m");
//        scanf("%d", &x);
//    }
//
//    destroy_linked_list(pNode);
//================
    LinkList *pNode = create_link_list3();
    print_list(pNode, 1);
    process_linked_list(pNode, 20);
    print_list(pNode, 1);


    return 0;
}
