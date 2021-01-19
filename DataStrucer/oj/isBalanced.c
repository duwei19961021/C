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
    // 前序方式,会重复计算，由顶自下计算，第二层计算深度需要将第三层开始的子树都计算一次，
    // 第三层计算深度要将第四层开始的子树都计算一次，类推，复杂度O(N*N)
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

///////////////////////////////////////////
// 第二种解法 优化到O(N),从叶子结点开始计算，并将高度返回给上一层，因此只需遍历一次二叉树（由底至顶）。

bool _isBalanced(struct TreeNode* root, int* pDepth)
{
    if(root == NULL) // root结点进入函数，如果不为空，则会递归调用，直到为空。也是这个题优化的关键，从叶子结点开始计算高度，通过指针将高度返回给上层函数（计算一层将高度返回给上一层，避免重复计算）
    {
        *pDepth = 0;
        return true;
    }
    else
    {
        // 先左子树再右子数最后检查根
        // 顺序：左孩子 => 左孩子 => 左孩子 ..... => NULL 返回上一层 => 右孩子 ...... 返回上一层 => 右孩子 ...... => 返回到上一层..... , 直到返回到根节点时调用的返回结束
        int leftDepth = 0;
        if(_isBalanced(root->left,&leftDepth) == false)
        {
            return false;
        }

        int rightDepth = 0;
        if(_isBalanced(root->right,&rightDepth) == false)
        {
            return false;
        }

        if(abs(leftDepth-rightDepth) > 1)
        {
            return false;
        }
        else
        {
            *pDepth = leftDepth > rightDepth ? leftDepth+1:rightDepth+1; // 通过pDepth将本层的高度告诉上一层
            return true;
        }
    }
}

bool isBalanced(struct TreeNode* root){
    int depth = 0;
    return _isBalanced(root,&depth);
}