/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 用一个指针记录下一个非零元素应该放置的位置
        int notZeroIdx = 0;
        for(int i = 0; i < nums.size();i++){
            if(nums[i]){
                nums[notZeroIdx] = nums[i];
                notZeroIdx++;
            }
        }
        for(;notZeroIdx<nums.size();notZeroIdx++){
            nums[notZeroIdx] =0;
        }
    }
    /*
    bo
    {int k = 0; // keep nums[0...k) are all zero elements
        for(int i = 0 ; i < nums.size() ; i ++)
            if(nums[i])
                swap(nums[k++] , nums[i]);
    }
    这样可以避免极端情况[0,0,0...1]重复的赋值操作，但是swap在普通情况下感觉还是挺耗计算量的
    */
};
// @lc code=end

