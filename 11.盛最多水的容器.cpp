/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int l = 0;
        int r = height.size()-1;
        while(l<r){
            res = max(res,(r-l)*min(height[l],height[r]));
            if(height[l]<height[r])
                l++;
            else
                r--;
        }
        return res;
    }
};
// int main(){
//     vector<int> vec={1,8,100,2,100,4,8,3,7};
//     int res=Solution().maxArea(vec);
//     return res;
// }
// @lc code=end

