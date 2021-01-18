/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start

// * Definition for singly-linked list.
// #include <iostream>
// using namespace std;
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        // 先找到需要反转的位置的头，和尾，然后进行反转就可以了
        // 关键就是特殊情况，m=n的情况，以及从头开始反转的情况
        if (m == n)
            return head;
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *begin = NULL;    //指向需要反转的前一个元素
        ListNode *end = NULL;      //指向需要反转的后一个元素
        ListNode *cur = dummyHead; //指向当前需要反转的元素
        ListNode *before = NULL;   //指向当前需要反转的前一个元素
        int index = 0;
        while (index <= n + 1)
        {
            if (index == m - 1)
                begin = cur;
            if (index == n + 1)
                end = cur;
            index++;
            // 还是要注意这里的边界条件
            if (cur)
                cur = cur->next;
        }
        cur = begin->next;
        while (cur != end)
        {
            ListNode *after = cur->next;
            cur->next = before;
            before = cur;
            cur = after;
        }
        begin->next->next = end;
        begin->next = before;
        return dummyHead->next;
    }
};
/*我的版本1
 ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        // 先找到需要反转的位置的头，和尾，然后进行反转就可以了
        // 关键就是特殊情况，m=n的情况，以及从头开始反转的情况
        if (m == n)
            return head;
        ListNode *begin = NULL;
        ListNode *before = NULL;
        ListNode *cur = NULL;
        ListNode *end = NULL;
        int index = 1;
        ListNode *ptr = head;
        while (ptr)
        {
            if (index == m - 1)
                begin = ptr;
            if (index == n + 1)
                end = ptr;
            ptr = ptr->next;
            index++;
        }
        if (!begin)
            cur = head;
        else
            cur = begin->next;
        while (cur != end)
        {
            ListNode *after = cur->next;
            cur->next = before;
            before = cur;
            cur = after;
        }
        if (!begin)
        {
            head->next = cur;
            return before;
        }
        begin->next->next = end;
        begin->next = before;
        return head;
    }
*/
/*大神的操作，主要是加了dummy头，我写的逻辑的主要问题还是没有能够处理好从头开始翻转这种情况
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {

        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode* pre = dummyHead;
        for(int i = 0; i < m - 1; i ++, pre = pre->next);

        ListNode* tail = pre->next;
        ListNode* left;
        pre->next = reverse(pre->next, n - m, left);
        tail->next = left;

        ListNode* ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }

private:
    ListNode* reverse(ListNode* head, int index, ListNode* &left){

        if(index == 0){
            left = head->next;
            return head;
        }

        ListNode* tail = head->next;
        ListNode* ret = reverse(head->next, index - 1, left);
        tail->next = head;
        return ret;
    }
}
*/
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
// @lc code=end
// int main()
// {
//     int arr[2] = {3, 5};
//     ListNode *head = build_list(arr, 2);
//     head = Solution().reverseBetween(head, 1, 2);
// }