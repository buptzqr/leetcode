/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
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
class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        //记住有个reverse函数就行,必须得是BidirectionalIterator
        queue<pair<TreeNode *, int>> q;
        vector<vector<int>> res;
        while (!root)
            return res;
        q.push(make_pair(root, 0));
        while (!q.empty())
        {
            pair<TreeNode *, int> elem = q.front();
            int level = elem.second;
            TreeNode *node = elem.first;
            q.pop();
            if (elem.second == res.size())
                res.push_back(vector<int>());

            res[level].push_back(node->val);
            if (elem.first->left)
                q.push(make_pair(elem.first->left, level + 1));
            if (elem.first->right)
                q.push(make_pair(elem.first->right, level + 1));
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
