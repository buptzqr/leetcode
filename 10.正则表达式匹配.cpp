/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        //又是dp 首先状态方程dp[i][j]表示s的前i个字符和p的前j个字符是否匹配
        // 如果p的当前字符是字母或者. s[i]==p[j]则dp[i][j]=dp[i-1][j-1] 否则 dp[i][j]=false
        // 如果p的当前字符是* 
        // - 如果s[i]!=p[j-1] dp[i][j] = dp[i][j-2] 
        // - 如果s[i]==p[j-1] dp[i][j] = dp[i-1][j]||dp[i][j-2]||dp[i][j-1]
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;
        for(int j=1;j<=n;j++)
            if(p[j-1]=='*'&&dp[0][j-2])
                dp[0][j]=true;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                if(p[j-1]!='*')
                    if(p[j-1]=='.'||s[i-1]==p[j-1])
                        dp[i][j] = dp[i-1][j-1];
                    else
                        dp[i][j] = false;
                else
                    if(p[j-2]=='.'||s[i-1]==p[j-2])
                        dp[i][j] = (dp[i-1][j]||dp[i][j-2]||dp[i][j-1]);
                    else
                        dp[i][j] = dp[i][j-2];
                
            }
        return dp[m][n];
    }
};
// int main(){
//     string s1 = "aab";
//     string s2 = "c*a*b";
//     Solution().isMatch(s1,s2);
// }
// @lc code=end


