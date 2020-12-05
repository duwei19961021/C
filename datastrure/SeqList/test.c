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
}
int main()
{
    TestSeqList1();
    return 0;
}