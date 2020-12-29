//
// Created by duwei on 2020/12/29.
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。
 * 请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
 * 请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
 * 链接：https://leetcode-cn.com/problems/odd-even-linked-list
 *
 * 输入: 1->2->3->4->5->NULL
 * 输出: 1->3->5->2->4->NULL
 * */

/*
 * 解题思路：
 * 创建两个指针：first、second
 * first指向第一个元素，second指向第二个元素。
 * 每一次循环将first的next指向first->next->next，first = first->next。
 * 这样奇数位置上的结点就会连成一个链表
 * second同理，不过不同的是要再拿一个指针保存second的头结点。
 * 因为循环完成之后要将first的尾结点指向second的头结点
 * */

struct ListNode* oddEvenList(struct ListNode* head){
    if(!head)
    {
        return head;
    }
    struct ListNode *first = head;
    struct ListNode *second = head->next,*second_head = head->next;
    while(first && first->next && second && second->next)
    {
        first->next = first->next->next;
        first = first->next;
        second->next = second->next->next;
        second = second->next;
    }
    first->next = second_head;
    return head;
}