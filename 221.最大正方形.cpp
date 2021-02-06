/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int min3(int a,int b,int c){
        return min(a,min(b,c));
    }
// dp(i,j) 表示以 (i, j)(i,j) 为右下角，且只包含 1 的正方形的边长最大值。
// 状态转移方程为dp(i,j)=min(dp(i−1,j),dp(i−1,j−1),dp(i,j−1))+1
// 可以这样考虑，想让(i,j)位置构成的正方形取值最大，就必须让其左边，上边和
// 左上不受限制，所以(i,j)位置正方形的取值受限于这三个位置的dp的最小值
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i =0 ;i<matrix.size();i++)
            if(matrix[i][0]=='1')
                dp[i][0]=1;
        for(int i =0 ;i<matrix[0].size();i++)
            if(matrix[0][i]=='1')
                dp[0][i]=1;
        for(int i = 1;i<matrix.size();i++){
            for(int j = 1;j<matrix[0].size();j++){
                if(matrix[i][j]=='0')
                    dp[i][j]=0;
                else
                    dp[i][j] = min3(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
            }
        }
        int res =0;
        for(int i = 0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
                res = max(res,dp[i][j]);
        return res*res;
    }
};
// @lc code=end

