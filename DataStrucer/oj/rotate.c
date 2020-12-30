//
// Created by duwei on 2020/12/30.
//

/*
 * 旋转数组
 * 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
 *
 * 输入: [1,2,3,4,5,6,7] 和 k = 3
 * 输出: [5,6,7,1,2,3,4]
 * 解释:
 * 向右旋转 1 步: [7,1,2,3,4,5,6]
 * 向右旋转 2 步: [6,7,1,2,3,4,5]
 * 向右旋转 3 步: [5,6,7,1,2,3,4]
 * 链接：https://leetcode-cn.com/problems/rotate-array
 * */

/*
 * 解题思路:
 * [1,2,3,4,5,6,7]
 * 当要旋转k次时，数组后k个数字先逆序
 * [1,2,3,4,7,6,5]
 * 然后将数组整体逆序
 * [5,6,7,4,3,2,1]
 * 然后将k下标开始的剩下的数逆序
 * [5,6,7,1,2,3,4]
 * 如果k大于numsSize,要对k以numsSize为底进行取模
 * */

void reverseArr(int *arr,int start, int end)
{
    while(start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k){
    if(k>numsSize)
    {
        k%=numsSize;
    }
    reverseArr(nums,numsSize-k,numsSize-1);
    reverseArr(nums,0,numsSize-1);
    reverseArr(nums,k,numsSize-1);
}