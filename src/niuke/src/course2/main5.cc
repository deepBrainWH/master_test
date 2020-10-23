//
// Created by wangheng on 3/9/20.
//
#include <iostream>

using namespace std;

template<typename T>
struct node {
    T val;
    struct node *next;

    node() {}

    node(T v) {
        val = v;
        next = nullptr;
    }
};

typedef struct node<double> IntNode;

IntNode *construct_link_list() {
    int n;
    cin >> n;
    IntNode *root = nullptr;
    IntNode *p = root;
    for (int i = 0; i < n; i++) {
        IntNode *tmpNode = new IntNode;
        cin >> tmpNode->val;
        tmpNode->next = nullptr;
        if (root == nullptr) {
            root = tmpNode;
            p = root;
        } else {
            p->next = tmpNode;
            p = p->next;
        }
    }
    return root;
}

IntNode *revertLinkedList(IntNode *head) {
    if (head->next == nullptr){
        return head;
    }
    IntNode *last = revertLinkedList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return last;
}

IntNode *successor = nullptr;
IntNode *revertLinkedList(IntNode* head, int n){
    if(n == 1){
        successor = head->next;
        return head;
    }
    IntNode *last = revertLinkedList(head->next, n - 1);
    head->next->next = head;
    head->next = successor;
    return last;
}

IntNode *revertLinkedList(IntNode* head, int m, int n){
    if(m == 1){
        return revertLinkedList(head, n);
    }
    head->next = revertLinkedList(head->next, m-1, n-1);
    return head;
}



void print_link_list(IntNode *root) {
    IntNode *p = root;
    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    IntNode *root = construct_link_list();
    print_link_list(root);
    IntNode *reversed = revertLinkedList(root);
    print_link_list(reversed);
    IntNode *revert2 = revertLinkedList(reversed, 3);
    print_link_list(revert2);
    IntNode *revert3 = revertLinkedList(revert2, 2, 5);
    print_link_list(revert3);
    return 0;
}
