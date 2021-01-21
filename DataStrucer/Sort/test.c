//
// Created by duwei on 2021/1/20.
//

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Sort.h"
#define N 100000

int main()
{
    srand(time(NULL));
    int arr[N];
    for (int i = 0; i < N; ++i) {
        arr[i] = rand()%100;
    }

    int start = clock();
//    ShellSort(arr,N); // 10w: 0.0156s
//    InsertSort(arr,N); // 10w: 5.0256s
//    HeapSort(arr,N); // 10w: 0.0203s
//    BubbleSort(arr,N); // 10w: 25.2067s
    SelectSort(arr,N); // 10w: 8.8934s, 优化之后: 6.1726s
    int end = clock();
    printf("spend: %3.4f s\n",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}