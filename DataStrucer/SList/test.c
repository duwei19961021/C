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

void Test()
{
    SListNode* pList = NULL;
    SListPushBack(&pList,1);
    SListPushBack(&pList,1);
    SListPushBack(&pList,1);
    SListPushBack(&pList,1);
    SListPushBack(&pList,1);
    SListPushBack(&pList,1);
    SListPushBack(&pList,2);
    SListPushBack(&pList,1);
    SListPrint(pList);
    SListNode *ret = removeElements(pList,1);
    SListPrint(ret);
}

int main()
{
    SListNode* pList = NULL;
    Test();
    return 0;
}