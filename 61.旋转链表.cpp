/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.*/
// #include<iostream>
// using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
//这个题的关键就是找到新的头节点的前一个节点
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next)
            return head;
        ListNode* tail=head;
        int list_len = 1;
        while(tail->next){
            list_len++;
            tail=tail->next;
        }
        k = list_len-k%list_len;
        ListNode* trans_head_before = head;
        for(int i = 1;i<k;i++)
            trans_head_before=trans_head_before->next;
        tail->next = head;
        ListNode* ret = trans_head_before->next;
        trans_head_before->next = NULL;
        return ret;
    }
};
/*
波神用的还是双指针的技术，推断新的头节点前一个节点和原尾节点之间的距离
ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL)
            return NULL;

        int len = get_len(head);
        k = k % len;

        ListNode* end = head;
        for(int i = 0 ; i < k ; i ++)
            end = end->next;

        ListNode* start = head;
        while(end->next != NULL){
            start = start->next;
            end = end->next;
        }

        end->next = head;
        head = start->next;
        start->next = NULL;

        return head;
    }
*/
// @lc code=end

