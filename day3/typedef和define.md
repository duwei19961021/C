##### 浅谈#define和typedef

```c
typedef struct s {
    int age;
    int class;
} stu,*p_stu;

int main(){
    stu s0= {1,2};
    const p_stu s1 = &s0;
    s1->class = 3;
    printf("%d\n",s1->class);
    stu s4 = {100,100};
    s1 = &s4; //err:cannot assign to variable 's1' with const-qualified type 'const p_stu',note: variable 's1' declared const here
}
```

#define是在编译阶段进行替换

typedef是对已存在的类型进行重命名产生一个新类型名(而非新类型)



所以上述代码中的：

- const p_stu s1;
- p_stu const s2;

二者意思相同，相当于：

- int const a;
- const int a;

二者没有区别。所以const是限定s1、s2的内容不可变。

------



```c
#define de_INT int
typedef int ty_INT;

int main(){
    de_INT m = 1;
    ty_INT n = 2;
}
```

```shell
duweideMacBook-Pro:test duwei$ gcc -E test.c -o test.i
duweideMacBook-Pro:test duwei$ cat test.i
# 1 "test.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 361 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "test.c" 2

typedef int ty_INT;

int main(){
    int m = 1;
    ty_INT n = 2;
}
duweideMacBook-Pro:test duwei$
```

经过预处理阶段可知：

- #define是在预处理阶段进行替换

- typedef是真正意义上的产生了一种新的类型名

  ```c
  #include <stdio.h>
  
  #define PCHAR char*
  typedef char* pchar;
  
  int main(){
      PCHAR p3,p4;	//p3是一个char类型的字符指针，p4是一个char类型字符而非指针
      pchar p1,p2;
      printf("sizeof(p1=%d)\n",sizeof(p1));	// sizeof(p1=8)
  }
  ```

  

