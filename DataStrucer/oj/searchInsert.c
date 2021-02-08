//
// Created by duwei on 2021/2/8.
//

/*
 * 链接：https://leetcode-cn.com/problems/search-insert-position/submissions/
 * 搜索插入位置
 */

int binarySerrch(int* nums, int numsSize, int target, int* midIndex) // 二分查找，找到返回下标，没找到返回-1，并且利用midIndex记录最后一次mid
{
    int index = -1;
    int left = 0, right = numsSize-1, mid = (left+right)/2;
    while(left <= right)
    {
        if(target > nums[mid])
            left = mid+1;
        if(target < nums[mid])
            right = mid-1;
        if(target == nums[mid])
        {
            index = mid;
            break;
        }
        *midIndex = mid = (left+right)/2;
    }
    return index;
}

int searchInsert(int* nums, int numsSize, int target)
{
    int midIndex = -1;
    int ret = binarySerrch(nums,numsSize,target,&midIndex);
    if(ret == -1 && nums[midIndex] > target)
        return midIndex;
    else if(ret == -1 && nums[midIndex] < target)
        return midIndex+1;
    else
        return ret;
}