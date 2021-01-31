#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
    public:
    //01背包问题，记忆化搜索
    // vector<vector<int>> memo;
    // //尝试从[0,idx]的物品中找容量小于cap的最大价值的物品
    // int findBestValue(int idx,vector<int>& w,vector<int>& v,int cap){
    //     if(idx<0||cap<0)
    //         return 0;
    //     if(memo[idx][cap]!=-1)
    //         return memo[idx][cap];
    //     int res =findBestValue(idx-1,w,v,cap);
    //     if(cap>w[idx])
    //         res =max(res,v[idx]+findBestValue(idx-1,w,v,cap-w[idx]));
    //     memo[idx][cap] = res;
    //     return res;
    // }
    // int packetProblem(vector<int> w, vector<int> v, int cap){
    //     memo = vector<vector<int>>(w.size(),vector<int>(cap+1,-1));
    //     return findBestValue(v.size(),w,v,cap);
    // }
    //动态规划
    int packetProblem(vector<int> w, vector<int> v, int cap){
        vector<int> memo(cap+1,0);
        //memo[i]代表考虑[0,j]号物品，找这些物品组合（满足容量小于i），的最大价值(j)在下面代码中体现
        for(int i=0;i<=cap;i++)
            memo[i] = w[0]<=i?v[0]:0;
        for(int i=1;i<w.size();i++)
            for(int j=cap;j>=w[i];j--)
                memo[j] = max(memo[j],v[i]+memo[j-w[i]]);
        return memo[cap];
    }

};
int main(){
}