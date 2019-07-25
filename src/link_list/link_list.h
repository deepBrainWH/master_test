#ifndef LINK_LIST_H
#define LINK_LIST_H

#include<stdio.h>
#include<stdlib.h>
#include "../stack/stack_queue.h"

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

void delete_node_by_value(Node* p, Element_t value);

//Creating doubly linked list. (Head insert.)
BiLinkList* create_doubly_linked_list1();

//Creating doubly linked list. (Tail insert.)
BiLinkList* create_double_linked_list2();

//Creating circulativly single direction link list.
LinkList* create_cycle_s_d_linked_list();

//Creating circulatively doubly linked list.
BiNode* create_cycle_doubly_linked_list();

void invert_print_linked_list(LinkList head);

void invert_print_linked_list2(LinkList* head);

void print_list(LinkList* list, int exit_head);

void print_cycle_single_direction_linked_list(LinkList* head, int times);

void print_doubly_linked_list(BiLinkList list);

int find_element(LinkList* list, Element_t value);

Element_t delete_the_minimum_node(LinkList* list);

void invert_linked_list(LinkList* empty_head_node);

void invert_linked_list2(LinkList* empty_head_node);

LinkList* create_linked_list_by_value_ascent();

void delete_node_which_value_between_two_number(LinkList* empty_head, Element_t n1, Element_t n2);

void is_valid(LinkList* list);

#endif
