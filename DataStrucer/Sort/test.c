//
// Created by duwei on 2021/1/20.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Sort.h"
#define N 7

void PrintArr(int* arr, int Size)
{
    printf("[ ");
    for (int i = 0; i < Size; ++i)
    {
        printf("%d ",arr[i]);
    }
    printf("]\n");
}

int main()
{
    srand(time(NULL));
    int arr[N];
    for (int i = 0; i < N; ++i) {
        arr[i] = rand()%100;
    }
    PrintArr(arr,N);
    HeapSort(arr,N);
    PrintArr(arr,N);
    return 0;
}