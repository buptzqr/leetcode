/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        //先用两个指针卡出两头有序范围
        //对于中间无序的这部分内容[low,high]，遍历此区域
        //如果当前值比high+1大，则high++，如果当前值比low-1小，则low--
        int low = 0;
        int high = nums.size()-1;
        
        while(low<nums.size()-1&&nums[low]<=nums[low+1])
            low++;
        while(high>0&&nums[high]>=nums[high-1])
            high--;
        if(low>=high)
            return 0;
        for(int i=low;i<=high;i++){
            while(high<nums.size()-1&&nums[i]>nums[high+1])
                high++;
            while(low>0&&nums[i]<nums[low-1])
                low--;
        }
        return high-low+1;
    }
};
// @lc code=end

