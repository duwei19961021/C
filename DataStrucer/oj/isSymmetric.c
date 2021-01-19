//
// Created by duwei on 2021/1/19.
//

/*
 * 对称的二叉树
 * 链接：https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/
 * */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool IsEquel(struct TreeNode* L, struct TreeNode* R)
{
    if(L == NULL && R == NULL) // 判断左右是否同时为空，则结构相同
    {
        return true;
    }

    if((L==NULL && R!=NULL) || (L!=NULL && R==NULL)) // 判断是否是做空右不空，左不空右空，结构不同则不是镜像
    {
        return false;
    }

    if(L->val != R->val) // 判断val
    {
        return false;
    }
    return IsEquel(L->left,R->right) && IsEquel(L->right,R->left); // 先递归L的左和R的右（外层），再递归L的右和R的左（内层）
}

bool isSymmetric(struct TreeNode* root){
    if(!root)
    {
        return true;
    }
    return IsEquel(root->left,root->right);
}