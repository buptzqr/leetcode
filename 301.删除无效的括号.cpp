/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
// 算出需要删除多少个左括号，多少个右括号
// 对于当前遇到的字符，如果是左括号，则可以删除或者不删除
// 对于当前遇到的字符，如果是右括号，如果左括号总数大于右括号总数，
//                      则可以删除或不删除，否则一定得删除
// 对于当前遇到的字符，如果是其他字符，不做处理
    int l;//需要删除的左括号数目
    int r;//需要删除的右括号数目
    vector<string> res;//用来保存结果
    void dfs(string& s,string path,int idx,int cnt,int l,int r){
        // idx表示当前访问的字符，cnt 表示当前'('-')'
        // l表示还有多少个需要减的(
        // r表示还有多少个需要减的)
        if(idx == s.size()){
            if(cnt == 0)
                res.push_back(path);
            return;
        }
        if(s[idx]=='('){
            // 删除若干(
            // 统计有多少个连续的(,
            int num = 0;
            while(s[idx+num]=='(')
                num++;
            for(int i = num;i>=0;i--){
                if(l-i>=0){//i表示要删除的(的数目
                    dfs(s,path,idx+num,cnt+(num-i),l-i,r);
                }
                path+='(';
            }
        }
        else if(s[idx]==')'){
            // 删除若干右括号
            int num = 0;
            while(s[idx+num]==')')
                num++;
            for(int i=num;i>=0;i--){
                if(cnt>=num-i&&r-i>=0){//i表示要删除的)的数目
                    dfs(s,path,idx+num,cnt-(num-i),l,r-i);
                }
                path += ')';
                    
            }
        }
        else{
            path += s[idx];
            dfs(s,path,idx+1,cnt,l,r);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        l = 0;
        r = 0;
        for(auto c:s)
            if(c == '(')
                l++;
            else if(c == ')'){
                if(l>0) 
                    l--;
                else 
                    r++;
            }
        dfs(s,"",0,0,l,r);        
        return res;
    }
};
// int main(){
//     Solution().removeInvalidParentheses("()())()");
// }
// @lc code=end

