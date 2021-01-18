/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
// #include<iostream>
// #include<stack>
// using namespace std;
//写的什么代码，傻逼透了
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        s.push(string("/"));
        while (path.size())
        {
            string c_path = find_content(path);
            if (c_path ==string(".."))
                if(s.top()==string("/"))
                    continue;
                else 
                    s.pop();
            else if (c_path ==string("."))
                    continue;
            else
                if(c_path.size())
                    s.push(c_path);
        }
        string ret = "";
        if(s.size()==1)
            return string("/");
        while (!s.empty())
        {
            if(s.top()!=string("/")){
                ret.insert(0,s.top());
                ret.insert(0, "/");
            }
            s.pop();
        }
        return ret;
    }

private:
    string find_content(string & str){
        int found1 = str.find('/');
        if(found1!=string::npos){
            int found2 = str.find('/', found1 + 1);
            if(found2!=string::npos){
                if(found2==found1+1){
                    str = str.substr(found2, string::npos);
                    return string("");
                }
                string ret = str.substr(found1 + 1, found2 - found1-1);
                str = str.substr(found2, string::npos);
                return ret;
            }
            if(found1!=str.size()-1){
                string ret =str.substr(found1 + 1, string::npos);
                str = string("");
                return ret;
            }
            else{
                str = string("");
                return string("");
            }
        }
        return string("");
}
};
/*
class Solution {
public:
    string simplifyPath(string path) {

        vector<string> stack;
        for(int start = 1, i = 1; i <= path.size(); i ++)
            if(i == path.size() || path[i] == '/'){
                string f = path.substr(start, i - start);
                if(f.size()){
                    if(f == ".."){
                        if(stack.size()) stack.pop_back();
                    }
                    else if(f != ".") stack.push_back(f);
                }
                start = i + 1;
            }

        string res = "";
        for(string e: stack)
            res += "/" + e;
        return res == "" ? "/" : res;
    }
};
*/
// int main(){
//     string s = "/a/../../b/../c//.//";
//     string ret=Solution().simplifyPath(s);
//     cout << "hello" << endl;
// }
// @lc code=end

