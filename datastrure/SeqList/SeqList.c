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

void SeqListPushBack(SL* ps, SLDataType x)
{
    assert(ps);
    printf("size=%d,cap=%d\n",ps->size,ps->cap);
    if (ps->size >= ps->cap){
        printf("bool = %d\n",ps->size >= ps->cap);
        ps->a = (SLDataType *)realloc(ps->a,sizeof(SL)*ps->cap*2);
        if (NULL == ps->a){
            printf("realloc() failed when Push");
            exit(-1);
        }
        ps->cap*=2;
    }
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
    ;
}

void SeqListPopFront(SL* ps)
{
    ;
}

void SeqListInsert(SL* ps, int pos, SLDataType x)
{
    ;
}

void SeqListErase(SL* ps, int pos, SLDataType x)
{
    ;
}