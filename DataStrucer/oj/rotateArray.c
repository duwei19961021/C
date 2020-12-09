//
// Created by duwei on 2020/12/8.
//

#include <stdio.h>

void rotate(int* nums, int numsSize, int k){
    for (int i = numsSize-1; i >= 0 ; --i) {
        int temp = nums[i];
        nums[i] = nums[i-1];
    }
}

int main()
{
    int nums[] = {1,2,3,4};
    int numsSize = sizeof(nums) / sizeof(int);
    rotate(nums,numsSize,2);
    for (int i = 0; i < numsSize; ++i) {
        printf("%d ",nums[i]);
    }
}