/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top = 0;
        int bottom = n-1;
        int left = 0; 
        int right  = n-1;
        int i = 0;
        int j = 0;
        //从左到右0，从上到下1，从右到左2，从下到上3
        int orentation = 0;
        int val = 1;
        vector<vector<int>> res(n,vector<int>(n,0));
        while(j>=left&&j<=right&&i>=top&&i<=bottom){
            if(orentation==0){
                top++;
                while(j<=right){
                    res[i][j] = val;
                    j++;
                    val++;
                }
                i++;
                j--;
            }
            else if(orentation == 1){
                right --;
                while(i<=bottom){
                    res[i][j] = val;
                    i++;
                    val ++;
                }
                i--;
                j--;
            }
            else if(orentation == 2){
                bottom--;
                while(j>=left){
                    res[i][j] = val;
                    j--;
                    val ++;                    
                }
                j++;
                i--;
            }
            else{
                left++;
                while(i>=top){
                    res[i][j] = val;
                    i--;
                    val++;
                }
                i++;
                j++;
            }
            orentation = (orentation+1)%4;
        }
        return res;
    }
};
// int main(){
//     Solution().generateMatrix(3);
// }
// @lc code=end

