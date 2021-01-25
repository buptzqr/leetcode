/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
// 用元素填满sum/2的背包，相当于01背包问题
class Solution {
public:
// 记忆化搜索
    // vector<vector<int>> memo;
    // bool tryFindSum(const vector<int>& nums,int idx,int cap){
    //     if(!cap)
    //         return true;
    //     if(cap<0||idx<0)
    //         return false;
    //     if(memo[idx][cap]!=-1)
    //         return memo[idx][cap];
    //     bool res = tryFindSum(nums,idx-1,cap)||tryFindSum(nums,idx-1,cap-nums[idx]);
    //     memo[idx][cap]= res;
    //     return res;
    // }
    // bool canPartition(vector<int>& nums) {
    //     int sum=0;
    //     for(auto e:nums)
    //         sum+=e;
    //     if(sum%2)//如果sum不能被2整除，那肯定不能将数组分成两部分
    //         return false;
    //     sum/=2;
    //     memo = vector<vector<int>>(nums.size(),vector<int>(sum+1,-1));
    //     //memo[idx][cap]代表使用从[0，idx]的元素是否可以填满容量为cap背包，1代表可以填满背包
    //     // 0代表无法填满,-1代表未访问
    //     return tryFindSum(nums,nums.size()-1,sum);
    // }
    // 动态规划
       bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto e:nums)
            sum+=e;
        if(sum%2)//如果sum不能被2整除，那肯定不能将数组分成两部分
            return false;
        sum/=2;
        vector<bool> memo(sum+1,false);
        for(int i=0;i<=sum;i++)
            if(nums[0]==i)
                memo[i] = true;
        //memo[j]代表上[0,i]的元素是否可以填满容量为j的背包，j在下面的循环中体现
        for(int i=1; i<nums.size();i++)//这里小心，已经初始化了就从1开始循环了
            for(int j = sum;j>=nums[i];j--)
                memo[j] = memo[j]||memo[j-nums[i]];
        return memo[sum];
    }
 
};
// @lc code=end

