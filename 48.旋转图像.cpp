/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
//以左上右下对角线做一次翻转，然后对每行元素进行左右翻转
    void rotate(vector<vector<int>>& matrix) {
        int sz = matrix.size();
        for(int i=0;i<sz;i++)
            for(int j=i;j<sz;j++)
                swap(matrix[i][j],matrix[j][i]);
        for(int i = 0;i<sz;i++)
            for(int j=0;j<sz/2;j++)
                swap(matrix[i][j],matrix[i][sz-j-1]);
    }
};
// @lc code=end

