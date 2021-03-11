/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        //dp[i][j]表示从word1的前i个字符转变word2的前j个字符所需的
        // 最小操作数
        // 常规操作
        // dp[i][j] = dp[i-1][j-1]改
        // dp[i][j] = dp[i-1][j]删
        // dp[i][j] = dp[i][j-1]增
        // 若word1[i]==word2[j]
        // dp[i][j] = dp[i-1][j-1]
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,INT_MAX));
        for(int i = 0;i<=word2.size();i++)
            dp[0][i] = i;
        for(int j =0;j<=word1.size();j++)
            dp[j][0] = j;
        for(int i=1;i<=word1.size();i++){
            for(int j = 1;j<=word2.size();j++){
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                if(word1[i-1]==word2[j-1])
                    dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
            }
        }
        return dp.back().back();
    }
};
// int main(){
//     Solution().minDistance("b","");
//     return 0;
// }
// @lc code=end

