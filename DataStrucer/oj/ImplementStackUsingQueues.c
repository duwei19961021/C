//
// Created by duwei on 2021/1/11.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int STDataType;
typedef struct
{
    int *_a;
    int _front; // 头,出方向
    int _rear; // 尾,进方向
    int _size; // size
} Queue;

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
    STDataType ret = pq->_a[pq->_front];
    return ret;
}

STDataType QueueBack(Queue* pq)
{
    assert(pq);
    STDataType ret = pq->_a[pq->_rear-1];
    return ret;
}

typedef struct {
    Queue _q1;
    Queue _q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* st = (MyStack*)malloc(sizeof(MyStack));
    QueueInit(&st->_q1,100);
    QueueInit(&st->_q2,100);
    return st;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) { // 往非空队列push(因为要留一个空队列来装另一个队列的数据)
    if(!QueueIsEmpty(&obj->_q1))
    {
        QueuePush(&obj->_q1,x);
    }
    else
    {
        QueuePush(&obj->_q2,x);
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    Queue* EmptyQueue = &obj->_q1;
    Queue* NotEmptyQueue = &obj->_q2;

    if(QueueIsEmpty(&obj->_q2)) // 找出空队列和非空队列
    {
        NotEmptyQueue = &obj->_q1;
        EmptyQueue = &obj->_q2;
    }

    while(QueueSize(NotEmptyQueue) > 1) // 将非空队列的元素(除了最后一个元素)移动到空队列
    {
        QueuePush(EmptyQueue,QueueFront(NotEmptyQueue));
        QueuePop(NotEmptyQueue);
    }
    int ret = QueueFront(NotEmptyQueue);
    QueuePop(NotEmptyQueue);  // 拿到非空队列的最后一个数，pop并返回
    return ret;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if(!QueueIsEmpty(&obj->_q1)) // 始终会保持一个队列空一个队列非空，拿到非空队列尾元素
    {
        return QueueBack(&obj->_q1);
    }
    else
    {
        return QueueBack(&obj->_q2);
    }
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return QueueIsEmpty(&obj->_q1) && QueueIsEmpty(&obj->_q2);
}

void myStackFree(MyStack* obj) {

}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/