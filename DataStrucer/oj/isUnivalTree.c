//
// Created by duwei on 2021/1/17.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*
 * 判断是否为单值二叉树。
 * 链接：https://leetcode-cn.com/problems/univalued-binary-tree/
 */


bool isUnivalTree(struct TreeNode* root){
    if(!root)
    {
        return true;
    }

    if(root->left != NULL && root->left->val != root->val)  // 必须先判断left是否是空，不然会造成访问空指针的错误
    {
        return false;
    }

    if (root->right != NULL && root->right->val != root->val)
    {
        return false;
    }

    return isUnivalTree(root->left) && isUnivalTree(root->right); // 递归 左子树 和 右子树
}