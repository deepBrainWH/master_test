#ifndef LINK_LIST_H
#define LINK_LIST_H

#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;
typedef struct Node LinkList;
typedef struct BiNode BiNode;
typedef struct BiLinkList BiLinkList;
typedef int Element_t;

struct Node{
    Element_t val;
    Node* next;
};

struct BiNode{
    Element_t value;
    BiNode* next;
    BiNode* previous;
};

struct BiLinkList{
    BiNode* head;
    BiNode* tail;
    int length;
};

//Creating single direction link list with one empty head node. (Head insert method.)
LinkList* create_link_list1();

void insert_element(LinkList* list, Element_t number);

//Creating single direction link list without empty head node.( Head insert method.)
LinkList* create_link_list2();

//Creating single direction link list with one empty head node. (Tail insert method.)
LinkList* create_link_list3();

//Creating single direction link list without empty head node. (Tail insert method.)
LinkList* create_link_list4();

//Creating doubly linked list.
BiLinkList* create_doubly_linked_list1();



void print_list(LinkList* list, int exit_head);

void print_doubly_linked_list(BiLinkList list);

int find_element(LinkList* list, Element_t value);


void is_valid(LinkList* list);

#endif
