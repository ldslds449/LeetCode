/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
 */

// @lc code=start

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == nullptr) return 0;
        int total = 0;
        if(low <= root->val && high >= root->val) total += root->val;
        if(high >= root->val) total += rangeSumBST(root->right, low, high);
        if(low <= root->val) total += rangeSumBST(root->left, low, high);
        return total;
    }
};
// @lc code=end

