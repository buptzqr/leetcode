/*
 * @lc app=leetcode.cn id=879 lang=cpp
 *
 * [879] 盈利计划
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
// dfs超时了
    // void dfs(int n, int minProfit, vector<int>& group, vector<int>& profit,int idx,int cur_profit,int& res){
    //     if(idx>=group.size()){
    //         if(cur_profit>=minProfit)
    //             res = (res+1)%(1000000007);
    //         return;
    //     }
    //     if(n>=group[idx])
    //         dfs(n-group[idx],minProfit,group,profit,idx+1,cur_profit+profit[idx],res);
    //     dfs(n,minProfit,group,profit,idx+1,cur_profit,res);       
            
    // }
    // int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    //     // 遍历group的所有组合
    //     int res=0;
    //     dfs(n,minProfit,group,profit,0,0,res);
    //     return res;
    // }
    // dp[j][k]表示j人最少获得k利润的方法数,相当于三层01背包
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int sz=group.size();
        const int M=1e9+7;
        vector<vector<int>> dp(n+1,vector<int>(minProfit+1,0));
        for (int j = 0; j <= n; ++j) {
            dp[j][0] = 1;
        }
        for(int i=1;i<=sz;++i){
            int g=group[i-1];
            int p=profit[i-1];
            for(int j=n;j>=g;--j){
                for(int k=minProfit;k>=0;--k){
                    dp[j][k]+=dp[j-g][max(k-p,0)];
                    dp[j][k]%=M;
                }
            }
        }
        return dp.back().back();
    }
    
    
};
// int main(){
//     vector<int> group={2,2};
//     vector<int> profit={2,3};
//     Solution().profitableSchemes(5,3,group,profit);
// }
// @lc code=end

