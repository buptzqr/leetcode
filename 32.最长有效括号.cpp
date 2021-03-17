/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        // 和301貌似有点相似，但是实际是不同的
        // dp
        // dp[i]表示以下标i字符结尾的最长有效括号的长度
        // if s[i] =='(' 则dp[i]=0
        // if s[i] ==')' && s[i-1] ==')' 如果s[i-dp[i-1]-1]=='('
        // 则dp[i] = dp[i-1]+ dp[i-dp[i-1]-2] +2 否则0
        // if s[i] ==')' && s[i-1] =='(' dp[i] = dp[i-2] + 2
        vector<int> dp(s.size(),0);
        int res = 0 ;
        for(int i = 1;i<s.size();i++){
            if(s[i] ==')' && s[i-1] ==')'&&i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='('){
                dp[i] = dp[i-1]+ (i-dp[i-1]-2>=0?dp[i-dp[i-1]-2]:0) +2;
                res = max(res,dp[i]);
            }
            else if(s[i] ==')' && s[i-1] =='('){
                dp[i] = (i-2>=0?dp[i-2]:0) + 2;
                res = max(res,dp[i]);
            }
            
        }
        return res;
    }
};
// @lc code=end

