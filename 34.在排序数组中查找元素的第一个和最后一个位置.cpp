/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
//双指针
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return vector<int>(2,-1);
        int begin = -1;
        int end = nums.size();
        while(begin+1<nums.size()&&nums[begin+1]<target)
            begin++;
        while(end-1>=0&&nums[end-1]>target)
            end--;
        begin++;
        end--;
        int a[2] = {begin,end};
        if(begin>end)
            return vector<int>(2,-1);
        return vector<int>(a,a+2);        
    }
};
// @lc code=end

