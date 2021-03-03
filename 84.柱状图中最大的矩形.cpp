/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 单调栈，单调栈作用是用o（n）的复杂度来找任一元素左右的最大或最小值
        // 递增栈的特性，同理可以知道递减栈
        // 低增栈入栈规则是如果当前元素比栈顶元素大，则入栈
        // 如果当前元素小于栈顶元素，就出栈，知道当前元素大于等于栈顶元素，将当前元素入栈
        // 入栈的元素是栈顶元素右边第一个大于等于他的元素，
        // 栈内栈顶元素的下一个元素是栈顶元素左边第一个比他小的元素
        vector<int> s;
        heights.insert(heights.begin(),0);
        heights.push_back(0);//哨兵
        int res = 0;
        for(int i = 0; i <heights.size();i++){
            // 这里压入下标的原因是为了方便计算矩形宽度
            while(!s.empty()&&heights[s.back()]>heights[i]){
                int h = heights[s.back()];
                s.pop_back();
                int left = s.back()+1;
                int right = i -1;
                res = max(res,(right - left + 1) * h);
            }
            s.push_back(i);
        }
        return res;
    }
};
// int main(){
//     vector<int> vec={2,1,5,6,2,3};
//     Solution().largestRectangleArea(vec);
// }
// @lc code=end

