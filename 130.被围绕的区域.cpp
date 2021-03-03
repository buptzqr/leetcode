/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
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
    public:
        //都提示了，只要flood一下与边界上的o相连的o就可以了
        void flood(vector<vector<char>> &board,int row,int col){
            //一定要先把inArea放前面保证row和col没有越界
            if(inArea(row,col)&&board[row][col]=='O'&&!visited[row][col]){
                visited[row][col] = true;
                for (int i = 0; i < 4;i++){
                    int n_row = row + go[i][0];
                    int n_col = col + go[i][1];
                    flood(board, n_row, n_col);
                }
            }
        }
        void solve(vector<vector<char>> &board)
        {
            r = board.size();
            if(!r)
                return;
            c = board[0].size();
            visited = vector<vector<bool>>(r, vector<bool>(c, false));
            for (int i = 0; i < r;i++){
                if(board[i][0]=='O'&&!visited[i][0]){
                    flood(board, i, 0);
                }
                if(board[i][c-1]=='O'&&!visited[i][c-1]){
                    flood(board, i, c-1);
                }
                
            }
            for (int i = 0; i < c;i++){
                if(board[0][i]=='O'&&!visited[0][i]){
                    flood(board, 0, i);
                }
                if(board[r-1][i]=='O'&&!visited[r-1][i]){
                    flood(board, r-1, i);
                }
            }
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (!visited[i][j])
                        board[i][j] = 'X';
                }
            }
        }
};
// int main(){
//     char b1[4][4] = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
//     vector<vector<char>> board1;
//     for( int i = 0 ; i < 4 ; i ++ )
//         board1.push_back(vector<char>(b1[i], b1[i] + sizeof(b1[i]) / sizeof(char)));
//     Solution().solve(board1);
//     cout << "ok" << endl;
// }
// @lc code=end

