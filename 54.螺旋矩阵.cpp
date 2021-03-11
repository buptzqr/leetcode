/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //右变下，下变左，左变上，上变右
        //右0，下1，左2，上3
        int direction = 0;
        int top = 0;
        int bottom = matrix.size()-1;
        int left = 0;
        int right = matrix[0].size()-1;
        int x = 0,y = 0;
        vector<int> res;
        while(y>=left&&y<=right&&x<=bottom&&x>=top){
            if(direction == 0){
                top++;
                while(y<=right){
                    res.push_back(matrix[x][y]);
                    y++;
                }
                
                y=right;
                x++;
                direction = (direction + 1)%4;
            }
            else if(direction ==1){
                right--;
                
                while(x<=bottom){
                    res.push_back(matrix[x][y]);
                    x++;
                }
                
                x=bottom;
                y--;
                direction = (direction + 1)%4;
            }
            else if(direction == 2){
                bottom--;
                while(y>=left){
                    res.push_back(matrix[x][y]);
                    y--;
                }
                
                y=left;
                x--;
                direction = (direction + 1)%4;
            }
            else{
                left++;
                while(x>=top){
                    res.push_back(matrix[x][y]);
                    x--;
                }
                
                x=top;
                y++;
                direction = (direction + 1)%4;
            }
        }
        return res;
    }
};
// int main(){
//     vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
//     Solution().spiralOrder(matrix);
//     return 0;
// }
// @lc code=end

