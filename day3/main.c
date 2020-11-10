#include <stdio.h>

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