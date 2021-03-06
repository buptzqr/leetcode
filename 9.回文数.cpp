/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        // 反转后一半数字，和前一半比较（只要是回文，想办法找中间点是一种常见的方式）
        if(x<0 ||(x % 10 == 0 && x != 0))//后面拖着一堆0的情况要注意
            return false;
        int last_half = 0;
        while(x>last_half){
            last_half = last_half*10+x%10;
            x/=10;
        }
        return x==last_half||last_half/10==x;
    }
};
// @lc code=end

