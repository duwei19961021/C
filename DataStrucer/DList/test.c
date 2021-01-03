#include "DList.h"

void TestList1()
{
    ListNode *phead = NULL;
    ListInit(&phead);
    ListPushBack(phead,1);
    ListPushBack(phead,2);
    ListPushBack(phead,3);
    ListPushBack(phead,4);
    ListPushFront(phead,0);
    ListPopBack(phead);
    ListPopBack(phead);
    ListPrint(phead);

    ListPopFront(phead);
    ListPopFront(phead);
    ListPopFront(phead);
    ListPopFront(phead);
    ListPrint(phead);

    ListPushFront(phead,99);
    ListPushFront(phead,99);
    ListPushFront(phead,99);
    ListPrint(phead);

    ListPopFront(phead);ListPopFront(phead);ListPopFront(phead);
    ListInsert(phead->next->next,10000);
    ListNode *ret  = ListFind(phead,10000);
    ret->data=9999;
    ListPrint(phead); // 02:12:00

    ListPushFront(phead,0);
    ListPushFront(phead,1);
    ListPushFront(phead,2);
    ListPrint(phead);

    ListErase(phead->next->next);
    ListErase(phead->next);
    ListPrint(phead);

    printf("===========\n");
    ListDestory(&phead);
    ListPrint(phead);

}

int main()
{
    TestList1();
    return 0;
}