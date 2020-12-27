//
// Created by duwei on 2020/12/27.
//

/*给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
 * 链接：https://leetcode-cn.com/problems/linked-list-cycle-ii/
 * */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
        {
            break;
        }
    }

    if(!fast || !fast->next)
    {
        return NULL;
    }

    while(fast && head)
    {
        if(fast == head)
        {
            return fast;
        }
        fast = fast->next;
        head = head->next;
    }
    return NULL;
}