/*
 * 两数之和
 * 链接：https://leetcode-cn.com/problems/two-sum/
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int* returnArr = (int*)malloc(sizeof(int)*2);
    for(int i = 0; i < numsSize;i++)
    {
        for(int j = 0; j < numsSize;j++)
        {
            if(nums[i] + nums[j] == target)
            {
                returnArr[0]=i;
                returnArr[1]=j;
                *returnSize=2;
                break;
            }
        }
    }
    return returnArr;
}
