/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // dfs求集合肯定行
        // 排序然后对每个位置做检查时间复杂度是n^2，类似于三数之和
        sort(nums.begin(),nums.end());
        int res = nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i] == nums[i-1])
                continue;
            int k = nums.size()-1;
            for(int j = i+1;j<k;j++){
                if(j>i+1&&nums[j]==nums[j-1])
                    continue;
                while(k>j&&nums[j]+nums[k]+nums[i]>target){
                    if(abs(res-target)>abs(nums[j]+nums[k]+nums[i]-target))
                        res = nums[j]+nums[k]+nums[i];
                    k--;
                }
                if(k==j)
                    break;
                // 刚比target小时也要尝试进行更新
                if(abs(res-target)>abs(nums[j]+nums[k]+nums[i]-target))
                    res = nums[j]+nums[k]+nums[i];
                // 就下面这条语句就疯狂提升时间和空间效率
                if(res == target) 
                    return res;                  
            }
        }
        return res;
    }
};
// int main(){
//     vector<int> vec={-1,2,1,-4};
//     Solution().threeSumClosest(vec,1);
// }
// @lc code=end

