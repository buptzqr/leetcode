/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
// #include <vector>
// using namespace std;
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
class Solution {
public:
//同样是自底向上的归并排序，因为不是数组，所以merge后要更新list
    ListNode * Merge(ListNode *l,ListNode *r){
        ListNode * dummy_head = new ListNode(-1);
        ListNode * cur = dummy_head;
        while(l&&r){
            if(l->val>r->val){
                cur->next = r;
                r= r->next;
                cur=cur->next;
            }
            else{
                cur->next = l;
                l= l->next;
                cur=cur->next;
            }
        }
        if(l)
            cur->next = l;
        if(r)
            cur->next = r;
        ListNode * ret =dummy_head->next;
        delete dummy_head;
        return ret;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size())
            return NULL;
        while(lists.size()>1){
            int l =0;
            vector<ListNode*> tmp;
            while(l<lists.size()){
                int r = l+1;
                if(r>=lists.size()){
                    tmp.push_back(lists[l]);
                    break;
                }
                else{
                    tmp.push_back(Merge(lists[l],lists[r]));
                    l+=2;
                }
            }
            lists = tmp;
        }
        return lists[0];
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
//     int arr1[] = {1, 4, 5};
//     int arr2[] = {1, 3, 4};
//     int arr3[] = {2,6};
//     ListNode *head1 = build_list(arr1, sizeof(arr1) / sizeof(arr1[0]));
//     ListNode *head2 = build_list(arr2, sizeof(arr2) / sizeof(arr2[0]));
//     ListNode *head3 = build_list(arr3, sizeof(arr3) / sizeof(arr3[0]));
//     vector<ListNode*> vec;
//     vec.push_back(head1);
//     vec.push_back(head2);
//     vec.push_back(head3);
//     ListNode* head = Solution().mergeKLists(vec);
//     cout << "hello" << endl;
// }