/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode *root)
    {
        // 层序遍历，每次检查一层的元素是否满足就好
        if (!root)
            return true;
        vector<TreeNode *> cur;
        cur.push_back(root);
        while (cur.size())
        {
            vector<TreeNode *> vec_val; //记录当前层节点，包括null节点
            vector<TreeNode *> next;    //记录下一层非空节点
            for (auto e : cur)
            {
                vec_val.push_back(e->left);
                vec_val.push_back(e->right);
                if (e->left)
                    next.push_back(e->left);
                if (e->right)
                    next.push_back(e->right);
            }
            auto l = 0;
            auto r = vec_val.size() - 1;
            while (l <= r)
            {
                if (!vec_val[l] && vec_val[r])
                    return false;
                if (vec_val[l] && !vec_val[r])
                    return false;
                if (vec_val[l] && vec_val[r] && vec_val[l]->val != vec_val[r]->val)
                    return false;
                l++;
                r--;
            }
            cur = next;
        }
        return true;
    }
    /*这个递归的方法也太强了，如何判断两棵树镜像对称，首先根节点值相同，其次其中一个的左子树和另一个
    的右子树镜像对称，右子树和两一个的左子树镜像对称
     bool check(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return check(root->left, root->right);
    }

    栈和递归也是密切相关的呀
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        stack<TreeNode*> tree({root->left, root->right});
        while (!tree.empty()) {
            auto left = tree.top();
            tree.pop();
            auto right = tree.top();
            tree.pop();

            if (left == right) continue;
            if (!left || !right || left->val != right->val)
                return false;

            tree.push(left->left);
            tree.push(right->right);
            tree.push(left->right);
            tree.push(right->left);
        }
        return true;
    }
    */
};
// @lc code=end
