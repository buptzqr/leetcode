/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
//记忆化搜索
    vector<vector<int>> memo;
    // 考虑从[0,idx]的元素凑amount需要的最少硬币数
    int findMinCoins(const vector<int>& coins,int idx,int amount){
        if(amount<=0||idx<0)
            return -1;
        if(memo[idx][amount]!=-1)
            return memo[idx][amount];
        for(int j=coins[idx];j<=amount;j++){
            int n  = j/coins[idx];//凑j最多可以使用多少个coins[idx]
            
        }
    }
    //memo[idx][amount]表示从[0,idx]凑成amount所需要的最少硬币数，-1代表无法凑成
    int coinChange(vector<int>& coins, int amount) {
        // 这种可以多次使用的东西一般需要排序
        sort(coins.begin(),coins.end());
        memo = vector<vector<int>>(coins.size(),vector<int>(amount+1,-1));
        return findMinCoins(coins,coins.size()-1,amount);
    }
};
// @lc code=end

