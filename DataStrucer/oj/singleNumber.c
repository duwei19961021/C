//
// Created by duwei on 2020/12/10.
//

/*
 * 给定一个整数数组nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。
 * 找出只出现一次的元素。
 * */

#include <stdio.h>
#include <stdlib.h>
#define N 8

int* singleNumber(int* nums, int numSize, int* returnSize)
{
    int ret = 0;
    for (int i = 0; i < numSize; ++i) {
        ret ^= nums[i];
        /*
         * 相同的数异或得0，那么整个数组异或完之后的结果 必定是两个出现一次的数异或的结果
         * */
    }
    int m = 0;
    while (m<32)
    {
        if (ret & (1<<m)){
            break;
        } else{
            m++;
        }
        /*
         * 找到ret上为1的任意位。
         * ret的二进制上 为1，则说明异或的两个数在这个比特位上的二进制数是不同的，一个为1一个为0
         * */
    }
    int x1 = 0,x2 = 0;
    for (int i = 0; i < numSize; ++i)
    {
        if (nums[i] & (1<<m))
        {
            x1^=nums[i];
        } else{
            x2^=nums[i];
        }
        /*
         * 开始进行分组。
         * 数组中的数在m位上为1的分到一组，为0的分到一组进行异或。*/
    }
    int *returnArr = malloc(sizeof(int)*2);
    returnArr[0]=x1;
    returnArr[1]=x2;
    *returnSize=2;
    return returnArr;
}

int main()
{
    int arr[N] = {1,2,1,2,6,6,3,5};
    int returnSize = 0;
    int *ret = singleNumber(arr, N, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ",ret[i]);
    }
    return 0;
}
