/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
 
class Solution {
public:
// o(n)空间复杂度
    // ListNode *detectCycle(ListNode *head) {
    //     vector<ListNode*> node_vec;
    //     if(!head||!head->next)
    //         return NULL;
    //     node_vec.push_back(head);
    //     while(head->next){
    //         head = head->next;
    //         auto itr = find(node_vec.begin(),node_vec.end(),head);
    //         if(itr==node_vec.end())
    //             node_vec.push_back(head);
    //         else
    //             return *itr;
    //     }
    //     return NULL;
    // }
    // o(1)空间复杂度 快慢指针法
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next)
            return NULL;
        ListNode *dummy_head = new ListNode(-1);
        dummy_head->next = head;
        ListNode* slow = dummy_head;
        ListNode* fast = dummy_head;
        bool flag = false;
        while(fast->next&&fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                flag = true;
                break;
            }
        }
        if(!flag)
            return NULL;
        fast = dummy_head;
        while(fast!=slow){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

};

// @lc code=end

