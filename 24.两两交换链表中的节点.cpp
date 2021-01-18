/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
// #include<iostream>
// using namespace std;
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        //可以借鉴归并的思路了，把链表分成两部分，然后归并
        if (!head||!head->next)
            return head;
        ListNode *dummy_head = new ListNode(-1);
        dummy_head->next = head;
        ListNode *h1 = dummy_head;
        ListNode *h2 = head;
        while (h1->next && h2->next)
        {
            ListNode *h1_next = h1->next;
            ListNode *h2_next = h2->next;
            h1->next = h1_next->next;
            h2->next = h2_next->next;
            h1 = h1->next;
            h2 = h2->next;
        }
        if(h1)
            h1->next = NULL;
        if(h2)
            h2->next = NULL;
        h1 = dummy_head->next;
        h2 = head;
        while(h1){
            ListNode *h1_next = h1->next;
            ListNode *h2_next = h2->next;
            h1->next = h2;
            h1 = h1_next;
            if(h1_next)
                h2->next = h1_next;
            h2 = h2_next;
        }
        ListNode* ret_node = dummy_head->next;
        delete dummy_head;
        return ret_node;
    }
    /*想复杂了，波神思路就是要交换的一对节点，以及一对节点的前一个，和一对节点的后一个
    然后来考虑这个问题，就是先交换节点，然后将前一个节点指向交换节点后的第一个节点，交换节点后的第二个节点指向
    该对节点后的节点，保证链表相连 
    ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* p = dummyHead;
        while(p->next && p->next->next){
            ListNode* node1 = p->next;
            ListNode* node2 = node1->next;
            ListNode* next = node2->next;
            node2->next = node1;
            node1->next = next;
            p->next = node2;
            p = node1;
        }

        ListNode* retHead = dummyHead->next;
        delete dummyHead;

        return retHead;*/
};
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
//     int arr[] = {1, 2,3,4};
//     ListNode *head = build_list(arr, sizeof(arr) / sizeof(arr[0]));
//     head = Solution().swapPairs(head);
//     cout << "hello" << endl;
// }
// @lc code=end
