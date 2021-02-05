/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
// 求每个元素i左侧所有元素的乘积L[i]和每个元素右侧所有元素的乘积R[i]
// 最后每个位置的结果就是L[i]*R[i]
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     vector<int> ret(nums.size(),0);
    //     vector<int> L(nums.size(),1);
    //     vector<int> R(nums.size(),1);
    //     int r = nums.size()-1;
    //     for(int i = 1;i < nums.size();i++){
    //         L[i] = nums[i-1]*L[i-1];
    //         R[r-i] = nums[r-i+1]*R[r-i+1];
    //     }
    //     for(int i = 0;i < nums.size();i++)
    //         ret[i] = L[i]*R[i];
    //     return ret;            
    // }
    //用两轮循环轻松干掉多余的R和L
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size(),1);
        int l = 1;
        for(int i = 1;i < nums.size();i++){
            l *= nums[i-1];
            ret[i]=l;
        }
        int r = 1;
        for(int j = nums.size()-2;j>= 0; j--){
            r*=nums[j+1];
            ret[j]*=r;
        }
        return ret;
    }

};
// @lc code=end

