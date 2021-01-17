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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
 * 二叉树的前序遍历
 * 链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
 */

int TreeSize(struct TreeNode* root)
{
    if(!root)
    {
        return 0;
    }

    return 1 + TreeSize(root->left) + TreeSize(root->right);
}

void _preorderTraversal(struct TreeNode* root,int* retarr, int* size)
{
    if(!root)
    {
        return;
    }
    retarr[*size] = root->val;
    (*size)++;
    _preorderTraversal(root->left,retarr,size);
    _preorderTraversal(root->right,retarr,size);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    int* retarr = (int*)malloc(sizeof(int)*TreeSize(root));
    _preorderTraversal(root,retarr,returnSize);
    return retarr;
}