/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 用一个counter来记录该元素出现的次数
        // 用idx记录下一个元素应该被放置的位置
        if(!nums.size())
            return 0;
        int counter = 1;
        int idx= 1;
        for(int i=1; i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                counter=1;
                nums[idx] = nums[i];
                idx++;
            }
            else if(nums[i]==nums[i-1]&&counter<2){
                nums[idx] = nums[i];
                counter++;
                idx++;
            }
            else{
                counter++;
            }
        }
        return idx;        
    }
};
// @lc code=end

