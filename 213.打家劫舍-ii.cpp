/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
#include<vector>
#include<iostream>
using namespace std;
class Solution {
// 我的笨办法，按照偷不偷最后一个房子来分情况做动态规划，后来发现好多人这样做
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        vector<int> memo(n, 0);
        memo[n-1]= nums[n-1];
        int res = 0;
        for(int i=n-2;i>0;i--)
            memo[i] = max(nums[i]+(i+2<n?memo[i+2]:0),memo[i+1]);
        res = max(res,memo[1]);
        memo = vector<int>(n,0);
        memo[n-2] = nums[n-2];
        for(int i=n-3;i>=0;i--)
            memo[i] = max(nums[i]+(i+2<n-1?memo[i+2]:0),memo[i+1]);
        res = max(res,memo[0]);
        return res;     
    }
};
// @lc code=end

