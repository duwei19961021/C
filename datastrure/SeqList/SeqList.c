#include "SeqList.h"

void SeqListInit(SL *ps)
{
    ps->a = (SLDataType*)malloc(sizeof(SLDataType)*4);
    if (NULL == ps->a)
    {
        printf("malloc failed when SeqListInit.");
        exit(-1);
    }
    ps->size=0;
    ps->cap=4;
}

void SeqListCheckCap(SL *ps)
{
    if (ps->size >= ps->cap){
        ps->a = (SLDataType *)realloc(ps->a,sizeof(SL)*ps->cap*2);
        if (NULL == ps->a){
            printf("realloc() failed");
            exit(-1);
        }
        ps->cap*=2;
    }
}

void SeqListPushBack(SL* ps, SLDataType x)
{
    assert(ps);
    SeqListCheckCap(ps);
    ps->a[ps->size] = x;
    ps->size++;
}

void SeqListPrint(SL* ps)
{
    assert(ps);
    for (int i = 0; i < ps->size; ++i) {
        printf("%d ",ps->a[i]);
    }
    printf("\n");
}

void SeqListPopBack(SL* ps)
{
    assert(ps);
    ps->size--;
}

void SeqListPushFront(SL* ps, SLDataType x)
{
    assert(ps);
    SeqListCheckCap(ps);
    for (int i = ps->size-1; i >= 0; i--) {
        ps->a[i+1] = ps->a[i];
    }
    ps->a[0]=x;
    ps->size++;
}

void SeqListPopFront(SL* ps)
{
    assert(ps);
    for (int i = 0; i < ps->size; ++i) {
        ps->a[i] = ps->a[i+1];
    }
    ps->size--;
}

void SeqListInsert(SL* ps, int pos, SLDataType x)
{
    assert(ps);
    SeqListCheckCap(ps);
    for (int i = ps->size-1; i >= pos; i--) {
        ps->a[i+1] = ps->a[i];
    }
    ps->a[pos] = x;
    ps->size++;
}

void SeqListErase(SL* ps, int pos)
{
    assert(ps);
    for (int i = pos; i <= ps->size; i++) {
        ps->a[i] = ps->a[i+1];
    }
    ps->size--;
}