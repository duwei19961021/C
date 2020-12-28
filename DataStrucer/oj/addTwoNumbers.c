//
// Created by duwei on 2020/12/28.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* 给出两个非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照逆序的方式存储的，并且它们的每个节点只能存储一位数字。
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 您可以假设除了数字 0 之外，这两个数都不会以 0开头。
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/add-two-numbers
 *
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 * */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *jump = head;
    int N = 0;
    while(l1 && l2)
    {
        if(l1->val+l2->val+N >= 10)
        {
            struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode->next = NULL;
            newNode->val = (l1->val+l2->val+N)%10;
            N = 1;
            jump->next = newNode;
            jump = jump->next;
        }
        else
        {
            struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode->next = NULL;
            newNode->val = l1->val+l2->val+N;
            N = 0;
            jump->next = newNode;
            jump = jump->next;
        }
        l1 = l1->next;
        l2 = l2->next;
    }

    if(l1 == NULL && l2 !=NULL)
    {
        while(l2)
        {
            if(l2->val+N >= 10)
            {
                struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
                newNode->next = NULL;
                newNode->val = (l2->val+N)%10;
                N = 1;
                jump->next = newNode;
                jump = jump->next;
            }
            else
            {
                struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
                newNode->next = NULL;
                newNode->val = l2->val+N;
                N = 0;
                jump->next = newNode;
                jump = jump->next;
            }
            l2=l2->next;
        }
    }
    else if(l1 != NULL && l2 ==NULL)
    {
        while(l1)
        {
            if(l1->val+N >= 10)
            {
                struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
                newNode->next = NULL;
                newNode->val = (l1->val+N)%10;
                N = 1;
                jump->next = newNode;
                jump = jump->next;
            }
            else
            {
                struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
                newNode->next = NULL;
                newNode->val = l1->val+N;
                N = 0;
                jump->next = newNode;
                jump = jump->next;
            }
            l1=l1->next;
        }
    }

    if( N !=0)
    {
        struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        newNode->val=1;
        jump->next = newNode;
    }

    return head->next;
}