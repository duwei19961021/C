#include <stdio.h>

/*
 * leetCoode
 * 数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
 * 输入:[3,0,1] 输出:2
 * 输入：[9,6,4,2,3,5,7,0,1] 输出: 8
 * */

int missingNumber(int* nums, int numsSize){
    int sum = 0;
    int i;
    for(i=0;i<numsSize;i++){
        if (i<numsSize){
            sum+=i-nums[i];
        }
    }
    return sum+i;
}

int main() {
    int nums[] = {1};
    int numSize = 1;
    int ret = missingNumber(nums,numSize);
    printf("ret = %d\n",ret);
    return 0;
}