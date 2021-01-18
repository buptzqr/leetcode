/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
// #include <stack>
// using namespace std;
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 先进行reverse就成了第二题了
        // 辅助数据结构，用栈也可以
        // 波神也就这两种思路
        // 学习一下stack的各种操作，常见的就是push,pop,top,size,empty
        stack<int> s1;
        stack<int> s2;
        while(l1){
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2=l2->next;
        }
        int flag = 0;
        ListNode* dummy_head = new ListNode(-1);
        stack<int> res;
        while(!s1.empty()||!s2.empty()||flag){
            int x = 0;
            if(!s1.empty()){
                x += s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                x += s2.top();
                s2.pop();
            }
            x += flag;
            res.push(x % 10);
            flag = x / 10; 
        }
        ListNode *cur_node = dummy_head;
        while(!res.empty()){
            ListNode *node = new ListNode(res.top());
            cur_node -> next = node;
            cur_node = node;
            res.pop();
        }

        ListNode* ret_node = dummy_head->next;
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
//     int arr1[] = {7,2,4,3};
//     int arr2[] = {5,6,4};
//     ListNode *head1 = build_list(arr1, sizeof(arr1) / sizeof(arr1[0]));
//     ListNode *head2 = build_list(arr2, sizeof(arr2) / sizeof(arr2[0]));
//     head1 = Solution().addTwoNumbers(head1, head2);
//     cout << "hello" << endl;
// }
