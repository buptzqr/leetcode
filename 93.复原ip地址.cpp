/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    // cur代表目前存储的ip字段,idx代表当前要访问元素的idx
    void dfs(vector<string>& res,vector<string>& cur,int idx,string& s){
       if(cur.size()==4&&idx==s.size()){
           string s;
           for(auto e:cur){
               s += e;
               s += ".";
           }
           s.pop_back();
           res.push_back(s);
           return;
       }
       if((4-cur.size())*3+(3-cur.back().size())>=s.size()-idx){
           //对于0特殊处理,如果开头是0,或者当前字段已经填满了
           if((cur.back().size()==1&& cur.back()[0]=='0')||cur.back().size()==3){
               if(cur.size()<4){
                    cur.push_back(string(1,s[idx]));
                    dfs(res, cur, idx + 1, s);
                    cur.pop_back();
               }
           }
           else{
               int val = stoi((cur.back() + string(1, s[idx])).c_str());
               if (val >= 0 && val <= 255)
               {
                    cur.back().push_back(s[idx]);
                    dfs(res, cur, idx + 1, s);
                    cur.back().pop_back();
               }
               if(cur.size()<4){
                    cur.push_back(string(1,s[idx]));
                    dfs(res, cur, idx + 1, s);
                    cur.pop_back();   
               }
           }
       }
    }
    vector<string> restoreIpAddresses(string s) {
        //dfs，中止条件是
        if(s.size()<4)
            return vector<string>();
        vector<string> cur;
        vector<string> res;
        cur.push_back(string(1, s[0]));
        dfs(res, cur, 1, s);
        return res;
    }
};
// int main(){
//     string s = "25525511135";
//     vector<string> res = Solution().restoreIpAddresses(s);
//     cout << "hello" << endl;
// }
// @lc code=end

