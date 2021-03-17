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
    // vector<int> searchRange(vector<int>& nums, int target) {
    //     if(nums.size() == 0)
    //         return vector<int>(2,-1);
    //     int begin = -1;
    //     int end = nums.size();
    //     while(begin+1<nums.size()&&nums[begin+1]<target)
    //         begin++;
    //     while(end-1>=0&&nums[end-1]>target)
    //         end--;
    //     begin++;
    //     end--;
    //     int a[2] = {begin,end};
    //     if(begin>end)
    //         return vector<int>(2,-1);
    //     return vector<int>(a,a+2);        
    // }
    // 二分查找
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        // 计算下边界
        while(l<=r){
            int mid = l + ((r-l)>>1);
            if(nums[mid]>=target)
                r=mid-1;
            else
                l=mid+1;
        }
        int lower = l;
        l = 0;
        r = nums.size();
        // 计算上边界
        while(l<=r){
            int mid = l + ((r-l)>>1);
            if(nums[mid]<=target)
                l=mid+1;
            else
                r=mid-1;
        }
        int upper = r;
        vector<int> res;
        if(upper>=lower)
            res = {lower,upper};
        return res;
    }
    // 找第一个小于target的元素的下标
    int findFirstLowerIdx(vector<int>& nums,int target){
        int l = 0;
        int r = nums.size();
        while(l<=r){
            int mid = l + ((r-l)>>1);
            if(nums[mid]>=target)
                r=mid-1;
            else
                l=mid+1;
        }
        return r;
    }
};
int main(){
    vector<int> vec={5,7,7,8,8,10};
    Solution().findFirstLowerIdx(vec,4);
}
// @lc code=end

