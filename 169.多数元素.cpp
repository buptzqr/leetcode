/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;
class Solution {
public:
    // int majorityElement(vector<int>& nums) {
    //     // 哈希
    //     unordered_map<int,int> mmap;
    //     for(auto e:nums)
    //         mmap[e]++;
    //     for(auto e:mmap)
    //         if(e.second>nums.size()/2)
    //             return e.first;
    //     return 0;
    // }
    int majorityElement(vector<int>& nums) {
        // 摩尔投票法有点意思，本质思想就是我们要找的元素出现的次数
        // 减去其他所有元素出现的次数都大于1
        int res = nums[0];
        int count = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!= res){
                count--;
                if(count == 0){
                    res = nums[i];
                    count = 1;
                }
                    
            }
            else
                count++;
        }
        return res;
    }
};
// @lc code=end

