- 定义和声明

  - 定义：编译器创建一个对象，为这个对象分配一块内存并给它取一个名字，名字就是我们常说的变量或对象名。

    ```c
    int a;
    ```

  - 声明：告诉编译器，这个名字已经匹配到一块内存上了；告诉编译器，这个名字预定了，其它地方不能再使用，这种声明的最典型例子就是声明一个函数；声明不会分配内存。

    ```c
    extern inn a;
    void func(int a);	//声明一个函数
    ```

- struct

  ```c
  #include <stdio.h>
  struct stu
  {
  
  } s1;
  
  int main(){
      printf("%lu\n",sizeof(s1)); // 0
      return 0;
  }
  // 编译器gcc
  ```

- 柔性数组

  ```c
  #include <stdio.h>
  #include <stdlib.h>
  
  typedef struct
  {
      int a;
      int b[];
  } soft_arr;
  
  int main()
  {
      printf("%lu\n",sizeof(soft_arr)); // 4
      soft_arr *p = malloc(sizeof(soft_arr)+sizeof(int));
      free(p);
      return 0;
  }
  
  ```

  结构中最后一个成员允许是一个未知大小的数组，这个成员叫做柔性数组。sizefo 返回这种类型的大小不包括柔性数组的内存。包含柔性数组成员的结构用malloc进行内存动态分配。(应用：比如网络通信，收发数据包)

- union

  ```c
  union Person
  {
      char *name;
      int age;
      char *addr;
      double balance;
  };
  
  int main()
  {
      printf("%lu\n",sizeof(union Person));
      return 0;
  }
  ```

  union维护足够的空间来置放多个成员的某一个成员，而不是为每个数据成员配置空间。在union中所有成员公用一个空间，同一时间只能存储其中一个数据成员，所有数据成员拥有相同的起始地址。

  一个union需要配置足够的空间来容纳所有成员。上述例子中：double占用内存空间最大，所以Person的内存大小是8字节。

  大小端对union的影响：

  ```c
  union T
  {
      char a;
      int b;
  };
  
  int main()
  {
      union T t1;
      t1.b = 1;
      printf("%d\n",t1.a);
      return 0;
  }
  ```

  <img src="https://upload-images.jianshu.io/upload_images/15150075-33c893aeed324c98.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240" alt="image.png" style="zoom:67%;" />

- enum

  ```c
  enum Color
  {
      RED,
      BLACK,
      WHITE,
      YELLOW,
  };
  
  int main(){
      RED = 3; // expression is not assignable
      return 0;
  }
  ```

- auto

  编译器在默认缺省的情况下，所有变量都是auto。

- register

  请求编译器尽可能的将这个变量存在cpu内部的寄存器中而不是通过内存寻址访问。register变量可能不存放在内存中，所以不能用&符取地址。

- static

  - 修饰变量。
    - 变量分局部变量和全局变量，被static修饰它们都存在于内存的静态区。
    - 静态全局变量：作用域仅限于变量被定义的文件中。
    - 局部静态变量：只能在定义这个局部静态变量的函数使用，即使函数调用结束，这个变量也不会消失。
  - 修饰函数。
    - 函数前加static称为静态函数，静态不是指存储方式，而是此函数的作用域仅限于本文件内。

- switch

  ```c
  int main(){
      int a = 4;
      int c=6;
      switch (a) {
          case 1:
              printf("1\n");
              break;
          default:
              printf("default\n");
          case 2:
              printf("2\n");
          case 3:
              printf("3\n");
  //        case c:   // error
  //            printf("%d",c);
  //            break;
  //        case 3.14:    // error
  //            printf("3.14\n");
      }
  }
  // output:
  // default
  // 2
  // 3
  ```

  - case后只能是整形或字符型常量或常量表达式

- End0

- 0x01<<2+3

  结果为32，+的优先级比<<高。

  左移右移的位数不能大于数据的长度，不能小于0。

- ++i、i++

  ```c
  int main(){
      int i = 0;
      int j = (++i,++i,++i);      // ++i 先自增再进它其他运算。i在遇见逗号之后认为本计算单位已经结束，然后进行自增。
      printf("j = %d\n",j);       // 3
  
      int k = 0;
      int z = (k++,k++,k++);      // i++ 先进行其它运算再自增
      printf("z = %d\n",z);       // 2
    
      int x = 0;
      int y = (x++) + (x++) + (x++);
      printf("y = %d\n",y);       // 1+1+1=3 x遇到分号之后才认为本次计算单位已结束，x这时候才会进行自加
  }
  ```

- ++i+++i+++i

  ```c
  int main(){
      int a = 1;
      int b = 2;
      int ret = a+++b;            // 贪心算法：a++ + b
      printf("ret = %d\n",ret);   // ret = 3
  }
  ```

- #define宏定义注释符号

  ```c
  #define BSC //
  #define BMC /*
  #define EMC */
  int main(){
      int a = 10;BSC a is int
      DMC input a number:EMC
  }
  ```

  注释先于预处理指令被处理。当发生宏替换时，注释已经处理完毕，再出现//、/*则会出现错误。

- 宏定义中的空格

  ```c
  #define SUM(x) (x)+(x)
  
  int main(){
  	int ret = SUM (3);
  	return 0;
  }
  ```

  这个空格仅在定义的时候有效，在使用这个宏函数的时候，空格会被忽略掉。因此：SUM(x) 和SUM (x)是一样的。

  ```shell
  duweideMacBook-Pro:test duwei$ cat test.c
  #define SUM(x) (x)+(x)
  
  int main(){
  	int ret = SUM (3);
  	return 0;
  }
  duweideMacBook-Pro:test duwei$ gcc -E test.c -o test.i
  duweideMacBook-Pro:test duwei$ cat test.i
  # 1 "test.c"
  # 1 "<built-in>" 1
  # 1 "<built-in>" 3
  # 361 "<built-in>" 3
  # 1 "<command line>" 1
  # 1 "<built-in>" 2
  # 1 "test.c" 2
  
  
  int main(){
   int ret = (3)+(3);
   return 0;
  }
  duweideMacBook-Pro:test duwei$
  ```

- 预处理余下部分暂时省略，以后回来看

- 略

- 略

- 略

- int *p = NULL和 *p = NULL的区别

  - ```c
    int *p = NULL;
    ```

    定义一个指针变量p，其指向的内存里面保存的是int类型的数据，在定义变量p的同时把p的值设为0x00000000，这个过程叫初始化，是在编译的时候进行的。

  - ```c
    int *p;
    *p = NULL;
    ```

    第一行代码，定义了一个指针变量p，其指向内存里保存的是int类型的数据，此时p变量本身是多少不可知，也就是说p变量此时指向的内存地址可能是个非法值。第二行代码给*p赋值为NULL，也就是给 *p指向的内存赋值NULL。由于p变量的内存地址可能是非法的，所以在调试时编译器可能会报错。

- ```c
  int main(){
      char *p1 = "abcdef";
      printf("p1 = %p\n",p1);         // p1 = 0x109002f82
      printf("p1 = %p\n",p1+1);       // p1 = 0x109002f82
      printf("p1 = %p\n",p1+2);       // p1 = 0x109002f82
      printf("&p1 = %p\n",&p1);       // &p1 = 0x7ffee6bfda48
  
      char p2[] = "123456";
      printf("p2 = %p\n",p2);         // p2 = 0x7ffee6bfda41
      printf("&p2 = %p\n",p2+1);      // &p2 = 0x7ffee6bfda42
      printf("&p2 = %p\n",p2+2);      // &p2 = 0x7ffee6bfda43
  }
  ```

  ![p1的访问方式](https://upload-images.jianshu.io/upload_images/15150075-95496cd76b42207b.png?imageMogr2/auto-orient/strip|imageView2/2/w/1200/format/webp)

  ![p2的访问方式](https://upload-images.jianshu.io/upload_images/15150075-586f59dc81a1ece9.png?imageMogr2/auto-orient/strip|imageView2/2/w/1200/format/webp)

  结论：

  - 数组名即为数据本身
  - 数组作为参数传递给函数时，数组的地址赋值给形参，发生降维。

- a和&a的区别(数组名)

  ```c
  int main(){
      int a[5] = {1,2,3,4,5};
      int *ptr = (int *)(&a+1);
      printf("*(a+1)=%d\n*(ptr-1))=%d\n",*(a+1),*(ptr-1));    // *(a+1)=2，*(ptr-1))=5
  }
  ```

  结论：

  - &a代表的是数组地址，&a+1，加上的是sizeof(a)，指向a[4]的下一个元素。
  - a代表的是首元素地址。
  
- 定义为数组，声明为指针

  ```c
  int arr[3] = {1,2,3};
  
  int main(){
      extern int *arr;
  }
  ```

  将arr声明为指针会造成访问方式的错误，得出意外的结果。本应该是直接读取到arr的内存地址然后进行偏移操作，但是这里声明为指针，导致了访问方式的改变，访问时会先读取arr所在内存空间存放的内存地址，然后再进行偏移操作。

- 定义为指针，声明为数组

  ```c
  char *p = "abcd";
  
  int main(){
      extern char p[];
  }
  ```

  也会因为定义和声明的方式不一样造成访问方式不一样从而得到意外的结果。

- 指针和数组对比

  | 指针                                                         | 数组                                                         |
  | ------------------------------------------------------------ | ------------------------------------------------------------ |
  | 保存数据的地址，任何被存入指针变量p的数据都会被当做地址处理。p本身的地址有编译器另外存储，存储在哪里我们并不知道。 | 保存数据，数组名a代表的是数组首元素的地址而不是数组的首地址，&a才是整个数组的首地址。a本身的地址由编译器另外存储，存储在哪里，我们并不知道。 |
  | 间接访问数据，首先取得指针变量p的内容，把它当做地址，然后从这个地址提取或者写入数据。指针可以以指针的形式访问*(p+i)；也可以以下标的方式访问p[i]。但是其本质都是先取p的内容然后加上 i * sizeof(类型)个byte作为数据的真正地址。 | 直接访问数据，数组名a是整个数组的名字，数组内每个元素并没有名字。只能通过"具名+匿名"的方式来访问其它某个元素，不能把数组当做一个整体来进行读写操作。数组可以以指针的形式访问*(pa+i)；也可以以下标的方式访问a[i]。但其本质都是a所代表的数组的首元素地址加上 i * sizeof(类型)个byte作为数据的真正地址。 |
  | 通常用于动态数据结构                                         | 通常用于存储固定数目且数据类型相同的元素                     |
  | 相关函数malloc和free                                         | 隐式分配和删除                                               |
  | 通常指向匿名数据（也可指向具名数据）                         | 自身即为数组名                                               |

- 地址强制转换

  ```c
  int main(){
      int a[4] = {1,2,3,4};
      int *ptr1 = (int *)(&a+1);
      int *ptr2 = (int *)((int)a+1);
      
      printf("ptr1[-1] = %x\n",ptr1[-1]);
      printf("*ptr2 = %x\n",*ptr2);
      return 0;
  }
  ```

  32位系统下：

  ![image.png](https://upload-images.jianshu.io/upload_images/15150075-c638b8896fc9d3be.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

  64位系统下会报错：Segmentation fault

  个人看法：a代表的是首元素地址，将其强转成int然后+1再强转成int*，即将a地址进行+1操作然后赋值给ptr2。在32位下指针的长度和 int\* 类型的长度相同，所以不会发生提升。但是在64位下，将4位的int\* 提升为8位的地址会发生提升，提升后的地址远远大于当前数组所有元素的地址，所以在进行printf访问打印时会报错：Segmentation fault。

- &p\[4\][2] - &a\[4\][2] 等于多少？

  ```c
  int main(){
      int a[5][5];
      int(*p)[4];
      p = a;
      printf("%p,%d\n",&p[4][2] - &a[4][2],&p[4][2] - &a[4][2]);
  }
  ```

  ![ 是](https://upload-images.jianshu.io/upload_images/15150075-59a8fe82de0a6d11.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 无法向一个函数传递数组

  - C语言中，当一维数组作为函数参数时，编译器总把它解析成一个指向其首元素地址的指针。
  - 函数本身没有类型，只有函数的返回值才有类型。

- 能否把指针变量本身传递给一个函数

  main函数中的变量不是全局变量，只不过是它的声明周期和全区变量一样长而已。全局变量定义在函数外部。

- 函数指针的定义

  ```c
  char* (*func1)(char* p1, char* p2);
  ```

  func1是一个指针变量，指向一个有两个char\*类型参数且返回值是char\*类型的函数

- \*(int\*)&p

  ```c
  // 32位
  void Function(){
      printf("Call Function.\n");
  }
  
  int main(){
      void (*p)();
      *(int*)&p = (int)Function;
      (*p)();
      return 0;
  }
  ```

  p是一个指针变量，指向一个无参数无返回值的函数；

  (int\*)&p将p的地址强转成int数据类型的指针；

  \*(int\*)&p 就是一个整型，要将函数Function的地址赋值给p得先将其转为整型。

- (\*(void(\*)())0)();

  void(*)()：表示一个指针，指向一个返回值时void且没有参数的函数。

  (void(\*)())0：表示将0强制转换成void(\*)()这个函数指针类型。

  (\*(void(\*)())0)：获取地址0开始的内存中的一段内容(解引用)。

  (\*(void(\*)())0)()：函数调用。

- 函数指针数组

  ```c
  char* (*pf1)(char *p);		// pf1是一个指向参数是char *类型，返回值时char*的函数的指针
  char* (*pf2[3])(char *p);	// pf2是函数指针数组
  ```

  ```c
  #include <stdio.h>
  #include <string.h>
  
  char * func1(char *p){
      printf("%s\n",p);
      return p;
  }
  
  char * func2(char *p){
      printf("%s\n",p);
      return p;
  }
  
  char * func3(char *p){
      printf("%s\n",p);
      return p;
  }
  
  int main(){
      char *(*pf[3])(char *);
      pf[0]=func1;
      pf[1]=func2;
      pf[2]=func3;
      pf[0]("func1");
      pf[1]("func2");
      pf[2]("func3");
      return 0;
  }
  ```

- 函数指针数组的指针

  ```c
  char* (*pf2[3])(char *p);	// pf2是函数指针数组
  char* (*(*pf2)[3])(char *p);	// pf2是函数指针数组指针
  ```

- 常见内存错误以及对策

  - 指针没有指向一块合法的内存

    - 结构体成员指针未初始化

      ```c
      struct student{
          char *name;
          int score;
      }stu,*pstu;
      
      int main(){
          strcpy(stu.name,"jim");
          stu.score=99;
          return 0;
      }
      ```

      在实例化stu时，给name分配了四字节的内存，但并没有指向合法的地址。调用strcpy往所指向的内存拷贝"jim"，这块内存name指针根本就无权访问，导致出错。

      ```c
      #include <stdlib.h>
      #include <stdio.h>
      
      struct student{
          char *name;
          int score;
      }stu,*pstu;
      
      int main(){
          stu.name = (char*)malloc(sizeof(char));
          strcpy(stu.name,"jim");
          stu.score=99;
          printf("%s\n",stu.name);
      
          free(pstu);
          return 0;
      }
      ```

    - 没有为结构体指针分配足够的内存

    - 函数入口校验

      ```c
      assert(NULL!=p); // 是一个宏而非函数
      ```

  - 为指针分配的内存太小

  - 内存分配成功，但未初始化

    ```c
    int i = 10;
    char *p = (char *)malloc(sizeof(char));
    //在不确定变量初始值的时候可以初始化为0或者NULL
    int i = 0;
    char *p = NULL;
    //或者使用memset(起始地址,要被设置的值,要被设置的内存大小);
    int a[10];
    memset(a,0,sizeof(a));
    ```

    

  