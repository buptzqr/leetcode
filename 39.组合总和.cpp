/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
//这个题目要保持不会重复的做法就是不走回头路
#include<vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> res;

public:
//index记录当前访问到的candidates元素的下标,每次选取元素只能从index及以后的元素中选择
    // void solve(vector<int>& candidates, int target,int index,vector<int>&rec){
    //     if(target==0){
    //         res.push_back(rec);
    //         return;
    //     }
    //     for(int i=index; i<candidates.size();i++){
    //         if(target>=candidates[i]){
    //             rec.push_back(candidates[i]);
    //             solve(candidates, target - candidates[i], i, rec);
    //             rec.pop_back();
    //         }
    //     }
    // }
    // vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    //     vector<int> rec;
    //     solve(candidates, target, 0, rec);
    //     return res;
    // }
    void dfs(vector<int>& path,vector<int>& candidates,int idx,int target){
        if(target==0){
            res.push_back(path);
            return;
        }
        for(int i = idx;i<candidates.size();i++){
            if(candidates[i]<=target){
                path.push_back(candidates[i]);
                dfs(path,candidates,i,target-candidates[i]);
                path.pop_back();

            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        dfs(path,candidates,0,target);
        return res;
    }
};
int main(){
    vector<int> vec ={2,3,6,7};
    vector<vector<int>> res =Solution().combinationSum(vec,7);
    return 0;
}
// @lc code=end

