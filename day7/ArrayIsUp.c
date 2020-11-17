#include <stdio.h>
int IsUp(int *arr, int num)
{
    int ret;
    if (num == 1){
        return 1;
    }
    ret = (arr[num-1] - arr[num-2] > 0);
    return ret && IsUp(arr,num-1);
}

int main()
{
    int arr[] = {1,2,3,4,9,9,2};
    int length = sizeof(arr) / sizeof(arr[0]);
    if (IsUp(arr,length)){
        printf("数组递增\n");
    } else{
        printf("数组非递增\n");
    }
    return 0;
}