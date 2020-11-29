#include <stdio.h>

/*
 * 当字符串常量出现于表达式中的时候，它的值是一个指针常量。
 * 编译器把这些字符的一份拷贝存储在内存中，并存储指向第一个字符的指针。*/

void mystery(int n)
{
    n+=5;
    n/=10;
    printf("%s\n","**********"+10-n);
}

void binary_to_ascii(unsigned int value) // 将数字转转换成char打印
{
    unsigned int quotient;
    quotient = value/10;
    if (quotient!=0){
        binary_to_ascii(quotient);
    }
    putchar(value%10+'0');
}

int main()
{
    printf("%c,%p,%p\n",*("xyz"+1),"xyz","xyz"+1); // y,0x10569dfb0,0x10569dfb1
    printf("%c\n",*"xyz"); // x
    printf("%c\n","xyz"[2]); // z

    for (int i = 0; i < 100; ++i) {
        mystery(i);
    }

    binary_to_ascii(10086);

    return 0;
}