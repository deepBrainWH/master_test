#ifndef LINK_LIST_H
#define LINK_LIST_H

#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;
typedef struct Node LinkList;
typedef int Element_t;

struct Node{
    Element_t val;
    Node* next;
};



void create_link_list1(LinkList* list);

void ll_insert_element(LinkList* list, Element_t number);

//void create_link_list2

void ll_is_valid(LinkList* list);

#endif
