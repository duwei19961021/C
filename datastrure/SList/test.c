#include "SList.h"
#include <stdlib.h>

void Test()
{
    SListNode* pList = NULL;
    SListPushBack(&pList,1);
    SListPushBack(&pList,2);
    SListPushBack(&pList,3);
    SListPrint(pList);
    printf("NULL\n");
    SListPopBack(&pList);
    SListPopBack(&pList);
    SListPopBack(&pList);
    SListPopBack(&pList);
    SListPushFront(&pList,100);
    SListPushFront(&pList,99);
    SListPushFront(&pList,98);
    SListPushFront(&pList,97);
    SListPushFront(&pList,96);
    SListPrint(pList);
    printf("NULL\n");
    SListPopFront(&pList);
    SListPopFront(&pList);
    SListPrint(pList);
    printf("NULL\n");
    SListNode* point = SListFind(pList,99);
    printf("point = %d\n",point->data);
    point->data = 9999;
    free(point);
    SListPrint(pList);
    printf("NULL\n");
}

int main()
{
    SListNode* pList = NULL;
    Test();
    return 0;
}