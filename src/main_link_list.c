//
// Created by wangheng on 7/19/19.
//
#include <stdio.h>
#include <stdlib.h>
#include "link_list/link_list.h"

int main(){

//    LinkList *list_with_head_node = create_link_list1();
//    print_list(list1_with_head_node, 1);

//    LinkList * list2_without_head_node = create_link_list2();
//    print_list(list2_without_head_node, 0);

//    LinkList *list3_tail_insert = create_link_list3();
//    print_list(list3_tail_insert, 1);

//    LinkList *list4_tail_insert = create_link_list4();
//    print_list(list4_tail_insert, 0);

    BiLinkList *pList = create_doubly_linked_list1();
    print_doubly_linked_list(*pList);

    return 0;
}
