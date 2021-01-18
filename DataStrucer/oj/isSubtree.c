//
// Created by duwei on 2021/1/18.
//

/*
 * 另一个树的子树
 * 链接：https://leetcode-cn.com/problems/subtree-of-another-tree/
 * */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isEqual(struct TreeNode* s, struct TreeNode* t) // 判断是否相同
{
    if((s == NULL && t != NULL) || (s != NULL && t == NULL))
    {
        return false;
    }

    if(s==NULL && t == NULL)
    {
        return true;
    }

    if((s!=NULL && t!=NULL) && (s->val != t->val))
    {
        return false;
    }
    return isEqual(s->left,t->left) && isEqual(s->right,t->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){
    if(!s) // 为空就直接返回不用比较
    {
        return false;
    }

    if(isEqual(s,t))
    {
        return true;
    }

    return isSubtree(s->left,t) || isSubtree(s->right,t); // 这里应该用 "||" 而不是 "&&"，只要有一次为true，那就是两个树相等了
}