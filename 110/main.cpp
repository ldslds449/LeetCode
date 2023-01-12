/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

// @lc code=start

#include <algorithm>
#include <cmath>

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
    int helper(TreeNode* root, int level){
        if(root == nullptr) return level;
        int left = helper(root->left, level+1);
        if(left == -1) return -1;
        int right = helper(root->right, level+1);
        if(right == -1) return -1;
        int diff = abs(left - right);
        if(diff > 1) return -1;

        return max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return helper(root, 0) >= 0;
    }
};
// @lc code=end

