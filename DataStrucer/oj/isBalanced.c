//
// Created by duwei on 2021/1/19.
//

/*
 * 平衡二叉树
 * 链接：https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/
 * */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int Depth(struct TreeNode* root)
{
    if(!root)
    {
        return 0;
    }
    int leftDepth = Depth(root->left);
    int rightDepth = Depth(root->right);
    return 1 + (leftDepth > rightDepth ? leftDepth:rightDepth);
}

bool isBalanced(struct TreeNode* root){
    if(!root)
    {
        return true;
    }
    if(abs(Depth(root->left) - Depth(root->right)) > 1)
    {
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
}