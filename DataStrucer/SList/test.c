#include "SList.h"
#include <stdlib.h>

SListNode* removeElements(SListNode* phead, int val){
    SListNode *pre = phead;
    while (val == pre->data){
        if (NULL == pre->next)
        {
            pre=NULL;
            return pre;
        }
        pre = pre->next;
    }
    SListNode *cur = pre;
    SListNode *check = pre;
    while (NULL != cur->next)
    {
        check = cur->next;
        if (val == check->data)
        {
            cur->next = check->next;
        } else{
            cur = cur->next;
        }
    }
    return pre;
}

void Test()
{
    SListNode* pList = NULL;
    SListPushBack(&pList,6);
    SListPushBack(&pList,6);
    SListPushBack(&pList,6);
    SListPushBack(&pList,6);
    SListPushBack(&pList,3);
    SListPushBack(&pList,3);
    SListPushBack(&pList,2);
    SListPushBack(&pList,6);
    SListPushBack(&pList,6);
    SListPushBack(&pList,3);
    SListPushBack(&pList,3);
    SListPushBack(&pList,4);
    SListPushBack(&pList,5);
    SListPushBack(&pList,5);
    SListPushBack(&pList,6);
    SListPushBack(&pList,6);
    SListPushBack(&pList,6);
    SListPushBack(&pList,6);
    SListPushBack(&pList,6);
    SListPrint(pList);
    SListNode *ret = removeElements(pList,6);
    SListPrint(ret);
}

int main()
{
    SListNode* pList = NULL;
    Test();
    return 0;
}