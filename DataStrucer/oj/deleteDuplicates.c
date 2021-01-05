//
// Created by duwei on 2020/12/29.
//

/* 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
 * 链接: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
 * */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
 * 解题思路：
 * 创建前后两个指针，利用后指针去探路，值相同则移动后指针然后将前指针的next指向新的后指针(跳过中间元素)
 * */

struct ListNode* deleteDuplicates(struct ListNode* head){
    if(!head) // 处理空链表情况
    {
        return head;
    }
    struct ListNode* first = head;
    struct ListNode* second = head->next; // 定义一前一后的两个指针
    while(second)
    {
        if(first->val == second->val) // 前指针和后指针的val值相等则说明相邻结点val相同
        {
            second = second->next; // 移动后指针的位置
            first->next = second; // 并将前指针的next指向新的后指针
        }
        else // 相邻元素不同，则同时移动指针
        {
            first = first->next;
            second = second->next;
        }
    }
    return head;
}


/*
 * 写法2
 * */

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
        public:
        ListNode* deleteDuplication(ListNode* pHead)
        {
            struct ListNode* first = pHead;
            struct ListNode* cur = pHead;
            struct ListNode* next = cur->next;
            while(next)
            {
                if(cur->val == next->val)
                {
                    next = next->next;
                }
                else
                {
                    first->next = next->next;
                    first = first->next;
                    cur = first;
                    next = first->next;
                }
            }
            if(cur != next)
            {
                cur->next=NULL;
            }
            return pHead;
        }
};