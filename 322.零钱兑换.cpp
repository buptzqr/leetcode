/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include<vector>
#include<iostream>
#include<algorithm>
#include"limits.h"
using namespace std;
class Solution {
// 我自己的办法，时间复杂度amount*coins.size(),这道题需要注意的是-1代表找不到，是有意义的
// 所以memo初始化时不要初始化成-1
public:
//记忆化搜索
    // memo[idx][amount]:考虑从[0,idx]的元素凑amount需要的最少硬币数
    // vector<vector<int>> memo;
    // int findMinCoins(const vector<int>& coins,int idx,int amount){
    //     if(amount==0)
    //         return 0;
    //     if(amount<0||idx<0)
    //         return -1;
    //     if(memo[idx][amount]!=-2)
    //         return memo[idx][amount];
    //     int min_coins = INT_MAX;
    //     int n  = amount/coins[idx];//凑j最多可以使用多少个coins[idx]
    //     for(int i=0;i<=n;i++){
    //         int nums = findMinCoins(coins,idx-1,amount-i*coins[idx]);
    //         if(nums!=-1)
    //             min_coins = min(min_coins,nums+i);
    //     }
    //     if(min_coins!=INT_MAX)
    //         memo[idx][amount] = min_coins;
    //     else
    //         memo[idx][amount] = -1;
    //     return memo[idx][amount];
    // }
    // //memo[idx][amount]表示从[0,idx]凑成amount所需要的最少硬币数，-1代表无法凑成
    // int coinChange(vector<int>& coins, int amount) {
    //     memo = vector<vector<int>>(coins.size(),vector<int>(amount+1,-2));
    //     int ret = findMinCoins(coins,coins.size()-1,amount);
    //     return ret;
    // }
//波神版本，这个时间复杂度amount*coins.size()，思路是直接用coins凑amount最少需要多少个
// 硬币，想起来更简单一点
// public:
//     vector<int> memo;//memo[i]代表用coins中的钱币构成i所需要的最少钱币数,-2代表memo没有被访问，-1代表无法构成
//     int findCoins(vector<int>& coins,int amount){
//         if(!amount)
//             return 0;
//         if(amount<0)
//             return -1;
//         if(memo[amount]!=-2)
//             return memo[amount];
//         int res = INT_MAX;
//         for(auto e:coins){
//             int num =findCoins(coins,amount-e);
//             if(num>=0)
//                 res = min(res,num+1);
//         }
//         if(res!=INT_MAX)
//             memo[amount] = res;
//         else
//             memo[amount] = -1;//每次返回的是无法构成则memo[amount] = -1
//         return memo[amount];        
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         memo = vector<int>(amount+1,-2);
//         return findCoins(coins,amount);
//     }
// 动态规划
    public:
    int coinChange(vector<int>& coins, int amount) {
        //从0到amount
        vector<int> memo(amount+1,-2);
        memo[0]=0;
        for(int i=1;i<=amount;i++){
            int min_num = INT_MAX;
            for(auto coin:coins){
                int before = i-coin;
                if(before>=0&&memo[before]>=0)
                    min_num = min(min_num,memo[before]+1);
            }
            if(min_num<INT_MAX)
                memo[i] = min_num;
            else
                memo[i] = -1;
        }
        return memo[amount];
    }
};
// int main(){
//     vector<int> coins = {2};
//     Solution().coinChange(coins,3);
// }
// @lc code=end

