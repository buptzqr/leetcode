/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

// @lc code=start
/**
 * Definition for a binary tree node.*/
#include<iostream>
using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:

    // 令树中每个节点的depth值等于他的左子树深度加上右子树深度之和，
    // depth最大值即为直径
    int depth(TreeNode* root,int& res){
        if(!root)
            return 0;
        int l_depth=depth(root->left,res);
        int r_depth=depth(root->right,res);
        res = max(res,l_depth+r_depth);
        return max(l_depth,r_depth)+1;
    }
    // 不用dfs直接在求depth的时候顺便求maxdepth
    // void dfs(TreeNode* root,int& res){
    //     if(!root)
    //         return;
    //     res=max(res,depth(root->left)+depth(root->right));
    //     dfs(root->left,res);
    //     dfs(root->right,res);
    
    // }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int res=0;
        depth(root,res);
        return res;        
    }
};
// @lc code=end

