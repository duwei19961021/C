#include "Queue.h"


int TestList1()
{
    Queue st;
    QueueInit(&st,1000);
    for (int i = 0; i < 1000; ++i) {
        QueuePush(&st,i);
    }

    for (int i = 0; i < 89; ++i) {
        QueuePop(&st);
    }

    printf("size = %d\n",QueueSize(&st));

    printf("\n");

    while (!QueueIsEmpty(&st))
    {
        printf("%d ",QueueFront(&st));
        QueuePop(&st);
    }

    printf("\n");

    printf("empty: %d\n",QueueIsEmpty(&st));

    QueueDestory(&st);

    printf("empty: %d\n",QueueIsEmpty(&st));
}


int main()
{
    TestList1();

    return 0;
}