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
// 只要使用递归，那么一定是自顶向下的思考问题
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
    /*
    我们用 f[i]表示第 i 天结束之后的「累计最大收益」。
    根据题目描述，由于我们最多只能同时买入（持有）一支股票，
    并且卖出股票后有冷冻期的限制，因此我们会有三种不同的状态：
    我们目前持有一支股票，对应的「累计最大收益」记为 f[i][0]；
    我们目前不持有任何股票，并且处于冷冻期中，对应的「累计最大收益」记为 f[i][1]；
    我们目前不持有任何股票，并且不处于冷冻期中，对应的「累计最大收益」记为 f[i][2]。
    这里的「处于冷冻期」指的是在第i天结束之后的状态。也就是说：如果第i天结束之后处于冷冻期，那么第 i+1天无法买入股票。

    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        int f0 = -prices[0];
        int f1 = 0;
        int f2 = 0;
        for (int i = 1; i < n; ++i) {
            int newf0 = max(f0, f2 - prices[i]);
            int newf1 = f0 + prices[i];
            int newf2 = max(f1, f2);
            f0 = newf0;
            f1 = newf1;
            f2 = newf2;
        }

        return max(f1, f2);
    }

    */
};
// int main(){
//     vector<int> input ={1,2,3,0,2};
//     return Solution().maxProfit(input);
// }
// @lc code=end

