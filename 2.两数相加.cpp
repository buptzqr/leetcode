/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy_head = new ListNode(-1);
        ListNode *cur_node = dummy_head;
        int flag = 0;
        while (l1 || l2 || flag)
        {
            int x = 0;
            if (l1)
            {
                x += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                x += l2->val;
                l2 = l2->next;
            }
            x += flag;
            flag = x / 10;
            ListNode *node = new ListNode(x % 10);
            cur_node->next = node;
            cur_node = cur_node->next;
        }
        ListNode *ret_node = dummy_head->next;
        delete dummy_head;
        return ret_node;
    }
};
// @lc code=end
