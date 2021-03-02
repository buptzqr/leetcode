/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 这个题目的关键是从右到左找前nums[i]<nums[i+1]
        // 此时从[i+1,end)必然是降序，然后在这个范围内找第一个大于nums[i]的元素nums[k]
        // 交换nums[k]和nums[i],同时将[i+1,end)内元素逆置，将其变为升序
        if(nums.size()<2)
            return;
        for(int i = nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                for(int j = nums.size()-1;j>=i;j--)
                    if(nums[j]>nums[i-1]){
                        swap(nums[j],nums[i-1]);
                        break;
                    }
                // 逆置
                reverse(nums.begin()+i,nums.end());
                return;
            }
        }
        reverse(nums.begin(),nums.end());
    }
};
// int main(){
//     vector<int> vec={1,3,2};
//     Solution().nextPermutation(vec);
//     return 0;
// }
// @lc code=end

