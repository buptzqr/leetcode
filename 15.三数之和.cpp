/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    // 关键是要使得a<=b<=c那么就不会有重复了,想要达到这样的效果
    // 首先要排序
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size();i++){
            if(i>0&&nums[i]==nums[i-1])
                continue;
            int k = nums.size()-1;//k一定放在这个位置
            for(int j = i+1;j<nums.size();j++){
                if(j>i+1&&nums[j]==nums[j-1])
                    continue;
                while(j<k&&nums[j]+nums[k]>-nums[i])
                    k--;
                if(j==k)
                    break;
                if((nums[j]+nums[k]+nums[i])==0){
                    //k不需要排除重复元素，因为j排除了k就一定会排除
                    res.push_back({nums[j],nums[k],nums[i]});
                }
            }
        }
        return res;
    }
};
// @lc code=end

