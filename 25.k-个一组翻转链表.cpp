/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
class Solution {
    // 我的想法是定位这个子list的头之前的节点pre，和之后的节点next
    //用一个栈来记录要翻转的k个位置的地址，然后逐个连接，最后将这个新的list连接回原来的list
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // ListNode* dummy_head = new ListNode(-1);
        // dummy_head->next = head;
        // ListNode *pre_node = dummy_head;
        // ListNode *next_node = pre_node->next;
        // ListNode *c_list_head = head;
        // ListNode *c_list_tail = NULL;
        // int i = k;
        // stack<ListNode *> s;
        // while (next_node && i)
        // {
        //     s.push(next_node);
        //     if(i==1)
        //         c_list_tail = next_node;
        //     next_node = next_node->next;
        //     i--;
        // }
        // if(i){
        //     delete dummy_head;
        //     return head;
        // }
        // while (c_list_tail){
        //     ListNode *cur = s.top();
        //     s.pop();
        //     while(!s.empty()){
        //         cur->next =s.top();
        //         s.pop();
        //         cur=cur->next;
        //     }
        //     pre_node->next = c_list_tail;
        //     c_list_head->next = next_node;
        //     pre_node = c_list_head;
        //     c_list_head = pre_node->next;
        //     next_node = pre_node->next;
        //     int i = k;
        //     while (next_node && i)
        //     {
        //         s.push(next_node);
        //         if(i==1)
        //             c_list_tail = next_node;
        //         next_node = next_node->next;
        //         i--;   
        //     }
        //     if(i)
        //         break;
        // }
        // ListNode *ret_node = dummy_head->next;
        // delete dummy_head;
        // return ret_node;
    //第一次求nextnode其实没有必要可以参考波神的循环条件优化
        ListNode* dummy_head = new ListNode(-1);
        dummy_head->next = head;
        ListNode *pre_node = dummy_head;
        ListNode *c_list_tail = NULL;
        int i = k;
        stack<ListNode *> s;
        while (pre_node&&pre_node->next){
            ListNode *next_node = pre_node->next;
            ListNode *c_list_head = pre_node->next;
            int i = k;
            while (next_node && i)
            {
                s.push(next_node);
                if(i==1)
                    c_list_tail = next_node;
                next_node = next_node->next;
                i--;   
            }
            if(i)
                break;
            
            ListNode *cur = s.top();
            s.pop();
            while(!s.empty()){
                cur->next =s.top();
                s.pop();
                cur=cur->next;
            }
            pre_node->next = c_list_tail;
            c_list_head->next = next_node;
            pre_node = c_list_head;
        }
        ListNode *ret_node = dummy_head->next;
        delete dummy_head;
        return ret_node;
    }
    /*波神思路基本一致，他主要用了reverse这个递归的函数来将子list翻转
    public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode* pre = dummyHead;
        while(pre && pre->next){

            ListNode* end = pre;
            int i;
            for(i = 0; i < k && end->next; i ++)
                end = end->next;

            if(i != k) break;

            ListNode* next = end->next;

            // reverse from pre->next to end
            ListNode* rhead = reverse(pre->next, end);

            ListNode* tail = pre->next;
            pre->next = rhead;
            tail->next = next;
            pre = tail;
        }

        ListNode* ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }

private:
    ListNode* reverse(ListNode* head, ListNode* end){

        if(head == end) return head;

        ListNode* rhead = reverse(head->next, end);
        head->next->next = head;
        return rhead;
    }
};
    */
};
// @lc code=end

