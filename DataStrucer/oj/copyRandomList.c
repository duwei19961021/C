//
// Created by duwei on 2020/12/31.
//

/*
 * 复制带随机指针的链表
 * 链接: https://leetcode-cn.com/problems/copy-list-with-random-pointer/
 * */

struct Node* copyRandomList(struct Node* head) {
    struct Node *start = head;

    if(!head)
    {
        return head;
    }

    while(start)
    {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->next = NULL;
        newNode->val = start->val;
        newNode->next = start->next;
        start->next= newNode;
        start = newNode->next;
    }

    struct Node *cur = head;
    while(cur)
    {
        struct Node *copy = cur->next;
        if(cur->random)
        {
            copy->random = cur->random->next;
        }
        else
        {
            copy->random = NULL;
        }

        cur = copy->next;
    }

    cur = head;
    struct Node *newHead = head->next;
    while(cur)
    {
        struct Node *copy = cur->next;
        struct Node *next = copy->next;
        cur->next = next;
        if(next)
        {
            copy->next = next->next;
        }
        else
        {
            copy->next = NULL;
        }
        cur = next;
    }
    return newHead;
}