/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        // 这个题得思路就是既保存节点又保存节点得层数
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
        return res;
    }
};
// @lc code=end
