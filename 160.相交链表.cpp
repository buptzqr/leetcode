/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.*/
#include<iostream>
#include<stack>
using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     stack<ListNode*> sa;
    //     stack<ListNode*> sb;
    //     // 哈希表肯定可以
    //     // 两个链表都入栈，然后往出抛
    //     while(headA){
    //         sa.push(headA);
    //         headA = headA->next;
    //     }
    //     while(headB){
    //         sb.push(headB);
    //         headB = headB->next;
    //     }
    //     ListNode* res = NULL;
    //     while(!sa.empty()&&!sb.empty()&&sa.top()==sb.top()){
    //         res = sa.top();
    //         sa.pop();
    //         sb.pop();
    //     }
    //     return res;
    // }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 双指针法，将pa到达尾部后指向b链表，pb到达尾部后指向a链表
        // 两个指针指向相同位置时即为相交节点
        ListNode * pa=headA;        
        ListNode * pb=headB;
        while(pa!=pb){
            pa = pa?pa->next:headB;
            pb = pb?pb->next:headA;
        }        
        return pa;
    }

};
// @lc code=end

