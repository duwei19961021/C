//
// Created by duwei on 2020/12/10.
//

/*
 * 寻找链表中倒数第k个节点*/
SListNode* FindKthTotal(SListNode* phead, int k)
{
    SListNode *slow = phead;
    SListNode *quick = phead;
    for (int i = 0; i < k; ++i) {
        quick=quick->next;
    }
    while (quick)
    {
        slow = slow->next;
        quick = quick->next;
    }
    return slow;
}