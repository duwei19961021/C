#include <stdio.h>

/*
 * 喝汽水问题。
 * 汽水一元一瓶，两个汽水瓶能换一瓶汽水。
 * */

int DrinkSoda1(int bottle){ //一瓶汽水一元，两空瓶换一瓶汽水,x为空瓶子数
    if (bottle < 2){
        return bottle;
    }
    return bottle + DrinkSoda1(bottle/2+bottle%2)- bottle%2; //为什么要减去bottle%2：为0则说明每个瓶子都使用兑换掉了，如果为1则说明有一个瓶子没有使用掉则应在结果中减去一次
}

/*
            []     []    []    []    []
             \     /      \    /     |
                []          []       []
                  \        /         |
                      []             []
                        \            |
                              []
可以转换为一个倒立二叉树，求度为0和度为2的节点的总和(度为1的节点在整个过程中未被兑换过)，在二叉树中度为0的节点比度为2的节点多1个，这里度为0的节点为x(初始瓶子数)，
那么度为0和度为2节点总数为 x+x-1
 */

int DrinkSoda2(int bottle){
    return bottle+bottle-1;
}


int main() {
    int ret1 = DrinkSoda1(20);
    printf("ret = %d\n",ret1);
    int ret2 = DrinkSoda2(20);
    printf("ret = %d\n",ret2);
}