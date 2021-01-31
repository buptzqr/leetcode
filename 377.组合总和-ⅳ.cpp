/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        using ull = unsigned long long;
        vector<ull> memo(target+1,0);//memo[i]代表组成target的组合数
        memo[0] = 1;
        for(int i=1;i<=target;i++){
            ull target_num = 0;
            for(auto num:nums){
                int before = i - num;
                if(before>=0)
                    target_num +=memo[before];
            }
            memo[i] = target_num;
        }        
        return memo[target];
    }
};
// int main(){
//     vector<int> a = {3,33,333};
//     Solution().combinationSum4(a,10000);
// }
// @lc code=end

