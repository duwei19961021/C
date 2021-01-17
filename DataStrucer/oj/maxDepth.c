//
// Created by duwei on 2021/1/17.
//

/*
 * 二叉树的最大深度
 * 链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
 * */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*
int maxDepth(struct TreeNode* root){ // 会重复递归
    if(!root)
    {
        return 0;
    }

    return 1+ (maxDepth(root->left) > maxDepth(root->right) ? maxDepth(root->left):maxDepth(root->right));
}
*/

int maxDepth(struct TreeNode* root){
    if(!root)
    {
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1+ (leftDepth > rightDepth ? leftDepth:rightDepth);
}
