/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        int r=numbers.size()-1;
        vector<int> res;
        while(l<r){
            if(numbers[l]+numbers[r]==target){
                res.push_back(l+1);
                res.push_back(r+1);    
                break;            
            }
            if(numbers[l]+numbers[r]<target){
                l++;
            }
            if(numbers[l]+numbers[r]>target){
                r--;
            }
        }
        return res;
    }
};
// @lc code=end

