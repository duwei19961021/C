#include <stdio.h>
#include <stdlib.h>

double Add(double x,double y)
{
    return x+y;
}

double Sub(double x,double y)
{
    return x-y;
}

double Mul(double x,double y)
{
    return x*y;
}

double Div(double x,double y)
{
    return x/y;
}

double (*oper_func[])(double ,double )={Add, Sub, Mul, Div};

int main() {
    int selector;
    int x,y;
    printf("1、add          2、sub\n");
    printf("3、mul          4、div\n");
    printf("选择运算符：\n");
    scanf("%d",&selector);
    switch (selector) {
        case 1:
            printf("输入两个数组(example:12 13):\n");
            scanf("%d %d",&x,&y);
            printf("result = %lf\n",oper_func[0](x,y));break;
        case 2:
            printf("输入两个数组(example:12 13):\n");
            scanf("%d %d",&x,&y);
            printf("result = %lf\n",oper_func[1](x,y));break;
        case 3:
            scanf("%d %d",&x,&y);
            printf("输入两个数组(example:12 13):\n");
            printf("result = %lf\n",oper_func[2](x,y));break;
        case 4:
            scanf("%d %d",&x,&y);
            printf("输入两个数组(example:12 13):\n");
            printf("result = %lf\n",oper_func[3](x,y));break;
        case 0:
            exit(0);
        default:
            printf("输入错误，程序结束");
            break;
    }
    return 0;
}