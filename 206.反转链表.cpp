/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // ListNode* reverseList(ListNode* head) {
    //     // 三个指针，一个指向当前节点，一个指向前一个节点，一个指向后一个节点
    //     ListNode* cur = head;
    //     ListNode* before = NULL;
    //     while(cur){
    //         ListNode* next = cur->next;
    //         cur->next = before;
    //         before = cur;
    //         cur= next;
    //     }
    //     return before;
    // }
    ListNode* reverseList(ListNode* head){
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode* tail = head->next;
        ListNode* new_head = reverseList(head -> next);
        tail->next = head;
        head->next = NULL;
        return new_head;
    }
};
// @lc code=end

