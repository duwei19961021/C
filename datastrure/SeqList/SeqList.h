#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SeqList
{
    SLDataType *a;
    int size;   // 有效数据元素个数
    int cap;    // 容量
} SL,SeqList;

void SeqListInit(SL *ps);
void SeqListPrint(SL *ps);
void SeqListCheckCap(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);