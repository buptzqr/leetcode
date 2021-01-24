/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
// 记忆化搜索
    // vector<vector<int>> memo;
    // int row;
    // int col;
    // int dfs(vector<vector<int>>& obstacleGrid,int r,int c){
    //     if(r==row-1&&c==col-1)
    //         return 1;
    //     if(memo[r][c]!=-1)
    //         return memo[r][c];
    //     int res =0;
    //     if(r<row-1&&!obstacleGrid[r+1][c])
    //         res+=dfs(obstacleGrid,r+1,c);        
    //     if(c<col-1&&!obstacleGrid[r][c+1])
    //         res+=dfs(obstacleGrid,r,c+1);
    //     memo[r][c]=res;
    //     return res;        
    // }
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     if(obstacleGrid[0][0])
    //         return 0;
    //     row = obstacleGrid.size();
    //     col = obstacleGrid[0].size();
    //     if(obstacleGrid[row-1][col-1])
    //         return 0;
    //     memo = vector<vector<int>>(row,vector<int>(col,-1));
    //     return dfs(obstacleGrid,0,0);
    // }
    // 动态规划
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0])
            return 0;
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        if(obstacleGrid[row-1][col-1])
            return 0;
        vector<vector<long>>memo(row,vector<long>(col,0));
        memo[row-1][col-1]=1;
        for(int i=row-1;i>= 0; i--){
            for(int j=col-1;j>= 0; j--){
                if(obstacleGrid[i][j])
                    continue;
                if(i+1<row&&!obstacleGrid[i+1][j])
                    memo[i][j]+=memo[i+1][j];
                if(j+1<col&&!obstacleGrid[i][j+1])
                    memo[i][j]+=memo[i][j+1];    
            }
        }
        return memo[0][0];
    }
};
// @lc code=end

