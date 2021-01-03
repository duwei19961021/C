#pragma once
#include <stdio.h>

typedef int SListDataType;

typedef struct SListNode{
    SListDataType data;
    struct SListNode* next;
}SListNode;

void SListPushBack(SListNode** pphead, SListDataType x);
SListNode* CreateSListNode(SListDataType x);
void SListPopBack(SListNode** pphead);
void SListPushFront(SListNode** pphead, SListDataType x);
void SListPopFront(SListNode** pphead);
void SListPrint(SListNode* phead);
SListNode* SListFind(SListNode* phead, SListDataType x);
void SListInsertAfter(SListNode* pos, SListDataType x);
void SListEraseAfter(SListNode* pos);
void SListDestory(SListNode* phead);