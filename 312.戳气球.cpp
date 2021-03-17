/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& nums) {
// 想成是往里面加气球
// dp[i][j] 往(i,j)范围内加气球可以获得的最大价值
        int sz = nums.size();
        vector<int> val(sz+2,1);
        for(int i=1;i<=sz;i++)
            val[i] = nums[i-1];
        vector<vector<int>> dp(sz+2,vector<int>(sz+2,0));
        for(int i=sz-1;i>=0;i--){
            for(int j = i + 2;j <= sz + 1;j++){//j一定要紧贴着i然后一点点的扩展
                for(int k = i+1;k < j;k++){
                    int v = val[i] * val[j] * val[k];
                    dp[i][j] = max(dp[i][j],v + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][sz+1];
    }
};
// @lc code=end

