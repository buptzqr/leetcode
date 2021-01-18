/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
// #include<iostream>
// using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
//这里犯的错误还是if，else一定要想明白
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode *dummy_head = new ListNode(-1);
        dummy_head->next = head;
        ListNode *cur = head->next; //指向待排序节点
        head->next = NULL;
        while (cur)
        {
            ListNode *sorted_pre =dummy_head->next; //指向有序列表中当前待比较元素的前一个元素
            ListNode *cur_next = cur->next; //指向待排序节点的后一个
            cur->next = NULL;
            if (cur->val < sorted_pre->val)
            {
                cur->next = sorted_pre;
                dummy_head->next = cur;
            }
            else{
                while(sorted_pre->next){
                    if(sorted_pre->next->val>cur->val){
                        cur->next = sorted_pre->next;
                        sorted_pre->next = cur;
                        break;
                    }
                    sorted_pre = sorted_pre->next;
                }
                if(!sorted_pre->next)
                    sorted_pre->next = cur;
            }

            cur = cur_next;
        }
        ListNode *ret_node = dummy_head->next;
        delete dummy_head;
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
//     int arr[] = {4,2,1,3};
//     ListNode *head = build_list(arr, sizeof(arr) / sizeof(arr[0]));
//     head = Solution().insertionSortList(head);
//     cout << "hello" << endl;
// }
