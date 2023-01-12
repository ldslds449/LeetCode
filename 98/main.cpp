/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start

#include <climits>

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
    bool dfs(TreeNode* root, long long min, long long max){
        if(root == nullptr) return true;
        if(root->val <= min || root->val >= max) return false;
        if(!dfs(root->left, min, root->val)) return false;
        if(!dfs(root->right, root->val, max)) return false;
        return true;
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};
// @lc code=end

