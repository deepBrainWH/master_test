//
// Created by wangheng on 4/15/20.
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//typedef struct node{
//    int val;
//    struct node* left;
//    struct node* right;
//}TreeNode;
//
//class Solution{
//public:
//    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin){
//        TreeNode *head = new TreeNode;
//        head->val = pre[0];
//        vector<int> left;
//        vector<int> right;
//        int i = 0;
//        for(;vin[i] != pre[0];i++){
//            left.push_back(vin[i]);
//        }
//        for(int j = i+1;j<vin.size();j++){
//            right.push_back(vin[j]);
//        }
//
//    }
//};
