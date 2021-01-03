#include "Stack.h"

void TestList1()
{
    Stack st;
    StackInit(&st);
    StackPush(&st,1);
    StackPush(&st,2);
    StackPush(&st,3);
    StackPush(&st,4);
    StackPush(&st,5);
    StackPush(&st,6);
    printf("st._capacity = %d\n",st._capacity);
    printf("st._top = %d\n",st._top);
    printf("%d\n",st._a[5]);

    PrintStack(&st);


    while (!StackEmpty(&st))
    {
        printf("%d ",StackTop(&st));
        StackPop(&st);
    }
    printf("\n");

    StackDestory(&st);
}

int main()
{
    TestList1();
    return 0;
}