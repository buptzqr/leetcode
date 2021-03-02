/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // 以每一行为底，测量1的高度，问题就转化成84号问题了
        if(matrix.size()==0||matrix[0].size()==0)
            return 0;
        int res = 0;
        vector<int> heights(matrix[0].size()+2);
        for(auto e:matrix){
            for(int i = 0; i <e.size();i++)
                if(e[i]=='1')
                    heights[i+1]++;
                else
                    heights[i+1]=0;
            vector<int> s;
            for(int i=0; i<heights.size();i++){
                while(!s.empty()&&heights[s.back()]>heights[i]){
                    int h=heights[s.back()];
                    s.pop_back();
                    int left = s.back()+1;
                    int right = i-1;
                    res = max(res,(right-left+1)*h);
                }
                s.push_back(i);
            }
        }
        return res;
    }
};
// int main(){
//     vector<vector<char>> matrix = {{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
//     Solution().maximalRectangle(matrix);
// }
// @lc code=end

