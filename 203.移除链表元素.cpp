/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy_head = new ListNode(-1);
        dummy_head->next = head;
        ListNode* before_node = dummy_head;
        ListNode* cur_node = dummy_head -> next;
        while(cur_node){
            if(cur_node->val == val){
                ListNode* delete_node = cur_node;
                before_node->next = cur_node-> next;
                cur_node = cur_node -> next;
                delete delete_node;
            }
            else{
                before_node = cur_node;
                cur_node = cur_node -> next;
            }
        }
        return dummy_head->next;
    }
};
// @lc code=end

