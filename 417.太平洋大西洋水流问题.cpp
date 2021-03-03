/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
//从四个边界逆流搜索，分别记录可以到达太平洋和印度洋的节点，然后求交集,从边界节点出发，该节点的周围只要是元素>=该节点的，那么就可以洪泛到
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
private:
    vector<vector<bool>> pacific_arr;
    vector<vector<bool>> atlantic_arr;
    int r;
    int c;
    int go[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    bool inArea(int row, int col)
    {
        return row >= 0 && col >= 0 && row < r && col < c;
    }
    void flood(int row, int col, vector<vector<bool>> &arrived, vector<vector<int>> &matrix)
    {
        for (int i = 0; i < 4; i++)
        {
            int n_row = row + go[i][0];
            int n_col = col + go[i][1];
            if (inArea(n_row, n_col) && !arrived[n_row][n_col] && matrix[row][col] <= matrix[n_row][n_col]){
                arrived[n_row][n_col] = true;
                flood(n_row, n_col, arrived, matrix);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
    {
        r = matrix.size();
        if (!r)
            return matrix;
        c = matrix[0].size();
        vector<vector<int>> res;
        pacific_arr = vector<vector<bool>>(r, vector<bool>(c, false));
        atlantic_arr = vector<vector<bool>>(r, vector<bool>(c, false));
        for (int i = 0; i < r; i++)
        {
            pacific_arr[i][0] = true;
            atlantic_arr[i][c - 1] = true;
        }
        for (int i = 0; i < c; i++)
        {
            pacific_arr[0][i] = true;
            atlantic_arr[r - 1][i] = true;
        }
        for (int i = 0; i < r; i++)
        {
            flood(i, 0, pacific_arr, matrix);
            flood(i, c - 1, atlantic_arr, matrix);
        }
        for (int i = 0; i < c; i++)
        {
            flood(0, i, pacific_arr, matrix);
            flood(r - 1, i, atlantic_arr, matrix);
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (pacific_arr[i][j] && atlantic_arr[i][j])
                {
                    vector<int> tmp;
                    tmp.push_back(i);
                    tmp.push_back(j);
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};
// int main(){
//     int a[5][5] = { { 1, 2, 2, 3, 5 }, { 3, 2, 3, 4, 4 }, { 2, 4, 5, 3, 1 }, { 6, 7, 1, 4, 5 }, { 5, 1, 1, 2, 4 } };
//     vector<vector<int>> input;
//     for (int i = 0; i < 5;i++)
//         input.push_back(vector<int>(a[i],a[i]+sizeof(a[i])/sizeof(int)));
//     vector<vector<int>> res=Solution().pacificAtlantic(input);
//     cout << "hello" << endl;
// }
// @lc code=end

