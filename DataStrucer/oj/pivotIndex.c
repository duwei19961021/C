/*
 * 寻找数组的中心索引
 * 链接：https://leetcode-cn.com/problems/find-pivot-index/
 */

int pivotIndex(int* nums, int numsSize)
{
    int leftSum = 0, rightSum = 0, sum = 0;
    for(int i = 0; i < numsSize; i++) // 先求出数组的和
        sum += nums[i];
    for(int i = 0; i < numsSize; i++)
    {
        leftSum += nums[i]; // 累加leftSum
        rightSum = sum - leftSum + nums[i]; // rightSum 的值就是sum-leftSum + nums[i],leftSum循环时已经先加上了nums[i],所以rightSum也要加上nums[i](两个相等的数加上一个相同的数之后它们仍然相等)
        if (leftSum == rightSum) 
            return i;
    }
    return -1;
}
