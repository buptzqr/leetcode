/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include<limits.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        if(x>10&&x<10)
            return x;
       
        int res = 0;
        while(x){
            int next = x%10;
            // 这道题最应该注意的就是这个判断越界的条件
            if(res>INT_MAX/10||(res==INT_MAX/10&&next>7))
                return 0;
            if(res<INT_MIN/10||(res==INT_MIN/10&&next<-8))
                return 0;
            res = res*10+next;
            x/=10;
        }
        return res;
    }
};
// @lc code=end

