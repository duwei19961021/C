#include "Queue.h"

void TestList1()
{
    Queue pq;
    QueueInit(&pq);
    QueuePush(&pq,1);
    QueuePush(&pq,2);
    QueuePush(&pq,3);
    QueuePush(&pq,4);
    QueuePush(&pq,4);
    QueuePush(&pq,4);
//    QueueDestory(&pq);
    while (!QueueEmpty(&pq))
    {
        printf("%d ",QueueFront(&pq));
        QueuePop(&pq);
    }
}

int main()
{
    TestList1();
    return 0;
}