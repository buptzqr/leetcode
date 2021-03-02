/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //居然是异或运算
        if(nums.size()<=1)
            return nums[0];
        int res = nums[0];
        for(int i=1; i<nums.size();i++)
            res^=nums[i];
        return res;
    }
};
// @lc code=end

