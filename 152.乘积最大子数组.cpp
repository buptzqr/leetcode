/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
// 如果当前位置是负数，希望乘以前面的那串连续子数组越小越好
// 如果当前位置是正数，希望乘以前面的那串连续子数组越大越好
// dp dp_min[i]表示以i结尾的连续子数组的最小乘积的值
//  dp dp_max[i]表示以i结尾的连续子数组的最大乘积的值
// dp_min[i] = min(dp_min[i-1]*v[i],dp_max[i-1]*v[i],v[i])
// dp_max[i] = max(dp_min[i-1]*v[i],dp_max[i-1]*v[i],v[i])
    int max3(int a,int b,int c){
        return max(a,max(b,c));
    }
    int min3(int a,int b,int c){
        return min(a,min(b,c));
    }
    int maxProduct(vector<int>& nums) {
        vector<int> dp_min(nums.size(),-1);
        vector<int> dp_max(nums.size(),-1);
        dp_min[0]=nums[0];
        dp_max[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            dp_min[i] = min3(dp_min[i-1]*nums[i],dp_max[i-1]*nums[i],nums[i]);
            dp_max[i] = max3(dp_min[i-1]*nums[i],dp_max[i-1]*nums[i],nums[i]);
        }
        int res = dp_max[0];
        for(int i=1;i<nums.size();i++)
            res = max(res,dp_max[i]);
        return res;
    }
};
// @lc code=end

