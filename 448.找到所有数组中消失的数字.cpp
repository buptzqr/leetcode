/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // 这种方法时间复杂度可能不是o(n)
        // vector<int> res;
        // // 遍历一遍nums，把对应的元素放到该放的位置上
        // for(int i = 0; i < nums.size();i++){
        //     while(nums[i]!=i+1&&nums[i]){
        //         if(nums[i]==nums[nums[i]-1]){
        //             nums[i]=0;
        //             break;
        //         }
        //         swap(nums[i],nums[nums[i]-1]);
        //     }
        // }
        // for(int i=0;i<nums.size();i++)
        //     if(nums[i]==0)
        //         res.push_back(i+1);
        // return res;
        
        // 原地修改，将nums[nums[i]]*(-1),最后遍历元素，如果不为负值，则为未出现元素
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            int idx = nums[i]<0 ?nums[i]*-1:nums[i];
            nums[idx-1] = nums[idx-1]>0?nums[idx-1]*-1:nums[idx-1];
        }
        for(int i=0;i<nums.size();i++)
            if(nums[i]>0)
                res.push_back(i+1);
        return res;
    }
};
// int main(){
//     vector<int> vec={4,3,2,7,8,2,3,1};
//     Solution().findDisappearedNumbers(vec);
// }
// @lc code=end

