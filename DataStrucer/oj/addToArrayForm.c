//
// Created by duwei on 2020/12/9.
//

#include <stdio.h>
#include <stdlib.h>

/*
 * 对于非负整数而言，X的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果X = 1231，那么其数组形式为[1,2,3,1]。
 * 给定非负整数 X 的数组形式A，返回整数X+K的数组形式。
 *
 * 输入：A = [1,2,0,0], K = 34
 * 输出：[1,2,3,4]
 * 解释：1200 + 34 = 1234
 */

int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
    int tempK = K, KSize = 0;
    while (tempK)
    {
        KSize++;
        tempK/=10;
    }
    int len = ASize > KSize ? ASize:KSize;  // 求两个数的最大长度

    int *resultArr = (int *)malloc(sizeof(int)*(len+1));
    int reti = 0;

    int next = 0;
    int Ai = ASize-1;
    while (len--)
    {
        int a = 0;
        if (Ai >= 0)
        {
            a = A[Ai];
            Ai--;
        }
        int ret = K%10+a+next; // 每一位相加的和
        K/=10;
        if ( ret > 9)
        {
            ret -= 10;
            next = 1;
        } else{
            next = 0;
        }
        resultArr[reti] = ret;
        reti++;
    }

    if (next == 1)
    // 如果最后一次的next为1，则说明还需要进位一次
    {
        resultArr[reti] = 1;
        reti++;
    }

    *returnSize = reti;

    int j = 0,k=reti-1;
    while (j<k){
        int temp = resultArr[j];
        resultArr[j] = resultArr[k];
        resultArr[k] = temp;
        j++;
        k--;
    }

    return resultArr;
}

int main()
{
    int A[] = {6, 9, 9}, k = 888; // 364
    int returnSize = 0;
    int ASize = sizeof(A) / sizeof(A[0]);
    int * ret = addToArrayForm(A,ASize,k,&returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ",ret[i]);
    }
}