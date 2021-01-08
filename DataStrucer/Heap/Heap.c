//
// Created by duwei on 2021/1/7.
//

#include "Heap.h"

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void AdJustDown(HPDataType *a, int root, int n) // 前提: 左右子树是小堆, 根节点不满足。
{
    int parent = root;
    int child = parent*2+1;

    while (child < n)
    {
        // 找出左右孩子 小的孩子
        if (child+1 < n && a[child+1] < a[child])
        {
            child++;
        }

        // 如果小的孩子结点比父结点还小，那么就交换父结点和孩子结点，构建小堆
        if (a[child] < a[parent])
        {
            Swap(&a[child], &a[parent]);
            parent = child;
            child = parent*2 +1;
        }
        else // 如果child结点大于parent结点，则说明已经是一个小堆了，直接break
        {
            break;
        }
    }
}

void HeapInit(Heap* php, HPDataType* a, int n)
{
    php->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
    if (!php->_a)
    {
        printf("malloc failed.\n");
        exit(-1);
    }

    memcpy(php->_a,a,sizeof(HPDataType)*n);
    php->_size = n;
    php->_capacity = n;

    for (int i = (n-1-1)/2; i >= 0; --i) // 从最后一个非叶子结点开始构建堆
    {
        AdJustDown(php->_a,i,php->_size);
    }
}

void HeapDestory(Heap* php)
{

}

void HeapPush(Heap* php, HPDataType x)
{

}

void HeapPop(Heap* php)
{

}

HPDataType HeapTop(Heap* php)
{

}