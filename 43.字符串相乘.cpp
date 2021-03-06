/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
#include<iostream>
using namespace std;
class Solution {
public:
// 这道题目就是考察大数相乘
    string multiply(string num1, string num2) {
        if(num1[0]=='0'||num2[0]=='0')
            return 0;
        int advancement = 0;
        string res;
        while(num1.size()||num2.size()){
            if(!num1.size())
                res = num2+res;
            if(!num2.size())
                res = num1+res;
            
        }
    }
};
// @lc code=end

