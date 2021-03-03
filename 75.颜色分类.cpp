/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 计数排序
        int r=0;
        int w=0;
        int b=0;
        for(auto e:nums){
            if(e==0)
                r++;
            else if(e==1)
                w++;
            else
                b++;
        }
        int i =0;
        while(r>0){
            nums[i] = 0;
            i++;
            r--;
        }
        while(w>0){
            nums[i] = 1;
            i++;
            w--;
        }
        while(b>0){
            nums[i] = 2;
            i++;
            b--;
        }
    }
};
// @lc code=end

