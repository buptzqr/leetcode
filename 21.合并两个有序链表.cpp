/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
// 多个if并列一定要想清楚先后顺序，还有什么时候该用else了
// 链表题一定不要忘记dummy_head
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy_head = new ListNode(-1);
        ListNode *cur_node = dummy_head;
        while (l1 || l2)
        {
            if (!l1)
            {
                cur_node->next = l2;
                break;
            }
            if (!l2)
            {
                cur_node->next = l1;
                break;
            }
            if (l1->val <= l2->val)
            {
                cur_node->next = l1;
                cur_node = cur_node->next;
                l1 = l1->next;
            }
            else
            {
                cur_node->next = l2;
                cur_node = cur_node->next;
                l2 = l2->next;
            }
        }
        return dummy_head->next;
    }
};
// @lc code=end
