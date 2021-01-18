//
// Created by duwei on 2021/1/18.
//

/*
 * 相同的树
 * 链接：https://leetcode-cn.com/problems/same-tree/
 * */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){ // 递归遍历每个根结点
    if((p == NULL && q != NULL) || (p != NULL && q == NULL))  // 如果一个结点为空 一个结点不为空，则说明结构不同
    {
        return false;
    }

    if(p==NULL && q == NULL) // 两个结点同时为空，结构相同
    {
        return true;
    }

    if((p!=NULL && q!=NULL) && (p->val != q->val)) // 两个结点同时不为空时就比较他们的值
    {
        return false;
    }
    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right); // 递归比较左孩子、右孩子
}