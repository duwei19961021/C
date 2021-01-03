//
// Created by duwei on 2021/1/1.
//

#include "DList.h"

void ListInit(ListNode **pphead)
{
    *pphead = BuyLIstNode(0);
    (*pphead)->next = *pphead;
    (*pphead)->prev = *pphead;
}

void ListPrint(ListNode *phead)
{
    assert(phead);
    ListNode* cur = phead->next;
    while (cur != phead)
    {
        printf("%d ",cur->data);
        cur = cur->next;
    }
    printf("\n");
}

ListNode* BuyLIstNode(LTDataType x)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    if (!node)
    {
        return NULL;
    }
    node->next = NULL;
    node->prev = NULL;
    node->data = x;
    return node;
}

void ListPushBack(ListNode *phead, LTDataType x)
{
    assert(phead);

    ListNode* tail = phead->prev;
    ListNode* newNode = BuyLIstNode(x);

    tail->next = newNode;
    newNode->prev = tail;

    newNode->next = phead;
    phead->prev = newNode;
}

void ListPopBack(ListNode *phead)
{
    assert(phead);
    if (phead->next == phead)
    {
        return;
    }
    ListNode *tail = phead->prev;
    phead->prev = tail->prev;
    tail->prev->next = phead;
    free(tail);
}

void ListPushFront(ListNode *phead, LTDataType x)
{
    assert(phead);

    ListNode *first = phead->next;
    ListNode *newNode = BuyLIstNode(x);
    if (!newNode)
    {
        return;
    }

    phead->next = newNode;
    newNode->prev = phead;

    newNode->next = first;
    first->prev = newNode;
}

void ListPopFront(ListNode *phead)
{
    if (phead->next == phead)
    {
        printf("List is NULL!\n");
        return;
    }
    ListNode *first = phead->next;
    phead->next = first->next;
    first->next->prev = phead;
    free(first);
}

ListNode* ListFind(ListNode *phead, LTDataType x)
{
    assert(phead);
    ListNode *cur = phead->next;
    while (cur != phead)
    {
        if(cur->data == x)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

void ListInsert(ListNode *pos, LTDataType x)
{
    ListNode *newNode = BuyLIstNode(x);
    if(!newNode)
    {
        return;
    }

    newNode->next = pos;
    newNode->prev = pos->prev;
    pos->prev->next = newNode;
    pos->prev = newNode;
}

void ListErase(ListNode* pos)
{
    assert(pos);
    pos->prev->next = pos->next;
    pos->next->prev  = pos->prev;
    free(pos);
}

void ListClear(ListNode *phead)
{
    assert(phead);

    ListNode *cur = phead->next;
    while (cur != phead)
    {
        ListNode *next = cur->next;
        free(cur);
        cur = next;
    }

    phead->next = phead;
    phead->prev = phead;
}

void ListDestory(ListNode **pphead)
{
    assert(*pphead);

    ListClear(*pphead);

    free(*pphead);
    *pphead = NULL;
}