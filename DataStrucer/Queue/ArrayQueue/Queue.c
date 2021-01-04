//
// Created by duwei on 2021/1/1.
//

#include "Queue.h"

void QueueInit(Queue* pq,int size)
{
    pq->_size = size;
    pq->_a = (STDataType*)malloc(sizeof(STDataType)*pq->_size);
    if (!pq->_a)
    {
        printf("malloc failed.\n");
        exit(-1);
    }

    pq->_front = pq->_rear = 0;
}

void QueueDestory(Queue* pq)
{
    assert(pq);
    free(pq->_a);
    pq->_front = pq->_rear = 0;
}

int QueueIsFull(Queue* pq)
{
    assert(pq);
    return (pq->_rear + 1)%pq->_size == pq->_front%pq->_size;
}

void QueuePush(Queue* pq, STDataType x)
{
    assert(pq);
    if (QueueIsFull(pq))
    {
        printf("Queue is Full.\n");
        return;
    }
    pq->_a[pq->_rear%pq->_size] = x;
    pq->_rear++;
}

void QueuePop(Queue* pq)
{
    assert(pq);
    if (QueueIsEmpty(pq))
    {
        printf("Queue is Empty.\n");
        return;
    }
    pq->_front++;
}

int QueueSize(Queue* pq)
{
    assert(pq);
    return pq->_rear - pq->_front;
}

int QueueIsEmpty(Queue* pq)
{
    assert(pq);
    return pq->_rear == pq->_front;
}

STDataType QueueFront(Queue* pq)
{
    assert(pq);
    STDataType ret = pq->_a[pq->_front%pq->_size];
    return ret;
}

