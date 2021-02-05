/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
#include<iostream>
#include<string.h>
using namespace std;
class Trie {
public:
    /** Initialize your data structure here. */
    bool is_end;
    Trie* next[26];//精髓就是用指针数组取值是否为空来表示是否有该元素
    Trie() {
        is_end= false;
        memset(next,0,sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for(auto c:word){
            if(!node->next[c-'a']){
                node->next[c-'a'] = new Trie();
            }
            node = node->next[c-'a'];
        }
        node->is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node= this;
        for(auto c:word){
            if(!node->next[c-'a'])
                return false;
            node = node->next[c-'a'];//这个地方要小心
        }
        return node->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node= this;
        for(auto c:prefix){
            if(!node->next[c-'a'])
                return false;
            node = node->next[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

