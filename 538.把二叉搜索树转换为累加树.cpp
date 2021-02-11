/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 */

// @lc code=start
/**
 * Definition for a binary tree node.*/
#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
//二叉搜索树反向中序遍历，二叉树的一个重要性质就是进行中序遍历是一个递增的序列
// 所以进行反向中序遍历得到的就是一个递减的序列，然后用一个记录值
// 依次累加元素，并赋给当前值
// 时间复杂度是o(n),空间复杂度是o(logn)
// 我真懒得看morris了
    int res;
    void inorder_traverse(TreeNode* root){
        //右中左
        if(!root)
            return;
        inorder_traverse(root->right);
        res+= root->val;
        root->val = res;
        inorder_traverse(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        res=0;
        inorder_traverse(root);
        return root;
    }

};
// @lc code=end

