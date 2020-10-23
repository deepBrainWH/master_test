//
// Created by wangheng on 4/22/20.
//叉排序树，也称为二叉查找树。可以是一颗空树，也可以是一颗具有如下特性的非空二叉树：
// 1. 若左子树非空，则左子树上所有节点关键字值均不大于根节点的关键字值；
// 2. 若右子树非空，则右子树上所有节点关键字值均不小于根节点的关键字值；
// 3. 左、右子树本身也是一颗二叉排序树。 现在给你N个关键字值各不相同的节点，
// 要求你按顺序插入一个初始为空树的二叉排序树中，每次插入后成功后，
// 求相应的父亲节点的关键字值，如果没有父亲节点，则输出-1。

#include <iostream>
#include <vector>

using namespace std;

typedef struct node {
    struct node *left;
    struct node *right;
    int val;

    node(int a, struct node *left, struct node *right) {
        this->left = left;
        this->right = right;
        this->val = a;
    }
} Node;

void pre_order(Node *root) {
    if (root == NULL)
        return;;
    cout << root->val << endl;
    pre_order(root->left);
    pre_order(root->right);
}

int main() {

    vector<int> nums = {2, 3, 4, 1, 3, 5, 2, 7, 5, 3, 8};
    Node *root = NULL;
    Node *p;
    for (int i = 0; i < nums.size(); i++) {
        if (root == NULL) {
            root = new Node(nums[i], NULL, NULL);
        } else {
            p = root;
            while (true) {
                if (nums[i] >= p->val) {
                    if (p->right == NULL) {
                        p->right = new Node(nums[i], NULL, NULL);
                        break;
                    } else {
                        p = p->right;
                    }
                } else {
                    if (p->left == NULL) {
                        p->left = new Node(nums[i], NULL, NULL);
                        break;
                    } else {
                        p = p->left;
                    }
                }
            }
        }
    }
    pre_order(root);
    return 0;
}