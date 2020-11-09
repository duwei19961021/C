#include <stdio.h>

/*
 * 喝汽水问题。
 * 汽水一元一瓶，两个汽水瓶能换一瓶汽水。
 * */

int DrinkSoda(int bottle){ //一瓶汽水一元，两空瓶换一瓶汽水,x为空瓶子数
    if (bottle < 2){
        return bottle;
    }
    return bottle + DrinkSoda(bottle/2+bottle%2)- bottle%2; //为什么要减去bottle%2：为0则说明每个瓶子都使用兑换掉了，如果为1则说明有一个瓶子没有使用掉则应在结果中减去一次
}
int main() {
    int ret = DrinkSoda(20);
    printf("ret = %d\n",ret);
}