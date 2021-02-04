/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
//dp 时间复杂度是o(n^2)
    // int wiggleMaxLength(vector<int>& nums) {
    //     //memo[i][0]包括i在内的摆动子序列的长度前一个元素比nums[i]大
    //     //memo[i][1]包括i在内的摆动子序列的长度前一个元素比nums[i]小
    //     vector<vector<int>> memo(nums.size(),vector<int>(2,1));
    //     for(int i = 1;i < nums.size();i++){
    //         for(int j=0;j<i;j++){
    //             if(nums[j]<nums[i])
    //                 memo[i][1] = max(memo[i][1],1+memo[j][0]);
    //             if(nums[j]>nums[i])
    //                 memo[i][0] = max(memo[i][0],1+memo[j][1]);
    //         }
    //     }
    //     int ret =0;
    //     for(int i=0;i<nums.size();i++){
    //         ret = max(ret,memo[i][0]);
    //         ret = max(ret,memo[i][1]);
    //     }
    //     return ret;
    // }
    //dp 时间复杂度o(n)
    //up[i]表示从[0,i]最后两个元素是递增的最长摆动序列长度
    //down[i]表示从[0,i]最后两个元素是递增减的最长摆动序列长度
    //若nums[i]>nums[i-1] 对于down[i]肯定等于down[i-1]
    // 对于up[i] 如果down[i-1]最后一个元素正好的i-1则up[i] = down[i-1]+1 
    //如果最后一个元素不是i-1是j，那么从j到i-1要么是一直不增，要么一直不减
    // 因为如果先增后减那down[i-1]最后一个元素肯定不是j
    // 而对于这两种情况，依然up[i] = down[i-1]+1
    // 对于nums[i] = nums[i-1]保持不变
    // 对于nums[i]<nums[i-1]情况类似上面的分析
    // int wiggleMaxLength(vector<int>& nums) {
    //     if(!nums.size())
    //         return 0;
    //     int down = 1;
    //     int up = 1;
    //     int num = nums[0];
    //     for(int i=1;i<nums.size();i++){
    //         if(nums[i]<num)
    //             down = max(up+1,down);
    //         if(nums[i]>num)
    //             up = max(down+1,up);
    //         num = nums[i];
    //     }
    //     return down>up?down:up;
    // }
    //还可以这样思考，这道题目就是将上坡路和下坡路上多余的节点都去掉
    //然后看最后有多少个节点
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<=1)
            return nums.size();
        int i = 1; 
        while(i<nums.size()&&nums[i]==nums[0])
            i++;
        if(i == nums.size())
            return 1;
        int flag = nums[i]>nums[0]?1:0;//上坡为1，下坡为0
        int ret = 1;
        int point = nums[0];//记录前一个峰或谷点
        for(;i<nums.size();i++){
            if(nums[i]==nums[i-1])
                continue;
            if(flag==1&&nums[i]<nums[i-1]){
                flag = 0;
                ret++;
                point = nums[i-1];
            }
            if(flag ==0&&nums[i]>=nums[i-1]){
                flag = 1;
                ret++;
                point = nums[i-1];
            }
        }
        if(nums[nums.size()-1]!=point)//不等于前一个point则末尾元素要加进来，否则属于前一峰或谷点的平台
            ret++;
        return ret;        
    }
    
};
// int main(){
//     vector<int> input={0,0};
//     Solution().wiggleMaxLength(input);
// }
// @lc code=end

