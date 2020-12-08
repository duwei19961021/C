#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    int *pDel = nums, *pRet = nums;
    for (; pDel <= nums+numsSize-1; pDel++) {
        if (*pDel != *pRet){
            *++pRet=*pDel;
        }
    }
    pRet++;
    return (int)(pRet - nums);
}

int main()
{
    int arr[] = {1,1,2};

    int numsSize = sizeof(arr) / sizeof(int );

    int ret = removeDuplicates(arr,numsSize);

    printf("ret=%d\n",ret);

    printf("array:\n");
    for (int i = 0; i < ret; ++i) {
        printf("%d ",arr[i]);
    }
}