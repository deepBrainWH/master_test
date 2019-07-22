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

void insert_element(LinkList *list, Element_t number) {

}

void is_valid(LinkList *list) {
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

BiNode *create_cycle_doubly_linked_list() {

    return NULL;
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
    Node* t1 = p;
    Node* t2 = p->next;
    Node* t3 = NULL;

    while (t2!=NULL){
        if(t2->val==value){
            t3 = t2;
            t2 = t2->next;
            t1->next = t2;
            free(t3);
        }else{
            t1 = t1->next;
            t2 = t2->next;
        }
    }
}

void invert_print_linked_list(Node head) {
    if(head.next!=NULL){
        invert_print_linked_list(*head.next);
    }
    printf("%d\t", head.val);
}

void invert_print_linked_list2(LinkList *head) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    init_stack(stack);
    Node* p = head;
    while (p!=NULL){
        push_stack(stack, (stack_element_t)p->val);
        p = p->next;
    }

    while (!is_empty_stack(stack)){
        printf("%d\t", pop_stack(stack));
    }
    free_stack(stack);
}




