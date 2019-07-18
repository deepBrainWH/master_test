#ifndef SINGLE_DIRECT_LINKED_LIST_H
#define SINGLE_DIRECT_LINKED_LIST_H

#include<stdio.h>
#include<stdlib.h>


typedef struct Node
{
    int val;
    struct Node* next;
} Node;

Node* create_single_linked_list();

void free_linked_list(Node* root);

void print_linked_list(Node* root);


#endif // SINGLE_DIRECT_LINKED_LIST_H
