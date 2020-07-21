#ifndef LINK_LIST_H
#define LINK_LIST_H

#include<stdio.h>
#include<stdlib.h>
#include "stack_queue.h"

typedef struct Node Node;
typedef struct Node LinkList;
typedef struct BiNode BiNode;
typedef struct BiLinkList BiLinkList;
typedef struct FreqNode FreqNode;
typedef int Element_t;

struct Node {
    Element_t val;
    Node *next;
};

struct BiNode {
    Element_t value;
    BiNode *next;
    BiNode *previous;
};

struct BiLinkList {
    BiNode *head;
    BiNode *tail;
    int length;
};

struct FreqNode {
    Element_t value;
    int frequent;
    FreqNode *next;
    FreqNode *pre;
};

//Creating single direction link list with one empty head node. (Head insert method.)
LinkList *create_link_list1();

//Creating single direction link list without empty head node.( Head insert method.)
LinkList *create_link_list2();

//Creating single direction link list with one empty head node. (Tail insert method.)
LinkList *create_link_list3();

//Creating single direction link list without empty head node. (Tail insert method.)
LinkList *create_link_list4();

void delete_node_by_value(Node *p, Element_t value);

//Creating doubly linked list. (Head insert.)
BiLinkList *create_doubly_linked_list1();

//Creating doubly linked list. (Tail insert.)
BiLinkList *create_double_linked_list2();

//Creating circulativly single direction link list.
LinkList *create_cycle_s_d_linked_list();

void create_circle_s_d_linked_list_with_empty_head_node(LinkList *empty_head);

//invert print linked list.
void invert_print_linked_list(LinkList head);

void invert_print_linked_list2(LinkList *head);

void print_list(LinkList *list, int exit_head);

void print_cycle_single_direction_linked_list(LinkList *head, int times);

void print_doubly_linked_list(BiLinkList list);

void print_frequent_linked_list(FreqNode* list);

int find_element(LinkList *list, Element_t value);

Element_t delete_the_minimum_node(LinkList *list);

void invert_linked_list(LinkList *empty_head_node);

void invert_linked_list2(LinkList *empty_head_node);

LinkList *create_linked_list_by_value_ascent();

void delete_node_which_value_between_two_number(LinkList *empty_head, Element_t n1, Element_t n2);

void is_valid(LinkList *list);

void is_valid_of_Bnode(BiNode *list);

void is_valid_of_freqNode(FreqNode *list);

void create_Y_shape_linked_list(LinkList *empty_head1, LinkList *empty_head2);

void destroy_linked_list(LinkList *head_node);

void find_the_common_node(LinkList *list1, LinkList *list2);

void print_the_linked_list_by_value_ASC(LinkList *list);

void divide_linked_list_to_2_linked_list(LinkList *list, LinkList *result1, LinkList *result2);

void divide_linked_list_to_2_linked_list_DESC(LinkList *list, LinkList *result1, LinkList *result2);

void remove_repeat_element_in_sorted_list(LinkList *list);

LinkList *merge_2_linked_list_and_sort_by_DESC(LinkList *list1, LinkList *list2);

void merge_2_linked_list_intersection(LinkList *list1, LinkList *list2);

int linked_list_subsequence(LinkList *list1, LinkList *list2);

void create_circle_double_direction_linked_list_with_empty_head_node(BiNode *empty_head);

void print_cricle_double_direction_linked_list(BiNode *empty_head, int method);

int if_linked_list_symmetry(BiNode *empty_head);

void combine_two_circle_linked_list(LinkList *list1, LinkList *list2);

void destroy_circle_linked_list(LinkList *list);

//p038-19
void print_cricle_linked_list_by_value_ASC(LinkList *list);

//p038 20
void create_frequent_linked_list(FreqNode *empty_head);

//p038-20
FreqNode* Locate(FreqNode* empty_head, Element_t x);

void find_Kth_backwards_value(LinkList* empty_head, int k);

void process_linked_list(LinkList* empty_head, int n);

void insert_sort_linked_list(LinkList* empty_head);
#endif
