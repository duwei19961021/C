/*
 * 存在重复的元素
 * 链接：https://leetcode-cn.com/problems/contains-duplicate/
 */
int CmpInt(const int* a, const int* b)
{
    return *a > *b;
}

bool containsDuplicate(int* nums, int numsSize){
    qsort(nums,numsSize,sizeof(int),CmpInt); // 对数组进行排序,这里我直接排序的原数组(也可以复制一个再排序)
    int current = 0;
    int next = current+1;
    while(next < numsSize)
    {
        if(nums[next] - nums[current] == 0) // 循环判断两个相邻数组元素的差是否等于0,如果等于0则说明元素重复
            return true;
        current++;
        next++;
    }
    return false;
}
