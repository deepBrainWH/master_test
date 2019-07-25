//
// Created by wangheng on 7/19/19.
//
#include <stdio.h>
#include <stdlib.h>
#include "link_list.h"

int main(){

//    LinkList *list_with_head_node = create_link_list1();
//    print_list(list1_with_head_node, 1);

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

    LinkList *pNode = create_linked_list_by_value_ascent();
    print_list(pNode, 1);
    delete_node_which_value_between_two_number(pNode, 7, 12);
    print_list(pNode, 1);
    return 0;
}
