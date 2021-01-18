/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    // 不要想的太复杂，就是先探出来重复区间的头和尾，然后连接非重复的就行
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode *prev = dummyHead; //非头节点的
        ListNode *cur = prev->next;
        while (cur)
        {

            int num = 0;
            ListNode *p = cur;
            while (p && p->val == cur->val)
            {
                num++;
                p = p->next;
            }

            if (num <= 1)
            {
                prev->next = cur;
                prev = prev->next;
            }
            cur = p;
        }
        prev->next = NULL;
        ListNode *ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};
// @lc code=end
