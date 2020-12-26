//
// Created by duwei on 2020/12/26.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 * */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    // 判断存在空链表的情况
    if(!l1)
    {
        return l2;
    }
    if(!l2)
    {
        return l1;
    }

    // 新建一个头
    struct ListNode *head = NULL, *tail = NULL;

    // 比较两个链表的首元素，小的那个链表作为新链表的头
    if(l1->val < l2->val)
    {
        head = tail = l1;
        l1 = l1->next;
    }
    else
    {
        head = tail = l2;
        l2 = l2->next;
    }

    // 遍历 比较元素大小，小的取出尾插
    while(l1 && l2)
    {
        if(l1->val < l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // 比较完之后，不为空的链表追加到新链表表
    if(l1)
    {
        tail->next = l1;
    }
    else{
        tail->next = l2;
    }

    return head;
}