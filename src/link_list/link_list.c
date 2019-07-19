#include "link_list.h"

void create_link_list1(LinkList *list) {
    ll_is_valid(list);
    Element_t input = (Element_t) NULL;

    do{
        scanf("%d", &input);
        Node *node = (Node *) malloc(sizeof(Node));
        node->val = input;
        node->next = list->next;
        list->next = node;
        fflush(stdin);
    }while (input != 9999);
}

void ll_insert_element(LinkList *list, Element_t number) {

}

void ll_is_valid(LinkList *list) {
    if (list == NULL) {
        printf("The link list is invalid!\n");
        exit(-1);
    }
}

