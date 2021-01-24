/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
*/
// #include<iostream>
// using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    int getLen(ListNode* head){
        int n=0;
        while(head){
            n++;
            head = head->next;
        }
        return n;
    }
// 我能想到的蠢办法就是每次从头节点开始找应该相连的节点的前一个节点
    // 时间复杂度是o（n^2）空间复杂度是o（1）
    // void reorderList(ListNode* head) {
    //     int list_len =getLen(head);
    //     if(list_len<=2)
    //         return;
    //     ListNode * cur = head;
    //     ListNode * next_before = cur;
    //     int distance = list_len -2;
    //     while(distance>0){
    //         for(int i=distance;i>0;i--)
    //             next_before = next_before->next;
    //         ListNode* cur_next = cur->next;
    //         cur->next = next_before->next;
    //         next_before->next = NULL;
    //         cur->next->next = cur_next;
    //         cur = cur_next;
    //         next_before = cur;
    //         distance-=2;
    //     }
    // }
    /*
    方法一：线性表，时间和空间复杂度都是o（n）
    void reorderList(ListNode *head) {
        if (head == nullptr) {
            return;
        }
        vector<ListNode *> vec;
        ListNode *node = head;
        while (node != nullptr) {
            vec.emplace_back(node);
            node = node->next;
        }
        int i = 0, j = vec.size() - 1;
        while (i < j) {
            vec[i]->next = vec[j];
            i++;
            if (i == j) {
                break;
            }
            vec[j]->next = vec[i];
            j--;
        }
        vec[i]->next = nullptr;
    }
    方法二：目标链表即为将原链表的左半端和反转后的右半端合并后的结果
        所以分为三步来进行：
        1找到链表的中点
        2将链表的右半部分反转
        3合并两个链表
    */
    ListNode * reverseList(ListNode * head){
        //反转链表，三个指针
        if(!head||!head->next)
            return head;
        ListNode* before = NULL;
        ListNode* cur = head;
        ListNode* after = NULL;
        while(cur){
            after = cur->next;
            cur->next = before;
            before = cur;
            cur = after;
        }
        return before;
    }
    void reorderList(ListNode *head) {
        //寻找链表中点，快慢指针
        if(!head||!head->next)
            return;
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast->next&&fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = reverseList(slow->next);
        slow->next = NULL;
        ListNode* head1 = head;
        // 合并链表
        while(head1&&head2){
            ListNode* h1_next = head1->next;
            ListNode* h2_next = head2->next;
            head1->next = head2;
            head2->next = h1_next;
            head1 = h1_next;
            head2 = h2_next;
        }
    }
};
// @lc code=end

