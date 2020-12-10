#include "SList.h"
#include <stdlib.h>

SListNode* removeElements(SListNode* phead, int val){
    if (NULL == phead)
    {
        return phead;
    }
    SListNode *pre = NULL;
    SListNode *cur = phead;
    while (cur)
    {
        if (cur->data == val)
        {
            if (cur==phead)
            {
                phead = cur->next;
                free(cur);
                cur = phead;
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
    return phead;
}

SListNode* FindKthTotal(SListNode* phead, int k)
{
    SListNode *slow = phead;
    SListNode *quick = phead;
    for (int i = 0; i < k; ++i) {
        quick=quick->next;
    }
    while (quick)
    {
        slow = slow->next;
        quick = quick->next;
    }
    return slow;
}

void Test()
{
    SListNode* pList = NULL;
    SListPushBack(&pList,1);
    SListPushBack(&pList,2);
    SListPushBack(&pList,3);
    SListPushBack(&pList,4);
    SListPushBack(&pList,5);
    SListPushBack(&pList,6);
    SListPrint(pList);
    SListNode *ret = FindKthTotal(pList,1);
    printf("ret = %d\n",ret->data);
}

int main()
{
    Test();
    return 0;
}