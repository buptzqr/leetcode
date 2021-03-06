/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
// 用状态机的思想，因为只能完成两笔交易，所以有四个状态
// sold1,hold1,sold2,hold2
// 其中sold1,只能从sold1和hold1转过来
// hold1只能从hold1转过来
// hold2只能从sold1或者hold2转过来
// sold2只能由hold2或者sold2转过来
    int maxProfit(vector<int>& prices) {
        int sold1,hold1,hold2,sold2;
        hold1 = -prices[0];
        sold1 = 0;
        hold2 = -prices[0];
        sold2 = 0;
        for(int i = 1;i<prices.size();i++){
            hold1 = max(-prices[i],hold1);
            //不用prehold1的原因是这样就是多考虑了
            // 当天买入，当天卖出的情况，这种情况利益为0对实际结果不影响
            sold1 = max(hold1+prices[i],sold1);
            hold2 = max(sold1-prices[i],hold2);
            sold2 = max(hold2+prices[i],sold2);
        }
        return sold2;
    }
};
// @lc code=end

