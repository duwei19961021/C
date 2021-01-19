//
// Created by duwei on 2021/1/19.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

TreeNode* Create(char* str,int* pi)
{
    if(str[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }
    else
    {
        TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
        newNode->val = str[*pi];
        (*pi)++;
        newNode->left = Create(str, pi);
        newNode->right = Create(str,pi);
        return newNode;
    }
}

void InOrder(TreeNode* root)
{
    if(!root)
    {
        return;
    }
    InOrder(root->left);
    printf("%c ",root->val);
    InOrder(root->right);
}

int main()
{
    char str[100];
    scanf("%s",str);
    int i = 0;
    TreeNode* root =  Create(str, &i);
    InOrder(root);
    return 0;
}