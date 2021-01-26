//
// Created by duwei on 2021/1/20.
//

#include <stdio.h>
#include <stdlib.h>
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

int GetMidIdx(int* arr ,int left, int right) // 三数取中，让最坏的情况(有序或者接近有序)不会再出现
{
    int mid = (left+right)/2;
    if (arr[left] < arr[mid])
    {
        if (arr[mid] < arr[right])
        {
            return mid;
        }
        else if (arr[left] > arr[right])
        {
            return left;
        }
        else
        {
            return right;
        }
    }
    else // arr[left] >= arr[right]
    {
        if (arr[mid] > arr[right])
        {
            return mid;
        }
        else if (arr[left] < arr[right])
        {
            return left;
        }
        else
        {
            return right;
        }
    }
}

int PartSort(int* arr,int left, int right) // 将比key大的数放在key右边，比key小的数放在key左边
{
    int midIndex = GetMidIdx(arr,left,right);
    Swap(&arr[midIndex],&arr[right]);
    int keyIndex = right;
    while (left<right)
    {
        while (left<right && arr[left] <= arr[keyIndex])
        {
            left++;
        }
        while (left<right && arr[right] >= arr[keyIndex])
        {
            right--;
        }
        Swap(&arr[right], &arr[left]);
    }
    Swap(&arr[left],&arr[keyIndex]);
    return left; // 返回key的位置，因为key的左边比key小，key的右边全比key大，所以key是中间位置，下次循环不用再参加比较
}

void QuickSort(int* arr,int left, int right)
{
    if (left<right)
    {
        int  div = PartSort(arr,left,right); // key的位置
        QuickSort(arr,left,div-1); // key不再需要参与比较
        QuickSort(arr,div+1,right);
    }

}

// 非递归：1、提高效率(建立栈帧有消耗，可以忽略不计)
//        2、递归最大的缺陷是：如果栈帧的深度太深，可能会导致栈溢出，栈是M级别。
//           数据结构模拟非递归，数据是存储在堆上的，堆是G级别。
void QuickSortNoR(int* arr, int left, int right)
{
    Stack st;
    StackInit(&st);
    StackPush(&st,left); // 先将left、right依次入栈
    StackPush(&st,right);
    while (!StackEmpty(&st))
    {
        int right_ = StackTop(&st); // 由于入栈顺序是 left、right，所以先取出的是right
        StackPop(&st);
        int left_ = StackTop(&st); // 再取出left
        StackPop(&st);
        int div = PartSort(arr,left_,right_); // 调用子函数进行第一次排序
        // [left,div-1] div [div+1,right]
        if (div+1 < right_) // 再将右区间 [div+1,right_] push进栈
        {
            StackPush(&st,div+1); // 入栈顺序要保持一直
            StackPush(&st,right_);
        }
        if(left_<div-1) // 左区间进栈，[left_,div-1]
        {
            StackPush(&st,left_);
            StackPush(&st,div-1);
        }
        // 走到这里结束循环，再回到判断，由于栈 push进去了四个数字(两个区间下标)，栈不为空，
        // 再取出左区间进行排序，再分再入栈出栈，直至不可再分区间，再开始对右区间进行排序
    }
    StackDestory(&st);
}

// 将数组分割成N个有序小区间(1个数的区间，一个数也算有序)，再合并有序的数组
void _MergeSort(int* arr,int left, int right, int* tmp)
{
    if(left>=right) // 分割退出的条件
        return;
    int mid = (left+right)/2; // 拿到中间位置的索引，下一步递归分割，直到不可分为止(分割到只有一个数)
    _MergeSort(arr,left,mid,tmp); // 递归分割左半边
    _MergeSort(arr,mid+1,right,tmp); // 递归分割右半边
    int begin1 = left, end1 = mid; // 走到这里说明已经分割完了，分成了right+1个一个元素的数组
    int begin2 = mid+1, end2 = right;
    int index = begin1; // tmp区间起始位置

    while (begin1 <= end1 && begin2 <= end2) // 归并有序数组
    {
        if (arr[begin1] < arr[begin2])
        {
            tmp[index++] = arr[begin1++];
        }
        else
        {
            tmp[index++] = arr[begin2++];
        }
    }
    while (begin1<=end1)
        tmp[index++] = arr[begin1++];
    while (begin2<=end2)
        tmp[index++] = arr[begin2++];

    for (int i = left; i <= right; ++i) // 拷贝回原数组，拷贝一定是 <= 闭区间，因为right传入的是闭区间
    {
        arr[i] = tmp[i];
    }
}

// 归并，递归实现
void MergeSort(int* arr, int arrSize)
{
    int* tmp = malloc(sizeof(int)*arrSize);
    _MergeSort(arr,0,arrSize-1,tmp);
    free(tmp);

}

// 归并，非递归实现
void _MergeSortNoR(int* arr, int begin1, int end1, int begin2, int end2, int* tmp)
{
    int left = begin1,right = end2; // 这里必须使用新变量记录数组的起始结束位置，因为经过迭代后begin1会自增
    int index = begin1; // tmp区间起始位置
    while (begin1 <= end1 && begin2 <= end2) // 归并有序数组
    {
        if (arr[begin1] < arr[begin2])
        {
            tmp[index++] = arr[begin1++];
        }
        else
        {
            tmp[index++] = arr[begin2++];
        }
    }
    while (begin1<=end1)
        tmp[index++] = arr[begin1++];
    while (begin2<=end2)
        tmp[index++] = arr[begin2++];
    for (int i = left; i <= right; ++i)
    {
        arr[i] = tmp[i];
    }
}

void MergeSortNoR(int* arr, int arrSize)
{
    int* tmp = (int*)malloc(sizeof(int)*arrSize);
    int gap = 1;
    while (gap<arrSize)
    {
        for (int i = 0; i < arrSize; i+=2*gap)
        {
            // [i,i+gap-1] [i+gap, i+2*gap-1]
            int begin1 = i, end1 = i+gap-1, begin2 = i+gap, end2 =i+gap*2-1;
            if (begin2 >= arrSize) // begin2大于等于数组长度时说明只存在一组数据(无法分割成两组)
                break;
            if (end2>=arrSize) // end2大于等于数组长度则说明无法分割成均等的两组，end2超出了数组的范围
                end2 = arrSize-1; // 所以需要调整end2的位置，使其不能超出数组范围
            _MergeSortNoR(arr,begin1,end1,begin2,end2,tmp);
        }
        gap*=2;
    }
    free(tmp);
}
