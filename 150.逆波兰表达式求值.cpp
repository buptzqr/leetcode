/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
// #include<iostream>
// #include<vector>
// #include<stack>
// using namespace std;
//string 比较是否相同使用compare，string可以使用s.c_str()转成c类型字符串返回char*
// 然后使用strcmp(s1,s2)函数比较，这俩函数如果相同的话返回都是0
// 还有就是stoi函数
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(!tokens.size())
            return 0;
        stack<int> s;
        for(auto e:tokens) {
            if(!e.compare(string("+"))){
                int a1= s.top();
                s.pop();
                int a2= s.top();
                s.pop();
                int res = a1+a2;
                s.push(res);                
            }
            else if(!e.compare(string("-"))){
                int a1= s.top();
                s.pop();
                int a2= s.top();
                s.pop();
                int res = a2-a1;
                s.push(res);                
            }
            else if(!e.compare(string("*"))){
                int a1= s.top();
                s.pop();
                int a2= s.top();
                s.pop();
                int res = a1*a2;
                s.push(res);                
            }
            else if(!e.compare(string("/"))){
                int a1= s.top();
                s.pop();
                int a2= s.top();
                s.pop();
                int res = a2/a1;
                s.push(res);                
            }
            else
                s.push(stoi(e));
        }
        return s.top();
    }
};
// int main(){
//     string input[] ={"2","1","+","3","*"};
//     vector<string> i(input,input+5);
//     int res = Solution().evalRPN(i);
//     cout<<res<<endl;
// }
// @lc code=end

