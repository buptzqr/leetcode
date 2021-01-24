/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.*/
// #include<iostream>
// #include<unordered_map>
// using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    // 用f(o)代表选择o节点，偷盗以o为根树的最高偷盗金额
    // g(o)代表不选择o节点的，偷盗以o为根树的最高偷盗金额
    // 则对当前节点f(o)=o->val+g(o->left)+g(o->right)
    // g(o) = max(f(o->right),g(o->right))+max(f(o->right),g(o->right))
    // 最终返回max(f(o),g(o))即可
    // 动态规划是自底向上解决问题，树形结构中后续后续遍历满足这种方式
    // 还有一个点就是对待一个棵树如果节点有重复元素，但是想构建map的话
    // 不妨就用这个节点的地址做key（NULL也可以当作key）
    // 这道题用记忆化搜索思路上会更简单
    unordered_map<TreeNode*,int> f;
    unordered_map<TreeNode*,int> g;   
    void postorderTraverse(TreeNode* root){
        if(!root)
            return;
        postorderTraverse(root->left);
        postorderTraverse(root->right);
        f[root] = root->val+g[root->left]+g[root->right];
        g[root] = max(f[root->left],g[root->left])+max(f[root->right],g[root->right]);
    }
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        postorderTraverse(root);
        return max(f[root],g[root]);
        
    }
};
// @lc code=end

