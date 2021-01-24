/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // vector<int> memo;//memo[i]代表考虑从第i号房屋开始偷窃可以获得的最高金额（并不是第i号一定被偷窃）
    // int n ;
    // int dfs(vector<int>&nums,int index){//考虑从i号房子开始抢劫可以获得的最大收益
    //     if(index>=n)
    //         return 0;
    //     if(memo[index]!=-1)
    //         return memo[index];
    //     memo[index] = max(nums[index]+dfs(nums,index+2),dfs(nums,index+1));
    //     return memo[index];
    // }
    // int rob(vector<int>& nums) {    
    //     memo = vector<int>(nums.size(),-1);
    //     n=nums.size();
    //     return dfs(nums,0);
    // }
    int rob(vector<int>& nums) { 
        if(!nums.size())
            return 0;   
        vector<int>memo(nums.size(),0);
        int n=nums.size();
        memo[n-1] =nums[n-1];
        for(int i = n-2;i>=0;i--)
            memo[i] = max(memo[i+1],nums[i]+(i+2<n?memo[i+2]:0));
        return memo[0];
    }    
};
// @lc code=end

