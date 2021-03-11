/*
 * @lc app=leetcode.cn id=815 lang=cpp
 *
 * [815] 公交路线
 */

// @lc code=start
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool ifIntersect(vector<int>& a,vector<int>& b){
        int i = 0;
        int j = 0;
        // 双指针,假定传入的是单调递增的数组
        while(i<a.size()&&j<b.size()){
            if(a[i] == b[j])
                return true;
            else if(a[i] > b[j])
                j++;
            else 
                i++;
        }
        return false;
    }
    bool ifExist(vector<int>& a,int target){
        int l =0;
        int r =a.size()-1;
        while(l<r){
            int mid = (l+r)>>1;
            if(a[mid]==target)
                return true;
            else if(a[mid]>target)
                r = mid - 1;
            else
                l = mid + 1; 
        }
        return a[l] == target;
    }
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // 这道题关键是如何建图，把整个公交路线看成是一个节点
        // 然后建图
        if(source == target)
            return 0;
        vector<vector<int>> graph(routes.size(),vector<int>());
        // 排序
        for(auto& route:routes)
            sort(route.begin(),route.end());
        for(int i = 0 ;i<routes.size();i++){
            for(int j = i+1;j<routes.size();j++){
                if(ifIntersect(routes[i],routes[j])){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int ends[500] = {0};
        bool visited[500] = {false};
        vector<int> q;
        // 寻找source和end节点
        for(int i = 0;i<routes.size();i++){
            if(ifExist(routes[i],source)){
                q.push_back(i);
                visited[i] = true;
            }
            if(ifExist(routes[i],target))
                ends[i] = 1;
        }
        int res = 1;
        // bfs
        while(!q.empty()){
            vector<int> tmp;
            while(!q.empty()){
                int station = q.back();
                q.pop_back();
                if(ends[station])
                    return res;
                for(auto e:graph[station])
                    if(!visited[e]){
                        visited[e] = true;
                        tmp.push_back(e);
                    } 
            }
            q = tmp;
            res++;
        }
        return -1;
    }
};
// int main(){
//     vector<vector<int>> routes = {{7,12},{4,5,15},{6},{15,19},{9,12,13}};
//     int res = Solution().numBusesToDestination(routes,15,12);
//     return res;
// }
// @lc code=end

