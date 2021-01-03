//
// Created by duwei on 2021/1/1.
//

#include "Stack.h"

void StackInit(Stack* pst)
{
    pst->_top = 0;
    pst->_a = (STDataType *)malloc(sizeof(STDataType) * 4);
    if (!pst->_a)
    {
        printf("malloc failed.\n");
        exit(-1);
    }
    pst->_capacity = 4;
}

void StackDestory(Stack* pst)
{
    assert(pst);
    free(pst->_a);
    pst->_a = NULL;
}

void StackPush(Stack* pst, STDataType x)
{
    assert(pst);
    if (pst->_top == pst->_capacity)
    {
        pst->_a = (STDataType*)realloc(pst->_a,sizeof(STDataType)*pst->_capacity*2);
        if (!pst->_a)
        {
            printf("realloc failed.\n");
            exit(-1);
        }
        pst->_capacity *= 2;
    }

    pst->_a[pst->_top] = x;
    pst->_top++;
}

void StackPop(Stack* pst)
{
    assert(pst);
    assert(pst->_top > 0);
    --pst->_top;
}

int StackSize(Stack* pst)
{
    assert(pst);
    return pst->_top;
}

int StackEmpty(Stack* pst)
{
    assert(pst);
    return !pst->_top;
}

STDataType StackTop(Stack* pst)
{
    assert(pst);
    assert(pst->_top > 0);
    return pst->_a[pst->_top-1];
}

void PrintStack(Stack* pst)
{
    printf("[ ");
    for (int i = 0; i < pst->_top; ++i) {
        printf("%d ",pst->_a[i]);
    }
    printf("]\n");
}