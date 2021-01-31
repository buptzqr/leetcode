/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
// key <index,s> 考虑从[0,index]的元素构成s val 方法数
    // map<pair<int,long>,int> memo;
    // int targetSumWays(vector<int>& nums,int idx,long s){
    //     if(idx < 0&&s == 0)
    //         return 1;
    //     if(idx < 0)
    //         return 0;
    //     pair<int,long> p= make_pair(idx,s);
    //     if(memo.find(p)!= memo.end())
    //         return memo[p];
    //     int tmp=targetSumWays(nums,idx-1,s+nums[idx]);
    //     tmp+=targetSumWays(nums,idx-1,s-nums[idx]);
    //     memo[p]= tmp;
    //     return memo[p];
    // }
    // int findTargetSumWays(vector<int>& nums, int S) {
    //     int ret=targetSumWays(nums,nums.size()-1,S);
    //     return ret;        
    // }
    // int findTargetSumWays(vector<int>& nums, int S) {
    //     //动态规划
    //     int bias = 1000;
    //     vector<vector<int>> memo(nums.size(),vector<int>(2001,0));
    //     memo[0][nums[0]+bias] +=1;//注意这里可是+=
    //     memo[0][bias-nums[0]] +=1;
    //     for(int i = 1;i<nums.size();i++){
    //         for(int j = 0;j<=2000;j++){
    //             if(0<=j+nums[i]&&2000>=j+nums[i])
    //                 if(memo[i-1][j])
    //                     memo[i][j+nums[i]] += memo[i-1][j];//注意这里可是+=
    //             if(0<=j-nums[i]&&2000>=j-nums[i])
    //                 if(memo[i-1][j])
    //                     memo[i][j-nums[i]] += memo[i-1][j];
                
    //         }
    //     }
    //     if(-bias>S||2000-bias<S)
    //         return 0;
    //     return memo[nums.size()-1][S+bias];
    // }
    int findTargetSumWays(vector<int>& nums, int S) {
        //动态规划+空间优化
        int bias = 1000;
        vector<vector<int>> memo(2,vector<int>(2001,0));
        memo[0][nums[0]+bias] +=1;//注意这里可是+=
        memo[0][bias-nums[0]] +=1;
        for(int i = 1;i<nums.size();i++){
            memo[i%2]=vector<int>(2001,0);
            for(int j = 0;j<=2000;j++){
                if(0<=j+nums[i]&&2000>=j+nums[i])
                    if(memo[(i-1)%2][j])
                        memo[i%2][j+nums[i]] += memo[(i-1)%2][j];//注意这里可是+=
                if(0<=j-nums[i]&&2000>=j-nums[i])
                    if(memo[(i-1)%2][j])
                        memo[i%2][j-nums[i]] += memo[(i-1)%2][j];
                
            }
        }
        if(-bias>S||2000-bias<S)
            return 0;
        return memo[(nums.size()-1)%2][S+bias];
    }
};
// int main(){
//     vector<int> nums = {1,1,1,1,1};
//     Solution().findTargetSumWays(nums,3);
// }
// @lc code=end

