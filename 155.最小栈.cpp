/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
#include<iostream>
#include<stack>
#include<limits.h>
using namespace std;
// 用一个辅助栈来保存栈中最小的元素
class MinStack {
private:
    stack<int> min_stack;
    stack<int> help_stack;
public:
    /** initialize your data structure here. */
    
    MinStack() {
        help_stack.push(INT_MAX);
    }
    
    void push(int x) {
        min_stack.push(x);
        help_stack.push(min(help_stack.top(),x));
    }
    
    void pop() {
        min_stack.pop();
        help_stack.pop();
    }
    
    int top() {
        return min_stack.top();
    }
    
    int getMin() {
        return help_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

