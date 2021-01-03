//
// Created by duwei on 2021/1/1.
//
#pragma once
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef int LTDataType;

typedef struct ListNode
{
    struct ListNode* next;
    struct ListNode* prev;
    LTDataType data;
} ListNode;

void ListInit(ListNode** pphead);
void ListPrint(ListNode* phead);
void ListPushBack(ListNode *phead,LTDataType x);
ListNode* BuyLIstNode(LTDataType x);
void ListPopBack(ListNode *phead);
void ListPushFront(ListNode *phead,LTDataType x);
void ListPopFront(ListNode *phead);
ListNode* ListFind(ListNode *phead, LTDataType x);
void ListInsert(ListNode *pos, LTDataType x);
void ListErase(ListNode* pos);
void ListDestory(ListNode **pphead);
void ListClear(ListNode *phead);


/*
 * 变量风格:
 *      pos_prev
 *      posPrev
 * 函数风格:
 *      ListPrint
 *      list_print
 * */