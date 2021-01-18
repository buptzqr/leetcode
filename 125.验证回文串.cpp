/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
// 对撞指针还有就是判断数字字母那几个函数
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        if (!s.size())
            return true;
        int start = 0;
        int end = s.size() - 1;
        while (start < end)
        {
            if (isdigit(s[start]) || isalpha(s[start]))
            {
                if (isdigit(s[end]) || isalpha(s[end]))
                {
                    if (s[end] == s[start])
                    {
                        start++;
                        end--;
                    }
                    else if (isalpha(s[end]) && isalpha(s[start]) && abs(s[end] - s[start]) == 'a' - 'A')
                    {
                        start++;
                        end--;
                    }
                    else
                        return false;
                }
                else
                    end--;
            }
            else
                start++;
        }
        return true;
    }
    /*
    bool isPalindrome(string s) {
        int n = s.size(), l = 0, r = n - 1;
        while (l < r) {
            while (l < r && !isalnum(s[l])) {
                l++;
            }
            while (l < r && !isalnum(s[r])) {
                r--;
            }
            if (tolower(s[l++]) != tolower(s[r--])) {
                return false;
            }
        }
        return true;
    }*/
};
// int main()
// {
//     string s = "0P";
//     Solution().isPalindrome(s);
// }
// @lc code=end
