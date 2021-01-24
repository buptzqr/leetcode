/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// #include<iostream>
// using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //倒数第n个节点就相当于知道了这个节点和尾节点的距离，就不需要先扫描一次来确定这个链表
        // 有多少节点了
        if(!head)
            return NULL;
        ListNode* dummy_head = new ListNode(-1);
        dummy_head->next = head;
        ListNode* before=dummy_head;
        ListNode* cur = dummy_head->next;
        ListNode* sentinel = cur;
        while(n>1){
            sentinel= sentinel->next;
            n--;
        }
        while(sentinel->next){
            sentinel = sentinel->next;
            cur = cur->next;
            before = before->next;
        }
        ListNode* after = cur->next;
        before->next = after;
        delete cur;
        ListNode* ret =dummy_head->next;
        delete dummy_head;
        return ret;
    }
};
// @lc code=end

