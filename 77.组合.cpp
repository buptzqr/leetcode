/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    //visited代表下一次需要在那些数中寻找组合数，k代表需要寻找的组合数的数目
    vector<vector<int>> combine(int k,vector<int> visited){
        if(k>visited.size())
            return vector<vector<int>>();
        vector<vector<int>> res;
        if(k==1){
            for(auto e:visited)
                res.push_back(vector<int>(1, e));
            return res;
        }
        for (auto itr=visited.begin();itr!=visited.end();)
        {
            int val = *itr;
            itr=visited.erase(itr);
            k--;
            vector<vector<int>> res_after = combine(k, visited);
            if(res_after.size())
                for(auto e:res_after){
                    e.push_back(val);
                    res.push_back(e);
                }
            k++;
        }
        return res;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> visited;
        for (int i = 1; i <= n;i++)
            visited.push_back(i);
        return combine(k, visited);
    }
    //上面的方法相当于是从后往前的一种推，波神的思路是从前往后，感觉这种从前往后的思路连贯性更好，以后用这种思路吧
    /*
    private:
        vector<vector<int>> res;
    public:
    //求解c(n,k),start代表本轮开始搜索的元素，res代码之前已经搜索到的组合
    void combine(int n,int k,int start,vector<int>& rec){
        if(rec.size()==k){
            res.push_back(rec);
            return;
        }
        //循环结束条件做了剪枝
        for(int i=start;i<=n-(k-rec.size())+1;i++){
            vec.push_back(i);
            combine(n,k,i+1,rec);
            rec.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        if(n<=0||k<=0||k>n)
            return res;
        res.clear();
        vector<int> rec;
        combine(n,k,1,rec);
        return res;
    }
    */
};
// @lc code=end

