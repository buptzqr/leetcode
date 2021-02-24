/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
// 又是一道dp的题目
// dp[i][j]表示由字符串s[i...j]是否是回文串
// 状态转移方程：s[i]==s[j]&&(j-i<2||dp[i+1][j-1])
    // int countSubstrings(string s) {
    //     int sz = s.size();
    //     vector<vector<bool>> dp(sz,vector<bool>(sz,false));
    //     int res =0;
    //     for(int j=0;j<sz;j++)
    //         for(int i=0;i<=j; i++)
    //             if(s[i]==s[j]&&(j-i<2||dp[i+1][j-1])){
    //                 dp[i][j]=true;
    //                 res++;
    //             }
    //     return res;
    // }
// 中心扩展法
// 找到字符串的中心，然后扩展，需要注意的是中心点可以是单个字符，也可以是两个字符
// 比如caac就应该是由中心点aa扩展而来的
// 所以字符串一共有2*len-1个中心点
    int countSubstrings(string s) {
        int res = 0;
        for(int center = 0;center<2*s.size()-1;center++){
            int l = center/2;
            int r = l+center%2;
            while(l>=0&&r<s.size()&&s[l]==s[r]){
                res++;
                l--;
                r++;
            }
        }
        return res;
    }

};
// @lc code=end

