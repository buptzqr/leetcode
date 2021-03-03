/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
//经典问题，弄清楚\对角线和/对角线的元素的坐标特点
// 对角线/的元素的特点是每条对角线横纵坐标相加为固定值，对角线\的特点是每条对角线横纵坐标相减为固定值值
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //分别记录行列对角线12的占用情况
    vector<bool> col_rec;
    vector<bool> diag1_rec;
    vector<bool> diag2_rec;
    int go[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int n;
    bool inArea(int row, int col)
    {
        return row >= 0 && col >= 0 && row < n && col < n;
    }
    //放置第row行皇后是否成功
    void putQueen(int row,vector<int>& col_pos,vector<vector<string>>& res){
        if(row == n){
            res.push_back(pos2str(col_pos));
            return;
        }
        for (int i = 0; i < n;i++){
            if(!col_rec[i]&&!diag1_rec[row+i]&&!diag2_rec[row-i+n-1]){
                col_pos.push_back(i);
                col_rec[i] = true;
                diag1_rec[row + i] = true;
                diag2_rec[row - i + n - 1] = true;
                putQueen(row+1,col_pos,res);
                col_pos.pop_back();
                col_rec[i] = false;
                diag1_rec[row + i] = false;
                diag2_rec[row - i + n - 1] = false;
            }
        }
    }
    vector<string> pos2str(vector<int>& col_pos){
        vector<string> res;
        for (auto e:col_pos){
            string s(n,'.');
            s[e] = 'Q';
            res.push_back(s);
        }
        return res;
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        vector<int> col_pos;
        if(n==1){
            res.push_back(vector<string>(1,"Q"));
            return res;
        }
            
        this->n = n;
        col_rec = vector<bool>(n, false);
        diag1_rec = vector<bool>(2*n-1, false);
        diag2_rec = vector<bool>(2*n-1, false);
        putQueen(0,col_pos,res);
        return res;
    }
};
// int main(){
//     vector<vector<string>>res=Solution().solveNQueens(4);
//     cout<<"hello"<<endl;
//     return 0;
// }
// @lc code=end

