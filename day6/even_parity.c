#include <stdio.h>
/*
 * 校验奇偶
 * */

int even_parity(int value)
{
    return (value<<31>>31) & 1; // 左移31位然后右移31位得到第一个比特位的，其余位全0
}

int main(){
    int ret = even_parity(-11);
    printf("ret = %d\n",ret);
    return 0;
}