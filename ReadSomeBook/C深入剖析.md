- 0x01<<2+3

  结果为32，+的优先级比<<高。

  左移右移的位数不能大于数据的长玉，不能小于0。

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

- 1

- 2

- 3

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