//
// Created by duwei on 2020/12/10.
//

/*
 * 移除链表元素
 * 删除链表中等于给定值 val 的所有节点。
 * */

SListNode* removeElements(SListNode* phead, int val){
    SListNode *pre = phead;
    while (val == pre->data){
        /*
         * 先判断头是否等于val*/
        if (NULL == pre->next)
        {
            pre=NULL;
            return pre;
        }
        pre = pre->next;
    }
    SListNode *cur = pre;
    SListNode *check = pre;
    while (NULL != cur->next)
    {
        check = cur->next;
        if (val == check->data)
        {
            cur->next = check->next;
        } else{
            cur = cur->next;
        }
    }
    return pre;
}