/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=1)
            return nums.size();
        int res = 1;
        int num = nums[0];
        for(int i = 1; i<nums.size();i++){
            if(nums[i]!=num){
                nums[res] = nums[i];
                num = nums[i];
                res++;
            }
        } 
        return res;
    }
};
// @lc code=end

