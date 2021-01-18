/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
// #include <iostream>
// using namespace std;
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        //一个简单的想法就是创建两个链表，一个用来比x小的，一个用来保存不比x小的
        //最后把两个链表连接起来
        ListNode *small_head = new ListNode(-1);
        ListNode *big_head = new ListNode(-1);
        small_head->next = NULL;
        big_head->next = NULL;
        ListNode *cur_node = head;
        ListNode *cur_node_small = small_head;
        ListNode *cur_node_big = big_head;

        while (cur_node)
        {
            if (cur_node->val < x)
            {
                cur_node_small->next = cur_node;
                cur_node_small = cur_node;
            }
            else
            {
                cur_node_big->next = cur_node;
                cur_node_big = cur_node;
            }
            cur_node = cur_node->next;
        }
        cur_node_big->next = NULL;
        cur_node_small->next = big_head->next;
        ListNode *ret_node = small_head->next;
        delete big_head;
        delete small_head;
        return ret_node;
    }
};
// @lc code=end
// ListNode *build_list(int arr[], int n)
// {
//     if (n == 0)
//         return NULL;
//     ListNode *head = new ListNode(arr[0]);
//     ListNode *cur = head;
//     for (int i = 1; i < n; i++)
//     {
//         ListNode *node = new ListNode(arr[i]);
//         cur->next = node;
//         cur = node;
//     }
//     cur->next = NULL;

//     return head;
// }
// int main()
// {
//     int arr[] = {1, 4, 3, 2, 5, 2};
//     ListNode *head = build_list(arr, sizeof(arr) / sizeof(arr[0]));
//     head = Solution().partition(head, 3);
//     cout << "hello" << endl;
// }