#include "SList.h"

void Test()
{
    SListNode* pList = NULL;
    SListPushBack(&pList,1);
    SListPushBack(&pList,2);
    SListPushBack(&pList,3);
    SListPushBack(&pList,4);
    SListPushBack(&pList,5);
    SListPushBack(&pList,6);
    SListPushBack(&pList,7);
    SListPrint(pList);
    printf("NULL\n");
}

int main()
{
    SListNode* pList = NULL;
    Test();
    return 0;
}