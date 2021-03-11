/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
#include<iostream>
using namespace std;
class Solution {
public:
    // string addStrings(string num1, string num2) {
    //     string res;
    //     int advance = 0;
    //     while(num1.size()||num2.size()){
    //         int c1 = 0;
    //         int c2 = 0;
    //         if(num1.size()){
    //             c1 = num1[num1.size()-1]-'0';   
    //             num1 = string(num1.begin(),num1.end()-1);            
    //         }
    //         if(num2.size()){
    //             c2 = num2[num2.size()-1]-'0';
    //             num2 = string(num2.begin(),num2.end()-1);            
    //         }
    //         int add_res = c1+c2+advance;
    //         res = to_string(add_res%10) + res;
    //         advance = add_res/10;
    //     }
    //     if(advance)
    //         res = to_string(advance) + res;
    //     return res;
    // }
    // 双指针
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string res;
        while(i>=0||j>=0){
            int c1 = 0;
            int c2 = 0;
            if(i>=0)
                c1 = num1[i]-'0';
            if(j>=0)
                c2 = num2[j]-'0';
            res = to_string((c1+c2+carry)%10) + res;
            carry = (c1+c2+carry)/10;
            i--;
            j--;
        }
        if(carry)
            res = to_string(carry) + res;        
        return res;
    }

};
// int main(){
//     Solution().addStrings("9","999");
// }
// @lc code=end

