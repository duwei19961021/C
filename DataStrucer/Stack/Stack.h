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
    STDataType* _a;
    int  _top;
    int _capacity;
} Stack;

void StackInit(Stack* pst);
void StackDestory(Stack* pst);
void StackPush(Stack* pst,STDataType x);
void StackPop(Stack* pst);
int StackSize(Stack* pst);
int StackEmpty(Stack* pst); // 1是空,0是非空
STDataType StackTop(Stack* pst);
void PrintStack(Stack* pst);