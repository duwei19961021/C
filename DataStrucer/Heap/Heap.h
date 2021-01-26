//
// Created by duwei on 2021/1/7.
//

#ifndef C_HEAP_H
#define C_HEAP_H

typedef int HPDataType;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Heap
{
    HPDataType* _a;
    int _size;
    int _capacity;
} Heap;

void HeapInit(Heap* php, HPDataType* a, int n);
void HeapDestory(Heap* php);
void HeapPush(Heap* php, HPDataType x);
void HeapPop(Heap* php);
HPDataType HeapTop(Heap* php);
void HeapSort(Heap* php,int n);
int HeapSize(Heap* php);
int HeapEmpty(Heap* php);

#endif //C_HEAP_H