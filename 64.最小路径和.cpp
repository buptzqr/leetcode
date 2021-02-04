/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
class Solution {
public:
    // 从每个节点最短路径等于他的值加上右边或者下边节点的最短路径中较小的一个
    // vector<vector<int>> memo;
    // int r;
    // int c;
    // int findMinPath(vector<vector<int>>& grid,int row,int col){
    //     if(row>=r||col>=c)
    //         return INT_MAX;
    //     if(memo[row][col]!=-1)
    //         return memo[row][col];
    //     int min_path = min(findMinPath(grid,row+1,col),findMinPath(grid,row,col+1));
    //     memo[row][col] = grid[row][col]+(min_path<INT_MAX?min_path:0);
    //     return memo[row][col];
    // }
    // int minPathSum(vector<vector<int>>& grid) {
    //     memo=vector<vector<int>>(grid.size(),vector<int>(grid[0].size(),-1));
    //     this->r = grid.size();
    //     this->c = grid[0].size();
    //     return findMinPath(grid,0,0);
    // }
    // dp
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>memo(grid.size(),vector<int>(grid[0].size(),-1));
        int r = grid.size();
        int c = grid[0].size();
        for(int row = r-1;row>= 0; row--){
            for(int col = c-1;col>=0;col--){
                if(row == r-1&&col==c-1){
                    memo[row][col]=grid[row][col];
                    continue;
                }            
                int right = (col+1<c?memo[row][col+1]:INT_MAX);
                int down = (row+1<r?memo[row+1][col]:INT_MAX);
                memo[row][col] = grid[row][col] + min(right,down);
            }
        }
        return memo[0][0];
    }

};
// @lc code=end

