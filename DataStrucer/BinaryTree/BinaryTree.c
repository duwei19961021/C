//
// Created by duwei on 2021/1/13.
//

//
// Created by duwei on 2021/1/13.
//

#include <stdlib.h>
#include <stdio.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
    BTDataType _data;
    struct BinaryTreeNode* _left;
    struct BinaryTreeNode* _right;
}BTNode;

BTNode* CreateNode(char x)
{
    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
    if (!node)
    {
        printf("malloc failed.\n");
        exit(-1);
    }

    node->_data = x;
    node->_left = NULL;
    node->_right = NULL;
    return node;
}

void PrevOrder(BTNode* root) // 前序
{
    if (!root)
    {
//        printf("NULL ");
        return;
    }
    printf("%c ",root->_data);
    PrevOrder(root->_left);
    PrevOrder(root->_right);
}

void InOrder(BTNode* root) // 中序
{
    if (!root)
    {
//        printf("NULL ");
        return;
    }
    InOrder(root->_left);
    printf("%c ",root->_data);
    InOrder(root->_right);
}

void PostOrder(BTNode* root) // 后序
{
    if (!root)
    {
        printf("NULL ");
        return;
    }
    InOrder(root->_left);
    InOrder(root->_right);
    printf("%c ",root->_data);
}

int TreeSize(BTNode* root)
{
    if (!root)
    {
        return 0;
    }

    return 1+TreeSize(root->_left) + TreeSize(root->_right); // 递归到空返回
}

int TreeLeafSize(BTNode* root)
{
    if (root == NULL)
        return 0;

    if (!root->_left && !root->_left) // 左右结点都为空则说明是叶子结点,递归到叶子结点就可以结束,所以可以return
        return 1;

    return TreeLeafSize(root->_left) + TreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k) // 当前树的第k层可以转换成左右子树的第k-1层，层数==1时不需要再分解
{
    if (!root)
        return 0;
    if (k==1)
        return 1;
    return BinaryTreeLevelKSize(root->_left,k-1) + BinaryTreeLevelKSize(root->_right,k-1);
}

BTNode* BinaryTreeFind(BTNode* root,BTDataType x)
{
    if (!root)
        return NULL;
    if (root->_data == x)
        return root;
    BTNode* LNode = BinaryTreeFind(root->_left,x);
    if (LNode)
    {
        return LNode;
    }

    BTNode* RNode = BinaryTreeFind(root->_right,x);
    if (RNode)
    {
        return RNode;
    }
    return NULL;
}


int main()
{
    BTNode* A = CreateNode('A');
    BTNode* B = CreateNode('B');
    BTNode* C = CreateNode('C');
    BTNode* D = CreateNode('D');
    BTNode* E = CreateNode('E');
    A->_left = B;
    A->_right = C;
    B->_left = D;
    B->_right = E;

    PrevOrder(A); // 前序
    printf("\n");

    InOrder(A); // 中序
    printf("\n");

    PostOrder(A); // 后序
    printf("\n");

    printf("TreeSize = %d\n",TreeSize(A));
    printf("TreeLeafSize = %d\n",TreeLeafSize(A));
    return 0;
}