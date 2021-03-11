/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
class Solution {
public:
//     string add(string s1, string s2){
//         string res;
//         int advance = 0;
//         while(s1.size()||s2.size()){
//             int c1 = 0;
//             int c2 = 0;
//             if(s1.size()){
//                 c1 = s1[s1.size()-1]-'0';
//                 s1 = string(s1.begin(),s1.end()-1);            
//             }
//             if(s2.size()){
//                 c2 = s2[s2.size()-1]-'0';
//                 s2 = string(s2.begin(),s2.end()-1);            
//             }
//             int add_res = c1+c2+advance;
//             res = to_string(add_res%10) + res;
//             advance = add_res/10;
//         }
//         if(advance)
//             res = to_string(advance) + res;
//         return res;
//     }
// // 这道题目就是考察大数相乘
//     string multiply(string num1, string num2) {
//         if(num1[0]=='0'||num2[0]=='0')
//             return "0";
//         string res="0";
//         int degree = 0;
//         int advance = 0;
//         for(int i = num1.size()-1;i>=0;i--){
//             int c1 = num1[i]-'0';
//             string cur_res;
//             for(int j = num2.size()-1;j>=0;j--){
//                 int c2 = num2[j] - '0';
//                 int multi_res = c1*c2+advance;
//                 cur_res = to_string(multi_res%10)+cur_res;
//                 advance = multi_res / 10; 
//             }
//             if(advance){
//                 cur_res=to_string(advance)+cur_res;
//                 advance = 0;
//             }
                
//             for(int idx = 0;idx<degree;idx++)
//                 cur_res +='0';
//             degree++;
//             res = add(res,cur_res);
//         }
//         return res;
//     }
// 优化竖式,乘数 num1 位数为 MM，被乘数 num2 位数为 NN， num1 x num2 结果 res 最大总位数为 M+N
// num1[i] x num2[j] 的结果为 tmp(位数为两位，"0x","xy"的形式)，其第一位位于 res[i+j]，第二位位于 res[i+j+1]。
    string multiply(string num1, string num2) {
        vector<int> res(num1.size()+num2.size(),0);
        for(int i=num1.size()-1;i>=0;i--){
            int c1= num1[i]-'0';
            for(int j=num2.size()-1;j>= 0; j--){
                int c2= num2[j]-'0';
                int sum = c1*c2+res[i+j+1];
                res[i+j+1] = sum % 10; 
                res[i+j] += sum / 10; 
            }
        }
        int i = 0;
        string ret;
        while(i<res.size()&&res[i]==0)
            i++;
        if(i == res.size())
            return "0";
        for(;i<res.size();i++)
            ret+=to_string(res[i]);
        return ret;
    }

};
// int main(){
//     Solution().multiply("0","0");
// }
// @lc code=end

