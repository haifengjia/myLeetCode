/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;
        bool temp = (get_height(root->left) - get_height(root->right) < 2) && (get_height(root->left) - get_height(root->right) > -2);
        return temp && isBalanced(root->left) && isBalanced(root->right);
    }

    int get_height(TreeNode *node)
    {
        if (!node)
            return -1;
        return max(get_height(node->left), get_height(node->right)) + 1;
    }
};
// @lc code=end
