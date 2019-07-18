#include "array_list.h"

void init_sequent_list(SeqList *list) {
    list->data = (ElementType *) calloc(MAX_SIZE, sizeof(ElementType));
    list->length = 0;
}

void insert_element(SeqList *list, ElementType element) {
    is_valid(list);
    if (list->length < MAX_SIZE) {
        list->data[list->length++] = element;
    } else {
        printf("The number of element out of the max capacity!\n");
        return;
    }
}

int get_length(SeqList *list) {
    is_valid(list);
    return list->length;
}

int locate_element_index(SeqList *list, ElementType e) {
    for (int i = 0; i < list->length; i++) {
        if (list->data[i] == e) {
            return i;
        }
    }
    return -1;
}

ElementType get_element(SeqList *list, int index) {
    return index < list->length ? list->data[index] : -1;
}

void insert_element_by_index(SeqList *list, int i, ElementType value) {
    if (i < 1 || i > list->length + 1) {
        printf("\nInserting location Error!\n");
        return;
    } else if (list->length + 1 > MAX_SIZE) {
        printf("\nThe element of array list have already fulled! Inserting fail!");
    } else {
        for (int j = list->length; j >= i; j--) {
            list->data[j] = list->data[j - 1];
        }
        list->data[i - 1] = value;
        list->length += 1;
        printf("\nInsert successful!\n");
        return;
    }
}

ElementType delete_element_by_index(SeqList *list, int index) {
    if (index < 1 || index >= list->length) {
        printf("\nDelete element's index Error!\n");
        return -1;
    } else {
        ElementType e = list->data[index - 1];
        for (int i = index - 1; i < list->length - 1; i++) {
            list->data[i] = list->data[i + 1];
        }
        list->length--;
        return e;
    }
}

void print_list(SeqList *list) {
    printf("\nThe array list's length is : %d\n", list->length);
    for (int i = 0; i < list->length; i++) {
        printf("%d\t", list->data[i]);
    }
    printf("\n");
}

int is_empty(SeqList *list) {
    return list->length == 0;
}

void destroy_list(SeqList *list) {
    free(list->data);
    free(list);
}

void delete_array_list_minum_value(SeqList *list) {
    /**
     * Delete the minimum value of list, then make the end value in this location.
     */
    ElementType min = list->data[0];
    int location_index = 0;
    for (int i = 1; i < list->length; i++) {
        if (list->data[i] < min) {
            min = list->data[i];
            location_index = i;
        }
    }
    list->data[location_index] = list->data[list->length - 1];
    list->length--;
}

void invert_array_list_elements(SeqList *list) {
    is_valid(list);
    if (list->length <= 0) {
        printf("\nThere is no element in array list!\n");
    } else {
        int tmp = 0;
        for (int i = 0; i < list->length / 2; i++) {
            tmp = list->data[i];
            list->data[i] = list->data[list->length - 1 - i];
            list->data[list->length - 1 - i] = tmp;
        }
    }
}

void delete_element_by_value(SeqList *list, ElementType value) {
    is_valid(list);
    int k = 0;
    for (int i = 0; i < list->length; i++) {
        if (list->data[i] != value) {
            list->data[k] = list->data[i];
            k++;
        }
    }
    list->length = k;
}

void delete_element_by_value_scope(SeqList *list, ElementType a, ElementType b) {
    is_valid(list);
    if (a >= b) {
        printf("\nPlease key the correct value scope!\n You input value scope is: %d ~ %d\n", a, b);
    } else {
        int k = 0;
        for (int i = 0; i < list->length; i++) {
            if (!(list->data[i] >= a && list->data[i] <= b)) {
                list->data[k++] = list->data[i];
            }
        }
        list->length = k;
    }
}

void bubble_sort_array_list(SeqList *list) {
    is_valid(list);
    int tmp = 0;
    for (int i = 0; i < list->length; i++) {
        for (int j = 0; j < list->length - 1 - i; j++) {
            if (list->data[j] > list->data[j + 1]) {
                tmp = list->data[j];
                list->data[j] = list->data[j + 1];
                list->data[j + 1] = tmp;
            }
        }
    }
}

void select_sort_array_list(SeqList *list) {
    is_valid(list);
    int min = 9999;
    int min_index = -1;
    int tmp;
    for (int i = 0; i < list->length; i++) {
        for (int j = i; j < list->length; j++) {
            if (list->data[j] < min) {
                min = list->data[j];
                min_index = j;
            }
        }
        tmp = list->data[i];
        list->data[i] = list->data[min_index];
        list->data[min_index] = tmp;
        min = 9999;
        min_index = -1;
    }
}

void is_valid(SeqList *list) {
    if (list == NULL) {
        printf("\nThe struct of array list is NULL!\n");
        exit(-1);
    } else if (list->data == NULL) {
        printf("\nPlease initialize the structure's data memory!\n");
        exit(-1);
    }
}

void delete_all_the_repeating_elements_in_sorted_list(SeqList *list) {
    is_valid(list);
    int k = 0;
    for (int i = 1; i < list->length; i++) {
        if (list->data[k] != list->data[i]) {
            list->data[++k] = list->data[i];
        }
    }
    list->length = k;
}

void combine_two_sorted_array_list(SeqList *list1, SeqList *list2, SeqList *result) {
    is_valid(list1);
    is_valid(list2);
    is_valid(result);
    result->data = (ElementType *) calloc(list1->length + list2->length, sizeof(ElementType));
    result->length = list1->length + list2->length;
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < list1->length && j < list2->length) {
        if (list1->data[i] < list2->data[j]) {
            result->data[k] = list1->data[i];
            i += 1;
        } else {
            result->data[k] = list2->data[j];
            j += 1;
        }
        k += 1;
    }

    while (i < list1->length) {
        result->data[k++] = list1->data[i++];
    }
    while (j < list2->length) {
        result->data[k++] = list2->data[j++];
    }
}

void invert_two_array_list(SeqList *list, int m, int n) {//6, 5
    //There are two array list in list which is (a1, a2, ... , am) and (b1, b2, ... , bn)
    //and design an algorithm to transfer it to (b1, b2, ... , bn, a1, a2, ... , am)
    is_valid(list);
    if (m + n != list->length) {
        printf("\nThere is an error in m and n\n");
        exit(-1);
    } else {
        int tmp;
        int length = m + n;
        for (int i = 0; i < length / 2; i++) {
            tmp = list->data[i];
            list->data[i] = list->data[length - 1 - i];
            list->data[length - 1 - i] = tmp;
        }
        for (int i = 0; i < n / 2; i++) {
            tmp = list->data[i];
            list->data[i] = list->data[n - 1 - i];
            list->data[n - 1 - i] = tmp;
        }
        for (int i = n; i < (n + length) / 2; i++) {
            tmp = list->data[i];
            list->data[i] = list->data[length - 1 - i + n];
            list->data[length - i - 1 + n] = tmp;
        }
    }
}

void find_element_if_exist(SeqList *list, ElementType x) {
    //There is an array list:(a1, a2, a3, .. , an), and its order is ascent, design an algorithm to find the element
    //that value is `x`, if found, swap the position with the next value, or else insert an element valued x and keep
    //is ascent order.
    is_valid(list);
    int left = 0;
    int right = list->length - 1;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (list->data[mid] == x && mid < list->length - 1) {
            int tmp = list->data[mid];
            list->data[mid] = list->data[mid + 1];
            list->data[mid + 1] = tmp;
            return;
        } else if (list->data[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    for (int i = list->length; i > right; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[right+1] = x;
    list->length += 1;
}

ElementType find_middle_number(SeqList list1, SeqList list2) {
    is_valid(&list1);
    is_valid(&list2);

    int m = list1.length;
    int n = list2.length;

    int mid_index = ceil((m + n)/2.0);
    int i = 0;
    int p1 = 0;
    int p2 = 0;
    if(list1.data[list1.length-1]<list2.data[0]){
        if(mid_index>list1.length){
            return list2.data[mid_index-list1.length-1];
        }else{
            return list1.data[mid_index-1];
        }
    }else if(list2.data[list2.length-1]<list1.data[0]){
        if(mid_index>list2.length){
            return list1.data[mid_index-list2.length-1];
        }else{
            return list2.data[mid_index-1];
        }
    }

    while (i<=mid_index){
        if(list1.data[p1]<list2.data[p2]){
            i ++;
            if(i == mid_index){
                return list1.data[p1];
            }
            p1 ++;
        }else{
            i ++;
            if(i == mid_index){
                return list2.data[p2];
            }
            p2 ++;
        }
    }
    return -9999;
}

ElementType find_chiefly_element(SeqList list) {

    return -1;
}





