/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        //层序遍历，每一层的最右面的元素，vec_queue只存储一层的节点，tmp用来存储vec_queue存储节点的下一层节点
        if(!root)
            return vector<int>();
        vector<TreeNode*> vec_queue;
        vector<int> res;
        vec_queue.push_back(root);
        vector<TreeNode *> tmp;
        while (!vec_queue.empty())
        {
            auto node = vec_queue.front();
            vec_queue.erase(vec_queue.begin());
            if(node->left)
                tmp.push_back(node->left);
            if(node->right)
                tmp.push_back(node->right);
            if(vec_queue.size()==0){
                res.push_back(node->val);
                vec_queue = tmp;
                tmp.clear();
            }
        }
        return res;
    }
};
// @lc code=end

