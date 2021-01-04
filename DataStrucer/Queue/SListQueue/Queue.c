//
// Created by duwei on 2021/1/1.
//

#include "Queue.h"

void QueueInit(Queue* pq)
{
    assert(pq);
    pq->_head = pq->_tail = NULL;
}

void QueueDestory(Queue* pq)
{
    assert(pq);
    QueueNode* cur = pq->_head;
    while (cur)
    {
        QueueNode* next = cur->_next;
        free(cur);
        cur = next;
    }
    pq->_head = pq->_tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
    assert(pq);
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if(!newNode)
    {
        printf("malloc failed.\n");
        exit(-1);
    }
    newNode->_data = x;
    newNode->_next = NULL;

    if (!pq->_head)
    {
        pq->_head = pq->_tail = newNode;
    }
    else
    {
        pq->_tail->_next = newNode;
        pq->_tail = newNode;
    }
}

void QueuePop(Queue* pq)
{
    assert(pq);
    if (!pq->_head)
    {
        printf("Queue is NULL.\n");
        return;
    }

    QueueNode* del = pq->_head;
    pq->_head = pq->_head->_next;
    free(del);

    if (!pq->_head) // head 迭代到为空时，tail会变成野指针，所以要将tail置空
    {
        pq->_tail = NULL;
    }
}

QDataType QueueFront(Queue* pq)
{
    assert(pq);
    assert(pq->_head);
    return pq->_head->_data;
}

QDataType QueueBack(Queue* pq)
{
    assert(pq);
    assert(pq->_tail);
    return pq->_tail->_data;
}

int QueueEmpty(Queue* pq)
{
    return !pq->_head;
}

int QueueSize(Queue* pq)
{
    assert(pq);
    int size = 0;
    QueueNode* start = pq->_head;
    while (start)
    {
        size++;
        start = start->_next;
    }
    return size;
}