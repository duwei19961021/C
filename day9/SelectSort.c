#include <stdio.h>
#define  N  20

void  SelectSort(int a[], int n)
{ int i, j, t, p;
    for (j = 0 ;j < n-1 ;j++) {
        p = j;
        for (i = j;i < n; i++)
            if(a[i] < a[p])
                p = i;
        t = a[p] ; a[p] = a[j] ; a[j] = t;
    }
}
/*
 * 第一次假设a[0]是最小的元素，p=j，p是最小值的下标，然后遍历数组找到最小的值且将其下标赋给p，
 * 然后将a[p]和a[0]的值进行交换。
 * 第二次假设a[1]是最小的元素.....
 * 以此类推。
 * 示意图：https://images2017.cnblogs.com/blog/849589/201710/849589-20171015224719590-1433219824.gif
 * */


int main()
{
    int a[N]={9,6,8,3,-1},i, m = 5;
    printf("排序前的数据:") ;
    for(i = 0;i < m;i++) printf("%d ",a[i]); printf("\n");
    SelectSort(a,m);
    printf("排序后的数据:") ;
    for(i = 0;i < m;i++) printf("%d ",a[i]); printf("\n");
    return 0;
}