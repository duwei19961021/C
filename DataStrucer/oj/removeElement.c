#include <stdio.h>

/*
 * 给你一个数组 nums和一个值 val，你需要 原地 移除所有数值等于val的元素，并返回移除后数组的新长度。
 * 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
 * 元素的顺序可以改变。
 * 你不需要考虑数组中超出新长度后面的元素。
 *
 * 给定 nums = [3,2,2,3], val = 3,
 * 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
 * 你不需要考虑数组中超出新长度后面的元素。
*/

int removeElement(int* nums, int numsSize, int val)
{
    int *pDel = nums, *pRet = nums;
    for (; pDel < nums+numsSize; pDel++) {
        if (val != *pDel){
            *pRet = *pDel;
            pRet++;
        }
    }
    return (int)(pRet - nums);
}

int main()
{
    int arr[] = {3,2,3,3,2};
    int numsSize = sizeof(arr) / sizeof(int );
    int ret = removeElement(arr,numsSize,3);
    printf("ret=%d\n",ret);
    printf("array:\n");
    for (int i = 0; i < ret; ++i) {
        printf("%d ",arr[i]);
    }
    return 0;
}