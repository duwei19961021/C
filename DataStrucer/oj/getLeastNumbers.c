//
// Created by duwei on 2021/1/13.
//

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
 * 最小的k个数
 * 链接: https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/submissions/
 * */

// 建堆
void AdJustDown(int* arr, int root, int size) // 求最小k个数要建大堆，因为建堆之后堆顶的数是最大的，只有比堆顶小的数才能进堆
{
    int parent = root;
    int child = parent*2+1;
    while(child < size)
    {
        if(child+1<size && arr[child+1] > arr[child]) // 找出左右孩子中大的孩子
        {
            child++;
        }

        if(arr[child] > arr[parent]) // 如果孩子结点大于父结点则交换
        {
            int temp = arr[child];
            arr[child] = arr[parent];
            arr[parent] = temp;
            parent = child;
            child = parent*2+1;
        }
        else // 已经是大堆不用交换，直接退出
        {
            break;
        }
    }
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    *returnSize = k;
    int* retArr = (int*)malloc(sizeof(int)*k);

    if(!k)
    {
        return retArr;
    }

    for(int i=0;i<k;i++)
    {
        retArr[i] = arr[i];
    }

    for(int i = (k-1-1)/2 ;i>=0;i--) // 从最后一个非叶子结点开始建堆
    {
        AdJustDown(retArr,i,k);
    }

    for(int i = k;i<arrSize;i++)
    {
        if(arr[i]<retArr[0])
        {
            retArr[0] = arr[i]; // 如果要进堆的数比堆顶的数还要小则将这个数替换掉堆顶
        }
        AdJustDown(retArr,0,k);
    }

    return retArr;
}