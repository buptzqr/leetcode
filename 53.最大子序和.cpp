/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
#include<vector>
using namespace std;
// dp[i]表示以nums[i]元素为结尾的连续子数组的最大和
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        dp[0]=nums[0];
        for(int i=1; i<nums.size();i++)
            dp[i] = max(dp[i-1]+nums[i],nums[i]);
        int ret = dp[0];
        for(int i=1; i<nums.size();i++)
            ret= max(ret,dp[i]);
        return ret;
    }
};
// @lc code=end

