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

void AdJustUp(HPDataType *a, int child, int n)
{
    int parent = (child-1) / 2;
    while (child > 0)
    {
        if (a[child] < a[parent])
        {
            Swap(&a[child],&a[parent]); // 如果新增的结点比父结点要小(在此构建的是小堆)，则交换父子结点的位置
            child = parent;
            parent = (child-1)/2;
        }
        else
        {
            break; // 如果新增结点比它的父结点要小，则无需交换
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

void HeapSort(Heap* php,int n)
{
    for (int i = (n-1-1)/2; i >= 0; --i) // 从最后一个非叶子结点开始构建堆
    {
        AdJustDown(php->_a,i,php->_size);
    }

    // 构建完成之后，堆顶数据是最小的，
    int  end =  n-1;
    while (end > 0)
    {
        Swap(&php->_a[0],&php->_a[end]); // 将堆顶数据(最小)与数组最后一个数据交换，将最小数据放在数组的末尾
        end--; // 调整数组长度(排除掉Swap的数，因为每次swap之后数组末尾已经是最小的数了，没必要再参与堆构建)
        AdJustDown(php->_a,0,end);
    }
}

void HeapDestory(Heap* php)
{
    assert(php);
    free(php->_a);
    php->_a = NULL;
    php->_capacity = php->_size = 0;
}

void HeapPush(Heap* php, HPDataType x)
{
    assert(php);
    if (php->_size == php->_capacity) // 扩容
    {
        php->_capacity *= 2;
        php->_a = (HPDataType*)realloc(php->_a,sizeof(HPDataType) * php->_capacity);
    }
    php->_a[php->_size++] = x;
    AdJustUp(php->_a,php->_size-1,php->_size); // 重新构建堆，新增结点只会影响父结点
}

void HeapPop(Heap* php)
{
    assert(php);
    assert(php->_size > 0);

    Swap(&php->_a[0],&php->_a[php->_size-1]); // 将堆顶数组交换到末尾(数组)去
    php->_size--; // 调整size的执向，丢弃最后一个元素
    AdJustDown(php->_a,0,php->_size); // 然后从堆顶开始重新构建堆
}

HPDataType HeapTop(Heap* php)
{
    assert(php);
    return php->_a[0];
}

/*
 * top k问题:
 * 建堆 => HeapPop 3次, 选出最前三
 * */