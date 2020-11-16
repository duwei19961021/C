#include <stdio.h>

int* find_int(int key, int arr[], int length)
{
    int i;
    for (i = 0; i < length; ++i) {
        if (key == arr[i]){
            return &arr[i];
        }
    }
    return NULL;
}

int main()
{
    int arr[] = {10,4,2,3,5,7,6,9,11};
    int length = sizeof(arr) / sizeof(arr[0]);
    int *ret = find_int(4,arr,length);
    printf("%d\n",ret-arr);
    return 0;
}