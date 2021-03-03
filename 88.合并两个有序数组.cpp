/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 从后往前放就可以了
        int l=m-1;
        int r=n-1;
        for(int cur = nums1.size()-1;cur>=0&&r>=0;cur--){//只要保证nums2的都放好就行了
            if(l<0){
                nums1[cur] = nums2[r];
                r--;
            }
            else if(nums1[l]>=nums2[r]){
                nums1[cur] = nums1[l];
                l--;
            }
            else{
                nums1[cur] = nums2[r];
                r--;
            }
        }
    }
};
// @lc code=end

