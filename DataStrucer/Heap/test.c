#include "Heap.h"
#include <time.h>
#define N 10

void PrintArray(int *arr, int arrSize)
{
    printf("[ ");
    for (int i = 0; i < arrSize; ++i)
    {
        printf("%d ",arr[i]);
    }
    printf("]\n");
}

void test01()
{
    srand((unsigned)time(NULL));
    HPDataType arr[N];
    for (int i = 0; i < N; ++i)
    {
        arr[i] = rand()%100;
    }
    printf("arr: ");
    PrintArray(arr,N);

    Heap hp;
    HeapInit(&hp,arr,N);
    printf("init: ");
    PrintArray(hp._a, hp._size);

    HeapPush(&hp,101);

    HeapPop(&hp);
    printf("after pop: ");
    PrintArray(hp._a,hp._size);

    HeapSort(&hp,hp._size);

    printf("after sort: ");
    PrintArray(hp._a,hp._size);

    HeapDestory(&hp);
}

void test02() // top k
{
    srand((unsigned)time(NULL));
    HPDataType arr[N];
    for (int i = 0; i < N; ++i)
    {
        arr[i] = rand()%100;
    }
    printf("arr: ");
    PrintArray(arr,N);

    Heap hp;
    HeapInit(&hp,arr,N);

    for (int i = 0; i < 3; ++i)
    {
        printf("%d\n",HeapTop(&hp));
        HeapPop(&hp);
    }
}


int main()
{
    test02();
    return 0;
}