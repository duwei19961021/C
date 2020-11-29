/*
 * C程序的main函数具有两个形参。
 * argc:表示命令行参数的数目。
 * argv:指向一个组参数值。
 * */

#include <stdio.h>

int main(int argc, char **argv) // argv： char *[],在传参时要发生降维 => **argv
{
    for (int i = 0; i < argc; ++i) {
        printf("%s\n",*(argv+i)); // char *argv[] = ["first","second","third"],字符指针数组。argv代表的是首元素,首元素还是地址(字符指针)所以需要解引用。
    }
    return 0;
}