//
// Created by wangheng on 3/2/20.
//
#include <iostream>
#include <vector>
using namespace std;
template <class T>
struct Node{
    T val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(T x){
        this->val = x;
    }
    Node(T x, Node* left, Node* right){
        this->val = x;
        this->left = left;
        this->right = right;
    }
};
//declare the definition of functions.
template <class T>
struct Node<T>* build(vector<T> &preOrder, int ps, int pe, vector<T> &inOrder, int is, int ie);
template <class T>
struct Node<T>* buildTree(vector<T> &preOrder, vector<T> &inOrder);

template <class T>
struct Node<T>* buildTree(vector<T> &preOrder, vector<T> &inOrder){
    if(preOrder.size() == 0 || inOrder.size() == 0 || preOrder.size() != inOrder.size()){
        return nullptr;
    }
    return build(preOrder, 0, preOrder.size()-1, inOrder, 0, inOrder.size()-1);
}
template <class T>
struct Node<T>* build(vector<T> &preOrder, int ps, int pe, vector<T> &inOrder, int is, int ie){
    Node<T> *root = new Node<T>(preOrder[ps]);
    int i = is;
    while (i<ie && inOrder[i] != preOrder[ps]){
        i++;
    }
    int leftLen = i - is;
    int rightLen = ie - i;

    if(leftLen>0){
        root->left = build(preOrder, ps+1, ps+leftLen-1, inOrder, is, is+leftLen-1);
    }
    if(rightLen>0){
        root->right = build(preOrder,ps+leftLen+1, pe, inOrder, is+leftLen+1, ie);
    }
    return root;
}

template <class T>
void preOrder(Node<T>* root){
    if(root != nullptr){
        cout<<root->val<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}


int main(){

    vector<char> pre;
    vector<char> inOrd;
    pre.push_back('A');
    pre.push_back('B');
    pre.push_back('E');
    pre.push_back('C');
    pre.push_back('D');
    pre.push_back('F');
    pre.push_back('G');
    pre.push_back('H');
    pre.push_back('I');
    pre.push_back('J');

    inOrd.push_back('E');
    inOrd.push_back('B');
    inOrd.push_back('C');
    inOrd.push_back('D');
    inOrd.push_back('A');
    inOrd.push_back('F');
    inOrd.push_back('H');
    inOrd.push_back('I');
    inOrd.push_back('G');
    inOrd.push_back('J');
    Node<char> *pNode = buildTree(pre, inOrd);
    preOrder(pNode);


    return 0;
}

