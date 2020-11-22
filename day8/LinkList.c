#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct Node{
    int  elem;//存储整形元素
    struct Node *next;//指向直接后继元素的指针
} node;


node * InitList(){
    node * p = (node *)malloc(sizeof(node));
    p->elem = 0;
    p->next = NULL;
    return p;
}

int ListLen(node* p)
{
    p = p->next;
    int count = 0;
    for (;p;) {
        count++;
        p = p->next;
    }
    return count;
}

_Bool ListInsert(node * p, int i, int data){ // i=-1表示插入在尾部;i!=0表示插入到第i个位置，i起始值为1，超过链表长度则添加在末尾
    int length = ListLen(p);
    if (i == -1){
        node * new_node = (node*)malloc(sizeof(node));
        new_node->next = NULL;
        new_node->elem = data;
        for (;p->next;) {
            p = p->next;
        }
        p->next = new_node;
        return 1;
    } else if (i >= 0 && i <= length){
        node * new_node = (node*)malloc(sizeof(node));
        new_node->next = NULL;
        new_node->elem = data;
        for (int j = 0; j < i; j++) {
            p = p->next;
        }
        new_node->next = p->next;
        p->next = new_node;
        return 1;
    } else{
        printf("ListInsert(),invalid i and has insert into last.\n");
        ListInsert(p,-1,data);
        return 0;
    }
}

_Bool ListDelete(node *p,int i)
{
    int length = ListLen(p);
    if (i>length || i < 0){
        printf("ListDelete(),invalid i.\n");
        return 0;
    }
    for (int j = 0; j < i; j++) {
        p = p->next;
    }
    p->next=p->next->next;
    return 1;
}


void traverseList(node * p){
    p = p->next;
    for (;p;) {
        printf("%d ",p->elem);
        p = p->next;
    }
}

_Bool ListSearch(node * p, int data)
{
    for (;p->next;) {
        p = p->next;
        if (p->elem == data)
        {
            return 1;
        }
    }
    printf("the target number not found in ListLink.\n");
    return 0;
}

void ListSort(node * p)
{
    int length = ListLen(p);
    p = p->next;
    for (int num1 = p->elem, i = 0; i < length; ++i,p = p->next) {
        for (int num2 = p->elem,j = 0; j < length-i-1; ++j,p=p->next) {
            if (num1<num2)
            {
                node * pTmp = p->next;
                p->next = p->next->next;
                p = pTmp->next;
            }
        }
    }
}

int main(){
    node * p = InitList();
    srand((unsigned)time(NULL));
    for (int i = 0; i < 100; ++i) {
        ListInsert(p,-1,rand()%100);
    }
    traverseList(p);
    return 0;
}
