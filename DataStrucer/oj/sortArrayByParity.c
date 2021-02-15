/*
 * 按奇偶排序
 * 链接：https://leetcode-cn.com/problems/sort-array-by-parity/
 */

void Swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int* sortArrayByParity(int* A, int ASize, int* returnSize)
{
    int start = 0;
    int end = ASize-1;
    int* retA = (int*)malloc(sizeof(int)*ASize);
    memcpy(retA,A,ASize*sizeof(int));
    while(start < end)
    {
        while(start < end && retA[start]%2 == 0)
            start++;
        while(start < end && retA[end]%2 == 1)
            end--;
        Swap(&retA[start],&retA[end]);
        end--;
        start++;
    }
    *returnSize = ASize;
    return retA;
}
