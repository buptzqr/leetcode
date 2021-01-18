/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> binaryTreePaths(TreeNode* root) {
        // if(!root)
        //     return vector<string>();
        // else if(!root->right&&!root->left)
        //     return vector<string>(1, to_string(root->val));
        // else{
        //     vector<string> res;
        //     vector<string> left_path = binaryTreePaths(root->left);
        //     vector<string> right_path = binaryTreePaths(root->right);
        //     string ret_left_path =  to_string(root->val);
        //     string ret_right_path =  to_string(root->val);
        //     for(auto e:left_path)
        //         res.push_back(ret_left_path+"->"+e);
        //     for(auto e:right_path)
        //         res.push_back(ret_right_path+"->"+e);
        //     return res;

        //当然用栈/队列也可以实现,层序遍历,每个节点存储到达他的路径，这次存储方式是string以前有用vector的
        //从内存消耗和运行速度来看，显著快于递归
        if(!root)
            return vector<string>();
        vector<string> res;
        stack<pair<TreeNode *, string>> s;
        s.push(make_pair(root, to_string(root->val)));
        while(!s.empty()){
            TreeNode *node = s.top().first;
            string path = s.top().second;
            s.pop();
            if(!node->left&&!node->right)
                res.push_back(path);
            if(node->left)
                s.push(make_pair(node->left,path+"->"+to_string(node->left->val)));
            if(node->right)
                s.push(make_pair(node->right,path+"->"+to_string(node->right->val)));
            
        }
        return res;
    }
};
// @lc code=end

