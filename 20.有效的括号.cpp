/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for(auto c:s){
            if(c=='('||c=='{'||c=='[')
                ss.push(c);
            else{
                if(ss.empty())
                    return false;
                if(c=='}'&& ss.top()!='{')
                    return false;
                else if(c==')'&& ss.top()!='(')
                    return false;
                else if(c==']'&& ss.top()!='[')
                    return false;
                ss.pop();
            }
        }
        if(!ss.empty())
            return false;
        return true;
    }
};
// @lc code=end

