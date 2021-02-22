/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
#include<vector>
#include<iostream>
#include<queue>
using namespace std;
class Solution {
public:
// 最后一个测试用例不对，我也不知道最后一个测试用例是啥，时间复杂度和贪心一样
// 按理说不应该超时
    // bool canJump(vector<int>& nums) {
    //     //初步想法就是建图，然后用bfs，或者dfs了
    //     //bfs
    //     vector<bool> visited(nums.size(),false);
    //     vector<int> mmap;
    //     mmap.push_back(0);
    //     while(!mmap.empty()){
    //         vector<int> tmp;
    //         for(auto e:mmap)
    //             for(int i=0;i<=nums[e];i++){
    //                 int des = e+i<nums.size()?e+i:nums.size()-1;
    //                 if(!visited[des])
    //                     if(des == nums.size()-1)
    //                         return true;
    //                     else{
    //                         visited[des]=true;
    //                         tmp.push_back(des);
    //                     }
    //             }
    //         mmap = tmp;
    //     }
    //     return false;
    // }
    // 贪心
    // 不用管每次跳几步，我们只关注可以覆盖到的最大范围，我们在该范围内移动
    // 更新该范围，如果该范围达到最后一个元素，则返回true，否则返回false
    bool canJump(vector<int>& nums) {
        int range = nums[0];
        if (nums.size() == 1) return true;//只有一个元素肯定可以到达
        for(int i=1;i<=range;i++){
            range = max(range,i+nums[i]);
            if(range>=nums.size()-1)
                return true;
        }
        return false;
    }

};
// @lc code=end

