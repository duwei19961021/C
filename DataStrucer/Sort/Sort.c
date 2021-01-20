//
// Created by duwei on 2021/1/20.
//

#include "Sort.h"

void InsertSort(int* arr, int arrSize)
{
    for (int i = 0; i < arrSize-1; ++i)
    {
        int end = i; // 假设 0-end是有序数列，第一次end就是0,拿arr[1]和arr[0]比较
        int temp = arr[end+1]; // 选出end之后的第一个数
        while (end >= 0)
        {
            if(temp < arr[end]) // 升序
            {
                arr[end+1] = arr[end]; // 如果temp小于arr[end]，则说明要将end往后挪一次
                end--; // 然后end继续往前走,继续判断temp是否小于arr[end]
            }
            else
            {
                break; // 不小于arr[end]时直接跳出循环
            }
        }
        arr[end+1] = temp;
    }
}

void BubbleSort(int* arr, int arrSize)
{
    for (int i = 0; i < arrSize-1; ++i)
    {
        int flag = 0;
        for (int j = 0; j < arrSize-i-1; ++j)
        {
            if(arr[j] > arr[j+1])
            {
                flag = 1;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if (!flag)
            return;
    }
}

void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b= temp;
}

void AdJustDown(int* arr, int root, int arrSize)
{
    int parent = root;
    int child = parent*2 + 1;
    while (child < arrSize)
    {
        if (child+1 < arrSize && arr[child+1] > arr[child])
        {
            child++;
        }
        if(arr[parent] < arr[child])
        {
            Swap(&arr[parent],&arr[child]);
            parent = child;
            child = parent*2+1;
        }
        else
        {
            break;
        }
    }
}

void HeapSort(int* arr, int arrSize)
{
    for (int i = (arrSize-1-1)/2; i >=0 ; --i)
    {
        AdJustDown(arr,i,arrSize);
    }

    int end = arrSize-1;
    while (end > 0)
    {
        Swap(&arr[end],&arr[0]);
        end--;
        AdJustDown(arr,0,end);
    }
}