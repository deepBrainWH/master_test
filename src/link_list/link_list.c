//
// Created by wangheng on 7/19/19.
//
#include "link_list.h"

LinkList *create_link_list1() {
    LinkList *head = (LinkList *) malloc(sizeof(Node));
    head->next = NULL;
    head->val = 0;

    Element_t element = -1;
    Node *t = NULL;
    printf("Please input the insert value, end with 9999.\n");
    scanf("%d", &element);
    while (element != 9999) {
        t = (Node *) malloc(sizeof(Node));
        t->val = element;
        t->next = head->next;
        head->next = t;
        fflush(stdin);
        printf("Please input the insert value, end with 9999.\n");
        scanf("%d", &element);
    }
    return head;
}

LinkList *create_link_list2() {
    LinkList *node = NULL;

    Element_t element;
    Node *t = NULL;
    printf("Please input the insert value, end with 9999.\n");
    scanf("%d", &element);
    while (element != 9999) {
        t = (Node *) malloc(sizeof(Node));
        t->val = element;
        t->next = node;
        node = t;
        fflush(stdin);
        printf("Please input the insert value, end with 9999.\n");
        scanf("%d", &element);
    }
    return node;
}

void is_valid(LinkList *list) {
    if (list == NULL) {
        printf("\nThe link list is NULL!\n");
        exit(-1);
    }
}

void is_valid_of_Bnode(BiNode *list) {
    if (list == NULL) {
        printf("\nThe link list is NULL!\n");
        exit(-1);
    }
}

void is_valid_of_freqNode(FreqNode *list) {
    if (list == NULL) {
        printf("\nThe link list is NULL!\n");
        exit(-1);
    }
}

void print_list(LinkList *list, int exit_head) {
    is_valid(list);
    Node *p = NULL;
    if (exit_head)
        p = list->next;
    else
        p = list;
    while (p != NULL) {
        printf("%d\t", p->val);
        p = p->next;
    }
    printf("\n");
}


void print_frequent_linked_list(FreqNode *list) {
    is_valid_of_freqNode(list);
    FreqNode *p = NULL;
    p = list->next;
    while (p != NULL) {
        printf("%d\t", p->value);
        p = p->next;
    }
    printf("\n");
}

int find_element(LinkList *list, Element_t value) {
    return 0;
}

LinkList *create_link_list3() {
    LinkList *empty_head = (LinkList *) malloc(sizeof(LinkList));
    empty_head->next = NULL;
    empty_head->val = -1;

    Node *p = empty_head;

    Element_t value;
    printf("Please input the value which you want to add to link list and end with 9999.\n");
    scanf("%d", &value);

    while (value != 9999) {
        Node *node = (Node *) malloc(sizeof(Node));
        node->val = value;
        node->next = p->next;
        p->next = node;
        p = p->next;
        fflush(stdin);
        printf("Please input the value which you want to add to link list and end with 9999.\n");
        scanf("%d", &value);
    }

    return empty_head;
}

LinkList *create_link_list4() {
    Node *head = NULL;
    Node *p = NULL;

    Element_t value;
    printf("Please input the value which you want to add to link list and end with 9999.\n");
    scanf("%d", &value);

    while (value != 9999) {
        Node *node = (Node *) malloc(sizeof(Node));
        node->val = value;
        if (p == NULL) {
            node->next = NULL;
            head = node;
            p = head;
        } else {
            node->next = p->next;
            p->next = node;
            p = p->next;
        }
        fflush(stdin);
        printf("Please input the value which you want to add to link list and end with 9999.\n");
        scanf("%d", &value);
    }
    return head;
}

BiLinkList *create_doubly_linked_list1() {
    BiLinkList *biLinkList = (BiLinkList *) malloc(sizeof(BiLinkList));
    biLinkList->head = NULL;
    biLinkList->tail = NULL;
    biLinkList->length = 0;

    Element_t value;
    printf("Please input the value which you want to add to link list and end with 9999.\n");
    scanf("%d", &value);

    while (value != 9999) {
        BiNode *node = (BiNode *) malloc(sizeof(BiNode));
        node->value = value;
        if (biLinkList->head == NULL && biLinkList->tail == NULL) {
            node->next = NULL;
            node->previous = NULL;
            biLinkList->head = node;
            biLinkList->tail = node;
        } else {
            node->next = biLinkList->head;
            node->previous = biLinkList->head->previous;
            biLinkList->head->previous = node;
            biLinkList->head = node;
        }
        fflush(stdin);
        printf("Please input the value which you want to add to link list and end with 9999.\n");
        scanf("%d", &value);
    }
    return biLinkList;
}

void print_doubly_linked_list(BiLinkList list) {
    if (list.head == NULL || list.tail == NULL) {
        printf("\nThe doubly linked list is empty!\n");
    } else {
        BiNode *p = list.head;
        while (p != NULL) {
            if (p->next == NULL) {
                printf("%d\n", p->value);
                break;
            }
            printf("%d\t", p->value);
            p = p->next;
        }

        while (p != NULL) {
            printf("%d\t", p->value);
            p = p->previous;
        }
    }
}

BiLinkList *create_double_linked_list2() {
    BiLinkList *list = (BiLinkList *) malloc(sizeof(BiLinkList));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    Element_t value;
    printf("Please input the value which you want to add to link list and end with 9999.\n");
    scanf("%d", &value);

    while (value != 9999) {
        BiNode *node = (BiNode *) malloc(sizeof(BiNode));
        node->value = value;
        if (list->head == NULL && list->tail == NULL) {
            node->next = NULL;
            node->previous = NULL;
            list->head = node;
            list->tail = node;
        } else {
            node->next = NULL;
            node->previous = list->tail;
            list->tail->next = node;
            list->tail = node;
        }
        fflush(stdin);
        printf("Please input the value which you want to add to link list and end with 9999.\n");
        scanf("%d", &value);
    }
    return list;
}

LinkList *create_cycle_s_d_linked_list() {
    LinkList *head = NULL;
    Node *p = NULL;

    Element_t value;
    printf("Please input the value which you want to add to link list and end with 9999.\n");
    scanf("%d", &value);

    while (value != 9999) {
        Node *node = (Node *) malloc(sizeof(Node));
        node->val = value;
        if (p == NULL) {
            node->next = node;
            head = node;
            p = head;
        } else {
            node->next = p->next;
            p->next = node;
            p = p->next;
        }
        fflush(stdin);
        printf("Please input the value which you want to add to link list and end with 9999.\n");
        scanf("%d", &value);
    }
    return head;
}

void print_cycle_single_direction_linked_list(LinkList *head, int times) {
    is_valid(head);
    Node *p = head;
    int count = 0;
    while (p != NULL && count < times) {
        printf("%d\t", p->val);
        p = p->next;
        if (p == head) {
            printf("\n");
            count++;
        }
    }
}

void delete_node_by_value(Node *p, Element_t value) {
    Node *t1 = p;
    Node *t2 = p->next;
    Node *t3 = NULL;

    while (t2 != NULL) {
        if (t2->val == value) {
            t3 = t2;
            t2 = t2->next;
            t1->next = t2;
            free(t3);
        } else {
            t1 = t1->next;
            t2 = t2->next;
        }
    }
}

void invert_print_linked_list(Node head) {
    if (head.next != NULL) {
        invert_print_linked_list(*head.next);
    }
    printf("%d\t", head.val);
}

void invert_print_linked_list2(LinkList *head) {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    init_stack(stack);
    Node *p = head;
    while (p != NULL) {
        push_stack(stack, (stack_element_t) p->val);
        p = p->next;
    }

    while (!is_empty_stack(stack)) {
        printf("%d\t", pop_stack(stack));
    }
    free_stack(stack);
}

Element_t delete_the_minimum_node(LinkList *list) {
    Node *min_node_pre = list;//最小值节点前驱
    Node *min_node = list->next;//最小值节点
    Element_t min = min_node->val;//默认第一个节点值最小

    Node *p = min_node;//working point.
    Node *p_pre = list;//Previous working point.
    while (p != NULL) {
        if (p->val < min) {
            min = p->val;
            min_node = p;
            min_node_pre = p_pre;
        }
        p = p->next;
        p_pre = p_pre->next;
    }

    Node *t = min_node;
    min_node_pre->next = min_node->next;
    free(t);
    return min;
}

void invert_linked_list(LinkList *empty_head_node) {
    Node *head = empty_head_node;
    Node *p = head->next;

    head->next = NULL;
    Node *p_next = NULL;

    while (p != NULL) {
        p_next = p->next;
        p->next = head->next;
        head->next = p;
        p = p_next;
    }
}

void invert_linked_list2(LinkList *empty_head_node) {
    Node *head = empty_head_node;
    Node *p_pre = NULL;
    Node *p = empty_head_node->next;
    Node *p_next = p->next;

    while (p != NULL) {
        p->next = p_pre;
        p_pre = p;
        p = p_next;
        if (p_next != NULL)
            p_next = p_next->next;
    }
    head->next = p_pre;
}

LinkList *create_linked_list_by_value_ascent() {

    Node *empty_head = (Node *) malloc(sizeof(Node));
    empty_head->val = -1;
    empty_head->next = NULL;

    Element_t value;
    printf("Please input the value which you want to add to link list and end with 9999.\n");
    scanf("%d", &value);

    Node *p = empty_head;

    while (value != 9999) {
        while (p != NULL && p->next != NULL && p->next->val < value) {
            p = p->next;
        }
        Node *tmp = (Node *) malloc(sizeof(Node));
        tmp->val = value;
        tmp->next = p->next;
        p->next = tmp;

        fflush(stdin);
        printf("Please input the value which you want to add to link list and end with 9999.\n");
        scanf("%d", &value);

        p = empty_head;
    }
    return empty_head;
}

void delete_node_which_value_between_two_number(LinkList *empty_head, Element_t n1, Element_t n2) {
    if (n1 >= n2) {
        printf("Please input correct numbers of n1 and n2.\n");
        exit(-1);
    }
    Node *p = empty_head->next;
    Node *p_pre = empty_head;
    Node *tmp = NULL;

    while (p != NULL) {
        if (p->val > n1 && p->val < n2) {
            tmp = p;
            p_pre->next = p->next;
            p = p->next;
            free(tmp);
        } else {
            p = p->next;
            p_pre = p_pre->next;
        }
    }

}

void create_Y_shape_linked_list(LinkList *empty_head1, LinkList *empty_head2) {
    is_valid(empty_head1);
    is_valid(empty_head2);

    Node *p1 = empty_head1;
    Node *p2 = empty_head2;

    Node *new_node = NULL;
    Element_t value;

    printf("\033[1;31m--Creating the left branch. Please input the node's value and end with 9999--\n");
    scanf("%d", &value);
    while (value != 9999) {
        new_node = (Node *) malloc(sizeof(Node));
        new_node->val = value;
        new_node->next = NULL;
        p1->next = new_node;
        p1 = p1->next;
        fflush(stdin);
        printf("\033[0;31m--Creating the left branch. Please continue input the node's value and end with 9999--\n");
        scanf("%d", &value);
    }

    printf("\033[1;32m--Creating the left branch. Please input the node's value and end with 9999\n");
    scanf("%d", &value);
    while (value != 9999) {
        new_node = (Node *) malloc(sizeof(Node));
        new_node->val = value;
        new_node->next = NULL;
        p2->next = new_node;
        p2 = p2->next;
        fflush(stdin);
        printf("\033[0;32m--Creating the left branch. Please input the node's value and end with 9999\n");
        scanf("%d", &value);
    }

    printf("\033[1;33m--Creating the commonly linked list. Please input the node's value and end with 9999\n");
    scanf("%d", &value);
    while (value != 9999) {
        new_node = (Node *) malloc(sizeof(Node));
        new_node->val = value;
        new_node->next = NULL;
        p1->next = new_node;
        p2->next = new_node;
        p1 = p1->next;
        p2 = p2->next;
        fflush(stdin);
        printf("\033[0;33m--Creating the commonly linked list. Please input the node's value and end with 9999\n");
        scanf("%d", &value);
    }
}

void destroy_linked_list(LinkList *head_node) {
    Node *tmp = NULL;
    Node *p = head_node;
    while (p != NULL) {
        tmp = p;
        p = p->next;
        free(tmp);
    }
}

void find_the_common_node(LinkList *list1, LinkList *list2) {
    int len1 = -1;
    int len2 = -1;

    Node *p1 = list1;
    Node *p2 = list2;

    while (p1 != NULL) {
        len1++;
        p1 = p1->next;
    }
    p1 = list1;
    while (p2 != NULL) {
        len2++;
        p2 = p2->next;
    }
    p2 = list2;
    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) {
            p1 = p1->next;
        }
        while (p1 != NULL && p2 != NULL) {
            p1 = p1->next;
            p2 = p2->next;
            if (p1 == p2) {
                printf("\033[1;34m--The commonly linked list is: \n");
                while (p1 != NULL) {
                    printf("\033[0m%d\t", p1->val);
                    p1 = p1->next;
                }
                printf("\n");
                return;
            } else {
                continue;
            }
        }
    } else if (len1 < len2) {
        for (int i = 0; i < len2 - len1; i++) {
            p2 = p2->next;
        }
        while (p1 != NULL && p2 != NULL) {
            p1 = p1->next;
            p2 = p2->next;
            if (p1 == p2) {
                printf("\033[1;34m--The commonly linked list is: \n");
                while (p2 != NULL) {
                    printf("\033[0m%d\t", p2->val);
                    p2 = p2->next;
                }
                printf("\n");
                return;
            } else {
                continue;
            }
        }
    } else {
        while (p1 != NULL && p2 != NULL) {
            p1 = p1->next;
            p2 = p2->next;
            if (p1 == p2) {
                printf("\033[1;34m--The commonly linked list is: \n");
                while (p2 != NULL) {
                    printf("\033[0m%d\t", p2->val);
                    p2 = p2->next;
                }
                printf("\n");
                return;
            } else {
                continue;
            }
        }
    }
}

void print_the_linked_list_by_value_ASC(LinkList *list) {
    is_valid(list);
    Node *tmp = NULL;
    Node *p = NULL;
    Node *min_p_pre = NULL;

    while (list->next != NULL) {
        min_p_pre = list;
        p = list->next;
        while (p->next != NULL) {
            if (p->next->val < min_p_pre->next->val) {
                min_p_pre = p;
            }
            p = p->next;
        }
        printf("%d\t", min_p_pre->next->val);
        tmp = min_p_pre->next;
        min_p_pre->next = tmp->next;
        free(tmp);
    }
}

void divide_linked_list_to_2_linked_list(LinkList *list, LinkList *result1, LinkList *result2) {
    is_valid(list);
    is_valid(result1);
    is_valid(result2);

    Node *p1 = list->next;
    Node *p2 = result1;
    Node *p3 = result2;

    int flag = 1;
    while (p1 != NULL) {
        if (flag) {
            p2->next = p1;
            p2 = p2->next;
            flag = 0;
        } else {
            p3->next = p1;
            p3 = p3->next;
            flag = 1;
        }
        p1 = p1->next;
    }
    p2->next = NULL;
    p3->next = NULL;
}

void divide_linked_list_to_2_linked_list_DESC(LinkList *list, LinkList *result1, LinkList *result2) {
    is_valid(list);
    is_valid(result1);
    is_valid(result2);

    Node *p1 = list->next;
    Node *p1_next = NULL;
    Node *p2 = result1;
    Node *p3 = result2;

    int flag = 0;
    while (p1 != NULL) {
        p1_next = p1->next;
        if (flag) {
            p1->next = p2->next;
            p2->next = p1;
            flag = 0;
        } else {
            p1->next = p3->next;
            p3->next = p1;
            flag = 1;
        }
        p1 = p1_next;
    }
}

void remove_repeat_element_in_sorted_list(LinkList *list) {
    is_valid(list);
    Node *p1 = list->next;
    Node *p2 = NULL;
    Node *tmp = NULL;
    if (p1 != NULL) {
        p2 = list->next->next;
    } else {
        return;
    }
    while (p2 != NULL) {
        if (p2->val == p1->val) {
            tmp = p2;
            p2 = p2->next;
            free(tmp);
            p1->next = p2;
        } else {
            p1 = p1->next;
            p2 = p2->next;
        }
    }

}

LinkList *merge_2_linked_list_and_sort_by_DESC(LinkList *list1, LinkList *list2) {
    is_valid(list1);
    is_valid(list2);
    Node *result_head = (Node *) malloc(sizeof(Node));
    result_head->next = NULL;
    result_head->val = -9999;

    Node *p1 = list1->next;
    Node *p2 = list2->next;
    Node *tmp1 = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->val < p2->val) {
            tmp1 = p1->next;
            p1->next = result_head->next;
            result_head->next = p1;
            p1 = tmp1;
        } else {
            tmp1 = p2->next;
            p2->next = result_head->next;
            result_head->next = p2;
            p2 = tmp1;
        }
    }
    while (p1 != NULL) {
        tmp1 = p1->next;
        p1->next = result_head->next;
        result_head->next = p1;
        p1 = tmp1;
    }
    while (p2 != NULL) {
        tmp1 = p2->next;
        p2->next = result_head->next;
        result_head->next = p2;
        p2 = tmp1;
    }
    return result_head;
}

//p038-15
void merge_2_linked_list_intersection(LinkList *list1, LinkList *list2) {
    is_valid(list1);
    is_valid(list2);
    Node *p1_pre = list1;
    Node *p1 = list1->next;
    Node *p2 = list2->next;

    Node *tmp = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->val == p2->val) {
            p1_pre = p1_pre->next;
            p1 = p1->next;
            tmp = p2;
            p2 = p2->next;
            free(tmp);
        } else {
            while (p1->val < p2->val) {
                tmp = p1;
                p1 = p1->next;
                p1_pre->next = p1;
                free(tmp);
            }
            while (p2->val < p1->val) {
                tmp = p2;
                p2 = p2->next;
                free(tmp);
            }
        }
    }
    while (p1 != NULL) {
        p1_pre->next = NULL;
        tmp = p1;
        free(tmp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        tmp = p2;
        p2 = p2->next;
        free(tmp);
    }
}

int linked_list_subsequence(LinkList *list1, LinkList *list2) {
    is_valid(list1);
    is_valid(list2);
    Node *p1 = list1->next;
    Node *p1_pre = p1;
    Node *p2 = list2->next;

    while (p1 != NULL && p2 != NULL) {
        if (p1->val == p2->val) {
            p1 = p1->next;
            p2 = p2->next;
        } else {
            p2 = list2->next;
            p1_pre = p1_pre->next;
            p1 = p1_pre;
        }
    }
    if (p2 == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void create_circle_double_direction_linked_list_with_empty_head_node(BiNode *empty_head) {
    is_valid_of_Bnode(empty_head);
    BiNode *node = NULL;
    BiNode *p = empty_head;

    Element_t value;
    printf("\033[1;31m--Please key the value which you want to store in linked list:\n");
    scanf("%d", &value);

    while (value != 9999) {
        node = (BiNode *) malloc(sizeof(BiNode));
        node->value = value;
        node->next = p->next;
        p->next = node;
        node->previous = p;
        p = p->next;
        empty_head->previous = p;
        fflush(stdin);
        printf("\033[0;31m--Please key the value which you want to store in linked list:\033[0m\n");
        scanf("%d", &value);
    }
}

void print_cricle_double_direction_linked_list(BiNode *empty_head, int method) {
    is_valid_of_Bnode(empty_head);
    BiNode *p = NULL;
    if (method == 1) {
        p = empty_head->next;
        printf("\033[1;35m");
        while (p != empty_head) {
            printf("%d\t", p->value);
            p = p->next;
        }
        printf("\033[0m\n");
    } else {
        p = empty_head->previous;
        printf("\033[1;35m");
        while (p != empty_head) {
            printf("%d\t", p->value);
            p = p->previous;
        }
        printf("\033[0m\n");
    }
}

int if_linked_list_symmetry(BiNode *empty_head) {
    is_valid_of_Bnode(empty_head);
    BiNode *p = empty_head->next;
    BiNode *q = empty_head->previous;

    while (p->next != q && p != q) {
        if (p->value == q->value) {
            p = p->next;
            q = q->previous;
        } else {
            return 0;
        }
    }
    return 1;
}

void combine_two_circle_linked_list(LinkList *list1, LinkList *list2) {
    is_valid(list1);
    is_valid(list2);

    Node *p1 = list1;
    Node *p2 = list2;

    while (p1->next != list1)p1 = p1->next;
    while (p2->next != list2)p2 = p2->next;

    p2->next = list1;
    p1->next = list2;
}

void create_circle_s_d_linked_list_with_empty_head_node(LinkList *empty_head) {
    is_valid(empty_head);
    Node *p = empty_head;

    Element_t value;
    printf("Please input the value which you want to add to link list and end with 9999.\n");
    scanf("%d", &value);

    while (value != 9999) {
        Node *node = (Node *) malloc(sizeof(Node));
        node->val = value;
        node->next = p->next;
        p->next = node;
        p = p->next;
        fflush(stdin);
        printf("Please input the value which you want to add to link list and end with 9999.\n");
        scanf("%d", &value);
    }
}

void destroy_circle_linked_list(LinkList *list) {
    Node *tmp = NULL;
    Node *p = list->next;
    while (p != NULL && p != list) {
        tmp = p;
        p = p->next;
        free(tmp);
    }
    free(list);
}

//p038-19
void print_cricle_linked_list_by_value_ASC(LinkList *list) {
    is_valid(list);
    Node *p, *pre;
    Node *min_pre;
    Node *min_node;
    while (list->next != list) {
        pre = list;
        p = list->next;
        min_pre = list;
        min_node = p;

        while (p != list) {
            if (p->val < min_node->val) {
                min_node = p;
                min_pre = pre;
            }
            pre = p;
            p = p->next;
        }
        printf("\033[1;31m%d", min_node->val);
        min_pre->next = min_node->next;
        free(min_node);
    }
    printf("\033[0m");
    free(list);
}

void create_frequent_linked_list(FreqNode *empty_head) {
    is_valid_of_freqNode(empty_head);
    FreqNode *p = empty_head;
    FreqNode *node = NULL;
    Element_t value;
    printf("\033[0;31mPlease input the value which you want to add to link list and end with 9999.\033[0m\n");
    scanf("%d", &value);

    while (value != 9999) {
        node = (FreqNode *) malloc(sizeof(FreqNode));
        node->value = value;
        node->frequent = 0;
        node->next = p->next;
        node->pre = p;
        p->next = node;
        p = p->next;
        fflush(stdin);
        printf("\033[0;31mPlease input the value which you want to add to link list and end with 9999.\033[0m\n");
        scanf("%d", &value);
    }
}

FreqNode *Locate(FreqNode *empty_head, Element_t x) {
    is_valid_of_freqNode(empty_head);
    FreqNode *p = empty_head->next;
    FreqNode *p_tmp = empty_head;

    while (p != NULL) {
        if (p->value == x) {
            p->frequent++;
            while (p->frequent < p_tmp->next->frequent) {
                p_tmp = p_tmp->next;
            }
            p->pre->next = p->next;
            if (p->next != NULL) {
                p->next->pre = p->pre;
            }

            p->next = p_tmp->next;
            p_tmp->next->pre = p;

            p_tmp->next = p;
            p->pre = p_tmp;
            break;
        }else{
            p = p->next;
        }
    }
    if (p == NULL){
        printf("\033[1;31mThree is not exit the node that value is：%d\033[0m\n", x);
        return NULL;
    }
    return p;
}

void find_Kth_backwards_value(LinkList *empty_head) {

}








