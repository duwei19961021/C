//
// Created by duwei on 2021/1/20.
//

#include <stdio.h>
#include "Sort.h"

void PrintArr(int* arr, int Size)
{
    printf("[ ");
    for (int i = 0; i < Size; ++i)
    {
        printf("%d ",arr[i]);
    }
    printf("]\n");
}

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

// O(N^1.3 ~ N^2)
void ShellSort(int* arr, int arrSize)
{
    int gap = arrSize;
    /*
     * gap越大，靠前位置的数据越快被移动到靠后位置。靠后越小的数据越快被移动到靠前。
     * gap越大越不接近有序
     * gap越小越接近有序。gap==1就是插入排序。
     */
    while (gap>1)
    {
        gap = gap/3+1;
        for (int i = 0; i < arrSize-gap; ++i)
        {
            int end = i;
            int temp = arr[end+gap];
            while (end>=0)
            {

                if(temp<arr[end])
                {
                    arr[end+gap] = arr[end];
                    end-=gap;
                }
                else
                {
                    break;
                }
            }
            arr[end+gap] = temp;
        }
    }
}

/*
// 第一个版本
void SelectSort(int* arr, int arrSize)
{
    for (int i = 0; i < arrSize; ++i)
    {
        int max = i;
        for (int j = i+1; j < arrSize; ++j) // 选出最小的和i位置交换，也就是没次选一个最小数往前放。
        {
            if (arr[j] < arr[max])
            {
                max = j;
            }
        }
        Swap(&arr[max],&arr[i]);
    }
}
*/

// 选择排序优化版本
void SelectSort(int* arr, int arrSize)
{
    for (int begin = 0, end=arrSize-1; begin <= end; ++begin,--end)
    {
        int min = begin;
        int max = begin;
        for (int j = begin+1; j < arrSize-begin; ++j) // 选出最小的和i位置交换，也就是没次选一个最小数往前放。
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
            else if(arr[j] > arr[max])
            {
                max = j;
            }
        }
        Swap(&arr[min],&arr[begin]);
        if(begin==max)// 如果max和begin重叠，在经过上一行代码的交换之后，min位置保存的是最大值(max和begin指向同一个位置，begin和min交换之后，min指向的位置变成了最大值，要将max指向min的位置)
        {
            max=min;
        }
        Swap(&arr[max],&arr[end]);
    }
}