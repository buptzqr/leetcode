/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int bisearch(int l,int r,vector<int>& nums,int target){
        if(l>r)
            return -1;
        int mid=l+(r-l)/2;
        if(nums[mid]==target)
            return mid; 
        if(nums[l]<=nums[mid])
            // 左半部分有序
            if(target>=nums[l]&&target<nums[mid])
                return bisearch(l,mid-1,nums,target);
            else
                return bisearch(mid+1,r,nums,target);
        else
            // 右半部分有序 
            if(target>nums[mid]&&target<=nums[r])
                return bisearch(mid+1,r,nums,target);
            else
                return bisearch(l,mid-1,nums,target);
    }
    int search(vector<int>& nums, int target) {
        // 还是可以用二分搜索的办法
        return bisearch(0,nums.size()-1,nums,target);
    }
};
// int main(){
//     vector<int> vec={5,1,3};
//     int res =Solution().search(vec,5);
//     return res;
// }
// @lc code=end

