/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 从左下角或者右上角开始搜索时间复杂度n+m
        int row = matrix.size();
        int col = matrix[0].size();
        int i = row-1;
        int j = 0;
        while(i>=0&&j<col){
            if(matrix[i][j]>target)
                i--;
            else if(matrix[i][j]<target)
                j++;
            else 
                return true;
        }
        return false;
    }
    //逐行二分也可以时间复杂度 nlogm
};
// @lc code=end

