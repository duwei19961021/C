#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int CompareInt(const void *x, const void *y)
{
    return (*(int*)x - *(int *)y);
}

void swap(char *src, char *dest, int width)
{
    while (width--){
        char temp = *src;
        *src = *dest;
        *dest = temp;
        src++;
        dest++;
    }
}

int my_qsort(void *arr, int size, int width, int (*compare)(const void *, const void *))
{
    assert(arr!=NULL);
    assert(compare!=NULL);

    char *e = (char *)arr;

    for (int i = 0; i < size - 1; ++i) {
        int flag = 0;
        for (int j = 0; j < size-i-1; ++j) {
            if (compare(e+j*width, e+(j+1)*width) > 0){
                flag = 1;
                swap(e+j*width, e+(j+1)*width, width);
            }
        }
        if (!flag){
            printf("break\n");
            break;
        }
    }
}

int main()
{
    int arr[] = {10,  9, 8, 7, 6, 100, 5, 4, 3, 2, 1};
    int num = sizeof(arr)/sizeof(arr[0]);
//    qsort(arr,num,sizeof(int),CompareInt);
    my_qsort(arr,num,sizeof(int),CompareInt);

    for (int i = 0; i < num; ++i) {
        printf("%d ",arr[i]);
    }
    return 0;
}