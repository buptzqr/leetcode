/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    // 这个应该是n*logn的时间复杂度
    // vector<vector<int>> pathSum(TreeNode* root, int sum) {
        //递归的想法比较容易，但是超时了
        // if(!root)
        //     return vector<vector<int>>();
        // else if(!root->left&&!root->right&&root->val == sum){
        //     return vector<vector<int>>(1,vector<int>(1,root->val));             
        // }
        // else{
        //     vector<vector<int>> res;
        //     if (root->left)
        //         if(pathSum(root->left,sum-root->val).size())
        //             for(auto e:pathSum(root->left,sum-root->val)){
        //                 e.insert(e.begin(), root->val);
        //                 res.push_back(e);
        //             }
        //     if (root->right)
        //         if(pathSum(root->right,sum-root->val).size())
        //             for(auto e:pathSum(root->right,sum-root->val)){
        //                 e.insert(e.begin(), root->val);
        //                 res.push_back(e);
        //             }
        //     return res;
        // }
    // }
    //这个时间复杂度应该是o(n)
    //回溯
    public:
    vector<vector<int>> ret;
    vector<int> path;

    void dfs(TreeNode* root, int sum) {
        if (root == nullptr) {
            return;
        }
        path.emplace_back(root->val);
        sum -= root->val;
        if (root->left == nullptr && root->right == nullptr && sum == 0) {
            ret.emplace_back(path);
        }
        dfs(root->left, sum);
        dfs(root->right, sum);
        path.pop_back();//我觉得最难的一点在这里，因为使用的是引用，所以返回上一层的时候你应该把path还原
        //还是要搞清楚这个函数的意义，这个函数的意义是进行深度优先遍历，如果有满足条件的路径，就加入结果中，path保存的是
        //到达该节点（root）前的路径，所以返回的时候应该把push进去的节点给去掉
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return ret;
    }

};
// @lc code=end

