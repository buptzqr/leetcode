/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
// #include<iostream>
// #include<vector>
// using namespace std;
// class Solution
// {
// private:
//     vector<vector<bool>> visited;//记录元素是否被访问
//     int go[4][2] {{0,1},{1,0},{0,-1},{-1,0}};
//     int r;
//     int c;
//     //从row，和col开始寻找cur_str加上board中的元素是否可以构成word
//     bool search(int row, int col, vector<vector<char>> &board, vector<vector<bool>>&visited,string &cur_str, string word)
//     {
//         if(cur_str.size()==word.size()-1){
//             if(board[row][col]==word[cur_str.size()])
//                 return true;
//             else
//                 return false;
//         }

//         if(board[row][col]==word[cur_str.size()]){
//             cur_str.push_back(board[row][col]);
//             visited[row][col] = true;
//             for (int i = 0; i < 4;i++)
//             {
//                 int n_row = row + go[i][0];
//                 int n_col = col + go[i][1];
//                 if(0<=n_row&&n_row<r&&0<=n_col&&n_col<c&&!visited[n_row][n_col])
//                     if(search(n_row, n_col, board,visited, cur_str, word))
//                         return true;
//             }
//             cur_str.pop_back();
//             visited[row][col] = false;
//         }
//         return false;
//     }

//     public : 
//     bool exist(vector<vector<char>> &board, string word)
//     {
//         r = board.size();
//         c = board[0].size();
//         for (int i = 0; i < r;i++){
//             for (int j = 0; j < c;j++){
//                 vector<vector<bool>>visited(r, vector<bool>(c, false));
//                 string cur_str;
//                 if (search(i, j, board, visited, cur_str, word))
//                     return true;
//             }
//         }
//         return false;
//     }
// };
class Solution {

private:
    int d[4][2] = {{-1, 0}, {0,1}, {1, 0}, {0, -1}};
    int m, n;
    vector<vector<bool>> visited;

    bool inArea( int x , int y ){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    // start from board[startx][starty], find word[index...word.size())
    bool searchWord( const vector<vector<char>> &board, const string& word, int index,
                    int startx, int starty ){

        //assert( inArea(startx,starty) );
        if( index == word.size() - 1 )
            return board[startx][starty] == word[index];

        if( board[startx][starty] == word[index] ){
            visited[startx][starty] = true;
            for( int i = 0 ; i < 4 ; i ++ ){
                int newx = startx + d[i][0];
                int newy = starty + d[i][1];
                // 这个地方不用visited=true
                if( inArea(newx, newy) && !visited[newx][newy] &&
                    searchWord(board, word, index + 1, newx, newy))
                    return true;
            }
            visited[startx][starty] = false;
        }
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        m = board.size();
        assert( m > 0 );
        n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for( int i = 0 ; i < board.size() ; i ++ )
            for( int j = 0 ; j < board[i].size() ; j ++ )
                if( searchWord( board, word, 0 , i, j) )
                    return true;

        return false;
    }
};
// int main(){
//     char a[3][4] = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'E', 'S'}, {'A', 'D', 'E', 'E'}};
//     vector<vector<char>> input;
//     for (int i = 0; i < 3; i++)
//         input.push_back(vector<char>(a[i], a[i] + 4));
//     Solution().exist(input, "ABCEFSADEESE");
// }
// @lc code=end

