//
// Created by duwei on 2021/1/1.
//
#pragma once
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

void QueueInit(Queue* pq, int size); // size为栈大小
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq,STDataType x);
void QueuePop(Queue* pq);
int QueueSize(Queue* pq);
int QueueIsEmpty(Queue* pq); // 1是空,0是非空
STDataType QueueFront(Queue* pq);
int QueueIsFull(Queue* pq);
STDataType QueueBack(Queue* pq);