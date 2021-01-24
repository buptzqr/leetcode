/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    // 记忆化搜索
// private:
//     vector<vector<int>> memo;//即从（i，j）到（m，n）有多少条路径
//     int row;
//     int col;
// public:
//     int dfs(int i,int j){
//         if(i==row-1&&j==col-1)
//             return 1;
//         if(memo[i][j]!=-1)
//             return memo[i][j];
//         int res=0;
//         if(i<row-1)
//             res+=dfs(i+1,j);
//         if(j<col-1)
//             res+=dfs(i,j+1);
//         memo[i][j]=res;
//         return res;
//     }
//     int uniquePaths(int m, int n) {
//         row = m; 
//         col = n;
//         memo = vector<vector<int>>(m,vector<int>(n,-1));
//         return dfs(0,0);
//     }
public:
// 动态规划 
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp=vector<vector<int>>(m,vector<int>(n,1));
        dp[m-1][n-1] = 1;
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                    dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }

};
// @lc code=end

