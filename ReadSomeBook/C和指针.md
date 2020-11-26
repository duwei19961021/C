---
title:
date:
categories:
- C语言
tags:
- book
---
#### 第3章

##### 3.1 基本数据类型

###### 3.1.1 整形家族

长整型至少应该和整型一样，而整型至少应该和短整型一样长。

一、整型字面值

初始化之后不可以被修改。

在整数字面值后面添加L或l，可以使这个整数被解释为long类型值，字符U或u则用于把数值指定为unsigned整型值。如果添加lu则被解释为 unsigned long 整型值。字符常量的类型总是int。

```c
int main()
{
    123L;
    123u;
    123LU;
    0123; // 8进制
    0x1561; // 16进制
    printf("%lu\n",sizeof('a')); // 4
    return 0;
}
```

二、枚举类型

以整型方式存储。

```c
enum age
{
    a,
    b,
    c,
    d
};
```

###### 3.1.1 浮点类型

```c
int main()
{
    printf("%lu\n",sizeof(3.14)); // 8,缺省时默认为double类型
    printf("%lu\n",sizeof(3.14l)); // 16,long double
    printf("%lu\n",sizeof(3.14f)); // 4
    printf("%lu\n",sizeof(double )); // 8
    printf("%lu\n",sizeof(float )); // 4
    return 0;
}
```

###### 3.1.3 指针

把内存想象成一条长街，每间房子都用一个唯一的号码进行标识。每一个位置包含一个值，这和它的地址式独立且显著不同的，即使他们都是数字。

一、指针常量

二、字符串常量

字符串：一串以NUL字节结尾的零个或多个字符。字符串通常存储在字符数组总，所以c语言中没有显示的字符串类型。

```c
int main()
{
    printf("%lu\n",sizeof("")); // 1，虽然字符串为空，但是还是会分配内存
    return 0;
}
```

在程序中使用字符串常量时会生成一个“指向字符的常量指针”，当一个字符串常量出现于一个表达式中时，表达式所使用的值就是这些字符所存储的地址，而不是这些字符本身。因此，可以把字符串常量赋值给一个“指向字符的指针”。但是不能把字符串常量赋值给一个字符数组，因为字符串常量的直接值是一个指针，而不是这些字符本身。

##### 3.2 基本申明

int a;

###### 3.2.1 初始化

###### 3.2.2 声明简单数组

```c
int arr[100];
```

###### 3.2.3 声明指针

```c
int *a;
int *b,*c;
char *message = "hello world";
/*
char *message;
message = "hello world";
*/
```

###### 3.2.4 隐式声明

函数如果不显示的声明返回值的类型，就默认返回整型。

```c
f(int x)
{
    return x*2;
}

int main()
{
    printf("ret = %d\n",f(3));
    return 0;
}
```

##### 3.3 typedef

为数据类型定义新的名字，而不是产生新的类型。

```c
int const a;
const int a; // 二者等价

int const *pi; // const修饰 *pi ，可以修改pi的值但是不可以修改pi所指向的地址的值
int * const cpi; // 可以修改cpi所指向地址的值但是不可以修改cpi指向的地址。
int const * const cpci; // 无论是cpci指针本身还是它所指向的地址的值 都不可以修改
```

##### 3.5 作用域

###### 3.5.1 代码块作用域

任何在代码块的开始位置声明的标识符都具有代码块作用域。

###### 3.5.2 文件作用域

在代码块之外声明的标识符都具有文件作用域。

###### 3.5.3 原型作用域

只适用于在函数原型中声明的参数名。

```c
int f(int x)
{
 return x;  
}
```

##### 3.6 链接属性

标识符的链接属性决定如何处理在不同文件中出现的标识符。

链接属性

- external (extern)

  属于external链接属性的表示符不论声明多少次、位于几个源文件都表示同一实体。

- internal (static)

  属于internal的连接属性的标识符在同一源文件内的所有声明中都指同一个实体。

- none (auto)

  没有链接属性的标识符总是被当做单独的个体。

##### 3.7 存储类型

变量的存储类型是指存储变量值的内存类型。变量的存储类型决定变量何时创建、何时销毁以及它的值将保持多久。

- 普通内存
- 运行时堆栈
- 硬件寄存器

变量的缺省存储类型取决于它的声明位置。在任何代码块之外声明的变量总是存储于静态内存中(不属于堆栈)，这类变量称为静态变量。静态变量在程序运行之前创建，在程序的整个执行期间始终存在。

在代码块内部声明的变量的缺省内存存储类型是自动的(automatic)，它存储于堆栈中，称为自动(auto)变量。在程序执行到声明自动变量的代码块时，自动变量才被创建，当程序离开该代码块时自行销毁。

对于在代码块内部声明的变量，加上static关键字，可以使它的存储类型从自动变为静态。具有静态存储类型的变量在整个程序执行过程中一直存在，而不仅仅在声明它的代码块的执行时存在。修改变量的存储类型并不表示修改该变量的作用域，它仍然只能在该代码块内部按变量名访问。函数形式参数不能声明为静态，因为实参总是在堆栈中传递给函数，用于支持递归。

register可以用于自动变量声明，提示他们应该存储于机器的硬件寄存器而不是内存中，这类变量称为寄存器变量(因为不在内存中，所以不能用&取地址。)

初始化

- 静态变量

  静态变量的初始化中，可以把可执行程序文件想要初始化的值放在当程序执行时变量将会使用的位置。当可执行文件载入到内存时，这个已经保存了正确初始值的位置将赋值给那个变量。完成这个任务并不需要额外时间，也不需要额外指令，变量将会得到正确的值。如果不显式的指定其初始值，静态变量将初始化为0。

- 自动变量

  自动变量初始化需要更多的开销，因为当程序链接时还无法判断自动变量的存储位置。

#### 第六章 指针

##### 6.14 总结

声明一个指针变量并不会自动分配任何内存。

##### 第七章 函数

```c
int*
find_int(int key, int arr[], int length);
```

这种声明方式，也就是用单独的一行给出参数的类型，那么编译器就只记住函数返回值的类型，不保存函数的参数数量和类型信息。

```
int func();
这种声明会被解释为旧式风格的声明，只保存了函数的返回值类型。

int func(void);
使用新风格原型时，得加上void提示没有任何参数
```

##### 7.3 函数的参数

C函数的所有参数均以“值传递调用”方式进行传递。(参数为指针时也会发生值拷贝，拷贝地址)

##### 7.6 可变参数列表

###### 7.6.1 stdarg宏

#### 第八章 数组

- 下标：为了对下标表达式求值，编译器在程序中插入指令，取得a的值，并把它与整形的长度(也就是4)相乘，这个乘法需要花费一定的时间和空间。

- 指针：尽管不存在下标，但还是存在乘法运算，1这个值必须和整数的长度相乘，然后再与指针相加。但是这里存在一个重大区别：循环每次执行时，执行乘法的运算都是两个相同的数(1和4)。结果，这个乘法只在编译时执行一次----程序现在包含了一条指令，把4与指针相加。程序在执行时并不执行乘法运算。

  ```c
  int main()
  {
      int arr[100] = { 0 }, *ap;
      
      for (int i = 0; i < 100; ++i) { // 下标
          arr[i] = 0;
      }
  
      for (ap = arr; ap < arr+10; ++ap) { // 指针
          *ap = 0;
      }
      
      return 0;
  }
  ```

##### 8.1 一维数组

###### 8.1.1 数组名

```c
int a; // 标量
int b[10]; // 集合，称为数组
```

数据名是常量指针。

数组名在两种情况下表示整个数组，其余一律表示首元素。

```
int arr[10];

sizeof(arr);
&arr;
```

###### 8.1.2 下标引用

数组下标引用和间接访问完全相同。

C检查下标所涉及的开销比你想象的大得多。编译器必须在程序中插入指令，证实下标表达式的结果所引用的元素和指针表达式所指向的元素属于同一数组。这个比较操作需要程序中所有数组的位置和长度方面的信息。这将占用一些空间。当程序运行时，这些信息必须进行更新，以反映自动和动态分配的数组，这又将占用一定的时间。

###### 8.1.3 指针与下标

```c
int main(){
    int arr1[10],a; 
    for ( a = 0; a < 10; ++a) {
        arr1[a] = 0;
    }
    return 0;
}
```

为了对下标表达式求值，编译器在程序中插入指令，取得a的值，并把它与整形的长度(4)相乘。这个乘法需要花费一定的空间和时间。

```c
int main(){
    int arr2[10],*ap;
    for (ap=arr2; ap < arr2; ++ap) {
        *ap = 0;
    }
    return 0;
}
```

这里的乘法运算出现在for语句的调整部分(++ap)，1这个值必须与整形的长度相乘，然后再与指针相加。但是这里存在很大的区别：循环每次执行时，执行乘法运算的都是两个相同的数(1和4)。结果这个乘法只会在编译时执行一次----程序包含一条指令，把4与指针相加。程序在运行时并不执行乘法运算。

###### 8.1.4 指针的效率

###### 8.1.5 指针和数组

数组和指针不相等。

```c
int a[5];
int *p;
```

声明一个数组时，编译器将根据声明所指定的元素数量为数组保存内存空间，然后创建数组名，它的值是一个常量，指向这段空间的起始位置。

声明一个指针变量时，编译器只为指针本身保留内存空间，它并不为任何整形值分配内存空间。而且指针变量并未被初始化为指向任何现有的内存空间，如果是一个自动变量，它甚至不会被初始化。

因此：\*a是合法的。\*b将访问内存中某个不确定的位置，或者导致程序终止。但是b++可以通过编译，a++缺不行，因为a是一个常量。

###### 8.1.6 作为函数参数的数组名

一个数组名作为参数传递给函数：在函数传参时就会发生拷贝。可知数组是一个地址常量，在传参给函数时，发生地址拷贝，数组名(地址常量)传递给函数的形参，形参实例化成一个指针变量，指针变量存放数组的地址常量。因此数组地址传入函数之后，发生降维，降维成一个指针。函数如果执行了下标应用，实际山是对这个指针进行间接访问操作，并且通过这种间接访问，函数可以访问和修改调用程序的数组元素。

###### 8.1.7 声明数组参数

```
int strlen(char *string);
int strlen(char string[]);
```

###### 8.1.8 初始化

```
char message1[] = "Hello";
char *message2 = "Hello";
```

![image.png](https://upload-images.jianshu.io/upload_images/15150075-912a16aa87956bdb.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

###### 8.2.3 下标

```
int matrix[3][10];
```

- matrix

  ![image.png](https://upload-images.jianshu.io/upload_images/15150075-4e7271031de98d6a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

  martrix此时指向第一个二维数组

- matrix+1

  ![image.png](https://upload-images.jianshu.io/upload_images/15150075-cf614cf0e6dea534.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- *(matrix+1)

  ![image.png](https://upload-images.jianshu.io/upload_images/15150075-abe44a68c361cd8e.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- *(matrix+1)+5

  ![](https://upload-images.jianshu.io/upload_images/15150075-921e9fc90ec740f7.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

##### 8.5 总结

- 在绝大多数表达式中，数组名是指向数组第一个元素的指针。只有两个规则例外：
  - sizeof(arr)，返回整个数组占用的字节，而不是返回指针占用的字节。
  - &arr，单目操作符&返回一个指向整个数组的指针，而不是指向数组第一个元素的指针的指针。
- 指针和数组不相等。
  - 声明一个数组，同时也分配了一些内存，用于容纳数组元素。
  - 声明一个指针，只分配用于容纳指针本身的空间。
- 当数组名作为函数参数传递。实际传递的是一个指向数组第一个元素的指针。函数所接收到的参数实际上是原参数的一份拷贝，所以函数可以对其进行操纵而不影响实际的参数。但是对指针执行间接访问操作允许函数修改原先数组的元素。
- 数组形参既可以声明成数组也可以声明成指针，这两种声明形式只有当他们作为函数形参时才相等。

#### 第九章 字符串、字符和字节

##### 9.1 字符串基础

字符串是一串零个或多个字符，以NUL结尾。

##### 9.3 不受限制的字符串函数

###### 9.3.1 复制字符串

char *strcpy(char *dst, char const *src);

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char dest[] = "abcde";
    strcpy(dest,"xyz");
    printf("%s\n",dest); // xyz
    return 0;
}
```

目标参数以前的内容将被覆盖，即使新的字符串比dest原先的内存更短。(NUL也会被复制)

![image.png](https://upload-images.jianshu.io/upload_images/15150075-5f82cd2ae2a6e440.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

###### 9.3.2 连接字符串

char * strcat(char *dst, char const *src);

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char message[100] = {0};
    strcat(message,"hello");
    strcat(message," world");
    printf("%s\n",message);
    return 0;
}
```

###### 9.3.3 函数的返回值。

strcpy和strcat都返回它们第一个参数的一份拷贝，就是指向目标字符数组的指针。

###### 9.3.4 字符串比较

int strcmp(char const *s1, char const *s2);

```
int main()
{
    int ret = strcmp("duwei","zhangsan");
    /*
    if (ret){ // ret的值有三种情况：大于0，等于0，小于0。将其用bool值表达是一种坏风格，正确的方式是将其与0值进行比较
        printf("duwei > zhangsan");
    }
    */
    if (ret > 0){
        printf("duwei > zhangsan");
    }
    return 0;
}
```

##### 9.5 字符串查找

###### 9.5.1 查找一个字符

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char message[] = "learn C language.";

    char *p1 = strchr(message,'a'); // 返回第一次出现的位置
    printf("p1 - message = %lu\n",p1-message);

    char *p2 = strrchr(message, 'a'); // 返回最后一次出现的位置
    printf("p2 - message = %lu\n",p2-message);
    return 0;
}
```

###### 9.5.2 查找任何几个字符

char *strpbrk(char const *str, char const *group); 查找一组字符串在字符串中第一次出现的位置。

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char message[] = "learn C language.";

    char *p = strpbrk(message,"zC"); // 返回z或者C第一次出现的位置，

    printf("%s\n",p);
    return 0;
}
```

###### 9.5.3 查找一个子串

char *strstr(char const *s1, char const *s2);

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char message[] = "learn C language.";

    char *p = strstr(message,"lang");

    printf("%s\n",p);
    return 0;
}
```

##### 9.9 内存操作



