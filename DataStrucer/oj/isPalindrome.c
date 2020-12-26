//
// Created by duwei on 2020/12/27.
//

/*编写一个函数，检查输入的链表是否是回文的。
 * */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool isPalindrome(struct ListNode* head){
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while(fast && fast->next) // 找到中间结点。 fast为空或者fast的next为空则意味着fast指针不能再移动，循环应该停止
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *pHead = NULL;
    struct ListNode *current = slow;
    while(current) // 逆置后半部分链表(头插法)，取出第一个节点只想null，取出第二个节点指向第一个节点。。。。
    {
        struct ListNode *next = current->next;
        current->next = pHead;
        pHead = current;
        current = next;
    }

    while(pHead)
    {
        if(pHead->val!=head->val) // 存在节点不相等则返回false
        {
            return false;
        }
        pHead = pHead->next;
        head = head->next;
    }
    return true;
}