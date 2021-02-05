/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
#include<vector>
#include<limits.h>
using namespace std;
class Solution {
public:
//memo[idx][flag]记录idx采取flag操作，到最后一天所能得到的最大收益
// flag有三种状态0代表买入，1代表卖出，2代表冷冻
    vector<vector<int>> memo;
    // flag代表上一次的操作
    int findMaxProfit(vector<int>& prices,int idx,int flag){
        if(idx==prices.size()-1)
            if(flag==0)
                return prices[idx];
            else
                return 0;
        // 上次卖出，此次只能冰冻
        if(flag==1){
            if(memo[idx][2]==INT_MIN)
                memo[idx][2]=findMaxProfit(prices,idx+1,2);
            return memo[idx][2];
        }
        // 上次买入，此次可以卖出，可以等待（等待不是冰冻）
        if(flag==0){
            if(memo[idx][1]==INT_MIN)
                memo[idx][1]=max(prices[idx]+findMaxProfit(prices,idx+1,1),findMaxProfit(prices,idx+1,0));
            return memo[idx][1];
        }
        // 上次冰冻，此次可以买入，可以等待
        if(flag==2)
            if(memo[idx][0]==INT_MIN)
                memo[idx][0]=max(findMaxProfit(prices,idx+1,0)-prices[idx],findMaxProfit(prices,idx+1,2));
            return memo[idx][0];
    }

    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        memo = vector<vector<int>>(prices.size(),vector<int>(3,INT_MIN));
        int ret =max(findMaxProfit(prices,1,0)-prices[0],findMaxProfit(prices,1,2));    
        return ret;
    }
};
// int main(){
//     vector<int> input ={1,2,3,0,2};
//     return Solution().maxProfit(input);
// }
// @lc code=end

