//
// Created by duwei on 2021/1/21.
//

/*
 * 排序数组
 * 链接：https://leetcode-cn.com/problems/sort-an-array/*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize){ // 希尔排序
    int gap = numsSize;

    int* retNums = (int*)malloc(sizeof(int)*numsSize);
    for(int i =0;i<numsSize;i++)
    {
        retNums[i] = nums[i];
    }

    while(gap>1)
    {
        gap = gap/3+1;
        for(int i = 0;i<numsSize-gap;i++)
        {
            int end = i;
            int temp = retNums[end+gap];
            while(end>=0)
            {
                if(temp < retNums[end])
                {
                    retNums[end+gap] = retNums[end];
                    end-=gap;
                }
                else
                {
                    break;
                }
            }
            retNums[end+gap]=temp;
        }
    }
    *returnSize = numsSize;
    return retNums;
}