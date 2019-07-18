#include "single_direct_linked_list.h"

Node* create_single_linked_list()
{
    Node* head = NULL;
    Node* p = NULL;
    for(int i = 0; i<5; i++)
    {
        if(head == NULL)
        {
            head = (Node*)calloc(1, sizeof(Node));
            head->val = 10;
            head->next = NULL;
        }
        else
        {
            if(p==NULL)
            {
                p = head;
            }
            Node* node = (Node*)calloc(1, sizeof(Node));
            node->val = i+4;
            node->next = NULL;
            p->next = node;
            p = p->next;
        }
    }
    return head;
}

void free_linked_list(Node* root)
{
    while(root != NULL)
    {
        Node* p = root;
        root = root->next;
        free(p);
    }
}

void print_linked_list(Node* root)
{
    Node* p = root;
    while(p!=NULL){
        printf("%d \n", p->val);
        p = p->next;
    }
}



