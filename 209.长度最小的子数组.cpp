/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include<vector>
#include<limits.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 滑动窗口
        int l = 0;
        int r = 0;
        int cur_count = nums[0];
        int res = INT_MAX;
        while(r<nums.size()&&l<=r){
            if(cur_count<target){
                r++;
                if(r<nums.size())
                    cur_count+= nums[r];
            }
            else{
                res = min(res,r-l+1);
                cur_count-=nums[l];
                l++;
            }
        }
        if(res==INT_MAX)//防止加起来还达不到target的情况
            return 0;
        return res;
    }
};
// @lc code=end

