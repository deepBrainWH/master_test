#ifndef ARRAY_LIST_H_INCLUDED
#define ARRAY_LIST_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <math.h>
#define MAX_SIZE 100

typedef int ElementType;


typedef struct
{
    ElementType* data;
    int length;
}SeqList;

void init_sequent_list(SeqList* list);

void insert_element(SeqList* list, ElementType element);

int get_length(SeqList* list);

int locate_element_index(SeqList* list, ElementType e);

ElementType get_element(SeqList* list, int index);

void insert_element_by_index(SeqList *list, int i, ElementType value);

ElementType delete_element_by_index(SeqList* list, int index);

void print_list(SeqList* list);

int is_empty(SeqList* list);

void destroy_list(SeqList* list);

void delete_array_list_minum_value(SeqList* list);

void invert_array_list_elements(SeqList* list);

//Delete the element valued X in array list.
void delete_element_by_value(SeqList* list, ElementType value);

void delete_element_by_value_scope(SeqList* list, ElementType a, ElementType b);

void bubble_sort_array_list(SeqList* list);

void select_sort_array_list(SeqList *list);

void delete_all_the_repeating_elements_in_sorted_list(SeqList *list);

void combine_two_sorted_array_list(SeqList* list1, SeqList* list2, SeqList* result);

void invert_two_array_list(SeqList* list, int m, int n);

void find_element_if_exist(SeqList* list, ElementType num);

ElementType find_middle_number(SeqList list1, SeqList list2);

ElementType find_chiefly_element(SeqList list);

void is_valid(SeqList* list);


#endif // ARRAY_LIST_H_INCLUDED
