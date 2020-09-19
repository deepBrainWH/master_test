//
// Created by wangheng on 2020/9/12.
// https://leetcode-cn.com/problems/delete-middle-node-lcci/
#include <iostream>
using namespace std;

typedef struct ListNode{
    char val;
    struct ListNode* next;
    ListNode(char x): val(x), next(NULL){}
    ListNode(char x, ListNode next):val(x), next(&next){}
}Node;

class Solution{
public:
    Solution(){
        Node* p;
        int i = 0;
        if(head == NULL){
            head = new Node('a');
            i++;
        }
        p = head;
        for(;i<7;i++){
            Node* node = new Node('a'+i);
            p->next = node;
            p = p->next;
        }
    }
    ~Solution(){
        Node* p = head;
        while (p){
            Node* tmp = p;
            p = p->next;
            delete(tmp);
        }
    }
    void deleteNode(ListNode* node){
        node->val = node->next->val;
        node->next = node->next->next;
    }
    void printListNode(){
        struct ListNode* p = this->head;
        while(p != nullptr){
            cout<<p->val<<" ";
            p = p->next;
        }
        cout<<endl;
    }
    
    struct ListNode* getHead(){
        return this->head;
    }

private:
    struct ListNode* head;
};

int main(){
    Solution s;
    s.printListNode();
    struct ListNode *head =s.getHead();
    s.deleteNode(head->next);
    s.printListNode();
    return 0;
}