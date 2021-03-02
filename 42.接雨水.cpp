/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        // 双指针法，如果右边有更高的板子则从左到右的容积取决于左边的板子
        // 直到左边的板子大于等于右边这块最高的板子
        // 同理从右到左也一样
        if(height.size()<3)
            return 0;
        int l =1;
        int r =height.size()-2;
        int leftmax = height[0];
        int rightmax = height[height.size()-1];
        int res = 0;
        while(l<=r){
            while(l<=r){
                leftmax = max(leftmax,height[l]);
                if(leftmax>rightmax)
                    break;
                res+=leftmax - height[l];
                l++;
            }
            while(l<=r){
                rightmax = max(rightmax,height[r]);
                if(rightmax>leftmax)
                    break;
                res+=rightmax-height[r];
                r--;
            }
        }
        return res;
    }
    /*
    int trap(vector<int>& height)
{
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
            ++left;
        }
        else {
            height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
            --right;
        }
    }
    return ans;
}
    */
};
// int main(){
//     vector<int> vec ={4,2,0,3,2,5};
//     Solution().trap(vec);
// }
// @lc code=end

