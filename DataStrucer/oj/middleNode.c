//
// Created by duwei on 2020/12/10.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
 * 链表的中间结点
 * 给定一个头结点为 head 的非空单链表，返回链表的中间结点。
 * 如果有两个中间结点，则返回第二个中间结点。
 *
 * 输入：[1,2,3,4,5] 输出：此列表中的结点 3 (序列化形式：[3,4,5])
 * 输入：[1,2,3,4,5,6] 输出：此列表中的结点 4 (序列化形式：[4,5,6])
 * */

struct ListNode* middleNode(struct ListNode* head){
    int count = 0;
    struct ListNode *cur = head;
    while(NULL!=cur)
    {
        count++;
        cur = cur->next;
    }

    int i = count/2 + 1;

    struct ListNode *cur2 = head;
    while(i>1) // 返回第i个节点则需要循环i-1次，因为初始指向第一个节点。
    {
        cur2 = cur2->next;
        i--;
    }
    return cur2;
}


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* quick = head;
    struct ListNode* slow = head;
    while(quick->next) // quick的下一个节点为空则表示已经走到最后一个节点了
    {
        if(quick->next->next == NULL) // 当链表节点是偶数时要考虑quick指针在在最后一次移动时是否能移动两步
        {
            quick = quick->next; // 最后一次不能移动两步那么就移动一步
        }
        else
        {
            quick = quick->next->next;
        }
        slow = slow->next; // 每次移动一步
    }
    return slow;
}