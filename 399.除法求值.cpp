/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

// @lc code=start
#include<vector>
#include<unordered_map>
#include<iostream>
#include<queue>
using namespace std;
class Solution {
public:
    struct Node{
        double val;
        string key;
        Node(string k,double v):val(v),key(k){}
    };
    double bfs(string e,string target,unordered_map<string,bool> book,unordered_map<string,vector<Node*>>& table){
        queue<pair<string,double>> q;
        q.push(make_pair(e,1.0));
        while(!q.empty()){
            double num = q.front().second;
            string str = q.front().first;
            q.pop();
            if(str == target)
                return num;
            for(auto e:table[str]){
                if(!book[e->key]){
                    book[e->key]= true;
                    q.push(make_pair(e->key,num*e->val));
                }     
            }
        }
        return -1.0;
    }
//建图然后bfs或者dfs均可
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<Node*>> table;
        unordered_map<string,bool> book;
        for(int i=0;i<equations.size();i++){
            book[equations[i][0]]=false;
            book[equations[i][1]]=false;
            table[equations[i][0]].push_back(new Node(equations[i][0],1));
            table[equations[i][0]].push_back(new Node(equations[i][1],values[i]));
            table[equations[i][1]].push_back(new Node(equations[i][1],1));
            table[equations[i][1]].push_back(new Node(equations[i][0],1.0/values[i]));   
        }
        vector<double>res;
        // bfs
        for(auto e:queries){
            if(table.find(e[0])==table.end()||table.find(e[1])==table.end())
                res.push_back(-1.0);
            else
                res.push_back(bfs(e[0],e[1],book,table));
        }
        return res;
    }
};

// @lc code=end

