/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node*/
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
//这个思路很简单
    // TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    //     if(preorder.size()==0)
    //         return NULL;
    //     TreeNode* root = new TreeNode(preorder[0]);
    //     auto itr = find(inorder.begin(),inorder.end(),preorder[0]);
    //     vector<int> left_inorder(inorder.begin(),itr);
    //     vector<int> right_inorder(itr+1,inorder.end());
    //     vector<int> left_preorder(preorder.begin()+1,preorder.begin()+left_inorder.size()+1);
    //     vector<int> right_preorder(preorder.begin()+left_inorder.size()+1,preorder.end());
    //     root->left = buildTree(left_preorder,left_inorder);
    //     root->right = buildTree(right_preorder,right_inorder);
    //     return root;
    // }
    // 这个版本就两点改进，用哈希加快查找速度，用参数代替vector从而节省空间
    public:
        unordered_map<int, int> hash;
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            for(int i = 0; i < inorder.size(); i++)
                hash[inorder[i]] = i;
            return build(preorder, inorder, 0, preorder.size() - 1, 0, preorder.size() - 1);
        }
        // @brief: 构建二叉树
        // @pram: preorder, inorder: 前序遍历与中序遍历
        //        pl, pr : 当前前序遍历的区间
        //        il, ir : 当前中序遍历的区间
        // @ret: 构建的根节点
        TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir)
        {
            if (pl > pr) return nullptr;
            TreeNode* root = new TreeNode(preorder[pl]);
            int k = hash[root->val]; // 根节点在中序遍历的位置
            root->left  = build(preorder, inorder,pl + 1,k + pl - il ,il, k - 1);
            root->right = build(preorder, inorder, k + pr - ir + 1,pr,k + 1, ir);
            return root;
        }

};
// @lc code=end

