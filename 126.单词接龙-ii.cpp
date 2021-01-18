/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// @lc code=start
// #include<iostream>
// #include<vector>
// #include<unordered_map>
// #include<queue>
// #include<limits.h>
// using namespace std;
class Solution {
public:
    unordered_map<string, int> str2id;//key是string，val是该string的id
    vector<string> id2str;
    int node_num = 0;
    vector<vector<int>> con_map;//记录各节点连接关系
    void addNode(string str){
        if(str2id.find(str)==str2id.end()){
            str2id[str] = node_num;
            id2str.push_back(str);
            con_map.push_back(vector<int>());
            node_num++;
        }
    }
    void addEdge(string str){
        addNode(str);
        int id1 = str2id[str];
        for (char& itr : str)//auto 其实是复制容器内的元素
        {
            char tmp = itr;
            itr = '*';
            addNode(str);
            int id2 = str2id[str];
            con_map[id1].push_back(id2);
            con_map[id2].push_back(id1);
            itr = tmp;
        }
    }
    //相比于127号问题，主要就是用queue来存储到达某个节点经过的路径是什么，其他没有什么变化
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for(auto e:wordList)
            addEdge(e);
        if(str2id.find(beginWord) == str2id.end())
            addEdge(beginWord);
        if(str2id.find(endWord)==str2id.end())
            return vector<vector<string>>();
        vector<vector<string>> res;
        vector<int> cost(node_num,INT_MAX);//如果cost[src]+1>cost[dst],说明dst已经被访问
        queue<vector<int>> q; //vector记录的是从beginWord到达当前节点的路径
        int end_idx = str2id[endWord];
        int begin_idx = str2id[beginWord];
        q.push(vector<int>{begin_idx});
        cost[begin_idx] = 0;
        while (!q.empty())
        {
            auto tmp = q.front();
            int last_idx = tmp.back();
            q.pop();
            if(last_idx == end_idx){
                vector<string> r;
                for (auto idx: tmp){
                    if(id2str[idx].find('*')==string::npos)
                        r.push_back(id2str[idx]);
                }
                res.push_back(r);
            }
            else{
                for(auto e:con_map[last_idx]){
                    if(cost[last_idx]+1<=cost[e]){//=完全就是为了让多条最短路都能到达endword
                        cost[e] = cost[last_idx] + 1;
                        vector<int> vec(tmp);
                        vec.push_back(e);
                        q.push(vec);
                    }
                }
            }
            
        }
        return res;
    }
};
// int main(){
//     string begin = "a";
//     string end="c";
//     string list[] = {"a","b","c"};
//     vector<string> vec_list(list,list+sizeof(list)/sizeof(list[0]));
//     Solution().findLadders(begin, end, vec_list);
// }
// @lc code=end

