#include <stdio.h>
#include <stdlib.h>
#include "single_direct_linked_list.h"
#include "array_list.h"

int main()
{
    //Node* root = create_single_direct_linked_list();
    // print_linked_list(root);
    SeqList list;
    init_sequent_list(&list);
    insert_element(&list, 5);
    insert_element(&list, 6);
    insert_element(&list, 7);
    insert_element(&list, 8);
    insert_element(&list, 9);
    print_list(&list);
    insert_element_by_index(&list, 3, 10);
    insert_element_by_index(&list, 1, 11);
    print_list(&list);
    delete_element_by_index(&list, 4);
    print_list(&list);
    printf("\nlocate element location: %d", locate_element_index(&list, 10));
    printf("\nDeleting the minimum value of array list.\n");
    delete_array_list_minum_value(&list);
    print_list(&list);
    printf("\nInverting array list:\n");
    invert_array_list_elements(&list);
    print_list(&list);
    insert_element(&list, 3);
    insert_element(&list, 5);
    insert_element(&list, 3);
    print_list(&list);
    printf("\ndelete element by value.\n");
    delete_element_by_value(&list, 3);
    print_list(&list);
//    delete_element_by_value_scope(&list, 5, 8);
//    print_list(&list);
//    bubble_sort_array_list(&list);
    insert_element(&list, 3);
    insert_element(&list, 5);
    insert_element(&list, 3);
    select_sort_array_list(&list);
    print_list(&list);
    delete_all_the_repeating_elements_in_sorted_list(&list);
    print_list(&list);
    SeqList list2;
    list2.data = (ElementType*)calloc(list.length*2, sizeof(ElementType));
    list2.length = 0;
    insert_element(&list2, 1);
    insert_element(&list2, 2);
    insert_element(&list2, 2);
    insert_element(&list2, 7);
    insert_element(&list2, 9);

    print_list(&list2);
    SeqList* result = (SeqList*)calloc(1, sizeof(SeqList));
    init_sequent_list(result);
    combine_two_sorted_array_list(&list, &list2, result);
    print_list(result);

//    invert_two_array_list(result, 6, 5);
//    print_list(result);

    find_element_if_exist(result, 4);
    print_list(result);


    destroy_list(&list);

    return 0;
}
