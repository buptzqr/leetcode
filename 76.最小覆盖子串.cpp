/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        //滑动窗口，先扩展右边界，直到覆盖子串，然后向右移动左边界
        // 直到不能覆盖子串，此时再扩展右边界，如此往复
        string res=s;
        unordered_map<char,int> t_map;
        int count = 0;
        for(auto e:t){
            t_map[e]++;
            count++;
        }
        int l = 0;
        int r = 0;
        int flag = false;
        while(r<s.size()){
            if(t_map.find(s[r])!=t_map.end()){
                if(t_map[s[r]]>0)
                    count --;
                t_map[s[r]]--;
                while(count==0){
                    flag = true;
                    if(res.size()>r-l+1)
                        res = string(s,l,r-l+1);
                    if(t_map.find(s[l])!=t_map.end()){
                        if(t_map[s[l]]>=0)
                            count++;
                        t_map[s[l]]++;
                    }
                    l++;
                }
            }
            r++;
        }
    return flag?res:"";
         
    }
};
// int main(){
//     Solution().minWindow("ADOBECODEBANC","ABC");
// }
// @lc code=end

