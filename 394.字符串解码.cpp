/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
// 使用pair<num,string>来记录数字前的字符和数字
// 当 c 为数字时，将数字字符转化为数字 multi，用于后续倍数计算；
// 当 c 为字母时，在 res 尾部添加 c；
// 当 c 为 [ 时，将当前 multi 和 res 入栈，并分别置空置 0：
//      记录此 [ 前的临时结果 res 至栈，用于发现对应 ] 后的拼接操作；
//      记录此 [ 前的倍数 multi 至栈，用于发现对应 ] 后，获取 multi × [...] 字符串。
//      进入到新 [ 后，res 和 multi 重新记录。
// 当 c 为 ] 时，stack 出栈，拼接字符串 res = last_res + cur_multi * res，其中:
// last_res是上个 [ 到当前 [ 的字符串，例如 "3[a2[c]]" 中的 a；
// cur_multi是当前 [ 到 ] 内字符串的重复倍数，例如 "3[a2[c]]" 中的 2。

        stack<pair<int,string>> ss;
        string res;
        int num=0;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i]))
                num= num*10+(s[i]-'0');
            if(isalpha(s[i]))
                res+=s[i];
            if(s[i]=='['){
                //入栈，同时空置
                ss.push(make_pair(num,res));
                res="";
                num=0;
            }
            if(s[i]==']'){
                int j = ss.top().first;
                string befor_string = ss.top().second;
                ss.pop();
                string tmp = res;
                while(j>1){
                    res +=tmp;
                    j--;
                }
                res = befor_string + res;
            }
        }
        return res;
    }
};
// int main(){
//     Solution().decodeString("100[leetcode]");
//     return 0;
// }
// @lc code=end

