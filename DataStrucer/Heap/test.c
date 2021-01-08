#include "Heap.h"
#include <time.h>
#define N 9

void PrintArray(int *arr, int arrSize)
{
    printf("[ ");
    for (int i = 0; i < arrSize; ++i) {
        printf("%d ",arr[i]);
    }
    printf("]");
}

int main()
{
    srand((unsigned)time(NULL));
    HPDataType arr[N];
    for (int i = 0; i < N; ++i) {
        arr[i] = rand()%100;
    }

    PrintArray(arr,N);

    Heap hp;
    HeapInit(&hp,arr,N);

    PrintArray(hp._a,N);
    return 0;
}