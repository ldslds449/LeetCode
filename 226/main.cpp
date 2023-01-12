/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 */

// @lc code=start

#include <algorithm>

using namespace std;

// Definition for a binary tree node.
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
    void helper(TreeNode* root){
        if(root == nullptr) return;
        swap(root->left, root->right);
        helper(root->left);
        helper(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};
// @lc code=end

