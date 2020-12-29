//
// Created by duwei on 2020/12/29.
//

/*
 * 二进制链表转整数
 * 输入：head = [1,0,1]
 * 输出：5
 * 解释：二进制数 (101) 转化为十进制数 (5)
 * */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getDecimalValue(struct ListNode* head){
    int length = 0;
    struct ListNode *count = head;
    while(count)
    {
        length++;
        count = count->next;
    }

    int sum = 0;

    while(head)
    {
        if(head->val)
        {
            sum += pow(2,length-1);
        }
        head = head->next;
        length--;
    }
    return sum;
}