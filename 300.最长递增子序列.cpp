/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include<vector>
#include<iostream>
#include<iostream>
using namespace std;
class Solution {
public:
// dp o(n^2)时间复杂度
    // int lengthOfLIS(vector<int>& nums) {
    //     //LIS问题
    //     //lis[i]表示以第i个数字为结尾的最长上升子序列的长度
    //     //状态转移方程 lis[i]= max(1+lis[j],lis[i]) (if nums[j]<nums[i] j<i)
    //     vector<int> lis(nums.size(),1);
    //     for(int i=1;i<nums.size();i++)
    //         for(int j=0;j<i;j++)
    //             if(nums[j]<nums[i])
    //                 lis[i] = max(lis[i],lis[j]+1);
    //     int ret =1;
    //     for(auto e:lis)
    //         ret = max(ret,e);
    //     return ret;
    // }
    // 贪心+二分查找 时间复杂度o(nlogn)
    // 如果我们要使上升子序列尽可能的长，则我们需要让序列上升得尽可能慢，因此我们希望每次在上升子序列最后加上的那个数尽可能的小。
    // d[i] ，表示长度为 i 的最长上升子序列的末尾元素的最小值
    int lengthOfLIS(vector<int>& nums) {
        vector<int> d(1,nums[0]);
        int len =1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>d[len-1]){
                len++;
                d.push_back(nums[i]);
            }
            else
                *(lower_bound(d.begin(),d.end(),nums[i]))=nums[i];
        }
        return len;
    }

};
// int main(){
//     vector<int> input={10,9,2,5,3,7,101,18};
//     Solution().lengthOfLIS(input);
// }
// @lc code=end

