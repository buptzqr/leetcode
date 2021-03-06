/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include<iostream>
#include<limits.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int res =0;
        int i =0 ;
        while(s[i]==' ')    
            i++;
        int is_negative = 1;
        if(s[i]=='-')
            is_negative = -1;
        else if(isdigit(s[i]))
            res += s[i] - '0';
        else if(s[i]!= '+')
            return res;
        i++;
        for(;i<s.size();i++){
            if(!isdigit(s[i]))
                return res;
            if(res>INT_MAX/10||(res==INT_MAX/10&&s[i]-'0'>7))    
                return INT_MAX;
            if(res<INT_MIN/10||(res==INT_MIN/10&&s[i]-'0'>8))
                return INT_MIN;
            res = res*10+(s[i]-'0')*is_negative;
        }
        return res;
    }
};
// @lc code=end

