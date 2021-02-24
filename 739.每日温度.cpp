/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
#include<vector>
#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        // 通常是一维数组，
        // 要寻找任一个元素的右边或者左边第一个比自己大或者小的元素的位置
        // 此题维护一个从栈顶到栈底的单调递减的栈就好
        // 和之前的那个单调队列可以类比
        stack<int> rec;
        vector<int> res(T.size(),0);
        rec.push(0);
        for(int i=1;i<T.size();i++){
            while(!rec.empty()&&T[i]>T[rec.top()]){
                res[rec.top()] = i - rec.top();
                rec.pop();
            }
            rec.push(i);
        }
        return res;
    }
};
// @lc code=end

