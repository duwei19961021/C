//
// Created by duwei on 2021/1/5.
//

/*
 * 给定一个链表: 1->2->3->4->5, 和 k = 2.
 * 返回链表 4->5.
 * */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode* front = head;
    struct ListNode* rear = head;
    while(k)
    {
        rear = rear->next;
        k--;
    }

    while(rear)
    {
        front = front->next;
        rear = rear->next;
    }
    return front;
}