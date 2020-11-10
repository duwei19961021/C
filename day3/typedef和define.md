##### 浅谈#define和typedef

```c
    int age;
    int class;
} stu,*p_stu;

int main(){
    stu s0= {1,2};
  	p_stu const s2;
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