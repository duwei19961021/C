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