//
// Created by duwei on 2021/1/6.
//

/*
 * 删除链表中重复的结点
 * 链接：https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&&tqId=11209&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
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
            if(!pHead || !pHead->next)
            {
                return pHead;
            }
            struct ListNode* prev = NULL;
            struct ListNode* cur = pHead;
            struct ListNode* next = cur->next;

            while(next)
            {
                if(cur->val != next->val)
                {
                    prev = cur;
                    cur = next;
                    next = next->next;
                }
                else
                {
                    while(next  && cur->val == next->val)
                    {
                        next = next->next;
                    }
                    // 从这里出来next可能为空

                    if(!prev) // 不加判断，错误用例：{1,1,2}。说明第一个第二个相等(prev初始值为NULL,没有经过第一个判断的赋值)
                    {
                        pHead = next;
                    }
                    else
                    {
                        prev->next = next;
                    }

                    while(cur != next) // 释放重复节点的内存
                    {
                        struct ListNode* del = cur;
                        delete del;
                        cur = cur->next;
                    }
                    // 从这里出来之后，cur和next重合，因为next可能为空，所以cur也可能为空

                    if(cur) // 如果cur为空，说明链表数据已经比较完成，next也无需再移动
                    {
                        next = cur->next;
                    }
                }
            }
            return pHead;
        }
};