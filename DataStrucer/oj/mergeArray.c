//
// Created by duwei on 2020/12/8.
//

#include <stdio.h>

/*
 * 合并两个有序数组
 * 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
 * 说明：初始化nums1 和 nums2 的元素数量分别为m 和 n 。
 *      你可以假设nums1有足够的空间（空间大小大于或等于m + n）来保存 nums2 中的元素。
 *      nums1 = [1,2,3,0,0,0], m = 3
 *      nums2 = [2,5,6],       n = 3
 *      输出：[1,2,2,3,5,6]
 */

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    for (int i = 0; i < nums2Size; ++i) {
        for (int j = 0; j < nums1Size; ++j) {
            if (nums2[i] < nums1[j]){
                for (int k = m; k >j ; --k) {
                    nums1[k] = nums1[k-1];
                }
                nums1[j] = nums2[i];
                m++;
                break;
            } else if (j==m){
                nums1[m] = nums2[i];
                m++;
                break;
            }
        }
    }
}

int main()
{
    int nums1[7] = {1,2,3,0,0,0,0};
    int nums2[4] = {2,5,6,7};
    merge(nums1,7,3,nums2,4,4);
    for (int i = 0; i < 7; ++i) {
        printf("%d ",nums1[i]);
    }
}