/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
private:
    vector<vector<bool>> visited;
    int r;
    int c;
    int go[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    bool inArea(int row, int col)
    {
        return row >= 0 && col >= 0 && row < r && col < c;
    }
    void findIslands(int row, int col, vector<vector<char>> &grid)
    {
        if (inArea(row, col) && !visited[row][col] && grid[row][col] == '1')
        {
            visited[row][col] = true;
            for (int i = 0; i < 4; i++)
            {
                int n_row = row + go[i][0];
                int n_col = col + go[i][1];
                findIslands(n_row, n_col, grid);
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        r = grid.size();
        c = grid[0].size();
        int island_num = 0;
        visited = vector<vector<bool>>(r, vector<bool>(c, false));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    island_num++;
                    findIslands(i, j, grid);
                }
            }
        }
        return island_num;
    }
};
// int main(){
//     vector<vector<char>> input = vector<vector<char>>(2, vector<char>(2, '1'));
//     Solution().numIslands(input);
// }
// @lc code=end

