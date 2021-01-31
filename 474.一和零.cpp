/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
// 这个问题完全就是背包问题的变形，每个元素有个weiht1，也有个weight2，每个元素的
// 价值都是1，所以优化可以直接参考背包问题了
// 记忆化搜索
//memo[idx][m][n]考虑前idx个元素，最多有m个0和n个1构成的最大子集的大小
    vector<vector<vector<int>>> memo; 
    int str0Num(string s){
        int ret = 0;
        for(auto e:s)
            if(e=='0')
                ret++;
        return ret;
    }
    // // 搜索考略[0,idx]的元素，最多有m个0和n个1构成的最大子集的大小
    // int findSubset(vector<string>& strs,int idx,int m,int n){
    //     if(idx<0)
    //         return 0;
    //     if(memo[idx][m][n]!=-1)
    //         return memo[idx][m][n];
    //     int num0 = str0Num(strs[idx]);
    //     int num1 = strs[idx].size()-num0;
    //     int pre_max = findSubset(strs,idx-1,m,n);
    //     if(num0>m||num1>n){
    //         memo[idx][m][n] = pre_max;
    //         return pre_max;
    //     }
        
    //     memo[idx][m][n] = max(findSubset(strs,idx-1,m-num0,n-num1)+1,pre_max);
    //     return memo[idx][m][n];
    // }
    // int findMaxForm(vector<string>& strs, int m, int n) {
    //     memo = vector<vector<vector<int>>>(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
    //     int ret = findSubset(strs,strs.size()-1,m,n);
    //     return ret;
    // }
    //动态规划
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> memo(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,0)));
        //初始化
        int num0 = str0Num(strs[0]);
        int num1 = strs[0].size()- num0;
        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
                if(i>=num0 &&j>=num1)
                    memo[0][i][j] = 1;
        for(int k = 1;k<strs.size();k++){
            num0 = str0Num(strs[k]);
            num1= strs[k].size()-num0;
            for(int i = 0;i<=m;i++){
                for(int j=0;j<=n;j++){
                    if(i>=num0 &&j>=num1)
                        memo[k][i][j] = max(memo[k-1][i][j],memo[k-1][i-num0][j-num1]+1);
                    else
                        memo[k][i][j] = memo[k-1][i][j];
                }

            }
        }
        return memo[strs.size()-1][m][n];
    }
};
// int main(){
//     vector<string> s = {"10", "0", "1"};
//     int ret = Solution().findMaxForm(s,1,1);
//     return 0;
// }
// @lc code=end

