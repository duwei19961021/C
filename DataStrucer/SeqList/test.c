#include "SeqList.h"

void TestSeqList1()
{
    SeqList s;
    SeqListInit(&s);
    SeqListPushBack(&s, 10);
    SeqListPushBack(&s, 99);
    SeqListPushBack(&s, 1000);
    SeqListPushBack(&s, 1000);
    SeqListPushBack(&s, 1000);
    SeqListPushBack(&s, 1000);
    SeqListPushBack(&s, 1000);
    SeqListPushBack(&s, 1000);
    SeqListPushBack(&s, 1000);
    SeqListPrint(&s);
    SeqListPopBack(&s);
    SeqListPopBack(&s);
    SeqListPopBack(&s);
    SeqListPrint(&s);
    SeqListPushFront(&s,999);
    SeqListPushFront(&s,999);
    SeqListPushFront(&s,999);
    SeqListPushFront(&s,999);
    SeqListPushFront(&s,999);
    SeqListPushFront(&s,999);
    SeqListPushFront(&s,999);
    SeqListPushFront(&s,999);
    SeqListPushFront(&s,999);
    SeqListPushFront(&s,888);
    SeqListPrint(&s);
    SeqListPopFront(&s);
    SeqListPrint(&s);
    SeqListInsert(&s,1,555);
    SeqListInsert(&s,1,444);
    SeqListPrint(&s);
    printf("\n");
    SeqListErase(&s,1);
    SeqListErase(&s,1);
    SeqListPrint(&s);
    printf("size=%d,cap=%d\n",s.size,s.cap);
}
int main()
{
    TestSeqList1();
    return 0;
}