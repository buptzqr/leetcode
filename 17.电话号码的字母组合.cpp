/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
// #include<iostream>
// #include<vector>
// using namespace std;
//两个string的构造函数，以及这个insert函数得看一下
class Solution
{
public:
    const string digitMap[8] = {
        "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"};
    // 递归
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if(!digits.size())
            return vector<string>();
        vector<string> res_before=letterCombinations(string(digits, 1));
        
        for (auto e : digitMap[digits[0] - '0' - 2])
        {
            if(res_before.size())
                for(auto r:res_before)
                    res.push_back(r.insert(0, 1, e));
            else
                res.push_back(string(1, e));
        }
        return res;
    }
};
// int main(){
//     string s = "23";
//     vector<string> res = Solution().letterCombinations(s);
//     for(auto e:res)
//         cout << e<<endl;
// }
// @lc code=end

