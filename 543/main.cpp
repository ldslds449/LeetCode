/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 */

// @lc code=start

#include <algorithm>

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
    int max_val = 0;

    int dfs(TreeNode* root){
        if(root == nullptr) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        max_val = max(max_val, left + right);
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return max_val;
    }
};
// @lc code=end

