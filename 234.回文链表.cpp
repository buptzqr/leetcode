/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.*/
#include<iostream>
using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* reverseList(ListNode *head){
        ListNode* before = NULL;
        ListNode* cur = head;
        while(cur){
            ListNode* after = cur->next;
            cur->next = before;
            before = cur;
            cur = after;
        }
        return before;
    }
    bool isPalindrome(ListNode* head) {
        // 找到前半部分链表的尾节点。
        // 反转后半部分链表。
        // 判断是否回文。
        // 恢复链表。
        // 返回结果。
        if(!head||!head->next)
            return true;
        ListNode* slow = head;    
        ListNode* fast = head;
        while(fast->next&&fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // 反转后半部分链表。
        ListNode* head1 = reverseList(slow->next);
        // 判断是否回文
        ListNode* cur1 = head;
        ListNode* cur2 = head1;
        bool res = true;
        while(cur2){
            if(cur2->val!=cur1->val){
                res = false;
                break;
            }
            else{
                cur1=cur1->next;
                cur2 = cur2->next;
            }        
        }
        //恢复链表
        slow->next = reverseList(head1);
        return res; 
    }
};
// @lc code=end

