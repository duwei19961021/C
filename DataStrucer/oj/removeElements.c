//
// Created by duwei on 2020/12/10.
//

/*
 * 移除链表元素
 * 删除链表中等于给定值 val 的所有节点。
 * */

SListNode* removeElements(SListNode* phead, int val){
    if (NULL == phead)
    {
        return phead;
    }
    SListNode *pre = NULL;
    SListNode *cur = phead;
    while (cur)
    {
        if (cur->data == val)
        {
            if (cur==phead)
            {
                phead = cur->next;
                free(cur);
                cur = phead;
            } else{
                pre->next = cur->next;
                free(cur);
                cur = pre->next;
            }
        } else{
            pre = cur;
            cur = cur->next;
        }
    }
    return phead;
}