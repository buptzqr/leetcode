/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int l= 0;
        int r= 0;
        while(l<nums1.size()&&r<nums2.size()){
            if(nums1[l]<nums2[r]){
                nums.push_back(nums1[l]);
                l++;
            }
            else{
                nums.push_back(nums2[r]);
                r++;
            }
        }
        while(l<nums1.size()){
            nums.push_back(nums1[l]);
                l++;
        }
        while(r<nums2.size()){
            nums.push_back(nums2[r]);
            r++;
        }
        int idx = nums.size()/2;
        if(nums.size()%2)
            return nums[idx];            
        else
            return (nums[idx-1]+nums[idx])/2.0;
        
    }
};
// @lc code=end

