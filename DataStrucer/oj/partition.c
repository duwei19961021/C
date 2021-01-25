//
// Created by duwei on 2021/1/25.
//

/*
 * 链表分割
 * 使用两个链表，一个保存大于x的，一个保存小于x的，最后再合并两个链表。
 * 链接：https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
 * */

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/

class Partition {
        public:
        ListNode* partition(ListNode* pHead, int x) {
            struct ListNode* smallTail = NULL;
            struct ListNode* small = (struct ListNode*)malloc(sizeof(struct ListNode)); // 哨兵位,一定是malloc的结点，否则返回栈上地址会段错误
            small->next = NULL;
            smallTail = small;

            struct ListNode* bigTail = NULL;
            struct ListNode* big = (struct ListNode*)malloc(sizeof(struct ListNode)); // 哨兵位
            big->next = NULL;
            bigTail = big;

            struct ListNode* cur = pHead;
            while(cur)
            {
                if(cur->val < x)
                {
                    smallTail->next = cur;
                    smallTail = smallTail->next;
                    cur = cur->next;
                }
                else
                {
                    bigTail->next = cur;
                    bigTail = bigTail->next;
                    cur = cur->next;
                }
            }
            smallTail->next = big->next;
            bigTail->next = NULL;
            return small->next;
        }
};