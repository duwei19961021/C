//
// Created by duwei on 2021/2/9.
//

/*
 * 链接：https://leetcode-cn.com/problems/palindrome-number/submissions/
 * 回文数
 */

bool isSame(int* nums, int arrSize)
{
    int start = 0;
    int end = arrSize-1;
    while(start <= end)
    {
        if(nums[start++] != nums[end--])
            return false;
    }
    return true;
}

bool isPalindrome(int x){
    if(x < 0)
        return false;
    int nums[10];
    int j = 0;
    while(x > 0)
    {
        nums[j++] = x%10;
        x /= 10;
    }
    return isSame(nums,j);
}