//
// Created by duwei on 2021/1/7.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

/*
 * 冒泡排序的思想: 内外两层循环，每一次内循环都会将区间内最大的数移到最后的位置，逐次缩小区间
 * 时间复杂度:
 *          n个元素，第一次比较需要比较n-1次，第二次需要n-2次,......,0，总共需要比较的次数为: n(0+n-1)/2 => n^2
 */

void PrintArray(int *arr, int arrSize)
{
    printf("[ ");
    for (int i = 0; i < arrSize; ++i)
    {
        printf("%d ",arr[i]);
    }
    printf("]\n");
}

void BubbleSort(int* arr, int arrSize)
{
    for (int i = 0; i < arrSize-1; ++i)
    {
        int flag = 0;
        for (int j = 0; j < arrSize-1-i; ++j) // 内部每循环一次区间就可以缩小一，因为每次都会挑出一个最大数放在最后
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1; // 如果flag为1，则说明发生了数据交换，则说明排序还未完成
            }
        }

        if (!flag) // 如果flag为0则!flag为真，说明内部没有发生数据交换，排序已完成直接退出
        {
            break;
        }
    }
}

int main()
{
    srand((unsigned)time(NULL)); // 播种

    int arr[N];
    for (int i = 0; i < 20; ++i) {
        arr[i] = rand()%100;
    }

    printf("before sorted: ");
    PrintArray(arr,N);

    BubbleSort(arr,N);

    printf("after sorted: ");
    PrintArray(arr,N);

    return 0;
}