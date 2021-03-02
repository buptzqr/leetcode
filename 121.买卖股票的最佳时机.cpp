/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    // 单调栈：（这道题的本质是求任意一个元素右面和他差值最大的元素）
    // 维护一个单增栈
    // 当前元素如果比栈顶元素小或等于，将栈顶元素弹出栈，直到栈顶元素小于该元素
    // 将该元素入栈，在栈顶元素出栈时与栈底元素相减，更新最大利润
    // 栈顶元素弹栈的原因是即使后面存在比栈顶元素更大的元素
    // 他与栈顶元素的差也肯定比他与当前元素的差小
    // 如果当前元素比栈顶元素大，直接入栈
    // 最后入栈一个哨兵0，是为了让栈里所有的元素都弹出去
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        prices.push_back(0);
        vector<int> s;
        s.push_back(prices[0]);
        int res=0;
        for(int i=1;i<prices.size();i++){
            while(!s.empty()&&prices[i]<s.back()){
                res = max(res,s.back()-s.front());
                s.pop_back();
            }
            s.push_back(prices[i]);
        }
        return res;
    }
};
// @lc code=end

