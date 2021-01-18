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
    //这个函数就是从nums里面取长度为n的子集
    void solution(string nums,int idx,int n,string& before_str,vector<string>& res){
        if(before_str.size()==n){
            res.push_back(before_str);
            return;
        }
        if(n-before_str.size()> nums.size()-idx+1)
            return;
        solution(nums, idx + 1, n,before_str, res);
        before_str.push_back(nums[idx]);
        solution(nums, idx + 1, n,before_str, res);
        before_str.pop_back();
    }
    vector<string> readBinaryWatch(int num) {
        string high = "0123";
        string low = "012345";
        vector<string> high_vec;
        vector<string> low_vec;
        vector<string> res;
        string high_res;
        string low_res;
        for (int i = 0; i <= 4&&i<=num; i++)
        {
            high_vec.clear();
            low_vec.clear();
            high_res.clear();
            low_res.clear();
            solution(high, 0, i, high_res, high_vec);
            solution(low, 0, num-i, low_res, low_vec);
            if(high_vec.size()&&low_vec.size()){

                vector<int> high_ ;
                vector<int> low_;
                for (auto str : high_vec){
                    int high_num = 0;
                    for (auto c : str)
                        high_num += pow(2, c - '0');
                    if(high_num>=0&&high_num<=11)
                        high_.push_back(high_num);
                }
                for (auto str : low_vec){
                    int low_num = 0;
                    for (auto c : str)
                        low_num += pow(2, c - '0');
                    if(low_num>=0&&low_num<=59)
                        low_.push_back(low_num);
                }
                for(auto h:high_){
                    for(auto l:low_){
                        char buff[3];
                        snprintf(buff, sizeof(buff), "%02d", l);
                        res.push_back(to_string(h) + ":" + string(buff));

                    }
                }
            }
        }
        return res;
    }
};
int main(){
    vector<string> res = Solution().readBinaryWatch(1);
    for(auto e:res)
        cout << e << endl;
    return 0;
}

// @lc code=end

