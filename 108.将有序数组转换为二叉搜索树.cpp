/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //这个就是1382的简单版本了，直接建树，将中间节点作为根节点，将vector的左半部分构建左子树，将vector的右半部分构建右子树
        if(!nums.size())
            return NULL;
        int mid = nums.size()/ 2;
        TreeNode * node = new TreeNode(nums[mid]);
        vector<int> leftVec(nums.begin(), nums.begin() + mid);//这里有c++一个点,非常量引用不能指向临时对象，常量型引用可以：原因是如果你给函数传递一个非常量型的引用，意思是说你要获得这个函数对这个引用操作的结果，而对于临时变量，程序员后续是无法获取这个变量的，于是编译器怒了，你一开始说想要结果，结果我算一通给你结果，你又扔了，这不是逗我吗，同时C++的标准 为了防止给常量或临时变量（只有瞬间的生命周期）赋值(易产生bug)，只许使用const引用之
        node->left = sortedArrayToBST(leftVec);
        vector<int> rightVec(nums.begin() + mid + 1, nums.end());
        node->right = sortedArrayToBST(rightVec);
        return node;
    }
};
// @lc code=end

