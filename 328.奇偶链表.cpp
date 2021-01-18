/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
    ListNode *oddEvenList(ListNode *head)
    {
        //这个就和86号题目很像了
        ListNode *odd_head = new ListNode(-1);
        ListNode *even_head = new ListNode(-1);
        ListNode *odd_cur_node = odd_head;
        ListNode *even_cur_node = even_head;
        ListNode *cur_node = head;
        int index = 1;
        while (cur_node)
        {
            if (index % 2 == 0)
            {
                even_cur_node->next = cur_node;
                even_cur_node = cur_node;
            }
            else
            {
                odd_cur_node->next = cur_node;
                odd_cur_node = cur_node;
            }
            cur_node = cur_node->next;
            index++;
        }
        even_cur_node->next = NULL;
        odd_cur_node->next = even_head->next;
        ListNode *ret_node = odd_head->next;
        delete even_head;
        delete odd_head;
        return ret_node;
    }
};
// @lc code=end
