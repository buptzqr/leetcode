/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if(!head||!head->next)
            return head;
        int node_num = head->val;
        ListNode * pre_node = head;//记录前一个node的位置
        ListNode *cur_node = head->next;
        while (cur_node != NULL)
        {
            if(cur_node->val == node_num){
                ListNode * next_node = cur_node->next;
                pre_node->next = next_node;
                delete cur_node;
                cur_node = next_node;
            }
            else{
                pre_node = cur_node;
                node_num = pre_node->val;
                cur_node = cur_node->next;
            }
        }
        return head;
    }
};
// @lc code=end
