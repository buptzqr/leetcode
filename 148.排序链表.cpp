/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
// #include <iostream>
// using namespace std;
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
// 就是用归并排序的思路,找中点用快慢指针的思路（就是一个指针一次移动两个位置，一个指针一次移动一个位置）
    // ListNode* sortList(ListNode* head) {
    //     if(!head||!head->next)
    //         return head;
    //     ListNode* dummy_head = new ListNode(-1);
    //     dummy_head->next =head;
    //     ListNode *slow = dummy_head;
    //     ListNode *fast = dummy_head;
    //     while(fast->next){
    //         slow = slow->next;
    //         fast = fast->next;
    //         if(fast->next)
    //             fast = fast->next;
    //     }
    //     ListNode* mid = slow->next;
    //     slow->next = NULL;
    //     return merge(sortList(head), sortList(mid));
    // }
    // 这个自底向上的思路主要就是，要有一个pre把归并以后的链表穿起来，然后
    // 要注意最后一个分组不足size（甚至没有最后一个分组）的情况的处理
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)
            return head;
        int list_len = 0;
        ListNode *cur = head;
        while (cur)
        {
            cur =cur->next;
            list_len++;
        }
        ListNode *dummy_head = new ListNode(-1);
        dummy_head->next = head;
        for(int size = 1;size<=list_len;size+=size){
            ListNode *begin = dummy_head->next;
            ListNode *mid = dummy_head->next;
            ListNode *pre = dummy_head;
            while(begin){
                for (int i = 0;i<size-1&&mid;i++){
                    mid = mid->next;        
                }
                if(mid&&mid->next){
                    ListNode *mid_next = mid->next;
                    mid->next = NULL;
                    mid = mid_next;
                }
                else{
                    pre->next = begin;
                    break;
                }

                ListNode *next_begin = mid;
                for (int i = 0; i < size-1&&next_begin; i++)
                {
                    next_begin = next_begin->next;
                }
                if (next_begin)
                {
                    ListNode *tag = next_begin->next;
                    next_begin->next = NULL;
                    next_begin = tag;
                }
                pre->next=merge(begin, mid);
                while(pre->next){
                    pre = pre->next;
                }
                begin = next_begin;
                mid = begin;
            }
        }
        ListNode *ret = dummy_head->next;
        delete dummy_head;
        return ret;
    }
    ListNode* merge(ListNode* h1,ListNode* h2) {
        ListNode* dummy_head = new ListNode(-1);
        ListNode *cur = dummy_head;
        while (h1 && h2)
        {
            if(h1->val<=h2->val){
                cur->next = h1;
                h1 = h1->next;
                cur=cur->next;
            }
            else{
                cur->next = h2;
                h2 = h2->next;
                cur=cur->next;
            }
        }
        if(h2)
            cur->next = h2;
        if(h1)
            cur->next = h1;
        ListNode* ret_node = dummy_head->next;
        delete dummy_head;
        return ret_node;
    }
};
ListNode *build_list(int arr[], int n)
{
    if (n == 0)
        return NULL;
    ListNode *head = new ListNode(arr[0]);
    ListNode *cur = head;
    for (int i = 1; i < n; i++)
    {
        ListNode *node = new ListNode(arr[i]);
        cur->next = node;
        cur = node;
    }
    cur->next = NULL;

    return head;
}
// int main()
// {
//     int arr[] = {-1,5,3,4,0};
//     ListNode *head = build_list(arr, sizeof(arr) / sizeof(arr[0]));
//     head = Solution().sortList(head);
//     cout << "hello" << endl;
// }

// @lc code=end

