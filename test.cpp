#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
    public:
    //01背包问题，记忆化搜索
    vector<vector<int>> memo;
    //尝试从[0,idx]的物品中找容量小于cap的最大价值的物品
    int findBestValue(int idx,vector<int>& w,vector<int>& v,int cap){
        if(idx<0||cap<0)
            return 0;
        
    }
    int packetProblem(vector<int> w, vector<int> v, int cap){
        memo = vector<vector<int>>(w.size(),vector<int>(cap+1,-1));
    }
};
int main(){
}