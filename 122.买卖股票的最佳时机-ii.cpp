/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
// 有限状态机思想
// 两个装填sold（卖出）和hold（拥有）
// sold状态：第i天卖出后从hold状态转为sold，或者前一天是sold状态，今天什么都没干
// hold状态：前一天是hold状态，今天什么也没做仍旧维持hold状态，或者其一天是sold今天买入成为hold状态
    int maxProfit(vector<int>& prices) {
        // sold和hold表示第i天保持该状态可以获得的最大利润
        int sold = 0; //第一天不可能卖出，所以令sold为0
        int hold = -prices[0];
        for(int i = 1; i<prices.size();i++){
            int pre_hold = hold;//这里也一定要注意呀，有点像数据库的脏读
            hold = max(sold - prices[i],hold);
            sold = max(pre_hold + prices[i],sold); 
        }   
        return sold;
    }
};
// @lc code=end

