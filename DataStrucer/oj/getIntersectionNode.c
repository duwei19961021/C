//
// Created by duwei on 2020/12/27.
//

/*编写一个程序，找到两个单链表相交的起始节点。
 * */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *headOne = headA;
    struct ListNode *headTwo = headB;

    int lengthA = 0; // 计算两个链表的长度
    int lengthB = 0;

    while(headOne)
    {
        lengthA++;
        headOne = headOne->next;
    }

    while(headTwo)
    {
        lengthB++;
        headTwo = headTwo->next;
    }

    int  before = abs(lengthA-lengthB); // 计算链表长度差

    if(lengthA > lengthB) // 长的链表先走befor步
    {
        while(before--)
        {
            headA = headA->next;
        }
    }
    else if(lengthB > lengthA)
    {
        while(before--)
        {
            headB = headB->next;
        }
    }

    while(headB && headA) // 比较节点是否相同
    {
        if(headA == headB)
        {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }

    return NULL;
}