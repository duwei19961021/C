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
    SeqListPrint(&s);
    printf("size=%d,cap=%d\n",s.size,s.cap);
}
int main()
{
    TestSeqList1();
    return 0;
}