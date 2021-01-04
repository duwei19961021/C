//
// Created by duwei on 2021/1/1.
//
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int QDataType;

typedef struct QueueNode
{
    struct QueueNode* _next;
    QDataType _data;
} QueueNode;

typedef struct Queue
{
    QueueNode* _head;
    QueueNode* _tail;
} Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);