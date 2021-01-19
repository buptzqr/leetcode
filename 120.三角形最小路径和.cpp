/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
#include<vector>
#include<iostream>
#include "limits.h"
using namespace std;
class Solution {
public:
    // int total_floor;
    // vector<vector<int>> memo;
    // //寻找第i层第idx节点的最短路径,floor代表层数，idx代表这层应该访问的起始下标
    // int findMininum(int floor,vector<vector<int>>& t,int idx){
    //     if(floor == total_floor||idx>=t[floor].size()){
    //         return 0;
    //     }
    //     if(memo[floor][idx]==INT_MIN)
    //         memo[floor][idx]=t[floor][idx] + min(findMininum(floor + 1, t, idx),findMininum(floor + 1, t, idx+1));
        
    //     return memo[floor][idx];
    // }
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     for (int i = 0;i<triangle.size();i++){
    //         memo.push_back(vector<int>(triangle[i].size(),INT_MIN));
    //     }
    //     total_floor = triangle.size();
    //     return findMininum(0, triangle, 0);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        //第i层的最短路径，为min(v[i][0]+min(memo[i+1][0],memo[i+1][1]),v[i][1]+min(memo[i+1][1],memo[i+1][2],....)
        vector<vector<int>> memo;
        for(auto e:triangle)
            memo.push_back(vector<int>(e.size(), INT_MAX));
        int last_floor = triangle.size() - 1;
        // 最后一层初始化
        for (int i = 0; i < triangle[last_floor].size();i++)
            memo[last_floor][i] = triangle[last_floor][i];
        for (int i = last_floor - 1; i >= 0; i--)
        {
            for (int j = 0; j < memo[i].size();j++){
                memo[i][j] = triangle[i][j] + min(memo[i + 1][j], memo[i + 1][j + 1]);
            }
        }
        return memo[0][0];
    }
    /*波神直接从上往下走
        int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        for(int i = 1 ; i < n ; i ++){

            triangle[i][0] += triangle[i-1][0];
            triangle[i][i] += triangle[i-1][i-1];
            for(int j = 1 ; j < i ; j ++)
                triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
        }

        return *min_element(triangle[n-1].begin(), triangle[n-1].end());
    }
};
    */
//    这种初始化记一下
//   vector<vector<int>> triangle = { {2},
//                                      {3, 4},
//                                      {6,5,7},
//                                      {4,1,8,3}};

};
// int main(){
//     vector<vector<int>> input;
//     int a[] = {2};
//     input.push_back(vector<int>(a,a+sizeof(a)/ sizeof(a[0])));
//     Solution().minimumTotal(input);
//     return 0;
// }
// @lc code=end

