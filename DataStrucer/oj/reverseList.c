//
// Created by duwei on 2020/12/9.
//

#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
 * 反转链表
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *pHead = NULL;
    struct ListNode *curent = head;
    while(NULL != curent)
    {
        struct ListNode *next = curent->next;
        curent->next = pHead;
        pHead = curent;
        curent = next;
    }
    return pHead;
}