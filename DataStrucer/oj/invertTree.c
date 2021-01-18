//
// Created by duwei on 2021/1/18.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void Sawp(struct TreeNode** root) // 能进入这个循环说明root的左右孩子必然不可能全空，41行做过判断
{
    if((*root)->left == NULL) // 如果left为空则直接让right=left，left等于空进行交换
    {
        (*root)->left = (*root)->right;
        (*root)->right = NULL;
        return;
    }
    else if((*root)->left == NULL) // 同理
    {
        (*root)->right = (*root)->left;
        (*root)->left = NULL;
        return;
    }

    struct TreeNode* temp = (*root)->left;
    (*root)->left = (*root)->right;
    (*root)->right = temp;
}

void _invertTree(struct TreeNode** root) // 这里要传二级指针，不然传入的是一份拷贝
{
    if(*root==NULL) // 递归到叶子结点的left（空）、right（空）时无需处理
    {
        return;
    }

    if((*root)->left == NULL && (*root)->right == NULL) // 如果左右孩子同时为空，则无需交换
    {
        return;
    }
    Sawp(root);
    _invertTree(&(*root)->left); // 递归左右子树
    _invertTree(&(*root)->right);
}

struct TreeNode* invertTree(struct TreeNode* root){
    struct TreeNode* newRoot = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newRoot->left = NULL;
    newRoot->right = NULL;
    newRoot = root;
    if(!root)
    {
        return newRoot;
    }

    _invertTree(&newRoot);
    return newRoot;
}


////////////////////////////

struct TreeNode* invertTree(struct TreeNode* root){
    if(!root)
    {
        return NULL;
    }

    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}