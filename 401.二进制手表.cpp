/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class Solution
{

public:
    void dfs(vector<int>& res,vector<int>& path,int target,vector<bool>& visited,int idx){
        if(target==0){
            int ret = 0;
            for(auto e:path)
                ret+=pow(2,e);
            res.push_back(ret);
            return;
        }
        for(int i=idx;i<visited.size();i++){
            if(!visited[i]){
                visited[i] = true;
                path.push_back(i);
                dfs(res,path,target-1,visited,i+1);
                visited[i] = false;
                path.pop_back();
            }
        }
    }
    vector<string> readBinaryWatch(int num) {
        // 就是一个组合问题
        vector<string> res;
        for(int i = 0; i < 4&&i<=num;i++){
            if(num-i>=6)
                continue;                  
            vector<int> h;
            vector<int> h_path;
            vector<int> m;      
            vector<int> m_path;
            vector<bool> h_visited(4,false);
            vector<bool> m_visited(6,false);
            dfs(h,h_path,i,h_visited,0);
            dfs(m,m_path,num-i,m_visited,0);
            for(auto hour:h){
                for(auto minute:m){
                    if(hour<=11&&minute<=59){
                        string r;
                        r+=to_string(hour);
                        r+=':';
                        if(minute<=9){
                            r+='0';
                        }
                        r+=to_string(minute);
                        res.push_back(r);
                    }
                }
            }
        }
        return res;

    }
    // 一种特别简单的方法，直接遍历
    /*
      vector<string> readBinaryWatch(int num) {
        vector<string> res;
        //直接遍历  0:00 -> 12:00   每个时间有多少1
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                if (count1(i) + count1(j) == num) {
                    res.push_back(to_string(i)+":"+
                                  (j < 10 ? "0"+to_string(j) : to_string(j)));
                }
            }
        }
        return res;
    }
    //计算二进制中1的个数
    int count1(int n) {
        int res = 0;
        while (n != 0) {
            n = n & (n - 1);
            res++;
        }
        return res;
    }
    */
};
// int main(){
//     vector<string> res = Solution().readBinaryWatch(6);
//     for(auto e:res)
//         cout << e << endl;
//     return 0;
// }

// @lc code=end

