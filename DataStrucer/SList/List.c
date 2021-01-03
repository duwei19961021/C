//
// Created by duwei on 2020/12/7.
//

#include "SList.h"
#include <stdlib.h>

SListNode* CreateSListNode(SListDataType x)
{
    SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
    if (NULL == newNode){
        printf("malloc failed.");
        exit(-1);
    }
    newNode->next = NULL;
    newNode->data = x;
    return newNode;
}

void SListPrint(SListNode* phead)
{
    while (NULL != phead){
        printf("%d->",phead->data);
        phead = phead->next;
    }
    printf("NULL\n");
}

void SListPushBack(SListNode** pphead, SListDataType x)
{
    SListNode* newNode = CreateSListNode(x);
    SListNode* tail = *pphead;
    if (NULL == *pphead){
        *pphead = newNode;
    } else{
        while (tail->next != NULL){
            tail = tail->next;
        }
        tail->next=newNode;
    }
}

void SListPopBack(SListNode** pphead)
{
    if (NULL == *pphead){
        return;
    } else if (NULL == (*pphead)->next){
        free(*pphead);
        *pphead = NULL;
    } else{
        SListNode* tail = *pphead;
        while (NULL != tail->next->next){
            tail = tail->next;
        }
        free(tail->next);
        tail->next = NULL;
    }
}

void SListPushFront(SListNode** pphead, SListDataType x)
{
    SListNode* newNode = CreateSListNode(x);
    if (NULL == *pphead){
        *pphead = newNode;
    } else{
        newNode->next = *pphead;
        *pphead = newNode;
    }
}

void SListPopFront(SListNode** pphead)
{
    if (NULL == *pphead){
        return;
    } else{
        SListNode* front = *pphead;
        *pphead = (*pphead)->next;
        free(front);
    }
}

SListNode* SListFind(SListNode* phead, SListDataType x)
{
    SListNode* point = (SListNode*)malloc(sizeof(SListNode));
    point = phead;
    while (NULL != point){
        if (x == point->data){
            return point;
        }
        point = point->next;
    }
    return NULL;
}

void SListInsertAfter(SListNode* pos, SListDataType x)
{
    SListNode* newNode = CreateSListNode(x);
    newNode->next = pos->next->next;
    pos->next = newNode;
}

void SListEraseAfter(SListNode* pos)
{
    SListNode* target = pos->next;
    if (NULL != target)
    {
        SListNode* targetNext = target->next;
        free(target);
        pos->next = targetNext;
    }
}

void SListDestory(SListNode* phead)
{
    SListNode *p = NULL, *q = NULL;
    p = phead;
    while (NULL != p)
    {
        q = p->next;
        free(q);
        p=p->next;
    }
    phead = NULL;
}