//
// Created by duwei on 2020/12/10.
//

/*
 * 移除链表元素
 * 删除链表中等于给定值 val 的所有节点。
 * */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    if (NULL == head)
    {
        return head;
    }
    struct ListNode *pre = NULL;
    struct ListNode *cur = head;
    while (cur)
    {
        if (cur->val == val)
        {
            if (cur==head)
            {
                head = cur->next;
                free(cur);
                cur = head;
            } else{
                pre->next = cur->next;
                free(cur);
                cur = pre->next;
            }
        } else{
            pre = cur;
            cur = cur->next;
        }
    }
    return head;
}